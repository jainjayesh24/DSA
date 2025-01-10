class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
			unordered_map <int,int> mpp;
			vector<int> ans;

			for(int i = 0;i<nums.size();i++){
				mpp[nums[i]]++;
			}
			for(auto it: mpp){
				if(it.second==1) ans.push_back(it.first);
			}
			sort(ans.begin(),ans.end());
			return ans;
		}
};