// ���뱾.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define FILENAME "password.txt"//����ļ�����
#define SUANFA 10//�����㷨�������ټӼ�

#define WEBSEIT_SIZE 100
#define ACCOUNT_SIZE 32
#define PASSWORD_SIZE 32
#define MARK_SIZE 100

#define ¼����Ϣ 1
#define �޸���Ϣ 2
#define ɾ����Ϣ 3
#define ������Ϣ 4
#define ��ʾ������Ϣ 5
#define �˳� 6

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
		else {puts("���ָ������"); puts("0.�������˵���");}
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

	if (g_num != 0)	puts("\n�����ǹ��������վ��������Ϣ��\n------------------------------------------------------------");
	else puts("���뱾�����κ����ݣ�");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->website, website) != 0)
		{
			printf("%d: ��վ:%s �ʺ�:%s ����:%s ��ע:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("û�в��ҵ��κ����ݣ�\n------------------------------------------------------------");
}
void FindAccount(char *account)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n�����ǹ�������ʺŵ�������Ϣ��\n------------------------------------------------------------");
	else puts("���뱾�����κ����ݣ�");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->account,account)!=0)
		{
			printf("%d: ��վ:%s �ʺ�:%s ����:%s ��ע:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("û�в��ҵ��κ����ݣ�\n------------------------------------------------------------");
}
void FindPassword(char *password)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n�����ǹ�����������������Ϣ��\n------------------------------------------------------------");
	else puts("���뱾�����κ����ݣ�");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->password, password) != 0)
		{
			printf("%d: ��վ:%s �ʺ�:%s ����:%s ��ע:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}


	}
	if (add == 0) puts("û�в��ҵ��κ����ݣ�\n------------------------------------------------------------");
}
void FindMark(char *mark)
{
	PASSWORD *nPass = NULL;
	int i = 0, add = 0;
	system("cls");

	if (g_num != 0)	puts("\n�����ǹ��������ע��������Ϣ��\n------------------------------------------------------------");
	else puts("���뱾�����κ����ݣ�");

	for (; i < g_num; i++)
	{
		nPass = PPASWORD + i;
		if (strstr(nPass->mark, mark) != 0)
		{
			printf("%d: ��վ:%s �ʺ�:%s ����:%s ��ע:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
			if (g_num != 0)	puts("------------------------------------------------------------");
			add++;
		}
	}
	if(add==0) puts("û�в��ҵ��κ����ݣ�\n------------------------------------------------------------");
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

	if (g_num != 0)	puts("����Ϊ�������뱾��Ϣ��\n------------------------------------------------------------");
	else puts("���뱾�����κ����ݣ�");
	for (; i < g_num; i++) 
	{
		
		nPass = PPASWORD + i;
		printf("%d: ��վ:%s �ʺ�:%s ����:%s ��ע:%s\n", i, nPass->website, nPass->account, nPass->password, nPass->mark);
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

	MessageBoxA(NULL, "��ӭʹ��Mr.Hock���뱾��", "���뱾", MB_OK + MB_ICONASTERISK);
	system("title ��ӭʹ��Mr.Hock���뱾��");
	system("color 0a");

	while (1)
	{
		jump = false;
		num = 0;

		puts("��ӭʹ��Mr.Hock���뱾��");
		puts("------------------------------------------------------------");
		puts("1.¼����Ϣ\n");
		puts("2.�޸���Ϣ\n");
		puts("3.ɾ����Ϣ\n");
		puts("4.������Ϣ\n");
		puts("5.��ʾ������Ϣ\n");
		puts("6.�˳�");
		puts("------------------------------------------------------------");

		scanf("%d",&num);
		switch (num)
		{
		case ¼����Ϣ:
		{
			system("cls");
			puts("��������վ��");
			scanf("%s", website);
			puts("�������½����ʺţ�");
			scanf("%s", account);
			puts("���������룺");
			scanf("%s", password);
			puts("�����뱸ע��");
			scanf("%s", mark);
			SetAccount(website,account, password, mark);
			SaveData();
			puts("¼����Ϣ�ɹ���");
			puts("0.�������˵�");
			Waiting();
			break;
		}
		case �޸���Ϣ:
		{
			system("cls");

			while (1)
			{
				jump = false;
				num = 0;
				puts("������Ҫ�޸ĵ��ʺ�˳��");
				scanf("%d", &num);
				//if (num == 0) { jump = true; break; }
				if (num > g_num-1) { puts("�����˳������ʺ�������"); continue;}
				break;
			}

			if (jump == true) { jump = false; break; }
			int account_temp = num;

			while (1)
			{
				jump = false;
				puts("��ѡ��Ҫ�޸���Ϣ��");
				puts("1.�޸���վ");
				puts("2.�޸��ʺ�");
				puts("3.�޸�����");
				puts("4.�޸ı�ע");
				puts("0.�������˵�");
				scanf("%d", &num);

				if (num == 0) { jump = true; break; }
				if (num > 4) { puts("�������ָ������"); continue; }
				break;
			}

			if (jump == true) { jump = false; break; }

			switch (num)
			{
			case 1:
			{
				puts("�������޸ĵ���վ��");
				scanf("%s", website);
				ChangeWebsite(account_temp, website);
				SaveData();
				puts("�޸ĳɹ���վ��");
				puts("0.�������˵�");
				Waiting();
				jump = true;
				break;
			}
			case 2:
			{
				puts("�������޸ĵ��ʺţ�");
				scanf("%s", account);
				ChangeAccount(account_temp, account);
				SaveData();
				puts("�޸��ʺųɹ���");
				puts("0.�������˵�");
				Waiting();
				jump = true;
				break;
			}
			case 3:
			{
				puts("�������޸ĵ����룺");
				scanf("%s", password);
				ChangePassword(account_temp, password);
				SaveData();
				puts("�޸�����ɹ���");
				puts("0.�������˵�");
				Waiting();
				jump = true;
				break;
			}
			case 4:
			{
				puts("�������޸ĵı�ע��");
				scanf("%s", mark);
				ChangeMark(account_temp, mark);
				SaveData();
				puts("�޸ı�ע�ɹ���");
				puts("0.�������˵�");
				Waiting();
				jump = true;
				break;
			}
			}

			if (jump == true) { jump = false; break; }


		}
		case ɾ����Ϣ:
		{
			system("cls");
			while (1)
			{
				jump = false;
				puts("������Ҫɾ�����ʺ�˳��");
				scanf("%d", &num);
				//if (num == 0) { jump = true; break; }
				if (num > g_num-1) { puts("�����˳������ʺ�������"); continue; }
				break;
			}

			if (jump == true) { jump = false; break; }
			int account_temp = num;

			DelAccount(account_temp);
			SaveData();
			puts("ɾ���ʺųɹ���");
			puts("0.�������˵�");

			Waiting();
			break;

		}
		case ������Ϣ:
		{
			system("cls");
			while (1)
			{
				jump = false;
				puts("��ѡ���������ң�");
				puts("1.������վ����");
				puts("2.�����ʺŲ���");
				puts("3.�����������");
				puts("4.���ݱ�ע����");
				puts("0.�������˵�");
				scanf("%d", &num);
				if (num == 0) { jump = true; break; }
				if (num > 4) { puts("�������ָ������"); continue; }
				break;
			}

			if (jump == true){jump = false; break; }

			switch (num)
			{
			case 1:
			{
				puts("������Ҫ���ҵ���վ��");
				scanf("%s", website);
				FindWebsite(website);
				puts("��0�������˵���");
				Waiting();
				//jump = true;
				break;
			}
			case 2:
			{
				puts("������Ҫ���ҵ��ʺţ�");
				scanf("%s", account);
				FindAccount(account);
				puts("��0�������˵���");
				Waiting();
				//jump = true;
				break;
			}
			case 3:
			{
				puts("������Ҫ���ҵ����룺");
				scanf("%s", password);
				FindPassword(password);
				puts("��0�������˵���");
				Waiting();
				//jump = true;
				break;
			}
			case 4:
			{
				puts("������Ҫ���ҵı�ע��");
				scanf("%s", mark);
				FindMark(mark);
				puts("��0�������˵���");
				Waiting();
				//jump = true;
				break;
			}
			}

			jump == false; break;
		}
		case ��ʾ������Ϣ:
		{
			EnumAccount();
			puts("0.�������˵�");
			Waiting();
			break;
		}
		case �˳�:
		{
			puts("�ѳɹ��˳����뱾��");
			jump = true;
			break;
		}
		default:
			puts("�����������������ѡ��˵���");
			break;
		}

		if (jump == true)break;
		system("cls");
	}
	system("pause");
    return 0;
}

