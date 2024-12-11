//Brute
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        int posI = 0, negI = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans.push_back(pos[posI++]);
            } else {
                ans.push_back(neg[negI++]);
            }
        }


        return ans;
        
    }
};

//Optimal
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N,0);
        int posI = 0, negI = 1;
        for(int i = 0;i<N;i++){
            if(nums[i]>0){
                ans[posI] = nums[i];
                posI+=2;
            }
            else{
                ans[negI] = nums[i];
                negI+=2;
            }
        }
        return ans;

    }
};