// Time Complexity:O(m * n), where m is the number of rows and n is the number of columns in the matrix
// Space Complexity:O(m * n) for storing the result vector ans, where m is the number of rows and n is the number of columns in the matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int column = matrix[0].size();
        int top =0,left = 0;
        int right = column-1;int bottom = row-1; 
        while(top<=bottom && left<=right){
            for(int i = left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i = right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};