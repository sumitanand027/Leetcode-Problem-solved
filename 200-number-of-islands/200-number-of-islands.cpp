class Solution {
public:
    
    void dfs( vector< vector<char> > &grid , int i , int j , int m , int n , vector< vector<bool> > &vis )
    {
        if( i == m || j == n || i == -1 || j == -1 )
            return;
        
        if( vis[i][j] == 1 || grid[i][j] == '0' ) return;
        
        vis[i][j] = 1;
        
        dfs( grid , i + 1, j , m , n , vis );
        dfs( grid , i , j + 1 , m , n , vis );
        dfs( grid , i - 1 , j , m , n , vis );
        dfs( grid , i , j - 1 , m , n , vis );
    }
    
    
    int numIslands(vector<vector<char>>& grid)
    {
        // 4 : 10
        int m = grid.size();
        int n = grid[0].size();
        
        vector< vector<bool> > vis ( m , vector<bool> ( n , 0 ) );
        
        int ans = 0;
        
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j ++ )
            {
                if( vis[i][j] == 0 && grid[i][j] == '1' )
                {
                    ans++;
                    dfs( grid , i , j , m , n , vis );
                }
            }
        }
        return ans;
    }
};