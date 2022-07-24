class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();
        
        int i = 0 , j = m - 1;
        while( i < n && i >= 0 && j >= 0 && j < m ) {
            if( mat[i][j] == tar ) {
                return true;
            } else if( mat[i][j] > tar ){
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
