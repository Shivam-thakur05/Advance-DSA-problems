vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long >res;
           queue<int>q;
           //Taking a vector that contain res 
           for(int i = 0 ; i < K-1 ; ++i){
               if(A[i] <0 ) {
                   q.push(A[i]);
               }
           }
           //SC -- > taking queue space for containing negative elementn of window 
           for(int i = K-1 ; i < N ; ++i){
               if(A[i] < 0){
                   q.push(A[i]);
               }
               if(!q.empty()){
                   res.push_back(q.front());
                   if(q.front() == A[i-K + 1]){
                       q.pop();
                   }
               }
               else{
                   res.push_back(0);
               }
           }
           return res;
}