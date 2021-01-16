#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int m,in=24*60*60,out=0;
    char sign_in[16],sign_out[16];
    cin>>m;
    for(int i=0;i<m;i++){
        char id[16];
        int hh_in,mm_in,ss_in,hh_out,mm_out,ss_out,time_in,time_out;
        scanf("%s %d:%d:%d %d:%d:%d",id,&hh_in,&mm_in,&ss_in,&hh_out,&mm_out,&ss_out);
        time_in=hh_in*60*60+mm_in*60+ss_in;
        time_out=hh_out*60*60+mm_out*60+ss_out;
        if(time_in<=in){
            strcpy(sign_in,id);
            in=time_in;
        }
        if(time_out>=out){
            strcpy(sign_out,id);
            out=time_out;
        }
    }
    cout<<sign_in<<" "<<sign_out;
    return 0;
}
