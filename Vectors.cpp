//
//  Vectors.cpp
//  Practice1
//
//  Created by Taher Benisa on 9/1/22.
//  Copyright © 2022 taher benisa. All rights reserved.
//

#include "Vectors.hpp"
//#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::istream;
using std::ostream;

// !!!: ///////////////////////////////        Vectors     //////////////////////////////////
///
// compute mean and median temperatures
void ComputeMeanAndMedianTempertures()
{
    vector<double> temps; // temperatures
    for (double temp; cin>>temp; ) {    // read into temp
        temps.push_back(temp);          // put temp into vector
    }
    
    // compute mean temperature:
    double sum = 0;
    for (double x : temps) sum += x;
    cout << "Average temperature: " << sum/temps.size() << '\n';
    
    // compute median temperature:
    sort(temps.begin(), temps.end()); // sort temperatures
    cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}

void Test(double* d) {
    
}

void VectorPractice(void)
{
    {
        // !!!: √√√
        vector v1 {3}; // one element with the value 3.0
        vector<int> v2(3); // three elements each with the (default) value 0.0
    }
    {
        // 2D vectors<int>: static decleration
        vector<vector<int>> matrix1 (2, vector<int>(3));        // [2][3]: default initialization = 0
        vector<vector<int>> matrix2 = { vector<int>(2) };       // [1][2]: default initialization = 0
        vector<vector<int>> matrix3 = { vector<int>(2, 99) };   // [1][2]: initialized to 4
        // jagged 2D array using vector<>: [2][X] = { {0, 0} , {77, 77, 77} }
        vector<vector<int>> matrix4 = { vector<int>(2), vector<int>(3, 77) };
        // jagged 2D array using vector<>: [2][X] = { {66, 66} , {77, 77, 77} }
        vector<vector<int>> matrix5 = { vector<int>(2) = {66,66}, vector<int>(3, 77) };
        matrix2[0][0];
    }
    {
        vector<string> svec(10);                // size = 10 and string = "", on the stack
        vector<string> svec1(10, "defualt");    // size = 10 and string = "defualt", on the stack
        vector<string> *pvec1 = new vector<string>(10); // size = 10 strings, on the heap

        vector<string> *pvec2 = new vector<string>[10];    // ok, size = 10 strings, on the heap

        vector<string> *pv1 = &svec;
        vector<string> *pv2 = pvec1;
        delete pvec1;
       // delete [] pvec2;
        //delete pv1;   // can not delete a pointer varaiable created on the stack
        //delete pv2;
    }

    {
        // NOTE: v1 and v2 point to the same vector
        vector<int> *v1 = new vector<int>({1,2,3});
        vector<int> *v2;
        v2=v1;
        v1->push_back(4);
        v2->push_back(5);
        printVector(*v1);
        printVector(*v2);
        cout << endl;
    }

    {
        // Temporary whose address is used as value of local variable 'coefficients' will be destroyed at the end of the full-expression
        double* coefficients = (double[3]) {4.5, 1.0, -3.5};
    }
    {   /*
        vector<string> words;
        for(string temp; cin>>temp; ) {// read whitespace-separated words
            words.push_back(temp); // put into vector
        }
        cout << "Number of words: " << words.size() << '\n';
        
        sort(words.begin(), words.end()); // sort the words
        
        for (int i = 0; i<words.size(); ++i) {
            if (i==0 || words[i-1]!=words[i]) { // is this a !!!: new word?
                cout << words[i] << "\n";
            }
        }*/
    }
    cout << '\n';
    {
        // constructors used in the same order as described above:
        std::vector<int> first;                                // empty vector of ints
        std::vector<int> second (4,100);                       // four ints with value 100
        std::vector<int> third (second.begin(),second.end());  // iterating through second
        std::vector<int> fourth (third);                       // a copy of third
    }
    {
        // find() with vectors? You can use std::find from <algorithm>:
        vector<int> vec;
        // can have other data types instead of int but must same datatype as item
        bool found =  std::find(vec.begin(), vec.end(), 5) != vec.end();
        cout << found << endl;
        // This returns a bool (true if present, false otherwise). With your example:

        if ( std::find(vec.begin(), vec.end(), 5) != vec.end() ) {
           // do_this();
        }
        else {
           // do_that();
        }
    }
    // 2d vector stuff
    {
        vector<vector<int>> sum;
        // Build sub-array first, then push it at back onto v
        vector<int> v = {12, 34};
        sum.push_back(v);
        
        int row = 0;
        sum[row].push_back(7);
        sum[row].push_back(84);
        sum.push_back(v);

        vector<int> v1 = {56, 89};
        sum.push_back(v1);
        sum[0][0] = 99;
        
        cout << endl;
    }
    {
        vector<double> temps; // temperatures
        /*for (double temp; cin>>temp; ) // read into temp
            temps.push_back(temp); // put temp into vector*/
        // . . . do something . . .
        cout << endl;
    }

    // Traversing vector of vectors: method 1
    vector<vector<int>> vv(2, vector<int>(3,8));
    for(vector v : vv) {
        for(int i : v) {
            cout << i << ",";
        }
    }

    // Traversing vector of vectors: method 2
    // !!!: Greate to know: Creating and Intialzing 2D vector
    vector<vector<int>> xx(3, vector<int>(4, 55));   // 3x4 intialized to 55
    
    vector<vector<int>> vect
    {
           {1, 2, 3, 2},
           {4, 5, 6   },
           {7, 8, 9   },
        {}
    };
    long int row = vect.size();     cout << row << endl;
    long int col = vect[3].size();  cout << col << endl;
    for (int i = 0; i < vect.size(); i++)
     {
         for (int j = 0; j <vect[i].size(); j++)
         {
             cout << vect[i][j] << " ";
         }
         cout << endl;
     }

    // Traversing vector of vectors: method 3
    vector<int> nums = {-1,1,2,3,4};
    for (auto it = nums.begin(); it != nums.end();) {
        if (*it <= 0) {
            it = nums.erase(it);
        } else {
            it++;
        }
    }
}

void printVector(vector<int>& nums)
{
    long unsigned int size = nums.size();
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

// Overloaded function, using ostream out
void printVector(ostream& out, vector<int>& nums)
{
    out << "";
    long unsigned int size = nums.size();
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

 void printVectors(vector<vector<int>>& nums) {
        // vector<vector<int>>   result(2, vector<int>(3,8));
        // vector<vector<int>>   result2 = { 2, vector<int>(3,8) };
        vector<vector<int>>::iterator itr;

     for(itr = nums.begin(); itr != nums.end(); itr++) {
            vector<int> t = *itr;
            vector<int>::iterator itr1;
            cout << " [";
            size_t size = t.size();
            for(itr1 = itr->begin(); itr1 != itr->end(); itr1++) {
                cout << *itr1;
                if(--size)
                    cout << ", ";
            }
            cout << "]";
        }
}

void assigingVectors(vector<int>& a, vector<int>& b)
{
    a = b;
}

void simpleDictionary( void )
{
    // simple dictionary: list of sorted words
    vector<string> words;
    string temp ;
    
    // Method 1:
    while( cout << "Please enter a number: " && cin >> temp ) {
        words.push_back(temp);
    }
        
    // Method 2:
    /*while (cin >> temp) {
        words.push_back(temp);
    }*/
    
    // Method 3: or if you're looking for a way to take the extraction out of the loop condition, the following is equivalent:
    /*cin >> temp;
    while (cin)
    {
        words.push_back(temp);
        cin >> temp;
    }*/
    
    // Method 4: This's a lousy use case for a for loop.
    /*for( string temp; cin >> temp; ) {  // read whitespace-separated words
        words.push_back(temp);          // put into vector
    }*/

    cout << "Number of words: " << words.size() << '\n';
    sort(words.begin(), words.end());   // sort the words
   
    for( int i = 0; i < words.size(); ++i ) {
        if( i == 0 || words[i-1] != words[i] ) {  // is this a new word?
            cout << words[i] << "\n";
        }
    }
}




template <class myType> myType GetMax (myType a, myType b) {
    return (a>b?a:b);
}
