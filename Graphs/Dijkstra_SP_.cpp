/// Dijkstra's Shortest Path Algorithm

// using priority_queue and vector

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

typedef std::pair<int, float> prIntFlt;
typedef std::vector<std::vector<prIntFlt> > Graph;

class Comparator {
public:
    int operator()(const prIntFlt& p1, const prIntFlt& p2)
    {
        return p1.second > p2.second;
    }
};

void addEdge(Graph& gr, int u, int v, int w)
{
    gr[u].push_back(std::make_pair(v, w));
    gr[v].push_back(std::make_pair(u, w));
}

void printPath(std::vector<int>& path, int source, int destination)
{
    std::cout << std::endl
              << ">> Path: (from " << source << " to " << destination << ")" << std::endl;

    for (int i = path.size() - 1; i >= 0; i--)
        std::cout << "->" << path[i];
}

void Dijkstra(const Graph& gr, const int source, const int destination, std::vector<int>& path, int vrtxCount)
{
    std::vector<float> dist(gr.size());
    std::vector<int> parent(gr.size());
    std::vector<bool> visited(vrtxCount, false);

    for (unsigned int i = 0; i < gr.size(); i++) {
        dist[i] = std::numeric_limits<float>::max();
        parent[i] = -1;
    }

    // pq with comparator
    std::priority_queue<prIntFlt, std::vector<prIntFlt>, Comparator> pq;

    dist[source] = 0.0f;
    pq.push(std::make_pair(source, dist[source]));

    while (!pq.empty()) {
        int u = pq.top().first; // current vertex number
        pq.pop();
        visited[u] = true;

        for (unsigned int i = 0; i < gr[u].size(); i++) {
            int v = gr[u][i].first;
            float weight = gr[u][i].second;

            // If there is a shortened path to v through u
            if ((visited[v] == false) && (dist[v] > dist[u] + weight)) {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(v, dist[v]));

                parent[v] = u;
            }

        } /// End of For
    }

    // path part
    path.clear();
    int p = destination;
    path.push_back(destination);

    while (p != source) {
        p = parent[p];
        path.push_back(p);
    }

    // Printing shortest distances
    std::cout << "Vertex - Distance" << std::endl;
    for (int i = 0; i < vrtxCount; ++i)
        std::cout << i << "      :     " << dist[i] << std::endl;
}

int main()
{
    /// --- TEST ---
    std::cout << " --- TEST --- " << std::endl;
    int vrtxCount = 9;
    Graph graph;
    graph.resize(vrtxCount);

    int source = 0;
    int destination = 5;
    std::vector<int> path;

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    Dijkstra(graph, source, destination, path, vrtxCount);
    printPath(path, source, destination);
    /*Expected Output: 
        Vertex Distance 
        0 		 0
        1 		 4
        2 		 12
        3 		 19
        4 		 21
        5 		 11
        6 		 9
        7 		 8
        8 		 14      */

    return 0;
}

