#include <iostream>
using namespace std;
#define MAX_VAL 101

int main()
{
	int graph[MAX_VAL][MAX_VAL];
	int num;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		for (int j=0; j<num; ++j) {
			scanf("%d", &graph[i][j]);

			if (graph[i][j] == 0)
				graph[i][j] = MAX_VAL;
		}
	}

	for (int k=0; k<num; ++k)
		for (int i=0; i<num; ++i)
			for (int j=0; j<num; ++j)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

	for (int i=0; i<num; ++i) {
		for (int j=0; j<num; ++j) {
			if (graph[i][j] == MAX_VAL)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}

	return 0;
}
