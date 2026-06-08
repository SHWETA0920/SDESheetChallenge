class Solution{
public:
    int longestSubarray(vector<int> &arr, int k){
        int n = arr.size();
        long long sum = 0;
        int maxi = 0; 
        unordered_map<long long, int> m;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k){
                maxi = i + 1;
            }
            long long rem = sum - k;
            if(m.find(rem) != m.end()){
                maxi = max(maxi, i - m[rem]);
            }
            if(m.find(sum) == m.end()){
                m[sum] = i;
            }
        }
        return maxi;
        
    }
};
