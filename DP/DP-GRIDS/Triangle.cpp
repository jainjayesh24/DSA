class Solution {
   public:
    int func(int i, int j, vector<vector<int>> &triangle,
             vector<vector<int>> &dp) {
        // base case
        int n = triangle.size();
        if (i == n - 1) return triangle[n-1][j];
        if (dp[i][j] != -1) return dp[i][j];
        // Exploration
        int down = triangle[i][j] + func(i + 1, j, triangle, dp);
        int dig = triangle[i][j] + func(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, dig);
    }
    int minTriangleSum(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < n; ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }

        return func(0, 0, triangle, dp);
    }
};