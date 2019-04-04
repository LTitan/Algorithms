//
// Created by lyf on 2019-04-02.
//

#ifndef ASD_UTILS_H
#define ASD_UTILS_H

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <forward_list>
/*
 *此头文件包括图（有向图和无向图的了类）
 *图的邻接链表和邻接矩阵的表示及转换
 *
 */

using namespace std;
typedef pair<int, int> Pair;//first 代表指向的节点 second代表边的权值
#define INF 0x3f3fffff  //极大值表示不连通


//无向图的定义
class UnDirectedGraph {
    vector<vector<Pair>> adjList;//邻接链表 first 代表指向的节点 second代表边的权值
    int **adjMatrix = nullptr;//动态邻接矩阵
    unsigned int N; //图的节点数
public:
    void init_graph(unsigned int n) {
        /*
         * n 传入的节点大小
         */
        this->N = n;
        adjList.resize(N + 1);
        adjMatrix = new int *[N + 1];
        for (int i = 0; i < N + 1; i++) {
            adjMatrix[i] = new int[N + 1];
            fill(adjMatrix[i], adjMatrix[i] + N + 1, INF);//无限大距离表示不连通
        }
    }

    void addEdege(int s, int t, int v) {
        //首先采用邻接链表的方式生成无向图
        adjList[s].push_back(Pair(t, v));
        adjList[t].push_back(Pair(s, v));

    }

    void addEdege(int s, int t) {
        adjList[s].push_back(Pair(t, 1));
        adjList[t].push_back(Pair(s, 1));
    }

    void AdjListToMatrix() {
        //邻接链表转邻接矩阵
        for (int i = 1; i <= N; i++) {
            for (auto x:adjList[i])
                adjMatrix[i][x.first] = x.second,
                        adjMatrix[x.first][i] = x.second;
        }
    }

    int **getMatrix() { return adjMatrix; }

    vector<vector<Pair>> &getAdjList() { return adjList; }

    ~UnDirectedGraph() { delete[] adjMatrix; }
};

class Digraph {
private:
    vector<vector<Pair>> adjList;//邻接链表
    int **adjMatrix = nullptr;
    unsigned int N; //节点数
    vector<int> indegree;
public:
    void init_graph(unsigned int n) {
        this->N = n;
        adjList.resize(N + 1);
        indegree.resize(N + 1, 0);
        adjMatrix = new int *[N + 1];
        for (int i = 0; i < N + 1; i++) {
            adjMatrix[i] = new int[N + 1];
            fill(adjMatrix[i], adjMatrix[i] + N + 1, INF);
        }
    }

    void addEdege(int s, int t, int v) {
        //首先采用邻接链表的方式生成有向图
        adjList[s].push_back(Pair(t, v));
        ++indegree[t];
    }

    void addEdege(int s, int t) {
        //首先采用邻接链表的方式生成有向图
        adjList[s].push_back(Pair(t, 1));
        ++indegree[t];//计算节点的入度

    }

    void AdjListToMatrix() {
        for (int i = 1; i <= N; i++) {
            for (auto x:adjList[i])
                adjMatrix[i][x.first] = x.second;
        }
    }

    int **getMatrix() { return adjMatrix; }

    vector<vector<Pair>> &getAdjList() { return adjList; }

    vector<int> &getIndegree() { return indegree; }

    ~Digraph() { delete[] adjMatrix; }
};


#endif //ASD_UTILS_H
