#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;


template <typename T>
class SortSets
// 排序集合 类型为T T可以为任意实数类型
{
	typedef T value_type; //重新命名为 value_type
  public:
	SortSets(){};
	~SortSets() {}
	SortSets(const vector<value_type> &temp)
	{
		originalArrary.resize(temp.size());
		copy(temp.begin(), temp.end(), originalArrary.begin());
	}

	void InsertSort(); //插入排序声明
	void ShellSort();  //希尔排序声明
	void SelectSort();

  private:
	vector<value_type> usedArray;	  //排序使用的数组
	vector<value_type> originalArrary; //保存排序以前的乱序数组

	inline void printArray() //打印函数
	{
		cout << "results:" << endl;
		for (auto x : usedArray)
			cout << x << " ";
		cout << endl;
	}
	inline void copyTo() //将 原始数组 copy给要排序的数组
	{
		usedArray.clear();
		usedArray.resize(originalArrary.size());
		copy(originalArrary.begin(), originalArrary.end(), usedArray.begin());
	}
};

//插入排序实现
template <typename T>
void SortSets<T>::InsertSort()
{
	this->copyTo(); // 拷贝原始数组

	int preIndex;
	value_type current;

	for (int i = 1; i < usedArray.size(); i++)
	{
		preIndex = i - 1;
		current = usedArray[i];
		while (preIndex >= 0 && usedArray[preIndex] > current)
		{
			usedArray[preIndex + 1] = usedArray[preIndex];
			preIndex--;
		}
		usedArray[preIndex + 1] = current;
	}

	//排序完成打印数组
	this->printArray();
}
//希尔排序实现
template <typename T>
void SortSets<T>::ShellSort()
{
	this->copyTo();
	int step = 1, len = usedArray.size();
	//以 step为步长  步长到1结束排序
	while (step < len)
		step = step * 3 + 1;
	while (step >= 1)
	{
		for (int i = step; i < len; i++)
		{
			int j = i;
			while (j >= step && usedArray[j] < usedArray[j - step])
			{
				swap(usedArray[j], usedArray[j - step]);
				j--;
			}
		}
		step /= 3;
	}
	this->printArray();
}
//选择排序
template <typename T>
void SortSets<T>::SelectSort()
{
	this->copyTo();
	int len = usedArray.size();
	for (int i = 0; i < len - 1; i++)
	{
		int minx = i;
		for (int j = i + 1; j < len; j++)//不断找最小的下标
			if (usedArray[j] < usedArray[minx])
				minx = j;
		if (minx != i)
			swap(usedArray[i], usedArray[minx]);
	}

	this->printArray();
}

int main()
{
	vector<int> a{123, 435, -231, 45, 0, 2332, 10, 99};
	
	SortSets<int> test(a);
	test.ShellSort();
	test.SelectSort();

	return 0;
}
