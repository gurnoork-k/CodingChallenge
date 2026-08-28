class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = nums.size();

        for(int i=0; i< n; i++){
            int num = nums[i];
            count[num] += 1;
        }
        for(auto& [num,freq] : count){
            if(freq > (n/2)){
                return num;
            }
        }
        return -1;
    }
};