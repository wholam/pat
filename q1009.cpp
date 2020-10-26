#include<iostream>	
#include<iomanip>
using namespace std;

struct node
{
	int e;
	double c;
	struct node* next;
};
typedef struct node node;
int main()
{
	int K1, K2;//ÏîÊý
	node* h1, * h2;
	h1 = new node;
	h2 = new node;
	h1->next = NULL;
	h2->next = NULL;
	node* p,*q,*r,*prev,*next;
	int e;
	double c;
	cin >> K1;
	p = h1;
	int i;
	for (i = 0; i < K1; i++)
	{
		cin >> e >> c;
		q = new node;
		q->e = e;
		q->c = c;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	int count = 0;
	int flag = 1;
	cin >> K2;
	for (i = 0; i < K2; i++)
	{
		cin >> e >> c;
		q = h1->next;
		while (q != NULL)
		{
			r = new node;
			r->e = e + q->e;
			r->c = c * q->c;
			r->next = NULL;
			prev = h2;
			next = h2->next;
			flag = 1;
			while (next != NULL)
			{
				if (next->e == r->e)
				{
					next->c += r->c;
					if (next->c == 0)
					{
						prev->next = next->next;
						next = prev->next;
						count--;
						flag = 0;
					}
					break;
				}
				if (r->e < next->e)
				{
					prev = next;
					next = next->next;
				}
				else
				{
					r->next = next;
					prev->next = r;
					count++;
					break;
				}
			}
			if (next == NULL&&flag==1)
			{
				prev->next = r;
				count++;
			}
			q = q->next;
		}
	}
	if (count == 0)
		cout << count;
	else
		cout << count << " ";
	p = h2->next;
	cout <<setiosflags(ios::fixed)<<setprecision(1);
	while (p != NULL)
	{
		if (p->next == NULL)
			cout << p->e << " " << p->c;
		else
			cout << p->e << " " << p->c << " ";
		p = p->next;
	}
	return 0;
}