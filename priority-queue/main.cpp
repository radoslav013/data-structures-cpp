#include <iostream>
#include <string>

using namespace std;

#include "pqueue.h"

int main() {
    ListPriorityQueue<int, int> pq;
    pq.insert(1, 12);
    pq.insert(2, 10);
    cout << pq.size() << endl;
    pq.insert(3, 1);
    pq.insert(1, 13);
    pq.insert(4, 20);
    cout << pq.min() << endl;
    pq.removeMin();
    cout << "Size of pq: " << pq.size() << endl;
    cout << "Min of pq: " << pq.min() << endl;

    cout << "---------------------" << endl;

    ListPriorityQueue<int, int> pq1(pq);
    pq1.insert(1, 3);
    cout << "Size of pq1: " << pq1.size() << endl;
    cout << "Min of pq1: " << pq1.min() << endl;

    cout << "---------------------" << endl;

    ListPriorityQueue<int, int> pq2 = pq;
    pq2.insert(2, 3);
    cout << "Size of pq2: " << pq2.size() << endl;
    cout << "Min of pq2: " << pq2.min() << endl;

    cout << "---------------------" << endl;

    ListPriorityQueue<string, int> pq3;
    pq3.insert("a", 0);
    pq3.insert("z", 26);
    pq3.insert("0", 13);
    cout << "Size of pq3: " << pq3.size() << endl;
    cout << "Min of pq3: " << pq3.min() << endl;

    return 0;
}