//Brute
//Tc -> O(n)
class Solution {
public:
    int findPeakElement(vector<int> &arr) {
        int n = arr.size()-1; 
        for(int i =0;i<arr.size();i++){
            if((i==0 ||arr[i-1]<arr[i]) && (i==n-1||arr[i]>arr[i+1])){
                return i;
            }
        }
        return -1;
    }
};

//Optimal
// Time Complexity:O(log n) due to the binary search implemented in the while loop
// Space Complexity:O(1) as it uses a constant amount of extra space
class Solution {
public:
    int findPeakElement(vector<int> &arr) {
      int n  = arr.size();
      int low = 1;
      int high = n-2;
      if(n==1) return 0;
      if(arr[0]>arr[1]) return 0;
      if(arr[n-1]>arr[n-2]) return n-1;
      while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
           low = mid +1; 
        }else{
            high = mid -1;
        }
      }
      return -1;
    }
};