//
// Created by lyf on 2019-04-02.
//

#ifndef ASD_GRAPHFUNCTION_H
#define ASD_GRAPHFUNCTION_H

#include "utils.h"

/*
 * 图的BFS和DFS遍历
 * 有向图的拓扑排序
 * 图的最短路径算法 ：
 *      --  dijkstra（邻接链表版 邻接矩阵版）
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

/*
 //迪杰特斯拉的测试无向图例子
 //输入
7 9
1	3	1
2	3	2
3	4	3
2	5	10
3	6	7
4	6	1
5	6	5
4	7	5
6	7	8
//输出dis[节点下标]
 */

// 迪杰斯特拉的邻接链表算法  时间复杂度O(N+E)
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
// 迪杰斯特拉的邻接矩阵算法 时间复杂度O(N^2)
void dijkstra(int start, int **cost,int N, vector<int> &dis)
{
    /*
     *  start 表示起始位置
     *  cost 为图的邻接矩阵
     *  N 为顶点数
     *  dis 返回为s到各点的最短距离
     */
    if(!cost) return;

    dis.resize(N+1,INF); //调整大小
    vector<bool> used(N+1,false);//已经使用的顶点
    dis[start] = 0;
    while(true)
    {
        int v=-1;
        for(int u=1;u<=N;u++)
        {
            //先找到一个没有使用的点或者距离小于原来的点
            if(!used[u]&&(v==-1||dis[u]<dis[v]))
                v=u;
        }
        if(v==-1) break;
        used[v]=true;
        //依次更新节点
        for(int u=1;u<=N;u++)
        {
            dis[u]=std::min(dis[u],dis[v]+cost[v][u]);
        }
    }
}
#endif //ASD_GRAPHFUNCTION_H
