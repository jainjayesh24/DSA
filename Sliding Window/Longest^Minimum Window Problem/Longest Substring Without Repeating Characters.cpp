//Brute
//TC -> O(N2)
//SC -> O(256)
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        //your code goes here
        int maxi = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
          int j = i; 
          vector<int> hash(256,0);
          for(j=i;j<n;j++){
            if(hash[s[j]]==1) break;
            maxi = max(maxi,j-i+1);
            hash[s[j]] = 1;
          }
        }
        return maxi;
    }
};

//Optimal
// Time Complexity:The time complexity of the code is O(n) due to the single traversal of the string with two pointers, where n is the length of the string.
// Space Complexity:The space complexity is O(1) because the space used for the hash table is constant (256 integer space) and does not depend on the input size.
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        //your code goes here
        int l = 0,r = 0; int maxi = 0;
        int n = s.size();
        int hash[256];
        for (int i = 0; i < 256; ++i) {
            hash[i] = -1;
        }
        while(r<n){
          if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
              l = hash[s[r]]+1;
            }
          }
          maxi = max(maxi,r-l+1);
          hash[s[r]] = r;
          r++;
        }
        return maxi;
    }
};