class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        k = k % ( m * n );
        
        vector< vector<int> > ans ( m , vector<int>( n) );
        
        int a = 0 , b = 0;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( k > 0 ) {
                    k--;
                    continue;
                }
                ans[i][j] = grid[a][b++];
                if( b == n ) {
                    b = 0;
                    a++;
                }
            }
        }
        
        
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( a == m && b == 0 ) break;
                
                ans[i][j] = grid[a][b++];
                if( b == n ) {
                    b = 0;
                    a++;
                }
            }
        }
        
        return ans;
    }
};