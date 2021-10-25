#include <iostream>
#include <string>

using namespace std;

#include "game-entry.h"

GameEntry::GameEntry() {
    this->name = "";
    this->score = 0;
}

GameEntry::GameEntry(string name, int score) {
    this->name = name;
    this->score = score;
}

string GameEntry::getName() const {
    return this->name;
}

int GameEntry::getScore() const {
    return this->score;
}