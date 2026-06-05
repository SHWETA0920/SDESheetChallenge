class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int ans=-1;
        for(auto it:nums){
            m[it]++;
            if(m[it]>(n/2)){
                ans=it;
                break;
            }            
        }
        return ans;     
        
    }
};
// using hashmap
