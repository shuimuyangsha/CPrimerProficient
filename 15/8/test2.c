#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **pArray2;								/*��ά����ָ��*/
	int iIndex1,iIndex2;						/*ѭ�����Ʊ���*/
	pArray2=(int**)malloc(sizeof(int*[3]));		/*ָ��ָ���ָ��*/
	for(iIndex1=0;iIndex1<3;iIndex1++)
	{
		*(pArray2+iIndex1)=(int*)malloc(sizeof(int[3]));
		for(iIndex2=0;iIndex2<3;iIndex2++)
		{
			*(*(pArray2+iIndex1)+iIndex2)=iIndex1+iIndex2;
		}
	}

	//�����ά�����е��������ݡ�
	for(iIndex1=0;iIndex1<3;iIndex1++)
	{
		for(iIndex2=0;iIndex2<3;iIndex2++)
		{
			printf("%d\t",*(*(pArray2+iIndex1)+iIndex2));
		}
		printf("\n");
	}
	return 0;
}