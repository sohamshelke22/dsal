#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

int V, E;
string landmarks[MAX];  // 1D array of strings to store landmark names
int adj[MAX][MAX];  // adjacency matrix
int visited[MAX];

// Get index of a landmark by name
int getIndex(string name) {
    for (int i = 0; i < V; i++) {
        if (landmarks[i] == name)
            return i;
    }
    return -1;
}

// DFS using adjacency matrix
void dfs(int node) {
    visited[node] = 1;
    cout << landmarks[node] << " -> ";
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i])
            dfs(i);
    }
}

// BFS using adjacency matrix
void bfs(int start) {
    int q[MAX], front = 0, rear = 0;
    int vis[MAX] = {0};
    q[rear++] = start;
    vis[start] = 1;

    while (front < rear) {
        int cur = q[front++];
        cout << landmarks[cur] << " -> ";

        for (int i = 0; i < V; i++) {
            if (adj[cur][i] && !vis[i]) {
                q[rear++] = i;
                vis[i] = 1;
            }
        }
    }
}

int main() {
    cout << "Enter number of landmarks: ";
    cin >> V;
    cin.ignore();  // To clear the newline character from the buffer

    cout << "Enter landmark names:\n";
    for (int i = 0; i < V; i++) {
        getline(cin, landmarks[i]);  // Use getline for multi-word names
    }

    cout << "Enter number of paths: ";
    cin >> E;
    cin.ignore();  // To clear the newline character

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    cout << "Enter each path as two landmark names:\n";
    for (int i = 0; i < E; i++) {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        int u = getIndex(a);
        int v = getIndex(b);

        if (u == -1 || v == -1) {
            cout << "Invalid landmark name.\n";
            i--;
            continue;
        }

        adj[u][v] = adj[v][u] = 1;  // undirected graph
    }

    // DFS and BFS
    cout << "\nDFS from first landmark:\n";
    for (int i = 0; i < V; i++) visited[i] = 0;  // reset visited
    dfs(0);

    cout << "\n\nBFS from first landmark:\n";
    bfs(0);

    return 0;
}


