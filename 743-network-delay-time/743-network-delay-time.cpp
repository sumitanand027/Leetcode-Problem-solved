class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        
        vector<int> dist( n + 1 , INT_MAX );
        
        dist[ k ] = 0;
        
        for( int i = 0 ; i < n ; i++ )
        {
            for( auto it : edges )
            {
                if( 1LL * dist[ it[0]] + it[2] < dist[ it[1] ] )
                    dist[ it[1] ] = dist[ it[0] ] + it[2];
            }
        }
        
        int ans = 0;
        
        for( int i = 1 ; i <= n ; i++ ) 
        {
            ans = max( ans , dist[i] );
        }
        
        if( ans == INT_MAX ) return -1;
        return ans;
    } 
};