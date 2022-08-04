#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph {
    public:
        unordered_map<int , list<int> > adj;

        void addEdge (int u, int v, bool direction) {
            //direction = 0 -> undirected
            //direction = 1 -> directed graph

            //create an edge from u to v
            adj[u].push_back(v);
            if (direction == 0) {
                adj[v].push_back(u);
            }
        }

        void printAdjList () {
            cout << "Printing the adjacency list :-\n";
            for (auto i : adj) {
                cout << i.first << "-> ";
                for (auto j : i.second) {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};
int main () {
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << endl;
    cout << "Enter number of edges: ";
    int m;
    cin >> m;
    cout << endl;
    
    graph g;
    cout << "Enter the " << m << " edges :-\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge (u, v, 0);
    }

    g.printAdjList();
    return 0;
}