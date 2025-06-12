class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // Your Code Goes Here
    
        int n = sticks.size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i = 0;i<n;i++){
            pq.push(sticks[i]);
        }
        int cost = 0;
        while(pq.size()>=2){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            cost += first+second;
            pq.push(first+second);
        }

        return cost;


    }
};