//
//  BitManipulations.hpp
//  Practice1
//
//  Created by taher benisa on 11/13/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#ifndef BitManipulations_hpp
#define BitManipulations_hpp

#include <stdio.h>
#include "string"
#include <iostream>
#include <vector>

class BitManipulations
{
public:
    int computeXOR1(int number);
    int computeXOR2(int n);

    int CountSetBits(int n);

    int Update_Bits_1(int n, int m, int beginPos, int endPos);
    int Update_Bits_2(int n, int m, int beginPos, int endPos);

    // from Ritchi book
    unsigned int getBits2(unsigned int x, int p, int n);
    // Mine
    unsigned int getBits1(unsigned int x, int p, int n);

    // Generates 01010101010, See PrintNumHavingAltBitPattern1(int n)
    unsigned int setEvenBits_mine(unsigned int n);
    // Generates 10101010101, See PrintNumHavingAltBitPattern1(int n)
    unsigned int SetOddBits_geek(unsigned int n);
    unsigned int SetOddBits_mine(unsigned int n);

    unsigned char Clear_Bits_From_MSB_To_ithBit(unsigned char, int pos);

    // Use this function to do both SetEvenBits and SetEvenBits()
    // Call SetEvenBits() to set even bits and,
    // Call SetOddBits() to set odd bits or,
    // Call ~SetEvenBits() to set odd bits
    std::vector<int> generateAlternateBits1(int n); // Mine
    void        generateAlternateBits2(int n);

    bool Does_Interger_Have_Alternating_Bits_1(unsigned int n);
    bool Does_Interger_Have_Alternating_Bits_2(unsigned int n);

    int inspect_bits(unsigned int number);

    bool BigIndianLittleIndian(void);
    uint32_t ChangeEndianness_1(uint32_t u32Value);
    uint32_t ChangeEndianness_2(uint32_t u32Value);

    bool PowerOfTwo(unsigned int n);

    long multiplyWithShift(short x, short y);
    long int DivideWithoutUsingDivision_1(int x, int y);
    int      DivideWithoutUsingDivision_2(int a, int b) ;

    int printDuplicatesInBigDataSet(unsigned int* a, int size);

    void OnesLeftZerosRight(int* array, int size);

    unsigned int ReverseBits1(unsigned int n);
    void ReverseBits2(unsigned int &n);
    unsigned int ReverseBits3(unsigned int n);

    int  RotateBitsLeft_1(int n, int shiftleft);
    void RotateBitsLeft_2(int &n, int shiftleft);
    void rotateBitsLeft_3(unsigned int &n, int shiftleft);

    // Swap of bits, niblles, bytes
    std::byte Swap_EvenOdd_Bits_Byte(std::byte x);
    unsigned int Swap_2Bits_Nibble(unsigned int number);
    unsigned int Swap_Bytes_In_Integer(unsigned int number);
    unsigned int Swap_Halfword_In_Integer(unsigned int number);
    void SwapNumbers_NotUsingtemp(int &x, int &y);
    unsigned char Swap_Nibbles_In_Byte(unsigned char x);
    unsigned int Swap_Nibbles_In_Integer(unsigned int x);
    unsigned int Swap_EvenOdd_Bits_Integer(unsigned int n);
    int SwapRangeOfBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n);
    unsigned char swap2Bits(unsigned char data, int bit1, int bit2);
    unsigned char swap2BitsMySolution(unsigned char data, unsigned char bit1, unsigned char bit2);


    int Compute_Sign_of_Integer_1(int number);
    int Compute_Sign_of_Integer_2(int number);
    bool CheckOppositeSign(int a, int b);

    int is_number_odd_or_even( int number );

    int is_char_lower_or_upper( char character );

    // similar functions:
    int longestSubsequenceOf1s_afterFlipping_1bit_util( int integer );
    int longestSubsequenceOf1s_afterFlipping_1bit( int integer );
    int flipBit_to_Win( int integer );
    int longestSubstringOf1s_afterRemoving_1bit_1( std::string s );
    int longestSubstringOf1s_afterRemoving_1bit_2( std::string str );

    // Binary strings stuff
    int  CountNegativePulses( std::string str );
    int  CountPositivePulses( std::string str );
    std::vector<int>  PulsesEdges( std::string str );
    void DrawPattern( std::string str );
    
    int EqualLengths_of_Zeros_Ones_1( std::vector<int>& nums );
    int findEqualLengths_of_Zeros_Ones_2( std::vector<int> &nums );

    int trailingZeros_1( int number );
    int trailingZeros_2( int number );
    int leadingZeros_1 ( int number );
    
    int Equal_Sum_and_XOR ( int number );
    
    int evenbittogglenumber( int number );
};

#endif /* BitManipulations_hpp */


