class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        if(arr.size() <= 1){
            return;
        }
        int n = arr.size()-1;
        int last = arr[n];
        
        for(int i=n; i>=0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
};