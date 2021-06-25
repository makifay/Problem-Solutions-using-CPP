// Breadth First Search/Traverse

// implementation with vector and queue

#include <bits/stdc++.h>

std::vector<bool> visited;
std::vector<std::vector<int> > grAdjcnt; // for neighbours of vertices

// for storing graph edges
struct Edge {
    int src, dest;
};

// adding edge into neighbours
void edge(int a, int b)
{
    grAdjcnt[a].push_back(b); // enough for directed graph
}

void BFS(int u)
{
    std::queue<int> q;

    q.push(u);
    visited[u] = true;

    while (!q.empty()) {

        // take front and pop it
        int fr = q.front();
        q.pop();

        std::cout << fr << " ";

        for (auto i : grAdjcnt[fr]) {
            // push into queue and change the visited as true if not visited
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

    } // End of While
}

// ---------------
int main()
{
    int n = 15; // n: node number

    visited.assign(n, false);
    grAdjcnt.assign(n, std::vector<int>());

    // vector of graph edges
    std::vector<Edge> edges = {
        { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 }, { 5, 9 },
        { 5, 10 }, { 4, 7 }, { 4, 8 }, { 7, 11 }, { 7, 12 }
        // vertex 0, 13 and 14 are single nodes
    };

    for (auto e : edges)
        edge(e.src, e.dest);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            BFS(i);
    }

    return 0;
}


