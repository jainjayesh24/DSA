class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int mini = INT_MAX;
        int low = 0; int high = nums.size()-1;
        int index = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            //Left sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<mini){
                    mini = nums[low];
                    index = low;
                }
                low = mid+1;
            }
            //Right sorted
            else{
                if (nums[mid] < mini) {
                    index = mid;
                    mini = nums[mid];
                }
                high = mid-1;
            }

        }
        return index;
    }
};