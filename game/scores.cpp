#include <iostream>
#include <string>

using namespace std;

#include "scores.h"

Scores::Scores(int max_entries)
{
    this->max_entries = max_entries;
    this->ptr_arr = new GameEntry[this->max_entries];
}

Scores::~Scores()
{
    if (ptr_arr)
    {
        delete[] ptr_arr;
        ptr_arr = nullptr;
    }
}

void Scores::add(const GameEntry &entry) {
    if (num_entries == max_entries)
    {
        if (entry.getScore() <= this->ptr_arr[this->max_entries - 1].getScore()) {
            return;
        }
    } else {
        this->num_entries++;
    }
    int i = this->num_entries - 2;
    while (i >= 0 && entry.getScore() > this->ptr_arr[i].getScore())
    {
        this->ptr_arr[i + 1] = this->ptr_arr[i];
        i--;
    }
    this->ptr_arr[i + 1] = entry;
}