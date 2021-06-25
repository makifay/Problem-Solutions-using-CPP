// Bellman-Ford Algorithm

//------------------------

#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

// stores graph edges
struct Edge {
    int source, dest, weight;
};

// prints path of given vertex v from source vertex
void printPath(std::vector<int> const& parent, int v)
{
    if (v < 0)
        return;

    printPath(parent, parent[v]);
    std::cout << v << " ";
}

void BellmanFord(std::vector<Edge> const& edges, int source, int N)
{
    // count number of edges of graph
    int E = edges.size();

    // distance[] and parent[] stores shortest-path/cost
    std::vector<int> distance(N, INT_MAX);
    distance[source] = 0;

    std::vector<int> parent(N, -1);

    int u, v, w, k = N;

    // Relaxation step
    while (--k) {
        for (int j = 0; j < E; j++) {
            // edge from u to v where weight is w
            u = edges[j].source, v = edges[j].dest;
            w = edges[j].weight;

            // check whether it is better to take the edge "u->v"
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                // update distance
                distance[v] = distance[u] + w;

                // set parent
                parent[v] = u;
            }
        }
    }

    // relaxation step and checking for negative-weight
    for (int i = 0; i < E; i++) {
        // edge from u to v with weight w
        u = edges[i].source, v = edges[i].dest;
        w = edges[i].weight;

        // check negative-
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            std::cout << "Cycle is Negative Weighted ";
            return;
        }
    }

    // printing
    for (int i = 0; i < N; i++) {
        std::cout << ">> distance from source to vertex " << i << ": " << std::setw(2) << distance[i] << " |  path: { ";
        printPath(parent, i);
        std::cout << "}" << '\n';
    }
}


// ----------
int main()
{
    // vector of graph edges
    std::vector<Edge> edges = {
        // (x, y, w) -> edge from x to y with weight w
        { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
        { 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }
    };

    // Set maximum number of nodes in the graph
    int N = 5;

    // source vertex is 0
    int source = 0;

    // call the algorithm
    BellmanFord(edges, source, N);

    return 0;
}

