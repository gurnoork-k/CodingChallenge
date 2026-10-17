# Is Binary Tree Heap

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given the  **root** of a binary tree, and the task is to determine whether it satisfies the properties of a  **max-heap**.

A binary tree is considered a max-heap if it satisfies the following conditions:

- Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
- Max-Heap Property: The value of each node is greater than or equal to the values of its children.

 **Examples:** 

```
Input: root = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.

```

```
Input: root = [97, 46, 37, 12, 3, 7, 31, N, N, 2, 4]
 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
```

 **Constraints:** 
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T12:49:56.814Z  

```cpp
/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    int countNodes(Node* tree){
        if(tree == NULL){
            return 0;
        }
        int ans = 1 + countNodes(tree-> left ) + countNodes(tree-> right);
        return ans;
    }
  
    bool isCbt(Node* tree, int index, int count){
      if(tree == NULL){
          return true;
      }
      if(index > count){
          return false;
      }
      else{
          bool left = isCbt(tree-> left, 2*index, count);
          bool right = isCbt(tree-> right, 2*index+1, count);
          return (left && right); 
      }
    }
    
    bool isMaxOrder(Node* tree){
        //leaf node
        if(tree-> left == NULL && tree-> right == NULL){
            return true;
        }

        if(tree-> right == NULL){
            return(tree-> left -> data <= tree-> data);
        }
        else{
            bool l=  isMaxOrder(tree-> left);
            bool r = isMaxOrder(tree-> right);
            return (l && r && (tree-> left -> data <= tree-> data &&
                        tree-> right -> data <= tree-> data));
        }
    }
  
    bool isHeap(Node* tree) {
        // code here
        int index = 1;
        if(isCbt(tree, index, countNodes(tree)) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1)