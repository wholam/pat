#include<iostream>
#include<vector>

using namespace std;
bool flag = false;

void insertion_sort(vector<int> & tree, int n);
void heapsort(vector<int>& tree, int n);
void downAdjust(vector<int>& tree, int low, int high);
vector<int> des;
int main()
{
	int n, i, j, tmp;
	cin >> n;
	vector<int> tree1, tree2;
	tree1.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		tree1.push_back(tmp);
	}
	des.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		des.push_back(tmp);
	}
	tree2 = tree1;
	insertion_sort(tree1, n);
	if (flag == false)
		heapsort(tree2, n);
	return 0;
}
void insertion_sort(vector<int>& tree, int n)
{
	int i = 2;
	int j, tmp, k;
	while (i <= n)
	{
		tmp = tree[i];
		j = 1;
		while (j <= i - 1 && tree[j] <= tmp)
			j++;
		for (k = i; k > j; k--)
			tree[k] = tree[k - 1];
		tree[j] = tmp;
		i++;
		if (tree == des)
		{
			flag = true;
			continue;
		}
		if (flag == true)
		{
			cout << "Insertion Sort" << endl;
			for (j = 1; j <= n; j++)
				j == n ? cout << tree[j] << endl : cout << tree[j] << " ";
			break;
		}
	}
}

void heapsort(vector<int>& tree, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		downAdjust(tree, i, n);
	for (i = n; i > 1; i--)
	{
		swap(tree[i], tree[1]);
		downAdjust(tree, 1, i - 1);
		if (tree == des)
		{
			flag = true;
			continue;
		}
		if (flag == true)
		{
			cout << "Heap Sort" << endl;
			for (int j = 1; j <= n; j++)
				j == n ? cout << tree[j] << endl : cout << tree[j] << " ";
			break;
		}
	}
}
void downAdjust(vector<int>& tree, int low, int high)
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