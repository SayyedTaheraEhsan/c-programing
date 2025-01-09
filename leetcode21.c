#include<bits/stdc++.h>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = -1 ; 
        for(int i = 0  ; i< candies.size() ; i++){
           maxi = max ( candies[i],maxi ) ; 
        }
        int n = candies.size();
        vector<bool> b( n , false) ; 
        for(int i = 0 ; i< candies.size(); i++){
            if(candies[i] + extraCandies >= maxi){
                b[i] = true ; 
            }
            else{
                b[i] = false ; 
            }
        }
        return   b ; 
    }
};