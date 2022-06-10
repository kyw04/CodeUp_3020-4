#include <iostream>
#include <vector>
#define N 100000
using namespace std;

typedef struct Data
{
	Data* next;
	int index;
	int number;
};
Data memo[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;

	cin >> n;
	for (int i = 1; i < n + 1; i++)
	{
		int input, index;
		cin >> input;
		index = input % N;
		Data* newData = new Data;
		Data* temp = &memo[index];
		while (temp->next)
		{
			temp = temp->next;
		}
		newData->next = NULL;
		newData->index = i;
		newData->number = input;
		temp->next = newData;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input, index;
		cin >> input;
		index = input % N;
		Data* temp = &memo[index];
		while (temp->next && temp->number != input)
		{
			temp = temp->next;
		}
		if (temp->number == input)
			cout << temp->index << ' ';
		else
			cout << "-1 ";
	}

	return 0;
}