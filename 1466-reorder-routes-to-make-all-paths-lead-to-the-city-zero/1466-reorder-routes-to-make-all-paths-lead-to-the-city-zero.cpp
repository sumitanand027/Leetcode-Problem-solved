class Solution {
public:
    
    void dfs( int cur , int &ans , vector< vector<int> > &adj , vector<int> &vis )
    {
        if( vis[abs(cur)] == 1 )
            return;
        
        vis[abs(cur)] = 1;
        
        if( cur > 0 )
            ans++;
        
        for( auto x : adj[abs(cur)] ) {
            dfs( x ,ans, adj , vis );    
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector< vector<int> > adj(n);
        
        for( auto x : connections )
        {
            adj[ x[0] ].push_back (x[1]);
            adj[ x[1] ].push_back(-x[0]);
        }
        
        int ans = 0;
        
        vector<int> vis(n,0);
        
        dfs( 0 , ans , adj , vis );
        
        return ans;        
    }
};