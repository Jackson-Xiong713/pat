#include<iostream>
#include<vector>
using namespace std;
const int N=110;
vector<int> child[N];
int ansh=0;
int ans[N]={0};

void dfs(int index,int h)
{
    if(ansh<h){
        ansh=h;
    }
    if(child[index].size()==0){
        ans[h]++;
        return;
    }
    for(int i=0;i<child[index].size();i++){
        dfs(child[index][i],h+1);
    }
}

int main()
{
    int pa,ch,n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>pa>>k;
        for(int j=0;j<k;j++){
            cin>>ch;
            child[pa].push_back(ch);
        }
    }
    dfs(1,0);
    cout<<ans[0];
    for(int i=1;i<=ansh;i++){
        cout<<" "<<ans[i];
    }
    return 0;
}
