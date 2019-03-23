#include <iostream>
#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <wtypes.h>

#define CURYEAR 2019 
#define COLUMN 5 
#define NODENUM 5000

struct List{
	int year;
	int month;
	int day;
	int periodLenthFrom2000;
	struct List *next;
};

int showCopyright();
int showPresentTime();
struct List *createList();
int showMenu();
char getOption();
struct List *fillList(struct List *head);
int showList(struct List *head,int n);
int storeToFile(struct List *head);
int showFile();
bool isLegalDate(int year,int month,int day);
int reverseList(struct List *head);
int showIllegalNode(struct List *head);
int deleteFirst(struct List *head);
int deleteLast(struct List *head);
int deleteIllegal(struct List *head);
int countPeriodLenth(int year,int month,int day);
int fillPeriodLenth(struct List *head);
int freeList(struct List *head);
int getNodeNum(struct List *head);
int insertToFirst(struct List *head);
int insertToLast(struct List *head);
int insertBeforeLater(struct List *head);
int insertAfterFormer(struct List *head);
struct List *getPresentTimeNode();
bool isPrime(int num);
int showPeriodLenth(struct List *head);
int showPrimeDate(struct List *head);
int sortList(struct List *head);
