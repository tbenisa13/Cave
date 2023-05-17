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


void printVector(std::vector<int>& nums);
template<class T> void printVectorX(std::vector<T>& nums);

void printVector(std::ostream& out, std::vector<int>& nums);
void printVectors(std::vector<std::vector<int>>& nums);

void VectorPractice(void);

void assigingVectors(std::vector<int>& a, std::vector<int>& b);

#endif /* Vectors_hpp */
