class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector<int> ans;
        // map<int, int> count;
        // int r = grid.size();
        // int c = grid[0].size();

        // for(int i= 0; i< c; i++){
        //     for(int j= 0; j< c; j++){
        //         if(count.find(grid[i][j]) == count.end()){
        //             count[ grid[i][j] ] = 1;
        //         }   
        //         else count[ grid[i][j] ]+= 1;
        //     }
            
        // }

        // for(int i=1; i <= c*r; i++){
        //     if(count[i] > 1){
        //         ans.push_back(i);
        //     }
        // }
        // for(int i=1; i <= c*r; i++){
        //     if(count[i] == 0){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        int n = grid.size();
        int total = n*n;
        vector<int> count(total+1);

        for(auto row: grid){
            for(auto x: row){
                count[x]++;
            }
        }

        int rep = -1;
        int mis = -1;
        for(int i = 1; i <= total; i++){
            if(count[i] == 2){
                rep = i;
            }
            else if(count[i] == 0){
                mis = i;
            }
        }
        return {rep, mis};
    }
};