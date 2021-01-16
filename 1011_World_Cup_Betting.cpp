#include<iostream>
using namespace std;
int main()
{
    char game[3]={'W','T','L'};
    double odd[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>odd[i][j];
        }
    }
    double ans=1;
    for(int i=0;i<3;i++){
        double ma=odd[i][0];
        int k=0;
        for(int j=1;j<3;j++){
            if(odd[i][j]>ma){
                ma=odd[i][j];
                k=j;
            }
        }
        cout<<game[k]<<" ";
        ans*=ma;
    }
    ans=(ans*0.65-1)*2;
    printf("%.2f",ans);
    return 0;
}
