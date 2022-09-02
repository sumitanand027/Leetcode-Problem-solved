class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
        
        sort( inte.begin(), inte.end() );
        int lastS = inte[0][0], lastE = inte[0][1];
        
        vector< vector<int> > ans;
        
        for( int i = 1; i < inte.size(); i++ )
        {
            if( inte[i][0] > lastE ) {
                ans.push_back( {lastS , lastE} );
                lastS = inte[i][0];
                lastE = inte[i][1];
            } else {
                lastE = max( lastE , inte[i][1] );
            }
        }
        ans.push_back({lastS , lastE} );
        return ans;
    }
};