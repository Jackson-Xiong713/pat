#include<iostream>
#include<string>
using namespace std;
long long GetNum(string s,long long radix)
{
    long long sum=0;
    for(int i=0;i<s.length();i++){
        sum*=radix;
        if(s[i]>='0'&&s[i]<='9'){
            sum+=(s[i]-'0');
        }
        else{
            sum+=(s[i]-'a'+10);
        }
    }
    return sum;
}
int main()
{
    string s1,s2,s;
    int tag;
    long long radix;
    long long a1,a2;
    cin>>s1>>s2>>tag>>radix;
    if(tag==1){
        a1=GetNum(s1,radix);
        s=s2;
    }
    else{
        a1=GetNum(s2,radix);
        s=s1;
    }
    int maxr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(maxr<s[i]-'0'){
                maxr=s[i]-'0';
            }
        }
        else{
            if(maxr<s[i]-'a'+10){
                maxr=s[i]-'a'+10;
            }
        }
    }
    long long st=maxr+1,en=a1+1;
    while(st<=en){
        long long mid=(st+en)/2;
        a2=GetNum(s,mid);
        if(a1==a2){
            cout<<mid;
            return 0;
        }
        else if(a1<a2||a2<0){
            en=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    cout<<"Impossible";
    return 0;
}
