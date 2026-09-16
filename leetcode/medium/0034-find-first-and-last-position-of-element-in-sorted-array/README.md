# Find First and Last Position of Element in Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 

 **Example 1:** 

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

```

 **Example 2:** 

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

 **Example 3:** 

```
Input: nums = [], target = 0
Output: [-1,-1]

```

 

 **Constraints:** 

- 0 <= nums.length <= 105
- -109 <= nums[i] <= 109
- nums is a non-decreasing array.
- -109 <= target <= 109

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17.6 MB (beats 53.51%)  
**Submitted:** 2026-09-16T16:33:20.557Z  

```cpp
class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(nums[mid] == target) {
                ans = mid;      // possible answer
                e = mid - 1;    // keep searching left
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(nums[mid] == target) {
                ans = mid;      // possible answer
                s = mid + 1;    // keep searching right
            } else if(nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target){
        return { findFirst(nums, target), findLast(nums, target)};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)