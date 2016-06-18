#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int *BFSShortestReach (int start_node, queue<int> *adjacentNodes, int nodes)
{
	int *distances= new int [nodes];
	bool visited[nodes];
	for (int i = 0; i < nodes; i++) {
		distances[i] = 6001;
		visited[i] = false;
	}
	queue<int> q;
	q.push(start_node);
    visited[start_node-1] = true;
	distances[start_node-1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		while (!adjacentNodes[cur-1].empty())
		{
			int cur_adjacent = adjacentNodes[cur-1].front(); 
			adjacentNodes[cur-1].pop(); //pop each adjacent node off the queue
            if (visited[cur_adjacent-1] != true) {
                 visited[cur-1] = true;
                 int new_dist = distances[cur-1] + 6; //dist from cur node along this path is dist from prev node + 6 
                if (distances[cur_adjacent - 1] > new_dist)
			     	distances[cur_adjacent-1] = new_dist; //if found new path with smaller dist, update
			     q.push(cur_adjacent); //enqueue each node for later traversal   
            }
		}
	}

	return distances;
}

int main()
 {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
    	int nodes;
    	cin >> nodes;
    	int edges;
    	cin >> edges;
    	queue<int> adjacentNodes [nodes]; //build an adjacency list for each node
    	for (int j = 0; j < edges; j++) {
    		int one, two;
    		cin >> one; //get the two nodes that will share the common edge
    		cin >> two;
    		adjacentNodes[two-1].push(one); //add one to two's adjacency list
    		adjacentNodes[one-1].push(two); //add two to one's adjacency list
    	}
    	int start;
    	cin >> start;
    	int * distances = BFSShortestReach (start, adjacentNodes, nodes);
    	for (int j = 0; j < nodes; j++) {
            if (j != start-1) {
                if (distances[j] == 6001)
                    cout << -1 << " ";
                else
    	            cout << distances[j] << " ";
            }
        }
    	cout << endl;
    }
    return 0;
}
