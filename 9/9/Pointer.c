#include<stdio.h>

void  Evaluate(int* pPoint);				/*��������������Ϊ�ɱ䳤������*/
void  Display(int* pPoint);				/*��������������Ϊ�ɱ䳤������*/

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
void  Display(int* pPoint)					/*���庯��������Ϊ�ɱ䳤������*/
{
	int i;									/*�������ͱ���*/
	for(i=0;i<10;i++)						/*ִ��ѭ�������*/
	{									/*��ѭ�������ִ���������*/
		printf("the member number is %d\n",pPoint[i]);
	}
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*						��������Ԫ�صĸ�ֵ						*/
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void  Evaluate(int* pPoint)				/*���庯��������Ϊ�ɱ䳤������*/
{
	int i;									/*�������ͱ���*/
	for(i=0;i<10;i++)						/*ִ��ѭ�����*/
	{									/*��ѭ�������ִ�и�ֵ����*/
		pPoint[i]=i;
	}
}