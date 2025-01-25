//Brute
//TC-> O(N2)
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n = fruits.size();
        int maxi = 0;
        for(int i = 0;i<n;i++){
          set<int> st;
          for(int j = i;j<n;j++){
            st.insert(fruits[j]);
            if(st.size()<=2) maxi = max(maxi,j-i+1);
            else break;
          }
        }
        return maxi;
    }
};

// Better
// Time Complexity:The time complexity of the code is O(n) because there is a single while loop iterating over the fruits vector with two pointers moving across it.
// Space Complexity:The space complexity of the code is O(1), or more specifically O(k) where k is the maximum number of unique fruits allowed (which is 2 in this case).
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n = fruits.size();
        int maxi = 0;
        unordered_map<int,int> mpp;
        int l =0; int r = 0;
        while(r<n){
          mpp[fruits[r]]++;
          if(mpp.size()>2){
            while(mpp.size()>2){
              mpp[fruits[l]]--;
              if(mpp[fruits[l]]==0){
              mpp.erase(fruits[l]);
              }
              l++;
            }
          }
          if(mpp.size()<=2) maxi = max(maxi,r-l+1);
          r++;
        }
        return maxi;
    }
};

//optimal
// Time Complexity:The time complexity of the given code is O(n), where n is the number of elements in the 'fruits' vector.
// Space Complexity:The space complexity of the given code is O(1) for storing at most 3 keys in the unordered_map.

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int n = fruits.size();
        int maxi = 0;
        unordered_map<int,int> mpp;
        int l =0; int r = 0;
        while(r<n){
          mpp[fruits[r]]++;
          if(mpp.size()>2){
            if(mpp.size()>2){
              mpp[fruits[l]]--;
              if(mpp[fruits[l]]==0){
              mpp.erase(fruits[l]);
              }
              l++;
            }
          }
          if(mpp.size()<=2) maxi = max(maxi,r-l+1);
          r++;
        }
        return maxi;
    }
};