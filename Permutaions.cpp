//
//  Permutaions.cpp
//  Practice1
//
//  Created by taher benisa on 12/20/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "Permutaions.hpp"
#include "DataStructures.hpp"
#include "Vectors.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::istream;
using std::ostream;

int Factorial_Recursively(int n) {
    int result = 0 ;
    
    /*if(n == 0){
        return 1;
    }*/

     if(n == 1) {
         return n;
     }

    cout << "n before Call = " << n << ",  Result = " << result <<",\n";
    result = n * Factorial_Recursively(n - 1);
    cout << "n after Call  = " << n << ",  Result = " << result <<",\n";
    return result;
}

int Factorial(int n) {
    int result = n ;
    while(--n > 1) {    // both work: while(--n > 1) and while(n-- > 2)
        result *= n;
    }
 
    /* this works too
    int result = n ;
    while( n > 1) {
        result *= n-1;
        --n;
    }*/
    return result;
}


int Fibonacci_Recursively(int number)
{
    if(number == 1) {
        return 1;
    }
    if(number == 0) {
        return 0;
    }

    // number = 0 1 2 3 4 5 6 7
    // index  = 0 1 1 2 3 5 8 13....
    cout << endl << "left f1(i-1): i = "<< number << ", " ;
    int leftSum = Fibonacci_Recursively(number - 1);
    cout << "Left  Sum = " << leftSum << endl;
    
    cout << endl << "right f2(i-2): i = "<< number << ", ";
    int rightSum = Fibonacci_Recursively(number - 2);
    cout << "Right sum = " << rightSum << endl;

    int totalsum = leftSum + rightSum;
    cout << "Total Sum = " << totalsum  << endl;
    return totalsum;
}

int Fibonacci_Iteratively(int number)
{
    if(number == 0) {
        return 0;
    }
    if(number == 1) {
        return 1;
    }
    
    // number = 0 1 2 3 4 5 6 7
    // index  = 0 1 1 2 3 5 8 13....
    int i = 1;
    int sum1 = 0;
    int sum2 = 1;
    int sum = 0;
    cout << "i" << "  " << "sum" << endl;
    cout << "   " << sum1 << endl;
    cout << "   " <<sum2 << endl;
    while(i < number) {
        sum = sum1 + sum2;
        sum1 = sum2;
        sum2 = sum;
        cout << std::dec << i << ": " << sum << endl;

        i++;
    }
    
    return sum;
}


// Good job. print all combinations of a phonepad[buttons] strings.
// !!!: Notice no phone number is required
void Print_AllCombinationsOfPhonePadLetters_Iteratively( void )
{
    // phonepad[buttons] is an array of 8-buttons strings
    int buttons = 8;
    string phonepad[buttons];
    phonepad[0] = "ABC";
    phonepad[1] = "DEF";
    phonepad[2] = "GHI";
    phonepad[3] = "JKL";
    phonepad[4] = "MNO";
    phonepad[5] = "PQRS";
    phonepad[6] = "TUV";
    phonepad[7] = "WXYZ";
    
    // !!!: There are 11,664 combinations = 3 * 3 * 3 * 3 * 3 * 4 * 3 * 4
    int i = 1;
    for(char c0 : phonepad[0])
    {
        for(char c1 : phonepad[1])
        {
            for(char c2 : phonepad[2])
            {
                for(char c3 : phonepad[3])
                {
                    for(char c4 : phonepad[4])
                    {
                        for(char c5 : phonepad[5])
                        {
                            for(char c6 : phonepad[6])
                            {
                                for(char c7 : phonepad[7])
                                {
                                    cout<< i++ << ".\t" << c0 << c1 << c2 << c3 << c4 << c5 << c6 << c7 << endl;
                                    //!!!!: cout << phonepad[i] << phonepad[j] << phonepad[k] << phonepad[l] << phonepad[m]...;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// !!!: Iterative Solution: number must have 7 digits.
// Print All letter combinations for a 7 digit phone number. !!!: phoneNumber must be 7-digits, otherwise it is meaningless
void print_7digitTelephoneNumber_Iteratively(vector<int> phoneNumber) {
    int buttons = 10;
    string phonepad[buttons];
    // Digits 0 and 1 are left blank
    phonepad[0] = "000";
    phonepad[1] = "111";
    phonepad[2] = "ABC";
    phonepad[3] = "DEF";
    phonepad[4] = "GHI";
    phonepad[5] = "JKL";
    phonepad[6] = "MNO";
    phonepad[7] = "PRS";
    phonepad[8] = "TUV";
    phonepad[9] = "WXY";

    // !!!: There are 11,664 combinations = 3 * 3 * 3 * 3 * 3 * 4 * 3 * 4
    int i = 1;
    // Added 2 to array index
    // 4, 9, 7, 1, 9, 2, 7}
    for(char c0 : phonepad[phoneNumber[0]])
    {
        for(char c1 : phonepad[phoneNumber[1]])
        {
            for(char c2 : phonepad[phoneNumber[2]])
            {
                for(char c3 : phonepad[phoneNumber[3]])
                {
                    for(char c4 : phonepad[phoneNumber[4]])
                    {
                        for(char c5 : phonepad[phoneNumber[5]])
                        {
                            for(char c6 : phonepad[phoneNumber[6]])
                            {
                                cout<< i++ << ".\t" << c0 << c1 << c2 << c3 << c4 << c5 << c6 << endl;
                                //!!!!: cout << phonepad[i] << phonepad[j] << phonepad[k] << phonepad[l] << phonepad[m]...;
                            }
                        }
                    }
                }
            }
        }
    }
}


/* !!!: Find where these comments go
 !!!: Recursion:
 !!!: 1. You can think of the code before the recursive calls as happening on the way down the tree:
 !!!: 2. It compares the given key against the key at each node and moves right or left accordingly.
 !!!: 3. Then, think of the code after the recursive calls as happening on the way up the tree.
*/


// !!!: /////////////////////         Combinations        ////////////////////////

// !!!: Number can have any number-of-digits and Digits in keypad can be any length
void keypadCombinations_Recursively1( vector<int> phoneNumber ) {
    
    // digitIndex = 0, means row = 0
    int digitIndex = 0;
    keypadCombinations_Recursively_Utl1( phoneNumber, digitIndex );
}

// !!!: Algortihm is DFS. Less parameters than keypadCombinations_Recursively_Utl2. You do not pass string as parameter, so string must be static and saved before recursion
void keypadCombinations_Recursively_Utl1(vector<int> phoneNumber, int digitIndex /* digit=0 */) {
    static int Combinations = 0;  // Used for debugging only

    const int buttons = 10;
    static string keypad[buttons];        // !!!: Variable length array declaration cannot have 'static' storage duration
        keypad[0] = "000";                // Digits 0 and 1 are left blank on this phone pad
        keypad[1] = "111";                // All strings have same size = 3
        keypad[2] = "ABC";
        keypad[3] = "DEF";
        keypad[4] = "GHI";
        keypad[5] = "JKL";
        keypad[6] = "MNO";
        keypad[7] = "PQRS";
        keypad[8] = "TUV";
        keypad[9] = "WXYZ";

    static string currString = "";       // !!!: Must be static to remember its value between function calls,
                                        // !!!: otherwise pass it as a paramter.
    string prevString = "";             // !!!: Must not be static. it is a temp value, not used cross function calls,
                                        // !!!: and therefore it is decalred local (on the stack)

    // maxDigits is constant, since phoneNumber size doesn't change between calls
    size_t maxDigits = phoneNumber.size();   // !!!: should, size = maxDigits, be static?

    // exit condition: test if reached end of digits ---> digitIndex == maxDigits
    if( digitIndex == maxDigits ) {
        // reached end of digits in phoneNumber[] array, print current string
        cout << "Print \"" << currString << "\"   Combinations = " << ++Combinations << endl << endl;
        return;
    }
    
    // !!!: Do the following code for each row in keypad
    // !!!: We use digit to index into phoneNumber[digit] array, from which we get the row index for current keypad row
    int row = phoneNumber[digitIndex];
    
    // !!!: From Keeypad[], we get size of the string corresponding to current digit
    size_t COLS = keypad[row].size();
    
    // traverse all row's columns
    for(int col=0; col<COLS; col++) {
        prevString = currString;         // Save curString here or above
        
        //           keypad[           row = digitIndex][col]
        currString += keypad[phoneNumber[digitIndex]][col];  // add a char from each keypad row to current string

        cout << "String = " << currString << "\t\tdigitIndex = " << digitIndex << "\trow = " << row << "\tcol = " << col << endl;
       // cout << "PUSH str = " << curString << endl;
        
        keypadCombinations_Recursively_Utl1( phoneNumber, digitIndex+1 );
        //cout << "String = " << prevString << "\t\tdigitIndex = " << digitIndex << "\trow = " << row <<"\tcol = " << col << endl;
        //cout << "POP  str = " << prevString << endl;
        currString = prevString;
     }
}

// From geeksforgeeks. Function to find all possible combinations by replacing key's digits with characters of the corresponding list
// !!!: Number can have any number-of-digits. Digits in keypad can be any N length
// !!!: Alogrithm (DFS): Similr to keypadCombinations_Recursively1(). It takes keypad[] as a second paramter.
void Print_keypadCombinations_Recursively_2(vector<char> keypad[], vector<int> phoneNumber)
{
    // Size of the list corresponding to current digit
    int phoneNumberSize = (int )phoneNumber.size();
    Print_keypadCombinations_Recursively_2_Utl(keypad, phoneNumber, string(""), 0, phoneNumberSize);
}
// !!!: Note: string result And int row parameters can be ommited and defined as static inside recursive function.
// !!!: See keypadCombinations_Recursively3(vector<int> phoneNumber)
void Print_keypadCombinations_Recursively_2_Utl(vector<char> keypad[], vector<int> phoneNumber, string result, int row/*row=0*/, int ROWS) {
    // !!!: digitIndex = row
    // If processed every digit of key, print result
    if (row == ROWS) {
        cout << result << " \n";
        result = "";
        return;
    }
 
    // From phoneNumber, we get digit for current row
    int digit = phoneNumber[row];
    // From Keeypad[], we get size of the string corresponding to current digit
    size_t COLS = keypad[digit].size();
    
    // One by one replace the digit with each character in the corresponding list and recur for next digit
    // !!!: col = 0 ---> digit size
    for (int col = 0; col < COLS; col++) {
        string nextString = result + keypad[digit][col];
        cout << "PUSH digit index = " << row << ", col = " << col << ", result = " << nextString << endl;
        Print_keypadCombinations_Recursively_2_Utl(keypad, phoneNumber, nextString, row+1, ROWS);
        cout << "POP  digit index = " << row << ", col = " << col << ", result = " << result << endl;
    }
}

// !!!: PERFECT
// !!!: Algortihm is (DFS). Less parameters than keypadCombinations_Recursively_Utl2. You do not pass string,
// !!!: digitIndex (row) and size as parameters, So String and Keypad row must be static and saved before recursion
// !!!: Number can have any number-of-digits. Digits in keypad can be any N length
void Print_keypadCombinations_Recursively_3(vector<int> phoneNumber) {
    static int Combinations = 0;      // Used for debugging only = keypad[i] * keypad[j] * keypad[k] ...

    const int buttons = 10;
    static string keypad[buttons];    // !!!: Variable length array declaration cannot have 'static' storage duration
    keypad[0] = "000";                // Digits 0 and 1 are left blank on this phone pad
    keypad[1] = "111";
    keypad[2] = "ABC";
    keypad[3] = "DEF";
    keypad[4] = "GHI";
    keypad[5] = "JKL";
    keypad[6] = "MNO";
    keypad[7] = "PQRS";
    keypad[8] = "TUV";
    keypad[9] = "WXYZ";

    static int keypad_row = 0;                 // !!!: Must be static to remember its value between function calls
    static string curString = "";              // !!!: Must be static to remember its value between function calls

    // From phoneNumber, we get the number of keypad ROWS
    size_t keypad_ROWS = phoneNumber.size();   // !!!: should size be static? It can be static, but not neccessay,
                                               // !!!: it is derived from phoneNumber which is passed on stack
    if( keypad_row == keypad_ROWS ) {
        cout << "Combination = " << ++Combinations << "      str = " << curString <<endl;
       return;
    }

    // From Keypad, we get the number of keypad COLUMNS
    size_t keypad_COLS = keypad[ phoneNumber[keypad_row] ].size();
    
    for( int keypad_col=0; keypad_col<keypad_COLS; keypad_col++ ) {
        string prevString = curString; // Save curString here or above
        //cout << "PUSH str = " << prevString << endl;

        curString += keypad[ phoneNumber[keypad_row] ][keypad_col];
        keypad_row++;
        Print_keypadCombinations_Recursively_3(phoneNumber);
        keypad_row--;
        curString = prevString;

        //cout << "POP  str = " << prevString << endl;
     }
}


// !!!: Algorithm: Itertive Solution. Breadth First Search (BFS) from Geeks. Digits in keypad can be any length N
// !!!: Function to return a vector that contains all the generated letter combinations using Queue
vector<string> Print_keypadCombinations_GeeksSolution(vector<int> phoneNumber)
{
    // To store the generated letter combinations
    vector<string> list;
    
    int numLetters = static_cast<int>(phoneNumber.size());
 
    // table[i] stores all characters that corresponds to ith digit in phone
     string keypad[10] = { "0",   "1",   "ABC",  "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
      
    queue<string> q;
    q.push("");
 
    int counter = 0;  // Used for debugging only
    while (!q.empty()) {
        string popedString = q.front();
        q.pop();
        int size = (int )popedString.size();

        // If complete word is generated push it in the list
        if (popedString.length() == numLetters) {
            list.push_back(popedString);
            counter++;
        }
        else {
            // Try all possible letters for current digit in number[]
            // !!!: Size of poped string determines the index into phoneNumber[]
            //int size = (int )popedString.size();
            string digitString = keypad[phoneNumber[size]];
            cout << "Digit String = " << digitString << endl;
            cout  << "POP  str = " << popedString << endl;
            for(int i=0; i<digitString.size(); i++) {
                char letter = digitString[i];
                cout  << "PUSH str = " << popedString + letter << endl;
                q.push(popedString + letter);
                
                counter++;
            }
            // Another approch: compact code
            /*for (auto letter : keypad[phoneNumber[popedString.size()]]) {
                cout  << "PUSH str = " << popedString + letter << endl;
                q.push(popedString + letter);
                counter++;
            }*/
            cout << endl;
        }
    }
 
    cout << "Total Iterations = " << counter << endl;
    
    // Return the generated list
    return list;
}

// !!!: My code. Works Iteratively Beautiful. Using letterIndex[] as extra space
// Algorithm: There are 3^n combinations for n digits phone number. examples: phoneNum[n] = {2,3,4} => 3^3 = 27.
// !!!: All digits in keypad MUST be N length
// Use extra space for tracking letters in a digit => letterIndex[PHONE_NUMBER_LENGTH]
void Print_keypadCombinations_MySolution(vector<int> phoneNumber)
{
    int counter = 0;  // Used for debgging
    string keyPad[10] {
        "000", "111", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"
    };
    
    // PHONE_NUMBER_LENGTH = ROWS
    size_t PHONE_NUMBER_LENGTH = phoneNumber.size();    // count = COLS
    // LETTERS_PER_KEY = COLUMNS
    size_t LETTERS_PER_KEY = 3;
    size_t maxcount = (size_t )pow(LETTERS_PER_KEY, PHONE_NUMBER_LENGTH);   // !!!: O(3^N)

    // Could have used: colIndex[PHONE_NUMBER_LENGTH] = {0};
    vector<int> letterCol(PHONE_NUMBER_LENGTH, 0);   // Use either name: colIndex or letterIndex

    for(int count=1; count<=maxcount; count++) {
        
        // First, print current string:
        string str = "";
        for(int digit=0; digit<PHONE_NUMBER_LENGTH; digit++) {
                // keyPad [       row        ] [       col      ]
            str += keyPad [phoneNumber[digit]] [letterCol[digit]];
        }
        cout << str << endl;
        
        // Update next letters (column) indicies
        int tempCount = count;
        size_t digit = PHONE_NUMBER_LENGTH - 1;
        // !!!: letterColIndex[digit], digit=0 ---> PHONE_NUMBER_LENGTH-1, is ordered Most-Significant index to Least-Significant index
        do {
            letterCol[digit] = tempCount % LETTERS_PER_KEY;
            tempCount = tempCount / LETTERS_PER_KEY;
            digit--;
            counter++;
        } while(tempCount > 0);
    }

    cout << "Total Iterations = " << counter << endl;
}



////////////////////////////////////////////////////////         String Permutations        /////////////////////////////////////////////////////////////////
///
// Function to print permutations of string. This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
// !!!: Rrecursive function. Depth First Search
/*
 Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 Example 1:
 Input: nums = [1,2,3]. n!=3X2X1=6
 Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 Example 2:
 Input: nums = [0,1]
 Output: [[0,1],[1,0]]
 
 Example 3:
 Input: nums = [1]
 Output: [[1]]
  
 Constraints:

 1 <= nums.length <= 6
 -10 <= nums[i] <= 10
 All the integers of nums are unique.
 */

/*
*   Prints all the permutations of vector a in the ndex range begin...end, inclusive.
    The function's behavior is undefined if begin or end represents an index outside
    of the bounds of vector a.
*/
void printPermutation_Recursively2( vector<int>& array, int left, int right )
{
    if (left == right) {
        // print a permutation
        printVector(cout<<"               ", array);
    }
    else {
        for( int i = left; i <= right; i++ ) {
            // interchange left element with current element (at position i)
            std::swap( array[left], array[i] );
            // Recursively permute the rest of the vector
            printPermutation_Recursively2( array, left + 1, right );
            // Interchange the current element at the first position with the current element at position i
            std::swap(array[left], array[i]);
        }
    }
}

// similar to above function. instead of permuting over array of ints, now we permute over a string
void printPermutation_Recursively1( string str, int left, int right ) {
    if(left == right) {
       //cout << "left = " << left << endl;
       cout << "      Print \"" << str << "\"" << endl;
       // return; do not need to. doesn't make a difference
    }
    else {
       // A B C D
       // i=0 -> i=3.  left=0 -> left=2
       for(int i = left; i<= right; i++) {
           string temp = str;
           cout << "DOWN: Swap  " << "\"" << str << "\"" << "  left = " << left << ", i = " << i << endl;
           std::swap(str[left], str[i]);
          
           printPermutation_Recursively1(str, left + 1, right);
          
           //cout << "Swaped String = " << str << e ndl;
           //swap(str[left], str[i]); //swap back for backtracking
           str = temp;
          
           cout << "UP  :       " << "\"" << str << "\"" << "  left = " << left << ", i = " << i << endl << endl;
      }
   }
}

// My solution: under construction
void printPermutation_Recursively_mine(string str, int level) {
    static unsigned long len = str.size();
    static string originalString = str;
    static string str1 = "";
    //static int level = x;

    if(level == 0) {
        cout << str1 << " ";
        return;
    }
    
    //for(int count=0; count<=str.size(); count++) {
        // Go Left
        str1 += str[level-1];
        string tempstr = str1;
        
        printPermutation_Recursively_mine(str, level-1);
        
        str1 = tempstr;
        int i = (int )str1.size()-1;
        int j = (int )str1.size()-2;
        std::swap(str1[i], str1[j]);

        // Go Righ
        printPermutation_Recursively_mine(str, level-1);
    //}
}

// Iterative function to find permutations of a String
void Print_StringPermutation_Iteratively(string str)
{
    size_t size = str.length();
 
    // Weight index control array initialized by 0
    int p[size];
    for (int i = 0; i < size; i++) {
        // p[i] == i controls iteration and index boundaries for i
        p[i] = 0;
    }
 
    // i, j represents upper and lower bound index respectively for swapping
    int i = 1, j = 0;
 
    // Print given string, as only its permutations will be printed later
    cout << str << endl;
 
    while (i < size)
    {
        if (p[i] < i)
        {
            // if i is odd then j = p[i], otherwise j = 0
            j = (i % 2) * p[i];
 
            std::swap(str[j], str[i]);
 
            // Print current permutation
            cout << str << endl;
 
            p[i]++; // increase index "weight" for i by one
            i = 1;  // reset index i to 1
        }
        // otherwise p[i] == i
        else
        {
            // reset p[i] to zero
            p[i] = 0;
 
            // set new index value for i (increase by one)
            i++;
        }
    }
}




// From D.S Malik text book
int Find_LargestNumberRecursively(const int a[], int left, int right)
{
    // 5 10 12 8
    // {5, 10, 12, 8, 9, 2}
    int max;
    if (left == right) {//size of the sublist is one
        cout << "End of Array" << endl;
        return a[right]; // return last element. a[left] == a[right]
    }
    else
    {
        cout << "Left = " << left << endl;
        max = Find_LargestNumberRecursively(a, left + 1, right);
        cout << "Left = " << left << ", Max = " << max << endl;
        if (a[left] >= max)
            return a[left];
        else
            return max;
    }
}


// phone digits:  2      3      4      5      6       7      8      9
// index       :  0      1      2      3      4       5      6      7
string str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


// I don't about this still not working i think
int CombinationsOf_3_5_10(int n)
{
    int a[3] = {3, 5, 10};
    int delta = 0;
    int count = 0;
    int whole ;
    int remainder = 0;
    
    for(int i=0; i < 3; i++)
    {
        for(int j=i, k = 0; j < 3; j++)
        {
            cout << endl << endl;
            if( n % a[j] == 0)
                count++;
            k=1;
            delta = n - (a[i] * k++);
            do{
                whole = delta / a[j+1];
                remainder = delta % a[j+1];
                
                if( remainder == 0)
                    count++;
                
                cout << "delta = " << delta << "\twhole = " << whole  << "\tremainder = " << remainder << "\tcount = " << count << endl;
                
                delta = n - (a[i] * k++);
            }
            while( whole > 0);
        }
    }
    
    return count;
}

// !!!: /////////////////////       Coin Change     ///////////////////////
/* !!!: Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
 Example 1:
 Input:
 n = 4 , m = 3
 S[] = {1,2,3}
 Output: 4
 Explanation: Four Possible ways are:
 {1,1,1,1},{1,1,2},{2,2},{1,3}.
 
 Example 2:
 Input:
 n = 10 , m = 4
 S[] ={2,5,3,6}
 Output: 5
 Explanation: Five Possible ways are:
 {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
 */

// From: https://algorithms.tutorialhorizon.com/dynamic-programming-coin-change-problem/
// Objective: Given a set of coins and amount, Write an algorithm to find out how many ways we can make the change of the amount using the coins given.
// !!!: 40 iterations for 4 coins.
int coinChangeIterative1(vector<int> v, const int amount)
{
    int iterations = 0;
    int solution[v.size() + 1][amount+1];// = new int[v.size() + 1][amount + 1];//= new int[v.size() + 1][amount + 1];

    // if amount=0 then just return empty set to make the change
    for (int i = 0; i <= v.size(); i++) {
        solution[i][0] = 1;
    }

    // if no coins given, 0 ways to change the amount
    for (int i = 1; i <= amount; i++) {
        solution[0][i] = 0;
    }

    // now fill rest of the matrix.
    for (int i = 1; i <= v.size(); i++) {
        for (int j = 1; j <= amount; j++) {
            // check if the coin value is less than the amount needed
            if (v[i - 1] <= j) {
                // reduce the amount by coin value and
                // use the subproblem solution (amount-v[i]) and
                // add the solution from the top to it
                solution[i][j] = solution[i - 1][j]
                               + solution[i] [j - v[i - 1]];
            } else {
                // just copy the value from the top
                solution[i][j] = solution[i - 1][j];
            }
            iterations++;
        }
    }
    
    return solution[v.size()][amount];
}

// From Geeksforgeeks: !!!: Simpler. 40 iterations for 4 coins.
int coinChangeIterative2( int coins[], int numberOfCoins, int amount )
{
    int iterations = 0;
    int i, j, x, y;
 
    // We need n+1 rows as the table is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[amount + 1][numberOfCoins];
     
    // Fill the entries for 0
    // value case (n = 0)
    for (i = 0; i < numberOfCoins; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < amount + 1; i++)
    {
        for (j = 0; j < numberOfCoins; j++)
        {
            // Count of solutions including S[j]
            x = (i-coins[j] >= 0) ? table[i - coins[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
            iterations++;
        }
    }
    
    return table[amount][numberOfCoins - 1];
}
 
// From Geeksforgeeks. !!!: The Best. Much Simpler and more Effiecent. 28 iterations for 4 coins.
int coinChangeIterative3( int coins[], int numberOfCoins, int amount )
{
    int iterations = 0;
    // table[i] will be storing the number of solutions for value i. We need amount+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[amount+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<numberOfCoins; i++) {
        for(int coin=coins[i]; coin<=amount; coin++) {
            table[coin] += table[coin-coins[i]];
            iterations++;
        }
    }
    
    return table[amount];
}

// !!!: From Geeksforgeeks. Returns the count of ways we can. Sum S[0...M-1] coins to get sum N
int coinChangeRecursive1(int coins[], int numberOfCoins, int amount)
{
    int iterations = 0;
    // 1. If n is 0 then there is 1 solution (do not include any coin)
    if (amount == 0) {
        cout << " √√ Solution exist. " << "Coins = " << numberOfCoins << ", Amount = " << amount << endl;
        //cout << "Count1 = " << count1 << ", Count2 = " << count2 << endl;
        return 1;
    }
    
    // 2. If amount is less than 0 then no solution exist
    if (amount < 0) {
        cout << " Amount = " << amount << ", is less than 0. NO solution exists" << endl;
        return 0;
    }
 
    // 3. If there are no coins and amount is greater than 0, then no solution exist
    if (numberOfCoins == 0 && amount > 0) {    // Sindex <= 0 && amount >= 1
        cout << " No solution exist. Coin = " << numberOfCoins << ", Amount = " << amount << " is greater than 0\n\n";
        //cout << "Count1 = " << count1 << ", Count2 = " << count2 << endl;
        return 0;
    }
 
    iterations++;
    // Count is sum of solutions (i) including coins[m-1] (ii) excluding coins[m-1]
    // Go DOWN (LEFT)
    cout << " Left  Coin = " << coins[numberOfCoins-1] << ", Amount = " << amount << endl;;
    int leftCount = coinChangeRecursive1(coins, numberOfCoins - 1, amount);
    cout << "leftCount = " << leftCount << endl;
    
    iterations++;
    // Go RIGHT
    cout << " Right Coin = " << coins[numberOfCoins-1] << ", Amount = " << amount - coins[numberOfCoins-1] << endl;;
    int rightCount = coinChangeRecursive1(coins, numberOfCoins, amount - coins[numberOfCoins-1]);
    cout << "rightCount = " << rightCount << endl;
    cout << "leftCount + rightCount = " << leftCount + rightCount;
    cout << endl;

    return  leftCount + rightCount;
}

// From: https://algorithms.tutorialhorizon.com/dynamic-programming-coin-change-problem/
// Must use vector<int v and Must start with i=0
int coinChangeRecursive2(vector<int> coins, int index, int amount)
{
    if (amount == 0) {
        return 1;
    }
    
    if (amount < 0) {
        return 0;
    }
    
    // Means coins over and n>0 so no solution
    if(index == coins.size() && amount > 0) {
        return 0;
    }
    
    return coinChangeRecursive2(coins, index, amount - coins[index]) +
           coinChangeRecursive2(coins, index + 1, amount);
}


// !!!: ////////////////       Minimum Coin Change     ///////////////////////
int minCoinRecursive(int coin[], int size, int amount)
{
    if(amount == 0)
        return 0;
    
    int minCount = INT_MAX;
    
    for(int i = 0; i < size; i++)
    {
        if(amount >= coin[i])
        {
            int currCount = minCoinRecursive(coin, size, amount - coin[i]);
            
            if(currCount != INT_MAX && ((currCount + 1) < minCount)) {
                minCount = currCount + 1;
            }
        }
    }
    
    if(minCount == INT_MAX)
        return -1;
    else
        return minCount;
}

int minCoinNonRecursive(int coin[], int m, int amount)
{
    if(amount == 0)
        return 0;
    
    int Change[amount + 1];
    Change[0] = 0;
    for(int i = 1; i <= amount; i = i + 1) {
        Change[i] = INT_MAX;
    }
    
    for(int i = 1; i <= amount; i = i + 1)
    {
       for(int j = 0; j < m; j = j +1)
       {
           if(coin[j] <= i)
           {
               int currCount = Change[i - coin[j]];
               if(currCount != INT_MAX && currCount + 1 < Change[i])
                   Change[i] = currCount + 1;
           }
       }
    }
    
    if(Change[0] == INT_MAX)    // !!!: Should be => if(Change[amount] == INT_MAX)
        return -1;
    else
        return Change[0];  // !!!: Should be => Change[amount]
}

long long int myCoinChange(vector<int> coins, int amount)
{
    //          2 5 3 6
    long long int result = 0;
    for(int x=0; x< coins.size(); x++) {
        int amount0 = amount;
        
    for(int i=0; i < coins.size(); i++) {           // i = 0
        int amount1 = amount - coins[i]*(i+1);                 // 10 - 2 = 8
        if(amount1 == 0) {
            result++;
        }
        if(amount1 < 0) {
            break;
        }
        for(int j=i+1; j<coins.size(); j++) {     // j = 1
            int amount2 = amount1 - coins[j];             // 8 - 5 = 3
            if(amount2 == 0) {
                result++;
            }
            if(amount2 < 0) {
                break;
            }
            
            for(int k=j+1; k<coins.size(); k++) { // k = 2
                int amount3 = amount2 - coins[k];         // 3 - 3 = 0
                if(amount3 == 0) {
                    result++;
                }
                if(amount3 < 0) {
                    break;
                }

                for(int l=k+1; l<coins.size(); l++) { // l = 3
                    int amount4 = amount3 - coins[l]; // 3 - 3 = 0
                    if(amount4 == 0) {
                        result++;
                    }
                    if(amount4 < 0) {
                        break;
                    }
                }
            }
        }
    }
    }
    return result;
/*
 int j = 0, k = 1;
 while(true) {
     int curCoin = coins[i] * k; // 2x1=1
     amount = amount - curCoin;  // 8
     if(amount == 0) {
         // Exact Change FOUND
     }
     if(curCoin < amount) {
         ;
         result++;
     }
 */
    // i, j, k, l
    // S[]  = {2,5,3,6}
    // !!!:  2
    // 10-2 = 8                             i
           // 8-2 = 6                       j
                 // 6-2 = 4                 k
                       // 4-2 = 2           l
                             // 2-2= 0      ===> {2,2,2,2,2}
                       // 4-5 = -1          XXX: Negative
                       // 4-3 = 1           XXX: 1 is less than smallest coin in s[]: = 1<2
                             // 1-2 = -1    XXX
                             // 1-5 = -4    XXX
                             // 1-3 = -2    XXX
                             // 1-6 = -5    XXX
                             // 4-6 = -2    XXX
                       // 4-6 = -2          XXX
                 // 6-5 = 1                 XXX: 1 is less than smallest coin in s[]: = 1<2
                       // 1-2 = -1          XXX
                       // 1-5 = -4          XXX
                       // 1-3 = -2          XXX
                       // 1-6 = -7          XXX
                 // 6-3 = 3
                       // 3-2 = 1           XXX: 1 is less than smallest coin in s[]: = 1<2
                             // 1-2 = -1    XXX
                             // 1-5 = -4    XXX
                             // 1-3 = -2    XXX
                             // 1-6 = -5    XXX
                       // 3-5 = -2          XXX
                       // 3-3 = 0           ===> {2,2,3,3}
                       // 3-6 = -3          XXX
                 // 6-6 = 0                 ===> {2,2,6}
           // 8-5 = 3
                 // 3-2 = -1                XXX
                 // 3-5 = -2                XXX
                 // 3-3 = 0                 ===> {2,5,3}
                 // 3-6 = -3                XXX
           // 8-3 = 5
                 // 5-2 = 3                 ===> {2,3,2,3}
                       // 3-3 = 0
                 // 5-5 = 0                 ===> {2,3,5}
                 // 5-3 = 2
                       // 2-2 =0            ===> {2,3,3,2}
                 // 5-6 = -1                XXX
    
           // 8-6 = 2
                 // 2-2 = 0                 ===> {2,6,2}
    
//***********************************************************
    // !!!:  5
    // 10-5 = 5
           // 5-2 = 3
                 // 3-2 = 1            XXX
                 // 3-5 = -2           XXX
                 // 3-3 = 0            ===> {5,2,3}
                 // 3-6 = -3           XXX
           // 5-5 = 0                  ===> {5,5}
           // 5-3 = 2
                 // 2-2 = 0            ===> {5,3,2}
                 // 2-5 = -3           XXX
                 // 2-3 = -1           XXX
                 // 2-6 = -4           XXX
           // 5-6 = -1                 XXX
    
//***********************************************************
        // !!!:  3
        // 10-3 = 7
               // 7-2 = 5
                     // 5-2 = 3
                           // 3-3 = 0     ===> {3,2,2,3}
               // 7-5 = 2
                     // 2-2 = 0           ===> {3,5,2}
                     // 2-5 = -3          XXX
                     // 2-3 = -1          XXX
                     // 2-6 = -3          XXX
               // 7-3 = 4
                     // 4-2 = 2
                           // 2-2 = 0    ===> {3,3,2}
                     // 4-5 = -1         XXX
                     // 4-3 = 1          XXX: 1 is less than smallest coin in s[]: = 1<2
                     // 4-6= -2          XXX
               // 7-6 = 1                XXX: 1 is less than smallest coin in s[]: = 1<2
                     // 1-2 = -1         XXX
                     // 1-5 = -4         XXX
                     // 1-3 = -2         XXX
                     // 1-6 = -5         XXX
  
    //***********************************************************
            // !!!:  6
            // 10-6 = 4
                   // 4-2 = 2
                         // 2-2 = 0      ===> {6,2,2}
                         // 2-5 = -3     XXX
                         // 2-3 = -1     XXX
                         // 2-6 = -4     XXX

                   // 4-5 = -1           XXX
                   // 4-3 = 1
                         // 1-2 = -1          XXX
                         // 1-5 = -4          XXX
                         // 1-3 = -2          XXX
                         // 1-6 = -5          XXX
                   // 4-6 = -2                XXX
 
    
    // Another approch
//-----------------------------------------------------------
    
    // 10-2 = 8 => {2,2,2,2,2}, {2,2,3,3}, {2,5,3}, {2,3,5}, {2,2,6}, {2,6,2}
    
    // 10-5 = 5 => {5,2,3}, {5,3,2}, {5,5}
    
    // 10-3 = 7 => {3,2,5}, {3,5,2}
    
    // 10-6 = 4 => {6,2,2}

    // S[]  = {2,5,3,6}
}

// !!!: ////////////////////////      Print Stars      ////////////////////////////
// 4 stars ****. In this solution, we have 2 cout statement.
/*
    ****
    ****
    ***
    **
    *
*/
// 4 stars ****. In this solution, we have 2 cout statement
void printStars_1(int stars)
{
    static string starString = "";   // !!!: static eliminates passing starString as a parameter
    
    if (stars == 0) {
        cout << "\t\t\t" << starString << endl;  // !!!: Print max stars at the end: ****
        return;
    }
    
    // !!!: Done out of order. Should add one star first.
    starString += '*';              // !!!: First , Add one star at a time to starString, on the way down.
    string prevString = starString; // !!!: Second,  Save current, starString, since it is static
    printStars_1(stars - 1);
    cout << "\t\t\t" << prevString << endl;     // !!!: Print remaining stars here, on the way up: ***, **, *
}

/*
     ****
     ***
     **
     *
*/
// !!!: Best, using static starString eliminates passing string as a parameter, therefore, uses LESS parameters.
// !!!: In this solution, we have just 1 cout statement. Little bit more effiecient.
void printStars_2(int stars)
{
    static string starString = "";      // !!!: static eliminates passing starString as a parameter
    
    if(stars != 0) {
        starString += '*';              // !!!: First , Add one star at a time, on the way down.
        string prevString = starString; // !!!: Second, Save current, starString, since it is static
        printStars_2(stars - 1);
        cout << "\t\t\t" << prevString << endl;     // Print all stars here, on the way up, NO STACK: !!!: ****, ***, **, *
    }
}

// !!!: In this solution, we have just 1 cout statement. Little bit more effiecient.
void printStars_3(int stars)
{
    static string starString = "";
    
    if(stars == 0){
        return;                      // !!!: NOTICE: Do not print string at end
    }
    
    starString += '*';              // !!!: Add one star at a time, on the way down.
    string prevString = starString; // !!!: Must remeber starString, since it is static
    printStars_3(stars - 1);
    cout << "\t\t\t" << prevString << endl;     // !!!: Print remaining stars here, on the way up, NO STACK: ***, **, *
}

// !!!: Using 1 more parameter
void printStars_4(int stars, string starString)
{
    if(stars == 0){
        return;                     // !!!: Do not print string at end
    }
    
    starString += '*';             // !!!: Add one star at a time, on the way down, push on stack
    printStars_4(stars - 1, starString);
    cout << "\t\t\t" << starString << endl;    // !!!: Print all stars here, on the way up, pop off stack: ****, ***, **, *
}

void printStars_5(int stars, string starString)
{
    if(stars != 0){
        starString += '*';
        printStars_4(stars - 1, starString);
        cout << "\t\t\t" << starString << endl;
    }
}


void printStars_6(int stars)
{
    static string starString;
    
    if(stars != 0){
        starString += '*';                          // !!!: Add one star at a time, on the way down.
        string prevString = starString;             // !!!: Save starString, since it is static
        cout << "\t\t\t" << starString << endl;     // !!!: Print all stars here, on the way down: *, **, ***, ****
        printStars_6(stars - 1);
        cout << "\t\t\t" << prevString << endl;     // !!!: Print all stars here, on the way up  : ****, ***, **, *
    }
}

void printStars_7(int stars)
{
    static string starString = "";           
    
    if(stars != 0){
        // First, Build and Print stars
        starString = "";
        for(int i=0; i<stars; i++) {
            starString += "*";
        }
        cout << "\t\t\t" << starString << endl;     // Print stars here, on the way down, NO STACK: !!!: ****, ***, **, *
        
        string prevString = starString;             // !!!: Must remeber starString, since it is static

        printStars_7(stars - 1);

        cout << "\t\t\t" << prevString << endl;     // Print stars here, on the way up, NO STACK: !!!: ****, ***, **, *
        starString.resize(stars-1);                 // Remove one star from string on the way up
    }
}

void printStars_8(int stars, string starString)
{
    if(stars != 0){
        // First, Build and Print stars
        starString = "";                // must be intialized before using it
        for(int i=0; i<stars; i++) {
            starString += "*";
        }
        cout << "\t\t\t" << starString << endl;     // Print stars here, on the way down, NO STACK: !!!: ****, ***, **, *
        
        starString.resize(stars-1);     // Remove one star from string on the way down and Print it
        printStars_8(stars - 1, starString);

        starString += "*";
        cout << "\t\t\t" << starString << endl;     // Print stars here, on the way up, NO STACK: !!!: ****, ***, **, *
    }
}

/*     *
      **
     ***
    ****
*/
// O(ROWS * COLS). since, ROWS = COLS = stars, O(stars^2). O(4^2) = 16
void printStarsNonRecursive_1(int stars)
{
    unsigned int ROWS;
    unsigned int COLS = ROWS = stars;
    
    for(int row=0; row < ROWS; ++row)  // why start from zero?
    {
        // first, print spaces for each row
        for(int col=row; col < COLS-1; ++col)
        {
            cout << " ";
        }

        // second, print stars for each row
        for(int col=0; col <= row; ++col)
        {
            cout << "*";
        }
        
        // Print new line
        printf("\n");
    }
}

// similar to the above function printStarsNonRecursive_1()
// more efficient, since it prints a whole row at once. O(ROWS)
void printStarsNonRecursive_11(int stars)
{
    unsigned int ROWS = stars;
    string str( stars, ' ' ); // "    "
    
    for(int row=ROWS-1; row >= 0; --row)  // why start from zero?
    {
        // Print stars
        str[row] = '*';
        cout << str << endl;
    }
}

void printStarsNonRecursive_2(int stars)
{
    int row = 0, col = 0;
    unsigned int ROWS = stars;

    for(int row=0; row < ROWS; ++row)
    {
        // Print spaces for each row
        // col = f(row) = space(row) = ROWS - row - 1
        //                           = (ROWS - 1) - row
        //                           = 4-1 - row
        //                       col < 3 - row, for row = 0,1,2,3
        for( col=0; col < ROWS-row-1; ++col) {    // (col=1; col < ROWS-row; ++col)
            printf(" ");
        }
        
        // Print stars for rest of columns
        for(; col < ROWS; ++col) {
            printf("*");
        }
        
        // Print new line
        printf("\n");
    }
}

// My solution
void printStarsNonRecursive_3(int stars)
{
    int row = 0, col = 0;
    unsigned int ROWS = stars;
    unsigned int COLS = stars;

    for(int row=0; row < ROWS; ++row) {
        for(int col=0; col < COLS; ++col) {
            if( col < ROWS-row-1 ) {
                printf(" ");
            }
            else {
                printf("*");
            }
        }

        printf("\n");
    }
}


int recursiveFun1(int n)
{
    if (n == 0)
        return 1;
    else
        return 1 + recursiveFun1(n-1);
}

int recursiveFun2(int n)
{
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun2(n-5);
}

int recursiveFun3(int n)
{
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun3(n/5);
}

void recursiveFun4(int n, int m, int o)
{
    if (n <= 0)
    {
        printf("%d, %d\n",m, o);
    }
    else
    {
        recursiveFun4(n-1, m+1, o);
        recursiveFun4(n-1, m, o+1);
    }
}

int recursiveFun5(int n)
{
    for (int i = 0; i < n; i += 2) {
        // do something
    }

    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun5(n-5);
}

