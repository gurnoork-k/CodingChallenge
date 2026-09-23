# Flatten BST to Sorted List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the root of a Binary Search Tree (BST), flatten it into a right-skewed tree such that:

- The left child of every node is NULL.
- The right child points to the next node in the inorder traversal (sorted order) of the BST.

Return the root of the flattened tree.

 **Note:** The flattened tree should contain all the nodes of the original BST, preserving their inorder sequence.

 **Examples:** 

```
Input: root = [5, 3, 7, 2, 4, 6, 8]

Output: [2, N, 3, N, 4, N, 5, N, 6, N, 7, N, 8] 
Explanation: After flattening, the tree looks like this:
     
```

```
Input: root = [1, N, 2, N, 3, N, 4, N, 5]

Output: [1, N, 2, N, 3, N, 4, N, 5] 
Explanation: After flattening, the tree looks like this:

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-23T17:45:27.543Z  

```cpp
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* prev = NULL;
    
    void inorder(Node* root){
        
        if(root == NULL){
            return;
        }

        inorder(root-> left);
        
        if(prev != NULL){
            prev -> right = root;
        }
         
        root-> left = NULL;
        prev = root;
        
        inorder(root-> right);

    }
    
    Node *flattenBST(Node *root) {
    //     // code here
    //     while(root != NULL){
    //         if(root-> left != NULL){
    //             Node* prev = root-> left;
    //             while(prev -> right != NULL){
    //                 prev = prev -> right;
    //             }
    //         }
    //         else{
    //             prev = NULL;
    //         }
    //     }
        
    //     while(root != NULL){
    //         if(root-> right != NULL){
    //             Node* succ = root-> right;
    //             while(succ -> left != NULL){
    //                 succ = succ -> left;
    //             }
    //         }
    //         else{
    //             succ = NULL;
    //         }
    //     }
        
    //     prev-> right = root;
    //     root-> right = succ;
        
        prev = NULL;
        Node* curr = root;
        while (curr->left != NULL) curr = curr->left;

        inorder(root);
        return curr;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1)