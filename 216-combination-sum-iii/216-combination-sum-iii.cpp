class Solution {
public:
    
    void helper( vector< vector<int> > &ans , vector<int> cur , int k , int n )
    {
        if( n == 0 && k == 0 )
        {
            ans.push_back( cur );
            return;
        }
        if( k == 0 || n < 0  ) return;
        
        int i;
        
        if( cur.size() == 0 )
            i = 1;
        else
            i = cur[ cur.size() - 1 ] + 1;
        
        for( ; i <= n && i <= 9 ; i++ )
        {
            cur.push_back( i );
            helper( ans , cur , k - 1  , n - i );
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> cur;
        vector< vector<int> > ans;
        helper( ans, cur , k , n );
        
        return ans;
    }
};