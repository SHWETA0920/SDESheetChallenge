class Solution {
  public:
  
    int solve(vector<vector<int>> &mat, int x, int n, int m){
        int count = 0;
        
        for(int i = 0; i < n; i++){
            count += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
        }
        return count;
    }
    
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = INT_MAX, hi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);  
        }
        
        int req = (n * m) / 2;
        
        while(lo <= hi){  
            int mid = (lo + hi) / 2;
            int small = solve(mat, mid, n, m);
            
            if(small <= req) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return lo;
    }
};
