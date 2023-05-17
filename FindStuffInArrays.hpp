//
//  FindStuffInArrays.hpp
//  Practice1
//
//  Created by taher benisa on 11/15/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#ifndef FindStuffInArrays_hpp
#define FindStuffInArrays_hpp

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <array>
#include <algorithm>

#include "Vectors.hpp"

//using namespace std;

// Find min
int findMin_inSortedRotatedArray_2(std::vector<int> a);
int findMin_inSortedRotatedArray_1(std::vector<int> a);

int findNumberOfRotations_inSortedRotatedArray(std::vector<int> numbers);

// Find number in sorted rotated array
int findNumber_inSortedRotatedArray_1(std::vector<int> a, int target);
int findNumber_inSortedRotated_Array_2(std::vector<int>& a, int target);

int Find_MissingNumber_In_Incremental_SortedArray(std::vector<int> array);
// Array not sorted
int findMissingNumber_inIncrementalUnsortedArray(std::vector<int>& v);

// Find missing number in unsorted array,
int Find_FirstMissingPositive_In_UnsortedArray_1(std::vector<int>& nums);   // MY SOLUTION
int Find_FirstMissingPositive_In_UnsortedArray_2(std::vector<int>& nums);   // Less code from Leet
int Find_FirstMissingPositive_In_UnsortedArray_3(std::vector<int>& nums);   // suposedly fastest from Leet

char Find_FirstNonRepeatingChar(std::string s);

std::vector<int> Find_First2NonRepeatingNumbers_1(std::vector<int> numbers);
std::vector<int> Find_First2NonRepeatingNumbers_2(std::vector<int> numsbers);

char Find_MostRepeated_Letter_ExtraSpace(std::string );
char Find_MostRepeated_Letter_N0_ExtraSpace(std::string );

// Auxulary function
int Search_Binary_1(std::vector<int> a, int left, int right, int value);
int Search_Binary_2(int numbers[], int n, int k);

// Function to find the `k` closest elements to `x` in a sorted integer array `arr`
//void findKClosestElements(int arr[], int x, int k, int n);
std::vector<int> findClosest_kNumbers_toTarget1(const std::vector<int>& array, int numberOfElements, int target);
std::vector<int> Find_ClosestElementsToTarget2(const std::vector<int>& array, const int numberOfElements, int target);
std::vector<int> Find_ClosestElementsToTarget3(const std::vector<int>& array, const int numberOfElements, int target);
std::vector<int> Find_ClosestElementsToTarget_4(std::vector<int>& array, int Kelements, int target);

std::vector<int> findOnePair_withSum_closestToZero(std::vector<int> numbers);

std::vector<int> findOnePair_withGiven_Sum(std::vector<int>& nums, int target);

int  Find_Equal_Sum(std::vector<int>);
int  findEquilibriumPoint_1(std::vector<int> array);
int  findEquilibriumPoint_2(std::vector<int> array);
void findEquilibriumIndex_Optomized(int A[], int n);

// Distance to target from start
int Find_MinDistance(std::vector<int>& nums, int target, int start);

int Count_Students(std::vector<int>& students, std::vector<int>& sandwiches);

int Find_MaxForm(std::vector<std::string>& strs, int m, int n);

std::vector<int> Sort_Array_By_Parity(std::vector<int>& nums);

double Find_Median_In_SortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) ;

int Find_Where_TheyMeet_On_Circle(int N, int k1Steps, int k2Steps);

int Remove_Duplicates_ExtraSpace(int* a, int size);;
void Remove_Duplicates_NoExtraSpace(std::string& str);

void SelectionSort(int* array, int size);
void SelctionSort_Recursively(int* array, int size);

long long int NumberOf2sInRange(long long int number);

std::vector<int> Merge2SortedArrays_1(std::vector<int> a, std::vector<int> b);
std::vector<int> Merge2SortedArrays_2(std::vector<int> &v1, std::vector<int> v2);

std::vector<int> Largest_K_Numbers(std::vector<int> a, int k);
std::vector<int> Smallest_K_Numbers_1(std::vector<int> a, int k);
std::vector<int> Smallest_K_Numbers_2(std::vector<int> a, int k);

int Reverse_Number_1(int n);
int Reverse_Number_2(int n);
int Reverse_Number_3(int n);
int Reverse_Number_MyLeetCode(int n);
int printReverseLongNumber(void);
// LeetCode: the best solution in terms of execution time. Should return long long
long long ReverseNumber_LeetCode(int n);

//find the smallest K-digit number divisible by X
int findSmallestKdigitNumberDivisibleByX_1(int number, int Smallest_K_digit);
int findSmallestKdigitNumberDivisibleByX_2(int number, int Smallest_K_digit);

std::vector<int> flattenedMatrix(std::vector<int> matrix, int ROWS, int COLS);


std::vector<int> targetSum_Subarray(std::vector<int> numbers, long long targetSum);

// geeks, returns max sum
int              maxSum_subArray_geeks(const std::vector<int> array);
// wiki, returns max sum
int              maxSum_subArray_wiki (std::vector<int> array);
// mine, returns max sum, start and end indices
std::vector<int> maxSum_subArray_mine (std::vector<int> array);

bool isArrayContiguous_DuplicatesAllowed1(std::vector<int> numbers);
bool IsArrayaContiguous_DuplicatesAllowed2(std::vector<int> v);

void printAllSubarrays_1(std::vector<int> numbers);
void printAllSubarrays_2(std::vector<int> a);
void PrintSubsets(std::vector<int> numbers);

int Remove_Duplicates_From_SoretedArray(std::vector<int>& nums);

std::vector<int> findLongest_consecutiveNumbers(std::vector<int> nums);

void Rotate_Matrix_90DegCC(std::vector<std::vector<int>>& array);
void Rotate_MatrixLeft(int** a, int M, int N, int k);

void Rotate_Array_Right_1(std::vector<int>& array, int rotationRight);
void Rotate_Array_Right_2(std::vector<int>& array, int rotationRight);
void Rotate_Array_Right_3(std::vector<int>& array, int rotationRight);

int Raise_Number_To_Power_Recursive(unsigned int num, unsigned int power);
int Raise_Number_To_Power_Iterative(unsigned int num, unsigned int power);
int Raise_Number_To_Power3(unsigned int num, unsigned int power);

bool Are_Arrays_Equal_1(std::vector<int> A, std::vector<int> B, const size_t N);
// Using array
bool Are_Arrays_Equal_2(std::vector<int> A, std::vector<int> B, const size_t N);

// Notice decleration of function from the above one:
bool Are_Arrays_Equal_CPP(std::array<int, 5> A, std::array<int, 5> B);

int Find_First_K_Occurances_of_Element(std::vector<int>, int k);

std::vector<std::vector<int>> findPairs_withGiven_Difference( const std::vector<int> a, int diff);

void move_zeros_to_left(std::vector<int>& a);

std::vector<int> ZeroOneTwo3(std::vector<int> v) ;
std::string ZeroOneTwo4(std::string s);   // The best

void Rearrange_Array_Max_Min_Alternatively_1(std::vector<int>& a);
void Rearrange_Array_Max_Min_Alternatively_2(std::vector<int>& a);

std::vector<int> Rearrange_Array_Pos_Neg_Alternatively(std::vector<int>& a);

std::vector<int> sortArrayByParityII(std::vector<int>& a);

std::vector<int> pivotArray_1(std::vector<int>& a, int pivot);
std::vector<int> pivotArray_2(std::vector<int>& a, int pivot);

std::vector<int> intersection_2Arrays(std::vector<int> a1, std::vector<int> a2);

int leastCommonNumber(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3);

int minIncrements_to_uniqueArray_mine( std::vector<int>& a );
int minIncrements_to_uniqueArray_geek( std::vector<int>& a );

int findSumClosestToZero(std::vector<int> a);

bool Convert_to_Nondecreasing_Array_with_one_change_1( std::vector<int> a);
int  Convert_to_Nondecreasing_Array_with_one_change_2( std::vector<int> array );
int  totalSteps_to_Make_NonDecreasing_Array_1( std::vector<int>& a);
int totalSteps_to_Make_NonDecreasing_Array_2( std::vector<int>& a);

int countOdds_1(int low, int high);
int countOdds_2(int low, int high);
int countOdds_3(int low, int high);

bool isDivisible_byItsDigits( int num );

int monotoneIncreasingDigits( int number );

bool checkattendanceRecords(std::string s);

#endif /* FindStuffInArrays_hpp */
