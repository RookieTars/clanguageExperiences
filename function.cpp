#include "my.h"
using namespace std;

//����:��ʾ��Ȩ��Ϣ 
//����:�� 
//����ֵ:0 
int showCopyright() { 
	cout<< "Copyright <c> 2019-"<<CURYEAR<<" ������ <221801215>. All Rights Reserved."
	<<endl;
	return 0;
}
//����:չʾ��ǰʱ�� 
//����:�� 
//����ֵ:0  
int showPresentTime(){ 
	char weekDays[7][7]={"������","����һ","���ڶ�","������","������","������",
	"������"};
	SYSTEMTIME stCurTime={0};
	GetLocalTime(&stCurTime); 
    cout<<"��ǰʱ��Ϊ";
    printf("%4d-%02d-%02d<%s>%02d:%02d:%02d\n",stCurTime.wYear,stCurTime.wMonth,stCurTime.wDay,weekDays[stCurTime.wDayOfWeek],
	stCurTime.wHour,stCurTime.wMinute,stCurTime.wSecond);//�޷�ʹ��-> 
	return 0;
}
//����:��������(�ڱ����) 
//����:�� 
//����ֵ:�ڱ�����ַ 
struct List *createList(){ 
	struct List *head;
	head=(struct List*)malloc(sizeof(struct List));
	head->next=NULL;
	cout<<endl<<"�����ɹ�***************************************************"<<endl; 
	return head;
}
//����:չʾ���ܲ˵� 
//����:�� 
//����ֵ:0 
int showMenu(){
	showCopyright();
	showPresentTime();
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl
		<<"$   A.�����ڱ���㣬����������                                               $"<<endl
		<<"$   B.����5000���洢�����ʱ��Ľ�㲢��������                               $"<<endl
		<<"$   C.�鿴�����ǰn�����(����0�鿴ȫ��)                                     $"<<endl
		<<"$   D.������洢������ʱ�����ݴ��롰List.dat���ļ���                         $"<<endl
		<<"$   E.������ʾ�ļ���List.dat���д洢��ʱ������                               $"<<endl
		<<"$   F.�鿴���н����ʱ�䲻����ʵ�ʵ�ʱ������                                 $"<<endl
		<<"$   G.ɾ��ʱ�����ݲ�����ʵ�ʵĽ��                                           $"<<endl
		<<"$   H.ɾ������ĵ�һ�����                                                   $"<<endl
		<<"$   I.ɾ����������һ�����                                                 $"<<endl
		<<"$   J.�����е�ǰʱ��Ľ��嵽��ͷ                                           $"<<endl
		<<"$   K.�����е�ǰʱ��Ľ��嵽��β                                           $"<<endl
		<<"$   L.�����е�ǰʱ��Ľ��嵽��һ��ʱ��������֮��Ľ��֮ǰ                 $"<<endl
		<<"$   M.�����е�ǰʱ��Ľ��嵽��һ��ʱ��������֮ǰ�Ľ��֮��                 $"<<endl
		<<"$   N.�鿴ÿ��������2000��1��1�յ�����                                     $"<<endl
		<<"$   O.������������С����ð������                                           $"<<endl
		<<"$   P.ͳ�������� �� �� �ն��������Ľ���������ʾ                            $"<<endl
		<<"$   Q.��ͨ�������±�ת����                                                 $"<<endl
		<<"$   R.�ͷ�����                                                               $"<<endl
		<<"$   S.�˳�����                                                               $"<<endl
		<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl
		<<"��������빦��ǰ����ĸʵ�����蹦��:";
	return 0;
}
//����:�õ��û�ѡ�� 
//����:�� 
//����ֵ:char �û������ѡ����ĸ 
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
	cout<<endl<<"�����������������:";//����������µ��� 
	return getOption();
}
//����:��NODELNUM���������ʱ����½�����������(����) 
//����:�ڱ�����ַ 
//����ֵ: �ڱ�����ַ 
struct List *fillList(struct List *head){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<NODENUM;i++){
		struct List *node;
		node=(struct List*)malloc(sizeof(struct List));
		node->year=2000+rand()%101;//������������ 
		node->month=1+rand()%12;
		node->day=1+rand()%31;
		node->next=head->next;
		head->next=node;
	}
	cout<<endl<<"����ɹ�"<<i<<"��**************************************************"<<endl;
	return head;
}
//����:չʾn����� ,n=0ʱȫ��չʾ 
//����:�ڱ�����ַ,int��Ҫչʾ�Ľڵ����� 
//����ֵ: 0 
int showList(struct List * head,int n){
	struct List *node;
	node=head->next; 
	int i;
	for(i=0;node!=NULL&&(i<n||(n==0&&i<NODENUM));i++){
		if(i%COLUMN==0){
			printf("\n%4d:",i/COLUMN+1);//���в����к� 
		}
		printf("%04d-%02d-%02d   ",node->year,node->month,node->day);
		node=node->next;
	}
	cout<<endl<<"����ʾȫ��**********************************************"<<endl;
	return 0;
}
//����:������洢�����ݷ��д���List.dat�ļ� (ֻд) 
//����:�ڱ�����ַ 
//����ֵ: 0 
int storeToFile(struct List *head){//tested
	struct List *node;
	node=head->next;
	FILE *fp;
	if((fp=fopen("List.dat","w"))==NULL){
		cout<<endl<<"�޷����ļ�"<<endl;
		exit(1);
	}
	for(int i=0;node!=NULL;i++){
		if(i%COLUMN==0){
			fprintf(fp,"\n%d:",i/COLUMN+1);//���д洢 
		}
		fprintf(fp,"%4d-%02d-%02d   ",node->year,node->month,node->day);
		node=node->next;
	}
	fclose(fp);
	cout<<endl<<"�ļ��ѱ���";
	return 0;
}
//����:���ļ��е����ݷ���,���к���ʾ 
//����:�� 
//����ֵ:0 
int showFile(){
	FILE *fp;
	char ch;
	int i=-1;//�������� 
	if((fp=fopen("List.dat","r"))==NULL){//�ļ�ֻ�� 
		printf("�޷����ļ�");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		putchar(ch);
		if(ch=='\n'){
			i++;
			if(i>0&&i%30==0){//����,�к������ļ��� 
				printf("�����������");
				getch();
				printf("\n");
			} 
		}
	}
	fclose(fp);
	printf("\n�Ѽ���ȫ������");
	return 0;
}
//����:�ж��������Ƿ�Ϸ� 
//����:int ��,int ��,int �� 
//����ֵ:bool �Ϸ�:true,�Ƿ�:false 
bool isLegalDate(int year,int month,int day){
	bool result=true;
	if(year<2000||year>2100||month<1||month>12||day<1||day>31){
		result=false;
	}else if(month==4||month==6||month==9||month==11){
		if(day>30){
			result=false;
		}
	}else if(month==2){
		if((year%4==0&&year%100!=0)||year%400==0){//���� 
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
//����:չʾ�����зǷ��������� 
//����:�ڱ�����ַ 
//����ֵ:int �Ƿ�������� 
int showIllegalNode(struct List *head){
	struct List *node=NULL;
	int i=0;
	node=head->next;
	while(node!=NULL){
		if(!isLegalDate(node->year,node->month,node->day)){
			if(i%COLUMN==0){
				printf("\n%4d:",i/COLUMN+1);//���к� 
			}
			printf("%4d-%02d-%02d   ",node->year,node->month,node->day);
			i++;
		}
		node=node->next;
	}
	cout<<endl<<"����ʾȫ���Ƿ��ڵ�"<<i<<"��**************************************"<<endl;
	return i;
}
//����:��ת���� 
//����:�ڱ�����ַ 
//����ֵ: 0 
int reverseList(struct List *head){//tested
	struct List *prev=NULL,*pCur=NULL;
	if(head->next!=NULL){
		prev=head->next;
		pCur=prev->next;
	}
	while(pCur!=NULL){//��prev��һ�����뵽head֮�� ʵ�ַ�ת 
		prev->next=pCur->next;
		pCur->next=head->next;
		head->next=pCur;
		pCur=prev->next;
	}
	cout<<endl<<"��ת���**************************************************"<<endl;
	return 0;
}
//����:ɾ���ڱ�����ĵ�һ����� 
//����:�ڱ��ڵ��ַ 
//����ֵ: 0 
int deleteFirst(struct List *head){//tested
	struct List *node=NULL;
	node=head->next;
	head->next=node->next;
	free(node);
	cout<<endl<<"ɾ���ڱ�����ĵ�һ�����ɹ�*************************************************"<<endl; 
	return 0;
}
//����:ɾ�������е����һ���ڵ� 
//����:�ڱ�����ַ 
//����ֵ: 0 
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
	cout<<endl<<"ɾ�������е����һ���ڵ�ɹ�**************************************************"<<endl;
	return 0;
}
//����:ɾ�����������ݲ��Ϸ��Ľ�� 
//����:�ڱ�����ַ 
//����ֵ: 0 
int deleteIllegal(struct List *head){//tested
	struct List *pre,*cur;
	pre=head;
	cur=head->next;
	while(cur!=NULL){//��������,ɾ���Ƿ���� 
		if(!isLegalDate(cur->year,cur->month,cur->day)){
			pre->next=cur->next;
			free(cur);
			cur=pre->next;
		}else{
			pre=cur;
			cur=cur->next;
		}
	}
	cout<<endl<<"�Ƿ�������ɾ��**********************************************"<<endl;
	return 0;
}
//����:������洢ʱ�䵽2000.01.01������ 
//����:int ��,int ��,int �� 
//����ֵ:int �������� 
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
//����:������20000101��������䵽���� periodLenthFrom2000�� 
//����:�ڱ�����ַ 
//����ֵ:0
int fillPeriodLenth(struct List *head){
	struct List *node=NULL;
	node=head->next;
	while(node!=NULL){//��������� 
		node->periodLenthFrom2000=countPeriodLenth(node->year,
										node->month,node->day);
		node=node->next;
	}
	return 0;
}
//����:չʾ�����н�����20000101������ 
//����:�ڱ�����ַ 
//����ֵ: 0
int showPeriodLenth(struct List *head){
	struct List *node=head->next;
	int i=0;
	while(node!=NULL){
		if(i%COLUMN==0){//����չʾ 
			printf("\n%4d:",i/COLUMN+1);
		}
		printf("%10d   ",node->periodLenthFrom2000);
		node=node->next;
		i++;
	}
	cout<<endl<<"��ȫ����ʾ***************************************"<<endl;
	return 0;
}
//����:����ǰʱ��������մ洢��һ������� 
//����:�� 
//����ֵ:���е�ǰʱ��Ľ���ַ 
struct List *getPresentTimeNode(){//tested
	struct List *node;
	node=(struct List *)malloc(sizeof(struct List));
	node->next=NULL;
	SYSTEMTIME stCurTime={0};
	GetLocalTime(&stCurTime);//��ȡ��ǰʱ�� 
	node->year=stCurTime.wYear;//��������� 
	node->month=stCurTime.wMonth;
	node->day=stCurTime.wDay;
	node->periodLenthFrom2000=countPeriodLenth(node->year,node->month,node->day);
	return node;
}
//����: �����е�ǰʱ��Ľڵ�����ڱ����� 
//����:�ڱ�����ַ 
//����ֵ: 0
int insertToFirst(struct List *head){
	struct List *node;
	node=getPresentTimeNode();
	node->next=head->next;
	head->next=node;
	cout<<endl<<"����ɹ�********************************************************"<<endl;
	return 0;
}
//����: �����е�ǰʱ��Ľڵ�嵽����β�� 
//����:�ڱ�����ַ 
//����ֵ: 0
int insertToLast(struct List *head){
	struct List *cur,*node;
	node=getPresentTimeNode();
	cur=head;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next=node;
	node->next=NULL;
	cout<<endl<<"����ɹ�********************************************************"<<endl;
	return 0;
}
//����: �����е�ǰʱ��Ľڵ�嵽��һ��ʱ�����Ľ��֮ǰ 
//����:�ڱ�����ַ 
//����ֵ: 0
int insertBeforeLater(struct List *head){//tested
	struct List *node=NULL,*presentTimeNode=NULL;
	node=head;
	presentTimeNode=getPresentTimeNode();
	while(node->next!=NULL){
		if(node->next->periodLenthFrom2000>presentTimeNode->periodLenthFrom2000){//�ҵ���һ��ʱ�����Ľ�� 
			presentTimeNode->next=node->next;
			node->next=presentTimeNode;
			cout<<endl<<"����ɹ�********************************************"<<endl;
			return 0;
		}
		node=node->next;
	}
	cout<<endl<<"����ʧ�ܣ��޲����************************************"<<endl;
	return 1; 
}
//����: �����е�ǰʱ��Ľڵ�嵽��һ��ʱ���С�Ľ��֮�� 
//����:�ڱ�����ַ 
//����ֵ: 0
int insertAfterFormer(struct List *head){
	struct List *node=NULL,*presentTimeNode=NULL;
	node=head->next;
	presentTimeNode=getPresentTimeNode();
	while(node!=NULL){
		if(presentTimeNode->periodLenthFrom2000>node->periodLenthFrom2000){//�ҵ���һ��ʱ���С�Ľ�� 
			presentTimeNode->next=node->next;
			node->next=presentTimeNode;
			cout<<endl<<"����ɹ�********************************************"<<endl;
			return 0;
		}
		node=node->next;
	}
	cout<<endl<<"����ʧ�ܣ��޲����***********************************"<<endl;
	return 1;
}
//����: ��������,ͳ����Ч������� 
//����:�ڱ�����ַ 
//����ֵ: int ������� 
int getNodeNum(struct List *head){
	struct List *node=head->next;
	int i=0;
	while(node!=NULL){
		i++;
		node=node->next;
	}
	return i;
}
//����: �����ʱ����С��������(ð������) 
//����:�ڱ�����ַ 
//����ֵ: 0
int sortList(struct List *head){//tested
	int n=getNodeNum(head);
	struct List *pre=NULL,*cur1=NULL,*cur2=NULL,*temp=NULL;
	if(n>1){
		cout<<endl<<"��ȴ�......"<<endl;
		for(int i=0;i<n-1;i++){//ð������(����ѭ��) 
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
		cout<<endl<<"�޷�����"<<endl;//ֻ��һ����Ч����޷����� 
		return 1;
	}
	cout<<endl<<"�������"<<endl;
	return 0;
}
//����: ������ 
//����:int ��Ҫ�жϵ��� 
//����ֵ:  bool ����:true,������:false 
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
//����: չʾ�����������ն�Ϊ�����Ľ�� 
//����: �ڱ�����ַ 
//����ֵ:int �����ն�Ϊ�����Ľ������ 
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
	cout<<endl<<"����ʾ����ʱ��Ϊ�����Ľڵ㣬����:"<<i<<"��"<<endl;
	return i;
}
//����: �ͷ����� 
//����:�ڱ�����ַ 
//����ֵ: 0
int freeList(struct List *head){//tested
	struct List *node=head,*p=NULL;
	while(node!=NULL){
		p=node->next;
		free(node);
		node=p;
	}
	return 0;
}
