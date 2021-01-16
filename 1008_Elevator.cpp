#include<iostream>
using namespace std;
int main()
{
    int n,before=0,after,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>after;
        if(before<after){
            ans+=6*(after-before);
        }
        else{
            ans+=4*(before-after);
        }
        ans=ans+5;
        before=after;
    }
    cout<<ans;
    return 0;
}
