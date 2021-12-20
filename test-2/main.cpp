// Implement queue ADT based on a template circularly linked list. 
// The class must have the following features:

// template class
// constructor, copy constructor, destructor
// all queue specific functions

#include <iostream>

using namespace std;

#include "circular-linked-list.h"
#include "queue.h"
#include "node.h"

int main() {
    // Test enqueue() and dequeue()
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.size() << endl;
    q.enqueue(15);
    cout << q.front() << endl;
    // q.dequeue();

    cout << "--------------------" << endl;

    // Test front()
    Queue<int> q1;
    q1.enqueue(20);
    q1.enqueue(21);
    q1.enqueue(22);
    q1.enqueue(23);
    cout << q1.front() << endl;

    cout << "--------------------" << endl;

    // Test copy constructor
    Queue<int> q2(q1);
    q2.dequeue();
    cout << q2.front() << endl;

    cout << "--------------------" << endl;

    // Test the logic of the copy()
    cout << q1.front() << endl;

    cout << "--------------------" << endl;

    // Test the assignment operator
    Queue<int> q3 = q2;
    cout << q3.front() << endl;

    cout << "--------------------" << endl;

    // test assignment operator
    Queue<int> q4;
    q4 = q;
    cout << q4.front() << endl;

    cout << "--------------------" << endl;
    
    // Test behaviour when copying empty queues
    Queue<int> q5;
    Queue<int> q6(q5);
    Queue<int> q7 = q5;
    return 0;
}
