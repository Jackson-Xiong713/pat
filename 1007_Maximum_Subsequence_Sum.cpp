#include<iostream>
using namespace std;
int se[10005];
int main()
{
    int k;
    cin>>k;
    int ans_st,ans_en,sum=0,ma=-1,st=0;
    for(int i=0;i<k;i++){
        cin>>se[i];
        sum+=se[i];
        if(sum<0){
            sum=0;
            st=i+1;
        }
        else if(sum>ma){
            ma=sum;
            ans_st=st;
            ans_en=i;
        }
    }
    if(ma<0){
        ma=0;
    }
    cout<<ma<<" "<<se[ans_st]<<" "<<se[ans_en];
    return 0;
}
