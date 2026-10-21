# Kth Smallest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array  **arr[]**  and an integer  **k**, find and return the kth smallest element in the given array.

 **Examples :** 

```
Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.
```

```
Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T14:56:12.681Z  

```cpp
class Solution {
  public:

    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        int n = arr.size();
        
        for(int i =0; i< n; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i< n; i++){
            pq.pop();
        }
        
        return pq.top();
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1)