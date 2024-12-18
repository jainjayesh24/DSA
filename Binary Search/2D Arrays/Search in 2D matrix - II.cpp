// Time Complexity:The time complexity is O(n + m) where n is the number of rows and m is the number of columns due to the while loop traversing the matrix.
// Space Complexity:The space complexity is O(1) because no additional space is used that scales with input size.
class Solution{
public:
 bool searchMatrix(vector<vector<int>> &matrix, int target){
      int m = matrix[0].size();
      int n = matrix.size();
      int row = 0;
      int col = m -1;
      while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]>target) col--;
        else row++;
      }
      return false;
    }
};