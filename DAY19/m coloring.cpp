class Solution {
public:
    vector<int> color;

    bool isSafe(vector<vector<int>> &edges, int node, int c) {
        for (int k = 0; k < edges.size(); k++) {
            int u = edges[k][0];
            int w = edges[k][1];

            if (u == node && color[w] == c) return false;
            if (w == node && color[u] == c) return false;
        }
        return true;
    }

    bool solve(int v, vector<vector<int>> &edges, int node, int m) {
        if (node == v) return true;

        for (int c = 1; c <= m; c++) {
            if (isSafe(edges, node, c)) {
                color[node] = c;

                if (solve(v, edges, node + 1, m))
                    return true;

                color[node] = -1;
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        color.assign(v, -1);
        return solve(v, edges, 0, m);
    }
};
