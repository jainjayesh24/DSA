//Brute
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

//Better 
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) c0++;
            else if(nums[i]==1) c1++;
            else c2++;
        }

        for(int i = 0; i<c0;i++){
            nums[i] = 0;
        }

        for(int i = c0; i<c0+c1;i++){
            nums[i] = 1;
        }

        for(int i = c0+c1;i<nums.size();i++){
            nums[i] = 2;
        }
    }
};

