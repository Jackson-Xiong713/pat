#include<iostream>
#include<string>
#include<stack>
using namespace std;

string digit[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
    string n;
    int sum=0;
    cin>>n;
    for(int i=0;i<n.length();i++){
        sum+=n[i]-'0';
    }
    stack<int> s;
    do{
        s.push(sum%10);
        sum/=10;
    }while(sum);
    cout<<digit[s.top()];
    s.pop();
    while(!s.empty()){
        cout<<" "<<digit[s.top()];
        s.pop();
    }
    return 0;
}
