class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int x) {
        int count = 0;
        count += upper_bound(nums1.begin(), nums1.end(), x) - nums1.begin();
        count += upper_bound(nums2.begin(), nums2.end(), x) - nums2.begin();

        return count;
    }
    int median(vector<int>& nums1, vector<int>& nums2, int k, int n, int m) {
        int lo = INT_MAX, hi = INT_MIN;
        if (n != 0 && m != 0) {
            lo = min(nums1[0], nums2[0]);
            hi = max(nums1[n - 1], nums2[m - 1]);
        } else if (n == 0) {
            lo = min(lo, nums2[0]);
            hi = max(hi, nums2[m - 1]);
        } else {
            lo = min(lo, nums1[0]);
            hi = max(hi, nums1[n - 1]);
        }
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int count = solve(nums1, nums2, mid);
            if (count <= k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = m + n;
        if (total % 2 == 1) {
            return median(nums1, nums2, total / 2, n, m);
        } else {
            double a = median(nums1, nums2, (total / 2) - 1, n, m);
            double b = median(nums1, nums2, total / 2, n, m);
            return (a + b) / 2;
        }
        return -1;
    }
};
