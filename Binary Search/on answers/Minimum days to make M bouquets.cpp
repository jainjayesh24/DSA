// Time Complexity:O(n log m) where n is the size of nums and m is the difference between the minimum and maximum value in nums
// Space Complexity:O(1) as no additional space dependent on input size is used apart from a few variables.
class Solution {
private:
bool possible(vector<int> nums,int day,int k,int m){
  int count,bloom = 0;
  for(int i = 0;i<nums.size();i++){
    if(nums[i]<=day){
      count++;
    }else{
      bloom += (count/k);
      count = 0; 
    }
  }
  bloom += (count/k);
  return bloom>=m;
}
public:
int roseGarden(int n,vector<int> nums, int k, int m) {
    int ans = -1;
    if(m*k>n) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i = 0;i<nums.size();i++){
      mini = min(mini,nums[i]);
      maxi = max(maxi,nums[i]);
    }

    int low  = mini;int high = maxi;
    while(low<=high){
      int mid = low + (high-low)/2;
      bool pos = possible(nums,mid,k,m);
      if(pos){
        ans = mid;
        high = mid -1;
      }
      else{
        low = mid +1;
      }
    }
    return ans;
  }
};