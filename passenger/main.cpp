#include <iostream>

using namespace std; 

#include "passenger.h"

int main() {
    Passenger p1;
    Passenger* p2 = new Passenger("Rick", Passenger::MEAT, true);

    delete p2;
    return 0;
}