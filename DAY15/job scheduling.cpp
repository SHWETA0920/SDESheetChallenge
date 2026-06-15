/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
   static bool cmp(Job a, Job b){
       return a.profit > b.profit;
   }
    vector<int> JobScheduling(Job arr[], int n) {
        // code here
        
        sort(arr,arr+n,cmp);
        int maxD=0;
        for(int i=0;i<n;i++){
            maxD=max(maxD,arr[i].deadline);
        }
        int mprofit=0;
        int c=0;
        vector<int>v(maxD+1,-1);
        for(int i=0;i<n;i++){
            int cprofit=arr[i].profit;
            int cjob=arr[i].id;
            int cdead=arr[i].deadline;
            for(int k=cdead;k>0;k--){
                if(v[k]==-1){
                    c++;  
                    mprofit+=cprofit;
                    v[k]=cjob;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(c);
        ans.push_back(mprofit);
        return ans;
        
    }
};
