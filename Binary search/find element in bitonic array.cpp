#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int start = 0;
	    int end = n-1;
	    int ans = -1;
	    
	    while(start <= end){
	        int mid = start + (end - start)/2;
	        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return arr[mid];
	        else if(arr[mid] < arr[mid-1]){
	            ans = max(ans,arr[mid]);
	            end = mid - 1;
	        }
	        else{
	            ans = max(ans,arr[mid]);
	            start = mid + 1;
	        }
	    }
	    return ans;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
