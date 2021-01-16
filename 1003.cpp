#include<iostream>
#include<vector>
#include<cstring>
#define MaxNum 505
using namespace std;
int city_num,road_num,sou,des;
int graph[MaxNum][MaxNum];
int rescue[MaxNum];
int vis[MaxNum]={0},dis[MaxNum];
vector<int> vec[MaxNum];
void Input()
{
    cin>>city_num>>road_num>>sou>>des;
    memset(graph,-1,sizeof(graph));
    for(int i=0;i<city_num;i++){
        dis[i]=MaxNum;
    }
    for(int i=0;i<city_num;i++){
        cin>>rescue[i];
    }
    int x,y,z;
    for(int i=0;i<road_num;i++){
        cin>>x>>y>>z;
        graph[x][y]=z;
        graph[y][x]=z;
    }
}

void Dij(int source,int destination)
{
    vis[source]=1;
    dis[source]=0;
    vec[source].push_back(rescue[source]);
    int now=source;
    while(1){
        for(int i=0;i<city_num;i++){
            if(!vis[i]&&graph[now][i]!=-1){
                if(dis[now]+graph[now][i]<dis[i]){
                    dis[i]=dis[now]+graph[now][i];
                    vec[i].clear();
                    for(int j=0;j<vec[now].size();j++){
                        vec[i].push_back(vec[now][j]+rescue[i]);
                    }
                }
                else if(dis[now]+graph[now][i]==dis[i]){
                    for(int j=0;j<vec[now].size();j++){
                        vec[i].push_back(vec[now][j]+rescue[i]);
                    }
                }
            }
        }
        int minlen=MaxNum;
        for(int i=0;i<city_num;i++){
            if(!vis[i]&&minlen>dis[i]){
                now=i;
                minlen=dis[i];
            }
        }
        vis[now]=1;
        if(now==destination){
            break;
        }
    }
}
int main()
{
    Input();
    if(city_num==0){
        cout<<"0 0"<<endl;
    }
    else if(sou==des){
        cout<<"1 "<<rescue[sou];
    }
    else{
        Dij(sou,des);
        vector<int> ans=vec[des];
        cout<<ans.size()<<' ';
        int minn=ans[0];
        for(int i=1;i<ans.size();i++){
            if(minn<ans[i]){
                minn=ans[i];
            }
        }
        cout<<minn;
    }
    return 0;
}
