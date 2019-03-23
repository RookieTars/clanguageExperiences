#include "my.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	char option;
	struct List *head=(struct List *)malloc(sizeof(struct List)),*securer=NULL;
	securer=head;
	head->next=NULL;
	int num,tag=0;
	while(1){
		showMenu();
		option=getOption();
		switch(option){
			case 'A':
				if(tag==0){
					head=createList();
					tag++;
				}
				break;
			case 'B':
				if(tag==1){
					fillList(head);
					fillPeriodLenth(head);
				}
				break;
			case 'C':
				if(tag==1){
					cout<<endl<<"请输入要查看的个数:";
					cin>>num;
					showList(head,num);
				}
				break;
			case 'D':
				if(tag==1){
					storeToFile(head);
				}
				break;
			case 'E':
				if(tag==1){
					showFile();
				}
				break;
			case 'F':
				if(tag==1){
					showIllegalNode(head);
				}
				break;
			case 'G':
				if(tag==1){
					deleteIllegal(head);
				}
				break;
			case 'H':
				if(tag==1){
					deleteFirst(head);
				}
				break;
			case 'I':
				if(tag==1){
					deleteLast(head);
				}
				break;
			case 'J':
				if(tag==1){
					insertToFirst(head);
				}
				break;
			case 'K':
				if(tag==1){
					insertToLast(head);
				}
				break;
			case 'L':
				if(tag==1){
					insertBeforeLater(head);
				}
				break;
			case 'M':
				if(tag==1){
					insertAfterFormer(head);
				}
				break;
			case 'N':
				if(tag==1){
					showPeriodLenth(head);
				}
				break;
			case 'O':
				if(tag==1){
					sortList(head);
				}
				break;
			case 'P':
				if(tag==1){
					showPrimeDate(head);
				}
				break;
			case 'Q':
				if(tag==1){
					reverseList(head);
				}
				break;
			case 'R':
				if(tag==1){
					freeList(head);
				}
				break;
			case 'S':
				free(securer);
				return 0;
		}
	}
}
