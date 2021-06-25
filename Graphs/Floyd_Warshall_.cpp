// Floyd-Warshall for APSP(All Pair Shortest Path)

#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

// Number of vertices
#define N 4

// print path of u from source vertex v
void printPath(int path[][N], int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}

// print the shortest cost with path between all pairs of vertices
void printSltn(int cost[N][N], int path[N][N])
{
    for (int v = 0; v < N; v++) {
        for (int u = 0; u < N; u++) {
            if (cost[v][u] == INT_MAX)
                cout << setw(5) << "inf";
            else
                cout << setw(5) << cost[v][u];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Vertices  : Shortest Path" << endl;
    for (int v = 0; v < N; v++) {
        for (int u = 0; u < N; u++) {
            if (u != v && path[v][u] != -1) {
                cout << " [" << v << " to " << u << "] : (" << v << " ";
                printPath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}

// Floyd-Warshall Algorithm
void FloydWarshall(int adjMatrix[][N])
{
    // shortest-cost / shortest route
    int cost[N][N], path[N][N];

    for (int v = 0; v < N; v++) {
        for (int u = 0; u < N; u++) {
            // at first cost=weight
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != INT_MAX)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }

    // main algorithm section
    for (int k = 0; k < N; k++) {
        for (int v = 0; v < N; v++) {
            for (int u = 0; u < N; u++) {
                // If k is a part of shortest path (v->u),
                // update the related cost and path values
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX && cost[v][k] + cost[k][u] < cost[v][u]) {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }

            // checking the negative cycle
            if (cost[v][v] < 0) {
                cout << "Negative Weight Cycle Found!!";
                return;
            }
        }
    }

    // printing the shortest path between all pairs of vertices
    printSltn(cost, path);
}

// ------------
int main()
{
    int adjMatrix[N][N] = {
        { 0, INT_MAX, -3, INT_MAX },
        { 6, 0, 5, INT_MAX },
        { INT_MAX, INT_MAX, 0, 3 },
        { INT_MAX, -1, INT_MAX, 0 }
    };

    FloydWarshall(adjMatrix);

    return 0;
}
