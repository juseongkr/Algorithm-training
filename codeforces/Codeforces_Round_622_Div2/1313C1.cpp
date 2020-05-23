#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
const int INF = 1e9+7;

int n;
int num[MAX], ori[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		ori[i] = num[i];
	}

	long long ans = 0;
	vector<int> answer;
	for (int k=0; k<n; ++k) {
		for (int i=k; i<n; ++i)
			if (num[i] < num[i+1])
				num[i+1] = num[i];

		for (int i=k; i>=0; i--)
			if (num[i] < num[i-1])
				num[i-1] = num[i];

		vector<int> ret;
		long long sum = 0;
		for (int i=0; i<n; ++i) {
			sum += num[i];
			ret.push_back(num[i]);
			num[i] = ori[i];
		}

		if (ans < sum) {
			ans = sum;
			answer = ret;
		}
	}

	for (int i=0; i<answer.size(); ++i)
		cout << answer[i] << " ";

	return 0;
}
