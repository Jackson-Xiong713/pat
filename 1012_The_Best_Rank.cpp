#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
char sub[4]={'A','C','M','E'};
struct student
{
    int grade[4];
    student()
    {
        for(int i=0;i<4;i++){
            grade[i]=-1;
        }
    }
    student(int c,int m,int e)
    {
        grade[0]=(int)((c+m+e)/3+0.5);
        grade[1]=c;
        grade[2]=m;
        grade[3]=e;
    }
};
map<int,student> stu;
int A[2005];
int C[2005];
int M[2005];
int E[2005];
int main()
{
    int n,mm;
    cin>>n>>mm;
    for(int i=0;i<n;i++){
        int id;
        int c,m,e;
        cin>>id>>c>>m>>e;
        struct student s(c,m,e);
        stu[id]=s;
        A[i]=(int)((c+m+e)/3+0.5);
        C[i]=c;
        M[i]=m;
        E[i]=e;
    }
    sort(A,A+n,cmp);
    sort(C,C+n,cmp);
    sort(M,M+n,cmp);
    sort(E,E+n,cmp);
    for(int i=0;i<mm;i++){
        int id,mi=n+1,mini=-1;
        cin>>id;
        if(stu[id].grade[1]<0){
            cout<<"N/A"<<endl;
            continue;
        }
        int a=find(A,A+n,stu[id].grade[0])-A;
        if(a<mi){
            mi=a;
            mini=0;
        }
        int c=find(C,C+n,stu[id].grade[1])-C;
        if(c<mi){
            mi=c;
            mini=1;
        }
        int m=find(M,M+n,stu[id].grade[2])-M;
        if(m<mi){
            mi=m;
            mini=2;
        }
        int e=find(E,E+n,stu[id].grade[3])-E;
        if(e<mi){
            mi=e;
            mini=3;
        }
        cout<<mi+1<<" "<<sub[mini]<<endl;
    }
    return 0;
}
