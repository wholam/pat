#include<iostream>

using namespace std;
#define maxn 100

int tree[maxn];
int n;//树的结点个数

void downAdjust(int low, int high);//[low, high]要调整的树的范围
void upAdjust(int low, int high);
void HeapSort(int n);//结点个数
int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> tree[i];
		upAdjust(1, i);
	}
	HeapSort(n);
	return 0;
}

void downAdjust(int low, int high)
{
	int i = low;
	int j = 2 * i;
	while (j <= high)
	{
		if (j + 1 <= high && tree[j + 1] > tree[j])
			j = j + 1;
		if (tree[i] < tree[j])
		{
			swap(tree[i], tree[j]);
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
}

void upAdjust(int low, int high)
{
	int j = high;
	int i = j / 2;
	while (i >= low)
	{
		if (tree[j] > tree[i])
		{
			swap(tree[j], tree[i]);
			j = i;
			i = j / 2;
		}
		else
			break;
	}
}
void HeapSort(int n)
{
	int j = n;
	while (j > 1)
	{
		swap(tree[j], tree[1]);
		downAdjust(1, --j);
	}
}