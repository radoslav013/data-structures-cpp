#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <iostream>
#include <vector>
#include <time.h>

// #include "entry.h"

template <typename K, typename V>
class SkipList {
    private:
        class Node {
            public:
                Node(int l) : next(l) {}
                Node(const K& k, const V& v, int l) : key(k), val(v), next(l+1) {}

                K key; V val;
                vector<Node*> next; // vector with pointers to next node vertically
        };
    public:
        // typedef Entry<K, V> Entry; // a (key,value) pair // TODO
        // class Iterator;
    public:
        SkipList() : header(new Node(MAXLVL)), n(0), lvl(0) { srand((unsigned)time(0)); } // random reset seed
        ~SkipList();
        Node* find(const K& k); // find entry with key k
        Node* put(const K& k, const V& v); // insert/replace pair (k,v)
        void erase(const K& k); // remove entry with key k
        void erase(const Node* p); // erase entry at p

        Node* begin() const { return header; } // pointer to first entry

        Node* above(const Node* p);
        Node* below(const Node* p);
        Node* after(const Node* p);
        Node* before(const Node* p);

        // utilities
        int size() const { return n; }
        bool empty() const { return size() == 0; }
        bool flipCoin() const;
        int randomLevel() const;
        void print() const;
    private:
        const int MAXLVL = 3; // TODO: see what is the best?
        const float P = 0.5; // TODO: see what is the best
        int lvl;
        int n;
        Node* header;
        void copy(const SkipList<K, V>& b);
        void free();
    public:
        // class Iterator {
        //     public:
        //         Iterator();
        //         Iterator(Node* u);
        //         Iterator(const Iterator& u);
        //         K& operator*();
        //         bool operator ==(const Iterator& p) const;
        //         bool operator !=(const Iterator& p) const;
        //         Iterator& operator =(const Iterator& p);
        //         friend class SkipList;
        //     private:
        //         Node* v;
        //         void copy(const Iterator& u);
        // };
};

template <typename K, typename V>
SkipList<K, V>::~SkipList() {
    if(header) {
        delete header;
    }
    // TODO: delete vector of pointers next
}

template <typename K, typename V>
int SkipList<K, V>::randomLevel() const {
    float r = (float)rand()/RAND_MAX;
	int lvl = 0;
	while (r < P && lvl < MAXLVL)
	{
		lvl++;
		r = (float)rand()/RAND_MAX;
	}
	return lvl;
}

template <typename K, typename V>
void SkipList<K, V>::print() const {
	int currentLevel = lvl;
    while(currentLevel >= 0) {
		Node *node = header->next[currentLevel];
		cout << "S" << currentLevel << ": ";
		while (node) {
			cout << node->key << " ";
			node = node->next[currentLevel];
		}
		cout << endl;
        --currentLevel;
	}
};

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::find(const K& k) {
    Node* s = header;

    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key < k
        ) {
            s = s->next[currentLevel];
        }
        --currentLevel;
    }

    while(s->key != k && s->next[0]) {
        s = s->next[0];
    }

    if(s && s->key == k) {
        return s;
    } else {
        throw runtime_error("No element with this key"); // TODO: custom exception
        return nullptr;
    }
}

template <typename K, typename V>
void SkipList<K, V>::erase(const Node* p) {
    erase(p->key);
}

template <typename K, typename V>
void SkipList<K, V>::erase(const K& k) {
    Node* s = header;
    vector<Node*> toUpdateAfter(MAXLVL+1);
    
    // found where is the correct place for the new element
    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key < k
        ) {
            s = s->next[currentLevel];
        }
        toUpdateAfter[currentLevel] = s;
        --currentLevel;
    }
    s = s->next[0]; // TODO: after()

   if(s != nullptr || s->key == k) {
        for(int i = 0; i <= lvl; i++) {
            if(toUpdateAfter[i]->next[i] != s) {
                break;
            }
            toUpdateAfter[i]->next[i] = s->next[i];
        }

        // update all
        while(lvl > 0 && header->next[lvl] == 0) {
           --lvl;
        }
        --n;
    }
}

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::put(const K& k, const V& v) {
    Node* s = header;
    vector<Node*> toUpdateAfter(MAXLVL+1);

    // found where is the correct place for the new element
    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key < k
        ) {
            s = s->next[currentLevel];
        }
        toUpdateAfter[currentLevel] = s;
        --currentLevel;
    }
    s = s->next[0]; // TODO: after()

    Node* newNode;

    // insert new only if there is no key k already
    if(s == nullptr || s->key != k) {
        int newLevel = randomLevel(); // TODO: use flip coin

        if(newLevel > lvl) {
            for(int i = lvl+1; i < newLevel+1; i++) {
                toUpdateAfter[i] = header;
            }
            lvl = newLevel;
        }

        newNode = new Node(k, v, newLevel);

        // update all
        int u = 0;
        while(u <= newLevel) {
            newNode->next[u] = toUpdateAfter[u]->next[u];
            toUpdateAfter[u]->next[u] = newNode;

            ++u;
        }
        n++;
    } else {
        // update the value only, since the key is the same
        s->val = v;
        newNode = s;
    }

    return newNode;
}

template <typename K, typename V>
bool SkipList<K, V>::flipCoin() const {
    return rand() % 2; //since we are looking for 0 tails | 1 heads
}

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::after(const Node* p) {
    if(p->lvl < p->next.size()) {
        return p->next[p->lvl];
    } else {
       return nullptr;
    }
}

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::below(const Node* p) {
    if(p->lvl > 0) {
        return p->prev->next[p->lvl-1];
    } else {
        return nullptr;
    }
}

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::above(const Node* p) {
    // if(p->lvl < p->prev->next.size()-1) {
    //     return p->prev->next[++p->lvl];
    // } else {
    //     throw runtime_error("There is no above!");
    // }
}

template <typename K, typename V>
typename SkipList<K, V>::Node* SkipList<K, V>::before(const Node* p) {
    // if(p->lvl < p->prev->prev->next.size()) {
    //     return p->prev->prev->next[p->lvl];
    // } else {
    //     throw runtime_error("There is no before!");
    // }
}

template <typename K, typename V>
void SkipList<K, V>::copy(const SkipList<K, V>& b) {
    for(SkipList<K, V>::Node* it = b.begin(); it != b.end(); ++it) {
        insertBack(*it);
    }
}

template <typename K, typename V>
void SkipList<K, V>::free() {
    // while(!empty()) {
        // TODO
    // }
}


/*
template <typename K, typename V>
SkipList<K, V>::Iterator::Iterator() {
    v = new Node();
}

template <typename K, typename V>
SkipList<K, V>::Iterator::Iterator(Node* u) {
    v = u;
}

template <typename K, typename V>
SkipList<K, V>::Iterator::Iterator(const Iterator& u) {
    copy(u);
}

template <typename K, typename V>
typename SkipList<K, V>::Iterator& SkipList<K, V>::Iterator::operator =(const Iterator& u) {
    copy(u);
    return *this;
}

template <typename K, typename V>
void SkipList<K, V>::Iterator::copy(const Iterator& u) {
    v = u.v;
}

template <typename K, typename V>
K& SkipList<K, V>::Iterator::operator *() {
    return v->key;
}

template <typename K, typename V>
bool SkipList<K, V>::Iterator::operator ==(const Iterator& p) const {
    return p.v == v;
}

template <typename K, typename V>
bool SkipList<K, V>::Iterator::operator !=(const Iterator& p) const {
    return p.v != v;
}
*/
#endif