# Minimum in BST

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the  **root**  of a Binary Search Tree, find the  **minimum element**  in this given BST.

 **Examples** 

```
Input: root = [5, 4, 6, 3, N, N, 7, 1]

Output: 1
Explanation: The minimum element in the given BST is 1.
```

```
Input: root = [10, 5, 20, 2]

Output: 2
Explanation: The minimum element in the given BST is 2.
```

```
Input: root = []
Output: -1
Explanation: The root of the BST is NULL.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-21T18:14:10.915Z  

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
  public:
    int minValue(Node* root) {
        // code here
        Node* temp = root;
        
        while(temp -> left != NULL){
            temp = temp-> left;
        }
        return temp-> data;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1)