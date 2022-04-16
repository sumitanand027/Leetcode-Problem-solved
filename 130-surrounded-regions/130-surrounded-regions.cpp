class Solution {
public:
    
    void markOne( vector< vector<char> > &board , int i , int j , int m , int n , vector< vector<int> > &vis )
    {
        if( i == m || j == n || i < 0 || j < 0 || board[i][j] == 'X')
            return;
        
        if( vis[i][j] == 1 ) return;
        vis[i][j] = 1;
        
        if( board[i][j] == 'O')
            board[i][j] = '1';
        
        markOne( board , i + 1 , j , m , n , vis );
        markOne( board , i , j + 1 , m , n , vis );
        markOne( board , i , j - 1 , m , n , vis );
        markOne( board , i - 1 , j , m , n , vis );
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size() , n = board[0].size();
        vector< vector<int> > vis( m , vector<int>(n , 0 ));
        
        for ( int i = 0 ; i < m ; i++ )
            if( board[i][0] == 'O' ) {
                markOne( board , i , 0 , m , n , vis );
            }
        
        for ( int i = 0 ; i < m ; i++ )
            if( board[i][n-1] == 'O' ) {
                markOne( board , i , n-1 , m , n , vis );
            }
        
        for ( int j = 0 ; j < n ; j++ )
            if( board[0][j] == 'O' ) {
                markOne( board , 0 , j , m , n , vis );
            }
        
        for ( int j = 0 ; j < n ; j++ )
            if( board[m-1][j] == 'O' ) {
                markOne( board , m- 1, j , m , n , vis );
            }
        
        
        for( int i = 0 ; i < m ; i++ )
        {
           for( int j = 0 ; j < n ; j++ )
           {
                
               if( board[i][j] == 'O' )
                   board[i][j] = 'X';
               if( board[i][j] == '1')
                  board[i][j] = 'O';
              
           }
        }
        
    }
}; 

