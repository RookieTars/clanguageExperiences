#include "my.h"
using namespace std;

//功能:显示版权信息 
//参数:无 
//返回值:0 
int showCopyright() { 
	cout<< "Copyright <c> 2019-"<<CURYEAR<<" 陈亮亮 <221801215>. All Rights Reserved."
	<<endl;
	return 0;
}
//功能:展示当前时间 
//参数:无 
//返回值:0  
int showPresentTime(){ 
	char weekDays[7][7]={"星期天","星期一","星期二","星期三","星期四","星期五",
	"星期六"};
	SYSTEMTIME stCurTime={0};
	GetLocalTime(&stCurTime); 
    cout<<"当前时间为";
    printf("%4d-%02d-%02d<%s>%02d:%02d:%02d\n",stCurTime.wYear,stCurTime.wMonth,stCurTime.wDay,weekDays[stCurTime.wDayOfWeek],
	stCurTime.wHour,stCurTime.wMinute,stCurTime.wSecond);//无法使用-> 
	return 0;
}
//功能:创建链表(哨兵结点) 
//参数:无 
//返回值:哨兵结点地址 
struct List *createList(){ 
	struct List *head;
	head=(struct List*)malloc(sizeof(struct List));
	head->next=NULL;
	cout<<endl<<"创建成功***************************************************"<<endl; 
	return head;
}
//功能:展示功能菜单 
//参数:无 
//返回值:0 
int showMenu(){
	showCopyright();
	showPresentTime();
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl
		<<"$   A.创建哨兵结点，建立空链表                                               $"<<endl
		<<"$   B.建立5000个存储有随机时间的结点并插入链表                               $"<<endl
		<<"$   C.查看链表的前n个结点(输入0查看全部)                                     $"<<endl
		<<"$   D.将链表存储的所有时间数据存入“List.dat”文件中                         $"<<endl
		<<"$   E.分屏显示文件“List.dat”中存储的时间数据                               $"<<endl
		<<"$   F.查看所有结点中时间不符合实际的时间数据                                 $"<<endl
		<<"$   G.删除时间数据不符合实际的结点                                           $"<<endl
		<<"$   H.删除链表的第一个结点                                                   $"<<endl
		<<"$   I.删除链表的最后一个结点                                                 $"<<endl
		<<"$   J.将存有当前时间的结点插到链头                                           $"<<endl
		<<"$   K.将存有当前时间的结点插到链尾                                           $"<<endl
		<<"$   L.将存有当前时间的结点插到第一个时间在现在之后的结点之前                 $"<<endl
		<<"$   M.将存有当前时间的结点插到第一个时间在现在之前的结点之后                 $"<<endl
		<<"$   N.查看每个结点距离2000年1月1日的天数                                     $"<<endl
		<<"$   O.将链表按日期由小到大冒泡排序                                           $"<<endl
		<<"$   P.统计链表中 年 月 日都是素数的结点个数并显示                            $"<<endl
		<<"$   Q.不通过建立新表翻转链表                                                 $"<<endl
		<<"$   R.释放链表                                                               $"<<endl
		<<"$   S.退出程序                                                               $"<<endl
		<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl
		<<"请根据输入功能前的字母实现所需功能:";
	return 0;
}
//功能:得到用户选项 
//参数:无 
//返回值:char 用户输入的选项字母 
char getOption(){
	int i;
	char input,option[19]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'};
	input=getch();
	putchar(input);
	input=toupper(input);
	for(i=0;i<19;i++){
		if(input==option[i]){
			return input;
		}
	}
	cout<<endl<<"输入错误，请重新输入:";//输入错误重新调用 
	return getOption();
}
//功能:将NODELNUM个存有随机时间的新建结点插入链表(无序) 
//参数:哨兵结点地址 
//返回值: 哨兵结点地址 
struct List *fillList(struct List *head){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<NODENUM;i++){
		struct List *node;
		node=(struct List*)malloc(sizeof(struct List));
		node->year=2000+rand()%101;//填充随机年月日 
		node->month=1+rand()%12;
		node->day=1+rand()%31;
		node->next=head->next;
		head->next=node;
	}
	cout<<endl<<"插入成功"<<i<<"个**************************************************"<<endl;
	return head;
}
//功能:展示n个结点 ,n=0时全部展示 
//参数:哨兵结点地址,int需要展示的节点数量 
//返回值: 0 
int showList(struct List * head,int n){
	struct List *node;
	node=head->next; 
	int i;
	for(i=0;node!=NULL&&(i<n||(n==0&&i<NODENUM));i++){
		if(i%COLUMN==0){
			printf("\n%4d:",i/COLUMN+1);//分行并加行号 
		}
		printf("%04d-%02d-%02d   ",node->year,node->month,node->day);
		node=node->next;
	}
	cout<<endl<<"已显示全部**********************************************"<<endl;
	return 0;
}
//功能:将链表存储的数据分行存入List.dat文件 (只写) 
//参数:哨兵结点地址 
//返回值: 0 
int storeToFile(struct List *head){//tested
	struct List *node;
	node=head->next;
	FILE *fp;
	if((fp=fopen("List.dat","w"))==NULL){
		cout<<endl<<"无法打开文件"<<endl;
		exit(1);
	}
	for(int i=0;node!=NULL;i++){
		if(i%COLUMN==0){
			fprintf(fp,"\n%d:",i/COLUMN+1);//分行存储 
		}
		fprintf(fp,"%4d-%02d-%02d   ",node->year,node->month,node->day);
		node=node->next;
	}
	fclose(fp);
	cout<<endl<<"文件已保存";
	return 0;
}
//功能:将文件中的数据分屏,加行号显示 
//参数:无 
//返回值:0 
int showFile(){
	FILE *fp;
	char ch;
	int i=-1;//行数计数 
	if((fp=fopen("List.dat","r"))==NULL){//文件只读 
		printf("无法打开文件");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		putchar(ch);
		if(ch=='\n'){
			i++;
			if(i>0&&i%30==0){//分屏,行号已在文件中 
				printf("按任意键继续");
				getch();
				printf("\n");
			} 
		}
	}
	fclose(fp);
	printf("\n已加载全部内容");
	return 0;
}
//功能:判断年月日是否合法 
//参数:int 年,int 月,int 日 
//返回值:bool 合法:true,非法:false 
bool isLegalDate(int year,int month,int day){
	bool result=true;
	if(year<2000||year>2100||month<1||month>12||day<1||day>31){
		result=false;
	}else if(month==4||month==6||month==9||month==11){
		if(day>30){
			result=false;
		}
	}else if(month==2){
		if((year%4==0&&year%100!=0)||year%400==0){//闰年 
			if(day>29){
				result=false;
			}
		}else{
			if(day>28){
				result=false;
			}
		}
	}
	return result;
}
//功能:展示链表中非法结点的数据 
//参数:哨兵结点地址 
//返回值:int 非法结点数量 
int showIllegalNode(struct List *head){
	struct List *node=NULL;
	int i=0;
	node=head->next;
	while(node!=NULL){
		if(!isLegalDate(node->year,node->month,node->day)){
			if(i%COLUMN==0){
				printf("\n%4d:",i/COLUMN+1);//加行号 
			}
			printf("%4d-%02d-%02d   ",node->year,node->month,node->day);
			i++;
		}
		node=node->next;
	}
	cout<<endl<<"已显示全部非法节点"<<i<<"个**************************************"<<endl;
	return i;
}
//功能:翻转链表 
//参数:哨兵结点地址 
//返回值: 0 
int reverseList(struct List *head){//tested
	struct List *prev=NULL,*pCur=NULL;
	if(head->next!=NULL){
		prev=head->next;
		pCur=prev->next;
	}
	while(pCur!=NULL){//将prev后一个插入到head之后 实现翻转 
		prev->next=pCur->next;
		pCur->next=head->next;
		head->next=pCur;
		pCur=prev->next;
	}
	cout<<endl<<"翻转完成**************************************************"<<endl;
	return 0;
}
//功能:删除哨兵结点后的第一个结点 
//参数:哨兵节点地址 
//返回值: 0 
int deleteFirst(struct List *head){//tested
	struct List *node=NULL;
	node=head->next;
	head->next=node->next;
	free(node);
	cout<<endl<<"删除哨兵结点后的第一个结点成功*************************************************"<<endl; 
	return 0;
}
//功能:删除链表中的最后一个节点 
//参数:哨兵结点地址 
//返回值: 0 
int deleteLast(struct List *head){//tested
	if(head->next==NULL){
		return 0;
	}
	struct List *pre=NULL,*cur=NULL;
	cur=head->next;
	pre=head;
	while(cur->next!=NULL){
		pre=cur;
		cur=cur->next;
	}
	pre->next=NULL;
	free(cur);
	cout<<endl<<"删除链表中的最后一个节点成功**************************************************"<<endl;
	return 0;
}
//功能:删除链表中数据不合法的结点 
//参数:哨兵结点地址 
//返回值: 0 
int deleteIllegal(struct List *head){//tested
	struct List *pre,*cur;
	pre=head;
	cur=head->next;
	while(cur!=NULL){//遍历链表,删除非法结点 
		if(!isLegalDate(cur->year,cur->month,cur->day)){
			pre->next=cur->next;
			free(cur);
			cur=pre->next;
		}else{
			pre=cur;
			cur=cur->next;
		}
	}
	cout<<endl<<"非法日期已删除**********************************************"<<endl;
	return 0;
}
//功能:计算结点存储时间到2000.01.01的天数 
//参数:int 年,int 月,int 日 
//返回值:int 距离天数 
int countPeriodLenth(int year,int month,int day){//tested
	int monthDay1[12]={31,28,31,30,31,30,31,31,30,31,30,31},
		monthDay2[12]={31,29,31,30,31,30,31,31,30,31,30,31},
		sum=0;
	for(int i=2000;i<year;i++){
		if((i%4==0&&i%100!=0)||i%400==0){
			sum+=366;
		}else{
			sum+=365;
		}
	}
	if((year%4==0&&year%100!=0)||year%400==0){
		for(int i=0;i<month-1;i++){
			sum+=monthDay2[i];
		}
	}else{
		for(int i=0;i<month-1;i++){
			sum+=monthDay1[i];
		}
	}
	sum+=day-1;
	return sum;
}
//功能:将距离20000101的天数填充到结点的 periodLenthFrom2000中 
//参数:哨兵结点地址 
//返回值:0
int fillPeriodLenth(struct List *head){
	struct List *node=NULL;
	node=head->next;
	while(node!=NULL){//遍历并填充 
		node->periodLenthFrom2000=countPeriodLenth(node->year,
										node->month,node->day);
		node=node->next;
	}
	return 0;
}
//功能:展示链表中结点距离20000101的天数 
//参数:哨兵结点地址 
//返回值: 0
int showPeriodLenth(struct List *head){
	struct List *node=head->next;
	int i=0;
	while(node!=NULL){
		if(i%COLUMN==0){//分行展示 
			printf("\n%4d:",i/COLUMN+1);
		}
		printf("%10d   ",node->periodLenthFrom2000);
		node=node->next;
		i++;
	}
	cout<<endl<<"已全部显示***************************************"<<endl;
	return 0;
}
//功能:将当前时间的年月日存储到一个结点中 
//参数:无 
//返回值:存有当前时间的结点地址 
struct List *getPresentTimeNode(){//tested
	struct List *node;
	node=(struct List *)malloc(sizeof(struct List));
	node->next=NULL;
	SYSTEMTIME stCurTime={0};
	GetLocalTime(&stCurTime);//获取当前时间 
	node->year=stCurTime.wYear;//填充年月日 
	node->month=stCurTime.wMonth;
	node->day=stCurTime.wDay;
	node->periodLenthFrom2000=countPeriodLenth(node->year,node->month,node->day);
	return node;
}
//功能: 将存有当前时间的节点插入哨兵结点后 
//参数:哨兵结点地址 
//返回值: 0
int insertToFirst(struct List *head){
	struct List *node;
	node=getPresentTimeNode();
	node->next=head->next;
	head->next=node;
	cout<<endl<<"插入成功********************************************************"<<endl;
	return 0;
}
//功能: 将存有当前时间的节点插到链表尾部 
//参数:哨兵结点地址 
//返回值: 0
int insertToLast(struct List *head){
	struct List *cur,*node;
	node=getPresentTimeNode();
	cur=head;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next=node;
	node->next=NULL;
	cout<<endl<<"插入成功********************************************************"<<endl;
	return 0;
}
//功能: 将存有当前时间的节点插到第一个时间更大的结点之前 
//参数:哨兵结点地址 
//返回值: 0
int insertBeforeLater(struct List *head){//tested
	struct List *node=NULL,*presentTimeNode=NULL;
	node=head;
	presentTimeNode=getPresentTimeNode();
	while(node->next!=NULL){
		if(node->next->periodLenthFrom2000>presentTimeNode->periodLenthFrom2000){//找到第一个时间更大的结点 
			presentTimeNode->next=node->next;
			node->next=presentTimeNode;
			cout<<endl<<"插入成功********************************************"<<endl;
			return 0;
		}
		node=node->next;
	}
	cout<<endl<<"插入失败，无插入点************************************"<<endl;
	return 1; 
}
//功能: 将存有当前时间的节点插到第一个时间更小的结点之后 
//参数:哨兵结点地址 
//返回值: 0
int insertAfterFormer(struct List *head){
	struct List *node=NULL,*presentTimeNode=NULL;
	node=head->next;
	presentTimeNode=getPresentTimeNode();
	while(node!=NULL){
		if(presentTimeNode->periodLenthFrom2000>node->periodLenthFrom2000){//找到第一个时间更小的结点 
			presentTimeNode->next=node->next;
			node->next=presentTimeNode;
			cout<<endl<<"插入成功********************************************"<<endl;
			return 0;
		}
		node=node->next;
	}
	cout<<endl<<"插入失败，无插入点***********************************"<<endl;
	return 1;
}
//功能: 遍历链表,统计有效结点数量 
//参数:哨兵结点地址 
//返回值: int 结点数量 
int getNodeNum(struct List *head){
	struct List *node=head->next;
	int i=0;
	while(node!=NULL){
		i++;
		node=node->next;
	}
	return i;
}
//功能: 按结点时间由小到大排序(冒泡排序) 
//参数:哨兵结点地址 
//返回值: 0
int sortList(struct List *head){//tested
	int n=getNodeNum(head);
	struct List *pre=NULL,*cur1=NULL,*cur2=NULL,*temp=NULL;
	if(n>1){
		cout<<endl<<"请等待......"<<endl;
		for(int i=0;i<n-1;i++){//冒泡排序(二重循环) 
			pre=head;
			cur1=pre->next;
			cur2=cur1->next;
			for(int j=0;j<n-i-1;j++){
				if(cur1->periodLenthFrom2000>cur2->periodLenthFrom2000){
					cur1->next=cur2->next;
					cur2->next=cur1;
					pre->next=cur2;
					temp=cur1;
					cur1=cur2;
					cur2=temp;
				}
				pre=pre->next;
				cur1=cur1->next;
				cur2=cur2->next;
			}
		}
	}else{
		cout<<endl<<"无法排序"<<endl;//只有一个有效结点无法排序 
		return 1;
	}
	cout<<endl<<"排序完成"<<endl;
	return 0;
}
//功能: 判素数 
//参数:int 需要判断的数 
//返回值:  bool 素数:true,非素数:false 
bool isPrime(int num){
	bool result=true;
	if(num<2){
		result=false;
	}
	else{
		int k=sqrt(num);
		for(int i=2;i<=k;i++){
			if(num%i==0){
				result=false;
				break;
			}
		}
	}
	return result;
}
//功能: 展示链表中年月日都为素数的结点 
//参数: 哨兵结点地址 
//返回值:int 年月日都为素数的结点数量 
int showPrimeDate(struct List *head){
	int i=0;
	struct List *node=head->next;
	while(node!=NULL){
		if(isPrime(node->month)&&isPrime(node->day)&&isPrime(node->year)){
			if(i%COLUMN==0){
				printf("\n%4d:",i/COLUMN+1);
			}
			printf("%4d-%02d-%02d   ",node->year,node->month,node->day);
			i++;
		}
		node=node->next;
	}
	cout<<endl<<"已显示所有时间为素数的节点，共计:"<<i<<"个"<<endl;
	return i;
}
//功能: 释放链表 
//参数:哨兵结点地址 
//返回值: 0
int freeList(struct List *head){//tested
	struct List *node=head,*p=NULL;
	while(node!=NULL){
		p=node->next;
		free(node);
		node=p;
	}
	return 0;
}
