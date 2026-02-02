#include <iostream>
using namespace std;

int main() {
    int n, choice;
    cout << "Enter number of vertices: ";
    cin >> n;

    int g[20][20] = {0};

    while (true) {
        cout << "\n1 Add Edge\n2 Out Degree\n3 In Degree\n4 Adjacent Vertices\n5 Number of Edges\n6 Show Matrix\n7 Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            int u, v;
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            g[u][v] = 1;
        }
        else if (choice == 2) {
            int v;
            cout << "Vertex: ";
            cin >> v;
            int c = 0;
            for (int j = 0; j < n; j++)
                c += g[v][j];
            cout << "Out Degree: " << c << endl;
        }
        else if (choice == 3) {
            int v;
            cout << "Vertex: ";
            cin >> v;
            int c = 0;
            for (int i = 0; i < n; i++)
                c += g[i][v];
            cout << "In Degree: " << c << endl;
        }
        else if (choice == 4) {
            int v;
            cout << "Vertex: ";
            cin >> v;
            cout << "Adjacent: ";
            for (int j = 0; j < n; j++)
                if (g[v][j] == 1)
                    cout << j << " ";
            cout << endl;
        }
        else if (choice == 5) {
            int c = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (g[i][j] == 1)
                        c++;
            cout << "Number of Edges: " << c << endl;
        }
        else if (choice == 6) {
            cout << "Adjacency Matrix:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << g[i][j] << " ";
                cout << endl;
            }
        }
        else break;
    }
}
