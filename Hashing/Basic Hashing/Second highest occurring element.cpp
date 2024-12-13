// Time Complexity:O(n) where n is the size of the input vector due to the hash map creation and traversal
// Space Complexity:O(k) where k is the number of unique elements in the input vector due to the hash map storage
class Solution {
public:
    int secondMostFrequentElement(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int ele1 = -1, ele2 = -1;
        int fre1 = 0,fre2 = 0;

        for(auto i : hash){
            int ele = i.first;
            int fre = i.second;
            if(fre>fre1){
                fre2 = fre1;
                ele2 = ele1;
                fre1 = fre;
                ele1 = ele;
            }
            else if(fre == fre1){
                ele1 = min(ele1,ele);
            }

            else if(fre > fre2){
                fre2 = fre;
                ele2 = ele;
            }
            else if(fre == fre2){
                ele2 = min(ele2,ele);
            }
        }
        return ele2;

    }
};