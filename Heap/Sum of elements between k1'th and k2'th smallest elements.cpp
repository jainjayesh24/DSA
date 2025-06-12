typedef long long ll;
class Solution {
    private:
    ll helper(ll arr[],ll k,ll n){
        priority_queue<ll> pq;
        for(ll i = 0;i<n;i++){
            pq.push(arr[i]);
            
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        return pq.top();
    }
  public:

    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        ll first = helper(A,K1,N);
        ll second = helper(A,K2,N);
        ll sum = 0;
        for(ll i =0;i<N;i++){
            if(A[i]>first && A[i]<second) sum += A[i];
            
        }
        
        return sum;
    }
};