class Solution {
public:
    
    void revString ( string &s , int i, int j ) 
    {
        while( i < j ) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
    
    string reverseWords(string s) {
        int i = 0, j = 0 , l = 0;
        int n = s.size();
        int wordCount = 0; 
        
        while( true )
        {
            while( i < n && s[i] == ' ' ) i++;
            if( i == n ) break;
            if( wordCount ) s[j++] = ' ';
            l = j;
            while( i < n && s[i] != ' ' ) {
                s[j] = s[i];
                i++;
                j++;
            }
            revString( s , l , j - 1 );
            wordCount++;
        }
        s.resize(j);
        revString( s , 0 , j - 1 );
        return s;
    }
};