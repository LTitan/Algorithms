#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//原来的开发者做的是0-9以内的数字算法，并且都是暴力算法
//这里改进成动态规划算法

//最长公共子序列
int max_subsequence_dp(string str1, string str2)
{
	int **dp = new int*[str1.length()+1];
	for (int i = 0; i <= str1.length(); ++i)
		dp[i] = new int[str2.length() + 1];

	for (int i = 1; i <= str1.length(); ++i)
	{
		for (int j = 1; j <= str2.length(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int temp = dp[str1.length()][str2.length()];
	delete[] dp;
	dp = nullptr;
	return temp;
}
int main(int argc, char const *argv[])
{
	string str1 = "abcdefghijk", str2 = "acdej";
	//很明显是5
	cout << max_subsequence_dp(str1, str2)<<endl;
	system("pause");
	return 0;
}
