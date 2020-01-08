#include<queue>
#include<cstdio>

using namespace std;
int f, s, g, u, d;
#define maxs 1000001
bool node[maxs];
int edge[maxs];

int main()
{

	scanf(" %d %d %d %d %d", &f, &s, &g, &u, &d);
	queue<int> q;
	q.push(s);
	edge[s] = 0;
	node[s] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int next = now + u;
		if (!node[next] && next <= f)
		{
			node[next] = true;
			edge[next] = edge[now] + 1;
			q.push(next);
		}
		next = now - d;
		if (!node[next] && next >= 1)
		{
			node[next] = true;
			edge[next] = edge[now] + 1;
			q.push(next);
		}
	}
	if (!node[g])
		printf("use the stairs\n");
	else
		printf("%d\n", edge[g]);
}