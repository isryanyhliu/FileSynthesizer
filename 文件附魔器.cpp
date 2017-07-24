#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define V "2.4"

///////////////////////////////////////////////////////////////////全局变量 
int n = 0;

//////////////////////////////////////////////////////////////////// 
struct user
{
	char number[20];
	char passcode[20];
}
user[50];
////////////////////////////////////////////////////////////////////

void product_description();
void operating_instruction();
void warning();
void judgement();
void fileopen();
void filesave();
void core_system();
void login();
void regist();
void request();
void over();

///////////////////////////////////////////////////////////////// 
int main(void)
{ 
	system("color F0");
	
	fileopen();
	product_description();
	
	return 0;
}

/////////////////////////////////////////////文件新建，读取程序 
void fileopen()
{
	FILE *fp;
	int i;
	
	if ((fp = fopen("data", "at+")) == NULL)
	{
		fp = fopen("data", "at+");
	}
	
	for (i = 0; i < 50; i++)
	{
		fread(&user[i], sizeof(struct user), 1, fp);
	}
	fread(&n, 4, 1, fp);
	
	fclose(fp);
	
	system("attrib +h data");
}



/////////////////////////////////////////////文件保存程序 
void filesave()
{
	FILE *fp;
	int i;
	
	fp = fopen("data", "at+");
	for (i = 0; i <= 50; i++)
	{
		fwrite(&user[i], sizeof(struct user), 1, fp);
	}
	fwrite(&n, 4, 1, fp);
	
	fclose(fp);
	
	system("attrib +h data");
}




////////////////////////////////////////////产品介绍（界面） 
void product_description()
{
	system("cls");
	
	printf("   _______________________________________\n");
	printf("   |                                      |\n");
	printf("   |          欢迎使用文件附魔器！        |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |          制作人员：  刘永蘅          |\n");
	printf("   |                                      |\n");
	printf("   |          程序版本：  v%s            |\n", V);
	printf("   |______________________________________|\n");
	system("pause");
	
	operating_instruction();
}




///////////////////////////////////////////////操作说明 （界面） 
void operating_instruction()
{
	system("cls");
	
	printf("   ________________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |               程序说明               |\n");
	printf("   |                                      |\n");
	printf("   |该程序用于 将两个文件 进行合并        |\n");
	printf("   |即将两个文件内容 包含到一个新文件之中 |\n");
	printf("   |                例如                  |\n");
	printf("   |                                      |\n");
	printf("   |将一个   docx   和一个   jpg 文件合并 |\n");
	printf("   |          生成另外一个文件            |\n");
	printf("   |         可以依然是一张图片           |\n");
	printf("   |但如果将图片的拓展名 jpg 改为 docx    |\n");
	printf("   |便可以阅览图片中 隐藏的文档了         |\n");
	printf("   |______________________________________|\n");	
	
	system("pause");
	
	warning();
}


void warning()
{
	system("cls");
	
	printf("   _______________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |                WARNING               |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |      ******请先将这两个文件******    |\n");
	printf("   |                                      |\n");
	printf("   |      ******放到当前文件夹内******    |\n");
	printf("   |                                      |\n");
	printf("   |      ******请将文件做好备份******    |\n");
	printf("   |                                      |\n");
	printf("   |______________________________________|\n"); 
	
	system("pause");
	
	judgement();
}




////////////////////////////////////////////判断模块（判断是否为已注册用户） 
void judgement()
{
	system("cls");
	
	printf("   _______________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |                请选择                |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |         我已注册过——请按 0         |\n");
	printf("   |                                      |\n");
	printf("   |         我是新用户——请按 1         |\n"); 
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |______________________________________|\n");
	
	
	int flag = 1;
	while(flag)
	{
		switch(getch())
		{
			case '0':
				flag = 0;
				login();
				break;
				
			case '1': 
				flag = 0;
				regist();
				break; 
			
			default : 
				printf("\n   _______________________________________\n");
                printf("   |                                      |\n");			
			    printf("   |        彪啊，只能按 0 或者 1 !       |\n");
			    printf("   |______________________________________|\n");
		}
	}
}



/////////////////////////////////////////////获取验证码 （界面） 
void request()
{
	system("cls");
	
	printf("   _______________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |             请输入验证码             |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |         (验证码获取方法如下)         |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |      请加QQ号： 1014  2406  58       |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |        并向其发一个 大大 的红包      |\n");
	printf("   |            即可获得验证码            |\n");
	printf("   |______________________________________|\n");
}



//////////////////////////////////////////////////注册模块 
void regist()
{	
	char identifying_code[4] = {"\0"};//输入的验证码 
	char ch[] = "1017";//正确的验证码 
	
	char a = '\0';
	char b = '\0';
	char mima[20] = {'\0'};
	char c[20] = {'\0'};
	char d[20] = {'\0'};
	int i = 0;
	int j = 0;

	system("cls");
	
	request();
	
	printf("\n\n");
	
	printf("                  验证码: ");
	scanf("%s", &identifying_code);
	fflush(stdin);
	
	printf("\n                  正在验证..");
	Sleep(500);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(100);
	printf(".");
	Sleep(100);
	printf(".\n");
	
	
	
	if ( strcmp ( identifying_code, ch ) != 0 )
	{
		printf("     	          验证码错误！\n\n");
		printf("   _______________________________________\n\n");
		
		system("pause");
		regist();
	}
	
	else
	{
		printf("\n                  验证成功\n\n");
		printf("   _______________________________________\n\n");
		
		system("pause");
		system("cls");
		
			printf("   ________________________________________\n");
			printf("   |              文件附魔器              |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |           欢迎来到注册界面！         |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                                      |\n");
			printf("   |                     --by刘永蘅  V%s |\n", V);
			printf("   |______________________________________|\n\n");
		
		printf("              请输入学号: ");
		scanf("%s", &user[n].number);
		fflush(stdin);
		
		printf("\n");
		printf(" 请输入密码（字母/数字）: ");
		
		while((a = getch()) != '\n')
		{
			if(a == '\b')
			{
				c[i - 1] = NULL;
				
				putchar('\b');
				putchar(' ');
				putchar('\b');
				
				i--;
			}
			
			else if(isalpha(a) || isdigit(a))
			{
				printf("*");
				
				c[i++] = a;
			}
			
			else
			{
				break;
			}
		}
		fflush(stdin);
		
		printf("\n\n");
		printf("    	  请再次输入密码: ");
		
		while((b = getch()) != '\n')
		{
			if(b == '\b')
			{
				d[j - 1] = NULL;
				
				putchar('\b');
				putchar(' ');
				putchar('\b');
				
				j--;
			}	
	
			else if(isalpha(b) || isdigit(b))
			{
				printf("*");
				
				d[j++] = b;
			}
			
			else
			{
				break;
			}
		}
		fflush(stdin);
		
		printf("\n\n");
		printf("   _______________________________________\n\n");
		
		if ( strcmp (c, d) == 0 )
		{
			strcpy ( mima, c );  
			strcpy ( user[n].passcode, mima );
			
			printf("\n   	         注册成功！\n");
			printf("              ");
			
			int count_down = 0;
			for(count_down = 3; count_down >= 1 ; count_down--)
			{
				printf("%d秒后进入登陆界面", count_down);
				
				Sleep(1000);
				
				int temp = 1;
				for( ; temp <= 17; temp++)
				{
					putchar('\b');
				}
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
//				putchar ('\b');
			}
			
		}
		else
		{
			printf("\n    	     您两次输入的密码不同\n    	          请重新注册！\n\n\n!");
			
			system("pause");
			regist();
		}
		system("pause");		
	}
	filesave();
	login();
}



///////////////////////////////////////////////////////////////////////登录模块 
void login()
{
	system("cls");
	
	printf("   ________________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |           欢迎来到登陆界面！         |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                     --by刘永蘅  V%s |\n", V);
	printf("   |______________________________________|\n\n");
	
	int i = 0;
	int j = 0;
	int log[100] = {0};
	int l = 0;
	int t = 0;
	
	char number[20] = {'\0'};
	char passcode[20] = {'\0'};
	char a = '\0';
	
	printf("\n              请输入学号: ");
	scanf("%s", &number);
	fflush(stdin);
	
	printf("\n");
	printf("\n              请输入密码: ");
	
	
	while((a = getch()) != '\n')
	{
		if(a == '\b')
		{
			passcode[t - 1] = NULL;
			
			putchar('\b');
			putchar(' ');
			putchar('\b');
			
			t--;
		}
		
		else if(isalpha(a) || isdigit(a))
		{
			printf("*");
			
			passcode[t++] = a;
		}
		
		else
		{
			break;
		}
	}
	fflush(stdin);

	printf("\n\n");
	
	l = t;
	for(i = 0; i < l; i++)
	{
		if( ! strcmp(user[i].number, number))
		{
			if(strcmp(user[i].passcode, passcode) != 0)
			{
				printf("\n              登录失败， 密码错误\n\n");
				printf("   _______________________________________\n\n");
				
				system("pause");
				
				login();
			}
			else
			{
				printf("\n              登陆成功！\n");
				printf("              ");
			
				int count_down = 0;
				for ( count_down = 3; count_down >= 1 ; count_down-- )
				{
					printf("%d秒后进入附魔界面", count_down);
					
					Sleep(1000);
					
					int temp = 1;
					for( ; temp <= 17; temp++)
					{
						putchar('\b');
					}
				}
				core_system();
				break;
			}

		}
		else
		{
			printf("\n              登录失败， 用户名错误\n");
			printf("   _______________________________________\n\n");
			
			system("pause");
				
			login();
		}
	}
	
	
}




/////////////////////////////////////////////////////////////////////////文件附魔模块（核心模块） 
void core_system()
{
	system("cls");
	
	printf("   ________________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |           欢迎来到附魔界面！         |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                     --by刘永蘅  V%s |\n", V);
	printf("   |______________________________________|\n\n");
	
	FILE *fp_1;
	FILE *fp_2;
	FILE *fp_3;
	
	char ch_1 = '\0';
	char ch_2 = '\0';
	char ch_3 = '\0';
	char filename_1[20] = {"\0"};
	char filename_2[20] = {"\0"};
	char filename_3[20] = {"\0"};
	
	printf("\n请输入被隐藏的文件的名字（带拓展名）: ");
	scanf("%s", &filename_1);
	fflush(stdin);
	
	printf("\n请输入表面文件的名字（带拓展名）: ");
	scanf("%s", &filename_2);
	fflush(stdin);
	
	strcpy(filename_2, filename_3);
	
//	printf("\n请给生成的新文件命名（带拓展名）：");
//	scanf("%s", &filename_3);
//	fflush(stdin);

	//以只写的方式打开文件 3 
	if( ! (fp_3 = fopen(filename_3, "ab")))
	{
		printf("\n");
		printf("    无法打开此文件！\n");
		printf("    即将退出此程序！\n");
		
		system("pause");
		
		exit (0);
	}
	
	//以只读的方式打开文件 1 
	if( ! (fp_1 = fopen(filename_1, "rb")))
	{
		printf("\n");
		printf("    无法打开此文件！\n");
		printf("    即将退出此程序！\n");
		
		system("pause");
		
		exit (0);
	}
	
	//以只读的方式打开文件 2
	if( ! (fp_2 = fopen(filename_2, "rb")))
	{
		printf("\n");
		printf("    无法读取此文件！\n");
		printf("    即将退出此程序！\n");
		
		system("pause");
		
		exit (0);
	} 
	
	
	printf("\n              正在附魔...");
	int wait = 0;
	for(wait = 1; wait <= 20; wait++)
	{
		Sleep(100);
		printf(".");
	}
	
	
	
	while( ! (feof(fp_1)))
	{
		//读取文件 1 
		ch_1 = fgetc (fp_1);
		
		//写入文件 3	
		ch_3 = ch_1;
		fputc(ch_3, fp_3);	
	}
	
	printf("\n              请耐心等待\n");
	
	while( ! (feof(fp_2)))
	{
		//读取文件 2
		ch_2 = fgetc(fp_2);
		
		//写入文件 3 
		ch_3 = ch_2;
		fputc(ch_3, fp_3);
	}
	
	fclose(fp_2);
	fclose(fp_1);
	fclose(fp_3);
	
	remove(filename_1);
	remove(filename_2);
	
	printf("\n");
	printf("\n              附魔成功！\n");
	printf("   _______________________________________\n\n");
	system("pause");
	
	over();
}



////////////////////////////////////////////////////////结束（界面） 
void over()
{
	system("cls");
	
	printf("   ________________________________________\n");
	printf("   |              文件附魔器              |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |     *****感谢您的使用，再见！*****   |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                                      |\n");
	printf("   |                     --by刘永蘅  V%s |\n", V);
	printf("   |______________________________________|\n\n\n");
	
	system("pause");
	
	exit (0);
}
