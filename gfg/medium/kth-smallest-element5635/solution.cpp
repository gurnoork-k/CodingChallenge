class Solution {
  public:

    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        int n = arr.size();
        
        for(int i =0; i< n; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i< n; i++){
            pq.pop();
        }
        
        return pq.top();
    }
};