#include<stdio.h>



int main()
{
int arrayfind[10] = {0, 0, 0, 1, 2, 1, 1,  1};
int numberpass = -9999999;
int counter = 0;
int freq = 0;
int freqnum = 0;

	for (int i = 0; i<8; ++i)
	{
		
		if (numberpass != arrayfind[i])
		{
			for (int j=0; j<=8; ++j)
				if (j != i)
					if (arrayfind[j] == arrayfind[i])
					counter = counter + 1;
			
			numberpass = arrayfind[i];
			if (freq <= counter)
				freq = counter;
				freqnum = arrayfind[i];
		}
	}
	
	printf("The mode is %d \n", freqnum);
	
return 0;

}
