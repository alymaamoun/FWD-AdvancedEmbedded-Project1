#include "ApplicationLogic.h"


int main(void)
{
	AppDriversInit();
	while(1)
	{
		AppLogic();
	}
}