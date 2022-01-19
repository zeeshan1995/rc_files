
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
	FILE * f = fopen("info.txt","r");
	char * s = (char*)malloc(100);;
//	s = "hello";
//
	rewind(f);
	while(fscanf(f,"%s",s))
	{
		printf("%s %d ",s ,ftell(f));
		fseek(f,strlen(s),SEEK_SET);
		printf("%s %d ",s ,strlen(s));
	//	if(feof(f))
			break;
	}
	
	int x = fscanf(f,"%s",s);
	printf("%d",x);
}
