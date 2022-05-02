class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector< vector<int> > mat( n , vector<int> (n , INT_MAX ));
        
        for( int i = 0 ; i < n ; i++ )
        {
            mat[i][i] = 0;
        }
        
        for( auto x : edges )
        {
            mat[x[0]][x[1]] = x[2];
            mat[x[1]][x[0]] = x[2];
        }
        
        for( int k = 0 ; k < n ; k++ )
        {
            for( int i = 0 ; i < n ; i++ )
            {
                for( int j = 0 ; j < n ; j++ )
                {
                    if( mat[i][k] != INT_MAX && mat[k][j] != INT_MAX )
                        mat[i][j] = min( mat[i][j] , mat[i][k] + mat[k][j] ); 
                }
            }
        }
        
        int cnt = INT_MAX , ind = -1;
        
        for( int i = 0 ; i < n ; i++ )
        {
            int t = 0;
            for( int j = 0 ; j < n ; j++ )
            {
                if( i == j ) continue;
                if( mat[i][j] <= distanceThreshold ) {
                    t++;
                }
            }
            if( t <= cnt ) {
                cnt = t;
                ind = i;
            }
        }
        return ind;
    }
};



