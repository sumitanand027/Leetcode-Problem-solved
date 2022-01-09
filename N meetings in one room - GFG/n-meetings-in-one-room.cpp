// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector< pair<int,int> > v;
        for( int i = 0 ; i < n ; i++ ) {
            v.push_back( { start[i] , end[i] } );
        }
        
        sort( v.begin() , v.end() );
        
        int ans = 0 , s = -1 , e = -1;
        
        for( int i = 0 ; i < n ; i++ ) {
            if( v[i].first > e ) {
                ans++;
                s = v[i].first;
                e = v[i].second;
            } else if( v[i].first == s ) {
                if( v[i].second < e )
                    e = v[i].second;
            } else if( v[i].second < e ) {
                s = v[i].first;
                e = v[i].second;
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