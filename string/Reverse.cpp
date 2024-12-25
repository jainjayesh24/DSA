// Reverse a string
// Given a string, the task is to reverse it. The string is represented by an array of characters s. Perform the reversal in place with O(1) extra memory.


//Brute Approach
// tc - 2*o(n)
//sc - o(n)
class Solution{	
	public:		
		void reverseString(vector<char>& s){
			//your code goes here
			int n = s.size();
			int dup[n];

			for(int i = 0;i<n;i++){
				dup[n-i-1] = s[i];
			}

			for(int i = 0; i<n;i++){
				s[i] = dup[i];
			}
		}
};


//optimal 
// tc - o(n/2)
//sc - o(1)
class Solution{	
	public:		
		void reverseString(vector<char>& s){
			//your code goes here
			int l =0;
			int r = s.size()-1;
			while(l<r){
				swap(s[l],s[r]);
				l++;
				r--;
			}
		}
};