#include<stdio.h>

void  Evaluate(int iArrayName[]);				/*��������������Ϊ�ɱ䳤������*/
void  Display(int iArrayName[]);				/*��������������Ϊ�ɱ䳤������*/

int main()
{
	int iArray[10];							/*����һ������10��Ԫ�ص���������*/

	Evaluate(iArray);						/*���ú������и�ֵ����������������Ϊ����*/
	Display(iArray);						/*���ú������и�ֵ����������������Ϊ����*/
	return 0;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*						����Ԫ�ص���ʾ						*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void  Display(int iArrayName[])					/*���庯��������Ϊ�ɱ䳤������*/
{
	int i;									/*�������ͱ���*/
	for(i=0;i<10;i++)						/*ִ��ѭ�������*/
	{									/*��ѭ�������ִ���������*/
		printf("the member number is %d\n",iArrayName[i]);
	}
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*						��������Ԫ�صĸ�ֵ						*/
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void  Evaluate(int iArrayName[])				/*���庯��������Ϊ�ɱ䳤������*/
{
	int i;									/*�������ͱ���*/
	for(i=0;i<10;i++)						/*ִ��ѭ�����*/
	{									/*��ѭ�������ִ�и�ֵ����*/
		iArrayName[i]=i;
	}
}