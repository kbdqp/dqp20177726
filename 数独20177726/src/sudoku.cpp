#include<iostream>
using namespace std;

bool sign = false;/* ������ɱ�־ */

int num[9][9];/* ������������ */

/* �������� */
void Input();
void Output();
bool Check(int n, int key);
int DFS(int n);
int len;

int main()
{
	cout << "������һ��len*len���������󣬿�λ��0��ʾ:" << endl;
	cin >> len;
	Input();
	DFS(0);
	Output();
	system("pause");
}
/* ������������ */
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
/* ����������� */
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
/* �ж�key����nʱ�Ƿ��������� */
bool Check(int n, int key)
{
	/* �ж�n���ں����Ƿ�Ϸ� */
	for (int i = 0; i < len; i++)
	{
		/* jΪn������ */
		int j = n / len;
		if (num[j][i] == key) return false;
	}
	/* �ж�n���������Ƿ�Ϸ� */
	for (int i = 0; i < len; i++)
	{
		/* jΪn������ */
		int j = n % len;
		if (num[i][j] == key) return false;
	}

	/* ȫ���Ϸ���������ȷ */
	return true;
}
/* ���ѹ�������*/
int DFS(int n)
{
	/* ���еĶ����ϣ��˳��ݹ� */
	if (n > len* len - 1)
	{
		sign = true;
		return 0;
	}
	/* ��ǰλ��Ϊ��ʱ���� */
	if (num[n / len][n % len] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		/* ����Ե�ǰλ����ö�ٲ��� */
		for (int i = 1; i <= len; i++)
		{
			/* ��������ʱ�������� */
			if (Check(n, i) == true)
			{
				num[n / len][n % len] = i;
				/* �������� */
				DFS(n + 1);
				/* ����ʱ�������ɹ�����ֱ���˳� */
				if (sign == true) return 0;
				/* ������첻�ɹ�����ԭ��ǰλ */
				num[n / len][n % len] = 0;
			}
		}
	}
}
