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
int Fibonacci_Iteratively(int n);

std::vector<std::string> letterCombinations(std::string digits);

void           Print_keypadCombinations_MySolution(std::vector<int> phoneNum);
std::vector<std::string> Print_keypadCombinations_GeeksSolution(std::vector<int> number);

long long int myCoinChange(std::vector<int> coins, int cents);
int minCoinRecursive(int coin[], int m, int amount);
int minCoinNonRecursive(int coin[], int m, int K);

int coinChangeIterative1(std::vector<int> coins, const int amount);
int coinChangeIterative2( int coins[], int numberOfCoins, int amount );
int coinChangeIterative3( int coins[], int numberOfCoins, int amount );

int coinChangeRecursive1(int coins[], int numberOfCoins, int amount);
int coinChangeRecursive2(std::vector<int> coins, int i, int amount); // Must use vector<int v and start with i=0

long long int myCoinChange(std::vector<int> coins, int amount);

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

int recursiveFun1(int n);
int recursiveFun2(int n);
int recursiveFun3(int n);
void recursiveFun4(int n, int m, int o);
int recursiveFun5(int n);


#endif /* Permutaions_hpp */
