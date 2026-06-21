class Solution {
  public:
    int count(vector<int> &a,vector<int> &b,int x){
        int count=0;
        count+=upper_bound(a.begin(),a.end(),x)-a.begin();
        count+=upper_bound(b.begin(),b.end(),x)-b.begin();

        return count;
    }
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int lo=INT_MAX;
        int hi=INT_MIN;
        if(!a.empty()){
            lo=min(lo,a[0]);
            hi=max(hi,a.back());
        }
        if(!b.empty()){
            lo=min(lo,b[0]);
            hi=max(hi,b.back());
        }
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int req=count(a,b,mid);
            if(req<k) lo=mid+1;
            else hi=mid-1;
        }
        return lo;
        
    }
};
