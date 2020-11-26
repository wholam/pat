#include<iostream>
#include<string>
#include<map>
#include<iterator>

using namespace std;

int main()
{
	string request, offer;
	cin >> offer >> request;
	map<char, int> mp_r, mp_o,mp_n;
	int i;
	for (i = 0; i < offer.size(); i++)
		mp_o[offer[i]] += 1;
	for (i = 0; i < request.size(); i++)
		mp_r[request[i]] += 1;
	for (i = 0; i < request.size(); i++)
		mp_n[request[i]] = mp_o[request[i]] - mp_r[request[i]];
	bool flag = 0;
	int need = 0;
	map<char, int>::iterator it;
	for (it = mp_n.begin(); it != mp_n.end(); it++)
	{
		if (it->second < 0)
		{
			flag = 1;
			need += abs(it->second);
		}
	}
	if (flag == 0)
		cout << "Yes " << offer.size() - request.size() << endl;
	else
		cout << "No " << need << endl;
	return 0;
}