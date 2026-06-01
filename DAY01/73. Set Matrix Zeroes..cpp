class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int>row;
        vector<int>col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }            
        }
        // maing row zeroes
        for(int i=0;i<row.size();i++){
            int  ans=row[i];
            for(int j=0;j<m;j++){
                matrix[ans][j]=0;
            }
        }
        // making col zeroes
        for(int i=0;i<n;i++){
            for(int j=0;j<col.size();j++){
                int ans=col[j];
                matrix[i][ans]=0;
            }
        }
        
        
    }
};
