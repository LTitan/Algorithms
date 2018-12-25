#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
/*
字符串的模式匹配(返回能够匹配的第一个字符的下标)
	1.kmp算法
	2.哈希算法
*/

class KMP
{
public:
	~KMP() {}
	KMP(string a, string b) :A(a), B(b) {}
	KMP() {}
	void get_next();
	int kmp();
private:
	int *next = NULL;   //next数组
	string A, B;
};

void KMP::get_next()
{
	int len = B.length();
	next = new int[len + 1];
	next[0] = -1; //第一个是未知的，就放上-1
	int k = -1;//指针指在字符串最外面
	int j = 0;  //指针指在首地址上
	while (j < len - 1)
	{
		if (k == -1 || B[j] == B[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int KMP::kmp()
{
	this->get_next();

	int i = 0;
	int j = 0;
	int lens = A.length();
	int lenp = B.length();
	while (i < lens && j < lenp)
	{
		//如果j = -1,或者当前字符匹配成功即 A[i] == B[j]，都令指针移动
		if (j == -1 || A[i] == B[j])
		{
			i++;
			j++;
		}
		else
		{
			//如果j != -1，且当前字符匹配失败，则令 i 指针不懂，j 回退
			j = next[j];   //next[j]即为j所对应的next值
		}
	}
	delete[] next;
	if (j == lenp)
		return i - j;  //返回下标
	else
		return -1;
}
typedef unsigned long long ULL;
class Hash
{
public:
	~Hash() {}
	Hash() {}
	Hash(string a, string b) :A(a),B(b){}
	int hash();
private:
	string A, B;
	const ULL HashConst = 100000007;//哈希基数 mod hashConst

};


int Hash::hash()
{
	int lena = A.length();
	int lenb = B.length();

	if (lena > lenb) return -1;//a太长了

	ULL t = 1;
	//计算哈希计数的lena次方
	for (int i = 0; i < lena; ++i) t *= HashConst;

	//计算a和b为lena的前缀对应的哈希值
	ULL ah = 0, bh = 0;
	for (int i = 0; i < lena; ++i) ah = ah * HashConst + A[i];
	for (int i = 0; i < lena; ++i) bh = bh * HashConst + B[i];


	//匹配 更新哈希值
	for (int i = 0; i + lena <= lenb; i++)
	{
		if (ah == bh) return i;
		if (i + lena < lenb) bh = bh * HashConst + B[i + lena] - B[i] * t;
	}
	return -1;
}

int main(int argc, char **argv)
{
	string a = "helloOWorldNotheloWhy??helhellelo";
	string b = "hellelo";
	KMP test_kmp(a, b);
	cout <<"KMP:"<< test_kmp.kmp() << endl;


	Hash test_hash(b, a);

	cout << "hash:" << test_hash.hash() << endl;
	system("pause");
}
