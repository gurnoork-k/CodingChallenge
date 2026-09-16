# Search in Rotated Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

There is an integer array `nums` sorted in ascending order (with  **distinct**  values).

Prior to being passed to your function, `nums` is  **possibly left rotated**  at an unknown index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1],..., nums[n-1], nums[0], nums[1],..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be left rotated by `3` indices and become `[4,5,6,7,0,1,2]`.

Given the array `nums`  **after**  the possible rotation and an integer `target`, return  *the index of* `target` *if it is in* `nums` *, or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

 

 **Example 1:** 

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

```

 **Example 2:** 

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```

 **Example 3:** 

```
Input: nums = [1], target = 0
Output: -1

```

 

 **Constraints:** 

- 1 <= nums.length <= 5000
- -104 <= nums[i] <= 104
- All values of nums are unique.
- nums is an ascending array that is possibly rotated.
- -104 <= target <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.2 MB (beats 37.45%)  
**Submitted:** 2026-09-16T16:33:02.912Z  

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(nums[mid] == target) return mid;

            // Left half is sorted
            if(nums[s] <= nums[mid]) {
                if(nums[s] <= target && target <= nums[mid]) {
                    e = mid - 1; // target in left half
                } else {
                    s = mid + 1; // target in right half
                }
            }
            // Right half is sorted
            else {
                if(nums[mid] <= target && target <= nums[e]) {
                    s = mid + 1; // target in right half
                } else {
                    e = mid - 1; // target in left half
                }
            }
        }
        return -1; // not found
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)