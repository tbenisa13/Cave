//
//  StringStuff.cpp
//  Practice1
//
//  Created by taher benisa on 11/15/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "StringStuff.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::istream;
using std::ostream;

// Is Unique: Implement an algorithm to determine if a string has all
// unique characters. What if you cannot use additional data structures?
// My solution:
bool isUniqueChars (string str)
{
  unsigned int result = 0; // 32 bits to represent the ASCCI charecter set

  for (char c : str)
    {
      int i = c - 'a';
      int x = 1 << i;
      cout << std::dec << "i = " << i << std::hex << ", x = 0x" << x << endl;
      if ((result & 1 << i) != 0)
        {
          return false;
        }

      result |= 1 << i;
    }

  return true;
}

// Given 2 strings, write a method to decide if one is a permutaion of the
// other. Same char stirngs arranged differently Runtime: 23 ms, faster
// than 14.93% of C++ online submissions for Valid Anagram. Memory Usage: 7.3
// MB, less than 78.54% of C++ online submissions for Valid Anagram.
bool Anagrams1( string str1, string str2 )
{
  // Key: char, Value: int count
  map<char, int> map1;
  map<char, int> map2;

  for (char ch : str1)
    {
      map1[ch]++; // count of str1 char in map1
    }

  for (char ch : str2)
    {
      map2[ch]++; // count of str2 char in map2
    }

  for (char ch : str2)
    {
      if (map1[ch] != map2[ch])
        return false; // counts for ch in both maps are not equal
    }

  return true;
}

// More efficient
// Runtime: 10 ms, faster than 68.48% of C++ online submissions.
// Memory Usage: 7.4 MB, less than 46.83% of C++ online submissions
bool Anagrams2( string s1, string s2 )
{
    if ( s1.length () != s2.length () ) {
      return false;
    }

    // Key: char, Value: int count
    int str1_letter_count[128] = { 0 };

    for (char c : s1) {
      str1_letter_count[c]++;     // Count occurance of each letter in s1
    }

    for (char c : s2)
    {
      // !!!: Important update letter count first, then make comparison
      str1_letter_count[c]--; // Subtract 1 from count of each char in s2
      if (str1_letter_count[c] < 0)
        {
          return false;
        }
    }

    return true;
}

// 10.0 Worked first time
bool isStringPalindrome( string str )
{
    int left = 0;
    int right = static_cast<int>(str.size ()) - 1;

    while (left < right) {
        if (str[left++] != str[right--]) {
          return false;
        }
    }

    return true;
}

// Using Vector as an extra space. O( 2*(# of digits in n) )
bool isIntegerPalindrome_1( int integer )
{
    int left = 0;
    int right = 0;
    vector<int> array;

    // Decompose number to digits
    while (integer > 0) {
        array.push_back (integer % 10);
        integer /= 10;
        ++right;
    }

    --right;
    while (left < right) {
        if( array[left] != array[right] ) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

// Using Map as an extra space
bool isIntegerPalindrome_2( int integer )
{
    bool result = false;
    // <key=index, val=>
    map<int, int> Map; // !!!: Could've used vector
    int i = 0;

    // Add remainders of name to map
    while (integer > 0) {
        Map[i++] = integer % 10;
        integer /= 10;
    }

    int j = --i; // or j = i - 1
    i = 0;
    while (i < j) {
        if (Map[i] != Map[j]) {
          return false;
        }
        
        i++;
        j--;
    }

    return true;
}

// !!!: smart algorithem. the best from:
// https://www.w3schools.in/c-programming/examples/c-program-to-check-whether-the-given-number-is-a-palindromic
bool isIntegerPalindrome_3( int number )
{
    int reverse_number = 0;
    int original_number = number;
    
    // !!!: great way to reverse a number
    while( number > 0 ) {
        int remainder = number % 10;
        reverse_number = reverse_number * 10 + remainder;
        
        number /= 10;
    }
    
    number = original_number;   // not really needed. used for clarity and readability only
    if( reverse_number == number ) {
        return true;
    }
    else {
        return false;
    }
}

// is String a Permutation of a Palindrome
bool isStringPermutationOfPalindrome1( string str )
{
    int letter[128] = { 0 };    // Used to count occurance of letters
    int odd = 0;                // One odd varaibale for all letters

    for (char c : str) {
        ++letter[c];            // Increment count for each letter found in string
        if ((letter[c] % 2 == 1)) {
            ++odd; // odd
        }
        else {
            --odd; // even
        }
    }

    return odd < 2; // true, if, odd == 0 or 1
}

string longestPalindrome( string str )
{
    // s = "babad" ,  "cbbd"
    int size = (int)str.size ();
    if( size == 1 ) {
      return str;
    }

    string result = "";

    for (int left = 0; left < size - 1; left++) {
        for (int right = size; right > left + 1; right--) {
            int i = left;
            int j = right - 1;
            bool found = true;
            // cout << s.substr(left, right-left) << endl;
            while ((i < j)) {
                if (str[i++] != str[j--]) {
                  found = false;
                  break;
                }
            }
            
            if (found) {
                // cout << s.substr(left, right-left) << endl;
                string substr = str.substr (left, right - left);
                if (substr.size () > result.size ()) {
                    result = str.substr (left, right - left);
                }
            }

            // !!!: The following code works as well
            /* if( isStringPalindrome1(s.substr(left, right-left)) ) {
             string substr = s.substr(left, right-left) ;
               //cout << substr << endl;
               if(substr.size() > result.size()) {
                   result = s.substr(left, right-left);
               }
            }*/
        }
    }

    // No substring palindrome is found, return 1st char in s as string
    if (result == "") {
        return str.substr (0, 1);
    }

    return result;
}

// Remove ALL LETTERS in str2 from str1.
void Remove_Str2_Letters_From_Str1_1 (string &str1, string str2)
{
    int writeposition = 0;

    for (int i = 0; i < str1.length (); i++)
    {
      // find each letter of str1 in str2.
      if (str2.find (str1[i]) == string::npos)
        {
          // str1 letter is Not found in str2, therefore copy it to str1 at
          str1[writeposition++] = str1[i];
        }
    }

    str1.resize (writeposition);
}

// Remove ALL Occurances of str2 in str1. !!!: Works beuatifully O(number of
// str2 in str1)
void Remove_Str2_Letters_From_Str1_2 ( string &str1, string str2)
{
    // str1.find(str2) returns index of first letter in str1
    size_t firstLetterIndex;
    while ((firstLetterIndex = str1.find (str2)) != string::npos)
    {
      // str2 was found in str1, remove it from str1
      str1.erase (firstLetterIndex, str2.size ()); // erase FROM 'firstLetterIndex' TO
                                 // 'firstLetterIndex + size of str2'
    }
}

void ReverseStr (char *s)
{
    int strlen = 0;
    for (int i = 0; s[i] != '\0'; i++) {
      strlen++;
    }

    char *p1 = s;
    char *p2 = s + strlen - 1;
    while (p1 < p2)
    {
      char temp = *p1;
      *p1++ = *p2;
      *p2-- = temp;
    }
}

// Effiecient. Stop looking if str1 is within str1len - str2len
bool StrInStr (char *str1, char *str2)
{
    int alen = (int)strlen (str1);
    int blen = (int)strlen (str2);
    int right = alen - blen;
    int left = 0;

    while (left <= right)
    {
      int i = left;
      int j = 0;
      while (str2[j] != '\0' && str1[i] == str2[j])
        {
          i++;
          j++;
        }

      if (str2[j] == '\0')
        return true;

      left++;
    }

    return false;
}

// Effiecient. Stop looking if str1 is within str1len - str2len
bool StrInStr (string str1, string str2)
{
    int str1len = static_cast<int>(str1.size ());
    int str2len = static_cast<int>(str2.size ());
    int right = str1len - str2len;
    int left = 0;

    while (left <= right)
    {
      int i = left; // i - index of str1
      int j = 0;    // j - index of str2

      while (str2[j] != '\0' && str1[i] == str2[j])
        {
          i++;
          j++;
        }

      if (str2[j] == '\0')
        return true;

      left++;
      // cout << "left = " << left << ", " << "right = " << right << endl;
    }

    return false;
}

// returns true, if strins are identical. returns false, if strings are not identical.
// we cant tell which string greater or smaller than the other one. in that case,
// we return int to indicate which string is greater or smaller:
//   0: str1 == str2
// > 0: str1 > str2
// < 0: str1 < str2
bool strCmp (char *s1, char *s2)
{
    // while( !(*s1 == '\0' || *s2 == '\0' || *s1 != *s2) )
    while( *s1 != '\0' && *s2 != '\0' && *s1 == *s2 ) {
      s1++;
      s2++;
    }

    // reached end of the two strings. they must be identicals
    // ignore all other posibilites and return true
    if( *s1 == '\0' && *s2 == '\0' ) {
        return true;
    }

    // at this point, we can determine which string is greater or smaller than the other
    // if( *s1 == '\0' ) str1 < str2
    // else              str1 > str1
    return false;
}

int wordcount (string str)
{
  int count = 0;
  bool inword = false;

  for( char c : str ) {
      if( c != ' ' && !inword ) {
          inword = true;
          count++;
      }
      else if( c == ' ' ) { // c == ' ' OR inword. Both c == ' ' AND inword
          inword = false;
        }
    }

  return count;
}

// Great job: passing by reference
// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
void reverseWords( string& words )
{
    stack<string> stackOfwords;
    string word = "";

    // find a word in a string of words
    for( char c : words ) {
      if( c != ' ' ) {
          word += c;
      }
      else {
          // end of word reached --> push word onto stack
          stackOfwords.push (word); // add a word to stack
          word = "";                // clear word string
      }
    }
    stackOfwords.push (word); // add the final word to stack

    words = "";

    while (!stackOfwords.empty ())
    {
      // pop word from stack and put back in string of words
      string s = stackOfwords.top (); // get a word from top of stack
      stackOfwords.pop ();            // required by stack operations
      words += s + ' ';               // add a space as word seperator
    }
}

int sumOfDigits( int x )
{
    int sum = 0;
    while( x > 0 ) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

string compressString( string s )
{
  int count = 1;
  string result = "";
  int i = 1;
  for (; i < s.length (); i++)
    {
      if (s[i] == s[i - 1])
        {
          count++;
        }
      // else {(s[i] != s[i-1] || i == s.length()-1}. does not work. would not
      // get last count correctly.
      else
        {                                         // s[i] != s[i-1]
          result += s[i - 1] + std::to_string (count); // char(count) did not work
          count = 1; // static_cast<char>(count) did not work
        }
    }

  result += s[i - 1] + std::to_string (count);

  return result;
}

// Replace 'AB' charecters with 'C' charecter in a string
// Third attempt: perfect. tested. Geniuos
void translateABtoC( string &s )
{
    int writeindex = 0;
    int lastA = 0;

    for( int i = 0; i < s.length (); i++ ) {
      if (s[i] == 'B' && s[i - 1] == 'A') { // should check for i=0, i-1 becomes negative!!!
          s[lastA] = 'C';
      }
      else {
          if (s[i] == 'A') {
              lastA = writeindex;
          }

        s[writeindex++] = s[i]; // Copy all letters including A and B-
      }
    }

    s.resize (writeindex); // s[writeindex] = '\0';
}

/*  string orbits("684563.97 365.244566");
    std::string::size_type sz;     // alias of size_t
    float mars = std::stof(orbits, &sz);
    string tmp = orbits.substr(sz);
    float earth = std::stof(orbits.substr(sz));
    std::cout << "One martian year takes " << (mars / earth) << " Earth
   years.\n"; */
void removeSubstrs( string &str, const string &substr )
{
    string::size_type n = substr.length ();

    /*for (string::size_type i = s.find(p); i != string::npos; i = s.find(p))
    {
    s.erase(i, n);
    }*/

    size_t i = 0;
    // !!!: returns index of first letter where first substr is found
    i = str.find (substr);
    while( (i = str.find (substr)) != string::npos ) {
        str.erase (i, n);
    }
}

// Given a string s, find the length of the longest substring without repeating
// characters. Almost ~O(N2)
string longestSubstring_Without_Repeating_Letter( string str )
{
    // map<string, int> Map; "pwwkew"
    string temp_str = "";
    string max_str = "";
    int i = 0;

    // watch for empty string s = ""
    while( i < str.length () - 1 ) { // Consider using maxlength for optimization here
        int j = i;
        int length = 0;
        int maxlength = 0;

        // Build string until a repeated letter is found
        while( j < str.length () ) {
            auto found = temp_str.find(str[j]);
            if( temp_str.find (str[j]) != string::npos ) {        // npos == Not Found
                break; // letter is in result string, break from while loop
            }
            
            temp_str += str[j]; // Found non-repeating letter, Add it to result
            j++;
            length++;
        }

        if( length > maxlength ) {
          maxlength = length;
          max_str = temp_str;
        }

      temp_str = "";
      length = 0;
      i++;
        
    }

    return max_str;
}

/*  Given a string paragraph and a string array of the banned words banned,
   return the most frequent word that is not banned. It is guaranteed there is
   at least one word that is not banned, and that the answer is unique. The
   words in paragraph are case-insensitive and the answer should be returned in
   lowercase. */
// Not tested
string mostCommonWord( string paragraph, vector<string>& banned_words )
{
    string result = "";
    string word = "";
    // Create a map for words and their occurance counts
    // <word, count>
    map<string, int> Map;

    // !!!: Commented out following code, since words in paragraph are case-insensitive
    // Convert paragraph string to upper case
    /*for( int i = 0; i < paragraph.length (); i++ ) {
        paragraph[i] = (char)toupper(paragraph[i]);
    }

    // Convert banned string(s) to upper case
    for( int i = 0; i < banned[i].length (); i++ ) {
        for( int j = 0; j < banned[i][j]; j++ ) {
            banned[i][j] = (char)toupper (banned[i][j]);
        }
    }*/

    // Find words in parapraph and check it is not in banned
    for( int i=0, j=0, max=0; i < paragraph.length (); i = j + 1 ) {
        
        // find a word in the paragraph
        j = i;
        while( j < paragraph.length () && paragraph[j] != ' '
                  && paragraph[j] != ',' && paragraph[j] != '.' ) {
          word += paragraph[j++];
        }

        // find a word i banned words
        for( string banned_word : banned_words ) {
          if(word != banned_word ) {
              Map[word]++;
              if( Map[word] > max ) {
                  max = Map[word];
                  result = word;
              }
            }
        }
        
        word = "";
    }
    
    for( int i = 0; i < result.length (); i++ ) {
        result[i] = (char )tolower(result[i]);  // cast from int to char
    }

    return result;
}

// First try, it is OK, See next version
string addTwoStrings1( string s1, string s2 )
{
  string result = "";

  long int s1length = s1.length ();
  long int s2length = s2.length ();
  int digit1 = 0;
  int digit2 = 0;
  int carry = 0;
  int sum = 0;

  // i & j traverse s1 & s2 from end to start
  long int i = s1length - 1;
  long int j = s2length - 1;
  for (; i >= 0; i--, j--)
    {
      digit1 = s1[i] - '0'; // convert s1's char to int -> digit1
      sum = digit1 + carry; // INITIALIZE sum with digit1 + carry
      if (j >= 0)           // we have not reached end of s2
        {
          digit2 = s2[j] - '0'; // convert s2's char to int -> digit2
          sum += digit2;        // Notice +=, add digit2 to sum
        }

      carry = sum / 10;
      result += (sum % 10) + '0'; // Notice +=
    }

  // s2 > s1: add rest of digits in s2, if any left
  while (j >= 0)
    {
      digit2 = s2[j] - '0'; // convert s2's char to int -> digit2
      sum = digit2 + carry; // INITIALIZE sum with digit2 + carry

      carry = sum / 10;
      result += (sum % 10) + '0';
      j--;
    }

  // if there is a carry add to final result
  if (carry > 0)
    {
      result += char (carry + '0');
    }

  reverse (result.begin (), result.end ());

  return result;
}

// !!!: Execellent work by ME. Best version. Much cleaner
string addTwoStrings2 (string str1, string str2)
{
    string result = "";
    int carry = 0;
    // √√√: i & j traverse s1 & s2 from end to start
    long int i = str1.length () - 1;
    long int j = str2.length () - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = 0, digit2 = 0, digit_sum = 0;

        // 1. both strings have digits.
        //    then, add both digits to sum
        if (i >= 0 && j >= 0) {
          digit1 = str1[i] - '0';          // convert s1's char to int -> digit1
          digit2 = str2[j] - '0';          // convert s2's char to int -> digit2
          digit_sum = digit1 + digit2 + carry; // INITIALIZE sum with digit1 + carry
        }
        
        // 2) no more digits in string 2 to add to sum.
        //    then, just add all digits from string 1 to sum
        else if (i >= 0) {
            digit1 = str1[i] - '0';
            digit_sum = digit1 + carry;
        }
        
        // 3) no more digits in string 1 to add to sum.
        //    then, just add all digits from string 2 to sum
        else
        {
            digit2 = str2[j] - '0';
            digit_sum = digit2 + carry;
        }

        carry = digit_sum / 10;           // carry is a whole number
        result += (digit_sum % 10) + '0'; // !!!: Notice +=. store remainder in result

        i--;
        j--;
    }

    // if there is a carry at this point, add it to the final result
    if (carry > 0)
    {
        result += char (carry + '0');
    }

    // result data was entered in reverse order. reoder it.
    reverse (result.begin (), result.end ());

    return result;
}

string multiplyTwoStrings ( string number1, string number2 )
{
  string result;
  int carry = 0;
  int multiplier1 = 1;      // Used for inner loop
  int multiplier2 = 1;
  int product = 0;
  int productSum = 0;

  int size1 = (int)number1.size ();
  int size2 = (int)number2.size ();
  int number1_size = size1 - 1;
  int number2_size = size2 - 1;

    // 1) traverse every digit in number2 string
    while( number2_size >= 0 ) {
        
        // 1.1) get a digit from number2 string
        int digit2 = number2[number2_size] - '0';

        // 2) traverse every digit in number1 string
        while (number1_size >= 0) {
            
            // 2.1) get a digit from number1 string
            int digit1 = number1[number1_size] - '0';
            
            // 3) multiply the two digits and add carry to them
            int digits_product = digit1 * digit2 + carry;
            
            // 4) determine carry from the digit product
            carry = digits_product / 10;  // a carry over digit going from RIGHT to LEFT
            int remainder = digits_product % 10;

            // 5)
            product = product + remainder * multiplier1;

            multiplier1 *= 10;      // raise power of multiplier by 10 for next iteration
            number1_size--;
        }
        
        // 6) finished all iterations for number1. now we can calculate the result of
        //    multiplying a digit2 in number2 with all digits in number1, add it to product
        product += carry * multiplier1;

        product *= multiplier2;
        productSum += product;

        // Some initialization must be done at end of each iteration
        carry = 0;
        multiplier1 = 1;
        multiplier2 *= 10;
        product = 0;
        number1_size = size1 - 1; // Reset index of num1
        number2_size--;
    }

  result = std::to_string (productSum);
  return result;
}

vector<string> commonChars (vector<string> &words)
{
  vector<string> result;
  size_t size = words.size ();
  if (size == 0)
    {
      return result;
    }

  // Map of key=char and value=char count
  map<char, int> charCount;
  for (string word : words)
    {
      for (char c : word)
        {
          charCount[c]++;
        }
    }

  map<char, int>::iterator itr;
  for (itr = charCount.begin (); itr != charCount.end (); itr++)
    {
      int count = itr->second;
      int whole = count / size;
      int i = 0;
      while (i < whole)
        {
          string str;
          str = itr->first;
          result.push_back (str);
          i++;
        }
    }

  return result;
}

vector<string> unique_names (vector<string> names1, vector<string> names2)
{
    vector<string> result (names1);

    for (string str : names2) {
        if( find(begin(names1), end(names1), str) == end(names1) ) {
          result.push_back (str);
        }
    }
    
  return result;
}

char digit_to_hex_char( int digit)
{
    return "0123456789ABCD"[digit];
}

// remove characters from string without using string.h library
/*void New(void)
{
    int i=0,j=0,k=0,q;
     char a[20],b[20];
     char *p = malloc(20);
     scanf("%s %s",a,b);
      while(a[i] != '\0')
      {
          j=0;
          q =0;
          while(b[j] != '\0')
          {
             if(a[i] == b[j])
             {
                 q  =1;
                 break;
             }
             j++;
          }
          if(!q)
          p[k++] = a[i];
          i++;
      }
      p[k] = '\0';
      printf("%s\n",p);
}*/


