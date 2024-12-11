//Brute
// TC - O(n2)
// SC - O(1)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int N = nums.size();
        vector<int> leader;
        for(int i = 0;i<N;i++){
            bool flag = true;
            for(int j = i+1 ; j<N;j++){
                if(nums[j]>=nums[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                leader.push_back(nums[i]);
            }
        }
        return leader; 
    }
};

//optimal
//Tc - 2*O(N)
// Sc - o(1)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int N = nums.size();
        vector<int> leader;
        int max = nums[N-1];
        leader.push_back(max);
        for(int i = N-2; i>=0 ;i--){
            if(nums[i]>max){
                leader.push_back(nums[i]);
                max = nums[i];
            }
        }
        reverse(leader.begin(),leader.end());
        return leader;
    }
};