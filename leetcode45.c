class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        int res = 0;
        for( string op : operations ){
            int n = records.size();
            if( isdigit( op[0] ) || op[0] == '-' ){
                int dig = stoi( op );
                records.push_back( dig );
            }
            else if( op == "+" ){
                records.push_back( records[n - 1] + records[n - 2] );
            }
            else if( op == "D" ){
                records.push_back( 2 * records[n - 1] );
            }
            else{
                records.pop_back();
            }
        }
        for( int i = 0; i < records.size(); i++ )
            res += records[i];
        return res;
    }
};