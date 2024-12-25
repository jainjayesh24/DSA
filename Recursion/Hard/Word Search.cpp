class Solution {
private:
bool func(int index,int i,int j,int n,int m,vector<vector<char>> &board,string &word){
    if(index==word.size()) return true;
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) return false;
    bool ans = false;
    char temp = board[i][j];
        board[i][j] = '#';
    //top
    if(i-1>=0) ans |= func(index+1,i-1,j,n,m,board,word);
    //bottom
    if(i+1<n) ans |= func(index+1,i+1,j,n,m,board,word);
    //right
    if(j+1<m) ans |= func(index+1,i,j+1,n,m,board,word);
    //left
    if(j-1>=0) ans |= func(index+1,i,j-1,n,m,board,word);
    board[i][j] = temp;
    return ans;
}
public:
    bool exist(vector<vector<char> >& board, string word) {
        //your code goes here
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(func(0,i,j,n,m,board,word)==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};