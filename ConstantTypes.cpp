//
//  ConstantTypes.cpp
//  Practice1
//
//  Created by Taher Benisa on 5/22/22.
//  Copyright © 2022 taher benisa. All rights reserved.
//

#include "ConstantTypes.hpp"


using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::array;
using std::byte;
using std::endl;
using std::istream;
using std::ostream;

void ConstTypes(void) {

//!!!!:  ///////////////////   writng const int    //////////////////
    // writng const int
    const int constint = 5;
    int* pt = (int* ) &constint;
    //*pt++;          // does not increment constint
    cout << "1. *pt++ Does not increment Const int = " << constint << endl; // prints 5
    *pt = *pt + 1;  // it does increment constint
    cout << "2. *pt = *pt + 1 Does not increment Const int = " << constint << endl; // prints 5
    *pt = 9;        // this works. constint vlaue is now 9
    cout << "3. *pt = 9 assignment to 9, printing consting = " << constint << endl; // should print 9
    cout << "3.1 *pt = 9 assignment to 9, printing *pt = " << *pt << endl; // should print 9

    // writng nonconst int through pointer
    int nonconstint = 5;
    int* pt1 = (int* )&nonconstint;
    *pt1 = (*pt1)++;    // Does not increment nonconstint ????????
    cout << "1. *pt1 = (*pt1)++: Does not increment nonConst int, = " << nonconstint << endl; // prints 5
    
    (*pt1)++;    // it Does increment nonconstint
    cout << "2.  (*pt1)++: it Does increment nonConst int, = " << nonconstint << endl; // prints 6
    
    *pt1 += (*pt1)++;    // it Does increment nonconstint
    cout << "3. *pt1 += (*pt1)++ it Does increment nonConst int, = " << nonconstint << endl; // prints 13
    
    *pt1 = *pt1 + 1;    // it does increment nonconstint
    cout << "4. *pt1 = *pt1 + 1: it Does increment nonConst int, = " << nonconstint << endl << endl; // prints 14

// !!!: //////////////////      Writing const Array of chars     ////////////////////////

    // 1. Create const char array:
    
    // 1.1 Using 'new' to create array:
    // Cannot modify it through pointer to 'nonconst char'
    // You get Compile Time Error
    const char* new_name = new char[6] {'B', 'E', 'N', 'I', 'S', 'A'};
    //pcnew[0] = 'V';   // Compile Time Error: Read-only variable is not assignable
    char* pnew_name = (char* )new_name;
    cout << "*pcc = " << *pnew_name << endl; // or
    //pnew_name = new_name;  // Compile Time Error: Assigning to 'char *' from 'const char *' discards qualifiers
   
    // 1.2 Using const pointer to 'string literal' :
    //     Cannot modify it, through pointer to 'nonconst char'
    //     You get Run Time Error, but No Compile Time Error
    const char* static_name = "BENISA";
    char* pstatic_name = (char* )static_name;
    //pstatic_name[0] = 'V';  // Notice: Run Time Error, but No Compile Time Error.
    cout << pstatic_name << endl;

    // 1.3 Using const 'string literal' array:
    // You Can modify it. No Run Time Error and No Compile Time Error.
    const char static_name1[] = "BENISA";
    cout << "name[] = " << static_name1 << endl;
    //name[0] = 'V';    // Compile Time Error: Cannot assign to variable 'name' with const-qualified type 'const char[7]'
    char* pname = (char* )static_name1;  // or
    *pname = 'V';     // Surprisingly this is OK
    cout << "name[] = " << static_name1 << endl; // Prints "VENISA"

    char* pcx = pname;
    //pcx[0] = 'V';
    cout  << "pname = " << pcx << endl;
}
