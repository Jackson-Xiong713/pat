#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,k,q;
queue<int> qu[25];
int time_cost[1005];
int window_time[25];
int endtime[1005];
int main()
{
    cin>>n>>m>>k>>q;
    for(int i=1;i<=k;i++){
        cin>>time_cost[i];
    }
    int cus=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(cus>k){
                break;
            }
            else{
                qu[j].push(cus);
            }
            cus++;
        }
    }
    while(cus<=k){
        int min_time=window_time[0]+time_cost[qu[0].front()];
        int min_i=0;
        for(int i=1;i<n;i++){
            if(window_time[i]+time_cost[qu[i].front()]<min_time){
                min_time=window_time[i]+time_cost[qu[i].front()];
                min_i=i;
            }
        }
        window_time[min_i]+=time_cost[qu[min_i].front()];
        endtime[qu[min_i].front()]=min_time;
        qu[min_i].pop();
        qu[min_i].push(cus);
        cus++;
    }
    for(int i=0;i<n;i++){
        while(!qu[i].empty()){
            window_time[i]+=time_cost[qu[i].front()];
            endtime[qu[i].front()]=window_time[i];
            qu[i].pop();
        }
    }
    for(int i=0;i<q;i++){
        int query;
        cin>>query;
        if(endtime[query]-time_cost[query]>=(17-8)*60){
            cout<<"Sorry"<<endl;
        }
        else{
            printf("%02d:",(endtime[query]/60)+8);
            printf("%02d",endtime[query]%60);
            cout<<endl;
        }
    }
    return 0;
}