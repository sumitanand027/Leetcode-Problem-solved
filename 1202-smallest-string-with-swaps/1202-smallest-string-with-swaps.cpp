class dsu {
    public:
    vector<int> parent;
    vector<int> rank;
    

    dsu( int n ) {
        parent.resize( n );
        rank.resize( n );
        for( int i = 0 ; i < n ; i++ ) {
            parent[i] = i;
        }
        for( int i = 0 ; i < n ; i++ ) {
            rank[i] = 1;
        }
    }
    
    int find( int x ) {
        if( parent[x] != x ) parent[x] = find( parent[x] );
        return parent[x];
    }
    
    void uni( int x , int y ) {
        x = find( x );
        y = find( y );
        
        if( rank[x] < rank[y] ) {
            parent[x] = y;
        } else if( rank[y] < rank[x] ) {
            parent[y] = x;
        } else {
            parent[x] = y;
            rank[y]++;
        } 
    }
};


class Solution {
public:
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        dsu d(s.size());
        
        for( auto &x : pairs ) {
            d.uni( x[0] , x[1] );
        }
        
        unordered_map< int , vector< pair<char,int>> > m;
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            m[ d.find( i ) ].push_back( { s[i] , i } );
        }
        
        for( int i = 0 ; i < s.size()  ; i++ ) {
            cout << d.parent[i] << " ";
        }
        
        for( auto &x : m ) {
            sort( x.second.begin() , x.second.end() );
            vector<int> ind;
            for( auto &y : x.second ) {
                ind.push_back( y.second );   
            }
            sort( ind.begin(), ind.end() );
            int i = 0;
            for( auto &y : x.second ) {
                s[ ind[i++] ] = y.first;
            }
        }
        
        return s;
    }
};
