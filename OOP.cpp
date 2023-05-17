//
//  OOP.cpp
//  Practice1
//
//  Created by taher benisa on 2/13/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "OOP.hpp"

class Derived;  // forward decl
class Base
{   public:
    Base() {baseval = 1000;};        // defualt Xtor
    Base(int val) : baseval(val) {}; //if default param is used, Xtor becomes default Xtor
    void basefunc(void);
    
    int baseval;
    
    // It is uncommon for classes to define explicitly how to initialize or assign an object of
    // the base type from an object of derived
    //Base(const Derived&) {}; // create a new Base from a Derived
    //Base& operator=(const Derived&) {return *this;}; // assign from a Derived
    // Instead, base classes ususally define (either
    //explicitly or implicitly) their own copy constructor and assignment operator
    Base(const Base& b) { baseval = b.baseval;};
    Base& operator=(const Base& b)
    {
        baseval = b.baseval;
        return *this;};
    };

class Derived : public Base
{   public:
    Derived() : derivedval(33) {};  // calls base defualt Xtor first
    Derived(int val) : Base(23), derivedval(val) {};
    
    void derivedfunc(void);
   
    int derivedval;
};

// Conversion to a Reference is Not the Same as Converting an Object:
// param is ref to object
void funcRefToBaseParm(const Base&);    //prototype
void RefToBaseParam(void)
{
    /*Base base(777);     // object of base type
    Base base1;         // calls default Xtor
    Derived derived1;   //calls default Xtor */
    Derived derived(20);
    funcRefToBaseParm(derived);

    // ok: uses Base::Base(const Base&) constructor
    Base base2(derived); // Derived is "sliced down" to its Base portion
    // ok: calls Base::operator=(const Base&)
    base2 = derived; // Derived is "sliced down" to its Base portion
}

void funcRefToBaseParm(const Base& refBase)
{
    cout << refBase.baseval << endl;
    //cout << refBase.derivedval << endl; //No member named 'derivedval' in 'Base'
}

//////////////////////////////////////////////////////////////////////////////////////////
// param is object
void funcBaseObjectParm(const Base ojectBase);    //prototype
void ObjectBaseParamTo(void)
{
    Derived derived(20);
    funcBaseObjectParm(derived);
}

void funcBaseObjectParm(const Base ojectBase)
{
    cout << ojectBase.baseval << endl;
    //cout << ojectBase.derivedval << endl;   //No member named 'derivedval' in 'Base'
}
