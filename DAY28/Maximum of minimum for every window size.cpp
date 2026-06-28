#include <bits/stdc++.h> 
using namespace std;

vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> left(n), right(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    vector<int> ans(n, INT_MIN);

    for(int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }
    for(int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}
