class Solution{
public:
    void reverse(int arr[], int n){
        int l=0;
        int r = n-1;
        while(l<r){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
    }
};
