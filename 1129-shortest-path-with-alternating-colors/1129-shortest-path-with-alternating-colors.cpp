class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be ) {
        
        vector< vector< pair<int,int> >> g( n );
        
        for( auto &x : re ) {
            g[ x[0] ].push_back( { x[1] , 0 } );
        }
        
        for( auto &x : be ) {
            g[ x[0] ].push_back( { x[1] , 1 } );
        }
        
        queue< pair<int,int> > q;
        vector<int> distr ( n , -1 );
        vector<int> distb ( n , -1 );
        
        distr[0] = 0;
        distb[0] = 0;
        q.push( {0,0} );
        q.push( {0,1} );
        
        while ( !q.empty() )
        {
            auto [ i , c1 ] = q.front();
            q.pop();
            
            for( auto [ j , c2 ] : g[i] )
            {
                if( c1 == c2 ) continue;
                if( c2 == 0 && distr [j] != -1 ) continue; 
                if( c2 == 1 && distb [j] != -1 ) continue;
                
                if( c1 != c2 ) {
                    if( c2 == 0 ) {
                        distr[j] = distb[i] + 1;
                        q.push( {j , 0 } );
                    }
                    else {
                        distb[j] = distr[i] + 1;
                        q.push( {j , 1} );
                    }
                }
            }
        }
        
        vector<int> res (n);
        
        for( int i = 0 ; i < n ; i++ )
        {
            int a = distr[i];
            int b = distb[i];
            
            if( a == -1 )
                res[i] = b;
            else if( b == -1 )
                res[i] = a;
            else
                res[i] = min( a , b );
        }
        
        return res;
    }
};




