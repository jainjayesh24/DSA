// Time Complexity:The time complexity is O(n log n + m log m) due to sorting both Student and Cookie vectors and O(n + m) for the while loop.
// Space Complexity:The space complexity is O(1) as no additional space that grows with input size is used.
class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        //your code goes here
        sort(Student.begin(),Student.end());
        sort(Cookie.begin(),Cookie.end());
        int n = Student.size();
        int m = Cookie.size();
        int l = 0;
        int r = 0;
        while(l<n && r<m){
            if(Cookie[r]>=Student[l]){
                l++;
            }
            r++;
        }
        return l;
    }
};