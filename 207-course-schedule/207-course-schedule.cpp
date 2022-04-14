class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prep ) {
        
        vector< vector<int> >  adj( numCourses );
        vector< int > indegree( numCourses );
        
        for( auto &x : prep ) {
            adj[ x[0] ].push_back( x[1] );    
            indegree[ x[1] ]++;
        }
        
        queue<int> q;
        for( int i = 0 ; i < numCourses ; i++ )
        {
            if( indegree[i] == 0 ) 
                q.push( i );
        }
        
        int cnt = 0;
        while( !q.empty() )
        {
            int k = q.front();
            q.pop();
            
            cnt++;
            for( auto &x : adj[k] )
            {
                indegree[x]--;
                if( indegree[x] == 0 )
                    q.push( x );
            }
        }
        
        if( cnt != numCourses )
            return false;
        return true;
    }
};