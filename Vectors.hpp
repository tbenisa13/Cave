//
//  Vectors.hpp
//  Practice1
//
//  Created by Taher Benisa on 9/1/22.
//  Copyright © 2022 taher benisa. All rights reserved.
//

#ifndef Vectors_hpp
#define Vectors_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

// Print a vector
void printVector(std::vector<int>& nums);
void printVector(std::ostream& out, std::vector<int>& nums);
template<class T> void printVectorTemplate( std::vector<T>& nums );
template<class T> T GetMax (T a, T b);

// Print a vectorS
void printVectors(std::vector<std::vector<int>>& nums);

void VectorPractice(void);

void assigingVectors(std::vector<int>& a, std::vector<int>& b);


#endif /* Vectors_hpp */
