//Brute
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        int i = 0; int j =0;
        vector<int> arr3;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]) arr3.push_back(arr1[i++]);
            else arr3.push_back(arr2[j++]);
        }
        while(i<n1){
            arr3.push_back(arr1[i++]);
        }
        while(j<n2){
            arr3.push_back(arr2[j++]);
        }
        if (n % 2 == 1) {
            return (double)arr3[n / 2];
        }

        double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
        return median;
    }
};

//Better
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int index2 = n/2;
        int index1 = (n % 2 == 0) ? index2 - 1 : index2;
        int count = 0; int i = 0; int j = 0;
        int ele1 = -1; int ele2 = -1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count == index1) ele1 = nums1[i];
                if(count == index2) ele2 = nums1[i];
                count++;
                i++;
            }else{
                if(count == index1) ele1 = nums2[j];
                if(count == index2) ele2 = nums2[j];
                count++;
                j++;
            }
        }
        while(i<n1){
            if(count == index1) ele1 = nums1[i];
            if(count == index2) ele2 = nums1[i];
            count++;
            i++;
        }
        while(j<n2){
            if(count == index1) ele1 = nums2[j];
            if(count == index2) ele2 = nums2[j];
            count++;
            j++;
        }
        return (n % 2 == 1) ? (double)ele2 : ((double)ele1 + (double)ele2) / 2.0;
    }
};

//Optimal
// Time Complexity:O(log(min(n1, n2))) due to binary search on the smaller array
// Space Complexity:O(1) as only a constant amount of extra space is used
class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if(n1>n2) return median(arr2,arr1);
        int n = n1+n2;
        int left = (n1+n2+1)/2;
        int low =0; int high = n1;
        while(low<=high){
            int mid1 = low + (high-low)/2;
            int mid2 = left-mid1;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;
            if(mid1<n1) r1 = arr1[mid1];
            if(mid2<n2) r2 = arr2[mid2];
            if(mid1-1>=0) l1 = arr1[mid1-1];
            if(mid2-1>=0) l2 = arr2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2 == 1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2) high = mid1 -1;
            else low = mid1 +1;
        }
        return 0;
    }
};