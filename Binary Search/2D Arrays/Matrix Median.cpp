//Brute
class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
      vector<int> ans;
      int n = matrix.size();
      int m = matrix[0].size();
      for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.push_back(matrix[i][j]);
        }
      }
      sort(ans.begin(),ans.end());
      int median = (n*m)/2;
      return ans[median];
    }
};

//Optimal
// Time Complexity:The time complexity is O(n * log(m) + n * log(max - min)), where n is the number of rows and m is the number of columns in the matrix.
// Space Complexity:The space complexity is O(1) as it uses a constant amount of space for variables.
class Solution{
private:
int upperBound(vector<int> nums,int x){
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]>x){
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}

int SmallE(vector<vector<int>>&nums,int x,int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        count += upperBound(nums[i],x);
    }
    return count;
}
public:
    int findMedian(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX; int high = INT_MIN;
        for(int i = 0;i<n;i++){
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][m-1]);
        }

        int req = (n*m)/2;

        while(low<=high){
            int mid = low + (high - mid)/2;
            int smaller = SmallE(matrix,mid,n);
            if(smaller<=req) low = mid +1;
            else high = mid -1;
        }
        return low;
    }
};