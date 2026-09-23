# Pair Sum in BST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

 **Examples:** 

```
Input: root[] = [7, 3, 8, 2, 4, N, 9], target = 12

Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
```

```
Input: root[] = [9, 5, 10, 2, 6, N, 12], target = 23

Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-23T11:57:17.232Z  

```cpp
/* Binary Tree Node Structure
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
    void inorder(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        inorder(root-> left, ans);
        ans.push_back(root-> data);
        inorder(root-> right, ans);

    }
    
    bool findTarget(Node *root, int target) {
        // code here.
        vector<int> ans;
        inorder(root, ans);
        
        int n = ans.size();
        int i = 0;
        int j = n-1;
        int sum = 0;
        bool flag = false;
        
        while(i < j){
            sum = ans[i] + ans[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                flag = true;
                break;
            }
            
        }
        return flag;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1)