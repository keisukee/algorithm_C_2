#include <stdio.h>
#include <string.h>

#define min(x,y) x < y ? x:y
#define max(x,y) x > y ? x:y
#define INF 100000000

int n,x;
int a[50], b[50], c[50], cost[50];
int mem[101][51][51];

int dfs(int, int, int);

int main(int argc, char const *argv[]) {
	int cases, i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&x);
		for(i = 0;i < n;i++){
			scanf("%d %d %d %d",a+i, b+i, c+i, cost+i);
		}
		memset(mem,-1,sizeof(mem));
		int res = dfs(0,0,0);
		printf("%d\n", res == INF ? -1:res);
	}
	return 0;
}

// 深さ優先探索 depth first search
int dfs(int pen,int apple,int pineapple) {
  int i;
	if (pen == 2*x && apple == x && pineapple == x) return 0;
	if (mem[pen][apple][pineapple] != -1) return mem[pen][apple][pineapple];
	int* res = &mem[pen][apple][pineapple];
	*res = INF;
	for(i = 0; i < n;i++){
		*res = min(*res, dfs(min(pen+a[i],2*x), min(apple+b[i],x), min(pineapple+c[i],x))+cost[i]);
	}
	return *res;
}
