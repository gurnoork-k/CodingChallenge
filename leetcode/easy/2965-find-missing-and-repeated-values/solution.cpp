class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        map<int, int> count;
        int r = grid.size();
        int c = grid[0].size();

        for(int i= 0; i< c; i++){
            for(int j= 0; j< c; j++){
                if(count.find(grid[i][j]) == count.end()){
                    count[ grid[i][j] ] = 1;
                }
                else count[ grid[i][j] ]+= 1;
            }
            
        }

        for(int i=1; i <= c*r; i++){
            if(count[i] > 1){
                ans.push_back(i);
            }
        }
        for(int i=1; i <= c*r; i++){
            if(count[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};