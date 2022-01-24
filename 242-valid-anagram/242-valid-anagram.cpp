class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> cm , tm;
        
        for( auto c : s ) {
            cm[c]++;
        }
        for( auto c : t ) {
            tm[c]++;
        }
        
        for( auto c : cm ) {
            if( c.second != tm[c.first] ) return 0;
        }
        for( auto c : tm ) {
            if( c.second != cm[c.first] ) return 0;
        }
        return 1;
    }
};