class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        set<int> r , c;
        
        for( int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < m ; j++ ) {
                if( mat[i][j] == 0 ) {
                    r.insert( i );
                    c.insert( j );
                } 
            }
        }
        
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < m ; j++ ) {
                if( r.find( i ) != r.end() || c.find( j ) != c.end() ) {
                        mat[i][j] = 0;
                }
            }
        }
    }
};