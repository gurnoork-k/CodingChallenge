# Min and Max in Array

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given an array **arr[]**. Your task is to find the  **minimum** and **maximum** elements in the array.

 **Examples:** 

```
Input: arr[] = [1, 4, 3, 5, 8, 6]
Output: [1, 8]
Explanation: minimum and maximum elements of array are 1 and 8.
```

```
Input: arr[] = [12, 3, 15, 7, 9]
Output: [3, 15]
Explanation: minimum and maximum element of array are 3 and 15.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T11:52:25.267Z  

```cpp
class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
            
        }
        return {mini, maxi};
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1)