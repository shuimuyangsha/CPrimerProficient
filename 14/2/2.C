#include <stdio.h>
main()
{
    FILE *fp;						/*����һ��ָ��FILE���ͽṹ���ָ�����*/
    char ch;						/*�������������Ϊ�ַ���*/
    fp = fopen("e:\\exp02.txt", "r");		/*��ֻ����ʽ��ָ���ļ�*/
    ch = fgetc(fp);					/*fgetc��������һ���ַ�����ch*/
    while (ch != EOF)				/*��������ַ�ֵ����EOFʱ����ѭ��*/
    {
        putchar(ch);				/*��������ַ��������Ļ��*/
        ch = fgetc(fp);				/*fgetc������������һ���ַ�����ch*/
    }
    fclose(fp);						/*�ر��ļ�*/
}