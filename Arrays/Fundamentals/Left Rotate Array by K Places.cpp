//Brute\
// TC - 3*O(n)
//Sc - O(n)

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
        k = k%n;
        for(int i=0;i<k;i++){
            temp.push_back(nums[i]);
        }
        for(int i=k;i<n;i++){
            nums[i-k] = nums[i];
        }

        for(int i = n-k;i<n;i++){
            nums[i] = temp[i-(n-k)];
        }
}
};


//optimal
// TC - 2*O(n)
//Sc - O(1)
class Solution {
private:
    void reverse(vector<int>& nums, int l, int r) { 
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1); 
        reverse(nums, 0, n - 1);
        }
};
