#include<stdio.h>
#include<process.h>
main()
{
	FILE *fp;
	char ch,filename[50];
	printf("please input filename:\n");
	scanf("%s",filename);							/*�����ļ���*/
	if((fp=fopen(filename,"r"))==NULL) 				/*��ֻ����ʽ�򿪸��ļ�*/
	{
		printf("cannot open this file.\n");
		exit(0);
	}
	ch = fgetc(fp);				
	while (ch != EOF)				
	{
		putchar(ch);								/*����ַ�*/
		ch = fgetc(fp); 							/*��ȡfpָ���ļ��е��ַ�*/
	}
	rewind(fp); 									/*ָ��ָ���ļ���ͷ*/
	ch = fgetc(fp);					
	while (ch != EOF)					
	{
		putchar(ch); 								/*����ַ�*/
		ch = fgetc(fp);			
	}
	fclose(fp); 									/*�ر��ļ�*/
}