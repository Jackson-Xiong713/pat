#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int a,b;
    cin>>a>>b;
    int c=a+b;

    if(c==0){
        printf("0");
    }
    else{
        if(c<0){
            printf("-");
            c=-c;
        }
        while(c){
        s.push(c%10);
        c/=10;
        }
        while(!s.empty()){
            printf("%d",s.top());
            s.pop();
            if(s.size()%3==0&&!s.empty()){
                printf(",");
            }
        }
    }
    return 0;
}
