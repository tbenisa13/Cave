//
//  Algorithms.hpp
//  Practice1
//
//  Created by Taher Benisa on 9/2/21.
//  Copyright © 2021 taher benisa. All rights reserved.
//

#ifndef Algorithms_hpp
#define Algorithms_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include "Vectors.hpp"

/*  Depth First Traversal (or Search) for a graph is similar to Depth First Traversal (DFS) of a tree.
    The only catch here is, unlike trees, graphs may contain cycles, so a node might be visited twice.
    To avoid processing a node more than once, use a boolean visited array.
Solution:
    Approach: Depth-first search is an algorithm for traversing or searching tree or graph data structures.
    The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph)
    and explores as far as possible along each branch before backtracking. So the basic idea is to start from the
    root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until
    there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them.
    Finally print the nodes in the path.
    The only difference between iterative DFS and recursive DFS is that the recursive stack is replaced by a stack of nodes.
Algorithm:
    Created a stack of nodes and visited array.
    Insert the root in the stack.
    Run a loop till the stack is not empty.
    Pop the element from the stack and print the element.
    For every adjacent and unvisited node of current node, mark the node and insert it in the stack.
    Implementation of Iterative DFS: This is similar to BFS, the only difference is queue is replaced by stack.*/

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V; // No. of vertices
    std::list<int> *adj; // adjacency lists
    
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int s); // prints all vertices in DFS manner
    // from a given source.
};

/*  https://tutorialhorizon.com/algorithms/dynamic-programming-minimum-cost-for-climbing-stairs/
    Dynamic Programming - Minimum Cost for Climbing Stairs
    Given the staircase and cost for each stair. Once you pay the cost at a step you can climb one or two stairs.
    Yor are allowed to start from any of the first two stairs. Your task is to reach to the top of the staircase
    by paying the minimum cost.

Example:
         costs = [10, 12, 14, 20, 7]
         minimum cost = 31
         10 -- 14 -- 7

         costs = [10, 1, 1, 15, 2, 30, 3]
         minimum cost = 7
         1 -- 1-- 2 -- 3
 
Approach:
    1) Recursion:
        If you look closely, for each stage you have two options,whether to take one stair or two stairs.
        So you will try out all the options at every stage and will pick the minimum out of it. The problem
        is time complexity will be very high - O(2n).

    2) Dynamic Programming: Bottom-up:
        Initialize dp[] as the same length as the cost array. dp[i] will represent the minimum cost required
        to reach the ith index and it will be calculated as:
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]): !!!: similar to Fabanacci
        Base case would be dp[0] = cost[0] and dp[1] = cost[1].
        Time Complexity: O(N)   */

int minCost_iter1( std::vector<int> cost );
int minCost_iter2( std::vector<int> cost );

#endif /* Algorithms_hpp */
