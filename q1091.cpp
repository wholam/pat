#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct node
{
	int x, y, z;
}node;

int xz[6] = {0, 0, -1, 1, 0, 0};
int yz[6] = {-1, 1, 0, 0, 0, 0};
int zz[6] = { 0, 0, 0, 0, -1, 1 };

int main()
{
	int M, N, L, T;
	cin >> M >> N >> L >> T;
	vector<vector<int>> slice;
	vector<vector<vector<int>>> slices;
	vector<vector<vector<bool>>> isvisited;
	vector<int> tmp;
	vector<bool> tmp1;
	vector<vector<bool>> tmp4;
	int a;
	int i, j, k, m;
	queue<node> q;
	node tmp2, tmp3;

	for (k = 0; k < N; k++)
		tmp1.push_back(false);
	for (k = 0; k < M; k++)
		tmp4.push_back(tmp1);
	for (j = 0; j < L; j++)
		isvisited.push_back(tmp4);

	int ans = 0;
	int sum = 0;
	for (i = 0; i < L; i++)
	{
		slice.clear();
		for (j = 0; j < M; j++)
		{
			tmp.clear();
			for (k = 0; k < N; k++)
			{
				cin >> a;
				tmp.push_back(a);
			}
			slice.push_back(tmp);
		}
		slices.push_back(slice);
	}
	for(int z=0;z<L;z++)
		for(j = 0;j<M;j++)
			for (k = 0; k < N; k++)
			{
				if (slices[z][j][k] == 1 && isvisited[z][j][k] == false)
				{
					sum = 0;
					tmp2.x = j;
					tmp2.y = k;
					tmp2.z = z;
					q.push(tmp2);
					isvisited[z][j][k] = true;
					sum++;
					while (!q.empty())
					{
						tmp2 = q.front();
						q.pop();
						for (m = 0; m < 6; m++)
						{
							tmp3.x = tmp2.x + xz[m];
							tmp3.y = tmp2.y + yz[m];
							tmp3.z = tmp2.z + zz[m];
							if (tmp3.x >= 0 && tmp3.x < M && tmp3.y >= 0 && tmp3.y < N && tmp3.z>=0 && tmp3.z < L && slices[tmp3.z][tmp3.x][tmp3.y] == 1 && isvisited[tmp3.z][tmp3.x][tmp3.y] == false)
							{
								isvisited[tmp3.z][tmp3.x][tmp3.y] = true;
								q.push(tmp3);
								sum++;
							}
						}
					}
					if (sum >= T)
						ans += sum;
				}
			}
	cout << ans << endl;
	return 0;
}