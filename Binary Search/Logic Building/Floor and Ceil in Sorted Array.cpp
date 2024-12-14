#include <vector>
using namespace std;

class Solution {
private:
    int Cceil(vector<int> &n, int x) {
        int low = 0, high = n.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (n[mid] >= x) {
                ans = n[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int Ffloor(vector<int> &n, int x) {
        int low = 0, high = n.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (n[mid] <= x) {
                ans = n[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int fl = Ffloor(nums, x); 
        int c = Cceil(nums, x);
        return {fl,c};
    }
};
