class Solution {
public:
    int search(vector<int> &nums, int k) {
       int low = 0;
       int high = nums.size()-1;
       while(low<=high){
        int mid = (high+low)/2;
        if(nums[mid]==k) return mid;
        //Left Sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=k && k<=nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //Right Sorted
        else{
            if(nums[mid]<=k && k<=nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
       }
       return -1;
    }
};