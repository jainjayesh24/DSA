typedef pair<int,int> pp;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
        }

        priority_queue< pp,vector<pp> , greater<pp>> pq;

        for(auto it : mpp){
            pq.push({it.second,it.first});

            if(pq.size()>k) pq.pop();
        }
        vector<int> result;
        while(pq.size()>0){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};