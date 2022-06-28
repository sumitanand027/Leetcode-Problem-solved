class Solution {
public:
    int minDeletions(string s) {
        
        vector<pair<int,char>> v;
        map<char,int> m;
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            m[ s[i] ]++;
        }
        
        for( auto &p : m ) {
            v.push_back( { p.second, p.first } );
        }
        
        sort( v.begin() , v.end()  );
        
        int ans = 0;
        
        for( int i = v.size() - 2 ; i  >= 0 ; i-- )
        {
            while( v[i].first >= v[i+1].first && v[i].first > 0 ) {
                v[i].first--;
                ans++;
            }
        }
        return ans;
        
    }
};