#include <iostream>
#include <queue>
#include <stack>

// 1. vertex visitation - 2. vertex exploration
// Breadth-first search; on binary trees: level-ordered traversal / queue-based; BFS spanning tree w/ cross-edges
// Depth-first search; on binary trees: pre-ordered traversal / stack-based; DFS spanning tree w/ back-edges

#define N 7

enum node_status
{
	UNKNOWN,
	DISCOVERED,
	VISITED,
};

int main(int argc, char const *argv[])
{
	bool adj_matrix[N][N] = {
		{0, 1, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 0},
		{0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 0},
	};

	node_status nodes[N] = {};

	std::queue<int> Q;

	Q.push(0);

	while (!Q.empty())
	{
		int current = Q.front();
		Q.pop();

		nodes[current] = VISITED;
		for (size_t i = 0; i < N; i++)
		{
			if (adj_matrix[current][i] && nodes[i] == UNKNOWN)
			{
				Q.push(i);
				nodes[i] = DISCOVERED;
			}
		}
		std::cout << current << "\t";
	}

	std::cout << "\n";

	for (size_t i = 0; i < N; i++)
	{
		nodes[i] = UNKNOWN;
	}

	std::stack<int> S;

	S.push(0);
	while (!S.empty())
	{
		int current = S.top();
		S.pop();

		if (nodes[current] == VISITED) continue;
		
		nodes[current] = VISITED;
		for (int i = N - 1; i >= 0; i--)
		{
			if (adj_matrix[current][i] && nodes[i] != VISITED)
			{
				S.push(i);
				nodes[i] = DISCOVERED;
			}
		}
		std::cout << current << "\t";
	}

	return 0;
}
