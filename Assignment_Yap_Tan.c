#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


int main()
{

FILE *fp;
int i=1;
char returnData[64];
char * ip;

fp = popen("/sbin/ifconfig eth0", "r");

while (fgets(returnData, 64, fp) != NULL)
{
	if(i == 2)
	{
		ip = strtok(returnData," ");
		break;
	}
	i++;
}

if(ip!=NULL)
{
	printf("%s ", ip);
	ip = strtok(NULL,"B");
	printf("%s\n", ip);	
}

pclose(fp);
return 0;
}
