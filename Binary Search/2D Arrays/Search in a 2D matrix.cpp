//Better
// Time Complexity:O(n log m) due to n iterations over m elements in binary search
// Space Complexity:O(1) as no extra space is used except for a few variables.
class Solution{
private:
bool checkNum(vector<int> nums,int x){
    int low = 0; int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==x) return true;
        if(nums[mid]>x){
            high = mid -1;
        }else low = mid + 1;
    }
    return false;

}
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
           if(checkNum(mat[i],target)){
            return true;
           }
        }
        return false;
    }
};

//Optimal
// Time Complexity:The time complexity of the given code is O(log(n*m)) due to the binary search algorithm applied over a virtual 1D representation of the 2D matrix.
// Space Complexity:The space complexity of the given code is O(1) as it uses a constant amount of extra space for variables.
class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = (n*m-1);
        while(low<=high){
            int mid = low + (high - low)/2;
            int row = mid/m;
            int col = mid%m;
            if(mat[row][col]==target) return true;
            if(mat[row][col]>target) high = mid -1;
            else low = mid +1;
        }
        return false;
    }
};