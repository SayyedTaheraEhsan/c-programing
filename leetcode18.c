class Solution {
public:
    long long thirdMax(vector<int>& nums) {
        long long first_max, second_max, third_max;
        first_max = second_max = third_max = LLONG_MIN;

        for (long long num : nums) {

            // check if we have seen this value earlier
            if (num == first_max || num == second_max || num == third_max) continue;

            // Update maximums if current number is greater
            if (num > first_max) {
                // Shift previous maximums down
                third_max = second_max;
                second_max = first_max;
                first_max = num;
            } else if (num > second_max) {
                // Shift previous second maximum down
                third_max = second_max;
                second_max = num;
            } else if (num > third_max) {
                third_max = num;
            }
        }

        // If third maximum doesn't exist (still a LLONG_MIN)
        // Then return largest number from the array
        if (third_max == LLONG_MIN) {
                return first_max;
        }  

        return third_max;          
    }
};