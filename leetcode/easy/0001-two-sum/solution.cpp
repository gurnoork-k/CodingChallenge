class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        for(int i=0; i< nums.size(); i++){
            int complement = target - nums[i];
            if(comp.find(complement) != comp.end()){
                return {comp[complement], i};
            }
            comp[nums[i]] = i;
        }
        return {};
    }
};