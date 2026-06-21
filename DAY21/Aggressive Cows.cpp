class Solution {
  public:
   bool isvalid(vector<int>&stalls,int dis ,int k,int n){
       int count=1;
       int last=stalls[0];
       for(int i=1;i<n;i++){
           if(stalls[i]-last>=dis){
               count++;
               last=stalls[i];
           }
       }
       if(count>=k) return true;
       else return false;
   }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int lo=1;//minimum that should be there 
        int hi=stalls.back()-stalls[0];// maxi diatcnce can be possible
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isvalid(stalls,mid,k,n)){
                ans=mid;
                lo=mid+1;
                
            }
            else hi=mid-1;
        }
        return ans;
    }
};
