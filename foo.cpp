#include "foo.h"
#include <iostream>
#include <ctime>

void RandomArr(int *arr, int n, int d) {
	std::srand(time(0));
	for (int i = 0; i < n; ++i)
		arr[i] = std::rand() % d;
}
void PrintArr(int *arr, int n) {
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int Max(int *a, int n){
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int majorbit(int a)
{
	int flag = 31;
	UI mask = 1;
	int n = 0;
	mask <<= 31;
	while ((mask & a) == 0)
	{
		flag--;  
		mask >>= 1;
		n = flag;
	}
	return n;
}
void Swap(int &a, int &b){
	int c;
	c = a;
	a = b;
	b = c;
}
void ByteSort(int *a, int n, int l, int r, int k){
	if ((l >= r) || (k < 0)) return;
	else
	{
		int i = l;
		int j = r;
		int mask = 1;
		mask <<= k;
		while (i < j)
		{
			while ((i < j) && ((a[i] & mask) == 0))
				i++;
			while ((i < j) && ((a[j] & mask) != 0))
				j--;
			if (i < j) Swap(a[i], a[j]);
		}
		if ((a[r] & mask) == 0) j++;
		if (l < j) ByteSort(a, n, l, j - 1, k - 1);
		if (i < r) ByteSort(a, n, i, r, k - 1);
	}
}