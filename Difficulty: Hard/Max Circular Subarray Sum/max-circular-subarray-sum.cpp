//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#include <iostream>
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
using namespace std;  
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl; 
#define REP(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORD(i,a,b) for(int i=(a);i>=(b);i--) 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; } 
 
const int INF = 1<<29; 
typedef long long ll; 
 
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; } 
 
template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 

class Solution {
public:
    int circularSubarraySum(vector<int>& arr) {
        int n = arr.size();
        
        int maxLinearSum = kadaneMax(arr);
        
        int totalSum = 0;
        int idx = 0;
        while (idx < n) {
            totalSum += arr[idx];
            arr[idx] = -arr[idx];
            ++idx;
        }
        
        int maxWrapSum = totalSum + kadaneMax(arr);
        
        return maxWrapSum > maxLinearSum && maxWrapSum != 0 ? maxWrapSum : maxLinearSum;
    }
    
private:
    int kadaneMax(vector<int>& arr) {
        int maxSoFar = arr[0];
        int currentMax = arr[0];
        
        int idx = 1;
        while (idx < arr.size()) {
            currentMax = max(arr[idx], currentMax + arr[idx]);
            maxSoFar = max(maxSoFar, currentMax);
            ++idx;
        }
        
        return maxSoFar;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends