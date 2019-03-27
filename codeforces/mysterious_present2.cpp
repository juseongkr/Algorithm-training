#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<pair<long long, long long>, long long>> env;
	long long num, card_height, card_width;
	long long height, width;

	cin >> num >> card_height >> card_width;

	env.push_back({{card_height, card_width}, 0});
	for (int i=0; i<num; ++i) {
		cin >> height >> width;
		if (width > card_width && height > card_height) {
			env.push_back({{width, height}, i + 1});
		}
	}

	sort(env.begin(), env.end());
	
	for (auto e : env) {
		cout << e.second << ":[" << e.first.first << ": " << e.first.second << "], ";
	}
	cout << '\n';

	long long dp[5001];
	long long ind[5001];

	for (int i=1; i<env.size(); ++i) {
		for (int j=0; j<i; ++j) {
			if (env[j].first.first <= env[i].first.first ||
			    env[j].first.second <= env[i].first.second) {
				dp[i] = max(dp[j] + 1, dp[i]);
				if (dp[j] + 1 == dp[i])
					ind[i] = j;
			}
		}
	}

	long long index = 0, result = 0;
	for (int i=0; i<env.size(); ++i) {
		result = max(dp[i], result);
		if (dp[i] == result)
			index = i;
	}
	
	cout << result << '\n';
	if (result == 0)
		return 0;

	for (int i=1; i<env.size(); ++i) {
		cout << env[i].second << ' ';
	}
	cout << '\n';

	return 0;
}
