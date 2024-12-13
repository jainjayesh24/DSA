// Time Complexity:O(n) where n is the number of elements in nums, due to the single pass to count frequencies and another to find max and min frequencies
// Space Complexity:O(k) where k is the number of unique elements in nums for storing their frequencies in the hash map
class Solution {
public:
    int sumHighestAndLowestFrequency(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }

        int MaxF = 0,MinF=nums.size();
        for(auto i : hash){
            int freq = i.second;
            
            MaxF = max(MaxF,freq);
            MinF = min(MinF,freq);
        }
        return MaxF+MinF;
    }
};
