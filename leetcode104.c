class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for (char c : s) umap[c]++; // 🔢 Count character frequency
        for (int i = 0; i < s.length(); i++) 
            if (umap[s[i]] == 1) return i; // 🎯 Find the first unique character
        return -1; // ❌ No unique character found
    }
};