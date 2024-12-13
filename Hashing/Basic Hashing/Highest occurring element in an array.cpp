#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int, int> freq;  
        int maxcount = 0;
        int ele = INT_MAX;

        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxcount || (freq[num] == maxcount && num < ele)) {
                maxcount = freq[num];
                ele = num;
            }
        }

        return ele;
    }
};
