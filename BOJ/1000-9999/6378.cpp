#include <cstdio>
#include <cstring>
char numstr[1001];
int main(){
	while(~scanf("%s",numstr) && strcmp(numstr,"0")){
		int ans=0;
		for(int i=0;numstr[i];++i) ans+=numstr[i]-'0';

		while(ans>=10){
			int num=0;
			while(ans) num+=ans%10, ans/=10;
			ans=num;
		}
		printf("%d\n",ans);
	}
}