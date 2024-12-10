//Brute
//Linear Search Approach
//TC-o(n2)
//SC - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        for(int i =0;i<=N;i++){
            int flag = 0;
            for(int j = 0;j<N;j++){
                if(nums[j]==i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return i;
        }
    }
};


//Better
// Hashing Approach
//TC-2*o(n)
//SC - On)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int hash[N+1] = {0};
        for(int i = 0;i<N;i++){
            hash[nums[i]] = 1;
        }

        for(int i =0;i<sizeof(hash);i++){
            if(hash[i] == 0) return i;
        }
    }
};


//Optimal
// Sum Approach
//TC-o(n)
//SC - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int sum = (N*(N+1))/2;
        int s2 = 0;
        for(int i = 0;i<N;i++){
            s2+=nums[i];
        }
        return sum-s2;
    }
};
