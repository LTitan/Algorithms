#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//原来的开发者做的是0-9以内的数字算法，并且都是暴力算法
//这里改进成动态规划算法

//最长公共子序列
int max_subsequence_dp(string str1, string str2)
{
	const int n =str1.length(), m = str2.length();
	vector<vector<int> > dp(n+1, vector<int>(m+1,0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][m];
}
//本次改成了vector比较方便，看不懂的话理解为数组即可
int maxSubstring(string str1,string str2)
{
	const int n =str1.length(), m = str2.length();
	vector<vector<int> > dp(n+1, vector<int>(m+1,0));
	int res = -1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = 0;
			res = max(res, dp[i][j]);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string str1 = "abcdefghijk", str2 = "acdej";
	//很明显是5
	cout << max_subsequence_dp(str1, str2)<<endl;
	
	// cde
	cout<<maxSubstring(str1,str2)<<endl;
	return 0;
}
