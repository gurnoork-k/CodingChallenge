# Lowest Common Ancestor in a BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a Binary Search Tree (BST) with unique node values and two nodes  **n1**  and  **n2**  (n1 != n2), find their Lowest Common Ancestor (LCA).

The Lowest Common Ancestor (LCA) of two nodes is defined as the deepest node in the tree that has both n1 and n2 as descendants, where a node can be a descendant of itself.

 **Examples:** 

```
Input: root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1->data = 7, n2->data = 8
       
Output: 7
Explanation: 7 is the lowest node that has both 7 and 8 as descendants.

```

```
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], n1->data = 8, n2->data = 14
 
Output: 8
Explanation: 8 is the lowest node that has both 8 and 14 as descendants.
```

```
Input: root = [2, 1, 3], n1->data = 1, n2->data = 3

Output: 2
Explanation: 2 is the lowest node that has both 1 and 3 as descendants.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-22T20:31:17.429Z  

```cpp
/* Structure of a Binary Search Tree node
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
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        //base case
        
        if(root == NULL) return root;
        
        if(n1-> data < root-> data && n2-> data < root-> data){
            return findLCA(root-> left, n1, n2);
        }
        if(n1-> data > root-> data && n2-> data > root-> data){
            return findLCA(root-> right, n1, n2);
        }
        return root;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)