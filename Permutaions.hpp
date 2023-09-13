//
//  Permutaions.hpp
//  Practice1
//
//  Created by taher benisa on 12/20/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#ifndef Permutaions_hpp
#define Permutaions_hpp

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

class Permutations {
public: 
    int myPartition(int* a, int len);
    
    void Print_AllCombinationsOfPhonePadLetters_Iteratively();
    
    void print_7digitTelephoneNumber_Iteratively(std::vector<int> number);
    
    void keypadCombinations_Recursively1(std::vector<int> number);
    void keypadCombinations_Recursively_Utl1(std::vector<int> number, int curDigit);
    
    void Print_keypadCombinations_Recursively_2(std::vector<char> keypad[], std::vector<int> phoneNumber);
    void Print_keypadCombinations_Recursively_2_Utl(std::vector<char> keypad[], std::vector<int> phooneNumber, std::string result, int digitIndex, int size);
    
    void Print_keypadCombinations_Recursively_3(std::vector<int> phoneNumber);
    
    void printPermutation_Recursively2(std::vector<int>& a, int begin, int end);  // Recursive
    
    void printPermutation_Recursively1(std::string str, int left, int right);
    void Print_StringPermutation_Iteratively(std::string str);
    void printPermutation_Recursively_mine(std::string str, int row) ;
    
    int CombinationsOf_3_5_10(int n);
    
    int Factorial(int n);
    int Factorial_Recursively(int n);
    int Fibonacci_Recursively(int n);
    int Fibonacci_Recursively_Memoization_Utl( int n );
    int Fibonacci_Recursively_Memoization(int number, int memo[] );
    int Fibonacci_Iteratively(int n);
    
    int printPowersOf2( int n );
    bool isPowerOf2_recursive( int n );
    bool isPowerOf2_iterative( int n );
    int power_recursive( int a, int b ) ;
    int power_recursive1(unsigned int num, unsigned int power);
    int power_Iterative(unsigned int num, unsigned int power);
    int Raise_Number_To_Power3(unsigned int num, unsigned int power);
    
    std::vector<std::string> letterCombinations(std::string digits);
    
    void           Print_keypadCombinations_MySolution(std::vector<int> phoneNum);
    std::vector<std::string> Print_keypadCombinations_GeeksSolution(std::vector<int> number);

// !!!: ////////////////    Minimum Coin Counts    //////////////////////////
    
    int minCoin_Recursive(int coin[], int m, int amount);
    int minCoin_Iterative(int coin[], int m, int K);
    
    int coinChange_Iterative1(std::vector<int> coins, const int amount);
    int coinChange_Iterative2( int coins[], int numberOfCoins, int amount );
    int coinChange_Iterative3( int coins[], int numberOfCoins, int amount );
    
    int coinChange_Recursive1( int coins[], int numberOfCoins, int amount);
    int coinChange_Recursive2( std::vector<int> coins, int i, int amount); // Must use vector<int v and start with i=0
    int coinChange_Recursive3( std::vector<int> coins, int amount );
    
    long long int myCoinChange(std::vector<int> coins, int amount);
    // long long int myCoinChange(std::vector<int> coins, int cents);

// !!!: ////////////////    Print Star Pattern    //////////////////////////
        
    void printStarsNonRecursive_1(int stars);
    void printStarsNonRecursive_11(int stars);
    void printStarsNonRecursive_2(int stars);
    void printStarsNonRecursive_3(int stars);
    
    void printStars_1(int stars);
    void printStars_2(int stars);
    void printStars_3(int stars);
    void printStars_4(int stars, std::string starString);
    void printStars_5(int stars, std::string starString);
    
    void printStars_6(int stars);
    void printStars_7(int stars);
    void printStars_8(int stars, std::string starString);
    
    int Find_LargestNumberRecursively(const int array[], int left, int right);
    
    // have fun with recursion
    int  increment_recursive(int n);
    int  fiveStep_Jumps(int n);
    int  which_bin_iterative(int n);
    int  which_bin_recursive_2(int n);
    void recursiveFun4(int n, int m, int o);
    int  recursiveFun5(int n);
    
    int countWays_recursively( int total_steps );
    int countWays_iteratively( int total_steps ) ;
    int countWays_recursively_memoization( int total_steps );
    int countWays_recursively_memoization_helper(int total_steps, std::vector<int>& dp);
    
    int largestNumber_recursively1( int array[], int left, int right );
    int largestNumber_recursively2( std::vector<int> array );
    
    void DFS( std::vector<std::vector<int>> grid);
    
    int recurse( int& x, int c );
    
    int gcd( int u, int v);

};

#endif /* Permutaions_hpp */
