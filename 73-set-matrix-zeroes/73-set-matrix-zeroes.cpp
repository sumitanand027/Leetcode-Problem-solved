class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int presentInX = 0 , presentInY = 0;
        
        for( int i = 0 ; i < matrix.size() ; i++ )
            if( matrix[i][0] == 0 )
                presentInX = 1;
        
        for( int j = 0 ; j < matrix[0].size() ; j++ )
            if( matrix[0][j] == 0 )
                presentInY = 1;
        
        for( int i = 1 ; i < matrix.size() ; i++ )
        {
            for( int j = 1 ; j < matrix[0].size() ; j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for( int i = matrix.size() - 1 ; i >= 0 ; i-- )
        {
            for( int j = matrix[0].size() - 1 ; j >= 0 ; j-- )
            {
                if( matrix[i][0] == 0 || matrix[0][j] == 0 ) {
                    matrix[i][j] = 0;
                } 
            }
        }
        
        for( int i = 0 ; i < matrix.size() && presentInX ; i++ )
            matrix[i][0] = 0;
        
         for( int i = 0 ; i < matrix[0].size() ; i++ )
            if( presentInY )
                matrix[0][i] = 0;
    }
};