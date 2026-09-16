# Permutations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

 **Example 2:** 

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]

```

 **Example 3:** 

```
Input: nums = [1]
Output: [[1]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10
- All the integers of nums are unique.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 25.83%)  
**Memory:** 12 MB (beats 9.81%)  
**Submitted:** 2026-09-16T16:33:32.082Z  

```cpp
class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = index; j < nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            //backtrack
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/permutations/)