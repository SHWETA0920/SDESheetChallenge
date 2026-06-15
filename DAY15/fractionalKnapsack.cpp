class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n = val.size();
        
        vector<pair<double, pair<long long, long long>>> items;
        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }
        sort(items.begin(), items.end(), greater<>());
        
        double maxValue = 0.0;
        
        for(int i = 0; i < n; i++) {
            long long value = items[i].second.first;
            long long weight = items[i].second.second;
            
            if(capacity >= weight) {
                maxValue += value;
                capacity -= weight;
            } else {
               
                maxValue += items[i].first * capacity;
                break;
            }
        }
        
        return maxValue;
    }
};
