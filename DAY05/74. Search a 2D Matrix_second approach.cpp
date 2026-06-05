class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int idx=-1;
        for(int i=0;i<n;i++){            
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                idx=i;
                break;
            }
        }
        if(idx==-1) return false;
        int lo=0;
        int high=m-1;        
        while(lo<=high){
            int mid = lo + (high - lo) / 2;
            if (matrix[idx][mid] == target)
                return true;
            else if (target > matrix[idx][mid])
                lo = mid + 1;
            else
                high = mid - 1;
        }
        return false;
      // time omplextind O(n+logm) // space =O(1)        
    }
};
