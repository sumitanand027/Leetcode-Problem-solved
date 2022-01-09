// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    bool static cmp ( pair<int,int>  a, pair<int,int>  b ) {
        if( a.second < b.second ) return 1;
        else if ( a.second > b.second ) return 0;
        else if( a.first < b.first ) return 1;
        else return 0;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector< pair<int,int> > v;
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back( { start[i] , end[i] } );
        }
        
        sort( v.begin() , v.end() , cmp );
        
        int ans = 0, s = -1, e = -1;
        for( int i = 0; i < n; i++ ) {
            if( v[i].first > e ) {
                s = v[i].first;
                e = v[i].second;
                ans++;
            }
            
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends