#include<iostream>
using namespace std;

bool sign = false;/* 构造完成标志 */

int num[9][9];/* 创建数独矩阵 */

/* 函数声明 */
void Input();
void Output();
bool Check(int n, int key);
int DFS(int n);
int len;

int main()
{
	cout << "请输入一个len*len的数独矩阵，空位以0表示:" << endl;
	cin >> len;
	Input();
	DFS(0);
	Output();
	system("pause");
}
/* 读入数独矩阵 */
void Input()
{
	char temp[9][9];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cin >> temp[i][j];
			num[i][j] = temp[i][j] - '0';
		}
	}
}
/* 输出数独矩阵 */
void Output()
{
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
}
/* 判断key填入n时是否满足条件 */
bool Check(int n, int key)
{
	/* 判断n所在横列是否合法 */
	for (int i = 0; i < len; i++)
	{
		/* j为n竖坐标 */
		int j = n / len;
		if (num[j][i] == key) return false;
	}
	/* 判断n所在竖列是否合法 */
	for (int i = 0; i < len; i++)
	{
		/* j为n横坐标 */
		int j = n % len;
		if (num[i][j] == key) return false;
	}

	/* 全部合法，返回正确 */
	return true;
}
/* 深搜构造数独*/
int DFS(int n)
{
	/* 所有的都符合，退出递归 */
	if (n > len* len - 1)
	{
		sign = true;
		return 0;
	}
	/* 当前位不为空时跳过 */
	if (num[n / len][n % len] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		/* 否则对当前位进行枚举测试 */
		for (int i = 1; i <= len; i++)
		{
			/* 满足条件时填入数字 */
			if (Check(n, i) == true)
			{
				num[n / len][n % len] = i;
				/* 继续搜索 */
				DFS(n + 1);
				/* 返回时如果构造成功，则直接退出 */
				if (sign == true) return 0;
				/* 如果构造不成功，还原当前位 */
				num[n / len][n % len] = 0;
			}
		}
	}
}
