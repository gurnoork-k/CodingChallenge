# Union of Arrays with Duplicates

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given two arrays  **a[]**  and  **b[]**, return the union of both the arrays in any order. 

- Elements of a[] and b[] are not necessarily distinct, but output should have only distinct elements.
- The returned union may have elements in any order, the driver code will print the result in sorted order only.

 **Examples:** 

```
Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]
Explanation: Union set of both the arrays will be 1, 2 and 3.

```

```
Input: a[] = [1, 2, 3], b[] = [4, 5, 6] 
Output: [1, 2, 3, 4, 5, 6]
Explanation: Union set of both the arrays will be 1, 2, 3, 4, 5 and 6.
```

```
Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
Output: [1, 2]
Explanation: Union set of both the arrays will be 1 and 2.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-21T17:01:02.559Z  

```cpp
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s;
        vector<int> ans;
        
        for(int i=0; i< a.size(); i++){
            s.insert(a[i]);
        }
        for(int i=0; i< b.size(); i++){
            s.insert(b[i]);
        }
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1)