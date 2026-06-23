class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        
        int n = mat.size();  
        priority_queue< tuple<int, int, int>,vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;
        for (int i = 0; i < n; i++) {
            if (!mat[i].empty()) {
                pq.push({mat[i][0], i, 0});
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            auto [val, r, c] = pq.top(); 
            pq.pop();

            ans.push_back(val);

            if (c + 1 < mat[r].size()) {
                pq.push({mat[r][c + 1], r, c + 1});
            }
        }

        return ans;
    }
};
