//Brute
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int N = nums.size();
        for(int i =0;i<N;i++){
            for(int j = i+1;j<N;j++){
                if(nums[i]+nums[j]== target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;

                }
            }
        }
        return {-1,-1};
    }
};

//Better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int N = nums.size();
        for(int i = 0 ;i<N;i++){
            int numb = nums[i];
            int more = target - numb;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more],i};
            }
            mpp[numb] = i;
        }
        return {-1,-1};
    }   
};


