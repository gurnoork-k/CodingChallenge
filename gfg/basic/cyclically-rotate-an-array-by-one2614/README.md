# Rotate Array by One

![Difficulty](https://img.shields.io/badge/Difficulty-Basic-red)

## Problem

Given an array  **arr[]**, rotate the array by one position in clockwise direction.

 **Examples:** 

```
Input: arr[] = [1, 2, 3, 4, 5]
Output: [5, 1, 2, 3, 4]
Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.
```

```
Input: arr[] = [9, 8, 7, 6, 4, 2, 1, 3]
Output: [3, 9, 8, 7, 6, 4, 2, 1]
Explanation: After rotating clock-wise 3 comes in first position.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T21:12:34.733Z  

```cpp
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        if(arr.size() <= 1){
            return;
        }
        int n = arr.size()-1;
        int last = arr[n];
        
        for(int i=n; i>=0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1)