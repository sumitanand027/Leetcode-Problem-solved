// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    static bool comp ( const Job &a , const Job &b ) {
        if( a.profit > b.profit )
            return 1;
        else
            return 0;
    }
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort( arr , arr + n , comp );
        
        int mx = 0;
        for( int i = 0 ; i < n ; i++ ) {
            mx = max( arr[i].dead , mx );
        }
        
        vector<int> deadline( mx + 1 , -1 );
        
        int cnt = 0;
        int prof = 0;
        for( int i = 0 ; i < n ; i++ ) {
            if( deadline[ arr[i].dead] == -1 )
            {
                cnt++;
                deadline[ arr[i].dead] = arr[i].profit;
                prof += arr[i].profit;
            } else {
                int j = arr[i].dead - 1;
                while( j > 0 && deadline[ j ] != -1 ) j--;
                
                if( j > 0 ) {
                    cnt++;
                    deadline[j] = arr[i].profit;
                    prof += arr[i].profit;
                }
            }
        }
        
        vector<int> ans;
        
        ans.push_back( cnt );
        ans.push_back( prof );
        return ans;
    } 
    
    
    
    
    
    
    
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends