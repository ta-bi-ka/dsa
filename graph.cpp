#include<bits/stdc++.h>
using namespace std;

//graph implementation using adjacency list
class Graph{
    int V; //number of vertices
    list<int> *adj; //pointer to an array containing adjacency lists

public:
    Graph(int V){ //constructor
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v){ //function to add an edge to graph
        adj[u].push_back(v); //add v to u's list
        adj[v].push_back(u); //add u to v's list
    }

    void BFS(){ //function to print BFS traversal from a given source s
        queue<int> q; //create a queue for BFS
        vector<bool> visited(V,false); //mark all vertices as not visited
        q.push(0); //enqueue the source vertex
        visited[0]=true; //mark the source vertex as visited
        while(!q.empty()){ //loop until the queue is empty
            int s=q.front(); //dequeue a vertex from the queue and print it
            cout<<s<<" ";
            q.pop();
            for(int i:adj[s]){ //get all adjacent vertices of the dequeued vertex s
                if(!visited[i]){ //if an adjacent has not been visited, then mark it visited and enqueue it
                    visited[i]=true;
                    q.push(i);
                }
            }
        }

    }
    //dfs
    void DFSUtil(int v, vector<bool> &visited){
        visited[v]=true; //mark the current node as visited and print it
        cout<<v<<" ";
        for(int i:adj[v]){ //recur for all the vertices adjacent to this vertex
            if(!visited[i]){
                DFSUtil(i,visited);
            }
        }
    }

    void DFS(int v){ //function to print DFS traversal from a given source v
        vector<bool> visited(V,false); //mark all vertices as not visited
        DFSUtil(v,visited);
    }

    void printGraph(){ //function to print the graph
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<": ";
            for(int j:adj[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};


//number of islands in a 2D grid














int main(){
    Graph g(4); //create a graph with 4 vertices
    g.addEdge(0,1); //add edges to the graph
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2); //print BFS traversal starting from vertex 2
    cout<<"\nGraph adjacency list representation:\n";
    g.printGraph(); //print the graph
    cout<<"\nDepth First Traversal (starting from vertex 2) \n";
    g.DFS(2); //print DFS traversal starting from vertex 2
    return 0;
}
