#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <time.h>

template <typename E>
class SkipList;

class SkipListExcpt : public runtime_error {
    public:
        SkipListExcpt(const string& msg) : runtime_error(msg) {}
};

#include "skip-list-entry.h"

template <typename E>
class SkipList {
    public:
        typedef SLEntry<E> SLEntry; // an entry
        typedef typename SLEntry::Key K; // a key
        typedef typename SLEntry::Value V; // a value
        class Iterator;
    public:
        SkipList() : header(new SLEntry(MAXLVL)), n(0), lvl(0) { srand((unsigned)time(0)); } // random reset seed
        ~SkipList();
        Iterator find(const K& k); // find entry with key k
        Iterator put(const K& k, const V& v); // insert/replace pair (k,v)
        void erase(const K& k); // remove entry with key k
        void erase(const Iterator& p); // erase entry at p

        Iterator begin() const { return Iterator(header); } // pointer to first entry

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
        SLEntry* header;
        void copy(const SkipList& b);
        void free();
    public:
        class Iterator {
            public:
                Iterator();
                Iterator(SLEntry* u);
                Iterator(const Iterator& u);
                SLEntry* operator->();
                bool operator ==(const Iterator& p) const;
                bool operator !=(const Iterator& p) const;
                bool exist() const;
                Iterator& operator =(const Iterator& p);

            friend class SkipList;
            private:
                SLEntry* v;
                void copy(const Iterator& u);
        };
};

template <typename E>
SkipList<E>::~SkipList() {
    if(header) {
        delete header;
    }
    // TODO: delete vector of pointers next
}

template <typename E>
int SkipList<E>::randomLevel() const {
    float r = (float)rand()/RAND_MAX;
	int lvl = 0;
	while (r < P && lvl < MAXLVL)
	{
		lvl++;
		r = (float)rand()/RAND_MAX;
	}
	return lvl;
}

template <typename E>
void SkipList<E>::print() const {
	int currentLevel = lvl;
    while(currentLevel >= 0) {
		auto node = header->next[currentLevel]; // TODO: fix auto
		cout << "S" << currentLevel << ": ";
		while (node) {
			cout << node->key() << " ";
			node = node->next[currentLevel];
		}
		cout << endl;
        --currentLevel;
	}
};

template <typename E>
typename SkipList<E>::Iterator SkipList<E>::find(const K& k) {
    Iterator s = begin();

    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key() < k
        ) {
            s = s->next[currentLevel];
        }
        --currentLevel;
    }

    while(s->key() != k && s->next[0]) {
        s = s->next[0];
    }

    if(s.exist() && s->key() == k) {
        return s;
    } else {
        throw SkipListExcpt("No element with this key"); // TODO: custom exception
        return nullptr;
    }
}

template <typename E>
void SkipList<E>::erase(const Iterator& p) {
    Iterator s = p;
    erase(s->key());
}

template <typename E>
void SkipList<E>::erase(const K& k) {
    Iterator s = begin();
    vector<SLEntry*> toUpdateAfter(MAXLVL+1);
    
    // found where is the correct place for the new element
    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key() < k
        ) {
            s = s->next[currentLevel];
        }
        toUpdateAfter[currentLevel] = s.v;
        --currentLevel;
    }
    s = s->next[0]; // TODO: after()

   if(s.exist() && s->key() == k) {
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
    } else {
        throw SkipListExcpt("No element found to delete.");
    }
}

template <typename E>
typename SkipList<E>::Iterator SkipList<E>::put(const K& k, const V& v) {
    Iterator s = begin();
    vector<Iterator> toUpdateAfter(MAXLVL+1);

    // found where is the correct place for the new element
    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s->next[currentLevel] &&
            s->next[currentLevel]->key() < k
        ) {
            s = s->next[currentLevel];
        }
        toUpdateAfter[currentLevel] = s;
        --currentLevel;
    }
    s = s->next[0]; // TODO: after()

    Iterator newNode;

    // insert new only if there is no key k already
    if(!s.exist() || s->key() != k) {
        int newLevel = randomLevel(); // TODO: use flip coin

        if(newLevel > lvl) {
            for(int i = lvl+1; i < newLevel+1; i++) {
                toUpdateAfter[i] = header;
            }
            lvl = newLevel;
        }

        newNode = Iterator(new SLEntry(k, v, newLevel));

        // update all
        int u = 0;
        while(u <= newLevel) {
            newNode->next[u] = toUpdateAfter[u]->next[u];
            toUpdateAfter[u]->next[u] = newNode.v;

            ++u;
        }
        n++;
    } else {
        // update the value only, since the key is the same
        s->setValue(v);
        newNode = s;
    }

    return newNode;
}

template <typename E>
bool SkipList<E>::flipCoin() const {
    return rand() % 2; //since we are looking for 0 tails | 1 heads
}

template <typename E>
void SkipList<E>::copy(const SkipList<E>& b) {
    for(SkipList<E>::SLEntry* it = b.begin(); it != b.end(); ++it) {
        insertBack(*it);
    }
}

template <typename E>
void SkipList<E>::free() {
    // while(!empty()) {
        // TODO
    // }
}

template <typename E>
SkipList<E>::Iterator::Iterator() {
    v = new SLEntry(0);
}

template <typename E>
SkipList<E>::Iterator::Iterator(SLEntry* u) {
    v = u;
}

template <typename E>
SkipList<E>::Iterator::Iterator(const Iterator& u) {
    copy(u);
}

template <typename E>
typename SkipList<E>::Iterator& SkipList<E>::Iterator::operator =(const Iterator& u) {
    copy(u);
    return *this;
}

template <typename E>
void SkipList<E>::Iterator::copy(const Iterator& u) {
    v = u.v;
}

template <typename E>
typename SkipList<E>::SLEntry* SkipList<E>::Iterator::operator ->() {
    return v;
}

template <typename E>
bool SkipList<E>::Iterator::operator ==(const Iterator& p) const {
    return p.v == v;
}

template <typename E>
bool SkipList<E>::Iterator::operator !=(const Iterator& p) const {
    return p.v != v;
}

template <typename E>
bool SkipList<E>::Iterator::exist() const {
    return v != nullptr;
}
#endif