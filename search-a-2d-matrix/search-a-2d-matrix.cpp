class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0;
        int h = n * m - 1;
        
        while( l <= h ) {
            int mid = ( l + h ) / 2;
            if( mat[mid/m][mid%m] == tar ) {
                return true;
            } 
            if ( mat[mid/m][mid%m] < tar ){
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return false;
    }
};