# Sum of nodes on the longest path

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary tree  **root[]**, you need to find the  **sum** of the nodes on the  **longest path**  from the  **root** to any  **leaf node**. If two or more paths have the same length, the path with the  **maximum** sum of node values should be considered.

 **Examples:** 

```
Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
Output: 13
Explanation:

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
```

```
Input: root[] = [1, 2, 3, 4, 5, 6, 7]

Output: 11
Explanation: 

The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
```

```
Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

Output: 19
Explanation: 

The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
```

 **Constraints:** 
1 <= number of nodes <= 106
0 <= node->data <= 104

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-17T12:13:19.302Z  

```cpp
/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
private:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
        //base case
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum += root-> data;
        solve(root-> left, sum, maxSum, len+1, maxLen);
        solve(root-> right, sum, maxSum, len+1, maxLen);
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int sum = 0;
        int maxSum = INT_MIN;
        
        int len = 0;
        int maxLen = 0;
        
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)