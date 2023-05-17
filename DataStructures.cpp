//
//  Practice2.cpp
//  Practice1
//
//  Created by taher benisa on 2/8/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "DataStructures.hpp"
#include <stdlib.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::map;
using std::set;
using std::bitset;
using std::istream;
using std::ostream;
using std::pair;
using std::tuple;

enum BIG_LITTLE_INDIAN {BIG_INDIAN = 0, LITTLE_INDIAN = 1};

// String
void StringPractice(void)
{
    string s("String Data");
    char *p = s.data();
    *p = 'X';
    cout << p << endl;
    
    const char *pc = s.c_str();
    // *pc = 'X'; Can't do this. it is a constant
    cout << pc << endl; //[0] << pc[1];
   
    char t = s.back();              cout << t << endl;
    char d = s.basic_string::at(0); cout << d << endl;
    char d1 = s.at(0);              cout << d1 << endl;
    auto f = s.begin();             cout << *f << endl;
    string::iterator f1 = s.begin();cout << *f1 << endl;
    s.append(" ws");
    s.append("   A", 3);
    s.append(" VBN");
    string ss = s.assign("TTTT");
    s.swap(ss);

    cout << endl;
}

// map
void MapPractice(void)
{
    cout << "Map Manipulation:" << endl;
    
    map<int, int> map1;
    map<int, int>::iterator mapIter;
    
    map1[3] = 2;
    map1[5] = 4;
    map1[7] = 6;
    mapIter  = map1.find(71);
    if(mapIter != map1.end()){
        int t = mapIter->second;    // should check mapIter before using it to access second
        cout << t << endl;
    }
    else
        cout << "Not found" << endl;

    //if( map1.find(7) == true) {    } //did not work
    
    //find key = 3 in map
    //auto mapIter1  = map1.find(3);
    map<int, int>::iterator mapIter1  = map1.find(3);
    cout << "\tfind key = " << mapIter1->first << endl;
    if(mapIter1 != map1.end())
    {
        auto ppp =  *mapIter1;
        cout << "\tFOUND first  = " << ppp.first << endl;
        cout << "\tFOUND second = " << ppp.second << endl;
    }
    else
        cout << "\tNOT FOUND" << endl;
    
    cout << "\tIterate thru map: " << endl;
    for(mapIter = map1.begin(); mapIter != map1.end(); mapIter++ )
    {
        cout << "\tFirst "  << mapIter->first << ", \t";
        cout << "\tSecond " << mapIter->second << endl;
    }
    cout << endl;
    {
        //declaration of map
        map<string, const char*, std::less<string>> Mp;
        //intialising maps
        Mp = { { "Banana", "yellow" },
          {  "Apple", "red" },
          { "Orange", "orange" } };
        //sorting of map during creation
        for (map<string, const char*>::iterator it = Mp.begin(); it != Mp.end();             it++) {
            cout << it->first << " => " << it->second << endl;
        }
    }

}

// set and bitset (for bit manipulation)
void SetPractice(void)
{
    {
        cout << "\n\t***** \tSet Stuff \t*****\n";
// !!!: /////////////////////      Print Sorted Set     /////////////////////
        
        int myints[5] = {21, 64, 17, 78, 49};
        cout << "My Original Set Contains:         ";
        for( int i=0; i < 5; i++ ) {
            cout << myints[i] << " ";
        }
        
        // ordered set
        set<int> myset (myints, myints + 5);

        cout << "\nMethod 1, My Sorted Set Contains:";
        set<int>::iterator itr = myset.begin();
        for( itr = myset.begin(); itr != myset.end(); ++itr ) {
            cout << ' ' << *itr;
        }

        cout << "\nMethod 2, My Sorted Set Contains:";
        set<int>::reverse_iterator rit1 = myset.rend();
        --rit1;
        for( ; rit1 != myset.rbegin(); --rit1 ) {
            cout << ' ' << *rit1;
        }
        cout << ' ' << *rit1;
        
// !!!: /////////////////////      Print Sorted Set in Reverse     /////////////////////
        
        set<int>::reverse_iterator rit = myset.rbegin();

        cout << "\nMy Reversed Sorted Set Contains: ";
        for( rit = myset.rbegin(); rit != myset.rend(); ++rit ) {
            cout << ' ' << *rit;
        }
    }
    cout << endl;
// !!!: /////////////////////      Set Declerations     /////////////////////
    {
        // Method 1: empty set of ints
        set<int> first;
        
        // Method 2:  range
        int myints[]= {10, 20, 30, 40, 50};
        set<int> second (myints, myints+5);
        
        // Method 3: a copy of second
        set<int> third( second );
        
        // Method 4: iterator Xtor
        set<int> fourth( second.begin(), second.end() );
        
        // Method 5: class as Compare
        //set<int,classcomp> fifth;
        
        // Attempt to add duplicates
        set<int> S {10, 3, 7, 2, 7, 11, 3};
        for (auto elem : S)
            cout << elem << ' ';
        cout << '\n';
        auto x = S.extract(10);
        int y = x.value();  // y = 10
        cout << "set.extract(10)" << y << endl;
        
        auto v = S.lower_bound(7);  // ???
        cout << v.operator*() << endl;      // ???

        set<int> Set = {3, 2, 4, 3};
        size_t found = Set.count(3);    cout << found << endl;
        Set.erase(3);
    }
}

void BitSetPractice(void)
{
    ///////////////////     bitset      ///////////////s
    cout << "Bitset Manipulation:" << endl;
    // create bitset of 5 bits intialized to 8
     bitset<5> b(8); // same as: bitset<5> b = 8
     cout << "\t5 bits intialized to 8: " << b << endl;

    string bit_string = "110010";
    bitset<8> b1(bit_string);             // [0, 0, 1, 1, 0, 0, 1, 0]
    cout << "\tcreate bitset initialized to bit_string: " <<  "\t" << b1 << endl;
     
    // string from position 2 till end
    bitset<8> b2(bit_string, 2);      // [0, 0, 0, 0, 0, 0, 1, 0]
    cout << "\tcreate bitset initialized to bit_string from position 2 till end: " <<  "\t" << b2 << endl;

     // string from position 2 till next 3 positions
    bitset<8> b3(bit_string, 2, 3);   // [0, 0, 0, 0, 0, 0, 0, 1]
    cout << "\tcreate bitset initialized to bit_string from position 2 till next 3 positions: "<<  "\t" << b3 << endl << endl;

     // string constructor using custom zero/one digits
    string alpha_bit_string = "aBaaBBaB";
    bitset<8> b4(alpha_bit_string, 0, alpha_bit_string.size(),
                        'a', 'B');         // [0,1,0,0,1,1,0,1]
    cout << "string constructor using custom zero/one digits: " << b4 << endl << endl;

    string bits1 = "1110";
    bitset<4> b5(bits1);
    b5 = b5.operator~();
    b5 = ~b5;
    b5[0] = 1;
    b5.set(0) = 0b101;  // ???
    b5.operator=(0b1011);
    
    string bits2 = "1100";
    bitset<4> b6(bits2);
    
    cout << "bits1 = " << bits1 << endl << "bits2 = " << bits2 << endl;
    cout << bits1 << " & "<< bits2 << " = " << (b5 & b6) <<endl;    // AND
    cout << bits1 << " | "<< bits2 << " = " << (b5 | b6) <<endl;    // OR
    cout << bits1 << " ^ "<< bits2 << " = " << (b5 ^ b6) <<endl;    // XOR
    cout << bits1 << " ^ " << bits2 << " ^ " << bits2 << " = bits1 = " << ((b5 ^ b6) ^ b6) << endl;    // XOR and XOR
    cout << "flip bits1  = " << (b5.flip()) <<endl;
    cout << "bits1[1]   = " <<  b5[1] << endl;
    cout << "shift b5 = " << (b5 <<= 1) << endl;
    {
        typedef std::size_t length_t, position_t; // the hints
        
        // constructors:
        constexpr std::bitset<4> b1;
        constexpr std::bitset<4> b2{0xA}; // == 0b1010
        std::bitset<4> b3{"0011"}; // can also be constexpr since C++23
        std::bitset<8> b4{"ABBA", length_t(4), /*0:*/'A', /*1:*/'B'}; // == 0B0000'0110
        
        // bitsets can be printed out to a stream:
        std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';
        
        // bitset supports bitwise operations:
        b3 |= 0b0100; assert(b3 == 0b0111);
        b3 &= 0b0011; assert(b3 == 0b0011);
        b3 ^= std::bitset<4>{0b1100}; assert(b3 == 0b1111);
        
        // operations on the whole set:
        b3.reset(); assert(b3 == 0);
        b3.set(); assert(b3 == 0b1111);
        unsigned int x = b3.any();
        assert(b3.all() && b3.any() && !b3.none());
        b3.flip(); assert(b3 == 0);
        
        // operations on individual bits:
        b3.set(position_t(1), true); assert(b3  == 0b0010);
        b3.set(position_t(1), false); assert(b3 == 0b0000);
        b3.flip(position_t(2)); assert(b3 == 0b0100);
        b3.reset(position_t(2)); assert(b3 == 0);
        
        // subscript operator[] is supported:
        b3[2] = true; assert(true == b3[2]);
        
        // other operations:
        assert(b3.count() == 1);
        assert(b3.size() == 4);
        assert(b3.to_ullong() == 0b0100ULL);
        assert(b3.to_string() == "0100");
    }
}

// list
void ListPractice(void)
{
    cout << "List Manipulation:" << endl;
    
    list<int> lst;
    lst.push_back(1); lst.push_back(7); lst.push_back(5); lst.push_back(13);
    list<int>::iterator iterlist1 = lst.begin();
    
    //list items:
    cout << "\tList items: ";
    for( ; iterlist1 != lst.end(); iterlist1++ )
    {
        cout << "\t" << *iterlist1 << ", ";
    }
    
    cout << endl;

    //list items in reverse order:
    cout << "\tIn reverse order: ";
    list<int>::reverse_iterator riterlist;
    for(riterlist = lst.rbegin(); riterlist != lst.rend(); riterlist++)
        cout << *riterlist << ", ";
    
    cout << endl<< endl;
}

void pairPractice(void)
{
    {
        // pair
        pair <string,double> product1;                     // default constructor
        pair <string,double> product2 ("tomatoes", 2.30);  // value init
        pair <string,double> product3 (product2);          // copy constructor
        
        product1 = make_pair(string("lightbulbs"), 0.99);  // using make_pair (move)
        
        product2.first = "shoes";                  // the type of first is string
        product2.second = 39.90;                   // the type of second is double
        
        cout << "The price of " << product1.first << " is $" << product1.second << '\n';
        cout << "The price of " << product2.first << " is $" << product2.second << '\n';
        cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    }
}
    
void tuplePractice(void)
{
    /*    {
        // tuple
         tuple<int,char> foo (10,'x');
         auto bar = make_tuple("test", 3.1, 14, 'y');

         get<2>(bar) = 100;                                 // access element

         int myint; char mychar;

         tie (myint, mychar) = foo;                         // unpack elements
         tie (ignore, ignore, myint, mychar) = bar;         // unpack (with ignore)

         mychar = get<3>(bar);

         get<0>(foo) = get<2>(bar);
         get<1>(foo) = mychar;

         cout << "foo contains: ";
         cout << get<0>(foo) << ' ';
         cout << get<1>(foo) << '\n';
    }
 */
}

// Passing unique_ptr to functions as parameter:
void foo(std::unique_ptr<int> ptr)
{
    // Your code goes here
}

int* foo_cpp03(void)
{
    int temp = 10;
    return &temp;   // Warning: Address of stack memory associated with local variable 'temp' returned
};

void smartPointers(void)
{
    {
        // Creates a unique_ptr to an int with value 59
        std::unique_ptr<int> ptr1 = std::make_unique<int>(59);
        // Creates a unique_ptr to an array of 15 ints
        std::unique_ptr<int[]> ptr2 = std::make_unique<int[]>(15);
    }
    {
        // You can transfer ownership of the contents of a smart pointer to another pointer by using std::move, which will
        // cause the original smart pointer to point to nullptr.
        // 1. std::unique_ptr
        std::unique_ptr<int> ptr1 = std::make_unique<int>();
        // Change value to 1
        *ptr1 = 1;
        // 2. std::unique_ptr (by moving 'ptr' to 'ptr2', 'ptr' doesn't own the object anymore)
        std::unique_ptr<int> ptr2 = std::move(ptr1);
        int a = *ptr2; // 'a' is 1
        int b = *ptr1; // undefined behavior! 'ptr' is 'nullptr'
        // (because of the move command above)
    }
    {
        std::unique_ptr<int> ptr = std::make_unique<int>(59);
        foo(std::move(ptr));
    }
    {
        // Compare this to:
        int* p = foo_cpp03(); // do I own p? do I have to delete it at some point?
        // it's not readily apparent what the answer is.
    }
}

