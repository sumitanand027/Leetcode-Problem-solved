// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void helper( int row, int col,  vector< vector<int> > &m, vector< vector<int>> & mat, vector<string> &ans, int n, string path )
    {
        if( row == n - 1 && col == n - 1 ) {
            ans.push_back( path );
            return;
        }
        
        
        if( row < n - 1 && mat[row+1][col] == 0 && m[row+1][col] == 1 ) {
            mat[row+1][col] = 1;
            path += 'D';
            helper( row + 1 , col, m, mat, ans, n, path );
            mat[row+1][col] = 0;
            path.pop_back();
        }
        if( row > 0 &&  mat[row-1][col] == 0 && m[row-1][col] == 1 ) {
            mat[row-1][col] = 1;
            path += 'U';
            helper( row - 1 , col, m, mat, ans, n, path );
            mat[row-1][col] = 0;
            path.pop_back();
        }
        if( col < n - 1 &&  mat[row][col+1] == 0 && m[row][col+1] == 1 ) {
            mat[row][col+1] = 1;
            path += 'R';
            helper( row , col + 1, m, mat, ans, n, path );
            mat[row][col+1] = 0;
            path.pop_back();
        }
        if( col > 0 && mat[row][col-1] == 0 && m[row][col-1] == 1 ) {
            mat[row][col-1] = 1;
            path += 'L';
            helper( row , col - 1, m, mat, ans, n, path );
            mat[row][col-1] = 0;
            path.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector< vector<int> > mat(n, vector<int>(n,0) );
        vector<string> ans;
        mat[0][0] = 1;
        if( m[0][0] == 1 ) {
            helper( 0 , 0 , m, mat, ans, n, "");
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends