class Solution {   
public:    
    int minBitsFlip(int start, int goal) { 
        // XOR start and goal to find differing bits
        int difference = start ^ goal;
        int count = 0;
        // Count the number of 1s in the result of the XOR operation
        for (int i = 0; i < 31; i++) {
            if ((difference & (1 << i)) != 0) count++;
        }
        return count;
    }
};



// Line 5: Suggest renaming variable 'ans' to 'difference' for better clarity
// Line 8: Adding a comment to explain the logic behind counting 1s