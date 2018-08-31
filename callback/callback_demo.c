#include <stdio.h>
#include "callback.h"

void SimulateCallbackDemo()
{
	PF_CALLBACK callbackPtr = NULL;
	Init(&callbackPtr);
	int choice;

	while(1)
	{
		printf("Enter Choice:-");
		scanf("%d", &choice);

		if( choice == 100 )
		{
			callbackPtr();
		}
	}
}

int main()
{
	SimulateCallbackDemo();
}
