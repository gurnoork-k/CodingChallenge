# Normal BST to Balanced BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a  **root**  of a Binary Search Tree, modify and return the given BST such that it is balanced and has  **minimum** possible height. If there is more than one answer, return  **any**  of them.

 **Note:**  The height of balanced BST returned by you will be compared with the expected height of the balanced tree.

 **Examples:** 

```
Input: root[] = [30, 20, N, 10, N]
     
Output: 2
     
Explanation: The above unbalanced BST is converted to balanced with the minimum possible height i.e. 2.

```

```
Input: root[] = [4, 3, 5, 2, N, N, 6, 1, N, N, 7]
     
Output: 3
     
Explanation: The above unbalanced BST is converted to balanced with the minimum possible height i.e. 3.
```

 **Constraints:** 
1 <= Number of Nodes <= 105
1 <= Node -> data <= 109

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-23T17:59:03.699Z  

```cpp
/* BST Node Structure
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
}; */

class Solution {
  public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root-> left, in);
        in.push_back(root-> data);
        inorder(root-> right, in);
        
    }
    
    Node* inorderToBst(int s, int e, vector<int> in){
        if(s>e) return NULL;
        
        int mid = (s+e)/2;
        Node* root = new Node(in[mid]);
        root-> left = inorderToBst(s, mid-1, in);
        root-> right = inorderToBst(mid+1, e, in);
        return root;
    }
    
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        return inorderToBst(0, n-1, in);
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1)