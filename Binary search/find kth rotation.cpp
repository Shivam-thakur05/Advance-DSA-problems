class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        
        while(start <= end) {
            if (arr[start] <= arr[end]) return start;  // The array is already sorted.
            
            int mid = start + (end - start) / 2;
            
            // Check if the mid element is the smallest (pivot point)
            if (arr[mid] <= arr[mid-1] && arr[mid] <= arr[mid+1]) {
                return mid;
            }
            
            // If the left half is sorted, the pivot must be in the right half
            if (arr[mid] >= arr[start]) {
                start = mid + 1;
            } 
            // If the right half is sorted, the pivot must be in the left half
            else if (arr[mid] <= arr[end]) {
                end = mid - 1;
            }
        }
        return 0;
    }
};