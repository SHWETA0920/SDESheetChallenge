class Solution {
public:
    string solve(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++){          
            string s1 = solve(s, i, i);            
            string s2 = solve(s, i, i + 1);

            if(s1.length() > ans.length()) ans = s1;
            if(s2.length() > ans.length()) ans = s2;
        }
        return ans;
    }
};
