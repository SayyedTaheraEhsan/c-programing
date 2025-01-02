class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        // Traverse through the flowerbed
        for (int i = 0; i < size; ++i) {
            // Check if the current spot and adjacent spots are empty
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                
                // Place a flower in the current spot
                flowerbed[i] = 1;
                --n;  // Decrease the count of flowers to place
                
                // Skip the next index, as we can't place adjacent flowers
                i++;
            }
        }
        
        // Return whether we were able to place all flowers
        return n <= 0;
    }
};