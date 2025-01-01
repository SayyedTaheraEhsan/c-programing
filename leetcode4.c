class Solution {
public:
/* frugal and simplified approach based on first principle
    int ma(vector<int>& prefix_sum){
        int max=0;
        for(int i:prefix_sum){
            if(max<i){
                max=i;
            }
        }
        return max;
    }
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> prefix_sum(n + 1, 0);
        for(int i=1;i<=n;++i){
            prefix_sum[i]=prefix_sum[i-1]+gain[i-1];
            cout<<(prefix_sum[i]);
        }
        return ma(prefix_sum);
    }*/
    int largestAltitude(vector<int>& gain) {
        int max=0;
        int pre_sum=0;
        for(int i=0;i<gain.size();++i){
            pre_sum+=gain[i];
            max=pre_sum>max?pre_sum:max;
        }
        return max;
    }
};