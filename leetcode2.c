class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(target - nums[i]) != myMap.end()) {
                return {myMap.find(target - nums[i])->second, i};
            }
            myMap[nums[i]] = i;
        }
        return {};
    }
};