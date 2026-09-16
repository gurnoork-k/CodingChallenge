# Maximum Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, find the subarray with the largest sum, and return  *its sum*.

 

 **Example 1:** 

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

```

 **Example 2:** 

```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

```

 **Example 3:** 

```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

 

 **Follow up:**  If you have figured out the `O(n)` solution, try coding another solution using the  **divide and conquer**  approach, which is more subtle.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 71.7 MB (beats 52.26%)  
**Submitted:** 2026-09-16T16:53:22.372Z  

```cpp
class Solution {
public:
    /*brute force --------------------------
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i< nums.size(); i++){
            for(int j = i; j< nums.size(); j++){
                sum += nums[j];
                maxi = max(sum , maxi);
            }
        }
        return maxi;
    }*/

    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
            maxi = max(sum , maxi);

            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-subarray/)