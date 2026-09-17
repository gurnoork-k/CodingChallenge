# LCA in  Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the  **root**  of a binary tree with all unique values and two nodes value,  **n1**  and  **n2**.

Find the lowest common ancestor of the given two nodes. Both node values are always present in the Binary Tree.

 **Note:**  LCA is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

 **Examples:** 

```
Input: root = [1, 2, 3, 4, 5, 6, 7], n1 = 4, n2 = 5    

Output: 2
Explanation: LCA of 4 and 5 is 2.

```

```
Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, N, 8], n1 = 7, n2 = 8

Output: 3
Explanation: LCA of 7 and 8 is 3.
 
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-17T13:18:34.529Z  

```cpp
/* Structure of binary tree node
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
  public:
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        //base case
        if(root == NULL) return root;
        if(root -> data == n1 || root-> data == n2) return root;
        
        Node* leftAns = lca(root-> left, n1, n2);
        Node* rightAns = lca(root-> right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
  
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1)