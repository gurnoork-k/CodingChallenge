# Merge Two BSTs

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given the roots  **r1**  and  **r2**  of two Binary Search Trees (BSTs), merge the elements of both trees into a single sorted array and return it.

The returned array should contain all the elements from both BSTs, including duplicate values if they are present.

 **Examples:** 

```
Input: r1 = [3, 1, 5], r2 = [4, 2, 6]

Output: [1, 2, 3, 4, 5, 6]
Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].
```

```
Input: r1 = [8, 2, 10, 1, N], r2 = [5, 3, N, 0, N] 

Output: [0, 1, 2, 3, 5, 8, 10]
Explanation: After merging and sorting the two BST we get [0, 1, 2, 3, 5, 8, 10].
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-24T11:53:14.290Z  

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
    
    vector<int> mergeArrays(vector<int> a, vector<int> b){
        vector<int> ans(a.size() + b.size());
        int i = 0, j =0;
        int k = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }
        
        while(i < a.size()){
            ans[k++] = a[i];
            i++;
        }
        
        while(j < b.size()){
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }
    
    // Node* inorderToBst(int s, int e, vector<int> &in){
    //     //base case
    //     if(s> e){
    //         return NULL;
    //     }
    //     int mid = (s+e) / 2;
    //     root-> left = inorderToBst(s, mid-1, in);
    //     root-> right - inorderToBst(mid+1, e, in);
    //     return root; 
    // }
        
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int> bst1, bst2;
        
        
        inorder(r1, bst1);
        inorder(r2, bst2);
        
        vector<int> mergedArr = mergeArrays(bst1, bst2);
        return mergedArr;
        
        // int s = 0; 
        // int e = mergedArr.size()-1;
        // Node* ans = inorderToBst(s, e, mergedArr);
        // return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1)