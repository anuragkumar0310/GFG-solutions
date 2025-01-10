//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freqMap;
        int n = arr.size();

        for (int i = 0; i < k; ++i) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size());

        for (int i = k; i < n; ++i) {
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]);
            }
            freqMap[arr[i]]++;
            result.push_back(freqMap.size());
        }

        return result;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends