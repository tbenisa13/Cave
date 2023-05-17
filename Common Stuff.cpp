//
//  Common Stuff.cpp
//  Practice1
//
//  Created by Taher Benisa on 7/29/21.
//  Copyright © 2021 taher benisa. All rights reserved.
//

#include "Common Stuff.hpp"

using std::string;
using std::cin;
using std::cout;
using std::list;
using std::vector;
using std::array;
using std::stack;
using std::endl;
using std::istream;
using std::ostream;

// Easy
int deleteValue(vector<int>& array, int value)
{
    //if(nums.empty())
      //  return 0;
    
    int writeindex = 0;
    
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] != value) {
            array[writeindex++] = array[i];
        }
    }
    
    array.resize(writeindex);    //nums[writeindex] = '\0';
    
    return writeindex;
}

// N number of houses to rob. you can not rob adjacent houses.
// K amount of money in each house
int maximizeMoney_robbingHouses(int houses , int amount)
{
    // houses % 2, tells you if number of houses is even or odd
    // you always can robb houses/2. plus, if houses is odd you can do one more robbrey
    int number_of_houses_that_canBe_robbed = houses / 2 + houses % 2;
    return number_of_houses_that_canBe_robbed * amount;
}

// O(2N). traversing string twice
char GetMaxOccuringChar_1(char* str)
{
    // Create array to keep the count of individual characters and initialize the array to 0
    int count[256] = { 0 };

    // Construct letter count array from the input string
    size_t  len = strlen(str);
    for (int i = 0; i<len; i++)
        count[ str[i] ]++;        // str[i] resolves to an int. str[i] = A = 41

    int maxcount = 0;      // Initialize max count, consider maxcount = -1
    char result = 0;        // Initialize result

    // Traversing through the string looking for max count in count array
    for (int i = 0; i < len; i++) {
        if (count[str[i]] > maxcount) {
            maxcount = count[str[i]];
            result = str[i];
        }
    }

    return result;
}

// !!!: better than above function. O(N)
char GetMaxOccuringChar_2(char* str)
{
    // Create array to keep the count of individual characters and initialize the array to 0
    int count[256] = { 0 };

    int maxcount = 0;       // Initialize max count
    char result = 0;        // Initialize result

    // Construct letter count array from the input string
    size_t  len = strlen(str);
    for (int i = 0; i<len; i++) {
        count[str[i]]++;
        if (count[str[i]] > maxcount) {     // or, if (count[str[i]] >= maxcount)
            maxcount = count[str[i]];
            result = str[i];
        }
    }

    return result;
}

//  Given a sorted array containing only numbers 0 and 1, the task is to find the transition point efficiently. The transition point is the point where “0” ends and “1” begins.
//  A transition point is the index of the first ‘1’ appearing in the array.
int transitionPoint_SortedArray_1( vector<int> a ) {
    size_t size = a.size();
    int i = 0;
    bool one = true;   // important to start with 1
    
    while( i < size ) {
        // the order of 'if' statements is important here
        if( !one && a[i] == 1 ) {
            return i;   //  a transition is found, return index of this '1'
        }
        
        // handle 0
        if( a[i] == 0 ) {
            one = false;
        }
        
        // handle 1
        if( a[i] == 1 ) {
            one = true;
        }

        i++;
    }
    
    return -1;
}

/* Given an array of sorted numbers containing only 0s and 1s, find the transition point.
   A transition point is the index of the first ‘1’ appearing in the array*/
// !!!: taken advantage of SORTED array. O(log n)
int transitionPoint_SortedArray_2( vector<int> array )
{
    int size = static_cast<int>(array.size());
    int left  = 0;
    int right = size - 1;
    
    while( left <= right ) {
        int mid  = (left + right) / 2;
        
        // handle 0
        if( array[mid] == 0 ) {
            left = mid + 1;     // go right
        }
        
        // handle 1
        if( array[mid] == 1 )  {
            // corner case first:
            if( mid == 0 ) {
                return -1;      // reached left end and no transition was found: all 11111s
            }
            
            // is 0 is left of this 1
            if ( array[mid-1] == 0 ) {
                return  mid;    // yes, found a transition. return middle index
            }

            right = mid - 1;    // no, go left
        }
    }
    
   return -1;                   // no transitions: all 0s, or all 1s
}

// O(ROWS * COLUMNS)
/*   1 1 1 1 1 1 1 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 1 1 1 1 1 1 1
 */
// brillent
void create_pattern_1( int ROWS, int COLMUNS )
{
    for( int row = 1; row <= ROWS; row++ ) {
      for( int col = 1; col <= COLMUNS; col++ ) {
          // If element is in first/last row or first/last column
         if (row == 1 || row == ROWS || col == 1 || col == COLMUNS) {
            cout << " 1";
         } else {
            cout << " 0";
         }
      }
      cout << "\n";
    }

    return;
}

// O(ROWS * COLUMNS)
/*   1 1 1 1 1 1 1 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 0 0 0 0 0 0 1
     1 1 1 1 1 1 1 1
 */
void create_pattern_2 (int rows, int cols)
{
    string pattern1;    // all ones row: "111111", printed at fisrt and last rows
    for( int i=0; i<cols-1; ++i ) {
        pattern1 += "1 ";
    }
    pattern1 += "1";
    
    string pattern2 = "1 ";
    for( int i=1; i<cols-1; ++i ) {
        pattern2 += "0 ";
    }
    pattern2 += "1";
    
    for( int row=0; row<rows; ++row ) {
        if( row == 0 || row == rows-1 ) {
            cout << pattern1;
        }
        else {
            cout << pattern2;
        }
        cout << endl;
    }
}

// rows must be equal to columns
void create_pattern_Diagonally (int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {          // If element is in first/last row or first/last column
         if( col >= row ) {
            cout << " 1";
         } else {
            cout << " 0";
         }
      }
      cout << "\n";
    }

    return;

}

void create_pattern_Diagonally_Recursuvilly (int rows, int cols)
{
    if(rows == 0) {
        return;
    }
    
    static int i = 0;

    for (int col=0; col < cols; col++) {          // If element is in first/last row or first/last column
         if( col >= i ) {
            cout << " 1";
         } else {
            cout << " 0";
         }
      }
      cout << "\n";
    
    i++;
    
   create_pattern_Diagonally_Recursuvilly (rows-1, cols);
}


int getLastKthElement(list<int> list, int kthToLast)
{
    if( kthToLast >= list.size() ) {
        cout << "\nThis an error" << endl;
    }
    
    int kth = 0;
    stack<int> stak;
    
    for(int i : list) {
        stak.push(i);
    }
    
    while(kthToLast >= 0 && !stak.empty()) {
        kth = stak.top();
        stak.pop();
        --kthToLast;
    }
    
    return kth;
}


// !!!: /////////////////////   NumberOfPaths   ///////////////////////////
// Returns count of possible paths to reach cell at row number M and column number N from the topmost leftmost cell (cell at 1, 1)
/* The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move only to RIGHT or DOWN.
    The time complexity of above recursive solution is exponential. There are many overlapping subproblems
 */
// better than numberOfPaths_recursively2(). no helper function
long long  numberOfPaths_recursively1(int row, int col)
{
    static int counter = 0;
    // If either given row number is first or given column number is first
    // !!!: If we hit last row (1), we don't need to go right to reach END. The path to END is open and therefore, a path is found.
    if(row == 1 || col == 1) {
        //cout << "row = " << row << ", col = " << col << ", counter = " << ++counter << endl;
        return 1;   // One path is Found, return 1
    }
    
    // If diagonal movements are allowed then the last addition is required.
    // Go DOWN (LEFT)
    long long downPath   = numberOfPaths_recursively1( row - 1, col );
    // Go RIGHT
    long long rightPath  = numberOfPaths_recursively1( row, col - 1 );
    // Go DIAGONALLy
    // long long diagonalPath =  numberOfPaths(row-1, col-1);

    // Finally, return total paths: add leftpaths and rightpaths and rightlPath if requried
    return rightPath + downPath; // + diagonalPath;
}

// !!!: Helper function for My Solution.
// Still numberOfPaths_recursively1() is better, no helper function is needed
static int ROWS;
static int COLS;
// Very similar to numberOfPathsRecursive1()
long long numberOfPaths_recursively2(int row, int col)
{
    ROWS = row;
    COLS = col;
    return numberOfPathsMysolution( 0, 0 );
}

// It is similar to post order traversal for BST
long long numberOfPathsMysolution(int row, int col)
{
    static int counter = 0; // for troubleshooting only

    if( row == ROWS-1 || col == COLS-1 ) {
        cout << "  Path FOUND row = " << row << ", col = " << col << ", counter = " << ++counter << endl;
        return 1;   // One path is Found, return 1
    }
    
    // Go DOWN (LEFT)
    cout << "Going DOWN,  row = " << row << ", col = " << col << ", counter = " << counter << endl;
    long long downPath   = numberOfPathsMysolution( row + 1, col );
    // Go RIGHT
    cout << "Going RIGHT, row = " << row << ", col = " << col << ", counter = " << counter << endl;
    long long rightlPath = numberOfPathsMysolution( row, col + 1 );

    return rightlPath + downPath;
}

// !!!: Recursive + Dynamic Programming solution. Not practical to ask user to supply paths[4][4]. Should have a helper function for user and have helperFunction(row, col) call numberOfPathsRecursiveX()
// !!!: The following implementation is based on the (Top-Down) approach. (DFS)
// Returns count of possible paths to reach cell at row number m and column number n from the topmost leftmost cell (cell at 1, 1)
int numberOfPathsRecursiveX(int row, int col, int paths[4][4])
{
    if(row == 1 || col == 1)
        return paths[row][col] = 1;
     
    // Add the element in the DP table, If it is was not computed before
    if(paths[row-1][col-1] == 0) {
        cout << "Path = " << paths[row-1][col-1] << endl;
        paths[row][col] = numberOfPathsRecursiveX(row - 1, col, paths) + numberOfPathsRecursiveX(row, col - 1, paths);
        cout <<  "Path = " << paths[row][col] << endl;
    }

    return paths[row][col];
}
 
/* !!!: Iterative Solution
   Returns count of possible paths to reach cell at row number m and column number n from the topmost
   leftmost cell (cell at 1, 1).
   !!!: Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by
   !!!: constructing a temporary array count[][] in (BOTTOM UP) manner using the above recursive formula
 */
int numberOfPaths_iteratively1(int ROWS, int COLS)
{
    int counter = 0;

    // Create a 2D table to store results of subproblems
    int path[ROWS][COLS];
 
    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < ROWS; i++)
        path[i][0] = 1;
 
    // Count of paths to reach any cell in first row is 1
    for( int j = 0; j < COLS; j++ )
        path[0][j] = 1;
 
    // Calculate count of paths for other cells in "bottom-up" manner using the recursive solution
    for( int row = 1; row < ROWS; row++ ) {
        for( int col = 1; col < COLS; col++ ) {
            // By uncommenting the last part the code calculates the total possible paths if the Diagonal Movements are allowed
            path[row][col] = path[row - 1][col] + path[row][col - 1]; //+ count[i-1][j-1];
            counter++;
        }
    }
    
    return path[ROWS - 1][COLS - 1];
}
 
/* !!!: Iterative Solution. Butter than all above functions
   !!!: Time complexity of the above 2 dynamic programming solutions is O(mn).
   !!!: The space complexity of the above 2 solutions is O(mn).
   !!!: Space Optimization of DP solution:
   !!!: Above solution is more intuitive but we can also reduce the space by O(n); where n is column size.*/
// Returns count of possible paths to reach cell at row number m and column number n from
// the topmost leftmost cell (cell at 1, 1)
int numberOfPaths_iteratively2(int ROWS, int COLS)
{
    // Create a 1D array to store results of subproblems
    vector<int> path(COLS, 0); //int path[COLS] = { 0 }; Doesn't work: Variable-sized object may not be initialized
    path[0] = 1;
 
    int counter = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 1; col < COLS; col++) {
            path[col] += path[col - 1];
            counter++;
        }
    }
 
    return path[COLS - 1];
    
    /* !!!: This also works
     vector<int> path(ROWS, 0); //int dp[col] = { 1 }; Doesn't work: Variable-sized object may not be initialized
     path[0] = 1;
  
     int counter = 0;
     for (int col = 0; col < COLS; col++) {
         for (int row = 1; row < ROWS; row++) {
                 path[row] += path[row - 1];
                 counter++;
         }
     }
  
     return path[ROWS - 1];
     */
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
int trappingWater(vector<int>& height)
{
    if(height.empty())
        return 0;
    int ans = 0;
    size_t size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    
    for (int i = 1; i < size; i++) {
        left_max[i] = std::max(height[i], left_max[i - 1]);
    }
    
    right_max[size - 1] = height[size - 1];
    for (size_t i = size - 2; i >= 0; i--) {
        right_max[i] = std::max(height[i], right_max[i + 1]);
    }
    
    for (int i = 1; i < size - 1; i++) {
        ans += std::min(left_max[i], right_max[i]) - height[i];
    }
    
    return ans;
}

void extractDigits(unsigned int num)
{
    //char pointer declaration
    char temp[5];
    //assig number as string in char pointer
    sprintf((char*)temp,"%u",num);
    
    //extract and print each digits
    size_t len = strlen( temp );
    for( int i=0; i<len; i++) {
        printf("%c",temp[i]);
    }
    
    printf("\n");
}

