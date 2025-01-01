#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;  // Copy the original heights array
        sort(expected.begin(), expected.end());  // Sort the expected array
        
        int count = 0;
        
        // Compare each element in heights with expected and count the mismatches
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;  // Increment count when there's a mismatch
            }
        }
        
        return count;  // Return the number of mismatched indices
    }
};