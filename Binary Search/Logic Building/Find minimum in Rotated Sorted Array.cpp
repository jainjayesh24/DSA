class Solution {
public:
    int findMin(vector<int> &arr)  {
        int result = INT_MAX;
        int low = 0; int high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            //Left is sorted
            if(arr[low]<=arr[mid]){
                result = min(result,arr[low]);
                low = mid+1;
            }
            //Right is sorted
            else{
                result = min(result,arr[mid]);
                high = mid-1;

            }
        }
        return result;
    }
};