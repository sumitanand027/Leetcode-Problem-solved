class Solution {
public:
    
    vector< vector<int> > nav { { -1 , 0 } , { 0 , -1 } , { 1 , 0 } , { 0 , 1 } };
    
    void helper( vector< vector<char> > &board , int i , int j , string  &word , int ind , bool & ans  )
    {
        if( ans ) return;
        if( ind == word.size() ) {
            ans = true;
            return;
        }
        int m = board.size();
        int n = board[0].size();
        
        if( i >= m || i < 0 || j >= n || j < 0 ||board[i][j] != word[ind] ) return;
        
        char c = board[i][j];
        board[i][j] = '*';
        // for( auto na : nav ) {
            helper( board , i - 1 , j  , word , ind + 1 , ans );
            helper( board , i , j - 1 , word , ind + 1 , ans );
            helper( board , i + 1 , j , word , ind + 1 , ans );
            helper( board , i , j + 1 , word , ind + 1 , ans );
        // }
        board[i][j] = c;        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        
        bool ans = false;
        
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                helper( board , i , j , word , 0 , ans );
                if( ans ) return ans;
            }
        }
        
        return ans;
    }
};