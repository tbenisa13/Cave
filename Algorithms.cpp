//
//  Algorithms.cpp
//  Practice1
//
//  Created by Taher Benisa on 9/2/21.
//  Copyright © 2021 taher benisa. All rights reserved.
//

#include "Algorithms.hpp"
using std::string;
using std::cout;
using std::vector;
using std::map;
using std::list;
using std::stack;
using std::min;
//using std::set;



/* Exit Point in a Matrix
 Problem statement:
 
 Given a matrix with 0's and 1's, one enters the matrix at cell (0, 0) in left to right direction. Whenever one encounters a 0 he retains in the same direction, if one encounters a 1 he has to change direction to the right of current direction and change that 1 value to 0. Write a programming out from which index he will leave the matrix at the end. (Indexing starts from 0).

 Input: An mxn matrix with each element 0 or 1

 Output: Exit cell index pair (i, j) where is the row no & j is the column no

 Example & discussion

 Let's consider a 3x3 matrix of each element 0/1.
 matrix: 0 1 1
         0 0 0
         1 0 1
 
 Given that:
 Starting position is (0, 0).
 Starting moving direction is left to right (rightwards).
 Whenever current element value is 0, it retains its direction.
 Whenever current element value is 1, it changes direction to right of current moving directions.
 Moving directions can be of four types
 Leftwards
 Rightwards
 Downwards
 Upwards
 Whenever current element value is 0, moving directions becomes like
 Leftwards → leftwards
 Rightwards → rightwards
 Upwards → upwards
 Downwards → downwards
 Whenever current element value is 1, moving directions becomes like
 Leftwards → upwards (changing to right direction)
 Rightwards → downwards (changing to right direction)
 Upwards → rightwards (changing to right direction)
 Downwards → leftwards (changing to right direction)
 Current element value: 1 → 0*/

// Works good
vector<int> Find_ExitPoint_In_Matrix(vector<vector<int>> matrrix /* 2D array*/) {
    vector<int> result(2, -1);  // -1 indicates no exit from matrix exists (thsis should never happens)
    
    enum movingdir {MovingRight, MovingLeft, MovingUp, MovingDown};
    movingdir direction = MovingRight;
    
    int row=0, col=0;   // Used to traverse through matrrix
    int left = 0, right  = static_cast<int>(matrrix[0].size()) - 1; // Number of cols - 1
    int top  = 0, bottom = static_cast<int>(matrrix.size()) - 1;    // Number of rows - 1
    
    // determine row & col for next move
    while(row >= top && row <= bottom && col >= left && col <= right) {
        // 0 - Going straight
        // Determine next row & col
        // Notice: We don't need to determine previous Direction here, since we are staying in the same direction.
        if(matrrix[row][col] == 0) {
            switch (direction) {
                case MovingRight:
                    col++;
                    break;
                case MovingLeft:
                    col--;
                    break;
                case MovingUp:
                    row--;
                    break;
                case MovingDown:
                    row++;
                    break;
                default:
                    break;
            }
         }
        
        // 1 - Turning right
        // Determine next row & col
        // Notice: We do need to determine previous Direction here, since We are turning right.
        else if(matrrix[row][col] == 1) {
            switch (direction) {
                case MovingRight: row++;
                                  direction = MovingDown;
                                  break;
                case MovingLeft:  row--;
                                  direction = MovingUp;
                                  break;
                case MovingUp:    col++;
                                  direction = MovingRight;
                                  break;
                case MovingDown:  col--;
                                  direction = MovingLeft;
                                  break;
                default:
                                  break;
            }
        }
    }
    
    if(row < top) {
        result[0] = top; // Exit point: row
        result[1] = col; // Exit point: col
    }
    else if(row >= bottom) {
        result[0] = bottom;
        result[1] = col;
    }
    else if(col < left) {
        result[0] = row;
        result[1] = left;

    }
    else if(col >= right) {
        result[0] = row;
        result[1] = right;
    }
    //result[0] = ((row < top)   || (row >= bottom))? --row : row ;
    //result[1] = ((col < left)  || (col >= right))? --col : col ;
    
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|||||||||||||||||||||||||||||

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
 Accepted
 1,417,728
 Submissions
 4,879,850
 Se*/
vector<vector<int>> threeSum_Equal_To_Zero(vector<int>& nums) {
    // !!!: nums = {-1, 0, 1, 2, -1, -4} => [-1, 0, 1] [-1, 2, -1]
    int sum = 0;
    size_t size = nums.size();
    vector<vector<int>>   result; // Size unkown at point
    int row = 0;
    
    if(size < 3) {
        return result;
    }
    
    for(int i = 0; i < size-1; i++) {
        for(int j = i + 1; j < size-1; j++) {
            sum = nums[i] + nums[j];
            for(int k = j+1; k < size; k++) {
                bool conditonTrue = i!=j && i!=k && j!=k;
                //cout << conditonTrue << endl;
                int totalsum = sum + nums[k];
                if(totalsum == 0 && conditonTrue) { // Don't need to check conditonTrue, it is always TRUE
                    result.resize(row+1);   // Add new a row
                    result[row].resize(3);  // Add new a col
                    result[row][0] = nums[i];
                    result[row][1] = nums[j];
                    result[row][2] = nums[k];
                    row++;
                }
            }
        }
    }
    
    return result;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    // !!!: nums = {-1, 0, 1, 2, -1, -4} => [-1, 0, 1] [-1, 2, -1]
    int sum = 0;
    size_t size = nums.size();
    //vector<vector<int>> result(3, vector<int>(3, 0)); // Not good practice, size shouldn't br hardcoded
    vector<vector<int>>   result; // Not good practice, size shouldn't br hardcoded
    int row = 0;
    
    int i = 0, j =0, k = 0;
    for(i = 0; i < size-1; i++) {
        for(j = i + 1; j < size-1; j++) {
            sum = nums[i] + nums[j];
            for( k = j+1; k < size; k++) {
                int totalsum = sum + nums[k];
                if(totalsum == 0) {
                    result.resize(row+1);   // Add new a row
                    result[row].push_back(nums[i]);
                    result[row].push_back(nums[j]);
                    result[row].push_back(nums[k]);
                    row++;
                }
            }
        }
    }
    
    return result;
}

vector<vector<int>> threeSum3(vector<int>& nums) {
    // !!!: nums = {-1, 0, 1, 2, -1, -4} => [-1, 0, 1] [-1, 2, -1]

    int sum = 0;
    size_t size = nums.size();
    //vector<vector<int>> result(3, vector<int>(3, 0)); // Not good practice, size shouldn't br hardcoded
    vector<vector<int>>   result; // Not good practice, size shouldn't br hardcoded
    // < key=sum, vector<int>=values>
    map<vector<int>, int> sum2map;
    // <Sum, i>
    map<int, int> map1;
    // <Sum, j>
    map<int, int> map2;
    int colIndex = 2;   // Tracks i and j of 2 sum
    
    int sum2index = 0;
    int i = 0, j =0, k = 0;
    int min = 0;

    int row = 0, col = 0;

    for(i = 0; i < size; i++) {
        map1[nums[i]] = i;
    }
    for(i = 0; i < size; i++) {
        map2[nums[i]] = i;
    }
            
    for(i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            int sum2 = nums[i] + nums[j];
            if(nums[k] == sum2 ) {
                ;
            };
            /*int sum2 = nums[i] + nums[i * colIndex + j % colIndex];
             map1[i] = sum2;*/
            //map1[i * colIndex + j % colIndex] = sum2;  // j = i + 1
        j++;
        }
    }
    
    /*sum2index = 0;
    for( k = 0; k < size; k++) {
        int totalsum = sum2map[sum2index] + nums[k];
        if(totalsum == 0) {
            result.resize(min+1);
            result[min].push_back(nums[i]);
            result[min].push_back(nums[j]);
            result[min].push_back(nums[k]);
            min++;
        }
        sum2index++;
    }*/

    return result;
}
/*
 Input: n = 19
 Output: true
 Explanation:
 1*1 + 9*9 = 82
 8*8 + 2*2 = 68
 6*6 + 8*8 = 100
 1*1 + 0*0 + 0*0 = 1
 */
/*
 Input: n = 18
 Output: false
 Explanation:
 1*1 + 8*8 = 65
 5*5 + 6*6 = 61
 6*6 + 1*1 = 37
 3*3 + 7*7 = 58
 5*5 + 8*8 = 89
 ..............
 */
bool isHappy(int n) {
    int whole = n;

    while(whole) {
        int sum = 0;
        while(whole) {
            int remainder = whole%10;
            sum += remainder * remainder;
            whole /= 10;
        }
        if(sum == 1) {
            return true;
        }
        if(sum == 4) {  // or 89, 145
            return false;
        }
        whole = sum;
    }

    return false;
}


// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// prints all not yet visited vertices reachable from s
void Graph::DFS(int s)
{
    // Initially mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a stack for DFS
    stack<int> stack;

    // Push the current source node.
    stack.push(s);

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        int s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

/*  Example:
        costs = [10, 12, 14, 20, 7]
        minimum cost = 31
        10 -- 14 -- 7

        costs = [10, 1, 1, 15, 2, 30, 3]
        minimum cost = 7
        1 -- 1-- 2 -- 3    */
int minCost_iter1( vector<int> cost )
{
     size_t len = cost.size();
     vector<int>  dp( len );
     dp[0] = cost[0];
     dp[1] = cost[1];

     for (int i = 2; i < len ; i++) {
         dp[i]  = min( dp[i-1], dp[i-2] ) + cost[i];
     }

     int result = min( dp[len-1], dp[len-2] );
    
     return result;
}

// !!!: My idea based on Fabaincci algorithem i have developed before.
// !!!: more efficient than version 1, no array is needed, instead just need
// !!!: 2 variables first and second to hold the last 2 costs.
int minCost_iter2( vector<int> cost )
{
     size_t len = cost.size();
     int first  = cost[0];
     int second = cost[1];

    int result = 0;
    for (int i = 2; i < len ; i++) {
        result = min( first, second ) + cost[i];
        first = second;
        second = result;
     }
    
     return result;
}


