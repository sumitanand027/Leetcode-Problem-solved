class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack< pair<char,int> > sk;
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( sk.empty() || sk.top().first != s[i]  )
                sk.push( {s[i] , 1 } );
            else {
                auto p = sk.top();
                sk.pop();
                sk.push( {p.first , p.second  + 1 });
            }
            if( sk.top().second == k ) sk.pop();
        }
        
        string ans;
        
        while( !sk.empty() )        
        {
            auto cur = sk.top();
            sk.pop();
            while( cur.second-- ) {
                ans.push_back( cur.first );
            }
        }
        reverse( ans.begin() , ans.end() );
        return ans;
    }
};