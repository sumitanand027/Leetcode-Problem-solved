class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int m = h.size() , n = h[0].size();
        
        int dist[5] = {-1 , 0 , 1 , 0 , -1 };
        
        priority_queue< vector<int> , vector< vector<int> > , greater< vector<int> > > pq;
        vector< vector<int> > efforts( m , vector<int> (n , INT_MAX ) );
        
        pq.push( {0,0} );
        
        while( !pq.empty() )
        {
            int effort = pq.top()[0];
            int x = pq.top()[1] / 100 , y = pq.top()[1] % 100;
            pq.pop();
            
            if (x == m - 1 && y == n - 1) return effort;
            if( effort >= efforts[x][y] ) {
                continue;
            }
            efforts[x][y] = effort;
            
            for( int i = 0 ; i < 4 ; i++ )
            {
                int nx = x + dist[i] , ny = y + dist[i+1];
                if( nx < 0 || nx >= m || ny < 0 || ny >= n ) continue;
                int n_effort = max( effort , abs( h[nx][ny] - h[x][y] ) );
                pq.push( {n_effort , nx * 100 + ny} );
            }
        }
        
        
        return -1;       
    }
};


