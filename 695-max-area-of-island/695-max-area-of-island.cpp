class Solution {
public:
    
    int dfs( int i , int j , vector< vector<int> > &grid , vector< vector<int> > &vis )
    {
        if( i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == 0 )
            return 0;      
        
        if( vis[i][j] == 1 )
            return 0;
        
        vis[i][j] = 1;
        
        int a = 0;
        
        if( grid[i][j] == 1 )
            a++;
        
        a += dfs( i + 1 , j , grid , vis );
        a += dfs( i , j + 1 , grid , vis );
        a += dfs( i - 1 , j , grid , vis );
        a += dfs( i , j - 1 , grid , vis );
        
        return a;        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();
        
        vector< vector<int> > vis( m , vector<int> ( n , 0 ) );
        
        int ans = 0;
        
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 1 ) 
                    ans = max( ans , dfs( i , j , grid , vis ) );
            }
        }
        
        return ans;
    }
};