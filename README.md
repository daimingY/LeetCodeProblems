# LeetCodeProblems
**Note:** All problem descriptions are inside the corresponding problem folder.
## Algorithms
- Add Two Numbers
- Longest Substring Without Repeating Characters
- Median of Two Sorted Arrays
  - Linear solution actually runs better than d&c solution
- Longest Palindromic Substring
  - O(n^2) runtime with O(1) space
- ZigZag Conversion
- Reverse Integer
- String to Integer (atoi)
- Regular Expression Matching
  - DP solution
- Contain with Most Water
- Integer to Roman Number
- 3 Sums
- 3 Sum Closest
- Letter Combinations of A Phone Number
- 4 Sums
- Remove Nth From End
- Generate Parentheses
  - Solved with Backtracing, recursion method
- Merge K Sorted Lists
- Swap Nodes in Pairs
- Divide
- Next Permutation
- Reverse Nodes in k-Group
- Search in Rotated Sorted Array
  - Divide and Conquer
- Search for a Range
- Substring with Concatenation of All Words
- Longest Valid Parentheses
  - Using stack to get substring answers
  - 1-D Dynamic Programming solution didn't run as fast as stack
- Jump Game II
  - Using BFS to implement Greedy Algorithm.
- Valid Sudoku
  - Using Backtracking
- Sudoku Solver
  - Using Backtracking
- Combination Sum
- Combination Sum II
- Multiply Strings
- First Missing Positive
  - Though the array is given unsorted, linear runtime possible by swaping numbers into correct places
- Permutations
  - Using Backtracking
- Permutations II
  - Using Backtracking
- Rotate Image
  - Greedy Algorithm, O(1) space, O(n^2) runtime, as input size being a n^2 square matrix
- Group Anagrams
  - Using sort and hash map, achieve O(nklogk). Note: n is number of words, k is max length of a word.
- Pow(x,n)
  - O(log(n)), linear runtime, as n passed in as a number value, and considering multiplication as O(1).
- Wildcard Matching
  - DP solution, O(mn)
- N-Queens
  - Use Backtracking with information stored in 1-D Array
- N-Queens II
  - Same as above, except return the total number
- Spiral Matrix
  - Linear Runtime
- Jump Game
  - Linear Runtime at each position to push the farthest reachable index, and then check whether the last index is reachable. Minimum steps not required.
- Merge Intervals
- Spiral Matrix II
- Permutation Sequence
- Rotate List
- Unique Paths
  - Dynamic Programming solution. O(m * n) runtime, O(min(m, n)) space complexity.
- Unique Paths II
  - DP solution, considering obstacles.
- Minimum Path Sum
  - DP solution
- Valid Numbers
- Insert Interval
- Simply Path
- Set Matrix Zeroes
- Search a 2D Matrix
- Sort Colors
