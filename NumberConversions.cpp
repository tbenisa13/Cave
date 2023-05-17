//
//  NumberConversions.cpp
//  Practice1
//
//  Created by taher benisa on 11/14/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "NumberConversions.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;

int Convert_HexToDecimal(string hexString)
{
    int dec = 0;
    // "157BA";
    for (char ch : hexString)
    {
        if (ch >= '0' && ch <= '9')
            dec = (dec * 16) + (ch - '0');
        else
            dec = (dec * 16) + (ch - 'A') + 10;    // if c='A', c - 'A' = 0. why 10?
    }
    
    return dec;
}

string Convert_DecimalToHex(unsigned int decimal)
{
    string hexString = "";
    
    /*if( decimal < 0) {
        decimal = 0xFFFFFFFF + decimal +1;
    }*/
    //unsigned int temp = static_cast<unsigned int>(decimal);
    int remainder = 0;
    
    do
    {
        remainder = decimal % 16;
        //remainder = abs(remainder);
        if (remainder >= 0 && remainder <= 9)
            hexString += char(remainder + '0');
        else
            hexString += char(remainder - 10 + 'A');
        
        decimal /= 16;    // Divide by 16
        //decimal = abs(decimal);
    } while( decimal > 0 );
    
    reverse(hexString.begin(), hexString.end());    // Reverse strinng
    
    return hexString;
}

// Print
void print_DecimalToBinary(int decimal) {
    int res = 0;
    int lastbit = 1 << ((sizeof(decimal) * 8) - 1);    // 1 << 31 = 0x800000000 -> 10000000...
    
    while( decimal != 0 ) {
        (decimal & lastbit)? cout << 1 : cout << 0;
        
        decimal <<= 1;
    }
}

// Convert
string DecimalToBinary_mine(int decimal)
{
    string binaryString = "";
    int lastbit = 1 << (WORD_BIT - 1);    // 1 << 31 = 0x800000000 -> 10000000...

    while( decimal != 0 ) {
        // !!!: Last bit goes to 1st char in binary string so you don't need to reverse it.
        binaryString += (decimal & lastbit)? '1' : '0';
        
        decimal <<= 1;
    }

    return binaryString;
}

// from geeks
string DecimalToBinary_geeks(int decimal)
{
    string binaryString = "";
    // array to store binary number
    int binaryNum[32] = {0};

    // counter for binary array
    int i = 0;
    while (decimal > 0) {

        // storing remainder in binary array
        // set ith bit to 1, if odd, or 0 if even
        binaryNum[i] = decimal % 2;
        binaryString += std::to_string( binaryNum[i] );

        decimal >>= 1;     // decimal = decimal / 2;
        i++;
    }

    return binaryString;
 }

int Convert_BinaryToDecimal(string binary)
{
    int res = 0;
    int size = static_cast<int>(binary.size());
    int i = 0;;
    
    while( i < size ) {
        res <<= 1;

        int bit = binary[i] - '0';
        if(bit & 1) {
            res |= 1;  // res += 1 would always work
        }
        
        i++;
    }
    
    return res;
}

string Convert_Number_To_Excell_Headers(int number)
{
    //              0 1 2 ...... 25 26 27 ....
    // Excel Index: 1 2 3 ...... 26 27 28 ....
    // Excell     : A B C ...... Z  AA AB ....
    // Subtract 1, because 1=A, 2=B...,and '%' and '/' usde 0 1 2 3... for indexing
    number--;
    string str = "";
    while(number >= 0) {
        str += number % 26 + 'A';
        number = number/26 - 1;
    }
    
    reverse( str.begin(), str.end() );
    return str;
}

int atoi(string s)
{
    int result = 0;
    int multiplier = 10;
    int sign = 1;
    
    for(char c : s) {
        if(c=='-')
            sign = -1;
        
        int digit = c - '0';
        
        if( digit >= 0 && digit <= 9) {
            result = (result * multiplier) + digit;
        }
    }
    
    return result * sign;
}

/* Needs work
 Symbol       Value
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 */
// 1 <= num <= 3999
string intToRoman(int num)
{
    // 58 = 50 + 5 + 1 + 1 + 1 = L + V + I + I + I = LVIII;
    if(num < 1 || num > 3999) { return "";}
    string str = "";
    
    int r = num % 50 ;
    if( r ){
        int r1 = num % 50 ;
        int w  = num / 50;
        int z  = num - r1;
        while( z > 0 ) {
            switch( z ) {
                case 50: {
                    str += "L";
                    z /= 10;
                    break;
                }
                case 10: {
                    str += "X";
                    z /= 5;
                    break;
                }
                case 5: {
                    str += "V";
                    z /= 5;
                    break;
                }
                case 1: {
                    str += "I";
                    z -= 1;
                    break;
                }
                defualt: {
                    break;
                }
            }
           // z -= 50;
        }
    }

    return str;
}

