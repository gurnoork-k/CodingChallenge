class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
            
        }
        return {mini, maxi};
    }
};