// Time Complexity:O(4^N * N) where N is the length of digits due to recursive calls and string concatenation
// Space Complexity:O(N) for the recursion stack and O(4^N) for storing the combinations in ans
class Solution {
private:
void func(int index,string s,vector<string> &ans,string &digits,string combo[]){
    if(index == digits.size()){
        ans.push_back(s);
        return;
    }
    int digi = digits[index]-'0';
    for(int i = 0;i<combo[digi].size();i++){
        func(index+1,s + combo[digi][i],ans,digits,combo);
    }
}
public:
    vector<string> letterCombinations(string digits) {
        //your code goes here
        string combo[] =  {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s="";
        func(0,s,ans,digits,combo);
        return ans;
    }
};