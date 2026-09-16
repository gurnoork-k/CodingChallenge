# Top View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given the  **root**  of a binary tree, and your task is to return its  **top view**. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

 **Note:** 

- Return the nodes from the leftmost node to the rightmost node.
- If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

 **Examples:** 

```
Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
```

```
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-16T16:14:14.740Z  

```cpp
/*
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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        map<int, int> topNode;
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode-> data;
            }
            
            if(frontNode-> left){
                q.push(make_pair(frontNode-> left, hd-1));
            }
            if(frontNode-> right){
                q.push(make_pair(frontNode-> right, hd+1));
            }
        }
        
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)