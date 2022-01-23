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
        //! Default constructor
        /*!
            sets all default values
         */
        SkipList() : header(new SLEntry(MAXLVL)), n(0), lvl(0) { srand((unsigned)time(0)); } // random reset seed

        //! Destructor
        /*!
            Cleans pointers, specifically the header
         */
        ~SkipList();

        //! Find in Skip List
        /*!
            Traverses through the elements to find the entry with the given key
            \param key      key value
            \return         Iterator to that entry
         */
        Iterator find(const K& k);

        //! Insert into Skip List
        /*!
            If an entry with the provided key already exists, replace the provided data value.
            Otherwise, append the new key-data value pair in the map list.
            \param key      key value
            \param val      data value
            \return         iterator to the position of the modified or new entry
         */
        Iterator put(const K& k, const V& v);

        //! Deletes element
        /*!
            Deletes element with key k
            \param key      key value
         */
        void erase(const K& k);

        //! Deletes element
        /*!
            Deletes element by iterator
            \param p      iterator
         */
        void erase(const Iterator& p);

        //! Get begin iterator
        /*!
            Gets header iterator
            \return         iterator to the header
         */
        Iterator begin() const { return Iterator(header); } // pointer to first entry

        // utilities

        //! Returns the size
        /*!
            Returns the size
            \return         size
         */
        int size() const { return n; }

        //! Checks if skip list is empty
        /*!
            Checks if skip list is empty
            \return         true is skip list is empty and false otherwise
         */
        bool empty() const { return size() == 0; }

        //! Flip a coin
        /*!
            Generates a random number between 0 ... 1
            \return         false for tails and true for heads
         */
        bool flipCoin() const;

        //! Generate new height of newly inserted tower
        /*!
            Returns the height of the newly inserted tower. While the coin flips heads it keeps adding.
            \return         new height
         */
        int getNewHeight() const;

        //! Prints the skip list simply
        /*!
            Simply prints the skip list with the level indexing
         */
        void print() const;
    private:
        //! The max level
        /*!
            Depends on the use case. Set for, because of testing with small amount of entries
         */
        const int MAXLVL = 4;

        //! Level of the skip list
        /*!
            Stores the current level of the tree / height
         */
        int lvl;

        //! Size
        /*!
            Stores the size
         */
        int n;

        //! The first entry, only storing the next pointers
        /*!
            storing the next pointers
         */
        SLEntry* header;

        //! Helper function for destructing
        /*!
            Helper function for the destrcuting
         */
        void free();
    public:

        //! Class Iterator
        /*!
            Iterator helps when working with the entries
         */
        class Iterator {
            public:
                //! Default constructor
                /*!
                    creates an empty entry
                */
                Iterator();

                //! Parameter Constructor
                /*!
                    Accepts already created pointer to Skip list Entry object
                    \param u      pointer to skip list entry
                */
                Iterator(SLEntry* u);

                //! Copy constructor
                /*!
                    Copies pointer to one pointer to current
                    \param u      iterator
                */
                Iterator(const Iterator& u);

                //! Overloaded the -> operator
                /*!
                    Gives the possibility of a better syntax when working with iterators. 
                    Got the idea from std vector and list.
                    \return         pointer to skip list entry
                */
                SLEntry* operator->();

                //! Check if two iterators are equal
                /*!
                    Checks equality by pointers
                    \param u      iterator
                    \return         true if equal
                */
                bool operator ==(const Iterator& p) const;

                //! Check if two iterators are not equal
                /*!
                    Checks equality by pointers
                    \param u      iterator
                    \return         true if not equal
                */
                bool operator !=(const Iterator& p) const;

                //! checks if pointer exists
                /*!
                    Checks if pointer exists
                    \return         true if exists
                */
                bool exist() const;

                //! = Operator oveloaded
                /*!
                    Copies iterator to current, 
                    \param p      iterator
                    \return         Iterator
                */
                Iterator& operator =(const Iterator& p);

                //! Returns after this level
                /*!
                    Returns the next iterator
                    \param lvl      level
                    \return         next iterator
                */
                Iterator after(int lvl) const;

            friend class SkipList;
            private:
                //! Stores the pointer v
                /*!
                    Stores the pointer v
                */
                SLEntry* v;

                //! Copies pointer to this iterator 
                /*!
                    Checks equality by pointers
                    \param u      iterator
                */
                void copy(const Iterator& u);
        };
};

template <typename E>
void SkipList<E>::free() {
    if(header) {
        delete header;
    }
}

template <typename E>
SkipList<E>::~SkipList() {
    free();
}

template <typename E>
int SkipList<E>::getNewHeight() const {
    int l = 0;
    // increment l until tails
    while(!flipCoin() && l < MAXLVL) {
        ++l;
    }
	return l;
}

template <typename E>
void SkipList<E>::print() const {
	int currentLevel = lvl;
    while(currentLevel >= 0) {
		Iterator node = begin().after(currentLevel);
		cout << "S" << currentLevel << ": ";
		while (node.v) {
			cout << node->key() << " ";
			node = node.after(currentLevel);
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
            s.after(currentLevel).exist() &&
            s.after(currentLevel)->key() < k
        ) {
            s = s.after(currentLevel);
        }
        --currentLevel;
    }

    while(s->key() != k && s.after(0).exist()) {
        s = s.after(0);
    }

    if(s.exist() && s->key() == k) {
        return s;
    } else {
        throw SkipListExcpt("No element with this key");
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
    vector<Iterator> toUpdateAfter(MAXLVL+1);
    
    // found where is the correct place for the new element
    int currentLevel = lvl;
    while(currentLevel >= 0) {
        while(
            s.after(currentLevel).exist() &&
            s.after(currentLevel)->key() < k
        ) {
            s = s.after(currentLevel);
        }
        toUpdateAfter[currentLevel] = s.v;
        --currentLevel;
    }
    s = s.after(0);

    // update all previous
    if(s.exist() && s->key() == k) {
        for(int i = 0; i <= lvl; i++) {
            if(toUpdateAfter[i].after(i) != s) {
                break;
            }
            toUpdateAfter[i]->next[i] = s->next[i];
        }

        // update all
        while(lvl > 0 && !begin().after(lvl).exist()) {
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
            s.after(currentLevel).exist() &&
            s.after(currentLevel)->key() < k
        ) {
            s = s.after(currentLevel);
        }
        toUpdateAfter[currentLevel] = s;
        --currentLevel;
    }
    s = s.after(0);

    Iterator newNode;

    // insert new only if there is no key k already
    if(!s.exist() || s->key() != k) {
        int newLevel = getNewHeight();

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
typename SkipList<E>::Iterator SkipList<E>::Iterator::after(int lvl) const {
    return Iterator(v->next[lvl]);
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