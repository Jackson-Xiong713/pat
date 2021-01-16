#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct customer{
    int service;
    int time;
};
bool cmp(customer a,customer b){
    return a.time<b.time;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int window[k];
    //窗口时间
    for(int i=0;i<k;i++){
        window[i]=8*60*60;
    }
    //记录顾客到达时间及服务时间
    vector<customer> record(n);
    for(int i=0;i<n;i++){
        int hour,minutes,second;
        scanf("%d:%d:%d %d",&hour,&minutes,&second,&record[i].service);
        if(record[i].service>60){
            record[i].service=60;
        }
        record[i].time=hour*60*60+minutes*60+second;
    }
    //按照到达时间排序
    sort(record.begin(),record.end(),cmp);
    int num=0;//记录计算的顾客数
    int sum=0;//记录总等待时间
    while(record[num].time<=17*60*60&&num<n){
        int min_i=0;
        int min_time=window[0];
        //寻找结束时间最早的窗口
        for(int i=1;i<k;i++){
            if(min_time>window[i]){
                min_time=window[i];
                min_i=i;
            }
        }
        if(record[num].time<window[min_i]){
            sum+=window[min_i]-record[num].time;
        }
        else{
            window[min_i]=record[num].time;
        }
        window[min_i]+=record[num].service*60;
        num++;
    }
    if(num==0){
        cout<<'0'<<endl;
    }
    else{
        printf("%.1f\n",1.0*sum/(60*num));
    }
    return 0;
}