#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> p,m; int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n>0) p.push(-n);
		if(n<0) m.push(n);
		if(n==0){
			if(p.empty()&&m.empty()) puts("0");
			else if(p.empty()){
				printf("%d\n",m.top()); m.pop();
			}else if(m.empty()){
				printf("%d\n",-p.top()); p.pop();
			}else{
				int n1 = p.top(), n2=m.top();
				if(abs(n1)>=abs(n2)){ printf("%d\n",n2); m.pop(); }
				else { printf("%d\n",-n1);  p.pop(); }
			}
		}
	}
}