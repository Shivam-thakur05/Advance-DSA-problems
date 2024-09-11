#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int target;
    cin>>target;

    int ans = -1;

    int start = 0;
    int end = n-1;
    int minDiff = INT_MAX;

    while(start <= end){
        int mid = start + (end - start)/2;
        int diff = abs(arr[mid] - target);

        if(target == arr[mid]) {
            cout<<"nearest element is : "<<target<<endl;
            return 0;

        }

        if(diff < minDiff){
            minDiff = diff;
            ans = arr[mid];
        }
        if(target > arr[mid]) start = mid+1;
        else end = mid-1;
    }

    cout<<"nearest number is : "<<ans<<endl;
    return 0;
}