#include <cstdio>

int xy[3][2];
int main(){
	for(int i=0; i<3; ++i) scanf("%d%d", &xy[i][0], &xy[i][1]);
	int cross = (xy[0][0]*xy[1][1] + xy[1][0]*xy[2][1] + xy[2][0]*xy[0][1])
				- (xy[1][0]*xy[0][1] + xy[2][0]*xy[1][1] + xy[0][0]*xy[2][1]);
	printf("%d",cross > 0 ? 1 : (cross < 0 ? -1 : 0));
}