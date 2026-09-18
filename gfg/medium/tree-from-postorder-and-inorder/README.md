# Binary Tree from Inorder and Postorder

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two arrays representing the  **inorder**  and  **postorder** traversals of a binary tree, your task is to construct the binary tree and return its  **root**.

 **Note** : The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

 **Examples:** 

```
Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: [1, 2, 3, 4, 5, 6, 7, N, 8]
Explanation: For the given inorder and postorder traversal of tree the resultant binary tree will be:

```

```
Input: inorder[] = [9, 5, 2, 3, 4], postorder[] = [5, 9, 3, 4, 2]
Output: [2, 9, 4, N, 5, 3]
Explanation: The resultant binary tree will be: 

```

 **Constraints:** 
1 ≤ number of nodes ≤ 103
0 ≤ inorder[i], postorder[i] ≤ 106

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-18T15:12:09.055Z  

```cpp
/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    void createMapping(vector<int> in, map<int, int> &nodeToIndex, int n){
        for(int i=0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
  
    Node* solve(vector<int> &in, vector<int> &post, int &index, 
        int inStart, int inEnd, int n, map<int, int> &nodeToIndex){
        
        //base case
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        
        int ele = post[index--];
        Node* root = new Node(ele);
        int pos = nodeToIndex[ele];
        
        root->right = solve(in, post, index, pos+1, inEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inStart, pos-1, n, nodeToIndex);
        
        
        return root;
    }
    
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        
        int n = postorder.size();
        int index = n-1;
        
        int inStart = 0;
        int inEnd = n-1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        
        Node* ans = solve(inorder, postorder, index, inStart, inEnd, n, nodeToIndex);
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1)