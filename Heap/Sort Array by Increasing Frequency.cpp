typedef pair<int,int> pp;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
          auto cmp = [](pp &a, pp &b){
            if (a.first == b.first) return a.second < b.second;  
            return a.first > b.first;  
        };
        priority_queue<pp, vector<pp>, decltype(cmp)> pq(cmp);


        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        vector<int> result;

        while(pq.size()>0){
            int ele = pq.top().second;
            int fre = pq.top().first;
            for(int i = 0;i<fre;i++){
                result.push_back(ele);
            }

            pq.pop();
        }
        return result;
    }
};