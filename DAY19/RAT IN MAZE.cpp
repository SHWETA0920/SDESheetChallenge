class Solution {
public:
    vector<string> ans;

    void solve(int i, int j, int n, vector<vector<int>>& m, string& path) {
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] == 0) {
            return;
        }

      
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

      
        m[i][j] = 0;
        
        path.push_back('D');
        solve(i + 1, j, n, m, path);
        path.pop_back();

        // Left
        path.push_back('L');
        solve(i, j - 1, n, m, path);
        path.pop_back();

        // Right
        path.push_back('R');
        solve(i, j + 1, n, m, path);
        path.pop_back();

        // Up
        path.push_back('U');
        solve(i - 1, j, n, m, path);
        path.pop_back();

        // unmark (backtrack)
        m[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        if (maze[0][0] == 0) return ans;

        string path = "";
        solve(0, 0, n, maze, path);
        return ans;
    }
};
