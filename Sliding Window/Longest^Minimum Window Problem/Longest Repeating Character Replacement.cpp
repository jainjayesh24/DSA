//Brute
class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int n = s.size();
        int maxfre = 0 ; int maxi = 0;
        for(int i =0;i<n;i++){
            int hash[26] = {0};
            for(int j = i;j<n;j++){
                hash[s[j]-'A']++;
                maxfre = max(maxfre,hash[s[j]-'A']);
                int change = (j-i+1)-maxfre;
                if(change<=k) maxi = max(maxi,j-i+1);
                else break;
            }
        }
        return maxi;
    }
};

//Better
class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int n = s.size();
        int maxfre = 0 ; int maxi = 0;
        int l =0; int r = 0;
        int hash[26] = {0};
        while(r<n){
            hash[s[r]-'A']++;
            maxfre = max(maxfre,hash[s[r]-'A']);
            while((r-l+1)-maxfre>k){
                hash[s[l]-'A']--; maxfre = 0;
                for(int i =0;i<26;i++){
                    maxfre = max(maxfre,hash[i]);
                }
                l++;
            }
            if((r-l+1)-maxfre<=k){
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};

//Optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        int n = s.size();
        int maxfre = 0 ; int maxi = 0;
        int l =0; int r = 0;
        int hash[26] = {0};
        while(r<n){
            hash[s[r]-'A']++;
            maxfre = max(maxfre,hash[s[r]-'A']);
            if((r-l+1)-maxfre>k){
                hash[s[l]-'A']--; maxfre = 0;
                for(int i =0;i<26;i++){
                    maxfre = max(maxfre,hash[i]);
                }
                l++;
            }
            if((r-l+1)-maxfre<=k){
                maxi = max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};