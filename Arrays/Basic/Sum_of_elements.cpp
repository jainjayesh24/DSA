//Tc - o(n)
//Sc - o(1)

class Solution{
public:
	int sum(int arr[], int n) {
		int total =0;
		for(int i=0;i<n;i++){
			total = total + arr[i];
		}
		return total;
	  
	}
};