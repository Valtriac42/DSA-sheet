//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        long long big = arr[0];
        long long small = arr[0];
        int size = arr.size();
        int i = 1;
        for(i=1;i<size;i++)
        {
            if(big<arr[i])
            {
                big=arr[i];
            }
            if(small>arr[i])
            {
                small=arr[i];
            }
        }
        return make_pair(small,big);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}