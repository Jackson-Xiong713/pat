#include<iostream>
#include<math.h>
using namespace std;
int is(int x){
    if(x==1){
        return 0;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,d;
    while(1){
        cin>>n;
        if(n<0){
            break;
        }
        cin>>d;
        if(!is(n)){
            cout<<"No"<<endl;
            continue;
        }
        int after_n=0;
        while(n){
            after_n=after_n*d+n%d;
            n/=d;
        }
        if(is(after_n)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}