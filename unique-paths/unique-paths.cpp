class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector< vector<int> > mat( m , vector<int> (n , 1) );
        
        for( int i = m - 2; i >= 0; i-- )
        {
            for( int j = n - 2; j >= 0; j-- ) 
            {
                mat[i][j] = mat[i+1][j] + mat[i][j+1];
            }
        }
        return mat[0][0];
    }
};