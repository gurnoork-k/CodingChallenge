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