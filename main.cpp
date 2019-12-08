#include <iostream>
#include "foo.h"
const int N = 20;
int main(){
	using namespace std;
	int *a = new int[N];
	RandomArr(a, 20, 20);
	PrintArr(a, N);
	int max = Max(a, N);
	int k = majorbit(max);
	ByteSort(a, N, 0, N - 1, k);
	PrintArr(a, N);
	cin.get();
	return 0;
}