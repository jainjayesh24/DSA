//Brute
// Calculating each element and then obtaining pascal triangle 
// Tc -> o(N*3)
class Solution {
private:
int nCr(int n,int r){
    int res = 1;
    for(int i = 0 ;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i<=numRows;i++){
            vector<int> temp;
            for(int j = 1;j<=i;j++){
                temp.push_back(nCr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//optimal
// Calculating each row and then obtaining pascal triangle 

//Time Complexity:O(numRows^2) due to nested loop structure for generating each row of Pascal's triangle.
//Space Complexity:O(numRows^2) for storing the resulting Pascal's triangle in a 2D vector.

class Solution {
private:
vector<int> RowGen(int n){
    long long ans = 1;
    vector<int> row;
    row.push_back(ans);
    for(int i = 1; i<n;i++){
        ans = ans*(n-i);
        ans = ans/i;
        row.push_back(ans);
    }
    return row;
}
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        vector<vector<int>> Pascal;
        for(int i = 1;i<=numRows;i++){
            Pascal.push_back(RowGen(i));
        }
        return Pascal;
    }
};