class Solution {
public:
    
    int helper( string x , string y , int m , int n , vector<vector<int>> &t )
    {
        if( m == 0 || n == 0 )
            return 0;
        
        if( t[m][n] != -1 )
            return t[m][n];
        
        if( x[m-1] == y[n-1] )
            return t[m][n] = 1 + helper( x , y , m - 1 , n - 1 , t );
        else 
            return t[m][n] = max( helper( x , y, m - 1 , n ,  t ) , helper( x , y , m , n - 1 , t ) ) ;
    }
    
    int minDistance(string word1, string word2) {
        
        int m = word1.size() , n = word2.size();
        
        vector< vector<int> > t( m + 1 , vector<int> ( n + 1 , -1 ) );
        int common = helper( word1 , word2 , m , n , t);
        
        int ans = 0;
        
        ans += ( m - common );
        ans += ( n - common );
        
        return ans;
    }
};