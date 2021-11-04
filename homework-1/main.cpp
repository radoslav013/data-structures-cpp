// Implement a class Progression that represents the concept of numerical progression. 
// The class Progression must be an abstract class that is used as a base class 
// in inheritance hierarchy  that must include classes for 
// arithmetic progression, geometric progression, and harmonic progression. 

// Show polymorphism.
/// Comments
// Build&Run commands section
// Illustrate with examples
// Explain each progression type with Greek Sum and induction

// FACTS:
// Divergence indicates that two trends move further away from each other while convergence 
// indicates how they move closer together.

#include <iostream>

using namespace std;

#include "arit-progression.h"
#include "geom-progression.h"
#include "harm-progression.h"

int main() {
    Progression* p;

    double arit_incr = 1;
    cout << "Arithmetic progression with increment = " << arit_incr << endl;
    p = new AritProgression();
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    arit_incr = 15;
    cout << "Arithmetic progression with increment = " << arit_incr << endl;
    p = new AritProgression(arit_incr);
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    arit_incr = -20;
    cout << "Arithmetic progression with increment = " << arit_incr << " which is decreasing" << endl;
    p = new AritProgression(arit_incr);
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    double geom_base = 2;
    cout << "Geometric progression with base = " << geom_base << endl;
    p = new GeomProgression(geom_base);
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    geom_base = 3;
    cout << "Geometric progression with base = " << geom_base << endl;
    p = new GeomProgression(geom_base);
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    
    double harm_p = 1;
    cout << "Harmonic progression with p = " << harm_p << endl;
    p = new HarmProgression();
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    harm_p = 2;
    cout << "Harmonic progression with p = " << harm_p << endl;
    p = new HarmProgression(harm_p);
    cout << "The fifth element is: " << p->getNth(5) << endl;
    p->print();

    return 0;
}