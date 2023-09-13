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
    
    // add the word to stack
    stackOfwords.push (word);

    words = ""; // intitalize the words string to empty

    while( !stackOfwords.empty () ) {
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
string longestSubstring_Without_Repeating_Characters_1( string name )
{
    // map<string, int> Map; "pwwkew"
    string longest_substr = "";
    
    int i = 0;
    // watch for empty string s = ""
    while( i < name.length () - 1 ) { // Consider using maxlength for optimization here
        int j = i;
        string str = "";

        // Build string until a repeated letter is found
        while( j < name.length () ) {
            if( str.find( (char )toupper(name[j]) ) != string::npos ||
                str.find( (char )tolower(name[j]) ) != string::npos ) {      // npos == Not Found
                break; // letter is in result string, break from while loop
            }

            str += name[j++]; // Found non-repeating letter, Add it to result
        }

        if( str.size() > longest_substr.size() ) {
            longest_substr = str;
            cout << longest_substr << endl;
        }

        i++;
    }

    return longest_substr;
}

// !!!: trying to do  O(N). still not working
string longestSubstring_withoutRepeating_Characters_2( string str )
{
    //map<string, int> m;
    string curr_substr = {str[0]};
    string longest_substr = {str[0]};
    longest_substr = str[0];

    int i = 1;
    while( i < str.size() ) {
        // std::string::iterator it = longest_substr.begin();
        size_t index = str.find( str[i] );
        cout << "char = " << str[i] << " at index = " << index << endl;
        //str.find(
        if( curr_substr.find( (char )toupper(str[i]) ) == string::npos &&
            curr_substr.find( (char )tolower(str[i]) ) == string::npos) {
            // since, surr char is not in the longest substring, we need to add it to the longest substring
            curr_substr += str[i];
        }
        else {
            // char is in the longest substring, start a longest substring seach at curr index
            if( curr_substr.size() > longest_substr.size() ) {
                longest_substr = curr_substr;
                cout << longest_substr << endl;
            }

            curr_substr = "";
            longest_substr = str[index+1];
            i = index + 1;
        }
        i++;
    }
    
    return longest_substr;
    
    /*
     A short holds numbers too. As does a signed char.
     But none of those types are guaranteed to be large enough to represent the sizes of any strings.
     string::size_type guarantees just that. It is a type that is big enough to represent the size of a string, no matter how big that string is.
     For a simple example of why this is necessary, consider 64-bit platforms. An int is typically still 32 bit on those, but you have far more than 2^32 bytes of memory.
     So if a (signed) int was used, you'd be unable to create strings larger than 2^31 characters. size_type will be a 64-bit value on those platforms however, so it can represent larger strings without a problem.
     */
}

/*  Given a string paragraph and a string array of the banned words banned, return the most frequent word
    that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer
    is unique. The words in paragraph are case-insensitive and the answer should be returned in lowercase. */
// mostCommon_unbannedWord() is a special case of mostCommon_Word()
string mostCommon_unbannedWord( string paragraph, vector<string>& banned_words )
{
    string result = "";
    // Create a map for word counts
    // <"word", count>
    map<string, int> word_count;

    // Find words in parapraph and check it is not in banned
    int max_word_count = 0;
    
    int i = 0;
    while( i < paragraph.size () ) {
        // start with empty word
        string word = "";

        // 1) find a word in the paragraph
        int j = i;
        while( j < paragraph.length() && paragraph[j] != ' ' && paragraph[j] != ',' && paragraph[j] != '.' ) {
            word += paragraph[j++];
        }
        
        // if you have ' ' or ',' or '.' in the paragraph, you end up with empty word => "".
        // ignore current word and move to the next word index
        if( word == "" ) {
            i = j + 1;  // continue searching for the next word
            continue;
        }
        
        // 2) check if the word is banned
        bool banned = false;
        for( string banned_word : banned_words ) {
            if( word == banned_word ) {
                // word is banned, ignore it and go to the next word
                banned = true;
                break;
            }
        }

        // 3) check if the word is not banned
        if( !banned ) {
            // word not banned, add it to word count map and update its count
            word_count[word]++;
            if( word_count[word] > max_word_count ) {
                max_word_count = word_count[word];
                result = word;      // at this point, this is the most occured word
            }
        }
        
        i = j + 1;
    }
    
    return result;
}

// https://www.geeksforgeeks.org/frequent-word-array-strings/
// !!!: a bug in Geeks code. should return (max_wordcount +1) !!! O(N2)
void mostCommonWord_geeks( vector<string> words )
{
    // freq to store the freq of the most occurring variable
    int max_wordcount = 0;
    // most_commonword is used to store the most occurring string in the array of strings
    string most_commonword;
 
    // my idea to figure out O()
    // for number of words = 15: = N-1 + N-2 + N-3 ...1 = (14*15)/2 = (N*N+1)/2 = (N2+1)/2 = O(~N2)
    int test_count = 0;

    // running nested for loops to find the most occurring word in the array of strings
    for( int left = 0; left < words.size(); left++ ) {
        int wordcount = 0;
        // count the occurance of a word
        for( int right = left + 1; right < words.size(); right++ ) {
            test_count++;
            // compare right word with left word, and move to the next (right) word
            if( words[right] == words[left] ) { // comparing 2 strings
                wordcount++;
            }
        }
        
        // updating our max freq of occurred word in the array of words
        if( wordcount >= max_wordcount ) {
            most_commonword = words[left];
            max_wordcount   = wordcount;
        }
    }
 
    cout << "\tThe word that occurs most is : " << most_commonword;
    cout << ",\tNo of times: " << max_wordcount << endl;
}

// my solution: faster than Geeks, O(N words)
void mostCommonWord_mySol( vector<string> words )
{
    map<string, int> wordcount_map;
    int max_wordcount = 0;
    string most_commonword;
    
    // word: ["string", count]. [first, second]. [first] == second
    for( string word: words ) {
        wordcount_map[word]++;
        if( wordcount_map[word] >= max_wordcount ) {
            most_commonword = word;
            max_wordcount   = wordcount_map[word];
        }
    }
    
    /*// word: ["string", count]. [first, second]
    for( auto word: wordcount_map ) {
        if( word.second >= max_wordcount ) {
            most_commonword = word.first;
            max_wordcount   = word.second;
        }
    }*/
    
    cout << "\tThe word that occurs most is : " << most_commonword;
    cout << ",\tNo of times: " << max_wordcount << endl;
}

// First try, it is OK, See next version
string addTwoStrings1( string str1, string str2 )
{
    string result = "";

    // !!!: str1size & str2size traverse s1 & s2 from END to START
    int digit1 = 0, digit2 = 0, sum = 0, carry = 0;

    long int str1size = str1.length () - 1;
    long int str2size = str2.length () - 1;
    
    while ( str1size >= 0 ) {
        digit1 = str1[str1size] - '0'; // convert s1's char to int -> digit1
        sum = digit1 + carry; // INITIALIZE sum with digit1 + carry
        if (str2size >= 0 ) {          // we have not reached end of s2
          digit2 = str2[str2size] - '0'; // convert s2's char to int -> digit2
          sum += digit2;        // Notice +=, add digit2 to sum
            str2size--;
        }

        carry = sum / 10;
        result += (sum % 10) + '0'; // Notice +=
        str1size--;
    }

    // s2 > s1: add rest of digits in s2, if any left
    while ( str2size >= 0 ) {
        digit2 = str2[str2size] - '0'; // convert s2's char to int -> digit2
        sum = digit2 + carry; // INITIALIZE sum with digit2 + carry

        carry = sum / 10;
        result += (sum % 10) + '0';
        str2size--;
    }

    // if there is a carry add to final result
    if( carry > 0 ) {
        result += char (carry + '0');
    }

    reverse (result.begin (), result.end ());

    return result;
}

// !!!: Execellent work by ME. Best version. Much cleaner.
// does not work for negative numbers
string addTwoStrings2 (string str1, string str2)
{
    string result = "";
    int carry = 0;
    // !!!: str1size & str2size traverse s1 & s2 from END to START
    long int str1size = str1.size () - 1;
    long int str2size = str2.size () - 1;

    while( str1size >= 0 || str2size >= 0 ) {
        int digit1 = 0, digit2 = 0, sum = 0;

        // 1. check that we have not reached the end of both strings, then, add both digits to sum
        if( str1size >= 0 && str2size >= 0 ) {
            digit1 = str1[str1size] - '0';        // convert s1's char to int -> digit1
            digit2 = str2[str2size] - '0';        // convert s2's char to int -> digit2
            sum = digit1 + digit2 + carry;        // INITIALIZE sum with digit1 + carry
        }
        // 2) no more digits in string 2 to add to sum, then, just add all digits from string 1 to sum
        else if (str1size >= 0) {
            digit1 = str1[str1size] - '0';
            sum = digit1 + carry;
        }
        // 3) no more digits in string 1 to add to sum, then, just add all digits from string 2 to sum
        else {
            digit2 = str2[str2size] - '0';
            sum = digit2 + carry;
        }

        carry = sum / 10;           // carry over a whole number
        result += (sum % 10) + '0'; // !!!: Notice +=. store remainder in result

        str1size--;
        str2size--;
    }

    // if there is a carry at this point, add it to the final result
    if (carry > 0) {
        result += char (carry + '0');
    }

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

vector<string> commonChars_inStrings (vector<string> &words)
{
    vector<string> result;
    size_t size = words.size ();
    if (size == 0) {
      return result;
    }

    // Map of key=char and value=char count
    map<char, int> charCount;
    for (string word : words) {
      for (char c : word) {
          charCount[c]++;
        }
    }

    map<char, int>::iterator itr;
    for (itr = charCount.begin (); itr != charCount.end (); itr++) {
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

    for (string str2 : names2) {
        if( find(begin(names1), end(names1), str2) == end(names1) ) {
          result.push_back (str2);
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


