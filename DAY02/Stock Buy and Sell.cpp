class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_pro=INT_MIN;
        int min_stock=INT_MAX;
        for(int i=0;i<n;i++){
            min_stock=min(min_stock,prices[i]);
            max_pro=max(max_pro,prices[i]-min_stock);
        }
        return max_pro;        
    }
};
