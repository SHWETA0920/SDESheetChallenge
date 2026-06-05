//Boyer–Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0 , count=0;
        for(int ele:nums){
            if(count==0) ans=ele;
            if(ele==ans) count++;
            else count--;
        }
        return ans;    
       
    }
};
