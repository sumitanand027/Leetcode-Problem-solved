class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int tot = 0 , cnt = 0, min = 0;
        
        queue< pair<int,int> > rotting;
        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( grid[i][j] != 0 ) {
                    tot++;
                }
                if( grid[i][j] == 2 ) {
                    rotting.push( {i,j} );
                }
            }
        }
        
        int dx[4] = { 0, 0, 1, -1 };
        int dy[4] = { 1, -1, 0, 0 };
        
        while( !rotting.empty() )
        {
            int k = rotting.size();
            cnt += k;
            while( k-- ) 
            {
                int x = rotting.front().first;
                int y = rotting.front().second;
                rotting.pop();
                for( int i = 0; i < 4; i++ ) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if( nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1 )
                        continue;
                    grid[nx][ny] = 2;
                    rotting.push( {nx, ny});
                }
            }
            if( !rotting.empty() ) min++;
        }
        return tot == cnt ? min : -1;
    }
};





