// Time Complexity:The time complexity is O(n log m), where n is the number of rows and m is the number of columns, due to binary searching through columns while finding the maximum element in rows.
// Space Complexity:The space complexity is O(1) as we are using a constant amount of space regardless of the input size.
class Solution {
private:
int Maxele(vector<vector<int>> nums,int col){
    int n = nums.size();
    int maxi = INT_MIN;
    int index = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i][col]>maxi){
            maxi = nums[i][col];
            index = i;
        }
    }
    return index;
}
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m;
        while(low<=high){
            int mid = low + (high -low)/2;
            int row = Maxele(mat,mid);
            int left = INT_MIN;
            int right = INT_MIN;
            if(mid-1>=0){
                left = mat[row][mid-1];
            }
            if(mid+1<m){
                right = mat[row][mid+1];
            }

            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }else if(left>mat[row][mid]) high = mid-1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};