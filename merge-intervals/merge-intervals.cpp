class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& in ) {
        sort( in.begin() , in.end() );
        
        vector< vector<int> > ans;
        ans.push_back( in[0] );
        for( int i = 1 ; i < in.size() ; i++ ) 
        {
            if( ans.back()[1] < in[i][0] ) 
            {
                ans.push_back( in[i] );
            } else 
            {
                ans.back()[1] = max( ans.back()[1] , in[i][1] );
            }
        }
        return ans;            
    }
};