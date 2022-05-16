class Solution {
public:
    
    int dx[8] = {-1,1,0,0,-1, 1, -1, 1};
    int dy[8] = {0,0,-1,1, 1, 1, -1, -1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0)return -1;
        if(grid.size()==1){
            return 1;
        }
        
        queue< pair<int,int> > q;
        
        q.push( {0,0} );
        
        int step = 1;
        
        
        while( !q.empty() )
        {
            int sz = q.size();
            step++;
            
            for( int i = 0 ; i < sz ; i++ )
            {
                auto p = q.front();
                q.pop();
                
                for( int j = 0 ; j < 8 ; j++ )
                {
                    int nx = p.first + dx[j];
                    int ny = p.second + dy[j];
                    
                    if( nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0 ) {
                        q.push( { nx , ny });
                        grid[nx][ny] = 1;
                        if( nx == grid.size() - 1 && ny == grid[0].size() - 1 )
                             return step;
                    }
                }
            }
            
        }
        return -1;
    }
};





