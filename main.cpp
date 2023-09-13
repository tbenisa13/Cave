//
//  main.cpp
//  Practice1
//
//  Created by taher benisa on 8/7/19.
//  Copyright © 2019 taher benisa. All rights reserved.
//
#include "DataStructures.hpp"
#include "OOP.hpp"
#include "FindStuffInArrays.hpp"
#include "BitManipulations.hpp"
#include "NumberConversions.hpp"
#include "StringStuff.hpp"
#include "Logic.hpp"
#include "Recursion.hpp"
#include "Common Stuff.hpp"
#include "Algorithms.hpp"
#include "Vectors.hpp"
#include "ConstantTypes.hpp"
//#include "Temp.hpp"
//#include "std_lib_facilities.h"
#include <stdlib.h>
#include <pthread.h>
#include <algorithm>
#include <memory>
//#include "Algorithems"
#include <iomanip>

using std::string;
using std::cout;
using std::map;

// const int bufsize;       // Allowed in C not C++. bufsize must be initalized

int global_uninitialized;           // unintialized global
int static_global_uninitialized;    // static unintialized global
int global_initialized = 323;        // initialized global
int static_global_initialized= 54;  // static intialized global

////////////////////////////////////////////
template <class myType> myType GetMax (myType a, myType b) {
    return (a>b?a:b);
}

//template <class T> inline int MAX_TMPL(T a, T b) {return a >= b ? a : b;}
template<class T> void printVectorTemplate( vector<T>& nums )
{
   int size = static_cast<T>(nums.size());
    cout << "[";
    for( int i = 0; i < size; ++i ) {
        if( i < size-1 ) {
            cout << nums[i] << ", ";
        }
        else {
            cout << nums[i];
        }
    }
    cout << "]";
    cout  << endl;
}

BitManipulations        bitManipulation;
Recursion               rec;
Recursion::Permutation  permutation;
CommonStuff             commonStuff;
Logic logic;
Recursion::Factorial    factorial;
Recursion::Fibonacci    fibonacci;
Recursion::Power        power;
Recursion::Coins        coins;
Recursion::Stars        stars;
Recursion::Combinations combinations;


// !!!: //////////////////////       main()      /////////////////////////
// !!!:
int main(int argc,  char * argv[]) {
    {
        vector<int> cost = { 10, 1, 1, 15, 2, 30, 3 };//10, 1, 1, 15, 2, 30, 3};
        printVector( cout << "costs : ", cost );

        int result = minCost_iter1( cost );
        cout << "1) Minimum cost to reach top: " << result;

        int result2 = minCost_iter2( cost );
        cout << "\n2) Minimum cost to reach top: " << result2;
    }
{
    {
        // NVIDIA Interview Question for Senior Software Development Engineers: I think I nailed it
        // !!!: Given the following set of strings, write a function that stores this information.
                // /Electronics/Computers/Graphics Cards
                // /Electronics/Computers/Graphics Cards
                // /Electronics/Computers/SSDs
                // /Electronics/Computers/Graphics Cards
                // /Electronics/Computers/SSDs
                // /Electronics/TVs
                // /Electronics/Computers/Graphics Cards
                // /Electronics/TVs
                // /Electronics/TVs
                // /Garden
                // /Automotive/Parts
         // !!!: Your datastructure should be able to provide information as such:
                 // / = 11
                 // /Electronics = 9
                 // /Electronics/Computers = 6
                 // /Electronics/Computers/Graphics Cards = 4
                 // /Electronics/TVs = 3
                 // etc
                 // ["/Electronics/Computers/Graphics Cards", "/Garden"]


        string info[11] = {
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/SSDs",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/Computers/SSDs",
            "/Electronics/TVs",
            "/Electronics/Computers/Graphics Cards",
            "/Electronics/TVs",
            "/Electronics/TVs",
            "/Garden",
            "/Automotive/Parts"

        /*"/Electronics/Computers/Graphics Cards",
        "/Electronics/Computers/Graphics Cards",
        "/Electronics/Computers/SSDs",
        "/Electronics/Computers/Graphics Cards",
        "/Electronics/Computers/SSDs",
        "/Electronics/TVs",
        "/Electronics/Computers/Graphics Cards",
        "/Electronics/TVs",
        "/Electronics/TVs",
        "/Garden",
        "/Automotive/Parts",
        "/Automotive/Parts/Engine",
        "/Automotive/Parts/Engine",*/
        };
        int len =  sizeof(info)/sizeof(info[0]);
        map<string, int> info_map = commonStuff.StoreElectronicsInfo( info, len );
        map<string, int>::iterator itr = info_map.begin();
        while(itr != info_map.end() ){
            cout << " " << itr->first << " = " << itr->second << endl;
            itr++;
        }
    }
}

{
    int i = 4;
    int& r = i;
    int j=3;
    r = j;
    ++j;
    cout << i << r << j << endl;
}
    
{
        // !!!: (NVI) !!!:
        /*  — is known as the non-virtual interface (NVI) idiom. It's a particular manifestation of the more general design
         pattern called Template Method (a pattern that, unfortunately, has nothing to do with C++ templates). I call the nonvirtual
         function (e.g., healthValue) the virtual function's wrapper.
         IMPORTANT:
         It may have crossed your mind that the NVI idiom involves derived classes redefining private virtual functions —
         redefining functions they can't call! There's no design contradiction here. Redefining a virtual function specifies how
         something is to be done. Calling a virtual function specifies when it will be done. These concerns are independent. The
         NVI idiom allows derived classes to redefine a virtual function, thus giving them control over how functionality is
         implemented, but the base class reserves for itself the right to say when the function will be called. It may seem odd at
         first, but C++'s rule that derived classes may redefine private inherited virtual functions is perfectly sensible. */
        
        /*  The Template Method Pattern via the Non-Virtual Interface Idiom
         We'll begin with an interesting school of thought that argues that virtual functions should almost always be private.
         Adherents to this school would suggest that a better design would retain healthValue as a public member function
         but make it non-virtual and have it call a private virtual function to do the real work, say, doHealthValue:   */
        class GameCharacter {
        public:
            // non-virtual function: derived classes do not redefine this — see Item 36
            int healthValue() const
            {
                cout << "public: BaseCharacter::healthValue() calling: \n";
                // ... do "before" stuff — see below
                
                int retVal = doHealthValue(); // do the real work
                
                // ... do "after" stuff — see below
                return retVal;
            }

        private:
            // virtual private function: derived classes may redefine this
            virtual int doHealthValue() const
            {
                // ... // default algorithm for calculating
                cout << "private: BaseCharacter::doHealthValue() = 10%\n";
                return 0; // character's health
            }
        };
        
        // !!!: taher: I added this. it is very useful to test the concept of NVI
        class DerivedCharacter1 : public GameCharacter {
        private:
            virtual int doHealthValue() const {
                cout << "private: DerivedCharacter1::doHealthValue() = 50%\n";
                return 50;
            }
        };
        class DerivedCharacter2 : public GameCharacter {
        private:
            virtual int doHealthValue() const {
                cout << "private: DerivedCharacter2::doHealthValue() = 100%\n";
                return 100;
            }
        };

        // driver:
        DerivedCharacter1 derivedCharacter1;
        GameCharacter* pCharacter;
        pCharacter = &derivedCharacter1;        // pointer to base pointing to derived
        pCharacter->healthValue();             cout << endl;
        
        DerivedCharacter2 derivedCharacter2;
        pCharacter = &derivedCharacter2;        // pointer to base pointing to derived
        pCharacter->healthValue();             cout << endl;
        
        GameCharacter  Character;
        pCharacter = &Character;                // pointer to base pointing to base
        pCharacter->healthValue();
    }
    {
        class B {
        private:
            void nonfun( void ) {}
        public:
            virtual void fun( void ) { cout << " In B::fun()\n"; };
        };
        
        class D: public B {
        public:
            virtual void fun( void ) {
                cout << " In D::fun()\n";
            };
        };
        
        // driver
        D d;
        // fun through derived object: no virtual function calling
        d.fun();
        // fun through a pointer to derived object: virtual function calling
        D* pd = &d;
        pd->fun();
        // fun through a pointer to base object: virtual function calling
        B* pb = &d;
        pb->fun();
        
        // fun through base object: no virtual function calling
        B b;
        b.fun();
        // fun through a pointer to base object: virtual function calling
        pb = &b;
        pb->fun();
        pb = &d;
        pb->fun();
        

    }
    {
        // Driver program to test methods of graph class
        Graph g(5); // Total 5 vertices in graph
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 1);
        g.addEdge(0, 3);
        g.addEdge(1, 4);

        cout << "Following is Depth First Traversal\n";
        g.DFS(0);

    }

    {
        map<string, int> word_count;
        map<string, int>::iterator map_it = word_count.begin();
        // *map_it is a reference to a pair<const string, int> object
        cout << map_it->first; // prints the key for this element
        cout << " " << map_it->second; // prints the value of the element
        //map_it->first = "new key"; // error: key is const
        ++map_it->second; // ok: we can change value through an iterator
    }
    {
        multimap<string, string> authors { {"Taher","Benisa"}, {"Taher","Isa"} };;
        // author we'll look for
        string search_item("Taher");
        
        // how many entries are there for this author
        typedef multimap<string, string>::size_type sz_type;
        sz_type entries = authors.count( search_item );
        multimap<string, string>::iterator itr = authors.begin();
        
        
        // get iterator to the first entry for this author
        multimap<string,string>::iterator iter = authors.find(search_item);
        
        // loop through the number of entries there are for this author
        for( sz_type cnt = 0; cnt != entries; ++cnt, ++iter ) {
            cout << iter->second << endl; // print each title
        }
    }
    {

      cout << endl;

      cout << "C++ map: " << endl;
      map<string,int> m { {"Dijkstra",1972}, {"Scott",1976} };
      m["Ritchie"] = 1983;
      cout << "    m[Ritchie]: " <<  m["Ritchie"] << "\n    ";
      for(auto p : m) cout << '{' << p.first << ',' << p.second << '}';
      m.erase("Scott");
      cout << "\n    ";
      for(auto p : m) cout << '{' << p.first << ',' << p.second << '}';
      m.clear();
      cout << endl;
      cout << "    m.size(): " << m.size() << endl;

        cout << std::endl;

      cout << "C++11 unordered_map: " << endl;
      unordered_map<string,int> um { {"Dijkstra",1972},{"Scott",1976} };
        um["Ritchie"] = 1983;
        um["Ritchie"] = 1988;
      cout << "    um[Ritchie]: " <<  um["Ritchie"] << "\n    ";
      for(auto p : um) cout << '{' << p.first << ',' << p.second << '}';
      um.erase("Scott");
      cout << "\n    ";
      for(auto p : um) cout << '{' << p.first << ',' << p.second << '}';
      um.clear();
      cout << endl;
      cout << "    um.size(): " << um.size() << std::endl;

        unordered_map<int,int> um1 { {1,1979},{1,1970} };
        for(auto p : um1) cout << '{' << p.first << ',' << p.second << '}';

      cout << endl;

    }
    {
        std::map<int,int> keyValueMap;

        keyValueMap.insert(std::make_pair(0, 1));

        auto ret = keyValueMap.insert(std::make_pair(0, 2));
        if (!ret.second) ret.first->second = 2;

        int index = keyValueMap.begin()->second;

    }
    {
        /*Exercises Section 2.5
        Exercise 2.24:  Which of the following definitions, if any, are invalid? Why? How would you correct them?*/
        int ival = 1.01;        //  (a) Implicit conversion from 'double' to 'int' changes value from 1.01 to 1
     // int &rval1 = 1.01;      //  (b) Non-const lvalue reference to type 'int' cannot bind to a temporary of type 'double'
        int &rval2 = ival;      //  (c)
        const int& rval3 = 1;   //  (d)
        
        /*Exercise 2.25: Given the preceeding definitions, which, if any, of the following
        assignments are invalid? If they are valid, explain what they do. */
        rval2 = 3.14159;        //  (a) Implicit conversion from 'double' to 'int' changes value from 3.14159 to 3
        rval2 = rval3;          //  (b)
        ival  = rval3;          //  (c)
     // rval3 = ival;           //  (d) Error: Cannot assign to variable 'rval3' with const-qualified type 'const int &'
                                //      My explaination: can't reassign to reference rval3
        
        /*Exercise 2.26:
        What are the differences among the definitions in (a) and the assignments in (b)? Which, if any, are illegal?*/
        int ival1 = 0, &ri = ival1;
        ival1 = ri;             // (a)
        const int &ric = 0;     // (b)
        ri = ival1;             // (c)
        
        /*Exercise 2.27:
        What does the following code print?*/
        int i, &ri1 = i;
        i = 5; ri1 = 10;
        cout << i << " " << ri1 << std::endl;
    }
    {
        int n = 12;
        cout << bitManipulation.Equal_Sum_and_XOR( n ) << endl;
    }
    {

        int n = 11;
        cout << bitManipulation.evenbittogglenumber(n);
    }
{
    int x = 10, y = 11;
    int r = GetMax <int> (x,y);
    
    /*  OR: In this specific case where the generic type T is used as a parameter for GetMax the compiler can find out
        automatically which data type has to instantiate without having to explicitly specify it within angle brackets (like we
        have done before specifying <int> and <long>). So we could have written instead:
        int i,j;   */
    r = GetMax( x, y);
    
    vector<char> letters = {'a', 'b', 'c'};
    printVectorTemplate( letters );
    vector<int> numbers = {'a', 'b', 'c'};
    printVectorTemplate( numbers ); // prints [ 97, 98 ,99]
}
{
    //const int seven_segments_display[10][7] = {1,1,1,1,1,1,0}; //......
    
    enum class eyecolor:char{
        blue,green,brown
    } eye;
}

{
    int p = 5;
    printf("\np before = %d, recurse result = %d, p after = %d\n", p, rec.recurse(p, p), p);
}
{
    vector<vector<int>> grid =  { {1,   2,  3,  4},
                                  {5,   6,  7,  8},
                                  {9,  10, 11, 12},
                                  {13, 14, 15, 16}
                                };
    rec.DFS( grid );
}
    {
        const int size = 5;
        int array[size] = {0, 1, 1, 0, 1};
        cout << "\nFind largest number in: {";
        for( int i=0; i < size; ++i )
            cout << array[i] << " ";
        cout << "}";
        int max = rec.largestNumber_Recursive2( array, 0, size-1 );
        cout << "\nMax number = " << max << endl;
        
        vector<int> varray = {0, 1, 1, 0, 1};
        cout << "\nFind largest number in: ";
        printVector( varray );
        max = rec.largestNumber_Recursive3( varray );
        cout << "Max number = " << max;
    }
    {
        int* p = (int [] ){1, 2, 3};    // Warning: Temporary whose address is used as value of local variable 'p'                                            // will be destroyed at the end of the full-expression
        cout << endl <<  p[2] << endl;
    }
    {
    }
{
    int total_steps = 4;
    cout << "\n\n1) Possible ways a child can run up the stairs, recursively, is ";
    cout << combinations.countWays_recursively( total_steps );

    cout << "\n\n2) Possible ways a child can run up the stairs is ";
    cout << combinations.countWays_iteratively( total_steps );
    
    cout << "\n\n3) Possible ways a child can run up the stairs is ";
    cout << combinations.countWays_recursively_memoization( total_steps );
}
{
    unsigned int number = 12345;
    //function calling
    commonStuff.extractDigits( number );
}
    {
        // {1, 0, 0, 0, 1} = 2; { 1, 0, 0, 1, 0, 0, 0, 1 } = 2; { 1, 0, 0, 1, 0, 0, 0, 1, 0 } = 2;
        //                  {1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0}
        vector<int> seats = {1,0,1,1,0,0,0,1,1,1,0,0,1,1,1,0};
        int result = maxDist_toClosestPerson( seats );
        printVector( cout << "\n1) Given Bench:", seats ); cout << "   Maximum distance for nearest person: " << result << endl;

        result = maxDist_toClosestPerson_2( seats );
        printVector( cout << "\n2) Given Bench:", seats ); cout << "   Maximum distance for nearest person: " << result << endl;
    }
    {
        string student_attendance = "OLLOAOLLO";
        cout << "\nIs Student Attendance Record \"" << student_attendance << "\" OK? ";
        bool result = checkAttendance( student_attendance );
    }
    {
        int number = 391;   // 324-->299   4321-->3999     7384-->6999     12345-->12345

        int result = monotoneIncreasingDigits( number );
        cout << "Monotone Increasing Digits for " << number << " is " << result;
    }
    {
        int number = 0;
        bool result = isDivisible_byItsDigits( number );
        cout << "\n\nIs " << number << " Divisible by its Digits? " << (result? "YES" : "NO");
    }
{
    // tuple
     tuple<int,char> foo (10,'x');
     auto bar = make_tuple ("test", 3.1, 14, 'y');

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
    
// !!!: //////////////  Assigin Vectors     ////////////////////////
{
    vector<int> vector1 = {1, 2, 3};
    vector<int> vector2 = {4, 5, 6, 7};
    printVector(cout << "\nVector A: ", vector1);
    printVector(cout << "Vector B: ", vector2);

    assigingVectors(vector1, vector2);
    
    printVector(cout << "After assigning B to A: ", vector1);
}
    
// !!!: //////////////  Nondecreasing Array     ////////////////////////
{
    //vector<int> array = {10, 5, 2};      // False
    //vector<int> array = {4, 5, 1, 7};      // True
    //vector<int> array = {1,0,1,0};       // False
    //vector<int> array = {6, 5, 2, 1};       // False
    //vector<int> array = {6, 5, 7, 1};       // False
    //vector<int> array = {4, 5, 7, 1};       // True
    vector<int> array = {5,3,4,4,7,3,6,11,8,5,11};       // False
    //vector<int> array = {10, 5, 2,      6,5,8};       // False
    //vector<int> array = {4, 5, 1, 7};     // True: Change 1 to 6 or 5 or 7
    //vector<int> array = {1, 2, 1, 5};     // True: Change 2 to 1, or 1 to 2 or 1 to 3
    //vector<int> array = {1, 1, 1, 1};       // True: No Change required
    //vector<int> array1 = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    //vector<int> array1 =  {4, 5, 2, 1, 7}; //{5,7,11,11,9};   {4,5,7,7,13};

    printVector(cout << "\n1) Can you Make Array NonDecreasing by Modifing at most ONE Element: ", array);
    
    bool result = Convert_toNondecreasing_Array_1change_1(array);
    cout << "   result = " << ((result == true)? "true" : "false") << endl;
    
    
    printVector(cout << "\n2) Can you Make Array NonDecreasing by Modifing at most ONE Element: ", array);
    result = Convert_to_Nondecreasing_Array_with_one_change_2(array);
    cout << "   result = " << ((result == true)? "true" : "false") << endl;

    printVector(cout << "\n3) Can you Make Array NonDecreasing by Modifing at most ONE Element: ", array);
    result = Convert_to_Nondecreasing_Array_with_one_change_3(array);
    cout << "   result = " << ((result == true)? "true" : "false") << endl;

    printVector(cout << "\nTotal Steps to Make NonDecreasing Array: ", array);
    result = totalSteps_toMake_NonDecreasing_Array( array );
    cout << "   result = " << result << ":\t"; printVector(array);
    
    vector<int> array1 = {5,3,4,4,7,3,6,11,8,5,11};       // False
    printVector(cout << "\nTotal Steps to Make NonDecreasing Array: ", array1);
    result = totalSteps_toMake_nonDecreasing_Array2( array1 );
    cout << "   result = " << result << ":\t"; printVector(array1);
}

// !!!: ////////////////////////     Most Common Word     ////////////////////////////
{
    string paragraph = "one two three. hi one two";
    //vector<string> banned_words = {"", ""};
    vector<string> banned_words = {" ", " "};
    //vector<string> banned_words = {"one", "TWO"};
    //vector<string> banned_words = {"ONE", "TWO"};
    cout << "\nMost CommonWord in \"" << paragraph << "\"" << ", Execluding \"";
    for( string word: banned_words) {
        cout << word << " ";
    } cout << "\" \n";
    
    string result = mostCommon_unbannedWord( paragraph, banned_words );
    cout << "result = \"" << result << "\" \n";
    
    // given set of keys
    vector<string> words =
           { "geeks", "for", "geeks", "a", "learn", "be", "computer", "taher",
             "science", "taher", "fire", "taher", "taher", "data", "geeks" };
    cout << "\nMost CommonWord from Geeks:\n";
    for( string word: words ) cout << word << " ";       cout << "\" \n";

    mostCommonWord_geeks( words );
    
    cout << "\nMost CommonWord from Taher:\n";
    mostCommonWord_mySol( words );
}

// !!!: ////////////////////////     Least Common Number     ////////////////////////////
{
    vector<int> v1 = {6, 7, 10, 25, 30, 63, 64};
    vector<int> v2 = {1, 4, 5, 6, 7, 8, 50};
    vector<int> v3 = {1, 6, 10, 14};
    cout << "\nLeast Common Number for Three Arrays: \n" ;
    printVector(cout << "\t", v1);
    printVector(cout << "\t", v2);
    printVector(cout << "\t", v3);
    int result = leastCommonNumber(v1, v2, v3);
    cout << "\tResult: " << result;
}

// !!!: ////////////////////////     Intersection of Two Arrays     ////////////////////////////
{
    vector<int> a1 = {1, 2, 2, 1};
    vector<int> a2 = {2, 2};
    vector<int> result = intersection_2Arrays(a1, a2);
    cout << "The 2 arrays interset at: ";
    printVector(result);
}

// !!!: ///////////////////      Bits and Pieces     ///////////////////
// !!!: ///////////////////      Swap 2 Bits         ///////////////////
{
    unsigned char data = 0b10100000;
    unsigned char bit1 = 7, bit2 = 0;
    cout << "\n\nSwap bits " << bit1 << " and " << bit2 << "       = " << bitset<8>(data) << endl;
    unsigned char result = bitManipulation.swap2Bits(data, bit1, bit2);
    cout << "After swapping the bits = " << hex << bitset<8>(result)  << endl << endl;
    //cout << "After swapping the bits = " << hex << (unsigned)result << endl << endl;

    cout << "My Swap bits " << bit1 << " and " << bit2 << "    = " << bitset<8>(data) << endl;
    unsigned char result1 = bitManipulation.swap2BitsMySolution(data, bit1, bit2);
    cout << "After swapping the bits = " << hex << bitset<8>(result1);
    //cout << "After swapping the bits, data value is: " << hex << (unsigned)result1 << endl;
}
    
// !!!: ///////////////////      Swap Nibbles in a Byte    ///////////////////
{
    unsigned char byte = 0xEF;
    cout << "\n\nSwap Nibbles in Byte = 0x" << hex << static_cast<unsigned int>(byte);
    unsigned char newbyte = bitManipulation.Swap_Nibbles_In_Byte(byte);
    cout << "\nSwapped Nibbles      = 0x" << (unsigned int)newbyte << endl;
}
{
    unsigned char c = 0xBA;
    cout << "\n\t\t\t\t    c = " << hex << (unsigned int)(c) << endl;
    // return value promoted from 'unsigned char' to 'int'
    int result = bitManipulation.Swap_Nibbles_In_Byte(c);
    cout << "Swap Nibbles in Bytes = " << result << endl;
}
{
    unsigned int n = 0xABCDEF;
    cout << "\n\t\t\t\t\t  n = " << n << endl;
    unsigned int result = bitManipulation.Swap_Nibbles_In_Integer(n);
    cout << "Swapped nibbles in word = " << result << endl;
}
{
    byte b = byte(0b1110111);
    cout << "\nSwap Even and Odd Bits in a Byte: " << bitset<8>(int(b)) << endl;
    byte result = bitManipulation.Swap_EvenOdd_Bits_Byte(b);
   // cout << int(result) << endl;
    cout << "                          result: " << bitset<8>(int(result))  << endl;
}
{
    unsigned int number = 0b111001;
    cout << "\nn                        = " << bitset<8>(number) << endl;
    unsigned int result1 = bitManipulation.Swap_EvenOdd_Bits_Integer(number);
    cout << "Swaped Even and Odd Bits = " << bitset<8>(result1)  << endl << endl;
}
{
    unsigned int number = 0b111001;
    cout << "\nn                       = " << bitset<8>(number) << endl;
    unsigned int result2 = bitManipulation.Swap_2Bits_Nibble(number);
    cout << "Swaped 2 Bits of Nibble = " << bitset<8>(result2)  << endl << endl;
}
{
    unsigned int number = 0x12ABCDEF;
    cout << hex << "number = " << number << endl;
    unsigned int result3 = bitManipulation.Swap_Bytes_In_Integer(number);
    cout << "Swaped Bytes of Integer = " << result3 << endl;
}
{
    unsigned int number = 0x12ABCDEF;
    unsigned int result4 = bitManipulation.Swap_Halfword_In_Integer(number);
    cout << "Swaped Half-Word of Integer = " << result4 << endl;
}
{
    unsigned int integer = 0b00101111;
    int fromPos          = 1;
    int toPos            = 5;
    int range            = 3;
    cout << "Given a number = " << bitset<8>(integer) << ", Swap " << range << " bits from " << fromPos << " to " << toPos << endl;
    int res = bitManipulation.SwapRangeOfBits(integer, fromPos, toPos, range);
    cout << "        Result = " << bitset<8>(res) << endl;
}
{
    int number = 0b10001;
    bitset<32> x(number);
    // all are legal and set bit0
    x[0] = 1;       // ok
    x[0] = 2;       // ok
    x[0] = true;    // ok

    cout << "\nDoes number (" << bitset<16>(number) << ") contain 2 or more consecutive 1s: ";
    int result = bitManipulation.inspect_bits(number);
    cout << (result? "\nYes" : "\nNo");
}
{
    char character = 'A';
    int lower_upper = bitManipulation.is_char_lower_or_upper( character );
    cout << "\nIs '" << character << "' Lower or Upper?" << (lower_upper == 0? " Lower" : " Upper");
}

// !!!:  /////////////////     Equal Length Of Zeros Ones     ////////////////
{
    vector<int> nums = { 1, 1, 1, 0, 0, 0, 1, 1};
    printVector(cout << "\n\nFind Equal Length Of Zeros and Ones: ", nums);
    int result = bitManipulation.EqualLengths_of_Zeros_Ones_1(nums);
    cout << "1) result = " << result << endl;
    
    result = bitManipulation.findEqualLengths_of_Zeros_Ones_2(nums);
    cout << "2) result = " << result << endl;
}
{
    short x = 5, y = 11;
    long result = bitManipulation.multiplyWithShift(x, y);
    cout << "Multiple by Shifting = " << result << endl;
}

// !!!: ////////////////////////     Compute Sign of Integer     ////////////////////////////
{
    int number = -3;
    int sign = bitManipulation.Compute_Sign_of_Integer_1(number);
    cout << "\n1) Sign of Integer " << number << " is " << (sign? "Positive" : "Negative");

    sign = bitManipulation.Compute_Sign_of_Integer_2(number);
    cout << "\n2) Sign of Integer " << number << " is " << (sign? "Negative" : "Positive") << endl;
}

// !!!: ////////////////////////      Check Opposite Sign      ////////////////////////////
{
    int a = 0, b = 0;;
    int sign = bitManipulation.CheckOppositeSign(a, b); // check signs of a & b
    cout << "\nDo Integers " << a << " and " << b << " have the same sign? " << (sign? "No" : "Yes");
}

// !!!: ////////////////////////      Ones Left Zeros Right      ////////////////////////////
{
    //int zerosones[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int zerosones[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //int zerosones[20] = {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1};
    int arraySize = 20;
    //int array[10] = {0,0,0,0,0,1,0,0,0,0};
    //int zerosones[20] = {0,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,0,1};  //important case
    //int zerosones[10] = {1,1,1,1,1,1,1,1,1,1};
    //int zerosones[10] = {0,0,0,0,0,1,1,1,1,1};
    //int zerosones[10] = {1,1,1,1,1,0,0,0,0,0};
    //int zerosones[10] = {0,1,0,1,0,1,0,1,0,1};
    //int zerosones[1] = {1};
    cout << "OnesLeftZerosRight():\n\t";
    for(int i=0; i < arraySize; i++)
        cout << zerosones[i];
    //cout << "a[" << i << "] = " << array[i] << endl;
    
    bitManipulation.OnesLeftZerosRight(zerosones, arraySize);
    
    cout << endl << "\t";
    for(int i=0; i < arraySize; i++)
        cout << zerosones[i];
    
}

// !!!: /////////////////         Count Odds and Even Bits      ////////////////////////
{
    int number = 1103;
    int odd_even = bitManipulation.is_number_odd_or_even(number);
    cout << "\nIs " << number << " Odd or Even?" << (odd_even == 0? " Even" : " Odd");
}
{
    unsigned int integer = 0b101;    // 0b10101010101010101010101010101010
    //cout << "\nn                     = " << bitset<8>(number) << endl;

    bool result = bitManipulation.Does_Interger_Have_Alternating_Bits_1(integer);
    cout << "\nDoes number = " << bitset<8>(integer) << " Have Alternating Bits (1) = " << (result?"yes":"no")  << endl;

    bool result1 = bitManipulation.Does_Interger_Have_Alternating_Bits_2(integer);
    cout << "Does number = " << bitset<8>(integer) << " Have Alternating Bits (2) = " << (result1?"yes":"no")  << endl;
}
{
    int number = 50;
    cout << dec << "\n1) Generate Number Having Alt Bit Pattern My implementation: \n" << "   Number = " << number << ", Result: " << endl;
    vector<int> result = bitManipulation.generateAlternateBits1(number);
    for(int i : result) { cout << "\t\t\t\t\t\t" << i << "  = "; print_DecimalToBinary(i); cout << endl; }

    cout << "\n2) Generate Number Having Alt Bit Pattern: \n" << "   Number = " << number << ", Result: ";
    bitManipulation.generateAlternateBits2(number);
    for(int i : result) {
        cout << "\n\t\t\t\t\t\t" << i << "  = " << DecimalToBinary_mine(i);
}
{
    int n = 0b01101101;
    int result = bitManipulation.CountSetBits(n);
    cout << "\nSetBits(" << bitset<32>(n) << ") = " << bitset<32>(result) << endl;
}
{
    unsigned int number = 0b0111111110000;
    int frombit = 7;
    int tobit   = 7;

    cout << "\nGetBits() Mine: mask from bits = "<< frombit << " to " << tobit << endl;
    cout << " number  = " << DecimalToBinary_mine(number) << endl;
    unsigned int r1 = bitManipulation.getBits1(number, frombit, tobit);
    cout << " result = " <<  DecimalToBinary_mine(r1) << endl;
    
    cout << "\nGetBits() Ritchi: needs work" << endl;
    unsigned int r = bitManipulation.getBits2(number, frombit, tobit);
    cout << " result = " <<  DecimalToBinary_mine(r) << endl;
}

// !!!:  /////////////////     Set Odd and Even Bits     ////////////////
{
    unsigned int number = 0b00001010;    // Try 0b01010101, ob11
    cout << "\nSet EVEN Bits: n = " << bitset<32>(number);
    int res  = bitManipulation.setEvenBits_mine(number);
    cout << "\n       My result = " << bitset<32>(res);
    
    cout << "\n\nSet ODD Bits:  n = " << bitset<32>(number);
    res = bitManipulation. SetOddBits_mine(number);
    cout << "\n       My result = " << bitset<32>(res);
    res  = bitManipulation.SetOddBits_geek(number);
    cout << "\n     Geek result = " << bitset<32>(res);

    cout << "\n\nOdd & Even        = " << (bitset<32>(bitManipulation.SetOddBits_mine(number)) & bitset<32>(bitManipulation.setEvenBits_mine(number)) ) << endl;
}

// !!!: ////////////////////////   Square Wave Pattern   //////////////////////////////
//
{
    string str = "0101010";   // 1001010001, 3
    cout << "\n\nDrawing the pattern " << str << "\n\t\t\t\t\t";
    bitManipulation.DrawPattern( str );
    
    int result = bitManipulation.CountNegativePulses( str );
    cout << "\n\tNegative Pulses = " << result;

    result = bitManipulation.CountPositivePulses( str );
    cout << "\n\tPositive Pulses = " << result;

    vector<int> edges = bitManipulation.PulsesEdges( str );
    cout << "\n\tNegative Edges  = " << edges[0] << "\n\tPositive Edges  = " << edges[1] << endl;
}

// !!!: ////////////////  Longest Substring Of 1s After Removing One Element (0)  ////////////////
{
    // 110111000111111100 = 7 // 11110111111 = 10 // 1111000111111 = 6 (tricky)
    // [1,1,1] = 2             // [1,1,0,1] = 3    // [0,1,1,1,0,1,1,0,1] = 5 //  [1,1,0,0,1,1,1,0,1] = 4
    // [0,0,0] = 0
    string str = "110011101"; // "11101101"; 1101 = 3, 110011101 = 4, 011101101 = 5
    cout << "\n\n1) Longest Substring of 1's After Removing 1 Element in string = \"" << str << "\":" << endl;
    int max_bit_count = bitManipulation.longestSubstringOf1s_afterRemoving_1bit_1(str);
    cout << dec << "     my result = " << max_bit_count;

    cout << "\n2) Longest Substring of 1's After Removing 1 Element in string = \"" << str << "\":" << endl;
    max_bit_count = bitManipulation.longestSubstringOf1s_afterRemoving_1bit_2(str);
    cout << dec << "     my result = " << max_bit_count << endl;

// !!!: ////////////////  Longest Subsequence Of 1s After Flipping 0 to 1   ////////////////
    // needs serious work
    int integer = 0b11111;//0xFFFFFFFF ;
    cout << "\n1) Longest Subsequence Of 1s After Flipping 1 Element in integer = " << integer << ":\n     my result = " << bitset<32>(integer);
    // makes use of longestSubstringOf1s_AfterRemoving1Element( str ) above
    max_bit_count = bitManipulation.longestSubsequenceOf1s_afterFlipping_1bit( integer );
    cout<< " = " << max_bit_count;

    // from Cracking the Interview Code. !!!: does not work with 2 or more consicutavie 0s
    cout << "\n2) Flip a Bit to Win, from wiki:\n     wiki result = " << bitset<32>(integer);
    max_bit_count = bitManipulation.flipBit_to_Win( integer );
    cout<< " = " << max_bit_count;
}
    
// !!!: /////////////////////////      Clear Bits From MSB To ithBit    ////////////////////
{
    unsigned char byte = 0b10011101;
    int pos = 4;
    cout << "\nClear Bits From MSB to ith-bit " << pos <<" for number = " << bitset<8>(byte) << endl;
    unsigned char result = bitManipulation.Clear_Bits_From_MSB_To_ithBit(byte, pos);
    cout << bitset<8>( result) << endl;
}
    
// !!!: ///////////////////////////   XOR   ///////////////////////////////////////
{
    unsigned int number = 6;
    cout << "Number        = " << bitset<32>(number) << endl;
    int XORres = bitManipulation.computeXOR1(number);
    cout << "computeXOR1() = " << bitset<32>(XORres) << endl;
    
    XORres = bitManipulation.computeXOR2(number);
    cout << "computeXOR2() = " << XORres << endl << endl;
}
    
// !!!: ////////////////////////////      Update Bits     //////////////////////////
{
    int n = 0b11110101111;
    int m = 0b0;
    int beginBit = 4;
    int endBit   = 6;
    cout << "Update Bits with Range positions: " << beginBit << ", " << endBit << endl;
    cout << "Original bits      = " << bitset<11>(n) << endl;
    cout << "Insert bits        = " << bitset<3>(m);

    int newbits = bitManipulation.Update_Bits_1(n, m, beginBit, endBit);
    cout << "\nUpdateBitsVersion1 = " << bitset<11>(newbits);

    int newbits1 = bitManipulation.Update_Bits_2(n, m, beginBit, endBit);
    cout << "\nUpdateBitsVersion2 = " << bitset<11>(newbits1);
}
    
// !!!: /////////////////////      Divide Without Using Division Operator       ///////////////////
{
    int dividend = INT_MIN;     // INT_MIN = -2147483648
    int divisor  = -1;     // INT_MIN = -INT_MIN
    long int div1 = bitManipulation.DivideWithoutUsingDivision_1( dividend, divisor );
    cout << "\n\n1) Divide Without Using Division " << dividend << "/" << divisor << " = " << div1;

    int div2 = bitManipulation.DivideWithoutUsingDivision_2( dividend, divisor );
    cout << "\n2) Divide Without Using Division " << dividend << "/" << divisor << " = " << div2;
}

// !!!: ////////////////////////      Big Indian Little Indian       ////////////////////////////
{
    bool big_little_indian = bitManipulation.BigIndianLittleIndian();
    cout << "\nIs System LITTLE_INDIAN or BIG_INDIAN? \nresult: " << ((big_little_indian)? "LITTLE_INDIAN" : "BIG_INDIAN") << endl;
}

// !!!: ////////////////////////      Change End Ianness       ////////////////////////////
{
    uint32_t u32CheckData  = 0x11223344;
    uint32_t u32ResultData =0;
    u32ResultData = bitManipulation.ChangeEndianness_1(u32CheckData);  //swap the data
    printf("\nOriginal Integer = 0x%x\n",u32ResultData);
    u32CheckData = u32ResultData;
    u32ResultData = bitManipulation.ChangeEndianness_1(u32CheckData);//again swap the data
    printf("1) Afetr Changing Endianness = 0x%x\n",u32ResultData);
    
    u32ResultData = bitManipulation.ChangeEndianness_2(u32CheckData);//again swap the data
    printf("2) Afetr Changing Endianness = 0x%x\n",u32ResultData);
}
    
// !!!: ////////////////////////      Reverse Bits       ////////////////////////////
{
    //unsigned int bits = 0x1;
    //unsigned int bits = 0b00000000000000000000000000000001;
    unsigned int bits = 0b00000001000000001111111111111111;
    //unsigned int bits = 0b11110000000011110000111111110000;
    cout << "ReverseBits1(): Before reversing " << bitset<32>(bits) << endl;
    unsigned int revbits = bitManipulation.ReverseBits1(bits);
    cout << "ReverseBits1(): After reversing  " << bitset<32>(revbits) << endl << endl;

    cout << "ReverseBits2(): Before reversing " << bitset<32>(bits) << endl;
    bitManipulation.ReverseBits2(bits);
    cout << "ReverseBits2(): After reversing  "  << bitset<32>(bits) << endl << endl;

    cout << "ReverseBits3(): Before reversing " << bitset<32>(bits) << endl;
    unsigned int result = bitManipulation.ReverseBits3(bits);
    cout << "ReverseBits3(): Before reversing " << bitset<32>(result) << dec ;
}

// !!!: ////////////////////////      Rotate Bits Left       ////////////////////////////
{
    //int bits = 0b11111111000000000000000000000000;
    int bits = 0xFF00FF;
    int no_of_left_rotations = 15;
    
    cout << "\n\nRotate Bits    \"" << bitset<32>(bits) << "\" Left by " << no_of_left_rotations;
    int result = bitManipulation.RotateBitsLeft_1(bits, no_of_left_rotations);
    cout << "\n1) Rotated Bits " << bitset<32>(result);

    bitManipulation.RotateBitsLeft_2(bits, no_of_left_rotations);
    cout << "\n2) Rotated Bits " << bitset<32>(result);

    unsigned int ubits = 0xFF0000FF;
    bitManipulation.rotateBitsLeft_3(ubits, no_of_left_rotations);
    cout << "\n3) Rotated Bits " << bitset<32>(result);
}
{
    int x = 5;
    int y = 7;
    cout << "Before SwapNumbers(): " << x << " and " << y <<endl;
    bitManipulation.SwapNumbers_NotUsingtemp(x, y);
    cout << "After SwapNumbers(): " << x << " and " << y <<endl<< endl;
}
// !!!: /////////////////         Count Trailing ZEROS       ////////////////////////
{
    int number = 0b00000010;
    int count = bitManipulation.trailingZeros_1( number );
    cout << "\nTrailing ZEROS for Number " << bitset<8> (number) << ", is " << count;
    
    count = bitManipulation.trailingZeros_2( number );
    cout << "\nTrailing ZEROS for Number " << bitset<8> (number) << ", is " << count;
}

{
    int number = 2, _power = 3;
    int result1 = power.power_recursive1( number, _power );
    cout << "\n1) Raise " << number << " to the power of " << _power << " = " << result1 << endl;
    
    int result2 = power.power_Iterative( number, _power );
    cout << "2) Raise " << number << " to the power of " << _power << " = " << result2 << endl;
    
    int result3 = power.Raise_Number_To_Power3( number, _power );
    cout << "3) Raise " << number << " to the power of " << _power << " = " << dec << result3 << endl;
}

// !!!: ////////////////////////      Print Stars      ////////////////////////////
{
    int _stars = 4;
    string str = "" ;
    cout << "\nPrint 4, 3, 2, 1 stars";
    cout << "\nVersion 1:\n";
    stars.printStars_Recursive1( _stars );
    
    cout << "Version 2:\n";
    stars.printStars_Recursive2( _stars );
    
    cout << "Version 3:\n";
    stars.printStars_Recursive3( _stars );
    cout << "Version 4:\n";
    
    stars.printStars_Recursive4( _stars, str );
    cout << "Version 5:\n";
    stars.printStars_Recursive5( _stars, str);
    
    cout << "Version 6:\n";
    stars.printStars_Recursive6( _stars );
    
    // printStars13() and printStars14() are the same
    cout << "Version 7:\n";
    stars.printStars_Recursive7( _stars );
    
    cout << "Version 8:\n";
    stars.printStars_Recursive8( _stars, str );
    
    cout << "Non Recursive Version 1:\n";
    stars.printStars_Iterative1( _stars );
    
    cout << "Non Recursive Version 1.1:\n";
    stars.printStars_Iterative11( _stars );
    
    cout << "Non Recursive Version 2:\n";
    stars.printStars_Iterative2( _stars );
    
    cout << "Non Recursive Version 3:\n";
    stars.printStars_Iterative3( _stars );
}


    {
// !!!: ///////////     Recursion Functions     ///////////
        int n = 25;
        cout << "\n\nRecursive Fun1 for n = " << n << endl;
        int result = rec.increment_recursive(n);
        cout << "Result = " << result;

        cout << "\n\nNumber of hops to reach the bottom of stairs with " << n << " steps" << endl;
        result = rec.fiveStep_Jumps(n);
        cout << "Result = " << result;

        cout << "\n\nIterative Fun2 for n = " << n << endl;
        result = rec.which_bin_iterative( n );
        cout << "Result = " << result << endl;

        for(int n=0; n <= 25; n++) {
            // divide n by 5: n/5
            result = rec.which_bin_recursive_2(n); // 1-4=4, 5-24=20, 25-125=100, 125-625=500, 625-3125=2500, 3125-15625 = 12500
            cout << "\nRecursive Fun3 for n = " << n;
            cout << "\tResult = " << result;
        }

// !!!: ///////////     Power of 2      //////////
        cout << endl << endl;
        n = 3;
        cout << "\nPower of 2 for " << n << " is: ";
        power.printPowersOf2( n );

        bool bresult = power.isPowerOf2_recursive( n );
        cout << "\n\nIs " << n << " Power of 2 recursively? ";
        cout << (bresult? "YES" : "NO");

        bresult = power.isPowerOf2_iterative( n );
        cout << "\nIs " << n << " Power of 2 iteratively? ";
        cout << (bresult? "YES" : "NO");

        int  a = 3, b = 3;
        result = power.power_recursive( a, b);
        cout << "\n\nPower Recursive for " << a << " to power " << b << " = " << result;

        n = 4;
        int m = 2;
        int o = 3;
        cout << "\n\nRecursive Fun4 for n = " << n << ", m = " << m << ", o = " << o << endl;
        rec.recursiveFun4(n, m , o);

        n = 15;
        cout << "\nRecursive Fun5 for n = " << n << endl;
        result = rec.recursiveFun5(n);
        cout << "n = " << n << " result = "<< result << endl;
        /*while( n < 16 ) {
            result = recursiveFun5(n++);
            cout << "n = " << n << " result = "<< result << endl;
        }*/
    }



    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

{
    bool result = commonStuff.isHappy(18);
    cout << result;
}
    
    
// !!!: /////////////////         Logic OR AND      ////////////////////////
{
    bool A = true, B = true;
    cout << "\nLogic A || B: \n";
    bool result = logic.LogicOR(A, B);
    cout << "Logic " << A << " || " << B << " = " << result << endl;

    cout << "\nLogic A && B: \n";
    result = logic.LogicAND(A, B);
    cout << "Logic " << A << " && " << B << " = " << result << endl;
}
{
    int digit = 10;
    char c = digit_to_hex_char(digit);
    cout << "\ndigit_to_hex_char(" << digit << ") = " << c;
}
        

// !!!: ////////////////////////      Move Zeros to Left      ////////////////////////////
{
    vector<int> a = {1, 10, 20, 0, 59, 63, 0, 88, 0};
    printVector(cout << "Original Array: ", a);
      
    move_zeros_to_left(a);
      
    printVector(cout << "After Moving Zeroes to Left: ", a);
}

// !!!: ////////////////////////      Rearrange Array Max_Min Alternatively      ////////////////////////////
{
    // Given a SORTED array of POSITIVE integers
    vector<int> a1 = {1,2,3,4,5,16};//{10,20,30,40,50,60,70,80,90,100,110}; //{1,2};
    printVector(cout << "\n\nOriginal Array:                        ", a1);

    Rearrange_Array_Max_Min_Alternatively_1(a1);
    printVector(cout << "(1) After Rearanging Array Max_Min...: ", a1);

    vector<int> a2 = {1, 2, 3, 4, 5, 16};//{10,20,30,40,50,60,70,80,90,100,110}; //{1,2};
    Rearrange_Array_Max_Min_Alternatively_2(a2);
    printVector(cout << "(2) After Rearanging Array Max_Min...: ", a2);
}

// !!!: ////////////////////////      Rearrange Array Pos_Neg Alternatively      ////////////////////////////
{
    // array of even length, and consisting of an equal number of positive and negative integers.
    vector<int> a = {-3, -1, 2, 5, 2, -4};  //{1,-1};
    printVector(cout << "\nOriginal Array: ", a);
    vector<int> result = Rearrange_Array_Pos_Neg_Alternatively(a);
    printVector(cout << "After Rearanging Array Pos_Neg...: ", result);
}

// !!!: ////////////////////////      Sort Array By Parity      ////////////////////////////
{
    vector<int> a = {3,1,-2,-5,2,-4};
    printVector(cout << "\nOriginal Array: ", a);
    vector<int> result = sortArrayByParityII(a);
    printVector(cout << "After Rearanging Array Even_Odd...: ", result);
}
{
    int x = +-2;
    string s = "    +43"; //"+2"; //words and 987"; // 4193 with words";   //"    -43";
    int result = atoi(s);
    cout << result << endl;
}

// !!!: ///////////////////      Pivot Array     ////////////////////
{
    vector<int> a = {9,12,5,10,14,3,10};
    int pivot = 10;
    printVector(cout << "\nOriginal Array:                   ", a);
    vector<int> result = pivotArray_1(a, pivot);
    printVector(cout << "1) Array Around Pivot value = " << pivot << ": ", result);

    result = pivotArray_2(a, pivot);
    printVector(cout << "2) Array Around Pivot value = " << pivot << ": ", result);
}

// !!!: ///////////////////      Unique Names     ////////////////////
    {
        vector<string> names1 = {"Ava", "Emma", "Olivia"};
        vector<string> names2 = {"Olivia", "Sophia", "Emma"};
        cout << "\nUnique Names in Two Strings: ";
        cout << "\nNames 1: ";
        //printGenericVector(names1);
        for(string str : names1) {
            cout << str << ", ";
        }
        cout << "\nNames 2: ";
        for(string str : names2) {
            cout << str << ", ";
        }
        
        vector<std::string> result = unique_names(names1, names2);
        cout << "\nResult : ";
        for(string str : result) {
            std::cout << str << ", "; // should print Ava Emma Olivia Sophia
        }
    }

// !!!: ///////////////////      Does String Have Unique Chars     ////////////////////
    {
        char* str = const_cast<char* >("012");
        cout << endl << str[0] << endl;
        printf("%d \n", str[0]);

        bool result = isUniqueChars(str);
        cout << "\nDoes \"" << str << "\" Have Unique Chars? " << (result?"YES":"NO") << endl;
    }

// !!!: ///////////////////      Find First K Occurances of Element in Array    ////////////////////
    {
        int k = 3;
        cout << "\nFind First " << k << " Occurances of an Element in Array:";
        vector<int> array = {1, 7, 4, 3, 4, 8, 1, 4};
        printVector(cout << "\nOriginal Array: ", array);
        int result = Find_First_K_Occurances_of_Element(array, k);
        cout << "Result = " << result;
    }

// !!!: ///////////////////      Are Two Arrays Equal     ////////////////////
    {
        vector<int> A = {1,2,1,1,2};  // {4, 18, 19, 19, 3, 10, 2 };
        vector<int> B = {1,2,2,1,1};  //{10, 18, 10, 3, 2, 13, 19};
        // Using Map
        bool result = Are_Arrays_Equal_1(A, B, A.size());
        cout << "\n\n1) Are The Two Following Arrays Equal? ";
        printVector(cout << "\nArray A: ", A);
        printVector(cout << "Array B: ", B);
        cout<< (result?"YES":"NO");
        cout << " The Two Arrays Are Equal " << (result?"Equal":"Not Equal");

        // Using Array
        result = Are_Arrays_Equal_2(A, B, A.size());
        cout << "\n\n2) Are The Two Following Arrays Equal? ";
        printVector(cout << "\nArray A: ", A);
        printVector(cout << "Array B: ", B);
        cout<< (result?"YES":"NO");
        cout << " The Two Arrays Are Equal " << (result?"Equal":"Not Equal");

        array<int, 5> C {1,2,1,1,2};     // repeated chars
        array<int, 5> D {1,2,2,1,1};     // repeated chars
        // does not work for repeated integers
        // Notice decleration of function: bool Are_Arrays_Equal_CPP(array<int, 5> A, array<int, 5> B)
        result = Are_Arrays_Equal_CPP(C, D);
        cout << "\nAre The Two Arrays Equal CPP? " << (result?"YES":"NO") << endl;
    }
    {
        commonStuff.isPrime(5) ? cout << " true\n" : cout << " false\n";
    }


// !!!: ////////////////////////      Find Largest Number Recursively      ////////////////////////////
    {
        const int array[] = {-5, -10, -1, -8, -9, -2};
        int left = 0;
        int right = sizeof(array)/sizeof(array[0]) - 1;
        int result = rec.largestNumber_Recursive1(array, left, right);
        cout << dec << "\nLargest Number Recursive " << result << endl << endl;
    }

// !!!: ////////////////////////      Coin Change      ////////////////////////////
    {
        int _coins[] = { 1, 2, 3};
        int size = sizeof( _coins ) / sizeof(_coins[0]);
        int amount = 4;
        cout << "\n1) Recursive Ways to Make Change for Amount = " << amount << ", coin = {1, 2, 3}" << endl;
        int result1 = coins.Change_Recursive1( _coins, size, amount );
        cout << "   Number of Coin Changes = " << result1 << endl;

        int index{0};
        vector<int> vcoins = {1, 2, 3};
        cout << "\n2) Recursive Ways to Make Change for Amount = " << amount << ", coin = {1, 2, 3}" << endl;
        int result2 = coins.Change_Recursive2( vcoins, index=0, amount );
        cout << "   Number of Coin Changes = " << result2 << endl;
        
        // !!!: my solution: hope it works
        cout << "\n3) Recursive Ways to Make Change for Amount = " << amount << ", coin = {1, 2, 3}" << endl; // {2, 5, 3, 6}
        int result3 = coins.Change_Recursive3( vcoins, amount );
        cout << "   Number of Coin Changes = " << result3 << endl << endl;
    }
    {
        int amount = 10;
        vector<int> _coins = {2, 5, 3, 6};
        int numberOfCoinChanges1 = coins.Change_Iterative1( _coins, amount );
        cout << "3) Coin Changes Iterative1 = " << numberOfCoinChanges1 << " for Amount = " << amount << " and Coins: ";
        printVector( _coins );

        int array[] = {2, 5, 3, 6};
        int numberOfCoinChanges2 = coins.Change_Iterative2(array, 4, amount);
        cout << "4) Coin Changes Iterative2 = " << numberOfCoinChanges2 << " for Amount = " << amount << " and Coins: ";
        for(int i : array)
            cout << i << " ";

        int numberOfCoinChanges3 = coins.Change_Iterative3(array, 4, amount);
        cout << "\n5) Coin Changes Iterative3 = " << numberOfCoinChanges3 << " for Amount = " << amount << " and Coins: ";
        for(int i : array)
            cout << i << " ";
    
        // !!!: Does not work. wrong answer = 8, for {2, 5, 3, 9}
        long int myNumberOfCoinChanges = coins.myChange( _coins, amount );
        cout << endl << myNumberOfCoinChanges << endl;
    }
    {
        int _coins[4] = {2, 5, 3, 6};
        int amount = 10;
        int result = coins.Minimum_Recursive( _coins, 4, amount );
        cout << "minCoin 1 Recursive= " << result << endl;

        result = coins.Minimum_Iterative( _coins, 4, amount );
        cout << "minCoin 2 Iterative = " << result;
    }

// !!!: /////////////////////////       String Permutations     //////////////////////////
    {
        string str = "ABCD";
        int left = 0;
        int right = (int)str.size();
        cout << endl << "String Permutations Recursive(ABCD, 0, 3): " << endl;
        
        permutation.printPermutation_Recursively1(str, left, right-1);
        
        // not ready
        // stringPermutationMysolution(str, right);            //stringPermutationMysolution(str, 0);
        
        cout << "\nstringPermutation4() of " << str << " is: " <<endl;
        permutation.Print_StringPermutation_Iteratively(str);
    }

// !!!: //////////////////////////       Keypad Combinations     ////////////////////////////
    {
        vector<int> phoneNumber {2,3,9};
        cout << endl << "KeypadC Combinations My Solution:   Iterative Solution " << endl;
        permutation.Print_keypadCombinations_MySolution(phoneNumber);
        
        cout << endl << "Keypad Combinations Geeks Solution: Iterative Solution. Breadth First Search" << endl;
        // !!!: Breadth First Search
        vector<string> strings = permutation.Print_keypadCombinations_GeeksSolution(phoneNumber);
        cout << "Keypad Combinations Geeks Solution = " << strings.size() << endl;
        for(string s: strings) cout << s << endl;
        
        cout << endl << "Keypad Combinations Recursively (1): Depth First Search: " << endl;
        printVector(cout << "Phone number = ", phoneNumber);
        // !!!: Depth First Search
        permutation.keypadCombinations_Recursively1(phoneNumber);

        cout << endl << "Keypad Combinations Recursively (2): Depth First Search" << endl;
        // Given mobile keypad
        vector<char> keypad[] =
        {
            {}, {},        // 0 and 1 digit don't have any characters associated
            { 'A', 'B', 'C' },
            { 'D', 'E', 'F' },
            { 'G', 'H', 'I' },
            { 'J', 'K', 'L' },
            { 'M', 'N', 'O' },
            { 'P', 'Q', 'R', 'S'},
            { 'T', 'U', 'V' },
            { 'W', 'X', 'Y', 'Z'}
        };

        // Size of the array
        int size = (int )phoneNumber.size();

        // !!!: Depth First Search
        permutation.Print_keypadCombinations_Recursively_2(keypad, phoneNumber);
        
        cout << "\n3) Print keypad Combinations Recursively for Phone Number ";
        printVector(phoneNumber);
        permutation.Print_keypadCombinations_Recursively_3(phoneNumber);

        // It works. it is just a long list, so i do not want to cluter screen
        //PrintAllCombinationsOfPhonePadLetters();
        
        // array must contain Exactly 7 digits
        vector<int> phoneDigits{2, 3, 4,7}; // {4, 9, 7, 0, 9, 2, 7};
        //print_7digitTelephoneNumber(phoneDigits);
    }

    // ///////////////////////////////////////       Rotate 1D Array     //////////////////////////////////////////
    {
        vector<int> array = {17, 23, 13, -4, -5, -1};
        int rotations = 3;
        
        cout << endl << "(1) Rotate Array " << rotations << " right: ";
        printVector(array);
        rotateArray_Right_1(array, rotations);
        printVector(::cout << "Array After " << rotations << " Rotations = ", array);

        // !!!: Does not work quite well
        /*cout << "Rotate Array (2) " << rotations << " right:" << endl;
        rotateArrayRight2(array, rotations);
        cout << "Array after Rotation :"; printVector(array);*/

        cout << endl << "(3) Rotate Array " << rotations << " right:" << endl;
        rotateArray_Right_3(array, rotations);
        cout << "    Array after Rotation: "; printVector(array);
    }

// !!!:  /////////////////     Rotate 2D Array 90 Degrees Clockwise     ////////////////
    {
        // matrix = NxN
        //vector<vector<int>> matrix = { {1,2,3,4,5}, {16,17,18,19,6}, {15,24,25,20,7}, {14,23,22,21,8}, {13,12,11,10,9} };  // 5X5
        vector<vector<int>> matrix = { {1,2,3,4}, {12,13,14,5}, {11,15,16,6}, {10,9,8,7} };  // 4X4
        //vector<vector<int>> matrix = { {1,2,3}, {8,9,4}, {7,6,5} }; // 3X3
        //vector<vector<int>> matrix = { {1,2}, {4,3} };   // 2X2
        cout << "\nBefore rotating Matrix:" << endl;
        printVectors(matrix);
        
        rotateMatrix_90DegCW(matrix);
        rotateMatrix_90DegCW(matrix);
        rotateMatrix_90DegCW(matrix);
        rotateMatrix_90DegCW(matrix);
        cout << "\nAfter rotating Matrix:" << endl;
        printVectors(matrix);
    }

// !!!:  /////////////////     Rotate Matrix Left     ////////////////
    {
        int ROWS = 4, COLS = 8;
        int** matrix1 = new int*[ROWS]; // { { 7, 1, 3, 4, 5, 8, 6, 12, 10, 13 }, { 2, 9, 6, 0, 7, 8,1, 31, 4, 55 } };
        matrix1[0] = new int[COLS]{ 0, 1, 2, 3, 4, 5, 6, 7 };
        matrix1[1] = new int[COLS] { 1, 2, 3, 4, 5, 6, 7, 8 };
        matrix1[2] = new int[COLS] { 11, 22, 33, 44, 55, 66, 77, 88 };
        matrix1[3] = new int[COLS] { 51, 52, 53, 54, 55, 56, 57, 58 };
        int rotateleft = 5;
        cout << "\n\nBefore Rotating Matrix Left:" << endl;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
                cout << matrix1[i][j] << ", " ;
            cout << endl;
        }
        
        cout << "After Rotating Matrix Left by " << rotateleft << ": " << endl;
        rotateMatrix_Left(matrix1, ROWS, COLS, rotateleft);
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
                cout << matrix1[i][j] << ", ";
            cout << endl;
        }
    }

// !!!:  /////////////////     Remove Duplicates From Soreted Array     ////////////////
    {
        vector<int> sortedarray = {5,5,5,5,5,7,7,8,9,11,33,33};
        cout << "\nRemove Duplicates From Soreted Array:";
        printVector(cout << "\n Original Array: ", sortedarray);
        int newarraysize = removeDuplicates_fromSoretedArray(sortedarray);
        printVector(cout << " New array:      ", sortedarray);
    }

// !!!:  /////////////////     Find Number In Sorted Matrix     ////////////////
    {
        int a[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
        int target = 5;
        bool found = Find_Number_In_SortedMatrix( a, 3, 3, 0 );
        cout << "findElement_in_SortedMatrix(): element =  " << found << endl;
    }

// !!!:  /////////////////     Common Chars     ////////////////
    {
        vector<string> words = {"bella","label","roller"};//{"cool","lock","cook"}; //;//;
        cout << endl; for( string s: words ) { cout << s << " "; }
        vector<string>  result = commonChars_inStrings(words);
        for(string str : result) {
            cout << str << ", " ;
        }
        
    }


// !!!:  /////////////////     Is Array Contiguous     ////////////////
    {
        //vector<int> contiguousArray = {1, 2, 1, 2,  4};
        vector<int> contiguousArray = {2, 2, 1, 2};
        printVector(cout << "\n1) Is Array Contiguous Dduplicates Allowed = ", contiguousArray);
        bool cont = isArrayContiguous_DuplicatesAllowed1(contiguousArray);
        cout << "Is Arraya Contiguous = " << (cont ? "YES": "NO") << endl << endl;

        printVector(cout << "2) Is Array Contiguous Dduplicates Allowed = ", contiguousArray);
        cont = IsArrayaContiguous_DuplicatesAllowed2(contiguousArray);
        cout << "Is Arraya Contiguous = " << (cont ? "YES": "NO") << endl;
    }
    {
        string num1 = "21";
        string num2 = "8";
        string result = multiplyTwoStrings(num1, num2);
        cout << "\nnum1 string = "  << num1;
        cout << "\nnum2 string = " <<  num2;
        cout << "\nnum1 * num2 string = " << result;
    }
    {
        vector<vector<int>> matrix
        {
            /*{0, 1, 1},
            {0, 0, 0},
            {1, 0, 1}*/
            {0, 0, 0, 1},
            {0, 1, 1, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 1}
        };
        
        vector<int> result = commonStuff.Find_ExitPoint_In_Matrix(matrix);
        cout << "Matrix exit point: row = " << result[0] << ", col = " << result[1] << endl;
    }
    {
        int ROWS = 3, COLS = 4;
        vector<int> matrix{1,2,3,4,5,6,7,8,9,10,11,12};
        vector<int> result = flattenedMatrix(matrix, ROWS, COLS);
    }
    
    
    
    
    
    
cout << "\n==========================*************===========================\n";
    
    
    
    
    
// !!!: //////////////////      Find Closest K Elements to Target   ////////////////////////

    {
        vector<int> numbers{ -10,-1,0,2,10, 12, 15, 17, 18, 20, 25 };  //{ -15, 3, 8, 2, 1, 6 , 8, 7, -25, 18};
        //{0,4,5,7,8,9,10}; //{0,1,1,1,10,10,10};  // {1, 2, 3, 4, 5, 6, 15, 20};
        // {0,1, 1, 1, 2, 3, 6, 7 ,8, 9}, k=4, x=-2;
        // {0,1, 1, 1, 2, 3, 6, 7 ,8, 9}, k=9, x=4
        // Speial case??? vector<int> array{0, 1, 1, 1, 2, 3, 6, 7, 8, 9}; numberOfElements = 1, target = 5;
        
        int k = 5;
        int target = 6;
        cout <<  "\nFind CLOSEST " << k << " numbers to " << target << " in: ";
        printVector( numbers );

        vector<int> result1 = kClosest_toTarget_1( numbers, k, target );
        printVector( cout << "  1) Result" << " = ", result1 );

        // !!!: my implementation:
        vector<int> result2 = kClosest_toTarget_2(numbers, k, target);
        printVector( cout << "  2) Result" << " = ", result1 );
        
        vector<int> result3 = kClosest_toTarget_3( numbers, k, target );
        printVector( cout << "  3) Result" << " = ", result1 );
        
        vector<int> result4 =  kClosest_toTarget_4( numbers, target, k );
        printVector( cout << "  4) Result" << " = ", result4 );   // result not sorted
        
        // From https://www.techiedelight.com/find-k-closest-elements-to-given-value-array/
        // Works with SORTED array Only:
        vector<int> result5 =  kClosest_toTarget_5( numbers, target, k );
        printVector( cout << "  5) Result" << " = ", result5 );   // result not sorted

// !!!: //////////////////      Find 1 Pair Whose Sum is CLOSEST to Zero   ////////////////////////
        {
            cout << "\n\nFind 1 Pair whose Sum is CLOSEST to Zero: ";
            // unsorted numbers
            // vector<int> numbers = {1,-1,-1,2,-2};
            // vector<int> numbers = {0, 1, -1, 0, -1, 1, 0, 0};
            // vector<int> numbers = {-1, 0};
            // vector<int> numbers = {38, -44, 39, -51, -35, -1, 0};
            // vector<int> numbers  = {-INT_MAX, -INT_MAX, -INT_MAX, -INT_MAX};
            // vector<int> numbers  = {5, 5, 8};
            //        vector<int> numbers  = {-5, 5, 8, -8};
            //vector<int> numbers  = {-5, 3, -8, 2, 0, 6, 8, -6};
            printVector( numbers );
            
            // My function: !!!: O(n^2)
            vector<int> pairs;
            pairs = onePair_Closest_toZero_1( numbers );
            cout << "  1) Result = " << pairs[0] + pairs[1] << " : ";
            printVector( pairs );
            
            //cout << "\n2) Find 2 Numbers whose Sum is CLOSEST to Zero: \n";
            // returns a vector: !!!: O(nlogn)
            pairs = onePair_Closest_toZero_2( numbers );
            cout << "  2) Result = " << pairs[0] + pairs[1] << " : ";
            printVector( pairs );
            
            //cout << "\n3) Find 2 Numbers whose Sum is CLOSEST to Zero: \n";
            // returns int: !!!: O(nlogn)
            int sum  = onePair_Closest_toZero_3( numbers );
            cout << "  3) Result = " << pairs[0] + pairs[1] << " : ";
            printVector( pairs );
            
// !!!: /////////     Find 1 Pair EQUAL to a Target Sum        /////////////////////////////////////
            {
                // vector<int> numbers = {3, 5, 4, 2, 6, 5, 7, 4, 4, 8, 9, 0, -1};  // {5, 5}, sum=10
                int targetSum = 10;
                // returns INDICIES of the numbers that add up to target sum
                vector<int> pair = onePair_Equal_targetSum( numbers, targetSum );
                printVector(cout << "\n\nFind INDICES of 1 Pair With Sum EQUAL to " << targetSum << ": ", numbers);
                if( pair[0] == -1 )
                    cout << "   Target Sum '" << targetSum << "' Not Found\n";
                else
                    cout << "  Result: [" << numbers[pair[0]] << ", " << numbers[pair[1]] << "] = " << numbers[pair[0]] + numbers[pair[1]];
                
                // 2) print ALL pairs of equal sum
                //vector<int> array = {5, 9, 0, 5, 1, -1}; // {3, 5, 4, 2, 6, 5, 7, 4, 4, 8, 9, 0, -1};
                //sum = 8;
                printVector(cout << "\n\nPrint ALL Pairs With Sum EQUAL to " << targetSum << ": ", numbers);
                bool printed = print_allPairs_Equal_targetSum( numbers, targetSum );
                if( !printed )
                    cout << "   Target Sum '" << targetSum << "' Not Printed\n";
            }
            
// !!!: /////////     Find All Pairs EQUAL to a Target Difference        /////////////////////////////////////
            {
                //vector<int> numbers = {1, 7, 5, 9, 1, 2, 12, 3, -1, 11, -2, 15, 5, 20, 10}; // {3,1,3}; //
                int targetDiff = 10;
                printVector( cout << "\n\nFind ALL Pair(S) With DIFFERENCE Equal to " << targetDiff << ": ", numbers );
                vector<vector<int>> diff_matrix = allPairs_Equal_targetDifference( numbers, targetDiff );
                if( diff_matrix.empty() ) {
                    cout << "   Target Sum '" << targetDiff << "' Not Found\n";
                }
                else
                printVectors( diff_matrix );
            }
            
// !!!: //////////////////      3 Numbers Whose Sum is CLOSEST to Zero   ////////////////////////
            
            cout << "\n\nFind 3 Numbers whose Sum is CLOSEST to Zero: ";
            //vector<int> a = {-1, 4, -2, 5, 10, -5}; // {-1, 0, 1, 2, -1, -4}
            // cout << "\n\nMinimum Sum with Three Elements: ";
            printVector(cout << "\n\t", numbers);
            sum = find_3Sum_Closest_toZero( numbers );
            cout << "\tResult = " << sum;   // << " is Minimum Sum with three elements = ";
            
// !!!: //////////////////      3 Numbers Whose Sum is EQUAL to Zero   ////////////////////////!!!!!!!!!
            
            cout << "\n\nFind 3 Numbers whose Sum is EQUAL to Zero: ";
            // !!!: Notice result is 2D[][]
            printVector(cout << "\n\t", numbers);
            vector<vector<int>> equal_matrix = find_3Sum_Equal_toZero( numbers );
            if( equal_matrix.empty() ) {
                cout << "  None is Found \n";
            }
            sum = 0;
            for( vector<int> v : equal_matrix ) {
                for( int i : v ) {
                    sum += i;
                }
            }
            cout << "\tResult = " << sum << ":";
            printVectors(equal_matrix);
        }
        
        
        
// !!!:  /////////////////     Find Subarray with a Target Sum     ////////////////
        //
        {
            // Given an unsorted array A of size N that contains only "NON-NEGATIVE" integers
            //vector<int> numbers = {1,3,4,1,4};//{2,4,3,1,5,7};//{1,3,3,4,5,6,7,8,9,10};// {1,2,3,7,5};
            //vector<int> array = {1,5,6,7,8,9,10};
            vector<int> array = {6,8,11,10,1,3,2,1,4,5,6};
            int targetSum = 1;
            printVector(::cout <<  "\n\nContiguous Subarray with Sum = " << targetSum << ":\n Input:  " , array);
            vector<int> result = subarraySum(array, targetSum);
            
            int start = result[0];
            int end   = result[1];
            if( start == -1 ) {
                cout << " Result: Contiguous Sum " << targetSum << " Not Found" ;
            }
            else {
                cout << " Result: [";
                for( int i=start; i <= end; ++i) {
                    if( i != end )
                        cout << array[i] << ", ";
                    else
                        cout << array[i] ;
                }
                cout << "]";
            }
        }
        
        // !!!: ///////////////////////   Find SubArray with Maximum Sum  ///////////////////////////
        // array can have negative numbers
        {
            //vector<int> array = { -2 };
            //vector<int> array = { -2, -3 };
            //vector<int> array = { 0 };
            vector<int> array = {-12, -2, 3, 4, 7, 10, -20 };
            //vector<int> array = { -2, -3, 4, -1, -2, 1, 5, -3, 11 };
            //vector<int> array = { 1, 2, -3, 3, 4,5 , -1, -2, -3, -4, -5 };
            //vector<int> array = { 1, 2, -3, 3, 4, 5, -1, -2, -3, -4, -5, 13 };
            //vector<int> array = { 1, 2, 3, 4, -5, 15 };
            //vector<int> array = { -2, -3, -4, -5, -14 };
            //vector<int> array = { 12, 2, -3, -14, -5, 14 };
            
            printVector(cout<<"\n\nFind largest contiguous subarray: ", array);
            
            int max_sum = maxSum_subArray_geeks(array);
            cout << "1) Geek: Maximum contiguous sum is " << max_sum;
            
            max_sum = maxSum_subArray_wiki(array);
            cout << "\n2) Wiki: Maximum contiguous sum is " << max_sum;
            
            // My solution. Perefect √√√. rturns indexes to start and end of contiguous suarray
            vector<int> maxSum_indices = maxSum_subArray_mine(array);
            printVector(cout << "\n3) Mine: ", maxSum_indices);
            cout << "   Mine: Maximum contiguous sum = " << maxSum_indices[0];
            cout << "\n                          start = "  << maxSum_indices[1];
            cout << "\n                            end = "    << maxSum_indices[2];
        }
    }

cout << "\n\n===================******   Pivot Point *******====================\n";
        {
// !!!: //////////////       Find Pivot (Equilibrium) Point in Array   ///////////////
        // array MUST have all POSITIVE number
        //vector<int> array = { 3, 2, 11, 5, 5, 4, 2, 8, 12 };
     //       vector<int> array = { 4, 2, -5, 1, 3, -5, 5, 7, 8 };
            //vector<int> array = { -1, 2, -5, 1, 3, -5, 5, 7, 8, 8 };
           // vector<int> array = { -2, -2, -1, 0, 0, -1, -4};    // ans: 4
        vector<int> array = { 4, 3, 2, 1,5, 5, 8, 7 };  // lsum == rsum = 15 at pivot point = '11111'
        //vector<int> array = { 5, 5 };
            //array = { 0,0,0,0 };                     // ans = 2
            //array = { 2, 1, 2, 1 };               // Not Found
            //array = { 3, 1, 0, -1, 4};               // ans = 3
            // array = { -2, -2, 1, -4};               // ans = 2
            //array = { -2, -2, -1, 0, 0, -1, -4};    // ans: 4
            //array = { 2, 2, 1, 0, 1, 4};             // ans = 3
            //array = { 2, 1, 2, 1, 1, 1, 2, 2};       // Not Found
            //array = { 2, 1, 2, 0, 0, 1, 2, 2};         // ans: 4
            //array = { 2, 1, 2, 1, 1, 1, 2, 2};         // Not Found
           //array = { 10, -17, 4, -15, 8 };
            // size = 42
        //    vector<int> array = {4, 42, 27, 16, 28, 3, 4, 5, 9, 3, 31, 5, 5, 29, 10, 18, 35, 35, 33, 19, 41, 23, 8, 32, 9, 5, 8, 18, 35, 13, 6, 7, 6, 10, 11, 13, 37, 2, 25, 7, 28, 43};
            

        cout << "\n1) Find Equal-Sum Or Missing POSITIVE number to make Equa-Sum for array: ";
        printVector(array);
        int equalsum = PivoitPoint_1( array );
        if(equalsum != -1)
            cout << "   Result: Equilibrium Point FOUND at Location = " << equalsum;
        else
            cout << "   Result: Equilibrium Point NOT_FOUND";

        
        // !!!: EquilibriumPoint1() is sligtly different
        cout << "\n\n2) Find Equilibrium Point for ";
        printVector(array);
        equalsum = PivoitPoint_2( array );
        if(equalsum != -1)
            cout << "\n   Result: Equilibrium Point FOUND at Location = " << equalsum;
        else
            cout << "\n   Result: Equilibrium Point NOT_FOUND";

        cout << "\n\n3) Find Equilibrium Point for ";
        printVector(array);
        equalsum = PivoitPoint_3( array );
        if(equalsum != -1)
            cout << "\n   Result: Equilibrium Point FOUND at Location = " << equalsum;
        else
            cout << "\n   Result: Equilibrium Point NOT_FOUND";
            
        cout << "\n\n4) Find EquilibriumIndex_Optomized, for ";
        printVector(array);
        findEquilibriumIndex_Optomized( array );
    }
    {
        int target = 5;
        int startIndex  = 4;
        cout << "\n\nGet Min Distance to target = " << target << ", starting at index = " << startIndex << ", and \n";
        vector<int> numbers = {1,5,3,4,-1,5,5};// 1,9=0 //{1,5,3,4,5} 5,2
                                                   //{1,5,3,4,5,5} 5,3 //{5,3,6} 5,2 //{1,2,3,4,5} 5,3
                                                   //{1,2,7,3,11,5,5,4,5} 5,2 //{1,5,5,4,5} 5,2=0
        cout << "   Array = "; printVector(numbers);
        int res = Find_MinDistance_toTarget_fromStart(numbers, target, startIndex);
        cout << "   Result: Min Distance to " << target << ", starting at index " << startIndex << ", is = " << res << endl ;
    }
    {
        vector<int> nums = {4,2,3,1,1,88,17,22}; // output: [2,4,1,3], and [4,2,1,3] ;
        vector<int> res = Sort_Array_By_Parity(nums);
        cout << "Sort Array By Parity = " ;
        for(int i : res) {
            cout  << i << ", ";
        }
        cout << endl << endl;
    }
    {
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3,4};
        double d = Find_Median_In_SortedArrays(nums1, nums2);
        cout << "Find Median Sorted Arrays = " << d << endl << endl;
    }
    {
        int m = 5, n = 3;
        vector<string> strs = {"10","0001","111001","1","0"}; //{"10", "0001", "1", "0"};// {"10","0","1"}; {"10","0001","111001","1","0"};
        int res = Find_MaxForm(strs, m, n);
        cout << "find Max Form = " << res << endl << endl;
    }
    {
        vector<int> students = {1,1,0,1};//{1,1,1,0,0,1};
        vector<int> sandwiches = {0,1,0,1};//{1,0,0,0,1,1}; 
        int res = Count_Students(students, sandwiches);
        cout << " number of students that are unable to eat = "<< res << endl;
    }
    {
        int number = 28;
        string str = Convert_Number_To_Excell_Headers(number);
        cout << "ExcellAlphaBet() for " << number << " = " << str << endl;
    }
    
// !!!: /////////////////         Find Longest Substring Without Repeating Characters       ////////////////////////
    {
        // Given a string s, find the length of the longest substring without repeating characters
        string s = "abcabcbb";    // "abcabcbb"=abc, "bbbbb"=b, "pwwkewsspabcdefg"=spabcdefg
        cout << "\n1) Longest substring without repeating letters for \"" << s << "\" is " << endl;
        string max_str = longestSubstring_Without_Repeating_Characters_1(s);
        cout << "\"" << max_str << "\" with length of " << max_str.size() << endl;
/*
        cout << "\n2) Longest substring without repeating letters for \"" << s << "\" is " << endl;
        max_str = longestSubstring_Without_Repeating_Characters_2(s);
        cout << "\"" << max_str << "\" with length of " << max_str.size() << endl;*/
    }
    
{
    int low  = 7;
    int high = 9;
    int odds = CountOdds_1(low, high);
    cout << "\n\n1) Odd numbers between " << low << " and " << high << " is " << odds;

    odds = countOdds_2(low, high);
    cout << "\n2) Odd numbers between " << low << " and " << high << " is " << odds;
}
        
// !!!: ////////////////////////   Decimal to Binary   //////////////////////////////
//
        int decimal = 0b11011011000001;
        cout << "\n\nDecimal to Binary for " << decimal << ":";
        
        // !!!: my decimal to binary
        string binaryString = DecimalToBinary_mine(decimal);
        cout << "\n 1) my decimal to binary   " << " = " << binaryString;
        
        // !!!: print decimal to binary
        cout << "\n 2) print decimal to binary" << " = " ;
                              print_DecimalToBinary(decimal);

        // !!!: geeks decimal to binary
        binaryString =        DecimalToBinary_geeks(decimal);
        cout << "\n 3) geeks decimal to binary" << " = " << binaryString;
 
// !!!: ////////////////////////   Binary to Decimal    //////////////////////////////
//
        string binary = "1011";
        decimal = Convert_BinaryToDecimal(binary);
        cout << "\n\nBinary to Decimal for " << binary << " = " <<Convert_BinaryToDecimal(binary) << endl;
    }

    // !!!:  /////////////////     Find Longest Consecutive Integers     ////////////////
//
    {
        // Big set of numbers
        //vector<int> nums = {4,5,6,35,43,8,34,35,33,32,11,10,31,36,37,38,88,7,39};
        vector<int> nums = {4,100,-31,36, 7, 38, 88, 7, 38};
        cout << "\nFind Longest Consecutive Integers in Array:\n";
        printVector( nums );
        /*for(int i=0; i<nums.size(); i++) {
            nums[i] = rand()%10000000;
        }*/
        
        vector<int> result = findLongest_consecutiveNumbers(nums);
        printVector(cout << "\tNew array: ", result);
    }


// !!!:  /////////////////     Print Subarrays     ////////////////
//
    {
        vector<int> array = {1, 2, 3, 4};
        cout << "\n\n1) Print All Non-empty SUBARRAYS:";
        printVector(cout << "\n   Input = ", array);
        printSubarrays_1(array);
        
        cout << "\n2) Print All Non-empty SUBARRAYS:\n";
        printSubarrays_2(array);

        cout << "\nPrint All Non-empty SUBSETS:\n";
        printVector(cout << "   Input = ", array);
        printSubsets(array);
    }


// !!!: /////////////////         Minimum Increments      ////////////////////////
// !!!: :
{
    cout << "\n\nMinimum Increments to make all SORTED Array Elements Unique:\n";
    // vector must be SORTED
    // vector<int> a = {1, 1, 1, 1, 2, 2, 2}; // {2, 3, 4, 5, 6, 7}; // {2, 2, 3, 5, 6, 6};
    //vector<int> a = {2, 3, 4, 5, 5, 7};
     vector<int> a = {2, 3, 3, 5, 7, 7};
    printVector(cout << "1) Mine, Orignal Sorted Array:           ", a);
    int result = minIncrements_to_uniqueArray_mine( a );
    printVector(cout << "   Array After Minimum Increments: ", a);
    cout << "   Minimum Increments = " << result;

     a = {2, 3, 3, 5, 7, 7}; // {2, 3, 4, 5, 6, 7}; // {2, 2, 3, 5, 6, 6};
    printVector(cout << "\n\n2) Geeks, Orignal Sorted Array:           ", a);
    result = minIncrements_to_uniqueArray_geek( a );
    printVector(cout << "   Array After Minimum Increments: ", a);
    cout << "   Minimum Increments = " << result << endl;
}


// !!!: ////////////////////////////      Factorial     ////////////////////
    {
        int result = factorial.Factorial_Recursively(4);
        cout << result << endl;

        int result1 = factorial.Factorial1(4);
        cout << result1;
    }
    
// !!!: ////////////////////////////      Fibonacci     ////////////////////
    {
        int number = 13;
        int result = fibonacci.Fibonacci_Recursively( number );
        cout << "\n\n\nFibonacci Recursively(" << dec << number << ")                  = " << result;
        
        result = fibonacci.Fibonacci_Recursively_Memoization_Utl( number );
        cout << "\n\nFibonacci Recursively with Memoization(" << dec << number << ") = " << result;

        result = fibonacci.Fibonacci_Iteratively( number );
        cout << "\n\nFibonacci Iteratively(" << dec << number << ") = " << result << endl;
    }
    
// !!!: ////////////////////////////      Where Do They Meet on Circle      ////////////////////
    {
        int circleSize = 60; // circle size in steps;
        int step1 = 60;  // 1 step/min, and
        int step2 = 5;   // 1/60 step/min
        cout << "Given a circle with N = " << circleSize << " steps. Runner1 moves with k = " << " steps " << step1
        << " and Runner2 moves at k = " << step2 << " steps. "
        << "At what step Runner1 and Runner2 will meet (collide)?" << endl;
        int result = Find_Where_TheyMeet_On_Circle(circleSize, step1, step2);
        cout << "They meet at step No. " << result << endl << endl;
    }
    
// !!!: ////////////////////////////      Number Of Paths in Matrix      ////////////////////
    {
        int ROWS = 1, COLS = 8; // possible paths 1, 2, 6, 20, 70, 252
        cout << "Number of Paths for Matrix: " << ROWS << "x" << COLS << endl;
        long long   paths = commonStuff.numberOfPaths_recursively1( ROWS, COLS );
        cout<< "paths (1) = " << paths << " Recursive: " << endl;

        long long   paths1 = commonStuff.numberOfPaths_recursively2( ROWS, COLS );
        cout<< "\npaths (2) = " << paths1 << " Recursive MY Solution" << endl;

        // !!!: numberOfPathsRecursive3() Not a good solution. it assumes paths=4x4=16
        // Create an empty 2D table.
        /*int paths[4][4] = {0};
        memset(paths, 0, sizeof(paths));
        int         pathsX = numberOfPathsRecursiveX(ROWS, COLS, paths);
        cout<< "paths (3) = " << pathsX << " Recursive" << endl;*/

        int         paths3 = commonStuff.numberOfPaths_iteratively1( ROWS, COLS );
        cout<< "paths (3) = " << paths3 << " Iterative" << endl;
        
        // !!!: Iterative Solution. Butter than all above functions
        int         paths5 = commonStuff.numberOfPaths_iteratively2( ROWS, COLS );
        cout<< "paths (4) = " << paths5 << " Iterative" << endl << endl;
    }
    
// !!!: /////////////////////    Smallest K digit Number Divisible By X      //////////////////
    {
        int smallest_K_digit = 3;
        int X = 83;
        int result1 = findSmallestKdigitNumberDivisibleByX_1(X, smallest_K_digit);
        cout << "1) Find Smallest " << smallest_K_digit << " digit Number Divisible By " << X << " = " << result1 << endl;
        
        int result2 = findSmallestKdigitNumberDivisibleByX_2(X, smallest_K_digit);
        cout << "2) Find Smallest " << smallest_K_digit << " digit Number Divisible By " << X << " = " << result2 << endl;
    }
    
// !!!: ////////////////////////////      Zero One Two      ////////////////////
    {
        //vector<int> v = {0,2,2,1,1,1,2,1,2,1};
        //vector<int> v = {2,2,2,2,0,0,0,0,1,1};
        vector<int> v = {2,1,0,0,0,2,1};
        vector<int> result = ZeroOneTwo3(v);
        for(int i : result)
            cout << i;

        string s = "20101010101";
        string str = ZeroOneTwo4(s);
        for(char c : str) {
            cout << c ;
        }
    }

// !!!: ////////////////////////////      Permute     /////////////////////////////////
    {
        // !!!: Not complete
        vector<int> nums = {1,2,3};
        printVector(cout<<"\n\nPermute array: ", nums);
        
        permutation.printPermutation_Recursively2( nums, 0, nums.size()-1 );
    }

// !!!: //////////////////    Find MIN In Rotated Sorted Array (Douplectes Allowed)   //////////////////
    {
        //int array[] = {7, 1, 2, 3, 4, 5, 6};
        //int array[] = {6, 7, 1, 2, 3, 4, 5};
        //int array[] = {5, 6, 7, 1, 2, 3, 4};
        //int array[] = {4, 5, 6, 7, 1, 2, 3};
        //int array[] = {1, 1, 1, 1, 1, 1, 1};
        //int array[] = {2, 3, 4, 5, 6, 7, 1};
        //int array[size] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1};
        //int array[] = {7, 6, 5, 4, 3, 2, 1};  // wrong arrangment*/
        //int array[size] = {5, 7, 8, 9, 12, 15, 17, 25, 28, 32, 37, 3 };
        //int array[] = {7, 1, 2, 3, 4, 5, 6};
        /*int array[size] = {9, 12, 15, 17, 25, 28, 32, 37, 3, 5, 7, 8};
        //int array[size] = {8, 9, 12, 15, 17, 25, 28, 32, 37, 3, 5, 7};
        //int array[size] = { 3, 5, 7, 8, 9, 12, 15, 17, 25, 28, 32, 37 };*/
        vector<int> a = {2, 1};   // Duplicates and unsorted array
 
        cout << "\nEfficient (1): Find INDEX of Min element in Rotated Sorted Array:\n" ;
        for( int i=0; i < a.size(); i++) { cout << a[i] << ", " ; }
        // !!!: Returns index from which you can print its value. minIndex == 0, means no rotation
        // !!!: Works both sorted and unsorted arrays, so {1, 4, 5, 4, -48} Works
        int minIndex = findMin_inSortedRotatedArray_2(a);
        cout << endl << "Outpout: value = " << a[minIndex] << ", at index = " << minIndex << endl;
        

        cout << endl << "Inefficient: Find INDEX of Min element in Rotated Sorted Array:";
        // !!!: Works only for sorted array, so {1, 4, 5, 4, -48} Doesn't work
        int minIndex1 = findMin_inSortedRotatedArray_1(a);
        cout << endl << "Outpout: value = " << a[minIndex1] << ", at index = " << minIndex1 << endl;
    }

// !!!: ///////////////////   Number Of Sorted Array Rotations      //////////////////////
    {
        cout << endl << "Rotation of sorted array of numbers: " ;
        //vector<int> rotatedArray = { 1, 2, 3, 4, 5 };        // influction point 0
        vector<int> rotatedArray = { 5, 1, 2, 3, 4 };        // influction point 1
        //vector<int> rotatedArray = { 4, 5, 1, 2,  3 };        // influction point 2
        //vector<int> rotatedArray = { 3, 4, 5, 1, 2 };        // influction point 3
        //int rotatedArray[5] = { 2, 3, 4, 5, 1 };        // influction point 4
        //vector<int> rotatedArray = { 22, 33, 44, 55, 11 };    // influction point 4
        printVector(rotatedArray);
        int numberOfRotations = findNumberOfRotations_inSortedRotatedArray(rotatedArray);
        cout << "Array was rotated " << numberOfRotations << " positons to the right, OR" << endl;
        cout << "Array was rotated " << rotatedArray.size() - numberOfRotations << " positons to the left" << endl;
    }

// !!!: /////////////////   Find Number In Sorted ROTATED Array   //////////////////////
    {
        //vector<int> nums = {1,3 };
        //vector<int> a = {15, 16, 19, 20, 25 , 1, 3, 4, 5, 7, 10, 14}; //{8,9,0,1,2,4,5,6,7 }; // {5,6,7,1,2,3,4}
        //vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
        //vector<int> a = {5 };
        //vector<int> a = {};
        vector<int> a = {5, 6, 7, 1, 2, 3, 4};
        int number = 5;
        cout << "\nFind " << number << " in Sorted and Rotated Array: "; printVector(a);
        int result = findNumber_inSortedRotatedArray_1(a, number);
        if( result >= 0)
            cout << "1) Found " << number << " at index " << result;
        else
            cout << "1) " << number << " not Found in Array";

       //vector<int> a2 = {10, 15, 20, 0, 5};
        result = findNumber_inSortedRotated_Array_2(a, number);
        if( result >= 0)
            cout << "\n3) Found " << number << " at index " << result;
        else
            cout << "\n3) " << number << " not Found in Array";
    }
    
// !!!: ////////////////////////////     Non Repeating Elements    ///////////////////////////////////
    {
        string str = "teete"; //ZADCA
        char First_nonReptChar = Find_FirstNonRepeatingChar(str);
        //cout << endl << "\"" << str << "\"" << endl;
        cout << "\nFirst NonRepeating char in \"" << str << "\": ";
        if ( First_nonReptChar == '\0' ) {
            cout << "Not Found ";
        }
        else {
            cout << string(1, First_nonReptChar);
        }
    }
    {
        vector<int> numbers { 1, 1, 3, 3, 24, 24, 21, 10, 29, 8, 10, 29, 2};
        cout << "\n\nFirst 2 NonRepeating numbers in: "; printVector(numbers);
        vector<int> result1 = Find_First2NonRepeatingNumbers_1(numbers);
        cout << "Result = "; printVector(result1);
        
        vector<int> result2 = Find_First2NonRepeatingNumbers_2(numbers);
        cout << "Result = "; printVector(result2);

    }

// !!!: ////////////////////////     Remove Duplicate Integers Using Map    //////////////////////////
    {
        cout << "\nNot Using External Strcutre: Array before removing duplicates: \n\t";
        int arr[] = { 11,2,3,11,11,6,11,8,10,10 };
        //int ar[10] = { 8,8,8,8,8,8,8,8,8,8 };
        for (int i = 0; i < 10; i++)
            cout << arr[i] << ',';
        int ar_size = Remove_Duplicates_ExtraSpace(arr, 10);
        cout << "\nAfter removing duplicates \n\t";
        for (int i = 0; i < ar_size; i++)
            cout << arr[i] << ',';
    }
    {
        string str = "AAABAAA";
        cout << "\nArray before removing duplicates (No EXTRA SPACE = " << str << endl;
        Remove_Duplicates_NoExtraSpace(str);
        cout << "Array after removing duplicates = " << str;
    }

// !!!: /////////////////////////////     String in String    ///////////////////////////////////
    {
        // version 1: bool StrInStr(string str1, string str2)
        // notice: str1 < str2
        string str1 = "6";
        string str2 = "012345 789 6";
        bool b1 = StrInStr( str1, str2 );
        cout << "\n\n1) Is String \"" << str2 <<"\" in \"" << str1 << "\" ? Ans: " << ((b1 == false)?"NO" : "YES");
        // Another strstr
        str1 = "axbcdefsfsaffsabcdefghjklmn";
        str2 = "abcdefghjklmn";
        b1 = StrInStr(str1, str2);
        cout << "\n1) Is String \"" << str2 <<"\" in \"" << str1 << "\" ? Ans: " << ((b1 == false)?"NO" : "YES");

        // version 2: bool StrInStr(char* a, char* b)
        char* a = const_cast<char*>("012345 789 6");
        char* b = const_cast<char*>("6");
        b1 = StrInStr(a, b);
        cout << "\n2) Is String \"" << b <<"\" in \"" << a << "\" ? Ans: " << ((b1 == false)?"NO" : "YES") << endl;
    }

// !!!: /////////////////////////////     String Compare   ///////////////////////////////////
    {
        //bool sc = StrCmp((char*)("abc"), (char*)"abc");               // This works
        char* str1 = const_cast<char *>("abc");
        char* str2 = const_cast<char *>("abcd");

        bool result2 = strCmp(str1, str2);
        cout << "\n\nIs String \"" << str1 <<"\" = \"" << str2 << "\" ? Ans: " << ((result2)?"YES" : "NO") << endl;
    }
    
// !!!: ///////////////// Adding two number from two arrays ////////////////////////////////////

// !!!: /////////////////       Palindrome Permutation      ////////////////////////////////////
    {
        int number = 73909137;
        bool pal = isIntegerPalindrome_1(number);
        cout << "\n1) Is number "<< number << " a Palindrome? Ans: " << (pal? "YES": "NO");
        
        bool pal1 = isIntegerPalindrome_2(number);
        cout << "\n2) Is number " << number << " a Palindrome? Ans: " << (pal1? "YES": "NO");

        string str = "ZABCDCBAZ";
        bool palChar = isStringPalindrome(str);
        cout << endl << "Is string " << str << " a Palindrome? Ans: " << ((palChar)? "TRUE": "FALSE")  << endl;

        string s = "abauobu";
        bool result = isStringPermutationOfPalindrome1(s);
        cout << endl << "Is String a Permutation Of Palindrome = " << ((result)? "YES": "NO")  << endl;
    }
    {
        string str = "cbbd";
        cout << endl << "Longest Palindrome string = " << str << endl;
        string result = longestPalindrome(str);
        cout << result;
    }

    
// !!!: ///////////////// Missing Number in Incremental Sorted Sequence ////////////////////////
    {
        vector<int> Sequence = {};        // returns -1 no missing number
        //vector<int> Sequence = {2,3,4,5,6,7,8,9,10};       // missing 1
        //vector<int> Sequence = {1,3,4,5,6,7,8,9,10};       // missing 2
        //vector<int> Sequence = {1,2,4,5,6,7,8,9,10};       // missing 3
        //vector<int> Sequence = {1,2,3,5,6,7,8,9,10};       // missing 4
        //vector<int> Sequence = {1,2,3,4,6,7,8,9,10};       // missing 5
        //vector<int> Sequence = {1,2,3,4,5,7,8,9,10};       // missing 6
        //vector<int> Sequence = {1,2,3,4,5,6,8,9,10};       // missing 7
        //vector<int> Sequence = {1,2,3,4,5,6,7,9,10};       // missing 8
        //vector<int> Sequence = {1,2,3,4,5,6,7,8,10};       // missing 9
        cout << endl << "Original array = "; printVector(Sequence);

        int missing = Find_MissingNumber_In_Incremental_SortedArray(Sequence);
        if( missing != -1)
            cout << "Missing Number in Sorted Array = " << missing << endl;
        else
            cout << "No Missing Number in Sorted Array" << endl;
    }
    
// !!!: ///////////////// Missing Number in Incremental UnSorted Sequence ///////////////////
    {
        // array must have incremental integers: 0,2,3,4,5...
        vector<int> sequence {9,6,4,2,3,5,7,0,1};   // missing 8
        for(int num : sequence) {
            cout << num <<  ", " << endl;
        }
        int result = findMissingNumber_inIncrementalUnsortedArray(sequence);
        cout<< "missing Number in Incremental Sequence = " << result;
    }

// !!!:  ///////////////// First Missing Positive Number in UnSorted Array ///////////////////
    {
        //vector<int> nums = {3, 4, -1, 1};     // ret 2
        //<int> nums = {8, 7, 9, 11, 12};   // ret 1
        //vector<int> nums = {7, 8, 9, 10, 11, 12}; // ret 1
        //vector<int> nums = {1, 4, 3, 2};            // ret 5
        //vector<int> nums = {2, 3, 7, 6, 8, -1, -10, 15}; // ret 1
        //vector<int> nums = {-1, 2, 3, -7, 6, 8, 1, -10, 15}; // ret 4
        vector<int> nums = {-3, -1, 0, -1, -2};
        //vector<int> nums = {INT_MAX,2,0};
        //vector<int> nums = {INT_MAX,1,0};
        //vector<int> nums = {INT_MIN,2,0};
        //vector<int> nums = {INT_MIN,1,0};
        //vector<int> nums = {INT_MIN,2,0};
        //vector<int> nums = {1,1,1};
        //vector<int> nums = {1,1,0,};
        //vector<int> nums = {1,1,1,2,2,2};
        //vector<int> nums = {INT_MIN,INT_MIN,INT_MIN};
        //vector<int> nums = {INT_MAX,INT_MAX,INT_MAX};
        printVector(cout << "\n\nSmallest Missing Positive Number in: ", nums);
        
        int result = firstMissingPositive_inUnsortedArray_1(nums);
        cout << "1) Smallest Missing Positive Number = " << result;
        result = firstMissingPositive_inUnsortedArray_2(nums);
        cout << "\n2) Smallest Missing Positive Number = " << result;
        result = firstMissingPositive_inUnsortedArray_3(nums);
        cout << "\n3) Smallest Missing Positive Number = " << result << endl << endl;
    }

// !!!: ///////////////////     Print Duplicates in Big Data Set    //////////////////
    
    // I have 4KB of memory = 4Kbyte * 1024 bytes/Kbyte * 8 bits/byte = 32768 bits.
    unsigned int bigset[4*1024*8];
    int BIG_SET_SIZE = 4*1024*8;
    
    // Populate first 32000 of bigset[] = 1,2,3....,32000
    int index = 0;
    for(; index < 32000; index++) {
        bigset[index] = index + 1;
        //cout << bigset[index] << ", ";
    }
    cout << endl;
    int value= 32000;
    // Add duplicates for last 768 = 32768 - 32000
    for(; index < BIG_SET_SIZE; index++) {
        bigset[index] =  value--;  // OR, index + 1 OR something else
        //cout << bigset[index] << "' ";
    }
    
    // This function prints long list
    // int result1 = printDuplicatesInBigDataSet(bigset, BIG_SET_SIZE);
    // cout << "\nAs expected, Duplicate numbers = " << result1 << endl << endl;
    
// !!!: /////////////////      Selection Sort    ////////////////////////////////////
    {
        int array[7] = {5,4,1,2,6,7,3};
        //int array[7] = {1,2,3,4,5,6,7};
        //int array[7]   = {7,6,5,4,3,2,1};
        //SelectionSort(array, 7);
        
        SelctionSort_Recursively(array, 7);
    }

// !!!: ///////////////////     Sort Two Merged Integer Arrays  ///////////////////
    {
        vector<int> a = {7};
        vector<int> b = {1,2,4,5,6,7,7,8,10};
        cout << "\nMerege Two Sorted Arrays:";
        printVector(cout << "\nArray 1: ", a);
        printVector(cout << "Array 2: ", b);

        vector<int> result = Merge2SortedArrays_1(a, b);
        
        printVector(cout << "1) Merged Arrays: ", result);
        
        result =  Merge2SortedArrays_2(a, b);
        printVector(cout << "2) Merged Arrays: ", result);
    }
    
// !!!: ////////////////////////      Number Of 2s In Range      ////////////////////////////
    {
        long long int number = 12;//18468;
        long long int numof2s = NumberOf2sInRange(number);
        cout << "\nNumbers of 2s in Range for Number " << number << " is " << numof2s;
    }
    
// !!!: ////////////////////////      Word Count      ////////////////////////////
    string words = " One   Two Three   Four   " ;
    int numwords = wordcount(words);
    cout << "\n\nNumber of Words in \"" << words << "\" = " << numwords << endl;
    
// !!!: /////////////////////////   Hex To Decimal   ///////////////////////////
    string hexstr = "A57B";
    int dec1 = Convert_HexToDecimal(hexstr);
    cout << "Decimal of Hex " << hexstr << " = " << dec1  << endl << endl;
    
// !!!: ///////////////////////   Decimal To Hex    ////////////////////////////
    int decimal = -2;    //0x123456789ABCDEF; 0xABCDEF = 11259375; 0xFFFFFFFFFFFFFFFF = 18446744073709551615
    string hexString = Convert_DecimalToHex(decimal);
    cout << "Decimal to Hex " << decimal << " = " << hexString;

    decimal = -1;
    string binary = DecimalToBinary_mine(decimal);
    cout << "\n\nBinar to Decimal " << decimal << " = " << binary  << endl << endl;

// !!!: //////////////////////////////    Reverse Words    ///////////////////////////////////
    {
        string revwords = "         First Second Third Fourth             ";
        cout << endl << "Before ReverseWords(): " << revwords << endl;
        reverseWords(revwords);
        cout << "After ReverseWords(): " << revwords << endl<< endl;
    }
    //RefToBaseParam();
    //ObjectBaseParamTo();

// !!!: //////////////////////////////    Get Max Occuring Char    ///////////////////////////////////
    char str[] = "ABCA\\\\\\";
    char letter = commonStuff.GetMaxOccuringChar_1(str);
    if( letter != '\0')
        cout << "1) Get Max Occuring Letter in string: " << str << " is " << letter << endl;
    else
        cout << "Empty string" << endl;

    char letter2 = commonStuff.GetMaxOccuringChar_2(str);
    if(letter2 != '\0') {
        cout << "2) Get Max Occuring Letter in string: " << str << " is " << letter2 << endl;
    }
    else {
        cout << "2) Get Max Occuring Letter: EMPTY string " << endl;
    }
    cout << endl;
    
// !!!: ///////////////////////////   Anagrams   /////////////////////////////////
    {
        string str1 = "tar";
        string str2 = "rat";
        bool res1 = Anagrams1(str1, str2);
        cout << "Anagrams1() of " << str1 << " and " << str2 << (res1? " is True" : " is False") << endl;
            
        bool res2 = Anagrams2(str1, str2);
        cout << "Anagrams2() of " << str1 << " and " << str2 << (res1? " is True" : " is False") << endl;
    }
// !!!: //////////////////////        Get Last Kth Element       //////////////////////////////////
    {
        list<int> list = {1, 2, 3, 4, 5, 6, 7};
        int K = 6;
        cout << "\n\n" << K << "th to Last Element in List: ";
        for(int i : list) {
            cout << i << ", ";
        }
        
        int kthToLast = commonStuff.getLastKthElement(list, K);
        cout << "\nis " << kthToLast << endl;
    }
    
// !!!: ////////////////////////      Remove String Letters      ////////////////////////////
    {
        string str1 = "AB DCFGF";
        string str2 = "FG";     // remove these chars in str11
        cout << "\n1) After removing letters in str2 = \"" << str2 << "\", from str1 = \"" << str1 << "\", is ";
        
         Remove_Str2_Letters_From_Str1_1(str1, str2);
        cout << "\"" << str1 << "\"";
        
        str1 = "AB DCFGF";
        cout << "\n2) After removing letters in str2 = \"" << str2 << "\", from str1 = \"" << str1 << "\", is ";
        Remove_Str2_Letters_From_Str1_2(str1, str2);
        cout << "\"" << str1 << "\"";
    }
    
// !!!: ////////////////////////      Largest 10 Numbers In Array       ////////////////////////////
    {
        vector<int> a1 = {8, 7, 10, 11, 1, 12, 2, 9, 3, 6, 4, 5};
        int k = 2;
        printVector(cout << "\nLargest " << k << " Numbers: ", a1);
        vector<int> result = Largest_K_Numbers(a1, k);
        printVector(result);

        printVector(cout << "\n1) Smallest " << k << " Numbers: ", a1);
        result = Smallest_K_Numbers_1(a1, k);
        printVector(result);
        
        printVector(cout << "\n2) Smallest " << k << " Numbers: ", a1);
        result = Smallest_K_Numbers_1(a1, k);
        printVector(result);
    }
    
// !!!: ////////////////////////      Find Zero-to-One Transition Point in SORTED Array       ////////////////////////////
    {
        // array must be Sorted
        vector<int> binaryArray = { 0,1}; //{1,1,1,1,1}; {0,0,0,0,0};
        cout << "\nOriginal array = ";
        printVector(binaryArray);
        int transpoint =commonStuff.transitionPoint_SortedArray_1( binaryArray );
        if( transpoint != -1)
            cout << "1) Transition Point Occured at index " << transpoint;
        else
            cout << "1) Transition Point was not found ";

        transpoint = commonStuff.transitionPoint_SortedArray_2( binaryArray );
        if( transpoint >= 0 ) {
           cout<<"\n2) Transition Point Occured at index "<< transpoint;
        }
        else{
           cout<<"\n2) Transition Point was Not Found" << transpoint;
        }
    }
    
// !!!: ////////////////////////      Create Patterns       ////////////////////////////
    {
        int rows = 7;
        int cols = 8;

        commonStuff.create_pattern_1 (rows, cols);
        cout << endl;
        commonStuff.create_pattern_2 (rows, cols);
        cout << endl;

        rows = 7; cols = 7; // rows must be equal to columns
        commonStuff.create_pattern_Diagonally (rows, cols);
        cout << endl;
        
        commonStuff. create_pattern_Diagonally_Recursuvilly (rows, cols);
    }
    
// !!!: ////////////////////////      Add Two Strings       ////////////////////////////
    {
        string s1 = "-1";     // handle corner cases: s1="1" and s2="". s1="1" ans s2="-1"
        string s2 = "-1";
        string result = addTwoStrings1(s1, s2);
        cout << "\nMethod 1: result of adding numbers in 2 strings ( \"" << s1 << "\" + \"" << s2 << "\") = " << "\"" << result << "\"\n";
       
        // This is better solution
        result = addTwoStrings2( s1, s2);
        cout << "Method 2: result of adding numbers in 2 strings ( \"" << s1 << "\" + \"" << s2 << "\") = " << "\"" << result << "\"" <<endl<<endl;
    }
 
// !!!: /////////////////      Translate AB to C      ///////////////////////
    {
        string s = "AABfghABsdfABysuAB";
        cout << (s + '\n');
        translateABtoC(s);
        cout << (s + '\n');
    }
// !!!: /////////////////////        Reverse Number      ///////////////////////////
    {
        int number = 1534236462; // !!!: 1534236461 = 0x5B72972D = max nuber that can be reversed;
        cout << "Number to be reversed             = " << number << endl;
        int result = Reverse_Number_3(number);
        cout << "After Reverse_Number_3(n)         = " << result <<endl;
        
        // My implementation in LeetCode
        result = Reverse_Number_MyLeetCode(number);
        cout << "After Reverse_Number_MyLeetCode() = " << result << endl;
        
        long long longresult = ReverseNumber_LeetCode(number);
        cout << "After ReverseNumber_LeetCode()    = " << longresult << endl;
    
        // Silly and simple, not worth it, using char[] not int for number
        /*int res = reverseLongNumber();
        cout << "After reverseLongNumber(): " << res <<endl<< endl;*/

        // 0xFFFFFFFF / A  = 0x19999999, OR,
        // 4,294,967,295 / 10 = 429496729
        int s= INT_MAX; // INT_MAX = 2147483647
        // int max_number = 2147483647; 4,294,967,295 = -1;
        int max_number = 4294967295; // Works for 1,534,236,462, but not for 1,534,236,469 = 0x5B729735 and 900000000 = 0x18711A00;
        cout << "\nNumber to be reversed             = " << max_number;
        int r = Reverse_Number_3(max_number);
        cout << "\nAfter Reverse_Number_3()          = " << r;
        
        // int n1 = 1534236469;    // 9000000000 = 0x18711A00
        r = Reverse_Number_MyLeetCode(max_number);
        cout << "\nAfter Reverse_Number_MyLeetCode() = " << r <<endl;
        
        long long longresult1 = ReverseNumber_LeetCode(max_number);
        cout << "After ReverseNumber_LeetCode()    = " << longresult1 << endl;
    }

// !!!: /////////////////         Remove Element       ////////////////////////
    {
        vector<int> numbers = {1,2,15,3,4,5,15};
        int element = 15;
        printVector(::cout << "Remove " << element << " from Array = " , numbers);
        commonStuff.deleteValue(numbers, element);
        printVector(::cout << "Array after removing " << element << " = " , numbers);
    }

// !!!: /////////////////         Compress String       ////////////////////////
    {
        string s = "aaaassss";
        cout << "CompressString() before = " << s+'\n';
        string result = compressString(s);
        cout << "CompressString() after = " << (result+"\n\n");
    }

// !!!: /////////////////         Merge Two Sorted Arrays       ///////////////////
    {
        vector<int> v1(2);
        v1 = {1,2};
        vector<int> v2 = {1,12,15};
        v2.resize(v1.size() + v2.size());
        Merge2SortedArrays_2(v1, v2);
    }

// !!!: /////////////////         Remove Substrings       ////////////////////////
    {
        string s1 = "One fish, two fish, red fish, blue fish";
        string s2 = "h";
        cout << "s1 before removing " << s2 << " : " << s1 << endl;
        
        removeSubstrs(s1, s2);
        cout << "s1 after  removing " << s2 << " : " << s1 << endl;
    }

    {
        int number = 58;
        string str = intToRoman(number);
    }
    {
        int arr[] = {3, 4, 5, 6};
        int size = 4;
        int target = 7;
        int result = Search_Binary_2(arr, size, target);
        cout << "Binary Search = " << result << endl;
    }

    
    
    
    
    
// !!!: /////////////////         Data Structure Practices      ////////////////////////
    {
        StringPractice();
        MapPractice();
        SetPractice();
        BitSetPractice();
        ListPractice();
        VectorPractice();
        ConstTypes();
    }
    
    
    
    
    
    
    
    
    
    
    
// !!!: /////////////////         Expermental Stuff      ////////////////////////
    {
        const int SIZE = 1;
        // Make a vector and set
        std::vector<int> v;
        std::set<int> s;
        // Populate the vector and set with the first SIZE integers
        for (int i = 0; i < SIZE; i++) {
            v.push_back(i);
        }
        for (int i = 0; i < SIZE; i++) {
            s.insert(i);
        }
        // Make a vector that contains random numbers in the range
        // stored within the vector and set
        // UniformRandomGenerator gen(0, SIZE - 1);
        int gen = rand();
        std::vector<int> search_values;
        for (int i = 0; i < SIZE; i++)
        search_values.push_back(gen);
        clock_t start_time, stop_time;

        // Search each data structure for the integers 0 to 1,000,000
        start_time = clock();
        for (int i = 0; i < SIZE; i++) {
            int seek = search_values[i];
            std::find(std::begin(v), std::end(v), seek);
        }
        stop_time = clock();
        std::cout << "Vector time: " << stop_time - start_time << '\n';
        
        start_time = clock();
        for (int i = 0; i < SIZE; i++) {
            int seek = search_values[i];
            s.find(seek);
        }
        stop_time = clock();
        std::cout << "Set time: " << stop_time - start_time << '\n';
    }
    {
        vector<int> nums {2,2,2};
        
        int totalsum = 0;
        int actualsum = 0;
        
        for(int num : nums) {
            actualsum += num;
        }
        for(int i=1; i < nums.size(); i++) {
            totalsum += i;
        }

        int diff = actualsum - totalsum;
        cout << endl << "actualsum - totalsum = " << diff << endl;
    }
    {
        // Function pointer
        void (*p)(void);
        int (*p1[100])(int, int);
        //(int (*arr1[100])(int, int)) arr[100]; // NOT OK

        //void arr2[100];   // NOT OK, array of
        void* array[100];   // OK, array of pointers
    }
    {
        struct ABC {int i;};
        size_t size = sizeof(ABC);
        struct ABC *ptr = (struct ABC *)0;
        struct ABC *ptr1;
        ptr++;ptr++;
        // !!!:  Warning: Format specifies type 'int' but the argument has type 'struct ABC *'
        //printf("\n\nSize of structure is: %d", ptr);

        cout << endl;
    }
    
// !!!: ////////////////    Removing constantnce    ///////////////////
    {
        const int n = 4;
        int const &const_ref = n;
        cout << "\nBefor Removing Constantance from 'Const Ref' to n = " << const_ref << endl;
        //++const_ref;    // Error: Cannot assign to variable 'const_ref' with const-qualified type 'const int &'
        int& nonconst_ref1 = const_cast<int&>(const_ref);
        ++nonconst_ref1 ;
        cout << "After Modiying 'Const Ref': " << "nonconst_ref1 = " << nonconst_ref1 << ", nonconst_ref = " << const_ref << ", n = " << n;
 
        const int const_int = n;
        cout << "\nBefor Removing Constantance from 'Const int' to n = " << const_ref << endl;
        // Error: Const_cast to 'int', which is not a reference, pointer-to-object, or pointer-to-data-member
        //int nonconst_ref2 = const_cast<int>(const_int);
    }


    {
        int x = -2;
        x = x << 1;
        printf("%d\n", x);  // print x = -4
    }
    {
        // !!!: Find size of struct without using sizeof(). Memeory is accessed at byte address or at boundary of WORD size address,
        // !!!: which is 4 bytes for my system
        // class s {short int f;} x;       // 2 bytes
        //class s {char c1; char c2; short int short1;} x;       // 4 bytes
        //class s {char c1; char c2; char c3; short int s;} x;       // 6 bytes
        //      {1 byte; 4 bytes    ; 1 byte }
        //class s {char c; short int f; char t;} x;         // 6 bytes
        //      {                                 }
        class s {char c; short int f; short int t;} x;    // 6 bytes
        s* ps = &x;
        //ps++;
        cout << endl << ps+1 << " - " <<  ps <<  "  = " << ps+1 - ps << endl;
        cout << "Size of struct s using pointers  = " << (char*)(ps+1) - (char*)ps  << " bytes" << endl;
        cout << "Size of struct s using sizeof(s) = " << sizeof(s) << " byte" << endl;
    }
    {
        int x = 0;
        int a[x];   // Variable 'x' is uninitialized when used here
        int size = (int )sizeof(a)/sizeof(a[0]);
        cout << "\na[" << x << "] = " << a[x] << "\tsize = " << size << endl;
    }
    {
        char  buffer1[5] = {'a', 'b', 'c', 'd', '\0'};
        const char* buffer2 = "abcd";
        cout << buffer1 << endl << buffer2 << endl << endl;
    }
    {
        // 0x10011cbe8
        // Where variable stored in memory
        int local;
        cout << "\nstack address               = " << &local;
        
        int* iq = new int;
        cout << "\n\nheap: new int               = " << iq;
        int* iw = (int*) malloc(sizeof(int));
        cout << "\nheap: malloc(int)           = " << iw << endl;

        static int staicLocal_uninitialized;
        cout << "\nglobal uninitialized        = " << &global_uninitialized;
        cout << "\nstatic global uninitialized = " << &static_global_uninitialized;
        cout << "\nstatic local uninitialized  = " << &staicLocal_uninitialized;

        // intialized static and globals
        static int staicLocalInit = 23;
        cout << "\n\nglobal intialzed            = " << &global_initialized;
        cout << "\nstatic global initlized     = " << &static_global_initialized;
        cout << "\nstatic local initlized      = " << &staicLocalInit << endl;
    }
    {
        // !!!: mixing signed and unsigned ints in logical decsion statments: 'if', 'while and 'for
        char i = -1;
        cout << endl << endl;
        while( i > 0 ) {
            printf( "T minues %d and counting \n", i--);
        }
        
        // pay attention to the the following code. it is not the same as above loop
        i = -128;
        while( i ) {    // !!!: i is evaluated as 'unsigned'. i=-128=0xFF which is >0 and evaluated to true
            printf( "T minues %d and counting \n", i--);    // -128, 127, 127...3, 2, 1, 0
        }

        cout << endl;
        if( 0 > -1 ) {
            cout << "expected: 0 > -1" << endl;
        }
        
        // now
        int si = -1;
        unsigned int ui = 0;
        // si is converted to unsigned type and compare it to ui.
        // since, we are comparing ui==0 and si=-1=0xFFFFFFFF, results in 0 < -1
        if( ui > si ) {     // or, if( si < ui ) same result.
            cout << "expected: 0 > -1" << endl;
        }
        else if( ui < si ) {
            cout << "not expected!!!: 0 < -1" << endl;
        }
        else{
            cout << "ui == si" << endl;
        }


    }

    {
        // Shallow Copy
        int* p = new int{77};
        int* q = p;     // copy the pointer p
        *p = 88;        // change the value of the int pointed to by p and q    }
        
        // Deep Copy
        int* p1 = new int{77};
        int* q1 = new int{*p1}; // allocate a new int, then copy the value pointed to by p
        *p1 = 88;               // change the value of the int pointed to by p
        
        cout << endl;
    }
    {
        bitset<128> flags = 0xb;
        size_t size = sizeof(flags);
        cout << size << endl;
        
        struct PPN {                    // R6000 Physical Page Number
            unsigned int PFN : 22 ;     // Page Frame Number
            int : 3 ;                   // unused
            unsigned int CCA : 3 ;      // Cache Coherency Algorithm
            bool nonreachable : 1 ;
            bool dirty : 1 ;
            bool valid : 1 ;
            bool global : 1 ;
        };                              // total bits = 32 which can fit in 4 bytes
        
        PPN ppn;
        size_t size1 = sizeof(PPN);
        cout << size1 << endl;
    }
    {
        // !!!: PRECEDENCE: pre post fix ++
        int a = 42;
        int b = ++(++a);    // ok: b = 44
        //  b = ++(a++);    // error: Expression is not assignable. Notice, slight difference from above
            b = ++++a;      // ok: b = 46
        //  b = ++a++;      // error: Expression is not assignable
        
        // !!!: PRECEDENCE: ++ and *
        int array[3] = {10, 20, 30};
        int* parray = array;
        // READING array through pointer using prefix, postfix ++ and *
        // pre increment
        int i0 = ++*parray;         // ok, i0 == 11: increment array value at parr and store it in i0
                                    // !!!: pay attention to this statement. it modifies array value at parray
        int i1 = *++parray;         // ok, i1 == 20: increment array pointer and store its value in i1
        // post increment
        int i2 = *parray++;         // ok, i2 == 20: store array value at parr in i2 and increment array pointer
        int i3 = (*parray)++;       // ok, i3 == 30: store array value at parr in i3, and increment array value at parray
                                    // !!!: pay attention to this statement. it modifies array value at parray
        int i4 = ++*parray++;       // ok: i4 == 32: get value and increment it, and increment pointer

        // now, WRITING array through pointer and prefix, postfix ++ and *
        parray = array;             // arr[] = 11, 20, 32
        ++*parray = 44;             // arr[] = 44, 20, 32. !!!: Notice: ++ has no effect. increment value at parray and store 44 at parray
        *++parray = 55;             // arr[] = 44, 55, 32
        
        // (*parray)++ = 99;        // error: Expression is not assignable. !!!: my explaination: (*parr)++ doesn't produce lvalue
        ++(*parray) = 99;           // !!!: ok, increment value at parray and store 99 at parray. result: 99 is stored at parray
                                    // arr[] = 44, 99, 32
        *parray++ = 55;             // also ok, arr[] = 44, 55, 32
        
        // (++*parray)++ = 66;        // error: Expression is not assignable
        ++*parray++ = 66;           // ok, arr[] = 44, 55, 66
        
        cout << endl;
    }
    {
        // !!!: CORVERSIONS
        double dbl1 = 3 * 5 / 2;    // dbl1 = 7. * and /: left to right
        double dbl2 = 3 / 5 * 2;    // dbl2 = 0. * and /: left to right
        cout << "dbl = " << dbl1 << "\tdb2 = " << dbl2 << endl;
        
        double d = 2.5;
        int i = 2;
        double d2 = d/i;    // d2 == 1.25
        int i2 = d/i;       // i2 == 1. Warning: Implicit conversion turns floating-point number into integer: 'double' to 'int'
        // int i3 {d/i};       // error: double -> int conversion may narrow (§3.9.2)
                            // Type 'double' cannot be narrowed to 'int' in initializer list

        i2 = d/i; // i2 == 1
    }
    {
        // !!!: for loop vs while loop
        int max_length = 10;
        int quest_count = 0;
        char input_line[max_length];
        input_line[4] = '?';
        
        for (int i=0; i != max_length; i++) {
            if (input_line[i] == '?') {
                quest_count++;
            }
        }
        cout << quest_count << "\t";;
        
        // using while loop:
        int i = 0;
        while( i < max_length && input_line[i] == '?' ) {
            quest_count++;
        }
        cout << quest_count << endl;
    }
    {
        int a[3] = {1,5,7};
        //  int i = *a++;   // ERROR: Cannot increment value of type 'int[3]'
        int i = (*a)++;     // OK, i = 1 and (*a)++ = p[0]++ = 2
        cout << i << " " << *a << " ";
        (*a)++;             // ok
        cout << *a << endl;
    }
    {
        for(int i: {1,2,3,4,5,6,7,8,9})
            cout << i << " ";
        cout << endl;

        int i = 1;
        do {
            cout << i++ << " ";
        } while(i < 10) ;
        cout << endl;


        i = 1;
        loop:
            cout << i++ << " ";
        if(i < 10) goto loop;
        cout << endl;

        i = 1;
        while(i < 10 ) {
            cout << ++i << " ";
        }
        cout << endl;

        i = 1;
        do {
            cout << ++i << " ";
        } while(i < 10) ;
        cout << endl;
    }
    {
        char* str = const_cast<char* >("ABCD");
        int count = 0;
        // while( (*str)++ ) // Runtime Error. what is wrong? move inner parentheses
        while( *str++ )
            count++;
        cout << endl << "str count = " << count << endl << endl;
    }
    {
        int a = 0, b = 1;
        //not A and not B  == not ( A or B )
        bool flag1 = !a && !b;
        bool flag2 = !(a || b);
        
        // not A and B  = not ( A or not B )
        flag1  = !a && b;
        flag2 = !(a || !b);
    }
    // lval
    {
        int array[5] = {100, 200, 30, 40, 50};
        int *ptr = array;
        *ptr++ = 3; // *ptr = 3 and post increment ptr. ptr now points to 200: {3,    200, 30, 40,5 0}.
        ++*ptr = 4; // *ptr = 4. Pre increment has no effect here, ptr is still pointing to 4: {3, 4,    30, 40, 50}
        *++ptr = 5; // Pre increment ptr, now ptr points to 30, then *ptr = 5: {3, 4 ,5    ,40,50}
        //(*ptr)++ = 6; // Expression is not assignable: not Left Hand Value
        ++(*ptr) = 7;   // Ok. {3, 4, ,5 ,  40,50}. Pre increment has no effect here
        printf("\n\narray[0] = %d, array[1] = %d, array[2] = %d, *array = %d", array[0], array[1], array[2], *ptr);
    }
    {
        long i = -1;
        // !!!: sizeof(i) returns 'unsigned int', 'i' is promoted to 'unsigned int' and compare it to sizeof(i)
        if(i < sizeof(i) ) {
             printf("\nOK\n");
        }
        else {
             printf("\nERROR\n");
        }
         
        // 2π rad = 360º -> rad = 360º / 2*π rad ≈ 57.295779513082321 º/rad.
        // for angle = 90º -> 90º/(57.30 º/rad) ≈ 1.570796 rad
        cout << "\nSineWave(90º) = " << sin( 1.570796326794897 ) << endl;
        
        // 1) create sinewave array
        double angles[10];
        for( int angle=0; angle < 360; angle+=10 ) {
            double magnitude = 10 * sin( angle / (360/(2*M_PI)) );
            cout << "angle = " << angle << "º, magnitude = " << magnitude << endl ;

            angles[angle] = magnitude;
        }
        
        // 2) dispaly sinewave array
        
        cout << endl;
    }
    
    {
        int i = -32;
        int rem = i % 0xFFFFFFFF;
        int y = 1 << i;            // if, (>31) or (<0): compiler doesn't perform a shifit => 1<<0
        cout << hex << "y = 0x" << y << endl;
        
        for(int i=-1; i>-127; i--) {
            int y = 1 << i;            // if, (>31) or (<0): compiler doesn't perform a shifit => 1<<0
            // int z = 1 << i;
            cout << dec << "i = " << i << hex << ", y = 0x" << y << endl;
        }
    }
    {
        // Type Conversion
        
        float  flt = float(1)/5;    cout << endl << flt;
        flt = 1/5;    cout << endl << flt;

        unsigned int y = -1;
        std::cout << endl << y << endl;
        int x = y;
        std::cout << x << endl;
        y = x;
        std::cout << y << endl;

    }
    
    return 0;
}


/*{
    //string str = intToRoman(2999);
    //cout << str << endl;
}
{
    *vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};;
    int res = trappingWater(height);  // Needs work
    cout << res << endl;
}*/

// !!!: ////////////////////////////      Swap Range Of Bits in Integer    ////////////////////

// !!!: ////////////////////////////      Does Interger Have Alternating Bits    ////////////////////

// !!!: ////////////////////////////     Count Set Bits in Char    //////////////////////////////////////////

