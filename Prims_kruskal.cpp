#include <iostream>
using namespace std;

#define MAX 20
#define INF 999

// ======================================================
// EDGE CLASS
// ======================================================

class Edge {
public:
    int u, v, w;
};

// ======================================================
// GRAPH CLASS
// ======================================================

class Graph {

    int cost[MAX][MAX];
    int visited[MAX];

    Edge edges[MAX * MAX];

    int parent[MAX];

    int n, e;

public:

    // ==================================================
    // INPUT FOR PRIMS
    // ==================================================

    void inputPrims() {

        cout << "\n========== PRIM'S ALGORITHM ==========\n";

        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "\nEnter adjacency matrix:\n";
        cout << "(Enter 0 if no edge)\n\n";

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                cin >> cost[i][j];

                // IMPORTANT CORRECTION
                if(i != j && cost[i][j] == 0) {
                    cost[i][j] = INF;
                }
            }
        }
    }

    // ==================================================
    // PRIMS ALGORITHM
    // ==================================================

    void prims() {

        int mincost = 0;
        int ne = 0;

        for(int i = 0; i < n; i++) {
            visited[i] = 0;
        }

        visited[0] = 1;

        cout << "\nEdges selected in MST:\n";

        while(ne < n - 1) {

            int min = INF;
            int a = -1;
            int b = -1;

            for(int i = 0; i < n; i++) {

                if(visited[i]) {

                    for(int j = 0; j < n; j++) {

                        if(!visited[j] && cost[i][j] < min) {

                            min = cost[i][j];

                            a = i;
                            b = j;
                        }
                    }
                }
            }

            if(a != -1 && b != -1) {

                cout << a << " --> " << b
                     << "   Cost = " << min << endl;

                mincost += min;

                visited[b] = 1;

                ne++;
            }
            else {
                cout << "\nGraph is disconnected!\n";
                return;
            }
        }

        cout << "\nMinimum Cost of MST = "
             << mincost << endl;
    }

    // ==================================================
    // INPUT FOR KRUSKAL
    // ==================================================

    void inputKruskal() {

        cout << "\n========== KRUSKAL'S ALGORITHM ==========\n";

        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter number of edges: ";
        cin >> e;

        cout << "\nEnter edges:\n";
        cout << "Source Destination Weight\n\n";

        for(int i = 0; i < e; i++) {

            cout << "Edge " << i + 1 << " : ";

            cin >> edges[i].u
                >> edges[i].v
                >> edges[i].w;
        }

        // Initialize parents
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // ==================================================
    // FIND
    // ==================================================

    int find(int i) {

        while(parent[i] != i) {
            i = parent[i];
        }

        return i;
    }

    // ==================================================
    // UNION
    // ==================================================

    void unite(int i, int j) {

        int a = find(i);
        int b = find(j);

        parent[a] = b;
    }

    // ==================================================
    // SORT EDGES
    // ==================================================

    void sortEdges() {

        for(int i = 0; i < e - 1; i++) {

            for(int j = 0; j < e - i - 1; j++) {

                if(edges[j].w > edges[j + 1].w) {

                    Edge temp = edges[j];

                    edges[j] = edges[j + 1];

                    edges[j + 1] = temp;
                }
            }
        }
    }

    // ==================================================
    // KRUSKAL ALGORITHM
    // ==================================================

    void kruskal() {

        sortEdges();

        int mincost = 0;
        int edgeCount = 0;

        cout << "\nEdges selected in MST:\n";

        for(int i = 0; i < e; i++) {

            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            // Check cycle
            if(find(u) != find(v)) {

                cout << u << " --> "
                     << v
                     << "   Cost = "
                     << w << endl;

                mincost += w;

                unite(u, v);

                edgeCount++;
            }

            // MST complete
            if(edgeCount == n - 1) {
                break;
            }
        }

        // Check disconnected graph
        if(edgeCount != n - 1) {

            cout << "\nGraph is disconnected!\n";
            return;
        }

        cout << "\nMinimum Cost of MST = "
             << mincost << endl;
    }
};

// ======================================================
// MAIN FUNCTION
// ======================================================

int main() {

    Graph g;

    int choice;

    do {

        cout << "\n====================================";
        cout << "\n   MINIMUM SPANNING TREE PROGRAM";
        cout << "\n====================================";

        cout << "\n1. Prim's Algorithm";
        cout << "\n2. Kruskal's Algorithm";
        cout << "\n3. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:

                g.inputPrims();
                g.prims();

                break;

            case 2:

                g.inputKruskal();
                g.kruskal();

                break;

            case 3:

                cout << "\nProgram Ended...\n";

                break;

            default:

                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 3);

    return 0;
}
