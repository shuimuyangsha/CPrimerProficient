#include<stdio.h>
main()
{
	char string[50];
	int i=0,letter=0,dig=0,spa=0,other=0;
	printf("������һ���ַ���:\n");
	gets(string);
	while(string[i]!='\0')
	{
		if(string[i]>='A'&&string[i]<='Z'||string[i]>='a'&&string[i]<='z')
			letter++;
		else if(string[i]==' ')
			spa++;
		else if(string[i]>='0'&&string[i]<='9')
			dig++;
		else
			other++;
		i++;
	}
	printf("�ַ���%d\n���֣�%d\n�ո�%d\n�����ַ���%d\n",letter,dig,spa,other);
}