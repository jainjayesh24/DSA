//Brute
//2O(N*2)
//O(N2)
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int N = matrix.size();
        vector<vector<int>> rotate(N,vector<int>(N,0));
        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++){
                rotate[j][((N-1)-i)] = matrix[i][j];
            }
        }
        for(int i = 0; i < rotate.size(); i++){
            for(int j = 0; j < rotate[0].size(); j++){
                matrix[i][j] = rotate[i][j];
            }
        }

    }
};

//Optimal
// Time Complexity:O(n^2) due to two nested loops iterating over the matrix
// Space Complexity:O(1) as the rotation is done in place with no additional space
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};