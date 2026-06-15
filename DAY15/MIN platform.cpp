class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int p = 0, maxPlat = 0;

        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {
                p++;  
                i++;
            } else {
                p--;     
                j++;
            }
            maxPlat = max(maxPlat, p);
        }

        return maxPlat;
    }
};
