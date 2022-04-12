class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        
        unordered_map<int,vector<int> > adj;
        
        
        for( int i = 0 ; i < edges.size() ; i++ ) {
            adj[ edges[i][0] ].push_back( edges[i][1] );
            adj[ edges[i][1] ].push_back( edges[i][0] );
        }
        
        int n = adj.size();
        vector<int> dist( n , INT_MAX );
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push( 0 );
        vis[0] = 1;
        dist[0] = 0;
        
    
        while ( !q.empty() )
        {
            int k = q.front();
            q.pop();
            
            for( auto it : adj[k] )
            {
                if( vis[it] == 0 ) {
                    q.push( it );
                    vis[ it ] = 1;
                    dist[it] = dist[k] + 1; 
                } else {
                    dist[it] = min( dist[it] , dist[k] + 1 );
                }
            }
        }
        
        
        int maxVal = 0;
        for( int i = 0 ; i < n; i++ )
        {
            
            maxVal = max( maxVal , dist[i] );
        }
        
        
        int slowest = 0;
        for (int i = 1; i < n; i++) {
            int firstTimeReceive = dist[i] * 2;
            int waitingTime = firstTimeReceive - 1;
            int numResend = waitingTime / patience[i];
            int timeDone = firstTimeReceive + numResend * patience[i];
            slowest = max(slowest, timeDone);
        }
        return slowest + 1;
        
    }
    
    
};