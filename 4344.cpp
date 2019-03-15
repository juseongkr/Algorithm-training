#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int num, n, tmp, sum, cnt;
	double ave;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		scanf("%d", &n);
		vector<int> scores;
		sum = 0;
		cnt = 0;
		ave = 0;

		for (int j=0; j<n; ++j) {
			scanf("%d", &tmp);
			scores.push_back(tmp);
			sum += tmp;
		}

		ave = sum / n;
		for (int j=0; j<n; ++j) {
			if (scores[j] > ave)
				cnt++;
		}
		printf("%.3lf%%\n", ((double)cnt/n)*100);
	}

	return 0;
}
