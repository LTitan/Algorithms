/*
最小生成树算法
	1.prim算法
	2.kruskal算法
*/
#include "utils.h"
using namespace std;

/*
prim算法
*/
template<typename Type>
//模板类 Type为边的权值类型  N为顶点数
class Prim
{
public:
	void initilize(int);//初始化变量
	//参数一为传入的图的邻接矩阵
	//返回生产的最小生成树的边的权值和
	Type prim(Type **cost);

	//析构函数
	~Prim(){delete[] mincost;delete[] used;}
private:
	//Type cost[N][N];//cost[u][v] 表示边e(u,v)的权值
	Type *mincost= nullptr;//从集合X出发到每个顶点的最小权值
	bool *used= nullptr;//i 是否包含在X里面
	int N;//节点个数
};
template<typename Type>
void Prim<Type>::initilize(int n)
{
	//无向图如图 MST.png 所示
	//更改传入方式在main函数里面输入图，此类只是单纯的调用算法
	this->N=n;
	mincost = new Type[N+1];
	used = new bool[N+1];
	//初始化所有的最小值都是无穷大，并且顶点都不在集合内
	for (int i = 0; i <= N; i++)
	{
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[1] = 0;//自身到自身的距离为0
}
template<typename Type>
Type Prim<Type>::prim(Type **cost)
{
	/*
	计算最小生成树的权值
	时间复杂度约为O(N^2)
	*/
	Type res = 0;
	while (true)
	{
		int v = -1;
		//从不属于X的顶点中选取到X权值最小的顶点
		for (int u = 1; u <= N; u++)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;
		}
		if (v == -1) break;//证明所有点遍历完毕
		used[v] = true;
		res += mincost[v];//权值加起来
		for (int u = 1; u <= N; u++)
		{
			//更新后面的顶点
			mincost[u] = std::min(mincost[u],cost[v][u]);
		}
	}
	return res;
}

//Kruskal算法需要借助于另一种数据结构--并查集,可以提前自行学习一下
template<int N>
class UnionCheckingSet
{
public:
	void init() {
		//初始化
		for (int i = 0; i < N; i++)
			par[i] = i, rank[i] = 0;
	}
	int find(int x){
		//递归查询查询树的根节点,并更新
		if (par[x] == x) {
			return x;
		}
		else
			return par[x] = find(par[x]);
	}
	void unite(int x, int y){
		//合并x 和 y 所属的集合
		x = this->find(x);
		y = this->find(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else
		{
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
	bool same(int x, int y) { return this->find(x) == this->find(y); }
private:
	int par[N];//父亲
	int rank[N];//树的高度
};

//Kruskal算法
struct edge { int u, v, cost; }; //u和v边的权值为cost

template<typename Type, int N,int E> //N为顶点数,E为边数
class Kruskal
{
public:
	void initialize();
	Type kruskal();
private:
	edge es[E];
	UnionCheckingSet<N> ucSet;
};

template<typename Type, int N, int E>
void Kruskal<Type, N, E>::initialize()
{
	//用笨的方法赋值边，更容易理解
	es[0].u = 0, es[0].v = 2, es[0].cost = 1;
	es[1].u = 1, es[1].v = 2, es[1].cost = 2;
	es[2].u = 2, es[2].v = 3, es[2].cost = 3;
	es[3].u = 1, es[3].v = 4, es[3].cost = 10;
	es[4].u = 2, es[4].v = 5, es[4].cost = 7;
	es[5].u = 4, es[5].v = 5, es[5].cost = 5;
	es[6].u = 3, es[6].v = 5, es[6].cost = 1;
	es[7].u = 3, es[7].v = 6, es[7].cost = 5;
	es[8].u = 5, es[8].v = 6, es[8].cost = 8;
	//从小到大排序
	sort(es, es + E, [](const edge&a, const edge&b) {return a.cost < b.cost; });
	//并查集初始化
	ucSet.init();
}
template<typename Type, int N, int E>
Type Kruskal<Type, N, E>::kruskal()
{
	Type res = 0;
	for (int i = 0; i < E; i++)
	{
		edge e = es[i];
		if (!ucSet.same(e.u, e.v))
		{
			ucSet.unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main(int argc, char **argv)
{

	/*
	 //样例输入
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
	 //输出 17
	 */
    int N,E;
    cin>>N>>E;
    UnDirectedGraph dg; //创建无向图

    dg.init_graph(N);//无向图的初始化
    for(int i=0;i<E;i++)
    {
        //输入无向图的节点和边权值
        int s,v,t;
        cin>>s>>t>>v;
        dg.addEdege(s,t,v);
    }
    dg.AdjListToMatrix();//邻接表转矩阵

	Prim<int> test_prim;
	test_prim.initilize(N);
	cout<<"prim:"<<test_prim.prim(dg.getMatrix())<<endl;


	//考虑到并不熟悉utils的类，克鲁斯卡尔依然保留了原始的代码

	Kruskal<int, 7, 9> test_krus;
	test_krus.initialize();
	cout << "kruskal:" << test_krus.kruskal() << endl;

}
