//
//  NumberConversions.hpp
//  Practice1
//
//  Created by taher benisa on 11/14/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#ifndef NumberConversions_hpp
#define NumberConversions_hpp

#include <stdio.h>
#include "string"
#include <iostream>

int    Convert_HexToDecimal(std::string);
std::string Convert_DecimalToHex(unsigned int);
std::string DecimalToBinary_mine(int decimal);
std::string DecimalToBinary_geeks(int decimal);

void   print_DecimalToBinary(int);
int    Convert_BinaryToDecimal(std::string);
// Needs work
std::string intToRoman(int num);
std::string Convert_Number_To_Excell_Headers(int );

int atoi(std::string s);

#endif /* NumberConversions_hpp */
