# Search in BST

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a Binary Search Tree and a node value key, return true if the node with value key is present in the BST; otherwise, return false.

 **Examples:** 

```
Input: root = [6, 2, 8, N, N, 7, 9], key = 8
    
Output: true
Explanation: 8 is present in the BST as right child of root.
```

```
Input: root = [16, 12, 18, 10, N, 17, 19], key = 14
    
Output: false
Explanation: 14 is not present in the BST
```

**Constraints:
**1 ≤ number of nodes ≤ 3*104
1 ≤ node->data, key ≤ 109

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-21T17:47:01.315Z  

```cpp
/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        //base case
        if(root == NULL){
            return false;

        }
        if(root -> data == key){
            return true;
        }

        if(root-> data > key){
            search(root-> left, key);
        }
        else{
            search(root-> right , key);
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1)