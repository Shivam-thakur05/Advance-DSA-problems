#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    //binary search to find the bitonic array
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == target) return mid;
        
    }

    return 0;
}