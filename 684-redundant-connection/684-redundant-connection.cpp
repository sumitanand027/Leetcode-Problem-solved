class DisjointSet {
    
    vector<int> parent;
    vector<int> rank;
    public:
    DisjointSet ( int n ) {
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1,0);
        for( int i = 1 ; i <= n ; i++ )
        {
            parent[i] = i;
            // rank.push_back( 0 );
        }
    }    
    int find( int x ) {
        if( x != parent[x] ) {
            parent[x] = find( parent[x] );
        }
        return parent[x];
    } 
    void unionDis( int x , int y ) {
        int parentx = find( x );
        int parenty = find( y );

        if ( rank[parentx] < rank[parenty] ) {
            parent[parentx] = parenty;
        } else if( rank[parentx] > rank[parenty] ) {
            parent[parenty] = parentx;
        } else {
            parent[ parentx ] = parenty;
            rank[parenty]++;
        }
    }
};
    

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DisjointSet d ( edges.size()  );
        
        for( auto &x : edges )
        {
            int parentx = d.find( x[0] );
            int parenty = d.find( x[1] );
            
            if( parentx == parenty )
                return { x[0] , x[1] };
            
            d.unionDis ( x[0] , x[1] );
        }
        
        return { 1 , 1 };
    }
    
    
};











