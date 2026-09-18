# Construct Tree from Inorder & Preorder

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two arrays representing the  **inorder**  and  **preorder**  traversals of a binary tree, construct the binary tree and return its  **root**.

 **Note:**  The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.  

 **Examples:** 

```
Input: inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [0, 1, 2, 3, 4, 5]
Explanation: The tree will look like

```

```
Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [1, 4, 3, 5, N, N, N, 2]
Explanation: The tree will look like

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-18T15:19:51.381Z  

```cpp
/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
private: 
    int findPosition(vector<int> &inorder, int ele, int n){
        for(int i=0; i< n; i++){
            if(inorder[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inStart, int inEnd, int n){
        //base case
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        
        int ele = preorder[index++];
        Node* root = new Node(ele);
        int pos = findPosition(inorder, ele, n);
        
        root-> left = solve(inorder, preorder, index,inStart, pos-1, n);
        root-> right = solve(inorder, preorder, index, pos+1, inEnd, n);
        
        return root;
        
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0;
        int n = inorder.size();
        Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/construct-tree-1/1)