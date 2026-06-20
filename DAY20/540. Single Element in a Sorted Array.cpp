class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int n=nums.size();
        int hi=n-1;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0]; 

        while(lo<=hi){
            if(lo== hi)  return nums[lo];
            int mid=(lo+hi)/2;
             if((mid==0 && nums[mid]!= nums[mid+1]) || (mid==n-1 && nums[mid]!= nums[mid-1]))
                return nums[mid];
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(nums[mid]==nums[mid-1]){
                if(mid%2==0) hi=mid-1;
                else lo=mid+1;
            }
            if(nums[mid]==nums[mid+1]){
                if(mid%2==0) lo=mid+1;
                else hi=mid-1;

            }
        }
        return 0;
        
    }
};
