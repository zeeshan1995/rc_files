

#include <stdio.h>
#include "../cvector.h"

int main()
{
	cvector v = create_vector(10);
	push_back(v, 100);
	push_back(v, 101);
	push_back(v, 102);
	print(v);
}
