#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec;
	int n, ans = 0;

	while (1) {
		cin >> n;
		if (n == -1)
			break;
		if (n == 0) {
			for (int i=0; i<vec.size(); ++i)
				for (int j=i+1; j<vec.size(); ++j)
					if (vec[i] == vec[j]*2 || vec[j] == vec[i]*2)
						ans++;
			cout << ans << '\n';
			ans = 0;
			vec.clear();
		} else {
			vec.push_back(n);
		}
	}

	return 0;
}
