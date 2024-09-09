/************************************************************

    Use get function that returns the value at index i
    in the infinite sorted binary array.

    get(i)
    {

    }
    

************************************************************/
long long firstOne()
{
    if(get(0) == 1) return 0;
    
    long long index = 1;

    while(get(index) != 1){
        index = index*2;
    }

    long long start = index/2;
    long long end = index;
    long long ans = -1; 

    while(start <= end){
        long long mid = start + (end-start)/2;
        if(get(mid) == 1){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}
