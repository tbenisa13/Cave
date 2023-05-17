//
//  Common Stuff.hpp
//  Practice1
//
//  Created by Taher Benisa on 7/29/21.
//  Copyright © 2021 taher benisa. All rights reserved.
//

#ifndef Common_Stuff_hpp
#define Common_Stuff_hpp

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <list>
#include <stack>
#include <set>
#include <algorithm>
#include <vector>

int  maximizeMoney_robbingHouses(int N , int K);

int  trappingWater(std::vector<int>& height);

int  deleteValue(std::vector<int>& nums, int val);

char GetMaxOccuringChar_1(char* str);
char GetMaxOccuringChar_2(char* str);

int  getLastKthElement(std::list<int>, int kthToLast );

int  transitionPoint_SortedArray_1(std::vector<int> array);
int  transitionPoint_SortedArray_2(std::vector<int> array);

void create_pattern_1 (int rows, int columns);
void create_pattern_2 (int rows, int columns);
void create_pattern_Diagonally (int rows, int cols);
void create_pattern_Diagonally_Recursuvilly (int rows, int cols);

////////////////////////////////////        Number of Paths       /////////////////////////////////////
long long   numberOfPaths_recursively1(int m, int n);
// The foloowing 2 functions are used together
long long   numberOfPaths_recursively2(int m, int n);
long long   numberOfPathsMysolution(int M, int N);
int         numberOfPaths_iteratively1(int row, int col);
int         numberOfPathsRecursiveX(int row, int col, int paths[4][4]);
int         numberOfPaths_iteratively2(int row, int col);

void extractDigits( unsigned int num );

#endif /* Common_Stuff_hpp */
