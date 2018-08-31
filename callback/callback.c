
#include "callback.h"
void Callback()
{
	printf("Invoking Callback Function\n");
}

void Init(PF_CALLBACK *ptr)
{
	*ptr = Callback;
}

