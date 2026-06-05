class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0, high = n*m - 1;
        while (lo <= high) {
            int mid = lo + (high - lo) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                lo = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
