class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int st = 0 , ed = n - 1;
        
        vector< vector<int> > mat( n , vector<int> ( n ));
        
        int val = 1;
        while( st <= ed )
        {
            for( int x = st ; x <= ed ; x++ )
            {
                mat[st][x] = val++;
            }
            
            for( int y = st + 1 ; y <= ed ; y++ )
            {
                mat[y][ed] = val++;
            }
            
            for( int x = ed - 1 ; x >= st ; x-- )
            {
                mat[ed][x] = val++;
            }
            
            for( int y = ed - 1 ; y > st ; y-- )
            {
                mat[y][st] = val++;
            }
            st++;
            ed--;
        }
        return mat;        
    }
};