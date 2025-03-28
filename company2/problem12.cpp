class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> d(n, vector<int>(n, n));
    for (auto &e : edges)
        d[e[0] - 1][e[1] - 1] = d[e[1] - 1][e[0] - 1] = 1;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    vector<int> res(n - 1, 0);
    for (int s = 0; s < 1 << n; ++s) {
        int max_depth = 0, nodes = 0, edges = 0;
        for (int i = 0; i < n; ++i)
            if (s & (1 << i)) {
                ++nodes;
                for (int j = i + 1; j < n; ++j)
                    if (s & (1 << j)) {
                        edges += d[i][j] == 1;
                        max_depth = max(max_depth, d[i][j]);
                    }
            }
        if (edges == nodes - 1 && max_depth > 0)
            ++res[max_depth - 1];
    }
    return res;
    }
};