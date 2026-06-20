class Solution {
  public:
    long long solve(int n, int exp, int m) {
        long long result = 1;
        
        for(int i = 0; i < exp; i++) {
            result *= n;
            if(result > m) return result; 
            
        }
        
        return result;
    }
    
    int nthRoot(int n, int m) {
        if(m == 0) return 0;
        
        int lo = 1, hi = m;
        
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            long long val = solve(mid, n, m);
            
            if(val == m) return mid;
            else if(val < m) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return -1;
    }
};
