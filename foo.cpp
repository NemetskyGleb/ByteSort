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
void ByteSort(int *a, int n, int L, int R, int k){
	if (L >= R || k < 0) return;
	int i = L, j = R;
	UI mask = 1;
	mask <<= k;
	do {
		while (i <= j && (a[i] & mask))
			i++;
		while (i <= j && !(a[j] & mask))
			j--;
		if (i < j) {
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	ByteSort(a, n, L, j, k - 1);
	ByteSort(a, n, i, R, k - 1);
}