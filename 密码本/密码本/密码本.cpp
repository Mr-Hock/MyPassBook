// 密码本.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define FILENAME "password.txt"//输出文件名称
#define SUANFA 10//加密算法，异或后再加减

#define WEBSEIT_SIZE 100
#define ACCOUNT_SIZE 32
#define PASSWORD_SIZE 32
#define MARK_SIZE 100

#define 录入信息 1
#define 修改信息 2
#define 删除信息 3
#define 查找信息 4
#define 显示所有信息 5
#define 退出 6

#include "myhead.h"

int g_num = 0;
int g_mem = 0;
PASSWORD *PPASWORD = NULL;

void Waiting()
{
	int num = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)break;
		else {puts("你的指令有误！"); puts("0.返回主菜单！");}
	}
}
int GetNumlen(int num)
{
	char temp[100];
	itoa(num, temp, 10);
	return strlen(temp);
}
void SetAccount(char *website, char *account,char *password,char *mark)
{
	PASSWORD *nPass = NULL;

	if (*account == NULL) return;

	if (g_num>= g_mem)
	{
		g_mem++;
		PPASWORD= (PASSWORD*) realloc(PPASWORD, sizeof(PASSWORD) * g_mem);
	}
	nPass = PPASWORD + g_num;

	strcpy_s(nPass->website, WEBSEIT_SIZE, website);
	strcpy_s(nPass->account, ACCOUNT_SIZE, account);
	strcpy_s(nPass->password, PASSWORD_SIZE, password);
	strcpy_s(nPass->mark, MARK_SIZE, mark);
	g_num++;

}
void DelAccount(int num)
{
	PASSWORD *nPass1 = NULL;
	PASSWORD *nPass2 = NULL;

	if (num > g_num-1)
		return;
/*
	else if (num == g_num - 1)
	{
		nPass1 = PPASWORD + num;

		strcpy(nPass1->account, "NULL");
		strcpy(nPass1->password, "NULL");
		strcpy(nPass1->beizhu, "NULL");
		g_num--;
		return;
	}*/


	for (int i = 0; i< g_num-num-1;i++)
	{
		nPass1 = PPASWORD + num+i;
		nPass2 = PPASWORD + num+i+1;

		strcpy(nPass1->website, nPass2->website);
		strcpy(nPass1->account, nPass2->account);
		strcpy(nPass1->password, nPass2->password);
		strcpy(nPass1->mark, nPass2->mark);
	}

	g_num--;

}
bool ChangeWebsite(int num, char *website)
{
	PASSWORD *nPass1 = NULL;
	if (num > g_num - 1)
		return false;
	nPass1 = PPASWORD + num;
	strcpy(nPass1->website, website);
	return true;
}
bool ChangeAccount(int num, char *account)
{
	PASSWORD *nPass1 = NULL;
	if (num > g_num - 1)
		return false;
	nPass1 = PPASWORD + num ;
	strcpy(nPass1->account, account);
	return true;
}
bool ChangePassword(int num, char *password)
{
	PASSWORD *nPass1 = NULL;
	if (num > g_num - 1)
		return false;
	nPass1 = PPASWORD + num;
	strcpy(nPass1->password, password);
	return true;
}
bool ChangeMark(int num, char *mark)
{
	PASSWORD *nPass1 = NULL;
	if (num > g_num - 1)
		return false;
	nPass1 = PPASWORD + num;
	strcpy(nPass1->mark, mark);
	return true;
}
void FindWebsite(char *website)
{
	PASSWORD *nPass = NULL;
	int i = 0,add=0;

	system("cls");

	if (g_num != 0)	puts("\n以下是关于这个网站的所有信息：\n------------------------------------------------------------");
	else puts("密码本内无任何数据！");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->website, website) != 0)
		{
			printf("%d: 网站:%s 帐号:%s 密码:%s 备注:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("没有查找到任何数据！\n------------------------------------------------------------");
}
void FindAccount(char *account)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n以下是关于这个帐号的所有信息：\n------------------------------------------------------------");
	else puts("密码本内无任何数据！");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->account,account)!=0)
		{
			printf("%d: 网站:%s 帐号:%s 密码:%s 备注:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("没有查找到任何数据！\n------------------------------------------------------------");
}
void FindPassword(char *password)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n以下是关于这个密码的所有信息：\n------------------------------------------------------------");
	else puts("密码本内无任何数据！");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->password, password) != 0)
		{
			printf("%d: 网站:%s 帐号:%s 密码:%s 备注:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("没有查找到任何数据！\n------------------------------------------------------------");
}
void FindMark(char *mark)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n以下是关于这个备注的所有信息：\n------------------------------------------------------------");
	else puts("密码本内无任何数据！");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->mark, mark) != 0)
		{
			printf("%d: 网站:%s 帐号:%s 密码:%s 备注:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}
	}
	if(add==0) puts("没有查找到任何数据！\n------------------------------------------------------------");
}
void JiamiData(bool jiami)
{
	FILE* PASSWORDFILE = NULL;

	int a = fopen_s(&PASSWORDFILE, FILENAME, "rb");
	if (a != 0)return;
	fseek(PASSWORDFILE, 0, SEEK_END);
	int seek = ftell(PASSWORDFILE);
	fseek(PASSWORDFILE, 0, SEEK_SET);
	char *p = (char*)malloc(seek);
	fread(p, 1, seek, PASSWORDFILE);
	fclose(PASSWORDFILE);


	for (int i = 0; i < seek; i++)
	{
		if (jiami == true) { *(p + i) += SUANFA; *(p + i) ^= SUANFA; }
		else { *(p + i) ^= SUANFA; *(p + i) -= SUANFA; }
	}

	fopen_s(&PASSWORDFILE, FILENAME, "wb");
	fwrite(p, seek, 1, PASSWORDFILE);
	fclose(PASSWORDFILE);
}
void SaveData()
{
	FILE* PASSWORDFILE = NULL;

	fopen_s(&PASSWORDFILE, FILENAME, "w");
	fprintf(PASSWORDFILE, "data_num %d |||", g_num);
	fclose(PASSWORDFILE);

	fopen_s(&PASSWORDFILE, FILENAME, "ab");
	fwrite(&*PPASWORD, sizeof(PASSWORD), g_num, PASSWORDFILE);
	fclose(PASSWORDFILE);

	JiamiData(true);

}
void OpenData()
{
	PASSWORD *pass = NULL;
	FILE* PASSWORDFILE = NULL;


	JiamiData(false);


	int a= fopen_s(&PASSWORDFILE, FILENAME, "rb");
	if (a != 0)return;
	fscanf_s(PASSWORDFILE, "data_num %d", &g_num);
	fclose(PASSWORDFILE);


	pass = (PASSWORD*)malloc(sizeof(PASSWORD) * g_num);
	int seek = strlen("data_num  |||") + GetNumlen(g_num);

	fopen_s(&PASSWORDFILE, FILENAME, "rb");
	fseek(PASSWORDFILE, seek, SEEK_SET);
	fread(&*pass, sizeof(PASSWORD), g_num, PASSWORDFILE);
	fclose(PASSWORDFILE);

	g_mem = g_num;
	PPASWORD=pass;
	//printf("%s\n", PPASWORD->beizhu);
}
void EnumAccount()
{
	PASSWORD *nPass = NULL;
	int i = 0;
	system("cls");

	if (g_num != 0)	puts("以下为所有密码本信息：\n------------------------------------------------------------");
	else puts("密码本内无任何数据！");
	for (; i < g_num; i++) 
	{
		
		nPass = PPASWORD + i;
		printf("%d: 网站:%s 帐号:%s 密码:%s 备注:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
		if (g_num != 0)	puts("------------------------------------------------------------");
	}

}
int main()
{
	int num = 0;
	bool jump = false;
	char website[WEBSEIT_SIZE];
	char account[ACCOUNT_SIZE];
	char password[PASSWORD_SIZE];
	char mark[MARK_SIZE];

	OpenData();
	SaveData();

	MessageBoxA(NULL, "欢迎使用Mr.Hock密码本！", "密码本", MB_OK + MB_ICONASTERISK);
	system("title 欢迎使用Mr.Hock密码本！");
	system("color 0a");

	while (1)
	{
		jump = false;
		num = 0;

		puts("欢迎使用Mr.Hock密码本！");
		puts("------------------------------------------------------------");
		puts("1.录入信息\n");
		puts("2.修改信息\n");
		puts("3.删除信息\n");
		puts("4.查找信息\n");
		puts("5.显示所有信息\n");
		puts("6.退出");
		puts("------------------------------------------------------------");

		scanf("%d",&num);
		switch (num)
		{
		case 录入信息:
		{
			system("cls");
			puts("请输入网站：");
			scanf("%s", website);
			puts("请输入新建的帐号：");
			scanf("%s", account);
			puts("请输入密码：");
			scanf("%s", password);
			puts("请输入备注：");
			scanf("%s", mark);
			SetAccount(website,account, password, mark);
			SaveData();
			puts("录入信息成功！");
			puts("0.返回主菜单");
			Waiting();
			break;
		}
		case 修改信息:
		{
			system("cls");

			while (1)
			{
				jump = false;
				num = 0;
				puts("请输入要修改的帐号顺序：");
				scanf("%d", &num);
				//if (num == 0) { jump = true; break; }
				if (num > g_num-1) { puts("输入的顺序大于帐号数量！"); continue;}
				break;
			}

			if (jump == true) { jump = false; break; }
			int account_temp = num;

			while (1)
			{
				jump = false;
				puts("请选择要修改信息：");
				puts("1.修改网站");
				puts("2.修改帐号");
				puts("3.修改密码");
				puts("4.修改备注");
				puts("0.返回主菜单");
				scanf("%d", &num);

				if (num == 0) { jump = true; break; }
				if (num > 4) { puts("你输入的指令有误！"); continue; }
				break;
			}

			if (jump == true) { jump = false; break; }

			switch (num)
			{
			case 1:
			{
				puts("请输入修改的网站：");
				scanf("%s", website);
				ChangeWebsite(account_temp, website);
				SaveData();
				puts("修改成功网站！");
				puts("0.返回主菜单");
				Waiting();
				jump = true;
				break;
			}
			case 2:
			{
				puts("请输入修改的帐号：");
				scanf("%s", account);
				ChangeAccount(account_temp, account);
				SaveData();
				puts("修改帐号成功！");
				puts("0.返回主菜单");
				Waiting();
				jump = true;
				break;
			}
			case 3:
			{
				puts("请输入修改的密码：");
				scanf("%s", password);
				ChangePassword(account_temp, password);
				SaveData();
				puts("修改密码成功！");
				puts("0.返回主菜单");
				Waiting();
				jump = true;
				break;
			}
			case 4:
			{
				puts("请输入修改的备注：");
				scanf("%s", mark);
				ChangeMark(account_temp, mark);
				SaveData();
				puts("修改备注成功！");
				puts("0.返回主菜单");
				Waiting();
				jump = true;
				break;
			}
			}

			if (jump == true) { jump = false; break; }


		}
		case 删除信息:
		{
			system("cls");
			while (1)
			{
				jump = false;
				puts("请输入要删除的帐号顺序：");
				scanf("%d", &num);
				//if (num == 0) { jump = true; break; }
				if (num > g_num-1) { puts("输入的顺序大于帐号数量！"); continue; }
				break;
			}

			if (jump == true) { jump = false; break; }
			int account_temp = num;

			DelAccount(account_temp);
			SaveData();
			puts("删除帐号成功！");
			puts("0.返回主菜单");

			Waiting();
			break;

		}
		case 查找信息:
		{
			system("cls");
			while (1)
			{
				jump = false;
				puts("请选择条件查找：");
				puts("1.根据网站查找");
				puts("2.根据帐号查找");
				puts("3.根据密码查找");
				puts("4.根据备注查找");
				puts("0.返回主菜单");
				scanf("%d", &num);
				if (num == 0) { jump = true; break; }
				if (num > 4) { puts("你输入的指令有误！"); continue; }
				break;
			}

			if (jump == true){jump = false; break; }

			switch (num)
			{
			case 1:
			{
				puts("请输入要查找的网站：");
				scanf("%s", website);
				FindWebsite(website);
				puts("按0返回主菜单！");
				Waiting();
				//jump = true;
				break;
			}
			case 2:
			{
				puts("请输入要查找的帐号：");
				scanf("%s", account);
				FindAccount(account);
				puts("按0返回主菜单！");
				Waiting();
				//jump = true;
				break;
			}
			case 3:
			{
				puts("请输入要查找的密码：");
				scanf("%s", password);
				FindPassword(password);
				puts("按0返回主菜单！");
				Waiting();
				//jump = true;
				break;
			}
			case 4:
			{
				puts("请输入要查找的备注：");
				scanf("%s", mark);
				FindMark(mark);
				puts("按0返回主菜单！");
				Waiting();
				//jump = true;
				break;
			}
			}

			jump == false; break;
		}
		case 显示所有信息:
		{
			EnumAccount();
			puts("0.返回主菜单");
			Waiting();
			break;
		}
		case 退出:
		{
			puts("已成功退出密码本。");
			jump = true;
			break;
		}
		default:
			puts("你的输入有误！请重新选择菜单。");
			break;
		}

		if (jump == true)break;
		system("cls");
	}
	system("pause");
    return 0;
}

