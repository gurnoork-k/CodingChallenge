# Heap Sort

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**. The task is to sort the array elements by Heap Sort.

 **Examples:** 

```
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 3, 4, 7, 9.

```

```
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.

```

```
Input: arr[] = [2, 1, 5]
Output: [1, 2, 5]
Explanation: After sorting elements using heap sort, elements will be in order as 1, 2, 5.
```

 **Constraints:** 
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T17:34:07.589Z  

```cpp
// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i + 2;

        if(left <n && arr[largest] < arr[left] ){
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        //max heap bana diya
        for(int i= (n-1)/2; i >= 0; i--){
            heapify(arr, n, i);
        }
        
        while(n > 1){
            swap(arr[0], arr[n-1]);
            n--;
            
            heapify(arr, n, 0);
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/heap-sort/1)