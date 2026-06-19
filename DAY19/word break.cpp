class Solution {
public:
    vector<string> ans;

    void solve(int index, string &s, unordered_set<string> &dict, string curr) {
        if (index == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        string temp = "";

        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (dict.count(temp)) {
                solve(i + 1, s, dict, curr + temp + " ");
            }
        }
    }

    vector<string> wordBreak(vector<string>& dict, string& s) {
        unordered_set<string> st(dict.begin(), dict.end());
        ans.clear(); 

        solve(0, s, st, "");

        return ans;
    }
};
