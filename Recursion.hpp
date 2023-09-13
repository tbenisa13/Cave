//
//  Recursion.hpp
//  Practice1
//
//  Created by Taher Benisa on 7/30/23.
//  Copyright © 2023 taher benisa. All rights reserved.
//

#ifndef Recursion_hpp
#define Recursion_hpp

#include <stdio.h>

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <math.h>

class Recursion {
public:
    class Permutation {
    public:
        void Print_AllCombinations_OfPhonePadLetters_Iterative();
        void print_7digitTelephoneNumber_Iterative( std::vector<int> number );
        void keypadCombinations_Recursively1( std::vector<int> number );
        void keypadCombinations_Recursively_Utl1( std::vector<int> number, int curDigit );
        void Print_keypadCombinations_Recursively_2( std::vector<char> keypad[], std::vector<int> phoneNumber );
        void Print_keypadCombinations_Recursively_2_Utl( std::vector<char> keypad[], std::vector<int> phooneNumber, std::string result, int digitIndex, int size );
        void Print_keypadCombinations_Recursively_3( std::vector<int> phoneNumber );
        void printPermutation_Recursively2( std::vector<int>& a, int begin, int end );  // Recursive
        void printPermutation_Recursively1( std::string str, int left, int right );
        void Print_StringPermutation_Iteratively( std::string str );
        void printPermutation_Recursively_mine( std::string str, int row );
        void Print_keypadCombinations_MySolution( std::vector<int> phoneNum );

        std::vector<std::string> letterCombinations( std::string digits );
        
        std::vector<std::string> Print_keypadCombinations_GeeksSolution( std::vector<int> number );
    };
    
    class Factorial {
    public:
        int Factorial1(int n);
        int Factorial_Recursively(int n);
    };
    
    class Fibonacci {
    public:
        int Fibonacci_Recursively(int n);
        int Fibonacci_Recursively_Memoization_Utl( int n );
        int Fibonacci_Recursively_Memoization(int number, int memo[] );
        int Fibonacci_Iteratively(int n);
    };
    
    class Power {
    public:
        int  printPowersOf2( int n );
        bool isPowerOf2_recursive( int n );
        bool isPowerOf2_iterative( int n );
        int  power_recursive( int a, int b ) ;
        int  power_recursive1(unsigned int num, unsigned int power);
        int  power_Iterative(unsigned int num, unsigned int power);
        int  Raise_Number_To_Power3(unsigned int num, unsigned int power);
    };
    

// !!!: ////////////////    Minimum Coin Counts    //////////////////////////
    
    class Coins {
    public:
        int Minimum_Recursive( int coin[], int m, int amount );
        int Minimum_Iterative( int coin[], int m, int K      );
        
        int Change_Iterative1( std::vector<int> coins, const int amount);
        int Change_Iterative2( int coins[]           , int numberOfCoins, int amount );
        int Change_Iterative3( int coins[]           , int numberOfCoins, int amount );
        
        int Change_Recursive1( int coins[]           , int numberOfCoins, int amount);
        int Change_Recursive2( std::vector<int> coins, int i, int amount); // Must use vector<int v and start with i=0
        int Change_Recursive3( std::vector<int> coins,        int amount );
        
        long long int myChange( std::vector<int> coins,       int amount);
        // long long int myCoinChange(std::vector<int> coins, int cents);
    };
    
// !!!: ////////////////    Print Star Pattern    //////////////////////////
        
    class Stars {
    public:
        void printStars_Iterative1 (int stars);
        void printStars_Iterative11(int stars);
        void printStars_Iterative2 (int stars);
        void printStars_Iterative3 (int stars);
        
        void printStars_Recursive1(int stars);
        void printStars_Recursive2(int stars);
        void printStars_Recursive3(int stars);
        void printStars_Recursive4(int stars, std::string starString);
        void printStars_Recursive5(int stars, std::string starString);
        
        void printStars_Recursive6(int stars);
        void printStars_Recursive7(int stars);
        void printStars_Recursive8(int stars, std::string starString);
    };
    
    class Combinations {
    public:
        int countWays_recursively( int total_steps );
        int countWays_iteratively( int total_steps ) ;
        int countWays_recursively_memoization( int total_steps );
        int countWays_recursively_memoization_helper(int total_steps, std::vector<int>& dp);
        
        int CombinationsOf_3_5_10(int n);
    };
    

    int largestNumber_Recursive1(const int array[], int left, int right);
    int largestNumber_Recursive2( int array[], int left, int right );
    int largestNumber_Recursive3( std::vector<int> array );

    // have fun with recursion
    int  increment_recursive(int n);
    int  recurse( int& x, int c );
    int  fiveStep_Jumps(int n);
    int  which_bin_iterative(int n);
    int  which_bin_recursive_2(int n);
    void recursiveFun4(int n, int m, int o);
    int  recursiveFun5(int n);
    
    int myPartition( int* a, int len );

    void DFS( std::vector<std::vector<int>> grid);
    
    int GCD( int u, int v);
};

#endif /* Recursion_hpp */
