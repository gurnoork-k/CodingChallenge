# Maximum Non-Adjacent Nodes Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the  **root**  of a binary tree with integer values. Your task is to select a  **subset of nodes**  such that the sum of their values is  **maximized**, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its  **parent**  nor its  **children**  can be included.

 **Examples:** 

```
Input: root = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

```

```
Input: root = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5 and 6, which are not directly connected to each other. Their total sum is 16.  

```

 **Constraints:** 
1 ≤ number of nodes ≤ 104
1 ≤ node.data ≤ 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-17T16:59:36.550Z  

```cpp
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
private:
    pair<int, int> solve(Node* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = solve(root-> left);
        pair<int, int> right = solve(root-> right);
        
        pair<int, int> res;
        res.first = root-> data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        return res;

    }
  public:
    int getMaxSum(Node *root) {
        // code here
         pair<int, int> ans = solve(root);
         return max(ans.first, ans.second);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)