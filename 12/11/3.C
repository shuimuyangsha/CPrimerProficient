#include <stdio.h>
left(unsigned value, int n)									/*�Զ������ƺ���*/
{
    unsigned z;
    z = (value >> (32-n)) | (value << n);						/*ѭ�����Ƶ�ʵ�ֹ���*/
    return z;
} 
right(unsigned value, int n)									/*�Զ������ƺ���*/
{
    unsigned z;
    z = (value << (32-n)) | (value >> n);						/*ѭ�����Ƶ�ʵ�ֹ���*/
    return z;
} 

main()
{
    unsigned a;
    int n;
    printf("please input a number:\n");
    scanf("%o", &a);										/*����һ���˽�����*/
    printf("please input the number of displacement��>0��:\n");
    scanf("%d", &n);									/*����Ҫ��λ��λ��*/
    printf("the result is %o:\n", left(a, n));					/*�����ƺ�Ľ�����*/
    printf("the result is %o:\n", right(a, n));					/*�����ƺ�Ľ�����*/
}