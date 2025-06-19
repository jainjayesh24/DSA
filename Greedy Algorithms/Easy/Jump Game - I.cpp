class Solution {
public:
    bool canJump(vector<int>& nums) {
        //your code goes here
        int maxIndex = 0;

        int n = nums.size();


        for(int i = 0;i<n;i++){
            if(i>maxIndex) return false;
            maxIndex = max(maxIndex,nums[i]+i);
        }

        return true;
    }
};

