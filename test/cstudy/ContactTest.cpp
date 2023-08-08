#include <stdio.h>
#include <string.h>
#include <assert.h>

#define _CRT_SECURE_NO_WARNINGS 1

//定义全局变量 MAX 100 -- 设置通讯录最多人数
#define MAX 100
//通讯录信息也是同理：
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
 
 
//对测试中，用户输入的选项进行枚举，
//用对应的功能名字代表对应的选项:
enum OPTION
{
	//枚举中的内容默认0开始往后排：
	EXIT,	// 0 对应 退出
	ADD,	// 1 对应 增加
	DEL,	// 2 对应 删除
	SEARCH, // 3 对应 搜索
	MODIFY, // 4 对应 修改
	SHOW,	// 5 对应 显示所有
	SORT	// 6 对应 排序
};
 



//1.结构体 struct PeoInfo -- 存放保存人的信息：
//使用 typedef 重命名结构体，
typedef struct PeoInfo
{
	char name[MAX_NAME]; //名字
	int age; //年龄
	char sex[MAX_SEX]; //性别
	char tele[MAX_TELE]; //电话
	char addr[MAX_ADDR]; //地址
}PeoInfo;
 
 
//2.结构体 struct contact -- 通讯录类型：
//使用 typedef 重命名结构体，
typedef struct contact
{
	//创建通讯信息录结构体变量数组：
	PeoInfo data[MAX];
 
	//创建一个变量来记录当前通讯录data的人数：
	int sz;
}Contact;
 
 
//3.函数 InitContact() 的声明 -- 初始化通讯录类型变量
void InitContact(Contact* pc);
 
//4.函数 AddContact() 的声明 -- 增加通讯录成员：
void AddContact(Contact* pc);
 
//6.函数 ShowContact() 的声明 -- 打印通讯录所有成员信息：
void ShowContact(const Contact* pc);
 
//7.函数 FindByName() 的声明 -- 删除指定通讯录成员信息：
//该函数只在 contact.c文件 中支持其它函数，
//为了保密可以不在该文件声明
// int FindByName(Contact* pc, char name[]);
 
//8.函数 DelContact() 的声明 -- 删除指定通讯录成员信息：
void DelContact(Contact* pc);
 
//9.函数 SearchContact() 的声明 -- 查找指定通讯录成员信息：
void SearchContact(const Contact* pc);
 
//10 . 函数 ModifyContact() 的声明 -- 查找指定通讯录成员信息：
void ModifyContact(Contact* pc); 


//1.函数 InitContact() --初始化通讯录类型变量
void InitContact(Contact* pc)
{
	//断言：
	assert(pc);
 
	memset(pc->data, 0, sizeof(pc->data));
	/*使用 memset系统函数，初始化data数组。
	参数1：被设置的空间 -- data
	参数2：要设置的指-- 0 （全部初始化为0）
	参数3：要设置的空间大小-- sizeof(pc->data) ，
		   直接计算出大小*/
 
	//联系人个数初始化为0：
	pc->sz = 0;
}

//2.函数 AddContact() 的声明 -- 增加通讯录成员：
void AddContact(Contact* pc)
{
	//断言：
	assert(pc);
 
	//增加的前提是还没放满：
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		//无法添加直接返回：
		return;
	}
 
	//没满则开始增加信息：
	// sz 和 data数组 的下标是对应的，
	// 所以可以通过 sz 找到 data 的对应元素，
	// 再通过对应元素找到对应元素的相应信息
	// 如果对应的信息是数组。可以不加&
 
	//名字：
	printf("请输入名字：>");
	//使用 scanf()函数 将信息放进去
	scanf("%s", pc->data[pc->sz].name);
 
	//年龄：
	printf("请输入年龄：>");
	//使用 scanf()函数 将信息放进去
	scanf("%d", &pc->data[pc->sz].age);
 
	//性别：
	printf("请输入性别：>");
	//使用 scanf()函数 将信息放进去
	scanf("%s", pc->data[pc->sz].sex);
 
	//电话：
	printf("请输入电话：>");
	//使用 scanf()函数 将信息放进去
	scanf("%s", pc->data[pc->sz].tele);
 
	//地址：
	printf("请输入地址：>");
	//使用 scanf()函数 将信息放进去
	scanf("%s", pc->data[pc->sz].addr);
 
	//添加完一个联系人后，将指针移向下一个联系人位置：
	pc->sz++;
 
	//打印添加成功信息：
	printf("成功添加联系人\n");
} 
 
 //3 . 函数 ShowContact() -- 打印通讯录所有成员信息：
void ShowContact(const Contact* pc)
{
	//断言：
	assert(pc);
 
	printf("\n");
 
	//打印列标题：
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n", 
		   "名字", "年龄", "性别", "电话", "地址");
 
	//使用 for循环 循环打印信息：
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
											   pc->data[i].age,
											   pc->data[i].sex,
											   pc->data[i].tele,
											   pc->data[i].addr
			  );
		// %20S：打印20个字符，这里名字是20个字符
		// \t： 使用制表符进行对齐
		// %4d：打印4个整型，这里是年龄
		// “-”号 ：左对齐
	}
 
 
	printf("\n");
 
}
 
 
//4 . 函数 FindByName() -- 删除指定通讯录成员信息：
int FindByName(const Contact* pc, char name[])
{
	//遍历查找该人坐标：
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			//如果 找到了一个下标元素的name 和 要找的name 一样
		{
			return i; //返回此时找到的下标
		}
	}
 
	return  -1; //未找到则返回-1
}
 
 
//5 . 函数 DelContact() --删除指定通讯录成员信息：
void DelContact(Contact* pc)
{
	//断言：
	assert(pc);
 
	//先判断通讯录是否为空：
	if (pc->sz == 0)
	{
		//为空就没法删除了，直接返回
		printf("通讯录为空，无法删除\n");
		return;
	}
 
	//创建存放要删除联系人名字的字符数组：
	char name[MAX_NAME] = { 0 };
 
	//输入并接收删除联系人名字：
	printf("请输入要删除的人名字：>");
	scanf("%s", name);
 
	//因为在通讯录中查找某人是多个功能所需要的，
	//所以可以将其封装成函数，再调用：
	int del = FindByName(pc, name);
 
	//如果del为-1，说明未找到：
	if (del == -1)
	{
		printf("要删除的人不存在\n");
		return; //直接返回
	}
 
	//如果找到了则删除坐标为del的联系人：
	int i = 0;
	for (i = del; i < pc->sz-1; i++)
		//从del下标开始，到倒数第二个元素
	{
		pc->data[i] = pc->data[i + 1];
		//把del后1个元素赋给del，循环覆盖掉del的元素
		//倒数第二个元素+1 为最后一个元素为止
	}
 
	//删除一个后，将pc指针向前移一位：
	pc->sz--;
 
	//打印提示：
	printf("成功删除该联系人\n");
}
 
 
//6 . 函数 SearchContact() -- 查找指定通讯录成员信息：
void SearchContact(const Contact* pc)
{
	//断言：
	assert(pc);
 
	//创建存放要查找的联系人名字的字符数组：
	char name[MAX_NAME] = { 0 };
 
	//输入并接收要查找联系人名字：
	printf("请输入要查找的联系人名字：>");
	scanf("%s", name);
 
	//使用 FindByName() 函数查找该人在通讯录中的下标：
	int pos = FindByName(pc, name);
 
	//如果del为-1，说明未找到：
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return; //直接返回
	}
	else //找到了则打印该人信息： 
	{
		//打印列标题：
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-30s\n",
			"名字", "年龄", "性别", "电话", "地址");
		//打印对应信息：
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
													pc->data[pos].age,
													pc->data[pos].sex,
													pc->data[pos].tele,
													pc->data[pos].addr);
	}
 
}
 
 
//7 . 函数 ModifyContact() -- 查找指定通讯录成员信息：
void ModifyContact(Contact* pc)
{
	//断言：
	assert(pc);
 
	//创建存放要修改的联系人名字的字符数组：
	char name[MAX_NAME] = { 0 };
 
	//输入并接收要修改联系人名字：
	printf("请输入要修改的联系人名字：>");
	scanf("%s", name);
 
	//使用 FindByName() 函数查找该人在通讯录中的下标：
	int pos = FindByName(pc, name);
 
	//如果del为-1，说明未找到：
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return; //直接返回
	}
	else //找到了则修改该人信息： 
	{
		//名字：
		printf("请输入名字：>");
		//使用 scanf()函数 将信息放进去
		scanf("%s", pc->data[pos].name);
 
		//年龄：
		printf("请输入年龄：>");
		//使用 scanf()函数 将信息放进去
		scanf("%d", &pc->data[pos].age);
 
		//性别：
		printf("请输入性别：>");
		//使用 scanf()函数 将信息放进去
		scanf("%s", pc->data[pos].sex);
 
		//电话：
		printf("请输入电话：>");
		//使用 scanf()函数 将信息放进去
		scanf("%s", pc->data[pos].tele);
 
		//地址：
		printf("请输入地址：>");
		//使用 scanf()函数 将信息放进去
		scanf("%s", pc->data[pos].addr);
 
		printf("修改成功\n");
	}
} 

//1 . 函数 void menu() -- 打印通讯录菜单：
void menu()
{
	// 选1：增加联系人		选2：删除联系人
	// 选3：搜索联系人		选4：修改联系人信息
	// 选5：显示所有联系人	选6：对联系人进行排序
	//				选0：退出通讯录
	printf("*****************************************************\n");
	printf("*****		1. add		2. del		*****\n");
	printf("*****		3. search	4. modify	*****\n");
	printf("*****		5. show		6. sort		*****\n");
	printf("*****			0. exit			*****\n");
	printf("*****************************************************\n");
}
 
 
//函数 void test() -- 完成通讯录测试：
void test()
{
	//创建通讯录类型变量：
	Contact con;
	//调用函数初始化通讯录类型变量：
	InitContact(&con);
 
	int input = 0;//接收输入的数据
	do
	{
		//调用菜单函数打印菜单：
		menu();
 
		//接收输入数据：
		printf("请选择：>");
		scanf("%d", &input);
 
		//使用switch语句进行筛选判断：
		switch (input)
		{
		case ADD:
			//如果用户输入1，
			//则调用AddContact()函数
			//添加联系人：
			AddContact(&con);
			//参数接收 &con ，对通讯录进行对应操作
			break;
 
		case DEL:
			//如果用户输入2，
			//则调用DelContact()函数
			//删除指定联系人：
			DelContact(&con);
			//参数接收 &con ，对通讯录进行对应操作
			break;
 
		case SEARCH:
			//如果用户输入3，
			//则调用SearchContact()函数
			//查找指定联系人：
			SearchContact(&con);
			//参数接收 &con ，对通讯录进行对应操作
			break;
 
		case MODIFY:
			//如果用户输入 4 ，
			//则调用ModifyContact()函数
			//修改指定联系人信息
			ModifyContact(&con);
			//参数接收 &con ，对通讯录进行对应操作
			break;
 
		case SHOW:
			//如果用户输入5，
			//则调用ShowContact()函数
			//打印所有联系人信息：
			ShowContact(&con);
			//参数接收 &con ，对通讯录进行对应操作
			break;
 
		case SORT:
			//待定
			break;
 
		case EXIT:
			//如果用户输入0，
			//打印对应信息并退出程序：
			printf("退出通讯录\n");
			break;
 
		default:
			//如果用户 输入非法，
			//打印对应信息并程序输入：
			printf("选择错误，重新选择\n");
			break;
		}
 
	} while (input);
	//只要输入数据不为0就继续进行
}
 
//主函数：
int main()
{
	//调用测试函数进行测试：
	test();
 
	return 0;

}

 