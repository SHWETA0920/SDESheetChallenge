class Solution {
  public:
    bool isvalid(vector<int>& arr,int maxi,int n,int k){
        int sum=0,count=1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>maxi){
                count++;
                sum=arr[i];
            }
        }
        if(count>k) return false;
        return true;
    }
     int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(n<k) return -1;
        int lo=INT_MIN;
        int hi=0;
        for(int i=0;i<n;i++){
            hi+=arr[i];
            lo=max(lo,arr[i]);
        }
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isvalid(arr,mid,n,k)) {
                ans = mid;
                hi = mid - 1;
            }
            else lo=mid+1;
        }
        return ans;
        
    }
    
};
