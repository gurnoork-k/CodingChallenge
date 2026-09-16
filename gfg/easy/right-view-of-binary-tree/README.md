# Right View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the **root** of a binary Tree. Return the  **right view**  of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the  **right** side.

 **Examples :** 

```
Input: root = [1, 2, 3, N, N, 4, 5]
     
Output: [1, 3, 5]

```

```
Input: root = [1, 2, 3, 4, N, N, N, N, 5]
     
Output: [1, 3, 4, 5]
```

```
Input: root = [3]    
  
Output: [3]
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-16T17:36:21.516Z  

```cpp
/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private: 
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }

        if(level == ans.size()){
            ans.push_back(root-> data);
        }
        solve(root-> right, ans, level+1);
        solve(root-> left, ans, level+1);
        
    }
    
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }

};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)