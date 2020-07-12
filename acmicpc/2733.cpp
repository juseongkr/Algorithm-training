#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
#define MAX 32768

int T;
char arr[MAX];
unordered_map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	string flush;
	getline(cin, flush);
	for (int t=1; t<=T; ++t) {
		mp.clear();
		string ans, s;
		fill(arr, arr+MAX, 0);
		int ptr = 0;
		while (1) {
			string p;
			getline(cin, p);
			if (p == "end")
				break;

			for (int i=0; i<p.length(); ++i) {
				if (p[i] == '%')
					break;
				if (p[i] != ' ')
					s += p[i];
			}
		}

		stack<int> st;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '[') {
				st.push(i);
			} else if (s[i] == ']') {
				int j = st.top();
				st.pop();
				mp[i] = j;
				mp[j] = i;
			}
		}

		cout << "PROGRAM #" << t << ":\n";
		if (st.size()) {
			ans = "COMPILE ERROR";
		} else {
			for (int i=0; i<s.length(); ) {
				if (s[i] == '>') {
					ptr = ptr == MAX-1 ? 0 : ptr+1;
					i++;
				} else if (s[i] == '<') {
					ptr = ptr == 0 ? MAX-1 : ptr-1;
					i++;
				} else if (s[i] == '+') {
					arr[ptr] = arr[ptr] == 255 ? 0 : (char)(arr[ptr]+1);
					i++;
				} else if (s[i] == '-') {
					arr[ptr] = arr[ptr] == 255 ? 255 : (char)(arr[ptr]-1);
					i++;
				} else if (s[i] == '.') {
					ans += arr[ptr];
					i++;
				} else if (s[i] == '[') {
					if (arr[ptr] == 0)
						i = mp[i]+1;
					else
						i++;
				} else if (s[i] == ']') {
					if (arr[ptr] != 0)
						i = mp[i];
					else
						i++;
				} else {
					i++;
				}
			}
		}
		cout << ans << '\n';

	}

	return 0;
}
