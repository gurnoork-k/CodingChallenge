# Tree Boundary Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a root of a Binary Tree, return its boundary traversal in the following order:

- Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
- Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
- Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

 **Note:**  The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

 **Examples:** 

```
Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

```

```
Input: root = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
```

 **Constraints:** 
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-15T14:41:11.327Z  

```cpp
/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        //base case
        if(root == NULL || root-> left == NULL && root-> right == NULL){
            return;
        }
        ans.push_back(root-> data);
        
        if(root-> left){
            traverseLeft(root-> left, ans);
        }
        else{
            traverseLeft(root-> right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        //base case
        if(root == NULL){
            return;
        }
        if(root-> left == NULL && root-> right == NULL){
            ans.push_back(root-> data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        //base case
        if(root == NULL || root-> left == NULL && root-> right == NULL){
            return;
            
        }
        if(root-> right)
            traverseRight(root-> right, ans);
        else
            traverseRight(root->left, ans);
        
        ans.push_back(root-> data);
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root-> data);
        
        traverseLeft(root-> left, ans);
        
        traverseLeaf(root-> left, ans);
        traverseLeaf(root-> right, ans);
        
        traverseRight(root-> right, ans);
        
        return ans;
        
        
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)