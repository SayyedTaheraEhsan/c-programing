class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z_i = 0;
        for (int i = 0; i < nums.size(); i++) {  // Corrected size() and added braces
            if (nums[i] != 0) {
                swap(nums[z_i++], nums[i]);  // Corrected typo: nums instead of num, and added semicolon
            }
        }
    }
};