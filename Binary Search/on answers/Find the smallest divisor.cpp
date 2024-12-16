// Time Complexity:O(n log(max_element)) where n is the size of nums due to the binary search on the divisor and the SUMD function which iterates through the array
// Space Complexity:O(1) as only a constant amount of space is used, aside from the input array
class Solution {
private:
int SUMD(vector<int> arr,int m){
  int sum = 0;
  for(int i = 0;i<arr.size();i++){
    sum = sum + ceil((double)arr[i]/(double)(m));
  }
  return sum;
}
public:
  int smallestDivisor(vector<int> &nums, int limit) {
       int n = nums.size();
       if(n>limit) return -1;
       int low = 1, high = *max_element(nums.begin(),nums.end());
       while(low<=high){
        int mid = low + (high - low)/2;
        if(SUMD(nums,mid)<=limit){
          high = mid -1;
        }
        else{
          low = mid +1;
        }
       }
       
    }
};