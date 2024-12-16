//Brute

class Solution {
private:
int func(vector<int> nums,int k){
    int total = 0;
    for(int i = 0;i<nums.size();i++){
        total += ceil((double)(nums[i])/(double)(k));
    }
    return total;
}
public:
int minimumRateToEatBananas(vector<int> nums, int h) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0;i< n;i++ ){
            maxi = max(maxi,nums[i]);
        }

        for(int i = 1;i<=maxi;i++){
            int req = func(nums,i);
            if(req<=h) return i;
        }

        return -1;
    }
};


//Optimal
// Time Complexity:O(n log m) where m is the max number in nums and n is the size of nums, it includes O(n) for finding max and O(n) for total in the binary search
// Space Complexity:O(1) for local variables and O(n) for input storage, overall O(n)

class Solution {
private:
int findMax(vector<int> nums,int n){
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

int totalH(vector<int> nums,int k){
    int total = 0;
    for(int i = 0;i<nums.size();i++){
        total += ceil((double)(nums[i])/(double)(k));
    }
    return total;
}
public:
int minimumRateToEatBananas(vector<int> nums, int h) {
    int n = nums.size();
    int high = findMax(nums,n);
    int low = 1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        int total = totalH(nums,mid);
        if(total<=h){
            ans = mid;
            high = mid - 1;
        } 
        else{
            low = mid +1;
        }
    }

    return ans;

    }
};
