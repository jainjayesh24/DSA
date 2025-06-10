class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n = arr.size();
        vector<int> result;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0;i<k+1;i++){
            pq.push(arr[i]);
        }
        
        result.push_back(pq.top());
        pq.pop();
        
        for(int i =k+1;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                result.push_back(pq.top());
                pq.pop();
            }
        }
        
        while(pq.size()>0){
            result.push_back(pq.top());
            pq.pop();
        }
        arr = result;
        
    }
};