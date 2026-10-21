class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // code here
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < arr.size(); i++){
           if(arr[i] >= 0){ 
               pos.push_back(arr[i]);
           }
           else{
               neg.push_back(arr[i]);
           }
       }
        
        for(int i=0; i< pos.size(); i++){
            arr[i] = pos[i];
        }
        int n = pos.size();
        for(int i=n; i<arr.size(); i++){
            arr[i] = neg[i-n];
        }
    }
};