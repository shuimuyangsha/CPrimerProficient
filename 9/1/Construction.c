#include<stdio.h>

void Move();	/*声明搬运函数*/
void Build();	/*声明建盖函数*/
void Paint();	/*声明粉刷函数*/

int main()
{
	Move();		/*执行搬运函数*/

	Build();	/*执行建盖函数*/

	Paint();	/*执行粉刷函数*/

	return 0;
}

/*//////////////////////////////////////////////////////////*/
/*						执行搬运功能						*/
/*//////////////////////////////////////////////////////////*/
void Move()
{
	printf("This Function can move material\n");
}
/*//////////////////////////////////////////////////////////*/
/*						执行建盖功能						*/
/*//////////////////////////////////////////////////////////*/
void Build()
{
	printf("This Function can build a building\n");
}
/*//////////////////////////////////////////////////////////*/
/*						执行粉刷功能						*/
/*//////////////////////////////////////////////////////////*/
void Paint()
{
	printf("This Function can paint cloth\n");
}