class Solution {
public:
    
    void helper( int sr , int sc , int nc , vector< vector<int> > &image , int pre , vector< vector<int> > &vis )
    {
        if( sr == image.size() || sc == image[0].size() || sr == -1 || sc == -1 )
            return;
        if( image[sr][sc] != pre )
            return;
        if( vis[sr][sc] != -1 ) return;
        vis[sr][sc] = 0;
        image[sr][sc] = nc;
        
        helper( sr + 1 , sc , nc , image , pre , vis);
        helper( sr , sc + 1 , nc, image , pre , vis ); 
        helper( sr - 1 , sc , nc , image , pre , vis );
        helper( sr , sc - 1, nc , image , pre , vis );
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc ) {
        // 3 : 01
        
        vector< vector<int> > vis( image.size() , vector<int> ( image[0].size() , -1 ) );
        helper( sr , sc , nc , image , image[sr][sc] , vis );
        
        return image;
    }
};