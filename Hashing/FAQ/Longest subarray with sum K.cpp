//Brute
//TC->O(N3)
//Sc->O(1)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int length = 0;
        for(int i=0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                int sum = 0;
                for(int k = i;k<=j;k++){
                    sum+=nums[k];
                }
                if(sum==k){
                    length = max(length,j-i+1);
                }
            }
        }
        return length;
    }
};

//Optimal
//Tc -> O(N2)
//SC->O(1)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int length = 0;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j = i;j<nums.size();j++){
                sum +=nums[j];
                if(sum==k){
                    length = max(length,j-i+1);
                }
            }
        }
        return length;
    }
};


//optimal
//Tc->
//Sc->
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size(); 
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) {
                maxLen = max(maxLen, i + 1);
            }
            int rem = sum - k;
            if (preSumMap.find(rem) != preSumMap.end()) {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
