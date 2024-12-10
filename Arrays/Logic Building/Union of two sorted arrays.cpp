//Brute
// TC - O(M+Nlog(M+N))
//SC - O(M+N)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> unionA;
        vector<int> result;
        for(int i = 0; i< nums1.size();i++ ){
            unionA.insert(nums1[i]);
        }

        for(int i = 0; i< nums2.size();i++ ){
            unionA.insert(nums2[i]);
        }

        for(auto i: unionA){
            result.push_back(i);
        }

        return result;

    }
};