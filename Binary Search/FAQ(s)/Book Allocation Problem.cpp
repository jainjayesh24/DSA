//Brute
//Tc -> O(sum-max+1)*O(n)
//Sc -> O(1)

class Solution {
private:
int CountPage(vector<int> nums,int Pages){
    int student =1; int pagesStudent = 0;
    for(int i=0;i<nums.size();i++){
        if(pagesStudent+nums[i]<=Pages) pagesStudent += nums[i];
        else{
            student++;
            pagesStudent = nums[i];
        }
    }
    return student;

}
public:
    int findPages(vector<int> &nums, int m)  {
        if(m>nums.size()) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        for(int i = low ; i<=high ;i++){
            if(CountPage(nums,i)==m) return i;
        }
    }
};


//Optimal
// Time Complexity:The time complexity is O(n log S), where n is the number of books and S is the sum of pages in all books, due to the binary search and the CountPage function.
// Space Complexity:The space complexity is O(1) since the algorithm uses a constant amount of space regardless of input size.
class Solution {
private:
int CountPage(vector<int> nums,int Pages){
    int student =1; int pagesStudent = 0;
    for(int i=0;i<nums.size();i++){
        if(pagesStudent+nums[i]<=Pages) pagesStudent += nums[i];
        else{
            student++;
            pagesStudent = nums[i];
        }
    }
    return student;

}
public:
    int findPages(vector<int> &nums, int m)  {
        if(m>nums.size()) return -1;
        int ans = -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high -low)/2;
            if(CountPage(nums,mid)<=m){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;   
        }
        return ans;
    }
};