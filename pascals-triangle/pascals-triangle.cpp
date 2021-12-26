class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > ans;
        ans.push_back( {1} );
        if( numRows == 1 )
            return ans;
        ans.push_back( {1,1} );
        if( numRows == 2 )
            return ans;
        int count = 2;
        while( numRows > 2 ) {
            count++;
            vector<int> temp(count);
            temp[0] = 1;
            temp[count-1] = 1;
            for( int i = 1 ; i < count - 1 ; i++ ) {
                temp[i] = ans[count - 2][i-1] + ans[count - 2][i];
            }
            numRows--;
            ans.push_back( temp );
        }
        return ans;
    }
};
