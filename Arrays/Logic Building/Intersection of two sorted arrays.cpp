//Brute
//tc - O(m+n)
//sc - O(n)
class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        vector<int> vis(nums2.size(),0);
        for(int i = 0;i<nums1.size();i++){
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i] == nums2[j] && vis[j]==0){
                    intersection.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
                if(nums2[j]>nums1[i]){
                    break;
                }
            }
        }
        return intersection;
    }
};

//optimal
//Tc- O(M), where M is the length of that array which has less elements.
// Sc - o(1)
class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        int i = 0;
        int j =0;
        int a = nums1.size();
        int b = nums2.size();
        while(i<a && j<b){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums2[j]<nums1[i]){
                j++;
            }
            else{
                inter.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        return inter;
    }
};

