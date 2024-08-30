class Solution { 
  private:
    int BinarySearch(vector<int> &arr,int start, int end, int key){
        if(arr[start] > key) return -1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == key) return mid;
            
            else if(arr[mid] > key){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
    int minElement(vector<int> &arr, int start, int end){
        while(start <= end){
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
    }
    
  public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        
        int minElementIdx = minElement(arr,start,end);
        //cout<<minElementIdx<<endl;
        
        //now we will left part and right part seperately
        int leftPart = BinarySearch(arr,start,minElementIdx-1,key);
        int rightPart = BinarySearch(arr,minElementIdx,end,key);
        
        //cout<<leftPart<<" "<<rightPart<<endl;
        
        if(leftPart == rightPart) return -1;
        else if(leftPart == -1) return rightPart;
        else return leftPart;
    }
};
