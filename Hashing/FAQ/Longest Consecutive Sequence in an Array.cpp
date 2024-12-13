//Brute 
// Tc - O(N2)
// Sc - o(1)
class Solution {
private:
bool ls(vector<int> n,int X){
    for(int i =0;i<n.size();i++){
        if(n[i]==X) return true;
    }
    return false;
}
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        for(int i = 0;i<nums.size();i++){
            int x = nums[i];
            int count = 1;
            while(ls(nums,x+1)){
                x +=1;
                count++;
            }
            longest = max(longest,count);
        }
        return longest;
    }
};


//Better
// Tc - O(N)+O(NlogN)
// Sc - o(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        int curCounter = 0;
        int LastS = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(nums[i]-1==LastS){
                curCounter++;
                LastS = nums[i];
            }
            else if(nums[i]!=LastS){
                curCounter = 1;
                LastS = nums[i];
            }
            longest = max(longest,curCounter);
        }
        return longest;
    }
};

//Optimal
//TC - 3*O(n) 
//Sc - O(n) 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> s;
        for(int i = 0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto i: s){
            if(s.find(i-1)==s.end()){
                int count = 1;
                int x = i;
                while(s.find(x+1)!=s.end()){
                    count++;
                    x++;
                }
                longest = max(longest,count);
            }
        }

        return longest;
    }
};