#include <iostream>
using namespace std;
double a[1005];
int main(){
	int k,x,m,count = 0;
	double y;
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		a[x] += y;
	}
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		a[x] += y;
	}
	for(int i = 0; i < 1001; i++){
		if(a[i] != 0) count++;
	}
	cout<<count;
	for(int i = 1001; i >= 0; i--){
		if(a[i] != 0){
			printf(" %d %.1f",i,a[i]);
		}
	}
	return 0;
}
