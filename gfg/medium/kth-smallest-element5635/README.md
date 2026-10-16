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
**Submitted:** 2026-10-16T18:57:10.319Z  

```cpp
class Solution {
  public:

    int kthSmallest(vector<int> &arr, int k) {
        // code here 
        int n = arr.size();
        
        priority_queue<int> pq;
        for(int i= 0; i< k; i++){
            pq.push(arr[i]);
        }
        
        for(int i= k; i<n ; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans = pq.top();
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1)