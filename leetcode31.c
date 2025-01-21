class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if (n*m!=r*c) return mat;
        vector<vector<int>> ans(r, vector<int> ( c, 1));
        int p=0;
        int u=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(p<c){
                    ans[u][p]=mat[i][j];
                    p++;
                }
                else if (p==c){
                    p=0;
                    u++;
                    ans[u][p]=mat[i][j];
                    p++;
                }
            }
        }
            return ans;
        
    }
};