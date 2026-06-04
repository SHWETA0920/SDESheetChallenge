class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();        
        vector<int> v(n+1, 0);   
        vector<int> ans(2);        
        int sumArr = 0;        
        for(auto it: nums){
            v[it]++;
            sumArr += it;
        }
        for(int i = 1; i <= n; i++){   
            if(v[i] > 1){
                ans[0] = i;            
            }
            if(v[i] == 0){
                ans[1] = i;            
            }
        }        
        return ans;  
    }
};
