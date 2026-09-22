# Validate Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the `root` of a binary tree,  *determine if it is a valid binary search tree (BST)*.

A  **valid BST**  is defined as follows:

- The left subtree of a node contains only nodes with keys strictly less than the node's key.
- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

 

 **Example 1:** 

```
Input: root = [2,1,3]
Output: true

```

 **Example 2:** 

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 104].
- -231 <= Node.val <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 22 MB (beats 15.90%)  
**Submitted:** 2026-09-22T15:37:12.284Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;

        inorder(root-> left, ans);
        ans.push_back(root-> val);
        inorder(root-> right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        
        inorder(root, ans);
        int n = ans.size();

        bool flag = true;
        for(int i=0; i < n-1; i++){
            if(ans[i] > ans[i+1] || ans[i] == ans[i+1]){
                flag = false;
            }
            
        }
        return flag;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/validate-binary-search-tree/)