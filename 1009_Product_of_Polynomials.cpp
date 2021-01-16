#include<iostream>
using namespace std;
double poly[1005];
double ans[2005];
int main()
{
    int k;
    cin>>k;
    int ex;
    double co;
    for(int i=0;i<k;i++){
        cin>>ex>>co;
        poly[ex]+=co;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>ex>>co;
        for(int j=0;j<=1000;j++){
            if(poly[j]!=0){
                ans[j+ex]+=co*poly[j];
            }
        }
    }
    int count=0;
    for(int i=2000;i>=0;i--){
        if(ans[i]!=0){
            count++;
        }
    }
    cout<<count;
    for(int i=2000;i>=0;i--){
        if(ans[i]!=0){
            printf(" %d %.1f",i,ans[i]);
        }
    }
    return 0;
}
