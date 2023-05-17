//
//  StringStuff.hpp
//  Practice1
//
//  Created by taher benisa on 11/15/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#ifndef StringStuff_hpp
#define StringStuff_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include "vector"
#include <algorithm>
#include <set>

bool Anagrams1(std::string str1, std::string str2);
bool Anagrams2(std::string str1, std::string str2);

std::string longestPalindrome(std::string s);

bool isIntegerPalindrome_2(int n);
bool isIntegerPalindrome_1(int n);

bool isStringPalindrome(std::string str);
bool isStringPermutationOfPalindrome1(std::string s);

bool isUniqueChars(std::string str);

void Remove_Str2_Letters_From_Str1_1(std::string& str1, std::string str2);
void Remove_Str2_Letters_From_Str1_2(std::string& str1, std::string str2);

void removeSubstrs(std::string &s, const std::string &p);

void ReverseStr(char* s);

bool StrInStr(std::string str1, std::string str2);
bool StrInStr(char* a, char* b);

bool strCmp(char* s1, char* s2);

int wordcount(std::string str);
void reverseWords(std::string& words);
void translateABtoC(std::string &s);

std::string compressString(std::string str);

std::string longestSubstring_Without_Repeating_Letter(std::string s);

std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned_words);

// Move to CommonStuff
int  sumOfDigits(int x);


std::string addTwoStrings1(std::string s1, std::string s2);
std::string addTwoStrings2(std::string s1, std::string s2);

std::string multiplyTwoStrings(std::string num1, std::string num2);

std::vector<std::string> commonChars(std::vector<std::string>& words);

std::vector<std::string> unique_names(std::vector<std::string> names1, std::vector<std::string> names2);

char digit_to_hex_char( int digit);


#endif /* StringStuff_hpp */
