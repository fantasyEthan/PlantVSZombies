#include"Random.h"

vector<int> Random(int start, int end, int num)
{
	vector<int> res(num);
	srand((int)time(0));
	for (int i = 0; i < num; ++i)
	{
		res[i] = rand() % (end - start) + start;
	}
	return res;
}
