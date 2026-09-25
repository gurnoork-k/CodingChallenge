# Largest BST Subtree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given the  **root**  of a binary tree, find the size of the largest subtree that is also a Binary Search Tree (BST). A subtree is considered a BST if, for every node in the subtree:

- All nodes in its left subtree have values less than the node's value.
- All nodes in its right subtree have values greater than the node's value.
- The subtree contains no duplicate values.

Return the number of nodes in the largest BST subtree.

 **Note:** The size of a subtree is the total number of nodes it contains.

 **Examples :** 

```
Input: root = [5, 2, 4, 1, 3]

Output: 3
Explanation:The following sub-tree is a BST of size 3

```

```
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-25T13:13:50.706Z  

```cpp
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class info{
    public:
        int maxi;
        int mini;
        bool isBst;
        int size;
};

info solve(Node* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max({root->data, left.maxi, right.maxi});
    currNode.mini = min({root->data, left.mini, right.mini});

    if(left.isBst && right.isBst && 
       (root->data > left.maxi && root->data < right.mini)){
        currNode.isBst = true;
    }
    else{
        currNode.isBst = false;
    }

    if(currNode.isBst){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

class Solution {
  public:

    int largestBst(Node *root) {
        int maxSize = 0;
        info temp = solve(root, maxSize);
        return maxSize;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/largest-bst/1)