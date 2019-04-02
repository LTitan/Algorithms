//
// Created by lyf on 2019-04-02.
//

#ifndef ASD_GRAPHFUNCTION_H
#define ASD_GRAPHFUNCTION_H

#include "utils.h"

bool *visited=nullptr;
//初始化标记数组
void init_visited(unsigned int N)
{
    if(!visited)
        visited = new bool[N+1];
    fill(visited, visited+N+1, false);
}
void remove_visited(){delete[] visited;}

//深度优先遍历
void DFS(vector<vector<Pair>> &G,int v)//传入邻接链表
{
    visited[v]=true;
    cout<<v<<"  ";
    for(auto x:G[v])
    {
        if(!visited[x.first])
            DFS(G, x.first);
    }
}


//广度优先遍历
void BFS(vector<vector<Pair>> &G,int v)
{
    queue<int> Q;
    Q.push(v);
    while (!Q.empty())
    {
        int f = Q.front();
        Q.pop();
        if(!visited[f]) {
            visited[f]=true;
            cout << f << "  "; //打印访问的节点
            for (auto x:G[f]) {
                if (!visited[x.first]) {
                    Q.push(x.first);
                }
            }
        }
    }
}
//有向图的拓扑排序
bool topologicalSort(vector<vector<Pair>> &G, vector<int> &indegree)
{
    stack<int> S;
    for(int i=1;i<indegree.size();i++)
        if(indegree[i]==0)
        {S.push(i);}
    int  c=0;
    while(!S.empty())
    {
        auto t = S.top();
        S.pop();
        cout<<t<<" ";++c;
        for(auto x:G[t])
        {
            if(!(--indegree[x.first]))
                S.push(x.first);
        }
    }
    if(c<indegree.size()-1)
    {
        cerr<<"图有环"<<endl;
        return false;
    }
    return true;
}

#endif //ASD_GRAPHFUNCTION_H
