#include<iostream>
#include<string.h>
using namespace std;
int city_num,road_num,check_city_num;
int flag[1005];
int map[1005][1005];
void check(int city,int checked){
    for(int i=1;i<=city_num;i++){
        if(map[city][i]&&!flag[i]&&i!=checked){
            flag[i]=1;
            check(i,checked);
        }
    }
}
int main()
{
    int city,city_1,city_2;
    cin>>city_num>>road_num>>check_city_num;
    for(int i=0;i<road_num;i++){
        cin>>city_1>>city_2;
        map[city_1][city_2]=1;
        map[city_2][city_1]=1;
    }
    for(int i=0;i<check_city_num;i++){
        cin>>city;
        int ans=0;
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=city_num;i++){
            if(i!=city&&!flag[i]){
                check(i,city);
                ans++;
            }
        }
        cout<<ans-1<<endl;
    }
    return 0;
}