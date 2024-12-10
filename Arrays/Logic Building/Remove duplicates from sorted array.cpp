//Brute
//tc - O(N * log N) + O(N)
// sc - O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> result;
        for(int i=0;i<nums.size();i++){
            result.insert(nums[i]);
        }
        int index = 0;
        for(auto i: result){
            nums[index] = i;
            index++;
        }
        return result.size();
        
    }
};


//optimal
//tc - O(N)
// sc - O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};