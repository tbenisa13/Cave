//
//  FindStuffInArrays.cpp
//  Practice1
//
//  Created by taher benisa on 11/15/20.
//  Copyright © 2020 taher benisa. All rights reserved.
//

#include "FindStuffInArrays.hpp"
#include <queue>

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::array;
using std::map;
using std::set;
using std::stack;
using std::endl;
using std::istream;
using std::ostream;
using std::max;
using std::to_string;
using std::priority_queue;
using std::pair;


// Inefficient algorthim. Does not take advatage of sorted array
int findMin_inSortedRotatedArray_1(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        // min index is found, if current number is greater than next number
        if (a[i] > a[i + 1])
        {
            //cout << "\n\trotated right " << (i + 1) << " times" << ", OR, rotated left " << (len - (i + 1)) << endl;
            return i + 1; // rotated right (i + 1), OR, rotated left (len - (i + 1))
        }
        
        //cout << i << ",";
    }
    //cout << "\n\tNo rotations of elements";
    
    return 0;
}

// !!!: ///////////////////       Find a Minimum Number in Sorted Rotated Array      /////////////////////
// !!!: Returns index from which you can print its value
// !!!: Brillint by me. Best solution. It takes advantage of sorted array
// Algorithem:
// !!!: Always look for min_index in the Unsoretd half-array

int findMin_inSortedRotatedArray_2(vector<int> array)
{
    // this function keeps tarck of min index as opposed to min value
    int left  = 0;
    int right = static_cast<int>(array.size() - 1);
    int min_index = 0;       // minmum index: starts at left which is zero
    int mid_index = 0;       // middle index:
    
    while( left <= right )
    {
        mid_index = (left + right) / 2;
        
        if( array[mid_index] < array[min_index] )
        {
            // left subarray is not sorted: 6 7 1 2 3 4 5
            min_index = mid_index;      // We have a new min
            right = mid_index - 1;      // search in left subarray
        }
        
        else
            // right subarray is not sorted: 4 5 6 7 1 2 3; Corner case: 1 2 3 4 5 6 7
            // Look right, since right half array is not sorted
            left = mid_index + 1;        // search in right subarray
    }
    
    return min_index;    // Returns min index
}

// !!!: from Practice2.cpp. Not a very good solution.
int findNumberOfRotations_inSortedRotatedArray(vector<int> array)
{
    return findMin_inSortedRotatedArray_2(array);
}

// !!!: ///////////////////       Find a Number in Sorted Rotated Array      /////////////////////
/*
 Search in Rotated Sorted Array:
 There is an integer array nums sorted in ascending order (with distinct values).
 Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 You must write an algorithm with O(log n) runtime complexity.

 Example 1:
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 
 Example 2:
 Input: nums = [5,1,3], target = 3
 Output: 2

 Example 3:
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1

 Example 4:
 Input: nums = [1], target = 0

 Algorithem:
 1. Determine which half of array is sorted, and which is not:
    left  subarray is sortd, if middle > left
    right subarray is sortd, if middle < right
 2. !!!: Look in the sorted half first:
    if (target is between left AND middle) || (target is between middle AND right)

 // 1) look in the sorted subarray first:
 //      A) look in left subarray if,  a[left]  =< number =< a[mid-1]
 //      B) look in right subarray if, a[mid+1] =< number =< a[right]
 // 2) if 1) is not satisfied, we are forced to look in the unsorted half
 */
// !!!: I am impressed with my solution
int findNumber_inSortedRotatedArray_1(vector<int> a, int number)
{
    // {8, 9, 0, 1, 2, 4, 5, 6, 7};
    // {5, 6, 7, 8, 9, 0, 1, 2, 4 };
    int left  = 0;
    int right = static_cast<int>(a.size()) - 1;
    int mid   = 0;

    // 4, 5, 6, 7, 1, 2, 3
    // 2, 3, 4, 5, 6, 7, 1
    while( left <= right ) {
        mid = (left + right) / 2;
        
        // bail out, number was found
        if(a[mid] == number) {
            return mid;
        }
        
        // 2. Find sorted and non-sorted halfs of array (subarrays)
        if( a[mid] > a[left] ) {
            // Left subarray is sorted
            if( number >= a[left] && number <= a[mid-1] ) {
                // target is in left subarray
                right = mid - 1;
            }
            else {
                // target is in right subarray
                left = mid + 1;
            }
        }
        else {
            // right subarray is sorted
            if( number >= a[mid+1] && number <= a[right] ) {
                // target is in right subarray
                left = mid + 1;
            }
            else {
                // target is in left subarray
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
  
// it works, but slower than above ones. too many function calls
int findNumber_inSortedRotated_Array_2(vector<int>& a, int number)
{
    int size = static_cast<int>(a.size());

    if( size == 0 ) {
        return -1;
    }
    
    // First, Find min in sorted array, uses binary search O(log size)
    int minIndex = findMin_inSortedRotatedArray_2(a);
    
    if( a[minIndex] == number )
        return minIndex;    // Input: nums = [4,5,6,7,0,1,2], target = 0, target FOUND
    
    int valueIndex = 0;

    if( number > a[minIndex] && number <= a[size - 1] )
        // Go right
        valueIndex = Search_Binary_1(a, minIndex + 1, size - 1, number);
    else
        // Go left
        valueIndex = Search_Binary_1(a, 0, minIndex - 1, number);
    
    return valueIndex;
}


// !!!: //////////////////       Missing Number In Incremental Sequence         ///////////////////////
/*  Given an UNSORTED array nums containing N distinct numbers in the range [0,1,2,3....N],
    return the only number in the range that is missing from the array.
    Follow up: Could you implement a solution using only O(1) extra space complexity and O(N) runtime complexity? YESS*/
// !!!: Runtime: 12 ms, faster than 97.15% of C++ online submissions for Missing Number.
// !!!: Memory Usage: 18.1 MB, less than 18.84% of C++ online submissions for Missing Number.
int findMissingNumber_inIncrementalUnsortedArray(vector<int>& array) {
    // [9,6,4,2,3,5,7,0,1] missing 8
    int result = -1; //
    
    int min = INT_MAX;
    int max = INT_MIN;   // Important
    int actualsum = 0;
    
    for( int i=0; i < array.size(); i++ ) {
        actualsum += array[i];      // array's sum
        if(array[i] < min) {
            min = array[i];         // array's min
        }
        if(array[i] > max) {
            max = array[i];         // array's max
        }
    }
    
    if( min != 0 ) { // remove if() statement, if range [1, N]
        return 0;
    }

    int expectedsum = (max * (max+1)) / 2;  // 0,1,2,3,4,5,6,7,8,9 = (9 * 10) / 2 = 45
    if( expectedsum == actualsum ) {
        // No missing number, return max+1, or return -1
        return max + 1;     // return 10, or -1
    }
    
    return expectedsum - actualsum;
}

// Find missing number in incremental SORTED sequence: a[N] = 1,3,4,5,6,7,8,9,10, n = 9, missing 2
// !!!: a[1...N]. Great, it works. O(log(N))
int Find_MissingNumber_In_Incremental_SortedArray(vector<int> a)
{
    // !!!: a[] = {1, ,3,4,5,6,7,8,9,10}; missing 2
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;
 
    while( left <= right ) {
        
        int mid = (left+right)/2;
        // 1) handle corner case FIRST, check if we reached left-end of array and that element is not 1: (mid == 0 && a[mid] != 1).
        // this is the case where a[mid] = a[0] = 2. return missing number: a[mid]-1 = 1
        if( mid == 0 && a[mid] != 1)
            return a[mid] - 1;  // or just return 1
        
        // 2) look at adjacent left to see if it is grater than middle number by 1
        if((a[mid] - a[mid-1]) > 1 ) {
            return a[mid] - 1;    // Found missing number, return it
        }

        // look at adjacent right to see if it is grater than middle number by 1
        // algorithem still works without this 'if' statmement. adding it, makes code more effiecent by 1 or 2 iterations
        if( (a[mid+1] - a[mid]) > 1) {
            return a[mid] + 1;    // Found missing number, return it
        }

        if(a[mid] - mid > 1)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return -1;
}


// !!!: ////////////     Find First Missing Positive In Unsorted Array    ////////////////
//  !!!: Nailed it
//  Given an UNSORTED integer array nums, find the Smallest Missing Positive integer.
//  Could you implement an algorithm that runs in O(n) time and uses constant extra space.?

/*  Runtime: 528 ms, faster than 5.02% of C++ online submissions for First Missing Positive.
 Memory Usage: 138.8 MB, less than 5.18% of C++ online submissions for First Missing Positive.*/
// O(N). Uses set as an extra space
int firstMissingPositive_inUnsortedArray_1(vector<int>& a) {
    // sorted set of positive and negative numbers
    set<int> sorted_set(a.begin(), a.end());
    set<int>::iterator itr = sorted_set.begin();
    int min = *itr;     // first number is min number in set
    itr = sorted_set.end();
    int max = *--itr;   // first number is min number in set
       
    if(min > 1) {
        return 1;   // [7,8,9,12,11]. min = 7, ret 1
    }

    // Missing number between 1 & maxNumber.
    for( int i = min + 1; i < max; i++ ) {
        if( i > 0 && sorted_set.find(i) == sorted_set.end() ) {    // Execlude negative numbers
                return i;   // Smallest number, between 1 & max, not in set. Return that number
                            // [3,4,-1,1] => [3,4,1]. min = 1, ret 2
        }
    }
    
    // Missing number Not found before min number, and Not found between min & max
    return max + 1;     // [4,1,3,2] ret 5, or better return -1
}

// Less code from Leet. Does not use extra space, but O(N^2 + N) => O(N^2)
int firstMissingPositive_inUnsortedArray_2( vector<int>& a )
{
    for( int i=0; i < a.size(); i++ ) {
        if( a[i] == i+1 ) {
            continue; // !!!: Pay attention to continue. Interesting!
        }
        
        int x = a[i];
        while( x >= 1 && x <= a.size() && x != a[x-1] ) {
            std::swap(x, a[x-1]);
        }
    }
    
    for( int i=0; i < a.size(); i++ ) {
        if( a[i] != i+1 ) {
            return i+1;
        }
    }
    
    return (int )(a.size()) + 1;  // Casting to int sielnce compiler
}

// Suposedly fastest from Leet. Uses set as an extra space
int firstMissingPositive_inUnsortedArray_3(vector<int>& array) {
    // FIRST DROP ALL THE NEGATIVES and SECOND FIND MAX AND MIN
    for( auto it = array.begin(); it != array.end(); ) {
        if (*it <= 0) {
            it = array.erase(it);
        } else {
            it++;
        }
    }
    
    unsigned long size = array.size();
    
    set<int> here;
    for( int i = 0; i < size; i++ ) {
        here.insert(array.at(i));
    }
    
    // !!!: This is more clear approch from Lettcode, but it is less efficient because r=1....
    // It should use min & max to find missing positive number.
    int r = 1;
    while( true ) {
        if( here.find(r) == here.end() ) {
            return r;
        }
        else {
            r++;
        }
    }
    
    return r;
}

// !!!: /////////////////////       Binary Serach       ///////////////////////
int Search_Binary_1(vector<int> a, int left, int right, int value)
{
    while( left <= right )
    {
        int mid = (left + right) / 2;
        if(a[mid] == value)
            return mid;
        
        if(value < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
        
    };
    
    return -1;
}

// Given a sorted array of size N and an integer value, find the position at which value is present in the array using binary search.
int Search_Binary_2(int arr[], int N, int value) {
    // code here
    int left = 0;
    int right = N - 1;
    int mid = 0;
    
    while( left <= right ) {
        mid = (left+right) / 2;
        
        if(arr[mid] == value) {
            return mid;
        }
        
        if(value < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return -1;
}

// !!!: //////////////////      First Non Repeating Lette in Stream     //////////////////
char Find_FirstNonRepeatingChar(string str)
{
    // str[i], count
    map<char, int> charCountMap;
    
    // Count of char in string
    for(char character : str) {
        charCountMap[character]++;
    }
    
    for(char character : str) {
        if( charCountMap[character] == 1) {
            return character;       // first non-repeating char
        }
    }
    
    return '\0';    // special character for c not found
}


// Find first 2 Non-Repeating numbers in numbers[]. This is the prefered solution
/*  You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.*/
vector<int> Find_First2NonRepeatingNumbers_1(vector<int> a)
{
    vector<int> result;
    
    map<int, int> intCountMap = {{0,0}};
    // Count of int in array
    for(int i : a)
        intCountMap[i]++;
    
    for(int i : a) {
        if( intCountMap[i] == 1) {
            result.push_back(i);
            
            if(result.size() == 2) {
                return result;
            }
        }
    }
    
    /*  Note: this works, but slower than using a Map instead of Set
        int res = 0;
        set<int> setCount;
        int res = 0;
        for(int i : nums) {
            if(setCount.find(i) == setCount.end()) {
                setCount.insert(i);
                res += i;
            }
            else {
                res -= i;
            }
     
        return res;
     }*/

    return result;    //
}

// This is Ok. Find_First2NonRepeatingNumbers_2()
vector<int> Find_First2NonRepeatingNumbers_2(vector<int> numbers)
{
    vector<int> result(2);

    // <number, count>
    map<int, int> intCount;
    for(int number : numbers) {
        intCount[number]++;
    }

    int count = 0;
    map<int, int>::iterator itr;
    for( itr = intCount.begin(); itr != intCount.end(); itr++ ) {
        if( itr->second == 1 && count < 2 ) {               // number's count == 1
            result[count++] = itr->first;   // store number
        }
    }

    return result;
}

/* Given an array of integers nums and an integer target, return INDICES of the two numbers such that they add up to target.
   You may assume that each input would NOT have !!!: EXACTLY ONE SOLUTION, and you may not use the same element twice.
   You can return the answer in any order.*/
/* Runtime: 12 ms, faster than 77.95% of C++ online submissions for Two Sum.
   Memory Usage: 12.3 MB, less than 7.66% of C++ online submissions for Two Sum.*/
// !!!: Time Complexity: O(n) Space Complexity: O(n)
// !!!: using extra space, "map<k, v>" to avoid sorting the array
vector<int> onePair_Equal_targetSum( vector<int>& array, int targetSum )
{
    // indices of 2 numbers that add up to target. If sum not found return idices of -1
    vector<int> result(2, -1);
    
    // <key = number, value = number index>
    map<int, int> Map;
    
    // 1) put all array values with their indices in map
    int index = 0;  // index to 'this number'
    for(int number : array) {
        Map[number] = index++;   // key = number, value = index
    }
    
    // 2) search for the other number in the map
    for(int index=0; index < array.size(); index++) {
        int thisNumber  = array[index];         // 2.1) get this number from input array.
        int otherNumber = targetSum - thisNumber;     // 2.2) subtract this number from target sum,
                                                //      to search for the other number in Map
        // !!!: You may not use the same number twice, means:
        // !!!: search for the condition where, the other number found in Map && it is not this number in input array
        // !!!: Critical thinking: Map[othernum] != i. Remember, Map[othernum] returns index,
        if( Map.find(otherNumber) != Map.end() && Map[otherNumber] != index ) {
            // found the other number in Map
            result[0] = index;              // return index to this number, and
            result[1] = Map[otherNumber];   // index of the other number in Map
            break;                          // return the indecies pair
        }
    }

    return result;  // return the indecies pair
}

// My solution: simpler with O(N) √√√. prints numbers not their indicies
// !!!: does not work
bool print_allPairs_Equal_targetSum( const vector<int>& array, int targetSum )
{
    int i = 0;
    bool found_sum = false; // a flag to indicate wether at least one some was found and printed

    for( ; i < array.size()-1; i++ ) {
        if( find( array.begin() + i+ 1, array.end(), targetSum - array[i] ) != array.end() )
        {
            found_sum = true;   //
            cout << "\t\t  " << targetSum << " = " << array[i] << " + " << targetSum - array[i] << endl;
           // cout << "[" << array[i] << ", " << array[i+1] << endl;
            
        }
    }
    
    return found_sum;
}

// Print pairs of integers with specific difference.
// You may assume that each input would have !!!: EXACTLY ONE SOLUTION
// a2 - a1 = diff
// find a2 = a1 + diff. look for a2 in the set
vector<vector<int>> allPairs_Equal_targetDifference( const vector<int> number, int targeyDiff)
{
    // {1, 7, 5, 9, 2, 12, 3, -1, 11, -2}
    
    vector<vector<int>> result; // result[][] is a 2D array
    vector<int> temp(2);
    
    // <key=array number, value=array index>
    map<int, int> Map;
    
    // Put all array values with their indices in map
    int index = 0;  // index to 'this number'
    for(int number : number) {
        Map[number] = index++;   // key = number, value = index
    }

    for(int index=0; index < number.size(); index++) {
        int thisNumber  = number[index];
        int otherNumber = targeyDiff + thisNumber;   // to find the other number, add diff to this number

        // !!!: You may not use the same element twice -> other number found in map && it is not this number
        // !!!: Critical thinking: Map[othernum] != i. Remember, Map[othernum] returns index,
        if( Map.find(otherNumber) != Map.end() && Map[otherNumber] != index ) {
            // found the other number in Map
            vector<int> temp(2);
            temp[0] = thisNumber;       // return index to this number, and
            temp[1] = otherNumber;      // index to the other number in Map
            result.push_back(temp);
            
            Map.erase(otherNumber);     // !!!: importante. delet the other number from Map. so, we don't consider it again
        }
    }

    return result;
}

// !!!: My function: we are not sorting array first
// !!!: O(n-1 + n-2 ... 1) = arithmetic series = (n*(n-1))/2 = (7*6)/2 = 42/2 = 21 , for n=7.
// !!!: Time Complexity : almost O(n^2), and Space Complexity: O(1)
vector<int> onePair_Closest_toZero_1(vector<int> numbers)
{
    int min_sum = INT_MAX;  // !!!: Note INT_MAX
    int left = 0, right = 0;
    size_t size = numbers.size();
    //int count = 0;  // For testing only

    vector<int> pair(2);
    for( left = 0; left < size-1; left++ ) {
        for( right = left+1; right < size; right++ ) {
            // !!!: Note: abs(), as we are only interested in the "minimist distance to zero", wether negative or positive
            int sum = abs( numbers[left] + numbers[right] );
            if( sum < min_sum ) {
                min_sum = sum;
                pair[0] = numbers[left];
                pair[1] = numbers[right];
                printf("\t\t\tMin pair sum = %d \t--> [%d, %d][%d, %d]\n", (numbers[left] + numbers[right]), left, right, numbers[left], numbers[right]);
            }
            //count++;
         }
     }
    
    //printf("My findMinSumPair(): BigO(count) = %d \n", count); // count is less for my function than one online
    //return min_sum;
    return pair;
}

/*  https://tutorialhorizon.com/algorithms/find-two-elements-whose-sum-is-closest-to-zero/
    Sorting approach:
    1. Sort the array.
    2. This will bring all the negative elements to the front and positive elements at the end of the array.
    3. Track 2 numbers, one positive number close to 0, let’s call it as positiveClose and one negative number
        close to 0, let’s call it as negativeClose. take 2 pointers, one from the beginning of the array and
        another one from the end of the array. say pointers are i and j.
    4. Add A[i] + A[j], if sum > 0 then reduce j, j-- and if sum < 0 then increase i ++.
    5. If sum > 0 compare it with positiveClose, if positiveClose>sum, do positiveClose = sum.
    6. If sum < 0 compare it with negativeClose, if negativeClose<sum, do negativeClose = sum.
    7. Repeat steps 5, 6, 7 till i<j.
    8. Return the minimum of absolute values of positiveClose and negativeClose, this will be the answer.
    9. At any point, if sum = 0 then return 0 since this will be the closest to the 0 possible.
    10. We can easily modify the code given below to track the two indexes as well for which the closest sum is possible.
    
   !!!: Time Complexity: O(nlogn) Space Complexity: O(n) by using merge sort.  */
// !!!: sorting the array and not using extra space, "map<k, v>"
vector<int> onePair_Closest_toZero_2( vector<int> numbers )
{
    //int count = 0;  // For testing only
    vector<int> pair(2);
    if( numbers.size() <= 2 ) {
        return numbers;
    }

    // 1) !!!: sort numbers first :!!!
    sort( numbers.begin(), numbers.end() );

    int left = 0, right = static_cast<int>(numbers.size() - 1);
    int positiveClose = INT_MAX;
    int negativeClose = INT_MIN;
    // !!!: we need to keep track of the left & right indices as we need them later
    int prev_left  = left;
    int prev_right = right;
    
    while( left < right ) {
        int sum = numbers[left] + numbers[right];
        // check if sum is greater than 0
        if( sum > 0 ) {
            // check if positiveClose needs to be updated.
            if( sum < positiveClose ) {
                prev_left = left;       // !!!: keep track of left index
                prev_right = right;     // !!!: keep track of right index
                positiveClose = sum;    // !!!: at this sum
            }
            // decrement right, in order to reduce the difference, close to 0
            right--;
        }
        else if( sum < 0 ) {
            // check if negative needs to be updated
            if( sum > negativeClose ) {
                prev_left = left;       // !!!: keep track of left index
                prev_right = right;     // !!!: keep track of right index
                negativeClose = sum;    // !!!: at this sum
            }
            // increment i, in order to reduce the difference, close to 0
            left++;
        }
        else {
            // means sum is Zero, that is the closest to zero we can get, return 0
            pair[0] = numbers[left];
            pair[1] = numbers[right];
            return pair;
        }
    }
    
    //printf("My findMinSumPair(): BigO(count) = %d \n", count);
    // target (zero) sum not found, return closest 2 numbers to Zero
    pair[0] = numbers[prev_left];
    pair[1] = numbers[prev_right];
    
    return pair;
}

// from: https://tutorialhorizon.com/algorithms/find-two-elements-whose-sum-is-closest-to-zero/
// retuns sum as int
int onePair_Closest_toZero_3(vector<int> numbers)
{
     // 1) sort numbers first
    sort( numbers.begin(), numbers.end() );

    int left = 0;
    int right = static_cast<int>(numbers.size() - 1);
    int positiveClose = INT_MAX;
    int negativeClose = INT_MIN;
    
    while( left < right ) {
        // 2) add 2 numbers, 1 from left and 1 from right
        int sum = numbers[left] + numbers[right];
        // check if sum is greater than 0
        if( sum == 0) {
            // means sum is 0, that is the closest to zero we can get, return 0
            return sum; // or, return 0
        }
        else if( sum > 0 ) {
            // check if positiveClose needs to be updated
            if( sum < positiveClose ) {
                positiveClose = sum;
            }
            // decrement right, in order to reduce the difference, close to 0
            right--;
        }
        else {  // ekse if( sum < 0 ) {
            // check if negative needs to be updated
            if( negativeClose < sum ) {
                negativeClose = sum;
            }
            // increment i, in order to reduce the difference, close to 0
            left++;
        }
    }
    
    //printf("My findMinSumPair(): BigO(count) = %d \n", count);
        
    // check the least absolute value in postiveClose and negativeClose
    /*  !!!: Note: I thought the output is 2147483648,at least ,it should be positive value.
        but When compile and run the code ,the output is :-2147483648.  */
    if( negativeClose == INT_MIN ) {
        return positiveClose;
    }
    if( positiveClose == INT_MAX ) {
        return negativeClose;
    }

    return std::min( abs(positiveClose), abs(negativeClose) );
}

// Objective: Given an array of integers, find the sum of any three elements which is closest to zero.
// The array may contain positive and negative elements.
// Time Complexity: O(N2)
/* 1) Sort the given array in ascending order.
   2) Initialize sum = 0, positiveClose = INTEGER_MAXIMUM, negativeClose = INTEGER_MINIMUM.
   3) Use two loops.
   4) Fix the element using the outer loop. Call it first
        1. sum = first element.
        2. Inside the inner loop, take two pointers, second and third.
           second at the next element to the first element and third at the last element in the array.
           Do sum = sum + second + third
        3. Now if sum = 0, return 0.
        4. Else if sum > 0 , do positiveClose = minimum(positiveClose, sum)
        5. Else do negativeClose = maximum(negativeClose, sum)
   5) If abs(negativeClose)<positiveClose return negativeClose else return positiveClose.
 !!!: WOW, a greate algorithem. still O(N^2)
*/
int find_3Sum_Closest_toZero(vector<int> a)
{
    int positiveClose = INT_MAX;
    int negativeClose = INT_MIN;

    int size = static_cast<int>(a.size());
    if( size < 3 ) {
         cout << "Invalid input";
         return positiveClose;
    }

    // 1) first, sort the array in ascending order
    sort(a.begin(), a.end());

    for( int i = 0; i < size ; i++ ) {
        //int n = a[i];
        int j = i+1;
        int k = size-1;

        while( j < k ) {
            //cout << "sum = " << sum << ": " << a[i] << ", " << a[j] << ", " << a[k] << endl;
            int sum = a[i] + a[j] + a[k];
            
            if( sum == 0 ) {
                return 0;
            }
            else if( sum > 0 ) {
                positiveClose = std::min(sum, positiveClose);
                k--;
            }
            else {
                negativeClose = std::max(sum, negativeClose);
                j++;
            }
        }
    }
    
    if( negativeClose == INT_MIN ) {
        return positiveClose;
    }
    if( positiveClose == INT_MAX ) {
        return negativeClose;
    }

    return std::min( abs(positiveClose), abs(negativeClose) );

    /*if( abs(negativeClose) < positiveClose ) {
        return negativeClose;
    }
    return positiveClose;*/
     
 }

/* threeSum()
     Medium Difficulty
     Given an integer array nums, return all the triplets "[nums[i], nums[j], nums[k]]" such that "i!=j, i!=k, and j!=k",
     and nums[i] + nums[j] + nums[k] == 0.

     Notice that the solution set must not contain duplicate triplets.

     Example 1:
     Input: nums = [-1,0,1,2,-1,-4]
     Output: [[-1,-1,2],[-1,0,1]]
     
     Example 2:
     Input: nums = []
     Output: []
     
     Example 3:
     Input: nums = [0]
     Output: []

     Constraints:
     0 <= nums.length <= 3000
     -105 <= nums[i] <= 105
*/
vector<vector<int>> find_3Sum_Equal_toZero(vector<int>& nums) {
    // !!!: nums = {-1, 0, 1, 2, -1, -4} => [-1, 0, 1] [-1, 2, -1]
    int sum = 0;
    size_t size = nums.size();
    //vector<vector<int>> result(3, vector<int>(3, 0)); // Not good practice, size shouldn't br hardcoded
    vector<vector<int>>   matrix; // Not good practice, size shouldn't br hardcoded
    int row = 0;
    
    int i = 0, j =0, k = 0;
    for( i = 0; i < size-1; i++ ) {
        for(j = i + 1; j < size-1; j++) {
            sum = nums[i] + nums[j];
            for( k = j+1; k < size; k++) {
                int totalsum = sum + nums[k];
                if(totalsum == 0) {
                    matrix.resize(row+1);   // Add new a row
                    matrix[row].push_back(nums[i]);
                    matrix[row].push_back(nums[j]);
                    matrix[row].push_back(nums[k]);
                    row++;
                }
            }
        }
    }
    
    return matrix;
}

/*  Given a UNSORTED integer array arr, two integers k and x, return the k closest integers to x in the array.
    The result should also be sorted in ascending order.

    !!!: An integer a is closer to x than an integer b if:
         |a - x| <  |b - x|, or
         |a - x| == |b - x| and a < b

    Example 1:
    Input: arr = [1,2,3,4,5], k = 4, target = 3
    Output: [1,2,3,4]
    
    Example 2:
    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]
*/
/*  Runtime: 64 ms, faster than 34.04% of C++ online submissions for Find K Closest Elements.
    Memory Usage: 37.9 MB, less than 5.09% of C++ online submissions for Find K Closest Elements.
*/
// !!!: Has issue with {0, 1, 1, 1, 2, 3, 6, 7, 8, 9}, K=0, target= 7. Correctly returns None, not 7.
// Algorithm: Usingg extra space, map<,>. too complicated
// !!!: TOO COMPLICATED
vector<int> kClosest_toTarget_1( vector<int> numbers, int k, int target )
{
    vector<int> closestKelements;

    // Zero OR negative elements requested OR. Ignor it, just return empty result vector
    unsigned long size = numbers.size();
    if(k <=0 || k > size) {
        cout << "\t Kelements = " << k  << " Can't be Zero, or Greater or Less than " << size << endl;
        return       vector<int> ()  ;    // Return empty closestKelements vector
    }

    // 1) first, sort the array in ascending order
    sort( numbers.begin(), numbers.end() );

    // Bail out eralier, if Target is not in array. No need to sort firstKelements and lastKelements as they alrady sorted
    if( target < numbers[0] ) {
        // Target not in array and less than min element, therefore, retuen fist K elements in array
        vector<int> firstKelements(numbers.begin(), numbers.begin()+k);
        return firstKelements;
    }
    else if( target > numbers[size-1] ) {
        // Target not in array and greater than max element, therefore, retuen last K elements in array
        vector<int> lastKelements(numbers.end()-k, numbers.end());
        return lastKelements;
    }

    // Hard work starts here: Target in Range of array elements, but not neccarray in array
    // <key=array[i], index>
    map<int         , int      > map1;
    // 1. Put all elements of array in map
    for(int i=0; i<size; i++) {
        map1[numbers[i]] = i;
    }
    
    // 2. Find index of Target to start looking left and right from its index, and Set left and right indecies accordingly
    int left = 0, right = 0;
    // Is Target in map?
    if( map1.find(target) == map1.end() ) {
        // Target NOT in map, therefore, NOT in array. Create left and right indecies accordingly
        int idx = 0;
        while(numbers[idx++] < target) { /* HEER: Take advantage of binary seach */};
        idx--;
        left  = idx - 1;    // !!!: Key Point
        right = idx;
    }
    else {
        // Target IN map, therefore, IN array. Set left and right indecies accordingly
        left  = map1[target] - 1;
        right = map1[target] + 1;
        closestKelements.push_back(target);    // This is a requirement
        k--;
    }

    // Look for closest K elements to target
    while( (left >= 0 || right < size) && k>0 ) {
        if( left >=0 && right < size ) {
            if( abs(numbers[left] - target) <= abs(numbers[right] - target) ) {
                closestKelements.push_back(numbers[left--]);
            }
            else {
                closestKelements.push_back(numbers[right++]);
            }
        }
        else if(left < 0) {
            // Copy remaining elements from right to end of arr
            closestKelements.push_back(numbers[right++]);
        }
        else { // right > size
            // Copy remaining elements from left to start of arr
            closestKelements.push_back(numbers[left--]);
        }
        
        k--;
    }

    sort(closestKelements.begin(), closestKelements.end());
    return closestKelements;
}

// !!!: my implementation: completed 08/06/2023 √√√√√√√√√. BRELIENT
// !!!: Much beter than closestElementsToTarget1(). 1) No extra space used. 2) Using Binay Search to find targer first.
vector<int> kClosest_toTarget_2( vector<int> numbers, int k, int target)
{
    if( k <= 0 || k > numbers.size() ) {
        cout << "\t Kelements = " << k  << " Can't be Zero, or Greater or Less than " << numbers.size() << endl;
        return       vector<int> ()  ;    // Return empty closestKelements vector
    }

    vector<int> closestKelements;   // Start with empty closest Kelements vector

    int left = 0;
    int right = static_cast<int>(numbers.size() - 1);
    int mid = 0;

    // 1) first, sort the array in ascending order
    sort( numbers.begin(), numbers.end() );

    // !!!: 1) Binary Search for target, or closest to target
    while( left <= right )   // !!!: Notice: 'left < righy' Not 'left <= right'
    {
        mid = (left + right) / 2;
        if( numbers[mid] == target )
            break; // target Found in array
        
        if(numbers[mid] > target)
            right = mid - 1;
        else
            left  = mid + 1;
    }

    // has target been found in array?
    if( numbers[mid] != target ) {
        // target not found in array, pick the smallest of left and right distance to target
        // and assign its index to mid
        if( abs(numbers[left]  - target) < abs(numbers[right] - target) ) {
            mid = left;
        }
        else if( abs(numbers[right] - target) < abs(numbers[left]  - target) ) {
            mid = right;
        }
        else {// !!!: do i need the else statment???
            // left_dist_to_target == right_dist_to_target = mid
            // mid = left;
        }
    }
    
    // target or closest to target is at mid
    closestKelements.push_back( numbers[mid] );
    int count = 1;

    int size = right;
    left = mid - 1; right = mid + 1;
    while( count < k ) {
        if( left >= 0 && right <= size ) {
            if( abs(numbers[left]  - target) <= abs(numbers[right] - target) ) {
                closestKelements.push_back( numbers[left--] );
            }
            else if( abs(numbers[left]  - target) > abs(numbers[right] - target) ) {
                closestKelements.push_back( numbers[right++] );
            }
        }
        else if( left < 0 ) {
            // reached left end, add the number at right to kelements array.
            closestKelements.push_back( numbers[right++] );
        }
        else {  // else if( right > size ) {
            closestKelements.push_back( numbers[left--] );
        }
        
        count++;
     }
    
    sort( closestKelements.begin(), closestKelements.end() );
    
    return closestKelements;
}

// returns the indecies to kelements in numbers[]
// !!!: My Solution: Best in my opinion √√√√√. O(N) using multimap<,>
vector<int> kClosest_toTarget_3( vector<int> numbers, int k, int target )
{
    unsigned long size = numbers.size();
    if( k <= 0 || k > numbers.size() ) {
        cout << "\t Kelements = " << k  << " Can't be Zero, or Greater or Less than " << size << endl;
        return vector<int> ()  ;    // Return empty closestKelements vector
    }
    
    // 1) map absulte distance to target at a location
    std::multimap<int, int> distance_map;
            
    for( int index=0; index < size; ++index ) {
        distance_map.insert( std::make_pair( abs( numbers[index] - target), index ) );
    }
    
    int index = 0;
    vector<int> closestKelements( k );
    std::multimap<int, int>::iterator itr = distance_map.begin();
    while( index < k && itr != distance_map.end() ) {
        //closestKelements[index] = itr->second;                // returns index to a number in numbers
        closestKelements[index++] = numbers[itr++->second];     // returns values of at numbers[index]
    }
    
    sort( closestKelements.begin(), closestKelements.end() );
    return closestKelements;
}

/*  Find K closest Element using Heap: https://www.geeksforgeeks.org/find-k-closest-numbers-in-an-unsorted-array/
    An efficient approach is to use a max heap data structure of size K.
    Find the absolute difference of the array elements with X and push them in the heap.
    If at any position the heap gets filled then only push elements when it has an absolute
    difference less than the first element of the max heap.   */
vector<int> kClosest_toTarget_4( vector<int> numbers, int target, int k )
{
    size_t size = numbers.size();
    // Make a max heap of difference with first k elements.
    //              pair<diff, location>
    priority_queue< pair<int , int> > pq;
    
    // !!!: build max heap with pairs: key = k number-to-target difference, and value = index:
    for( int index = 0; index < k; index++ ) {
        pq.push( { abs(numbers[index] - target), index } );
    }

    // Now process remaining elements.
    for (int i = k; i < size; i++) {
        
        int diff = abs(numbers[i] - target);

        // If difference with current element is more than root, then ignore it.
        if (diff > pq.top().first)
            continue;

        // Else remove root and insert
        pq.pop();
        pq.push( { diff, i } );
    }

    // Print contents of heap.
    vector<int> closestKelements;
    while( pq.empty() == false ) {
        closestKelements.push_back( numbers[pq.top().second] );
        pq.pop();
    }
    
    sort( closestKelements.begin(), closestKelements.end() );
    return closestKelements;
}

// https://www.techiedelight.com/find-k-closest-elements-to-given-value-array/
//  Function to find the `k` closest elements to `target` in a SORTED integer vector `input`
/*  Given a SORTED integer array, find the k closest elements to target in the array where k and target
    are given positive integers. The target may or may not be present in the input array. If target is less
    than or equal to the first element in the input array, return first k elements. Similarly, if target is
    more than or equal to the last element in the input array, return the last k elements. The returned
    elements should be in the same order as present in the input array. */
// !!!: Works for SORTED arrays ONLY.
vector<int> kClosest_toTarget_5(vector<int> const &input, int target, int k)
{
    // find the insertion point using the binary search algorithm: 
    int i = lower_bound(input.begin(), input.end(), target) - input.begin();
 
    int left = i - 1;
    int right = i;
 
    // run `k` times
    while (k-- > 0)
    {
        // compare the elements on both sides of the insertion point `i`
        // to get the first `k` closest elements
        if (left < 0 || (right < input.size() &&
                abs(input[left] - target) > abs(input[right] - target))) {
            right++;
        }
        else {
            left--;
        }
    }
 
    // return `k` closest elements
    return vector<int>(input.begin() + left + 1, input.begin() + right);
}


// !!!: //////////////      Find a Subarray with a Given Sum      /////////////////////
//
/* https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&curated[]=1&sortBy=submissions
   Given an UNSORTED array A of size N that contains only "NON-NEGATIVE" integers, find a continuous sub-array
   which adds to a given number S. The task is to complete the function subarraySum() which takes arr, N and S
   as input parameters and returns a list containing the STARTING and ENDING positions of the First such
   occurring subarray from the left where sum equals to S. The two indexes in the list should be according
   to 1-BASED indexing. !!!: If no such subarray is found, return an array consisting only one element that is -1
 */
// !!!: Briliant Algoritm by me √√√
vector<int> subarraySum(vector<int> array, long long targetsum)
{
    vector<int> result;  // return an array containing start and end idicies for max sum

    int size = (int )array.size();
    if(size == 0 || targetsum < 1) {
        result.push_back(-1);
        return result;
    }
    
    int left  = 0;
    int right = 0;
    int sum   = 0;

    while( right < size ) {
        // 1) sum less than target sum
        if( sum < targetsum ) {
            sum += array[right];    // add to sum at right
            right++;
        }
        
        // 2) sum greater than target sum
        if( sum > targetsum ) {
            sum -= array[left];     // subtract from sum at left
            left++;
        }
        
        // 3) sum equal to target sum
        // target sum is found, bail out and return. if this was first in the loop, while loop would be while(end <= size)
        if( sum == targetsum ) {
            result.push_back(left);         // start
            result.push_back(right - 1);    // end
            return result;
        }
    }
     
    // If no such subarray is found, return an array consisting only one element that is -1.
    result.push_back(-1);
    return result;
}



/*  Given an integer array nums (0-indexed) and two integers: target and start,
    find an index i such that nums[i] == target and abs(i - start) is minimized.
    Return abs(i - start). It is guaranteed that target exists in nums.*/
int Find_MinDistance_toTarget_fromStart(vector<int>& numbers, int target, int start) {
    unsigned long int size = numbers.size();
    int left = 0;
    int right = 0;

    // 1) look left from start to find target
    for( left=start; left >= 0 && numbers[left] != target; left-- ) {}
    // At this point, ethir left < 0, Or numbers[left] == target, Or Both
    
    // 2) look right from start to find target
    for( right=start; right < size && numbers[right] != target; right++ ) {}
    // At this point, right>=size, Or numbers[right] == target, Or Both

    // !!!: You do not need this code, if it is guaranteed that target is in numbers[]
    if( left < 0 && right >= size ) {
        // No target Found. left and right are out of bound
        return -1;
    }
    
    // From here on, at least one target should be Found
    if( left >= 0 && right < size ) {
        // Found 2 targets on left and right from start, return closer distance to target
        return ( abs(left - start) < abs(right - start) )? abs(left - start): abs(right - start);
    }
    else if(left < 0) {     // && right<size not needed
        // Found 1 target and it is not on left of start, return right distance to target
        return abs(right - start);
    }
    else { // if(right > size).  && left>=0 not needed
        // Found 1 target and it is not on right of start, return left distance to target
        return abs(left - start);
    }
}

/* GforG: Given an array A of n POSITIVE numbers. The task is to find the first Equilibium Point in the array.
 Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.*/

// Find a point in array where sum left of pint is equal to sum right of point
// left->........point....<-right
//     3 2 11 5 5 6 8 12
int PivoitPoint_1( vector<int> numbers )
{
    int len = static_cast<int>( numbers.size() );
    int left = 1;                         // left  points to second number in array
    int right = (len - 1) - 1;            // right points to number before last in array
    int leftSum = numbers[0];             // start with sum1 equals first number in array
    int rightSum = numbers[len -1];       // start with sum2 equals last  number in array

    // 1) add numbers from left to right in leftsum, add numbers from right to left in rightsum.
    while( left < right ) {
        if( leftSum < rightSum ) {
            leftSum += numbers[left++];   // leftsum < rightsum, add left number to leftsum
        }
        else {
            rightSum += numbers[right--]; // rightsum < leftsum, add right number to rightsum
        }
    }
    
    // 2) at this point, both left and right SHOULD be equal: left = right.
    // !!!: NOT necessarly true! corner case {5, 5}, left = 1, right = 0
    if( leftSum == rightSum ) {     // && left == right
        cout << "\tFound Equal_Sum of " << leftSum << " at pivot point: left = right " << left << endl;
        return left;    // or, return right
    }
    else {
        //cout << "Equal_Sum found at location " << left;
        cout << "\t\tCouldn't find Equal-Sum. \n" << "\t\tTo make Equal-Sum of " << ((leftSum < right)? leftSum : rightSum) << ", insert " << abs(leftSum - rightSum);
        
        cout << " in the " << (leftSum < rightSum ? "left" : "right") << " sub-array " << "at pivot point " << ((leftSum < rightSum)? left : right+1) << endl;
        
        return -1;
    }
}

// works for positive numbers but not negative numbers
int PivoitPoint_2(vector<int> array)
{
    int len = static_cast<int>( array.size() );
    if(len < 3)
        return -1;
        
    int left  = 1;
    int right = (len - 1) - 1;
    int leftSum  = array[0];
    int rightSum  = array[len -1];

    while( left < right ) {
        // don't add zeros, just advance left or right
        if( array[left] == 0 ) {
            left++;
            continue;
        }
        else if( array[right] == 0 ) {
            right--;
            continue;
        }
                
        if (leftSum < rightSum) {
            leftSum += array[left++];
        }
        else if (leftSum > rightSum) {
            rightSum += array[right--];
        }
        else {
            leftSum += array[left++];
            rightSum += array[right--];
        }
     }

    cout << "\t\tleftSum  = " << leftSum  << " at " << "leftLocation  = " << left << ", and\n"
         << "\t\trightSum = " << rightSum <<  " at rightLocation = " << right ;

    //&& left == right
    return (leftSum == rightSum )? left : -1;     // both left and right would work, since left = right at this point???
}

// works for positive and negative numbers. similar to version 1
int PivoitPoint_3( vector<int> array )
{
    int len = static_cast<int>( array.size() );
    int left = 1;                               // left  points to second number in array
    int right = (len - 1) - 1;                  // right points to number before last in array
    int leftSum = array[0];                     // start with sum1 equals first number in array
    int rightSum = array[len -1];               // start with sum2 equals last  number in array

    while( left < right ) {
        // !!!: order of following statements execution is very important!!!
        if( abs(leftSum) < abs(rightSum) ) {    // !!!: NOTICE: abs()
                leftSum += array[left++];
        }
        else {
            rightSum += array[right--];
        }
    }

    if( leftSum == rightSum ) { // && right == left
        cout << "\t\tleftSum  = " << leftSum  << " at " << "leftLocation  = " << left << ", and\n"
             << "\t\trightSum = " << rightSum <<  " at rightLocation = " << right ;
        return left;
    }
    
    cout << "\t\tCould not Find equal sum";
    return -1;
}

// not tested
// Optimized method to find the equilibrium index of an array
#include <numeric>
void findEquilibriumIndex_Optomized (vector<int> array )
{
    int size = static_cast<int>(array.size());
    // `total` stores the sum of all the array elements
    //int total = std::accumulate(A, A + n, 0);
    int total = std::accumulate( array.begin(), array.end(), 0);

    // `right` stores the sum of elements of subarray `A[i+1…n)`
    int right_sum = 0;
 
    // traverse the array from right to left
    for (int right = size-1; right >= 0; right--)
    {
        /* `i` is an equilibrium index if the sum of elements of subarray `A[0…i-1]`
           is equal to the sum of elements of the subarray `A[i+1…n)` i.e.
           `(A[0] + A[1] + … + A[i-1])` = `(A[i+1] + A[i+2] + … + A[n-1])` */
 
        // sum of elements of the left subarray `A[0…i-1]` is `total - (A[i] + right)`
        int left_sum = total - (array[right] + right_sum);
        if( right_sum == left_sum ) {
            cout << "   Result: Equilibrium Index found " << right << endl;
            cout << "\t\tleftSum  = " << left_sum  << " at " << "leftLocation  = " << right << ", and\n"
                 << "\t\trightSum = " << right_sum <<  " at rightLocation = " << right ;
        }
 
        // new right is `A[i] + (A[i+1] + A[i+2] + … + A[n-1])`
        right_sum += array[right];
    }
}

int Find_Where_TheyMeet_On_Circle(int N, int runner1Step, int runner2Step)
{
    int curstepK1 = 0;   //, runner1 at 0 step;
    int curstepK2 = 0;   //, runner2 at 0 step;
    int result = 0;
    
    // !!!: Loop forever until they meet, and they will always meet
    while(true) {
        int runner1 = (curstepK1 + runner1Step) % N;     // Also runner1/runner2 = k1/k2;
        int runner2 = (curstepK2 + runner2Step) % N;
        
        if(runner1 == runner2) {
            cout << "They meet after runner1 completes " << curstepK1+runner1Step << " steps" << " (" << (curstepK1+runner1Step)/N << " turns and " << (curstepK1+runner1Step)%N << " steps)" << endl;
            cout << "They meet after runne2 completes " << curstepK2+runner2Step << " steps" << " (" << (curstepK2+runner2Step)/N << " turns and " << (curstepK2+runner2Step)%N << " steps)" << endl;
            return runner1; // or, return runner2;
        }
        curstepK1 += runner1Step;
        curstepK2 += runner2Step;
    }
}

// O(N). returns the last written location in number[]
int Remove_Duplicates_ExtraSpace(int* number, int length)
{
    // Better solution:
    set<int> setOfNumbers;
    
    int writeLocation = 0;

    for(int i=0; i < length; i++)
    {
        // find number in set of numbers
        if( setOfNumbers.find(number[i]) == setOfNumbers.end() )
        {
            // number is Not in set, add it to set, and
            setOfNumbers.insert(number[i]);
            
            // write number to number[] at the write location
            number[writeLocation++] = number[i];
        }
    }
    
    return writeLocation;
}

// O(N2)
void Remove_Duplicates_NoExtraSpace(string& str)
{
    //if (str == NULL) return;
    int size = static_cast<int> (str.size());
    if(size < 2) {
        return;
    }
    
    int writeLocation = 1;

    for (int i = 1; i < size; ++i)
    {
        int left;
        for(left = 0; left < writeLocation; ++left)  // Or,  for( left = 0; left < writePos && str[i] != str[left]; ++left )
        {
            if (str[i] == str[left])
                break;      // Do nothing, a duplicate is found
        }
        
        if(left == writeLocation)
        {   // No duplicate found in range 0 to writePos, write it to writePos position
            str[writeLocation] = str[i];
            ++writeLocation;
        }
    }
    
    str.resize(writeLocation);
   // str[writePos] = '\0';
}

// !!!: ////////////////////////     Selection Sort     //////////////////////////////
void SelectionSort(int* array, int size)
{
    for (int i = 0; i< size-1; i++)
    {
        // 1) looking right, find index of smallest number
        int small = i;  // Assume ith number is smallest
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[small])
                small = j;
        }
        
        // 2) if smaller number was found, swap it with ith number
        if(small != i)  // Or, if( j < i )
        {
            int temp = array[small];
            array[small] = array[i];
            array[i] = temp;
        }
    }
}

void SelctionSort_Recursively(int* a, int right)
{
   // for (int i = 0; i< size-1; i++)
   //{
    if(right == 1) {
        return;
    }
    
    // 1) looking right from position 1, find largest number, then move it to last pos in a[]
    // {5,4,1,2,6,7,3}
    int maxIndex = 0;
    for( int left = 1; left < right; left++ ) {
        if( a[left] > a[maxIndex] ) {
            maxIndex = left;
        }
    }
    
    // move largest integer to last position:
    // swap last and largest
    int temp = a[maxIndex];         // save largest integer at maxIndex, before overwriting
    a[maxIndex] = a[right-1];        // write last integer to largest value at maxIndex
    a[right-1] = temp;               // write

    // following loop just for testing
    for( int i=0; i<right; i++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");

    SelctionSort_Recursively(a, right-1);
    
    return;
    
        /*if(small != i)  // Or, if( j < i )
        {
            int temp = a[small];
            a[small] = a[i];
            a[i] = temp;
        }*/
  //  }

}



// Counts the number of 2s in a number at d-th digit
//long long int count2sinRangeAtDigit(long long int number, long long int d)
//{
    // Your code goes here
//}
/* Counts the number of '2' digits between 0 and range */
long long int NumberOf2sInRange(long long int range)
{
    // Your code goes here
    long long int count = 0;
    long long int whole = 0;
    for(long long int number = 2; number <= range; number++)
    {
        whole = number;
        while( whole > 0 ) {
            if( whole % 10 == 2 ) {// Remainder of whole number
                count++;
            }
            whole = whole / 10; // Whole number
        }
    }
    return count;
}

// Returning a vector with size = sizea + sizeb
vector<int> Merge2SortedArrays_1(vector<int> a, vector<int> b)
{
    unsigned long sizea = a.size();
    unsigned long sizeb = b.size();
    vector<int> result(sizea + sizeb);
    
    int i = 0, j = 0, k = 0;
    
    while(i < sizea)
    {
        if((j < sizeb) && (b[j] < a[i]))
            result[k++] = b[j++];
        else    // j > sizea OR v2[j] > v1[i] OR both j > sizea AND v2[j] > v1[i]
            result[k++] = a[i++];
    }
    
    //copy remaining of b
    while(j < sizeb)
        result[k++] = b[j++];
    
    return result;
}

//I think this is a better solution and cleaner
vector<int> Merge2SortedArrays_2(vector<int> &a, vector<int> b)
{
    unsigned long sizea = a.size();
    unsigned long sizeb = b.size();
    vector<int> result(sizea + sizeb);
    
    int i = 0, j = 0, k = 0;
    
    while( i < sizea || j < sizeb ) {
        if( i < sizea && j < sizeb ) {
            if( b[j] < a[i] ) {
                result[k++] = b[j++];
            }
            else {
                result[k++] = a[i++];
            }
        }
        else if( i < sizea ) {
            result[k++] = a[i++];
        }
        else { // j < sizeb
            result[k++] = b[j++];
        }
    }
    
    return result;
}

// !!!: ////////////////////     Largest and Smallest K Numbers      //////////////////////////
//
vector<int> Largest_K_Numbers(vector<int> a, int k)
{
    vector<int> result;
    if( k > a.size() ) {
        return  result;;
    }

    set<int> s(a.begin(), a.end());
    
    set<int>::reverse_iterator rit = s.rbegin();

    for( int i=0; rit != s.rend() && i<k; i++, rit++ ){
        result.push_back(*rit);
    }
    
    return result;
}

vector<int> Smallest_K_Numbers_1(vector<int> a, int k)
{
    vector<int> result;
    if( k > a.size() ) {
        return  result;;
    }

    set<int> s(a.begin(), a.end());
    
    set<int>::reverse_iterator rit = s.rend();
    --rit;
    for( int i=1; rit != s.rbegin() && i<k; i++, --rit ){
        result.push_back(*rit);
    }
    result.push_back(*rit);

    return result;
}

vector<int> Smallest_K_Numbers_2(vector<int> array, int k)
{
    vector<int> result;
    if( k > array.size() ) {
        return  result;;
    }

    set<int> s(array.begin(), array.end());
    
    set<int>::iterator rit = s.begin();
    for( int i=0; rit != s.end() && i<k; i++, ++rit ){
        result.push_back(*rit);
    }

    return result;
}

// !!!: ////////////////////     Reverse Integer     //////////////////////////
// My implementation locally. This is silgtly different than everseNumber2()
/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
    Example 1:
     Input: x = 123
     Output: 321
    Example 2:
     Input: x = -123
     Output: -321
    Example 3:
     Input: x = 120
     Output: 21
    Example 4:
     Input: x = 0
     Output: 0
*/
// !!!: My solution. works fine but not for huge numbers => 900000000
int Reverse_Number_1(int n) {
    stack<int> stk;
    int power = 1;
    int result = 0;
    int sign = n<0? -1: 1;
    n = n<0? -n : n;
    
    while(n > 0) {
        stk.push(n%10);
        n /= 10;
    }
    
    int temp = 0;
    while(!stk.empty()) {
        int k = stk.top();
        stk.pop();
        if(power > k * stk.size()) {
            cout << k * power << ",  " << INT_MAX << endl;
        }
        
        result += k * power;
        power *= 10;    //
     }

    return sign * result;
}

int Reverse_Number_2(int n)
{
    int result = 0;
    bool negative = n>0? false: true;
    n = abs(n);
    int max= INT_MAX;
    // 1534236469
    long int digit = 0;
    while(n > 0) {
        // before processing result, check it is not > INT_MAX
        // try: (temp * 10 + n % 10) > INT_MAX)
        if( (digit * 10) > INT_MAX) {    // Note: difference in this line from everseNumber2()
            return 0;
        }
        result = result * 10 + n % 10;  // works like (result <<)
        digit = result;
        n /= 10;
    }
    
    if(negative) {
        result *= -1;
    }

    return result;
}

// from internet, beleive from Leet
int Reverse_Number_3(int number) {
    int rev = 0;
    while (number != 0) {
        int pop = number % 10;
        number /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    
    return rev;
}

// My implementation in LeetCode: Faster according to Leetcode and I agree, since it doesn't use extera space:
// You are here! !!!: Your runtime beats 100.00 % of cpp submissions
int Reverse_Number_MyLeetCode(int n) {
    int result = 0;
    bool negative = n>0? false : true;
    n = abs(n);
    long int prev_digit = 0;
    
    while(n > 0) {
        // before processing result, check it is not > INT_MAX (0xFFFFFFFF = 4294967295)
        // int range = 0x80000000  to 0x7FFFFFFF
        //           = -2147483648 to 2147483647
        //int next_number = (prev_digit * 10 + n % 10);   Warning: Implicit conversion loses integer precision: 'long' to 'int'
        if( (prev_digit * 10 + n % 10) > INT_MAX) {
            return 0;
        }
        
        result = result * 10 + n % 10; // Try result = prev * 10 + n % 10 ???
        prev_digit = result;
        n /= 10;
    }
    
    if(negative) {
        result *= -1;
    }
    
    return result;
}

// !!!: LeetCode: the best solution in terms of execution time. Should return long long
long long ReverseNumber_LeetCode(int n) {
    long long digit =0;
    while(n != 0) {
        digit = digit * 10 + n % 10;
        n = n / 10;
    }

    double index = pow(2, 31);
    if(digit >= -index && digit <= (index-1))
        return digit;
    else
        return 0;
}

// Silly and simple, not worth it, using char[] not int for number
int printReverseLongNumber(void)
{
    #define MAX 1000
    char num[MAX];
    int i = 0;

    printf("Enter any positive integer: ");
    scanf("%s",num);

    while(num[i]){
        // Only numbers are digits accepted
         if(num[i] < 48 || num[i] > 57){
             printf("Invalid integer number");
             return 0;
         }
         i++;
    }

    //printf("Reverse: ");
    int flag = 0;
    for(int j=i-1; j>=0; j--) {
         if(flag==0 &&  num[j] ==48){
         }
         else {
             printf("%c",num[j]);
         }
    }
    
    return 0;
}

// !!!: ////////////////////////////////////////////////////////////////////
// Doesn't work for all cases
int findSmallestKdigitNumberDivisibleByX_1(int n, int k)
{
    int min = static_cast<int>(pow(10, k-1));
    int max = static_cast<int>(pow(10, k));
    while( min < max ) {
        if( min % n == 0 ) {
            return min;
        }
        min += n;
    }
    
    return -1;  // Not found
}

// Works for all cases
int findSmallestKdigitNumberDivisibleByX_2(int number, int Smallest_K_digit)
{
    int min = static_cast<int>( pow(10, Smallest_K_digit-1) );
    /* int result = min;
    while( result < small + n) {
        result += n;
    }*/
    
    // MIN is the result
    if( min % number == 0 )
        return min;
    
    //return (min + n) - (min + n) % n;
    // Or, my solution
    return ((min + number) / number) * number;
}

/* Given a flattened matrix and number of rows and columns, find the sum of maximum row sum and maximum column sum*/
vector<int> flattenedMatrix(vector<int> matrix, int ROWS, int COLS) {
    vector<int> result;
    
    int prevRowSum = 0, curRowSum = 0, maxRowSum = 0;
    // Find maximum row sum
    for(int row=0; row<ROWS; row++) {
        curRowSum = 0;
        for(int col=0; col<COLS; col++) {
            // Current row sum. Notice index into matrix: row*COLS + col
            curRowSum += matrix[row*COLS+col];
            cout << matrix[row*COLS+col] << ", ";
        }
        cout << endl;
        if(curRowSum > prevRowSum) {
            maxRowSum = curRowSum;
        }
    }
    
    result.push_back(maxRowSum);
  
    int prevColSum = 0, curColSum = 0, maxColSum = 0;
    // Notice: traversing columns now. Outer loop now are columns
    for(int col=0; col<COLS; col++) {
        curColSum = 0;
        for(int row=0; row<ROWS; row++) {
            // Current column sum. Notice index into matrix: row*COLS + col
            cout << matrix[row*COLS+col] << ", ";
            curColSum += matrix[row*COLS+col]; // Notice: matrix[j*COLS+i] is different form above loop matrix[i*COLS+j]
        }
        cout << endl;
        if(curColSum > prevColSum) {
            maxColSum = curColSum;
        }
    }
    
    result.push_back(maxColSum);

    return result;
}

// !!!: //////////////      Is Array Contiguous Duplicates Allowed      /////////////////////
//
// using ordered set. slower than next version
bool isArrayContiguous_DuplicatesAllowed1(vector<int> array)
{
    size_t size = array.size();
    if (size == 0)
        return false;
    
    set<int> orderedSet(array.begin(), array.end());   // Copies array to Ordered set
    
    int prev = *orderedSet.begin();                         // first number
    set <int>::iterator curr_itr = ++orderedSet.begin();    // second number
    
    while( curr_itr != orderedSet.end() ) {
        cout << "\tPrevious Value = " << prev <<  endl;
        if( *curr_itr != prev + 1 ) {
            cout << "Missing number: " << prev << endl;
            return false;
        }

        prev = *curr_itr++;
    }

    return true;
}

// !!!: √√√√√√
// !!!: My algorithem. Great solution. It is more effecient. Array must be ordered using ordered set
bool IsArrayaContiguous_DuplicatesAllowed2(vector<int> array)
{
    if (array.size() == 0)
        return false;

    set<int> orderedSet(array.begin(), array.end());    // Copies array to Sorted set
                                                        // Set doesn't allow duplicates
    int minNumber = *orderedSet.begin();              // !!!: Interesting!!!
    int maxNumber  = *orderedSet.rbegin();
    
    return orderedSet.size() == maxNumber - minNumber + 1;
}


// !!!: //////////////      Find Longest Consecutive Numbers      /////////////////////
//
// !!!: Given an integer array find the longest subarray cantaining consequitive numbers.
// eg {4, 5, 34, 33, 32, 11, 10, 31}. Ans is {31,32,33, 34}
vector<int> findLongest_consecutiveNumbers( vector<int> array )
{
    int start = 0;
    int end   = 0;
    int count = 1;  // notice count set to, before even starting iterations
    
    int longestStart = 0;
    int longestEnd   = 0;
    int longestCount = 0;

    // 1) sort array. take advantage of set<int>. It is SORTED set initalized with array, vector<int>
    set<int>                 setIntegers(array.begin(), array.end());
    set<int>::iterator curr_itr = setIntegers.begin();
    int prev = *curr_itr;    // first element in set
    curr_itr++;
    
    set<int>::iterator longestEnd_itr;

    // 2) search the sorted set for consecutive numbers
    //    start with second element in set
    while( curr_itr != setIntegers.end() ) {
        // are numbers consecutive, at this point?
        if( *curr_itr == prev+1 ) {
            // 2.1) yes, consecutive numbers:
            count++;    // increase count
            end++;      // increase end
            //cout << "prev = " << prev << "\tcurr = " << *curr_itr <<  "\tCount = " <<  count << endl;
        }
        else {  //cout << "START = " << start << "\tEND = " << end << endl;
            // no consecutive numbers
            count = 1;  // reset counter to 1
            
            // new and same start & end location
            start = ++end;
        }

        if( count > longestCount ) {
            longestCount = count;
            longestStart = start;
            longestEnd   = end;
            
            longestEnd_itr = curr_itr;
        }
  
        prev = *curr_itr;
        
        curr_itr++;
    }

    //cout << "Start = " << start << "\tend = " << end << endl;
    // cout << *itr  << "  "  << *longestEnd_itr << endl;

    vector<int> result;
    
    // Advance iterator to longestStart index
    curr_itr = setIntegers.begin();
    for( int i=0; i < longestStart; i++ ) {
        curr_itr++;
    }

    // Start copying elements from longestStart index to longestEnd index in set to result array
    for( int i=longestStart; i <= longestEnd; i++, curr_itr++ ) {
        result.push_back(*curr_itr);
    }
       
    return result;
}

// !!!: //////////////      Find Maximum Contiguous SubArray with Max Sum      /////////////////////
//
struct MyException : public std::exception {
    const char * what () const throw ()
    {
        return "Empty array has no nonempty subarrays";
    }
};
// from geeks. returns max sum. !!!: efficent and easiest one to understand
int maxSum_subArray_geeks( const vector<int> array )
{
    int size = (int )array.size();
    if( size == 0 ) {
        throw MyException();
    }
    
    int max_sum  = INT_MIN;  // !!!: MUST start with the lowest negative value
    int curr_sum = 0;
 
    for( int i = 0; i < array.size(); i++ ) {
        // 1) firt, find current sum from prev sum
        curr_sum = curr_sum + array[i];
        
        // 2) if, sum > max sum, save current sum as maximum sum
        if( curr_sum > max_sum ) {
            max_sum = curr_sum;
        }
 
        // 3) if, current sum is negative, reset it to 0. we don't want to keep counts < 0
        else if( curr_sum < 0 ) {    // it can be just "if" statement. it can also be "curr_sum <= 0".
            curr_sum = 0;
        }
    }
    
    // return maximum sum
    return max_sum;
}

// My solution. returns max sum and indexes to start and end of contiguous subarray !!!: Perefect √√√
// !!!: based on findSubArray_with_maxSum_geeks(vector<int> array) above
vector<int> maxSum_subArray_mine( vector<int> array )
{
    size_t size = array.size();
    //"""Find a contiguous subarray with the largest sum."""
    vector<int> result(3);  // result to retuen max_sum, curr_start, curr_end
    
    int maximum_sum = INT_MIN;
    int current_sum = 0;    //

    // start indexes
    int next_start = 0;     // next_start
    int curr_start = 0;     // current_start
    int curr_end   = 0;     // end index
    
    // order is important:
    for( int left=0; left < size; left++ ) {
        // 1) first, find current sum: prev sum + curr number
        current_sum += array[left];

        // 2) if, current sum > max sum:
        if( current_sum > maximum_sum ) {
            // 2.1) save current sum as maximum sum
            maximum_sum = current_sum;
            
            // 2.2) keep the 'prev start' pointing to the 'current start'
            curr_start = next_start;
            curr_end    = left;
        }
        
        // 3) if, current sum is '0' or negative, discard it and start a new sum:
        else if( current_sum  < 0 ) {
            // 3.1) start a new "sum" and a new "start"
            current_sum = 0;
            
            // 3.2) make 'current start' points to the 'next loop-counter': 'i' + 1
            next_start = left + 1;
        }
        
    }
    
    result[0] = maximum_sum;
    result[1] = curr_start;
    result[2] = curr_end;
    return result;
}

// from Wikipedia. returns max sum: !!!: overhead useing max()
int maxSum_subArray_wiki( vector<int> a )
{
   int size = (int )a.size();
   if( size == 0 ) {
       throw MyException();
   }
   
   int max_sum  = INT_MIN;
   int curr_sum = 0;
   
   for( int i=0; i < size; ++i ) {
       curr_sum = max( a[i], curr_sum + a[i] );
       
       max_sum  = max( max_sum, curr_sum );
   }
   
   return max_sum;
}

// !!!: //////////////      Minimum Increments to make Array SORTED Elements Unique      /////////////////////
//
/* Minimum Increments to make all array elements unique.
 Given a SORTED array of integers, Write an algorithm to make all array elements distinct or unique by doing minimum increments.

 Example: Given Input: [2, 2, 3, 5, 6, 6]
 Unique Array: [2, 3, 4, 5, 6, 7], Minimum Increments: 3
 Explanation: Increment 2 to 3, 3 to 4 and 6 to 7.

 Given Input: [1, 1, 1, 1]
 Unique Array: [1, 2, 3, 4], Minimum Increments: 3 */
// using extra space, set<int> Set
int minIncrements_to_uniqueArray_mine( vector<int>& array )
{
    int size = static_cast<int>(array.size());
    if( size == 0 ) {
        return -1;
    }
    
    int min_increments = 0;
    
    set<int> Set;
    // 0) start by inserting first value in Set
    int prev_value = array[0];
    Set.insert( prev_value ) ;

    // do the followings in a loop:
    // notice: starting with 1
    for( int curr_location  = 1; curr_location < size; ++curr_location ) {
        // 1) read current value at current location
        int curr_value = array[curr_location];
        
         // 2) condition: is value at current location in Set?
        if( Set.find( curr_value ) != Set.end() ) {
            // 2.1) YES, found current value in Set, increment prev value and sotre it at current location
            array[curr_location] = prev_value + 1;
            
            // 2.2) keep track of minimum increments
            min_increments++;
        }
        
        // 3) NO, value at current location not in Set, insert it in Set
        Set.insert( array[curr_location] );
        
        // 4) always keep track of previous value, save value at current location to previous vlaue
        prev_value = array[curr_location];
    }
    
    // !!!: returned array[] is unquie
    return min_increments;
}

// from geeks, not using extra space. better than version 1
// notice array is modified inside function
int minIncrements_to_uniqueArray_geek( vector<int>& array )
{
    int size = static_cast<int>(array.size());
    if( size == 0 ) {
        return -1;
    }
    
    int min_increments = 0;
    int prev_value = array[0];
    
    // notice: start with 1
    for( int curr_location = 1; curr_location < size ; curr_location++ ) {
        //
        if( array[curr_location] <= prev_value ) {  // !!!:  notice: <=
            array[curr_location] = prev_value + 1;
            
            min_increments++;
        }
        
        prev_value = array[curr_location];
    }
    
    // !!!: returned array[] is unquie
    return min_increments;
}


// !!!: //////////////      Print Subarrays and Subset(sequence, combination)      /////////////////////
//
// !!!: NOTICE the difference.
// A subset (sequence, combination) is a subset that can be derived from another subset by 0 or more elements,
// without changing the order of the remaining elements.
// For N = 4, there are 15 (2^N -1) subsets ~ 2^N.

// A subarray is a contiguous part of array. An array that is inside another array. Here there are N*(N+1)/2 ~= (N^2)
// non-empty subarrays/substrings, for N=4: 4+3+2+1 = 4*5/2 = 10.

// Subsets:    (1), (2), (3), (4), (1,2), (1,3), (1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4) = 15.
// Subarrays : (1), (2), (3), (4), (1,2),               (2,3),        (3,4), (1,2,3),          (2,3,4),          (1,2,3,4) = 10

// !!!: A string example to differentiate:
// Consider strings “geeksforgeeks” and “gks”. “gks” is a subset of “geeksforgeeks” but not a substring.
// “geeks” is both a subset and subarray. Every subarray is a subsequence. More specifically,
// subset is a generalization of substring.

// !!!: Subarray/Substring. Geeksforgeeks
/* C++ code to generate all possible subarrays/subArrays !!!: Complexity - O(n^3)
 We can run two nested loops, the outer loop picks starting element and inner
 loop considers all elements on right of the picked elements as ending element of subarray.*/
// Prints all subarrays in arr[0..n-1]
void printSubarrays_1( vector<int> array )
{
    // My implenentaion. O(N^2)
    int count = 0;  // Used for Debuging
    int left = 0, right = 0;
    int size = (int )array.size();
    
    while( left < size ) {
        // Print first number
        cout << array[left] << endl;

        right = left + 1;
        while( right < size ) {
            // !!!: Inner loop: simpler and intuitive. My solution as well
            // Print first number
            string str = to_string(array[left]);
            while( right < size ) {
                str +=  " " + to_string(array[right]);
                cout << str << endl;
                right++;
                count++;
            }
        }

        left++;
        count++;
    }
    
    cout << "Number of subarrays = " << count << endl;
}

// !!!: √√√. Much better, faster O(N^2)
void printSubarrays_2( vector<int> array )
{
    size_t length = array.size();
    for( int i=0; i < length; i++ ) {
        
        string str = "";
        for( int j=i; j < length; j++ ) {
            str = str + to_string(array[j]) + " ";
            cout << str << endl;
        }
    }
}

// !!!: Subsets (sequences or combinations). When generating subset, order of elements is not imported. Geeksforgeeks
// Code to generate all possible subsets. Time Complexity O(N * 2^N) = 4 * 2^4 = 64 Proximit iterations.
// Pfoof from code: Exact iterations = maxCount * size = ((2^N) - 1) * N = 15 * 4     = 60 Exact iterations
// (1), (2), (3), (4), (1,2), (1,3), (1,4), (2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4) = 15.
void printSubsets( vector<int> set )
{
    /* !!!: Number of subsets is (2^n -1)*/
    int set_size = (int )set.size();
    //double numberOfSets = pow(2, size);
    double subsets = 1 << set_size;    // faster. N^2 = 4^2 = 16

    // Run from counter 000..1 to 111..1*/
    int subsetCount = 0;   // Number of subsets used for illustration ONLY
    for( int subset = 1; subset < subsets; subset++ )   // 15
    {
        for( int col = 0; col < set_size; col++ )       // 4
        {
            // Check if jth bit in the counter is set. If set then print jth element from arr[]
            if( subset & (1 << col) )
                cout << set[col] << " ";
        }
        cout << endl;
        subsetCount++;
    }
    // !!!: Notice, setCout = numberOfSets - 1
    cout << "Number of subsets = O(2^N - 1) = " << subsetCount  << endl;
    // cout << "Possible Total Iterations in the 2 Nested Loops = " << set_size * subsetCount << endl;
}

// Returns size of new array. !!!: May be should take advantage of sorted array. O(N)
int removeDuplicates_fromSoretedArray( vector<int>& numbers )
{
    int writeIndex = 1;
    int prevnumber = numbers[0];    // first-number

    for(int i=1; i < numbers.size(); i++) {
        // copy only unsorted elements to write position
        if( numbers[i] != prevnumber ) {
            numbers[writeIndex++] = numbers[i];
            prevnumber = numbers[i];         // We have a new first-number
        }
    }
    
    return writeIndex;
}

// !!!: Works beautifully good. Matrix Must have Rows = Cols: NxN
// !!!: it has advantage over Carcking Coding Interview implementation: it does not use offset
void rotateMatrix_90DegCW( vector<vector<int>>& matrix )
{
    int ROWS = (int )matrix.size(), COLS = ROWS;

    int top = 0;
    int left = 0;
    int bottom = ROWS - 1;
    int right  = COLS - 1;
    int layerWidth = COLS - 1;

    // layer = 1....ROW/2
    for( int layer=0; layer < ROWS/2; layer++ ) {
        
        for( int i=0; i < layerWidth; i++ ) {
            
            // First, save top row elements
            int temp1 = matrix[top][left+i];

            // Copy Left column to top row
            matrix[top][left+i] = matrix[bottom-i][left];
            
            // Copy Top row to Right column
            int temp2 = matrix[top+i][right];
            matrix[top+i][right] = temp1;
            
            // Copy Right column to Bottom row
            int temp3 = matrix[bottom][right-i];
            matrix[bottom][right-i] = temp2;
            
            // Copy Bottom row to Left column
            matrix[bottom-i][left] = temp3;
        }
        
        ++top;
        ++left;
        --right;
        --bottom;
        layerWidth -= 2;
    }
}

void rotateMatrix_Left(int** a, int M, int N, int k)
{
    if (k > N) return;

    for( int row = 0; row < M; row++ ) {
        int right = N - 1;
        int rotationleft = 0;

        while( rotationleft < N ) {
            int temp;
            int left = right;
            int prev = a[row][right];    // or [row][left]

            do
            {
                if( (left - k) < 0 )
                    left = left + N;

                temp = a[row][left - k];
                a[row][left - k] = prev;
                prev = temp;

                rotationleft++;

                if( (left - k < 0) )
                    left = left - k + N;
                else
                    left = left - k;

            } while (left != right);
        
            cout << "Number of Loops = " << N - right << endl;
            right--;
        }
    }
    // for k > 1:
    // number of swaps = ROWS (M) * rotateleft (k) * ( COLS / (k + 1) )
    //                   = M * K * COLS/(K+1)
    // for k = 1:      = ROWS * K * (N -1)
    //cout << "number of sawps = "<< numberofswaps << endl;
}


// !!!: Interesting. O(N) using vector<int> as extra space
void rotateArray_Right_1(vector<int>& array, int rotation)
{
    // 1. Copy array to vector<int>
    vector<int> orig_Array(array.begin(), array.end()) ;
    
    for(int orig_Pos = 0; orig_Pos < array.size(); orig_Pos++ ) {
        // formula to map a new position after rotation
        int newPos = (orig_Pos + rotation) % array.size();
        cout << "\tindex = " << orig_Pos << " maps to " << newPos << endl;

        // Copy original number to new location
        array[newPos] = orig_Array[orig_Pos];
    }
}

// !!!: Does not work quite well
void rotateArray_Right_2(vector<int>& numbers, int rotation)
{
    size_t N = numbers.size();
    int i    = 0;
    int from = 0;
    int to   = rotation;
    
    int prev = numbers[0];
    //int curr = a[K];
    while( i< N) {
        // Exchange current and previous.
        int temp = numbers[to];
        numbers[to] = prev;
        prev = temp;
        
        //a[to] = a[from];
        
        //from = (from + K) % N;
        to   = (to + rotation) % N;
        
        //temp = a[to];
        i++;
    }
}

/*  To rotate by one, store arr[0] in a temporary variable temp, move arr[1] to arr[0], arr[2] to arr[1]
    …and finally temp to arr[n-1]
    Let us take the same example arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2
    Rotate arr[] by one 2 times
    We get [2, 3, 4, 5, 6, 7, 1] after first rotation and [ 3, 4, 5, 6, 7, 1, 2] after second rotation.  */
// Time Complexity: O(N*d), Where N is the length of the given array and d is the rotation number.
// Auxiliary Space: O(1) and O(N^2)
void rotateArray_Right_3(vector<int>& a, int rotations)
{
    int N = static_cast<int>(a.size());

    int p = 1111;

    while (p <= rotations) {
        int last = a[0];
        for (int i = 0; i < N - 1; i++) {
            a[i] = a[i + 1];
        }
        a[N - 1] = last;
        p++;
    }
}

// Function to check if two arrays are equal or not.
/* Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
 Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.*/
// Using Map
bool Are_Arrays_Equal_1( vector<int> A, vector<int> B, const size_t N )
{
     map<int, int> B_count_map;
     for( int i : B ) {
         B_count_map[i]++;
     }
     
     //cout << endl << endl;
     for( int i=0; i < N; i++ ) {
         // check if A elemnt is not in B
         //cout << "A[i] = " << A[i] << ", B_count_map " << B_count_map[A[i]] << endl;
         if(B_count_map[A[i]] < 1 ) {
             return false;
         }
         
         B_count_map[A[i]]--;
     }
     
     return true;
}

// Using array. Should be faster than using Map
bool Are_Arrays_Equal_2(vector<int> a, vector<int> b, const size_t N)
{
    int b_count[N];
    for( int i=0; i < N; ++i ) {
        b_count[i] = 0;
    }

    for( int i : b ) {
        b_count[i]++;
    }
    
    for( int i=0; i < N; i++ ) {
        // check if A elemnt is not in B
        if( b_count[a[i]] < 1 ) {
            return false;
        }
        
        b_count[a[i]]--;
    }
    
    return true;
}

// C++ solution. Does not work for repeated integers
// Notice decleration of function from the above one:
bool Are_Arrays_Equal_CPP(array<int, 5> A, array<int, 5> B)
{
    if( A == B ) {
      // arrays contents are the same
        return true;
    } else {
      // not the same
        return false;
    }

}

int Find_First_K_Occurances_of_Element(vector<int> a, int k)
{
    // integer, count
    map<int, int> countMap;
    
    for(int i=0; i<a.size(); i++) {
        
        if( countMap[a[i]] == k - 1 ) {    // Notice: k-1 not k
            return a[i];
        }
        
        countMap[a[i]]++;
        /*
             countMap[array[i]]++;

             if( countMap[array[i]] == k ) {
                 return array[i];
             }
         */

    }
    
    return  -1;
}

/*  The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively.
    All students stand in a Queue. Each student either prefers square or circular sandwiches.
    The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack.
    At each step:
     •    If the student at the front of the Queue prefers the sandwich on the top of the Stack, they will take it and leave the queue.
     •    Otherwise, they will leave it and go to the Queue's end.
    This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
    You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the ith sandwich in the
    stack (i = 0 is the top of the stack) and students[j] is the preference of the j th student in the initial queue
    (j = 0 is the front of the queue). Return the number of students that are unable to eat.
  
 Example 1:
 Input: students = [1,1,0,0], sandwiches = [0,1,0,1] ^ 1,0,0,1 (!!!: Xor is not a good solution, Maybe NOR)
 !!!: Find number of zeros and ones in both students[] and sandwiches[]. If zeros in students[] && zeros in sandwiches[] are equal && If ones in students[] && ones in sandwiches[] are equal, then every student eats his preferred sandwiche.
 Output: 0
 Explanation:
 - Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
 - Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
 - Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
 - Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
 - Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
 - Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
 - Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
 - Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
 Hence all students are able to eat.
 Example 2:
 Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1] ^ 0,1,1,0,0,1
 Output: 3
  
 Constraints:
     •    1 <= students.length, sandwiches.length <= 100
     •    students.length == sandwiches.length
     •    sandwiches[i] is 0 or 1.
     •    students[i] is 0 or 1.
 */
int Count_Students(vector<int>& students, vector<int>& sandwiches) {
        size_t numStudents = students.size();

        int i = 0;
        int j = 0;
        int zerosStudentsCount = 0;
        int onesStudentsCount = 0;
        int zerosSandwichesCount = 0;
        int onesSandwichesCount = 0;

        // Count number of zeros and ones
        for(int i=0; i<numStudents; i++) {
            if(students[i] == 0)
                zerosStudentsCount++;
            else
                onesStudentsCount++;
            
            if(sandwiches[i] == 0)
                zerosSandwichesCount++;
            else
                onesSandwichesCount++;
        }
        
        if(zerosStudentsCount == zerosSandwichesCount &&
           onesStudentsCount == onesSandwichesCount) {
            return 0;
        }
        else {
            int zerosStudentsWithoutSnadwichwes = abs(zerosStudentsCount - zerosSandwichesCount);
            int onesStudentsWithoutSnadwichwes  = abs(onesStudentsCount  - onesSandwichesCount);
            return abs(zerosStudentsWithoutSnadwichwes + onesStudentsWithoutSnadwichwes);
        }
}

/* You are given an array of binary strings strs and two integers m and n. Return the size of the largest subset of strs such that there are at most m '0's and n '1's in the subset.
   A set x is a subset of a set y if all elements of x are also elements of y.
   Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
   Output: 4
   Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
  Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
  {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.*/
int Find_MaxForm(vector<string>& strs, int m, int n) {
    int zerosCount = 0;
    int onesCount = 0;
    int strcCount = 0;
    for(string str : strs) {
        for(char c : str) {
            // A or B
            if(zerosCount > m || onesCount > n) {
                break;
            }
            if(c == '0')
                zerosCount++;
            else
                onesCount++;
        }
        
        // A && B
        if(zerosCount <= m && onesCount <= n) {
            strcCount++;    // if you get here, break statment above is not executed
        }
        
        zerosCount = 0;
        onesCount  = 0;
    }
    
    return strcCount;
}

/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
   The overall run time complexity should be O(log (m+n)). */
double Find_Median_In_SortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = (int)nums1.size();
    int len2 = (int)nums2.size();
    vector<int> vectr(len1 + len2);
    int i = 0, j = 0, k = 0;
    
    // Merge the 2 arrays nums1 and nums2
    while(i < len1 || j < len2) {
        if(i < len1 && j < len2) {
            if(nums1[i] < nums2[j]) {
                vectr[k++] = nums1[i++];
            }
            else {
                vectr[k++] = nums2[j++];
            }
        }
        else if(i < len1) {
            vectr[k++] = nums1[i++];
        }
        else {
            vectr[k++] = nums2[j++];
        }
    }
    
    int l = 0;
    int r = len1 + len2 - 1;
    int m = (l + r)/2;
    //int c = vectr[m];
    //int f = vectr[m+1];
    // Find median for odd and even
    if((vectr.size() % 2) == 1) {
        return vectr[m];
    }
    else {
        return double(vectr[m] + vectr[m+1]) / 2;
    }
}

/* Given an array nums of non-negative integers, return an array consisting of all the even elements of nums,
   followed by all the odd elements of nums. You may return any answer array that satisfies this condition.
   Input: nums = [3,1,2,4]
   Output: [2,4,3,1]
   The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted. */
vector<int> Sort_Array_By_Parity(vector<int>& nums) {
    vector<int> result(nums.size());
    int even_index = 0;
    int odd_index  = 0;
    
    // Find where odd index starts. Even index obviuosely statrs at 0
    for(int i : nums) {
        if((i % 2) == 0) {
            odd_index++;
        }
     }

    // Add elements at Odd and Even indexes
    for(int i : nums) {
        if((i % 2) == 0) {
            result[even_index++] = i;
        }
        else {
            result[odd_index++] = i;
        }
     }

    return result;
}

void move_zeros_to_left(vector<int>& a)
{
    int write_index = static_cast<int>(a.size()) - 1;
    int read_index = write_index;

    while( read_index >= 0 ) {
        if(a[read_index] != 0) {
          a[write_index] = a[read_index];
          write_index--;
        }

        read_index--;
  }

  while(write_index >= 0) {
    a[write_index] = 0;
    write_index--;
  }
}

// The best: vector version
vector<int> ZeroOneTwo3(vector<int> v) {
    vector<int> result(v.size());   // = {0};
    int lastZero = 0;
    int lastOne  = 0;
    unsigned long lastTwo = v.size() - 1;

    // 2,1,0,0,2 -> 0,0,0,0,2 -> 0,1,0,0,2 ->
    for(int i=0; i < v.size(); i++) {
        if(v[i] == 2) {
            result[lastTwo--] = 2;
        }
        else if(v[i] == 1) {
            result[lastOne] = 1;
            lastOne++;
        }
        else {  // v[i] == 0
            // move zero to right place and move 1 right 1 position if you have to
            if(result[lastZero] == 1)  {
                result[lastOne] = 1;
            }
            result[lastZero] = 0;
            lastZero++;
            lastOne++;  // Must be updated here, not in if() above
        }
    }
    
    return result;
}

// The best: string version
string ZeroOneTwo4(string s)
{
    string result ("");
    //result.resize(s.size());        // Very important!!!

    int index0 = 0;                 // Index of last ZERO written to result
    int index1 = 0;                 // Index of last ONE written to result
    unsigned long index2 = s.size() - 1; // Index of last TWO written to result
    
    for(char c : s) {
        if(c == '0') {
            if(result[index0] == '1') {
                result[index1] = '1';
            }
            result[index0] = '0';
            index0++;                // Pay attention to next 2 lines
            index1++;
        }
        if(c == '1') {
            result[index1] = '1';
            index1++;
        }
        if(c == '2') {
            result[index2] = '2';
            index2--;
        }
    }
    
    return result;
}


/* Given a SORTED array of POSITIVE integers. Your task is to rearrange the array elements alternatively
   i.e first element should be max value, second should be min value, third should be second max, fourth
   should be second min and so on.
   Note: Modify the original array itself. Do it WITHOUT using any EXTRA SPACE. You do not have to return anything.
   arr[] = {1,2,3,4,5,6}
   Output: 6 1 5 2 4 3
*/
// No EXTRA SPACE
void Rearrange_Array_Max_Min_Alternatively_1( vector<int>& a )
{
    // {1,2,3,4,5,6}
    int left  = 0;
    int size  = static_cast<int>(a.size());
    int right = size - 1;
    
    while(right > left) {
        // swap
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        
        ++left;
        --right;
    }
    // {6,5,4,3,2,1}

    left = 1;
    right = size - 1;
    while(right > left) {
        int left1  = left;
        int right1 = right;
        while(right1 > left1) {
            int temp = a[left1];
            a[left1] = a[right1];
            a[right1] = temp;
            
            ++left1;
            --right1;
        }
        
        ++left;
    }
    // {6,1,5,2,4,3}
}

// better than version 1. No EXTRA SPACE
void Rearrange_Array_Max_Min_Alternatively_2(vector<int>& array)
{
    int left  = 0;
    int size = static_cast<int>(array.size());
    // last_index is made const on purpose, used for reading only
    const int LAST_INDEX = size - 1;
    //
    int number_of_elements_to_be_rotated_right = size - 1;
    
    while( number_of_elements_to_be_rotated_right > 0 ) {
        
        // rotate array RIGHT one position at a time, from
        // 1) first, save the last (max) number
        const int last = array[LAST_INDEX];
        int max = LAST_INDEX;
        
        int element_to_be_rotated_right = 0;
        while( element_to_be_rotated_right < number_of_elements_to_be_rotated_right ) {
            array[max] = array[max-1];
            --max;
            ++ element_to_be_rotated_right;
        }
        
        array[left] = last;
        
        number_of_elements_to_be_rotated_right -= 2;
        left += 2;
    }
}

/* You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

   You should rearrange the elements of nums such that the modified array follows the given conditions:
   1) Every consecutive pair of integers have opposite signs.
   2) For all integers with the same sign, the order in which they were present in nums is preserved.
   3) The rearranged array begins with a positive integer.
 
   Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
 
   Constraints:
        2 <= nums.length <= 2 * 10 power 5
        nums.length is even
        1 <= |nums[i]| <= 105
        nums consists of equal number of positive and negative integers.
 */
vector<int> Rearrange_Array_Pos_Neg_Alternatively(vector<int>& array)
{
    // {3,1,-2,-5,2,-4}
    int size = static_cast<int>(array.size());
    vector<int> result_array(size);
    int pos_index = 0;   // The rearranged array begins with a positive integer
    int neg_index = 1;
    
    int i = 0;
    while( i < size ) {
        
        if(array[i] > 0) {
            result_array[pos_index] = array[i];
            pos_index += 2;
        }
        
        if(array[i] < 0) {
            result_array[neg_index] = array[i];
            neg_index += 2;
        }
        
        ++i;
    }
    
    return result_array;
}

/* Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
   Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.
   Return any answer array that satisfies this condition.
 */
vector<int> sortArrayByParityII(vector<int>& a)
{
    int size = static_cast<int>(a.size());
    vector<int> result(size);

    int even  = 0;
    int odd   = 1;
    
    int i = 0;
    while( i < size ) {
        if( abs(a[i])%2 == 0 ) {
            result[even] = a[i];
            even += 2;
        }
        if( abs(a[i])%2 == 1 ) {
            result[odd ] = a[i];
            odd  += 2;
        }
        
        ++i;
    }
    
    return result;
}

// Runtime 577 ms Beats 21.85%. Memory 123.3 MB Beats 83.33%
vector<int> pivotArray_1(vector<int>& a, int pivot)
{
    // before: a[7] = {9,12,5,10,14,3,10}
    // after:  a[7] = {9,5,3,10,10,12,14}
    int size = static_cast<int>(a.size());
    vector<int> result(size);
    
    int i = 0;
    int j = 0;
    int pivot_value = 0;
    
    while( i < size ) {
        if( a[i] < pivot ) {
            result[j++] = a[i];
        }
        if( a[i] == pivot) {
            ++pivot_value;
        }
        ++i;
    }
    
    int k = 0;
    while( k < pivot_value) {
        result[j++] = pivot;
        ++k;
    }

    i = 0;
    while( i < size ) {
        if( a[i] > pivot ) {
            result[j++] = a[i];
        }
        ++i;
    }

    return result;
 }

// Runtime 233 ms Beats 91.93%. Memory 127.1 MB Beats 69.42%. Uses extra space: vector<int> grater_values;
vector<int> pivotArray_2(vector<int>& a, int pivot)
{
    int size = static_cast<int>(a.size());
    vector<int> result(size);
    vector<int> grater_values;

    int i = 0;
    int j = 0;
    int pivot_values = 0;
    
    while( i < size ) {
        if( a[i] < pivot ) {
            result[j++] = a[i]; // 1) copy all values less than pviot value, at beging of the result array
        }
        if( a[i] == pivot) {
            ++pivot_values;     // 2) keep track of pivot values coun,t to copy them to the result array later
        }
        if( a[i] > pivot) {     // 3) keep track of values greater than vipot values, to copy them to the result array later
            grater_values.push_back(a[i]);
        }
        ++i;
    }
    
    int k = 0;
    // 4) copy all previousely saved pivot values to the result array
    while( k < pivot_values) {
        result[j++] = pivot;
        ++k;
    }

    // 5) copy all previousely saved values greater than vipot values to the result array
    for(int i: grater_values ) {
            result[j++] = i;
    }

    return result;
 }

/* Given two arrays, write a function to compute their intersection.
 Each element in the result must be unique. The result can be in any order.
 Example Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/
vector<int> intersection_2Arrays(vector<int> a1, vector<int> a2)
{
    vector<int> result;
    
    set<int> set1;
    for( int i1 : a1) {
        set1.insert(i1);
    }
    
    for( int i2 : a2) {
        if( set1.find(i2) != set1.end()) {
            result.push_back(i2);
        }
    }
    
    return result;
}

// Finding the smallest common number in three arrays
int leastCommonNumber(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
    int i = 0, j = 0, k = 0;

    while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {

        if( (arr1[i] == arr2[j]) && (arr2[j] == arr3[k]) )
            return arr1[i];

        // Let's increment the iterator for the smallest value.
        if( arr1[i] <= arr2[j] &&  arr1[i] <= arr3[k] ) {
            i++;
        }

        else if( arr2[j] <= arr1[i] && arr2[j] <= arr3[k] ) {
            j++;
        }

        else if( arr3[k] <= arr1[i] && arr3[k] <= arr2[j] ) {
            k++;
        }
    }
    
  return -1;
}

 

// !!!: ///////     Nondecreasing Array     //////////
/*  !!!: https://tutorialhorizon.com/algorithms/convert-to-non-decreasing-array-with-one-change/
    Given an array of numbers, you need to find out whether an array can be converted to a non-decreasing array,
    where you are allowed to modify the maximum one element in the array.
 
    Non-decreasing array: Array is called a non-decreasing array when you traverse the array from left to right,
    each element on the left is less than equal to the element on the right. So for any element at index i, input[i-1]<=input[i]<=input[i+1].

    Example:
        Input[] = [4, 5, 1, 7]
        Output: true
        Change 1 to 6 or 5 or 7

        Input[] = [10, 5, 2]
        Output: false

        Input: [1, 2, 1, 5]
        Output: true
        Change 2 to 1.

        Input: [1, 1, 1, 1]
        Output: true
        No Change required  */
bool Convert_toNondecreasing_Array_1change_1( vector<int> array)
{
    int size = static_cast<int>(array.size());
    if( size < 3 ) {
        return false;
    }
    
    bool change = false;
    for( int i=1; i < size-1; i++ ) {

        // {7, 6, 5, 1}
        if( array[i-1] > array[i] && array[i] > array[i+1] ) {
            // can't modify one number to make NonDecreasing array
            return false;
        }
        
        // {6, 5, 7, 1} -> {6, 6, 7, 1}
        if( array[i-1] > array[i] && array[i] <= array[i+1] ) {
            if( change == true ) {
                return false;
            }
            array[i] = array[i-1]; // OR: a[i] = a[i+1];
        }

        // {4, 5, 1, 7} -> {4, 5, 5, 7}
        if( array[i-1] <= array[i] && array[i] > array[i+1] ) {
            if( change == true ) {
                return false;
            }
            array[i+1] = array[i];  // Only choice
         }
        
        change = true;
    }
    
    return true;
}

// from ytube. good algorithem
int Convert_to_Nondecreasing_Array_with_one_change_2( vector<int> array )
{
    int size = static_cast<int>(array.size());
    int change = 0;
    
    for( int i=1; i < size && change < 2; i++ ) {
        if( array[i] < array[i-1] ) {
            if( i == 1 || array[i-2] <= array[i] ) {
                array[i-1] = array[i];
             }
            else {
                array[i] = array[i-1];
            }
            change++;
        }
    }
    
    return change <= 1;
}

/*  Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element. */
bool Convert_to_Nondecreasing_Array_with_one_change_3(vector<int>& array)
{
    for( int i = 1, err = 0; i < array.size(); i++ ) {
        if( array[i] < array[i-1] ) {
            if( err++ || (i > 1 && i < array.size() - 1 && array[i-2] > array[i] && array[i+1] < array[i-1]) ) {
                return false;
            }
        }
    }
    
    return true;
}

// !!!: this is almost the same as: Convert_to_Nondecreasing_Array_with_one_change_2( )
int totalSteps_toMake_NonDecreasing_Array( vector<int>& array )
{
    size_t size = array.size();
    int count = 0;
    
    for( int i=1; i < size; i++ ) {
        // only when current number is < previous number, do:
        if( array[i] < array[i-1] ) {
            if( i == 1 || array[i] >= array[i-2] ) {
                array[i-1] = array[i];
            }
            else {
                // array[i] < array[i-2]
                array[i] = array[i-1];
            }
            count++;
        }
        // else do nothing
    }
    
    return count;
}
 
/*  You are given a 0-indexed integer array nums. In one step,
    remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
    Return the number of steps performed until nums becomes a non-decreasing array.

    Example 1:
            Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
            Output: 3
            Explanation: The following are the steps performed:
            - Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
            - Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
            - Step 3: [5,4,7,11,11] becomes [5,7,11,11]
            [5,7,11,11] is a non-decreasing array. Therefore, we return 3.
    Example 2:
            Input: nums = [4,5,7,7,13]
            Output: 0
            Explanation: nums is already a non-decreasing array. Therefore, we return 0
*/
int totalSteps_toMake_nonDecreasing_Array2( vector<int>& array)
{
    size_t size = array.size();
    int count = 0;
    
    for( int i=1, write_index=1; i < size; i++ ) {
        // only when current number is < previous number, do:
        if( array[i] > array[i-1] ) {
            array[write_index++] = array[i];
            count++;
        }
    }
    
    return count;
}

// find odds numbers between low and high numbers
// this algoritherm clearly makes more sense
int CountOdds_1(int low_number, int high_number) {
    int count = 0;
    
    while( low_number <= high_number ) {
        if( low_number & 1 ) {
            // odd number, skip over 1 position to get to the  next odd number
            low_number += 2;
            ++count;
        }
        else {
            // even number, just increment position to get to the next odd number
            ++low_number;
        }
    }
    
    return count;
 }

// Faster than version 1. pay attention to low && high
int countOdds_2(int low_number, int high_number)
{
    // the following 4 conditons exist for low and high numbers:
    // 1) both even, 2) both odd, 3) low=odd && high=even, 4) low=even && high=odd
    if( ((low_number & 1) == 0) && ((high_number & 1) == 0) ) {
        // 1) only when, both low and high are even, use this formaula
         return (high_number - low_number) / 2 ;
     }
     
    // the following 3 remaining conditons exist, use this formaula
    // 2) both odd 3) low=odd && high=even 4) low=even && high=odd
    return (high_number - low_number) / 2 + 1;
}

/*  from ---> https://tutorialhorizon.com/algorithms/check-if-number-is-divisible-by-its-digits/
 Check if Number is divisible by its digits
 Objective: Given a number, write a program to check if the number is divisible by all of its digits separately.

 Example:
 N = 15
 Output: true (15 is divisible by 1 and 5)
 N = 123
 Output: true (123 is divisible by 1, 2 and 3)
 N = 143
 Output: false (143 is not divisible by 4 and 3)
 */
// Taher: consider case where number is 0? should 0/0 accepted as true or false?
//        here, if number = 0 and since number is divisable by its 0 digit (number=0)/(digit=0),
//        i am returing true, prabaly not good assumption!!!
//        if 0 is inside number, retun false
bool isDivisible_byItsDigits( int number )
{
    while( number > 0 ) {
        // 1) find current digit
        int digit = number % 10;
        
        // 2) is number divisable by digit? make sure you don't divide number by 0 digit
        if( digit == 0 || (number % digit) != 0 ) {
            // 2.2) No - A) there is a 0 digit in number. since, you can't divide by 0, therefore return false, or
            //           B) number is not divisable by digit
            return false;
        }
        
        // 2.3) Yes - do nothing, just continue through the loop until number is zero
        number /= 10;
    }
    
    // 3) after prev loop: Yes - number is divisable by all of its digits
    return true;
}

/*
 Monotone Increasing Digits
 Objective: Given a number N, find the LARGEST number which is less than equal to N and has Monotone Increasing Digits.

 Monotone Increasing Digits - If all the pairs (x, y) of adjacent digits satisfy the property, x<=y. In other words if all digits are in ascending order (can have duplicates) then digits are called monotone increasing digits.

 Example:
    391--->389     333--->333      233--->233     432--->399      243--->199      234(sorted)--->234
    N = 324
        Output: 299
    N = 4321
        Output: 3999
    N = 12345. Notice: when N is SORTED, just return N
        Output: 12345
 
 Analysis:
    53421--->? 49999 = 53421 % 10000 = 3421 + 1 = 3422
    result = 53421 - 3422 = 49999
        
 */
int monotoneIncreasingDigits( int number )
{
    // 1 9 5 7:
    // To Do: find when array is out of order, then decrement last digit and all other digits in number 9
    // how many digits in a number???
    vector<int> out_of_order_marks = {false};

    int new_number = 0;
    
    int original_number = number;
    int prev_digit = number % 10;
    number /= 10;
    
    // iterate from first to last digit
    // 391
    int index = 0;   // i could have started from 0
    while( number > 0 ) {
        // start from right digit, search for out of order condition
        int curr_digit = number % 10;
        //index??
        if( curr_digit > prev_digit ) {
            // out of order:
            // make previous digit = 9, and decrement current digit
            prev_digit = 9;
            curr_digit--;
        }
        else {
            // curr_digit <= prev_digit
            out_of_order_marks.push_back(index);
        }
        
        // normal updates at end of each iteration through the loop
        index++;
        prev_digit = curr_digit;
        number /= 10;
    }
    
    return original_number;
}

/*
 Check If Student is eligible for an Attendance Reward
 In school a student gets rewarded if he has an attendance record without being absent for more than once or being late for 3 times continuously.

 Given a student's attendance record represented by a string. The record only contains the following three characters:
     'A' : Absent.
     'L' : Late.
     'O' : On-Time.
     Check whether the student qualifies for the reward.

 Examples:
     Record: "OLLAOOOLLO"
     Output: False
     Explanation: The student does not qualify for a reward because !!!: "LLA" means he was late 3 times in a row.

     Record: "OLLOAOLLO"
     Output: True
 */
bool checkAttendance( string attendance )
{
    int absent_days           = 0;
    int late_consecutive_days = 0;

    enum { OnTime='O', Late='L', Absent='A' };
    
    for( char day : attendance) {

        if( day == Late ) {
            // increment Late count and take action
            late_consecutive_days++;
            if( late_consecutive_days == 3 ) {
                // Action: no rewards, since student was late 3 times in a row,
                cout << "\n\tSorry no rewards is given to Student, because: \n";
                cout << "\tStudent was Late 3 consecutive days";
                return false;
            }
         }

        if( day == OnTime ) {
            // Action: no action is needed, since student was on time
            // we just need to reset the "3 consecutive Late days" rule. therefore, we reset Late count to 0
            late_consecutive_days = 0;
        }
        
        if( day == Absent ) {
            // increment Late count and take action
            absent_days++;
            if( late_consecutive_days == 2 || absent_days > 1 ) {
                // Action:
                cout << "\n\tSorry no rewards is given to Student, because: \n";
                if( absent_days > 1 ) cout << "\tStudent was absent more than once";
                else                  cout << "\tStudent was Late 2 consecutive days and one consecutive Absent.\n";
            
                return false;
            }
            
            // we need to reset the "3 consecutive Late days" rule. therefore, we reset Late count to 0
            late_consecutive_days = 0;
        }
    }
    
    cout << "\n\tPlease give student a REWARD, because of GOOD attendance\n";
    return true;
}

// algorithem: find max number of seats between tow persons and divide it by 2.
//             this should give you max distance from closest person
// !!!: does not work quite well for corner cases
int maxDist_toClosestPerson( vector<int> seats ) {
    size_t seats_size = seats.size();
    size_t last_seat  = seats.size() - 1;
    
    int empty_seats = 0;
    int max_empty_seats = 0;
    
    int last_empty_seats = 0;

    enum { Empty, Occupied };
    
    int cur_seat = 0;
    while( cur_seat < seats_size ) {
        // 1. count empty seats
        if( seats[cur_seat] == Empty ) {
            empty_seats++;
        }
       
        // 2. check max empty seats when current seat is occupied, or current seat is last seat
        if( seats[cur_seat] == Occupied || cur_seat == last_seat ) {
            if( empty_seats > max_empty_seats ) {
                max_empty_seats = empty_seats;
            }
            
            // !!!: pay attention to corner case, where first or last seats are empty.
            //      keep track of last empty seats as we need it later.
            if( cur_seat == last_seat ) {
                last_empty_seats = max_empty_seats;
            }

            empty_seats = 0;
        }

        ++cur_seat;
    }
    
    // !!!: corner case: last seat is empty, return last empty seats
    if( seats[last_seat] == Empty && last_empty_seats == max_empty_seats ) {
        return last_empty_seats;
    }
    else {  // general case:
        return max_empty_seats/2 + ( (max_empty_seats % 2 == 1)? 1: 0 );
    }
}

// https://leetcode.com/problems/maximize-distance-to-closest-person/submissions/
// Runtime Details 11ms Beats 75.48%of users with C++. O(N)
// Memory Details 16.99MB Beats 76.22%of users with C++
int maxDist_toClosestPerson_2( vector<int> seats ) {
    size_t number_of_seats = seats.size();
    size_t last_seat  = number_of_seats - 1;
    
    int empty_seats = 0;
    int first_empty_seats = 0;
    int midle_empty_seats = 0;
    int last_empty_seats = 0;

    enum { Empty, Occupied };
    
    // !!!: pay attention to corner case, where First seats are empty. keep track of last empty seats as we need it later.
    // 1) count the FIRST empty seats and store it for later use
    int cur_seat = 0;
    while( cur_seat < number_of_seats && seats[cur_seat] == Empty ) {
        cur_seat++;
    }
    first_empty_seats = cur_seat;

    empty_seats = 0;
    int prev_occupied =0, curr_occupied = 0;
    // 2) count max middle empty seats
    while( cur_seat < number_of_seats ) {
        // 2.1) count empty seats
        if( seats[cur_seat] == Empty ) {
            empty_seats++;
        }
       
        // 2.2) check max empty seats when current seat is occupied
        if( seats[cur_seat] == Occupied  ) {
            if( empty_seats >= midle_empty_seats ) {
                curr_occupied = prev_occupied;
                prev_occupied = cur_seat;
                cout << "prev occupied = " << curr_occupied << ", curr occupied = " << prev_occupied << endl;
                midle_empty_seats = empty_seats;
            }
            empty_seats = 0;
        }
        ++cur_seat;
    }

    // !!!: pay attention to corner case, where Last seat is empty. keep track of Last empty seats as we need it later.
    if( seats[last_seat] == Empty ) {
        last_empty_seats = empty_seats;
    }

    // if max empty middle seats is odd, add 1
    midle_empty_seats = midle_empty_seats/2 + ( (midle_empty_seats % 2 == 1)? 1: 0 );
    
    if( first_empty_seats >= midle_empty_seats && first_empty_seats >= last_empty_seats ) {
        cout << "Sit in the First seat";
        return first_empty_seats;
    }
    if( last_empty_seats >= midle_empty_seats && last_empty_seats >= first_empty_seats ) {
        cout << "Sit in the LAST seat";
        return last_empty_seats;
    }
    cout << "Sit in a middle seat. between seat " << curr_occupied << " and seat " << prev_occupied
         << ", at seat number = " <<  curr_occupied + midle_empty_seats ;
    return midle_empty_seats;
}


bool Find_Number_In_SortedMatrix(int a[][3], int ROWS, int COLS, int target)
{
    int row = 0;;
    int col = COLS - 1;

    while( row < ROWS && col >= 0 ) {
        if (target == a[row][col])
            return true;
        if (target > a[row][col])
            row++;
        else    // target < a[row][col]
            col--;
    }

    return false;
}

void setsOfSum(unsigned int* a, int len, int sum )
{
    map<int, int> mapsums;
    int i = 0, j = 0, count = 0;
    
    while( i < len - 1 && count < sum/2)
    {
        if( a[i] < sum && mapsums.find(a[i]) == mapsums.end())
        {
            j = i + 1;
            while( j < len)
            {
                 if( mapsums.find(a[i]) == mapsums.end() )
                   
                    j++;
            }
            
        }
        
    }
}

int LCSD(int* a, int n)
{
    int res = 1;
    for(int i=0; i < n; i++)
    {
        int j = i+1;
        for(; j < n; j++)
        {
            if( (a[j] % a[i]) != 0)
            {
                return 1;
            }
        }
        if(j == n)
            return a[i];
        
    }
    
    return res;
};

int myPartition(int* xa, int xlen)
{
    int a[] = {1, 5, 3, 0, 4, 2, 6, 7, 9, 8};
    int len = 10;

    int left = 1;
    int right = len - 1;
    int pivot = a[0];
    
    while(left < right)
    {
        if(a[left] > pivot && a[right] < pivot)
        {
            // swap a[i] and a[store]
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
        
        if(a[left] < pivot)
            left++;
            
        if(a[right] > pivot)
            right--;
    }
    
    int temp = a[0];
    a[0] = a[right];
    a[right] = temp;
    
    return pivot;
}


int Partition(int* a, int len)
{
    int left = 0;
    int right = len - 1;
    int store = left;
    
    for(int i=left; i <right; i++)
    {
        if(a[i] <= a[right])
        {
            // swap a[i] and a[store]
            int temp = a[i];
            a[i] = a[store];
            a[store] = temp;
            
            store++;
        }
    }

    // swap a[store] and a[right]
    int temp = a[store];
    a[store] = a[right];
    a[right] = temp;

    return store;
}


