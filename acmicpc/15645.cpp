#include <iostream>
using namespace std;

int line_max[3], line_min[3], cur_max[3], cur_min[3];

int main()
{
	int n, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			scanf("%d", &t);
			cur_min[j] = cur_max[j] = t;
			if (j == 0) {
				cur_min[j] += min(line_min[0], line_min[1]);
				cur_max[j] += max(line_max[0], line_max[1]);
			} else if (j == 1) {
				cur_min[j] += min(line_min[0], min(line_min[1], line_min[2]));
				cur_max[j] += max(line_max[0], max(line_max[1], line_max[2]));
			} else {
				cur_min[j] += min(line_min[1], line_min[2]);
				cur_max[j] += max(line_max[1], line_max[2]);
			}
		}
		for (int j=0; j<3; ++j) {
			line_max[j] = cur_max[j];
			line_min[j] = cur_min[j];
		}
	}
	int max_val = max(line_max[0], max(line_max[1], line_max[2]));
	int min_val = min(line_min[0], min(line_min[1], line_min[2]));

	printf("%d %d\n", max_val, min_val);

	return 0;
}
