#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<pair<double, int>> capa;
	vector<int> order;
	int type[10001];
	int t, num, vol, sum = 0;
	double c;

	scanf("%d %d", &num, &vol);

	for (int i=0; i<num; ++i) {
		scanf("%d %lf", &t, &c);
		type[i] = t;
		capa.push({c / t, i});
	}

	for (int i=0; i<num; ++i) {
		pair<double, int> pick = capa.top();
		if (vol >= type[pick.second]) {
			vol -= type[pick.second];
			sum += pick.first * type[pick.second];
			order.push_back(pick.second + 1);
			capa.pop();
		}
	}

	printf("%d\n", sum);

	for (int i=0; i<order.size(); ++i)
		printf("%d ", order[i]);

	printf("\n");

	return 0;
}
