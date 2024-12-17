// Better
//  Time Complexity:O(n) where n is the number of elements in nums, due to the single loop for counting and another for filtering
//  Space Complexity:O(k) where k is the number of unique elements in nums stored in the map
class Solution
{
public:
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        vector<int> ans;
        map<int, int> mpp;
        int n = nums.size() / 3;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }

        for (auto it : mpp)
        {
            int ele = it.first;
            int frq = it.second;
            if (frq > n)
                ans.push_back(ele);
        }

        return ans;
    }
};