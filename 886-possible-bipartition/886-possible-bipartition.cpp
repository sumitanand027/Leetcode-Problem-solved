class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        
        vector< vector<int> > adj( n + 1 );
        
        for( int i = 0 ; i < d.size() ; i++ )
        {
            adj[ d[i][0] ].push_back( d[i][1] );
            adj[ d[i][1] ].push_back( d[i][0] );
        }
        
        vector<int> color(n+1,-1);  
        queue<int> q;
        
        for( int i = 1 ; i <= n ; i++ )
        {
            if( color[i] == -1 )
            {
                q.push( i );
                color[ i ] = 0;

                while( !q.empty() )
                {
                    int k = q.front();
                    q.pop();

                    int parent = color[k];
                    for( auto it : adj[k] ) 
                    {
                        if( color[it] == -1 ) {
                            color[it] = parent == 1 ? 0 : 1;
                            q.push( it );
                        } else {
                            if( parent == color[it] ) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        
        return true;
    }
};






