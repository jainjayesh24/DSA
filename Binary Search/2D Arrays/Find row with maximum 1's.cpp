//Brute
//TC -> O(n*m)
class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();
    int cont_max = 0;
    int index = -1;
    for(int i = 0;i<n;i++){
      int count = 0;
      for(int j =0;j<m;j++){
        count+=mat[i][j];
      }
      if(count>cont_max){
        cont_max = count;
        index = i;
      }
    }
    return index;
    }
};
//Optimal
//TC-> O(n*logm)
class Solution {
  private:
  int firstOcc(vector<int> nums,int n,int x){
    int low = 0; int high = n-1;
    int ans = n;
    while(low<=high){
      int mid = low + (high - low)/2;
      if(nums[mid]>=x){
        ans = mid;
        high = mid -1;
      }else low = mid + 1;
    }
    return ans;
  }
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();
    int count_max = 0;
    int index = -1;
    for(int i = 0;i<n;i++){

      int count = m - firstOcc(mat[i],m,1);
      if(count>count_max){
        count_max = count;
        index = i;
      }
    }
    return index;
  }
};