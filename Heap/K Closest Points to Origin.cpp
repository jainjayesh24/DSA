class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],
                     {points[i][0], points[i][1]}});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> result;
        while(pq.size()>0){
            auto [x,y] = pq.top().second;
            result.push_back({x,y});

            pq.pop();
        }


        return result;

    }
};