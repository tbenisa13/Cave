//
//  Logic.cpp
//  Practice1
//
//  Created by taher benisa on 12/18/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "Logic.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::bitset;
using std::istream;
using std::ostream;

extern const int cintGlobal;    // Experiment
const int xx = cintGlobal;

bool Logic::LogicOR(bool A, bool B)
{
    {
        bool A = 0;
        // '&', '+', '-', '*';
        bool a = A & !A;     // 0   '&'
        bool b = A * !A;     // 0   '*'
        bool c = A * A;      // A   '*'
        bool d = A &  A;     // A   '&'
        
        bool e = A + !A;     // 1   '+'
        bool f = A - !A;     // 1   '-'
        f = 0-12;

        int n =0;
    }
    bool result = false;
    
    if(A || B){
        if(A && B) {
            cout << "Both A and B are True: A = " << A << ", " << "B = " << B << endl;
        }
        else if(A) { // A && !B
            cout << "A is True: A = " << A << ", " << "B = " << B << endl;
        }
        else {      // B && !A
            cout << "B is True: A = " << A << ", " << "B = " << B << endl;
        }
        
        result = true;
    }
    
    // After executing "if(A || B)" above
    //cout << "A = False && B = False" << endl;
    if(!A && !B) {
        cout << "Both A and B are False: A = " << A << ", " << "B = " << B << endl;
        result = false;
    }
    else if(!A) {
        cout << "A is Fale: A = " << A << ", " << "B = " << B << endl;
        result = true;
    }
    else if(!B) {
        cout << "B is False: A = " << A << ", " << "B = " << B << endl;
        result = true;
    }

    return result;
}

bool Logic::LogicAND(bool A, bool B)
{
    bool result = false;
    
    if(A && B) {
        cout << "A = " << A << ", " << "B = " << B << endl;
        // do some actions
        result = true;
    }
    
    //at this point either !A, or !B, or !A && !B
    // filter out what you need
    if(!A && !B) {    // A and B are false
        cout << "Both A and B are Fasle: A = " << A << ", " << "B = " << B << endl;
        // do some actions
        result = false;
    }
    else if(!A) {       // A is Fasle
        cout << "A is Fasle: A = " << A << ", " << "B = " << B << endl;
        // do some actions
        result = false;
    }
    else if(!B){        // B is Fasle
        cout << "Both B is Fasle: A = " << A << ", " << "B = " << B << endl;
        // do some actions
        result = false;
    }
    
    return result;
}
