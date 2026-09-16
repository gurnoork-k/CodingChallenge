class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i++){
            for(int j = i+1; j < col; j++){ 
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        int i = 0;
        while(i < row){
            int j = 0;
            int e = col-1;
            while(j < e){
                swap(matrix[i][j], matrix[i][e]);
                j++;
                e--;
            }
            i++;
        }


    }
};