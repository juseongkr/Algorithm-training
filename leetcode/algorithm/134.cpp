class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int state = 0, total = 0, idx = 0;

		for (int i=0; i<gas.size(); ++i) {
			int start = gas[i] - cost[i];
			if (state + start >= 0) {
				state += start;
			} else {
				state = 0;
				idx = i+1;
			}
			total += start;
		}

		return total >= 0 ? idx : -1;
	}
};
