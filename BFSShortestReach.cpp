#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int prev;
int *BFSShortestReach (int start_node, int *distances, int nodes)
{
	int distances[nodes];
	bool visited[nodes];
	for (int i = 0; i < nodes; nodes++) {
		distances[i] = -1;
		visited[i] = false;
	}
	queue q;
	q.enqueue(start_node);
	distances[start_node] = 0;
	while (!q.empty()) {
		int cur = queue.front();
		q.pop_front();
		while (!adjacentNodes[cur].empty()) //loop through all adjacent nodes {
			int cur_adjacent = adjacentNodes.front(); 
			adjacentNodes[cur].pop_front(); //pop each adjacent node off the queue
			distances[cur_adjacent] = distances[cur] + 6; //dist from cur node is dist from prev node + 6
			q.enqueue(cur_adjacent); //enqueue each node for later traversal
		}
	}

	return distances;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
    	int nodes;
    	cin >> nodes;
    	int edges;
    	cin >> edges;
    	int adjancentNodes [nodes]; //build an adjacency list for each node
    	for (int j = 0; j < edges; j++) {
    		int one, two;
    		cin >> one; //get the two nodes that will share the common edge
    		cin >> two;
    		adjancentNodes[two].push_back(one); //add one to two's adjacency list
    		adjancentNodes[one].push_back(two); //add two to one's adjacency list
    	}
    	int start;
    	cin >> start;
    	int * distances = BFSShortestReach (start, nodes);
    }
    return 0;
}
