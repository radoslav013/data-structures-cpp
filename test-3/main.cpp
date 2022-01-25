#include <iostream>
#include <random> // for random
#include <unordered_map> // to count collisions

using namespace std;

// Implement a comparator data type that provides hashing of 
// floating point numbers of type double. 
// The implementation must have the following features:
//      polynomial hash code based, calculated using the Horner's rule
//      MAD method for compression function
//      test the implementation on a series of randomly generated 
// floating point numbers in a given range, and count the collisions

// run with g++ -std=c++20 main.cpp hashc.cpp -o main.out && ./main.out

#include "hashc.h"

int main() {
    // initial seed
    srand(time(0));

    const int MIN = 1; // min value of the randomly-generated numbers
    const int MAX = 1000; // max value of the randomly-generated numbers
    const int N = 30; // size of the bucket array
    const int p = 103; // should be larger than N and be a prime number

    unsigned int a = rand() % (p-1) + 1; // (0, p-1]
    // a shouldn't be divisible by n
    while(a % N == 0) {
        a = rand() % (p-1) + 1; // (0, p-1]
        if(a % N != 0) {
            break;
        }
    }
    unsigned int b = rand() % p; // [0, p-1]

    int collisions = 0;
    HashCode hashCode;
    unordered_map<int, size_t> count;
    for (int i = 0; i < N; i++) {
        // generate a random floating-point number between MIN and MAX
        double num = MIN + (double)(rand()) / ((double)(RAND_MAX/(MAX - MIN)));
        long hashedCode = hashCode(num); // hash function

        // compression using the MAD method
        unsigned int compressedHashCode = (abs(a*hashedCode + b) % p) % N;

        // counting the collisions
        if(count[compressedHashCode]) {
            collisions++;
        }
        // add to the unordered map
        count[compressedHashCode]++;
    
        cout << num << " -> " << hashedCode << " -> " << compressedHashCode << endl;
    }

    cout << "--------" << endl;

    cout << "Collisions: " << collisions << endl;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "--------" << endl;

    // Demonstrating that h(k) == h(k)
    cout << "Demonstrating that h(k) == h(k) ";
    cout << hashCode(5.55) << " == ";
    cout << hashCode(5.55) << endl;
    
    return 0;
}