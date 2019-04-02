//
// Created by lyf on 2019-04-02.
//
#include "GraphFunction.h"
/*
一个无向图的输入
8 9
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 7


一个有向图的输入
12 16
1 2
1 3
1 4
1 12
2 3
3 5
3 7
3 8
4 5
5 7
6 8
9 10
9 11
9 12
10 12
11 6
 */
int main()
{
    /*
     // 无向图的测试例子
UnDirectedGraph ug1;
int N,E;
cin>>N>>E;
ug1.init_graph(N);

//自己输入无向图  可以带边的值
for(int i=0;i<E;i++)
{
    int s,t;
    cin>>s>>t;
    ug1.addEdege(s,t);
    //ug1.addEdge(s,t,v); 带权值的
}
init_visited(N);
cout<<"DFS:"<<endl;
DFS(ug1.getAdjList(),1);
cout<<"\nBFS:"<<endl;
init_visited(N);
BFS(ug1.getAdjList(),1);
remove_visited();
*/
    Digraph dg1;

    int N,E;
    cin>>N>>E;
    dg1.init_graph(N);
    for(int i=0;i<E;i++)
    {
        int s,t;
        cin>>s>>t;
        dg1.addEdege(s,t);
    }
    topologicalSort(dg1.getAdjList(),dg1.getIndegree());


}
