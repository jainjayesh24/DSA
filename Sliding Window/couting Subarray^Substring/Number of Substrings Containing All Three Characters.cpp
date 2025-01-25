//Brute
// TC-> O(N2)
// SC-> O(3)
class Solution {
public:
    int numberOfSubstrings(string s) {
        //your code goes here
        int n = s.size();
        int count = 0;
        for(int i = 0;i<n;i++){
            int hash[3] = {0};
            for(int j = i; j<n;j++){
                hash[s[j]-'a'] = 1;
                if(hash[0]+hash[1]+hash[2]==3) count++;
            }
        }
        return count;
    }
};

//Optimal
// Time Complexity:The time complexity of the given code is O(n) due to the single pass over the string with size n.
// Space Complexity:The space complexity is O(1) because the space used does not depend on the size of the input string.
class Solution {
public:
    int numberOfSubstrings(string s) {
        //your code goes here
        int n = s.size();
        int count = 0;
        int seen[3] = {-1,-1,-1};
        for(int i = 0; i<n;i++){
            seen[s[i]-'a'] = i;
            if(seen[0]!=-1 && seen[1]!=-1 && seen[2]!=-1){
                count += 1+(min({seen[0],seen[1],seen[2]}));
            }
        }
        return count;
    }
};