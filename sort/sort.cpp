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
	void SelectSort(); //选择排序
	void HeapSort();   //堆排序
	void BubbleSort(); //冒泡排序
	void QuickSort();  //快速排序
	void MergeSort();  //归并排序
  private:
	vector<value_type> usedArray;	  //排序使用的数组
	vector<value_type> originalArrary; //保存排序以前的乱序数组

	void adjustHeap(int, int);							  //堆排序构造堆
	void QuickSortRun(int, int);						  //快排递归
	void MergeSortRun(int, int, vector<value_type> &);	//归并排序递归
	void MergeArray(int, int, int, vector<value_type> &); //归并数组函数
	int devision(int, int);								  //快速排序双指针,找出重合位置
	inline void printArray()							  //打印函数
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
		for (int j = i + 1; j < len; j++) //不断找最小的下标
			if (usedArray[j] < usedArray[minx])
				minx = j;
		if (minx != i)
			swap(usedArray[i], usedArray[minx]);
	}

	this->printArray();
}
template <typename T>
void SortSets<T>::adjustHeap(int i, int length)
{
	value_type temp = usedArray[i];
	for (int k = i * 2 + 1; k < length; k = k * 2 + 1)
	{
		if (k + 1 < length && usedArray[k] < usedArray[k + 1])
			k++;
		if (usedArray[k] > temp)
		{
			usedArray[i] = usedArray[k];
			i = k;
		}
		else
			break;
	}
	usedArray[i] = temp;
}
template <typename T>
void SortSets<T>::HeapSort()
{
	this->copyTo();
	for (int i = usedArray.size() / 2 - 1; i >= 0; i--)
	{
		adjustHeap(i, usedArray.size());
	}
	for (int i = usedArray.size() - 1; i > 0; i--)
	{
		swap(usedArray[0], usedArray[i]);
		adjustHeap(0, i);
	}
	this->printArray();
}

template <typename T>
void SortSets<T>::BubbleSort()
{
	this->copyTo();
	for (int i = 0; i < usedArray.size() - 1; i++)
		for (int j = 0; j < usedArray.size() - i - 1; j++)
			if (usedArray[j] > usedArray[j + 1])
				swap(usedArray[j], usedArray[j + 1]);
	this->printArray();
}
template <typename T>
int SortSets<T>::devision(int left, int right)
{
	value_type temp = usedArray[left];
	while (left < right)
	{
		while (left < right && usedArray[right] >= temp)
			right--;
		if (left < right)
			usedArray[left] = usedArray[right];
		while (left < right && usedArray[left] <= temp)
			left++;
		if (left < right)
			usedArray[right] = usedArray[left];
	}
	usedArray[left] = temp;
	return left;
}
template <typename T>
void SortSets<T>::QuickSort()
{
	this->copyTo();
	this->QuickSortRun(0, usedArray.size() - 1);
	this->printArray();
}
template <typename T>
void SortSets<T>::QuickSortRun(int left, int right)
{
	if (left < right)
	{
		auto base = this->devision(left, right);
		QuickSortRun(left, base - 1);
		QuickSortRun(base + 1, right);
	}
}
template <typename T>
void SortSets<T>::MergeArray(int left, int mid, int right, vector<value_type> &temp)
{
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (usedArray[i] <= usedArray[j])
			temp[k++] = usedArray[i++];
		else
			temp[k++] = usedArray[j++];
	}
	while (i <= mid)
		temp[k++] = usedArray[i++];
	while (j <= right)
		temp[k++] = usedArray[j++];
	for (int t = 0; t < k; t++)
		usedArray[left + t] = temp[t];
}
template <typename T>
void SortSets<T>::MergeSortRun(int left, int right, vector<value_type> &temp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSortRun(left, mid, temp);
		MergeSortRun(mid + 1, left, temp);
		MergeArray(left, mid, right, temp);
	}
}
template <typename T>
void SortSets<T>::MergeSort()
{
	this->copyTo();
	vector<value_type> temp;
	temp.resize(usedArray.size());
	MergeSortRun(0, usedArray.size() - 1, temp);
	this->printArray();
}
int main()
{
	vector<int> a{123, 435, -231, 45, 0, 2332, 10, 99};
	SortSets<int> test(a);
	//希尔排序测试
	test.ShellSort();
	//选择排序测试
	test.SelectSort();
	//堆排序测试
	test.HeapSort();
	//冒泡排序测试
	test.BubbleSort();
	//快速排序测试
	test.QuickSort();
	//归并排序测试
	test.MergeSort();
	return 0;
}
