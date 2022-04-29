class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v(n,-1) , visited(n,0);
        
        for( int i = 0 ; i < n ; i++ )
        {
            if( !visited[i] ) 
            {
                queue<int> q;
                q.push( i );
                visited[i] = 1;
                v[i] = 0;
                while( !q.empty() )
                {
                    int cur = q.front();
                    int turn = v[cur]== 0 ? 1 : 0;
                    q.pop();
                    for( int i = 0 ; i < graph[cur].size() ;i++ ) {
                        if( v[graph[cur][i]] == -1 ||  v[graph[cur][i]] == turn  ) {
                            v[ graph[cur][i] ] = turn;
                            if( !visited[ graph[cur][i] ] ) {
                                visited[ graph[cur][i] ] = 1;
                                q.push( graph[cur][i] );
                            }
                        } else {
                            return false;
                        }
                    }
                }    
            }
        }
        
        return true;
    }
};