
#define MIN(a, b) (a<b ? a:b)
#define MAX(a, b) (a>b ? a:b)

#ifndef __SWAP__
#define __SWAP__

template <class TYPE> void Swap (TYPE& a, TYPE& b)
{
	TYPE tmp = a;
	a = b;
	b = tmp;
}

#endif //__SWAP__

/*
El mateix codi per a C, sense referéncies amb punters
void SwapPunteros(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
*/

// serie de fibonachi en recursive
/*
int fibonacci_rec(int pos)
{
	if(pos == 0 || pos == 1)
		return 1;
	else
		return fibonacci_rec(pos-1) + fibonacci_rec(pos-2);
}
//01234
//11234
//serie de fibonachi en iterativo
int  fibonachi_iterative(uint pos)
{
	int n = 1;
	int prev = 0;

	for (uint i = 0; i < pos; ++i)
	{
		n += prev;
		prev = n - prev;
	}
	return n;
	
}

int fibonnachi_ofuscated(uint pos)
{
	uint n = 1;
	for (uint 1 = 0, p = 1; i < pos; ++i, n += p, p = n - p);
	return n;
}
*/

