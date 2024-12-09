class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int temp = nums[0];
        for(int i=0;i<(nums.size()-1);i++){
            nums[i] = nums[i+1];
        }
        nums[nums.size()-1] = temp;
    }
};