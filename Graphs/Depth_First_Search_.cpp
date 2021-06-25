// Depth First Search

// iterative implementation
// algo ref: www.techiedelight.com

#include <iostream>
#include <stack>
#include <vector>

// for storing graph edges
struct Edge {
    int src, dest;
};

class Graph {
public:
    // vector of vectors for the adjacency list
    std::vector<std::vector<int> > adjList;

    Graph(std::vector<Edge> const& edges, int N)
    {
        // resize the vector to N elements
        adjList.resize(N);

        // add edges to the undirected graph
        for (auto& edge : edges) {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// iterative DFS on graph g starting from vertex v
void iterativeDFS(Graph const& graph, int v, std::vector<bool>& discovered)
{
    // create a stack for iterative DFS
    std::stack<int> stack;

    // push the source node
    stack.push(v);

    // traverse until stack is not empty
    while (!stack.empty()) {
        // take top item and pop it
        v = stack.top();
        stack.pop();

        // if the vertex is already discovered yet, ignore it
        if (discovered[v])
            continue;

        // we will reach here if the popped vertex v
        // is not discovered yet. We print it and process
        // its undiscovered adjacent nodes into stack
        discovered[v] = true;
        std::cout << v << " ";

        // iterate over reverse order
        for (auto it = graph.adjList[v].rbegin();
             it != graph.adjList[v].rend(); ++it) {
            int u = *it;
            if (!discovered[u])
                stack.push(u);
        }
        std::cout << std::endl;
    }
}

// ---------
int main()
{
    // vector of graph edges
    std::vector<Edge> edges = {
        { 1, 2 }, { 1, 7 }, { 1, 8 }, { 2, 3 }, { 2, 6 }, { 3, 4 },
        { 3, 5 }, { 8, 9 }, { 8, 12 }, { 9, 10 }, { 9, 11 }
    };

    // Number of nodes in the graph
    int N = 13;

    // create a graph from given edges
    Graph graph(edges, N);

    // stores vertex is discovered or not
    std::vector<bool> discovered(N);

    // Do iterative DFS traversal
    for (int i = 0; i < N; i++)
        if (discovered[i] == false)
            iterativeDFS(graph, i, discovered);

    return 0;
}
