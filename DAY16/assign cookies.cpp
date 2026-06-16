class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = s.size();
        int j = 0, i = 0;
        int c = 0;
        while (i < n && j < m) {
            if (s[j] >= g[i]) {
                c++;
                j++;i++;
            } else {
                j++;                
            }
        }
        return c;
    }
};
