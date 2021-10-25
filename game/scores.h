#ifndef SCORES_H
#define SCORES_H

#include "game-entry.h"
class Scores {
    public:
        Scores(int max_entries);
        ~Scores();
        void add(const GameEntry &entry);
        void remove(int i);
        int getNumEntries() const;
    private:
        int max_entries;
        int num_entries;
        GameEntry *ptr_arr;
};

#endif