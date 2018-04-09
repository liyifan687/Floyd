#include<stdio.h>
#include<string.h>
#include <cstdlib>
#define Num 16//地点数 
#define Maxedge 32767//极大值 
typedef struct
{
	char name[10];//名称 
	int number;//编号 
	char introduce[100];//简介 
}vertex;
vertex ver[Num];//定点信息 
int edge[Num][Num];//边长 
int shortest[Num][Num];//最短距离 
int path[Num][Num];//前趋节点 
void init();//初始化 
void map();//地图 
void menu();//菜单 
void shortestpath();
void informatation();
int main()
{
	init();
	map();
	menu();
}
void init()//初始化信息 
{
	char i,j;
	ver[1].number=1;
	strcpy(ver[1].name,"大门");
	strcpy(ver[1].introduce,"正门\n");
	ver[2].number=2;
	strcpy(ver[2].name,"图书馆");
	strcpy(ver[2].introduce,"图书馆");
	ver[3].number=3;
	strcpy(ver[3].name,"操场");
	strcpy(ver[3].introduce,"老校区操场");
	ver[4].number=4;
	strcpy(ver[4].name,"6号宿舍");
	strcpy(ver[4].introduce,"老校区男生宿舍区");
	ver[5].number=5;
	strcpy(ver[5].name,"小礼堂");
	strcpy(ver[5].introduce,"晚会活动的举办场地");
	ver[6].number=6;
	strcpy(ver[6].name,"下沉广场");
	strcpy(ver[6].introduce,"老校区下沉环形广场");
	ver[7].number=7;
	strcpy(ver[7].name,"学苑餐厅");
	strcpy(ver[7].introduce,"老校区餐厅");
	ver[8].number=8;
	strcpy(ver[8].name,"专家公寓");
	strcpy(ver[8].introduce,"外教公寓");
	ver[9].number=9;
	strcpy(ver[9].name,"教工3村");
	strcpy(ver[9].introduce,"教职工住址");
	ver[10].number=10;
	strcpy(ver[10].name,"荷花池");
	strcpy(ver[10].introduce,"小景点");
	ver[11].number=11;
	strcpy(ver[11].name,"9号教学楼");
	strcpy(ver[11].introduce,"文法学院教学楼");
	ver[12].number=12;
	strcpy(ver[12].name,"12号教学楼");
	strcpy(ver[12].introduce,"音乐学院教学楼");
	ver[13].number=13;
	strcpy(ver[13].name,"15号教学楼");
	strcpy(ver[13].introduce,"软件学院教学楼");
	ver[14].number=14;
	strcpy(ver[14].name,"学生广场");
	strcpy(ver[14].introduce,"活动广场");
	ver[15].number=15;
	strcpy(ver[15].name,"网球场");
	strcpy(ver[15].introduce,"新校区操场");
	ver[16].number=16;
	strcpy(ver[16].name,"东南餐厅");
	strcpy(ver[16].introduce,"新校区餐厅");
	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Num;j++)
		{
			edge[i][j]=Maxedge;
		}
	}
	for(i=1;i<=Num;i++)//边长 
	{
		edge[i][j]=0;
	}
	edge[1][2]=edge[2][1]=60;
	edge[1][3]=edge[3][1]=90;
	edge[1][4]=edge[4][1]=100;
	edge[2][3]=edge[3][2]=20;
	edge[2][4]=edge[4][2]=20;
	edge[2][5]=edge[5][2]=40;
	edge[3][5]=edge[5][3]=65;
	edge[3][9]=edge[9][3]=250;
	edge[4][6]=edge[6][4]=80;
	edge[5][6]=edge[6][5]=55;
	edge[6][7]=edge[7][6]=50;
	edge[6][8]=edge[8][6]=100;
	edge[7][8]=edge[8][7]=130;
	edge[8][9]=edge[9][8]=150;
	edge[9][10]=edge[10][9]=100;
	edge[10][11]=edge[11][10]=40;
	edge[10][12]=edge[12][10]=60;
	edge[11][12]=edge[12][11]=30;
	edge[11][14]=edge[14][11]=75;
	edge[12][13]=edge[13][12]=50;
	edge[12][14]=edge[14][12]=15;
	edge[13][14]=edge[14][13]=45;
	edge[13][15]=edge[15][13]=160;
	edge[14][15]=edge[15][14]=100;
	edge[15][16]=edge[16][15]=120;	
}
void map()
{
	printf("\t\t平面图");
	printf("\n\n东南餐厅（16）\n");
	printf("---网球场（15）-----学生广场（14）\n");
	printf("------ 15号教学楼（13）-----12号教学楼（12）----9号教学楼（11）\n");
	printf("--------------------------------------荷花池（10）\n");
	printf("----------------------------------------教工3村（9）--------------专家公寓（8）\n");
	printf("-------------------------------------------------------------------------------下沉广场（6）----------学苑餐厅（7）\n");
	printf("-----------------------------------------------------------------------------------------小礼堂（5）\n");
	printf("-----------------------------------------操场（3）---------------图书馆（2）--------------------6号宿舍（4）\n");
	printf("-----------------------------------------------------------------大门（1）\n");
}
void menu()
{	
	while(1)
	{
	char i;
	printf("\t\t\t欢迎使用导航系统\n\n");
	printf("输入“c”以查询最短路径\n");
	printf("输入“x”以查询信息\n");
	printf("输入“e”以退出程序\n");
	printf("请输入对应的英文小写字母，谢谢：\n\t");
    scanf("%s",&i);
		switch(i)
		{
			case'c':shortestpath();break;//查询最短路径 
			case'x':informatation();break;//信息 
			case'e':printf("\n\n\n\t\t\t 谢谢使用！\n ");
		    exit(0);break;
			default:printf("输入错误\n ");break;
		}
	}
	
}
void informatation()//查询信息 
{
	int i;
	while(1)
	{
		printf("请输入查询地点的编号：\n\t");
		scanf("%d",&i);
		if(i<=Num&&i>=1)
		{
			printf("\n名称：%s\n简介：%s\n\n",ver[i].name,ver[i].introduce);
			return;
		}
		else
		{
			printf("输入有误！请重新输入！");
		}
	}
}
void floyd()//弗洛伊德算法实现 
{
	int i=1,j=1,k=1;
	for(i=1;i<=Num;i++)
	{
		for(j=1;j<=Num;j++)
		{
			shortest[i][j]=edge[i][j];
			if(shortest[i][j]<Maxedge)
			path[i][j]=i;//有弧，置i 
			else 
			path[i][j]=-1;//i,j之间无弧，将j的前趋置-1 
		}
	}
	for(k=1;k<=Num;k++)
	{                                                                                                                              
		for(i=1;i<=Num;i++)
		{
			for(j=1;j<=Num;j++)
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))
				{
					shortest[i][j]=(shortest[i][k]+shortest[k][j]);//更新最短路径 
					path[i][j]=path[k][j];
				}
			}
		}
	}
}
void way(int i,int j)//路线 
{
	int k=0,a=i,b=j;
	if(shortest[i][j]!=Maxedge)
	{
		printf("\n从%s到%s的最短路径为：\n",ver[i].name,ver[j].name);
		printf("%s",ver[i].name);
		while(path[i][j]!=i)
		{
			k=path[i][j];
			while(path[i][k]!=i)//一直索引前趋，从i的第一个下节点输出 
			{
				k=path[i][k];
			}
			printf("-到-%s",ver[k].name);
			i=k;//更新i,再求【k,j】的前趋 
		}
		printf("-到—%s\n",ver[b].name);
		printf("\n最短距离为：%d米。\n",shortest[a][b]);
	}
	else
	{
		printf("从%s不能到达%s\n\n",ver[i].name,ver[j].name);
	}
}
void shortestpath()//最短距离 
{
	int i=0,j=0;
	while(1)
	{
		printf("请输入要查询的两点的编号：");
		scanf("%d%d",&i,&j);
		if(i<=Num&&i>0&&j<=Num&&j>0)
		{
			floyd();
			way(i,j);
			return ;
		}
	}
}
