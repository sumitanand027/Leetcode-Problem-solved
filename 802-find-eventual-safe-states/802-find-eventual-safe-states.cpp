class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector< vector<int> > g(n);
        vector<int>  outdegree( n, 0 );
        
        for( int i = 0 ; i < n ; i++ ) {
            for( auto j : graph[i]) {
                g[j].push_back( i );
                outdegree[i]++;
            }
        }
        
        queue<int> q;
        
        for( int i = 0 ; i < n ; i++ ) 
        {
            if( outdegree[i] == 0 )
                q.push( i );        
        }
        
        vector<int> ans;
        
        while( !q.empty() )
        {
            int k = q.front();
            q.pop();
 
            ans.push_back( k );
            for( auto i : g[k] ) {
                outdegree[i]--;
                if( outdegree[i] == 0 ) {
                    q.push( i );
                }
            }
            
        }
        
        sort( ans.begin() , ans.end() );
        return ans;        
    }
};