#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
#include <cstdbool>

// Breadth-first search: 1. Choose vertex; 2. Explore vertex; on binary trees: level-ordered traversal / queue-based; result: BFS spanning tree w/ cross-edges
// Depth-first search: 1. Explore vertex; 2. Choose vertex; on binary trees: pre-ordered traversal / stack-based; DFS spanning tree w/ back-edges

#define N 7

enum node_status
{
	UNKNOWN,
	DISCOVERED,
	VISITED,
};

int main(int argc, char const *argv[])
{
	// начать со списка/матрицы смежности
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

	// BFS: выбрать вершину, добавить в результат, добавить в очередь для исследования
	// BFS: исследовать вершину, каждую соседнюю вершину добавлять в очередь для исследования
	// BFS: когда вершина полностью исследована, удалять из очереди
	// BFS: когда очередь пуста, алгоритм завершен, дерево построено

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

	// DFS: выбрать вершину, добавить в результат, добавить в стэк для исследования
	// DFS: исследовать вершину, первого соседа добавить в стэк для исследования
	// DFS: повторять до появления тупиковой ветви, снимать со стека значение - это вершина, к которой надо вернуться
	// DFS: когда стэк пуст, алгоритм завершен, дерево построено

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
