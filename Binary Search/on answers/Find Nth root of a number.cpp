class Solution {
private:
int func(int mid,int N,int M){
  long long ans = 1;
  for(int i = 0;i<N;i++){
    ans = ans*mid;
    if(ans > M) return 2;
  }
  if(ans == M) return 1;
  return 0;
}
public:
  int NthRoot(int N, int M) {
       int low = 0;int high = M;
       while(low<=high){
        int mid = low + (high - low)/2;
        if(func(mid,N,M)==1) return mid;
        if(func(mid,N,M)==2) high = mid -1;
        else low = mid+1;
       }
       return -1;
    }
};
