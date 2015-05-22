
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