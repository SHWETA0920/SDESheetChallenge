class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n= arr.size();
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        mp[0]=1;
        for(int r=0;r<n;r++){
            sum^=arr[r];
            int x=sum^k;
            if(mp.find(x)!=mp.end()){
                ans+=mp[x];
            }
            mp[sum]++;
        }
        return ans;
    }
};
