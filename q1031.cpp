#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	char output[1000];
	cin >> str;
	int i, j,index;
	int n1, n2, n3;
	for (n2 = 3; n2 <= str.length(); n2++) {
		if ((str.length() + 2 - n2) % 2 == 0) {
			n1 = (str.length() + 2 - n2) / 2;
			n3 = n1;
			if (n1 <= n2)
				break;
		}
	}
	index = 0;
	for (i = 0; i < n1; i++) {
		if (i == n1 - 1) {
			for (j = n1 - 1; j < (n1 + n2 - 1); j++)
				output[index++] = str[j];
		}
		else {
			output[index++] = str[i];
			for (j = 0; j < n2 - 2; j++)
				output[index++] = ' ';
			output[index++] = str[str.length()-1-i];
		}
		output[index++] = '\n';
	}
	output[index] = '\0';
	cout << output;
	return 0;
}