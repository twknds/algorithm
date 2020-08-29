
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct node * nodePointer;
typedef struct node
{
	int num;
	nodePointer next;
}node;

nodePointer ary;
nodePointer * queue;
int front, rear;
int * visit;

int main()
{
	int N, M, V;
	int n1, n2;
	scanf("%d %d %d", &N, &M, &V);
	ary = (node*)malloc(sizeof(node) * (N+1));
	queue = (nodePointer*)malloc(sizeof(nodePointer) * N);
	visit = (node*)malloc(sizeof(int) * (N + 1));
	for (int i = 1; i <= N; i++) {
		ary[i].num = 0;
		ary[i].next = NULL;
		visit[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &n1, &n2);
		make_graph(n1, n2);	make_graph(n2, n1);
	}
	dfs(V);
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	printf("\n");
	bfs(V);
}

void make_graph(int num1, int num2) {
	node * temp, *cur;
	temp = (node*)malloc(sizeof(node));
	temp->num = num2;
	temp->next = NULL;
	if (ary[num1].next == NULL)
		ary[num1].next = temp;
	else
	{
		cur = &ary[num1];
		while (cur->next != NULL) {
			if (cur->next->num > num2) {
				temp->next = cur->next;
				cur->next = temp;
				return;
			}
			cur = cur->next;
		}
		cur->next = temp;
	}
}

void dfs(int num)
{
	nodePointer cur = &ary[num];
	if (visit[num] == 1 || num == 0)
		return;
	visit[num] = 1;
	printf("%d ", num);
	while (cur != NULL)
	{
		dfs(cur->num);
		cur = cur->next;
	}
}

nodePointer pop()
{
	return queue[front++];
}

void push(int num)
{
	queue[rear++] = &ary[num];
}

void bfs(int num)
{
	nodePointer cur;
	visit[num] = 1;
	printf("%d ", num);
	push(num);
	while (front != rear)
	{
		cur = pop();
		for (; cur; cur = cur->next)
		{
			if (visit[cur->num] == 0 && cur->num != 0)
			{
				printf("%d ", cur->num);
				push(cur->num);
				visit[cur->num] = 1;
			}
		}
	}
}