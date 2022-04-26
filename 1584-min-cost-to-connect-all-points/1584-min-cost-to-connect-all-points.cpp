class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        
        int n = points.size();
        vector< vector< pair<int,int> > > adj(n);
        
        for( int i = 0 ; i < n; i++ )
        {
            for( int j = i + 1 ; j < n ; j++ ) 
            {
                int x1 = points[i][0] , x2 = points[j][0];
                int y1 = points[i][1] , y2 = points[j][1];
                int dist = abs( x1 - x2 ) + abs( y1 - y2 );
                adj[i].push_back( { j , dist } );
                adj[j].push_back( { i , dist } );
            }
        }
        
        vector <bool> vis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push( {0,0} );
        
        int res = 0;
        
        for( int i = 0 ; i < n ; i++ )
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            
            int u = temp.second;
            if( vis[u] ) {
                i--;
                continue;
            }
            vis[ u ] = true;
            res += temp.first;
            
            for( auto x : adj[u] ) {
                int v = x.first;
                if( vis[v] == false ) {
                    pq.push( {x.second , v });
                }
            }
        }
        
        return res;
    }
};





