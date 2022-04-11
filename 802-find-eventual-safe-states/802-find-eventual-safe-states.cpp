class Solution {
public:
    
    unordered_set<int> safe;
    unordered_set<int> cycle;
    
    bool dfs( int x , unordered_set<int> &vis , vector< vector<int> > &graph )
    {
        if( safe.find( x ) != safe.end() )
            return true;
        if( cycle.find( x ) != cycle.end() )
            return false;
        
        if( vis.find( x ) != vis.end() ) {
            cycle.insert( x );
            return false;
        }
        
        vis.insert( x );
        
        for( auto i : graph[x] ) {
            if( !dfs( i , vis , graph ) ) {
                cycle.insert( x );
                return false;
            }
        }
        
        safe.insert( x );
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> ans;
        
        unordered_set<int> vis;
        
        for( int i = 0 ; i < graph.size() ; i++ )
        {
            if( dfs( i, vis , graph ) )
                ans.push_back( i );
        }
        
        return ans;
    }
};