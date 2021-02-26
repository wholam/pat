#include<iostream>
using namespace std;

int main() {
	int N, M;
	int total = 0;
	cin >> N;
	int* dist = new int[N+1];
	int i, j, tmp;
	dist[1] = 0;
	for (i = 2; i <= N; i++) {
		cin >> tmp;
		total += tmp;
		dist[i] = dist[i - 1] + tmp;
	}
	cin >> tmp;
	total += tmp;
	cin >> M;
	int* output = new int[M];
	int a, b;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		output[i] = abs(dist[a] - dist[b]);
		if ((total - output[i]) < output[i])
			output[i] = total - output[i];
	}
	for (i = 0; i < M; i++)
		cout << output[i] << endl;
	return 0;
}