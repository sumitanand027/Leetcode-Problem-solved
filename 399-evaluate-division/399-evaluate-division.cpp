class Solution {
public:
    void dfs( string cur , string dis , map<string , vector< pair<string , double>> > & m , set<string> v , double &ans , double temp ) {
        if( v.find( cur ) != v.end() ) return;
        v.insert( cur );
        
        if( cur == dis ) {
            ans = temp;
            return;
        }
        
        for( auto p : m[cur] ) {
            dfs( p.first , dis , m , v , ans , temp * p.second );
        }
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        map<string , vector< pair<string , double>> > m;
        
        for( int i = 0 ; i < e.size() ; i++ ) {
            m[ e[i][0] ].push_back( {e[i][1] , v[i] } );
            m[ e[i][1] ].push_back( {e[i][0] , 1 / v[i]} );
        }
            
        vector<double> ans;
        for( int i = 0 ; i < q.size() ; i++ ) {
            string s = q[i][0];
            string e = q[i][1];
            double temp = -1.0;
            set<string> v;
            if( m.find( s ) != m.end() ) {
                dfs( s , e , m , v , temp , 1.0 );
            }
            ans.push_back( temp );
        }
        return ans;
    }
};