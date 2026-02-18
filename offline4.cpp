#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    bool isConnected(int u, int v)
    {
        for (int i : adj[u])
        {
            if (i == v)
            {
                return true;
            }
        }
        return false;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int v, vector<bool> &visited, vector<int> &currentgroup)
    {
        visited[v] = true;
        currentgroup.push_back(v);
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                dfs(i, visited, currentgroup);
            }
        }
    }

    void DFS_helper(int v)
    {
        vector<bool> visited(V, false);
        vector<int> currentgroup;
        // vector<int> missing;
        vector<vector<int>> groups;
        // vector<vector<int>> allmissing;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                currentgroup.clear();
                dfs(i, visited, currentgroup);
                groups.push_back(currentgroup);
            }
        }

        printGroup(groups);
    }
    void printGroup(const vector<vector<int>> &groups)
    {
        cout << groups.size() << endl;
        for (int i = 0; i < groups.size(); i++)
        {
            cout << "Group " << i + 1 << ": ";
            cout << "{";
            for (int j = 0; j < groups[i].size(); j++)
            {

                cout << groups[i][j] << " ";
                if (j != groups[i].size() - 1)
                {
                    cout << ",";
                }
            }
            cout << "}";
            cout << "  |  ";
            bool nomissing = true;
            for (int j = 0; j < groups[i].size(); j++)
            {
                for (int k = j + 1; k < groups[i].size(); k++)
                {
                    if (!isConnected(groups[i][j], groups[i][k]) && !isConnected(groups[i][k], groups[i][j]))
                    {

                        cout << "[" << groups[i][j] << "," << groups[i][k] << "]  ";
                        nomissing = false;
                    }
                }
               
            }
            if (nomissing)
            {
                cout << "None";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(3, 4);
    g1.addEdge(5, 6);
    g1.addEdge(4, 8);
    g1.addEdge(2, 5);
    g1.addEdge(6, 2);
    g1.addEdge(1, 7);
    g1.DFS_helper(0);

    Graph g2(8);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(3, 0);
    g2.addEdge(3, 4);
    g2.addEdge(5, 6);
    g2.addEdge(6, 7);
    g2.DFS_helper(0);

    return 0;
}
