// Time Complexity:O(n log n) due to sorting, and O(n) for the CanPlace function, resulting in O(n log n) overall
// Space Complexity:O(1) for variables, but O(n) for input storage, so O(n) total
class Solution {
private:
bool CanPlace(vector<int> nums,int k,int distance){
    int count = 1; int last = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]-last>=distance){
            count++;
            last = nums[i];
        } if(count>=k) return true;
    }
    return false;
}
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 1;
        int high = nums[nums.size()-1]-nums[0];
        while(low<=high){
            int mid = low + (high - low)/2;
            if(CanPlace(nums,k,mid)) low = mid +1;
            else high = mid -1;
        }
        return high;
    }
};