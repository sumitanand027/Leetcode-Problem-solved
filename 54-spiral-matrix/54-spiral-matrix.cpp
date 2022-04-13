class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int stx = 0 , edx = n - 1;
        
        int m = mat[0].size();
        int sty = 0 , edy = m - 1;
        
        vector<int> v;

        while( stx <= edx && sty <= edy )
        {
            for( int y = sty ; y <= edy ; y++ )
            {
                v.push_back(mat[stx][y]);
            }
            
            for( int x = stx + 1 ; x <= edx ; x++ )
            {
                v.push_back(mat[x][edy]);
            }
            
            for( int y = edy - 1 ; y >= sty && stx != edx ; y-- )
            {
                v.push_back(mat[edx][y]);
                
            }
            
            for( int x = edx - 1 ; x > stx && sty != edy; x-- )
            {
                v.push_back(mat[x][sty]);
            }
            stx++;
            edx--;
            sty++;
            edy--;
        }
        return v; 
    }
};