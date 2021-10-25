#include <iostream>

using namespace std;

#include "game-entry.h"
#include "scores.h"

int main() {
    Scores* s = new Scores(100);

    GameEntry* g1 = new GameEntry("Rado", 21);
    s->add(*g1);

    GameEntry* g2 = new GameEntry("Yasen", 34);
    s->add(*g2);

    GameEntry* g3 = new GameEntry("Ivan", 42);
    s->add(*g3);

    s->remove(2);

    cout << s->getNumEntries() << endl;
    return 0;
}