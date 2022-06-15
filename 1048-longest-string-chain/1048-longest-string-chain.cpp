class Solution {
public:
    
    static bool cmp ( const string &a , const string &b ) {
        if( a.size() < b.size() )
            return true;
        else {
            // if( a < b )
            //     return true;
            return false;
        }
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort( words.begin() , words.end() , cmp );
        
        int ans = 1;
        map< string, int> s;
        for( int i = 0 ; i < words.size() ; i++ )
        {
            s[ words[i] ] = 1;
            for( int j = 0 ; j < words[i].size() ; j++ )
            {
                // string t = words[i];
                // t.erase( t.begin() + j );
                string t = words[i].substr(0, j) + words[i].substr(j + 1);
                if( s.find(t) != s.end() ) 
                {
                    s[ words[i] ] = s[ t ] + 1;
                    ans = max( ans , s[words[i]] );
                }
            }
            
        }
        return ans;
    }
};