#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int i = 1;
    
    while(i <= n){
        int j = 1;
        if(i == 1 || i == n){
            while(j <= n){
                cout<<"*"<<" ";
                j++;
            }
        }
        else{
            while(j <= n){
                if(j == 1 || j == n){
                    cout<<"*"<<" ";
                }
                else{
                    cout<<"  ";
                }
                j++;
            }
        }
       cout<<endl; 
      i++;
    }
    return 0;
}