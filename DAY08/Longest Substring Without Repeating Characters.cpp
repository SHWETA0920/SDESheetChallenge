class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char>st;
        int c=0,maxi=0,l=0,r=0;
        while(l<n && r<n){            
            if(st.find(s[r])==st.end()){                
                maxi=max(maxi,r-l+1);
                st.insert(s[r]);
                r++;
            }
            else {
                st.erase(s[l]);
                l++;
            }          
        }
        return maxi;        
    }
};
