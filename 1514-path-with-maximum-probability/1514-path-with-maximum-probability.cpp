 class node {
        public:
        int ed;
        double wt;
};

class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector< vector<node> > adj ( n );
        
        for( int i =  0 ; i < edges.size() ; i++ )
        {
            node newnode;
            
            newnode.ed = edges[i][1];
            newnode.wt = succProb[ i ];
            adj[ edges[i][0]].push_back( newnode );
            
            newnode.ed = edges[i][0];
            newnode.wt = succProb[ i ];
            adj[ edges[i][1]].push_back( newnode );
        }
        
        priority_queue< pair<double,int> > pq;
        pq.push( {0.0,start} );
        
        vector< double > dist ( n + 1 , 0.0 );
        dist[0] = 1;
        while( !pq.empty() )
        {
            double wt = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            
            for( auto &x : adj[cur] ) 
            {
                if( dist[cur] * x.wt > dist[x.ed] || dist[cur] == 0 ) {
                    if( dist[cur] == 0 ) 
                        dist[x.ed] = x.wt;
                    else
                        dist[x.ed] = dist[cur] * x.wt;
                    pq.push( {dist[x.ed],x.ed} );
                }
            }
        }
             
        return dist[ end ];
    }
};