class Solution{	
	private:
	int Xorrr(int n){
		if(n%4==1) return 1;
		if(n%4==2) return n+1;
		if(n%4==3) return 0;
		return n;
	}
	public:
		int findRangeXOR(int l,int r){
			//your code goes here
			return Xorrr(l-1)^Xorrr(r);
		}
};