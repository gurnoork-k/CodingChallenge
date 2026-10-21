class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s;
        vector<int> ans;
        
        for(int i=0; i< a.size(); i++){
            s.insert(a[i]);
        }
        for(int i=0; i< b.size(); i++){
            s.insert(b[i]);
        }
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};