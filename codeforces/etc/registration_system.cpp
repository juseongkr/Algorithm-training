#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> dic;
	string name;
	int n;

	cin >> n;

	for (int i=0; i<n; ++i) {
		cin >> name;

		auto iter = dic.find(name);
		if (iter != dic.end()) {
			iter->second++;
			cout << iter->first << iter->second << '\n';
		} else {
			dic[name] = 0;
			cout << "OK" << '\n';
		}
	}

	return 0;
}
