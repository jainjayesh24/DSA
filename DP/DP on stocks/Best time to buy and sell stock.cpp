class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int profit = 0;
        int mini = arr[0];

        for(int i =0;i<n;i++){
            int diff = arr[i] -mini;

            profit = max(diff,profit);

            mini = min(mini,arr[i]);
        }

        return profit;
    }
};

