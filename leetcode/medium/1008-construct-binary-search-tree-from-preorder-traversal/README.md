# Construct Binary Search Tree from Preorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers preorder, which represents the  **preorder traversal**  of a BST (i.e.,  **binary search tree**), construct the tree and return  *its root*.

It is  **guaranteed**  that there is always possible to find a binary search tree with the given requirements for the given test cases.

A  **binary search tree**  is a binary tree where for every node, any descendant of `Node.left` has a value  **strictly less than**  `Node.val`, and any descendant of `Node.right` has a value  **strictly greater than**  `Node.val`.

A  **preorder traversal**  of a binary tree displays the value of the node first, then traverses `Node.left`, then traverses `Node.right`.

 

 **Example 1:** 

```
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

```

 **Example 2:** 

```
Input: preorder = [1,3]
Output: [1,null,3]

```

 

 **Constraints:** 

- 1 <= preorder.length <= 100
- 1 <= preorder[i] <= 1000
- All the values of preorder are unique.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.5 MB (beats 20.71%)  
**Submitted:** 2026-09-23T18:33:37.920Z  

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
    TreeNode* solve(vector<int>& pre, int mini, int maxi, int &i ){
        if(i>= pre.size()){
            return NULL;
        }
        if(pre[i] < mini || pre[i] > maxi){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[i++]);
        root-> left = solve(pre, mini, root-> val, i);
        root-> right = solve(pre, root-> val, maxi, i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i =0;
        return solve(preorder, mini, maxi, i);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)