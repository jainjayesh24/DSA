// Time Complexity:The time complexity of the code is O(n) because each element in the array is processed at most twice by the two pointers.
// Space Complexity:The space complexity of the code is O(1) as it uses only a fixed amount of extra space.
class Solution {
   private:
    int func(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<0) return 0;
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while (r < n) {
            sum += nums[r] % 2;
            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

   public:
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        // your code goes here
        return func(nums,k)-func(nums,k-1);
    }
};