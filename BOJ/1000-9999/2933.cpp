#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<pair<int,int>> vii;
typedef vector<vii> vvii;

int r,c,n,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char board[101][101],stick;
vector<vector<bool>> visited;

void breakBlock(int height, bool isFromLeft){
	for(int i=0;i<c;++i){
		int idx=isFromLeft ? i : c-1-i;
		if(board[height][idx]=='x'){
			board[height][idx]='.'; 
			return;
		}
	}
}


void printBoard(){
	for(int i=r;i>0;--i) puts(board[i]);
}

inline bool ok(int y, int x) { return 1<=y&&y<=r && 0<=x&&x<c; }

vii bfs(int y, int x){
	vii ret;

	queue<pair<int,int>> q; bool isBottom=false;	
	q.push({y,x}); visited[y][x]=true;

	while(!q.empty()){
		int hereY=q.front().first, hereX=q.front().second; q.pop();
		if(hereY==1) isBottom=true;
		ret.push_back({hereY,hereX});

		for(int i=0;i<4;++i){
			int thereY=hereY+dir[i][0], thereX=hereX+dir[i][1];
			if(ok(thereY,thereX) && !visited[thereY][thereX] && board[thereY][thereX]=='x'){
				visited[thereY][thereX]=true;
				q.push({thereY, thereX});
			}
		}
	}

	if(isBottom) ret.clear();
	return ret;
}

vvii findComponent(){
	visited.assign(101,vector<bool>(101,false));
	vvii ret;

	for(int i=1;i<=r;++i){
		for(int j=0;j<c;++j){
			if(!visited[i][j] && board[i][j]=='x'){
				vii pointList = bfs(i,j);
				if(!pointList.empty()) ret.push_back(pointList);
			}
		}
	}

	return ret;
}

void glueBlock(const vii& v){
	vector<int> xy[101]; vii bottomList;
	for(auto& p : v) xy[p.second].push_back(p.first);
	for(int i=0;i<100;++i){
		sort(xy[i].begin(), xy[i].end());
		if(!xy[i].empty()) bottomList.push_back({i, xy[i].front()});
	}

	int len=1;
	while(1){
		bool canMove=true;
		for(auto& p : bottomList){
			int x = p.first, y = p.second;
			if(!ok(y-len,x) || board[y-len][x]=='x') {canMove=false; break;}
		}

		if(!canMove) break;
		len++;
	}

	len-=1;

	vector<int>yx[101];
	for(auto& p : v) yx[p.first].push_back(p.second);
	for(int i=1;i<=100;++i) sort(yx[i].begin(), yx[i].end());

	for(int i=1;i<=100;++i){
		for(int j : yx[i]){
			board[i][j] = '.';
			board[i-len][j] = 'x';	
		}
	}
		
}


int main(){
	scanf("%d%d",&r,&c);
	for(int i=r;i>0;--i) scanf("%s",board[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&stick);
		breakBlock(stick,i%2);

		vvii component = findComponent();
		
		if(!component.empty()) glueBlock(component.front());
	}

	printBoard();
	
}