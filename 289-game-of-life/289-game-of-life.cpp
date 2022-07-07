class Solution {
public:

    bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
        if( x >= board.size() || x < 0 || y >= board[0].size() || y < 0 )
            return 0;
        
        if( board[x][y] == 1 || board[x][y] == 2 )
            return 1;
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {

        vector<int> ways_x = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> ways_y = {1, -1, 1, -1, 0, 0, 1, -1};
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                
                
                int cnt = 0;
                
                for( int i = 0 ; i < 8 ; i++ )
                {
                    int x = row + ways_x[i];
                    int y = col + ways_y[i];
                    
                    if( isValidNeighbor( x , y , board ) ) {
                        cnt++;
                    }
                }
                
                if( board[row][col] == 1 ) {
                    if( cnt <= 1 || cnt >= 4 )
                        board[row][col] = 2;  
                    // else
                    //     board[row][col] = 2;
                } else {
                    if( cnt == 3 ) {
                        board[row][col] = -2;
                    }
                } 
            }
        }
        

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == 1 || board[row][col] == -2)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};