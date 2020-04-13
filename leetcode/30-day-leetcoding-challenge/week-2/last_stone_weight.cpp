class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> que;

		for (const auto i : stones)
			que.push(i);

		while (que.size() > 1) {
			int x = que.top();
			que.pop();
			int y = que.top();
			que.pop();
			que.push(x-y > 0 ? x-y : 0);
		}

		return que.top();
	}
};
