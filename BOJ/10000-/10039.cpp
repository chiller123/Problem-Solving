#include <cstdio>
int main(){
	int sum=0, temp;
	for(int i=0; i<5; i++){
		scanf("%d", &temp);
		sum += temp>=40 ? temp : 40;
	}
	printf("%d\n", sum/5);
	return 0;
}