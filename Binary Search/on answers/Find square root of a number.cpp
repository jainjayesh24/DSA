class Solution {
public:
    long long floorSqrt(long long n)  {
      long long low = 1,high = n;
      while(low<=high){
        long long mid = low+(high-low)/2;
        long long val = mid*mid;
        if(val <=(long long)(n)){
            low = mid+1;
        }
        else high = mid-1;
      }
      return high;
    }
};