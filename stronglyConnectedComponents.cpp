//Strongly connected component
#include<iostream>
#include<unordered_map>
#include<stack>
#include<list>

using namespace std;


class Graph{
    public:
    unordered_map<int,list<int> > adjList;
    void addEdge(int u,int v,bool direction)
    {
        adjList[u].push_back(v);
        if(direction == 1)
        {
            adjList[v].push_back[u];
        }
    }

void dfs1(int src,stack<int>&s, unordered_map<int,bool> &visited)
{
    visited[src] = true;
    for(auto nbr: adjList[src])
    {
        if(!visited[nbr])
        {
            dfs1(nbr,s,visited);
        }
    }
    s.push(src);
}

void dfs2(int src, unordered_map<int,bool> &visited,unordered_map<int,list<int> >& adjNew)
{
    visited[src] = true;
    for(auto nbr: adjNew[src])
    {
        if(!vis[nbr])
        {
            dfs2(nbr,visited,adjNew);
        }
    }
}

int countSCC(){
    stack<int> s;
    unordered_map<int,bool> visited;

    //finding topo order
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs1(i,s,visited);
        }
    }

    //reversal of edges
    unordered_map<int,list<int> > adjNew;
    for(auto t:adjList)
    {
        for(auto nbr:t.second)
        {
            int u = t.first;
            int v = nbr;
            //v->u insert
            adjNew[v].push_back(u);
        }
    }


    //traverse using DFS
    int count =0;
    unordered_map<int,bool> visited2;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited2[node])
        {
            dfs2(node,visited2,adjNew);
            count++;
        }
        
    }
    return count;
}
};
int main()
{
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,0,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(6,7,0);
    g.addEdge(7,7,0);

    int ans = g.countSCC();
    cout<<ans;
}