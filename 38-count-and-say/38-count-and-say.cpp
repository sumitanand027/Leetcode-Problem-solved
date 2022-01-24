class Solution {
public:
    string countAndSay(int n) {
        
        int i = 2;
        string pat = "1";
        
        while( i <= n ) 
        {
            string temp;
            int cnt = 1;
            char cur = pat[0];
            
            for( int j = 1; j < pat.size(); j++ )
            {
                if( pat[j] == pat[j-1] )
                {
                    cnt++;
                }
                else {
                    temp.push_back( '0' + cnt );
                    temp.push_back( cur );
                    cur = pat[j];
                    cnt = 1;
                }
            }
            temp.push_back( '0' + cnt );
            temp.push_back( cur );   
            pat = temp;
            
            i++;
        }
        return pat;
    }
};
