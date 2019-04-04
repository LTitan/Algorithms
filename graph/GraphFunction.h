//
// Created by lyf on 2019-04-02.
//

#ifndef ASD_GRAPHFUNCTION_H
#define ASD_GRAPHFUNCTION_H

#include "utils.h"

/*
 * 图的BFS和DFS遍历
 * 有向图的拓扑排序
 * 图的最短路径算法
 */

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
//有向图的拓扑排序--迭代版
bool topologicalSort(vector<vector<Pair>> &G, vector<int> &indegree)
{
    //G 为图的邻接链表 indegree为各节点的度
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

void dijkstra(int start, vector<vector<Pair>> &G, vector<int> &dis) {
    /*
     * start  start表示出发的位置
     * G  图的邻接链表
     * dis  返回距离dis数组
     *
     */
    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> que; //按Pfirst形成的优先队列
    dis.resize(G.size() + 1, INF);
    //fill(d, d + G.size() + 10, INF);
    dis[start] = 0;

    que.push(P(0, start));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dis[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            auto e = G[v][i];
            if (dis[e.first] > dis[v] + e.second) {
                dis[e.first] = dis[v] + e.second;
                que.push(P(dis[e.first], e.first));
            }
        }
    }
}
#endif //ASD_GRAPHFUNCTION_H
