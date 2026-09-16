# Left View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the  **root** of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

 **Note:**  If the tree is empty, return an empty list.

 **Examples :** 

```
Input: root = [1, 2, 3, 4, 5, N, N] 
 
Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

```

```
Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-16T17:50:39.297Z  

```cpp
/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
private:
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(root-> data);
        }
        solve(root-> left, ans, level+1);
        solve(root-> right, ans, level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)