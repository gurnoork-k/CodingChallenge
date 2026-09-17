# Kth Ancestor in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a  **binary tree** with  **n**  nodes, a target  **node**  value, and a positive integer  **k**, find the  **kth ancestor**  of the given node.

The kth ancestor of a node is the node that lies k levels above it in the tree. If the given node does not have a kth ancestor, return  **-1**.

 **Notes** 

- It is guaranteed that the given node exists in the binary tree.
- All node values in the tree are distinct.

 **Examples :** 

```
Input: root = [1, 2, 3, 4, 5], k = 2, node = 4

Output: 1
Explanation: The ancestors of node 4 are 2 and 1. Moving 2 levels upward from node 4 reaches node 1, so the output is 1.
```

```
Input: root = [1, 2, 3], k = 1, node = 3    

Output: 1
Explanation: The parent (1st ancestor) of node 3 is 1. Therefore, the output is 1.

```

```
Input: root = [1, 3, 2], k = 3, node = 2  

Output: -1
Explanation: Node 2 has only one ancestor, which is 1. Since a 3rd ancestor does not exist, the output is -1.
```

 **Constraints:** 
1 ≤ n ≤ 105
1 ≤ k ≤ 100
1 ≤ Node->data ≤ n

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-17T16:26:01.428Z  

```cpp
/* Definition for Node
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
private:
    Node* ans = NULL;
    int count = -1;

    int solve(Node* root, int node, int k) {
        if (root == NULL) return 0;

        if (root->data == node) {
            count = 0;
            return 1;
        }

        int left = solve(root->left, node, k);
        int right = solve(root->right, node, k);

        if (left || right) {
            count++;
            if (count == k && ans == NULL) {
                ans = root;
            }
            return 1;
        }

        return 0;
    }

  public:
    int kthAncestor(Node *root, int k, int node) {
        ans = NULL;
        count = -1;
        solve(root, node, k);
        return ans ? ans->data : -1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1)