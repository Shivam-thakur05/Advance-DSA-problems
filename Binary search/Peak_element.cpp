#include <iostream>
using namespace std;

class Solution
{
public:
    int peakElement(int arr[], int n)
    {
        if (n == 1) {
            return 1; // Single element is always a peak element
        }
        
        if (arr[0] >= arr[1]) return 1;
        if (arr[n-1] >= arr[n-2]) return 1;
        
        int start = 1;
        int end = n-2;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (mid > 0 && mid < n-1) {
                if (arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
                    return 1;
                } else if (arr[mid] < arr[mid-1]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        
        return 0;
    }
};

int main()
{
    Solution solution;
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = solution.peakElement(arr, n);
    
    if (result) {
        cout << 1 << std::endl;
    } else {
        cout << 0 << std::endl;
    }
    
    return 0;
}
