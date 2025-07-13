#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> dir = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };
    
    bool isValid(int x, int y, int n) {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    }

    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{knightPos[0], knightPos[1]}, 0});

        vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
        visited[knightPos[0]][knightPos[1]] = 1;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int x = front.first.first;
            int y = front.first.second;
            int steps = front.second;

            if (x == targetPos[0] && y == targetPos[1]) {
                return steps;
            }

            for (auto i : dir) {
                int newX = x + i[0];
                int newY = y + i[1];

                if (isValid(newX, newY, n) && !visited[newX][newY]) {
                    visited[newX][newY] = 1;
                    q.push({{newX, newY}, steps + 1});
                }
            }
        }

        return -1;
    }
};
