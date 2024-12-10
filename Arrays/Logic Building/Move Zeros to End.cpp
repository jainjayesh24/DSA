//Brute
//tc ->O(2n)
//sc->o(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }

        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
        for(int i=temp.size();i<nums.size();i++){
            nums[i] = 0;
        }
        
    }
};


//optimal
//tc - o(n)
//sc - o(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        for(int i = j+1;i<nums.size();i++){
            if(nums[i] !=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
};