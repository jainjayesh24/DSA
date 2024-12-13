//Brute
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int XOR = 0;
                for(int k =i;k<=j;k++){
                    XOR = XOR^nums[k];
                }
                if(XOR == k) count++;
            }
        }
        return count;
    }
};

//Better
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int XOR = 0;
            for(int j=i;j<nums.size();j++){
                    XOR = XOR^nums[j];
                    if(XOR == k) count++;
                }

        }
        return count;
    }
};

//Optimal
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int XOR = 0;
        map<int, int> mpp; 
        mpp[XOR]++; 
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            XOR = XOR ^ nums[i];
            int x = XOR ^ k;
            cnt += mpp[x];
            mpp[XOR]++;
        }
        return cnt;
    }
};