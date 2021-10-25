#ifndef GAME_ENTRY_H
#define GAME_ENTRY_H

class GameEntry {
    public:
        GameEntry();
        GameEntry(string name, int score);
        string getName() const;
        int getScore() const;

    private:
        string name;
        int score;
};

#endif