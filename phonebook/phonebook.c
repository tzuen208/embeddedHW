#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_LAST_NAME_SIZE 16

typedef struct __PHONE_BOOK_ENTRY {

	char LastName[MAX_LAST_NAME_SIZE];

	char FirstName[16];

	char email[16];

	char phone[10];

	char cell[10];

	char addr1[16];

	char addr2[16];

	char city[16];

	char state[2];

	char zip[5];

	struct	__PHONE_BOOK_ENTRY *pNext;

} PhoneBook;


PhoneBook *findName(char Last[], PhoneBook *pHead) {

	while (pHead != NULL) {

		if (strcasecmp(Last, pHead->LastName) == 0)

			return pHead;

		pHead = pHead->pNext;

	}

	return NULL;
}
PhoneBook *addName( char *lastname, PhoneBook *append){
	PhoneBook *newuser;
	newuser = (PhoneBook *) malloc(sizeof(PhoneBook));
	append -> pNext = newuser;
	strcpy( newuser -> LastName, lastname);
	newuser -> pNext = NULL;
	return newuser;
}
/*void printBook(PhoneBook *head){
	while(head!=NULL){
		printf("%s\n", head-> LastName);
		head = head -> pNext;
	}
}*/
int main(void){
	FILE *fp;
	
	char name[MAX_LAST_NAME_SIZE];
	fp = fopen("all-names.txt","r");
	PhoneBook *head, *append;
	head = (PhoneBook *) malloc(sizeof(PhoneBook));
	strcpy(head -> LastName, "ben");
	head -> pNext = NULL;
	append = head;
	//char c = head->pNext

	while(fscanf(fp, "%s", name) != EOF){
		//printf("%s", name);
		append = addName(name, append);
	}
	append = addName("tzuen", append);
//	printBook(head);
//	printf("%p\n", head->pNext);
	
//	append = head->pNext;
//	printf("%p\n", append->pNext);
//	append = append->pNext;
//	printf("%p\n", append->pNext);
//	printf("%d\n", sizeof(head->pNext));
	append = head;
//	printf("%s\n", *&(append->LastName));
	float startTime = 0 , endTime = 0;
	startTime = (float)clock()/CLOCKS_PER_SEC;

	append = findName("tzuen", head);
	endTime = (float)clock()/CLOCKS_PER_SEC;
	printf("time:%f\n", endTime-startTime);
//	printf("%s\n", append->LastName);	
	//findName_3("Zea", append->pNext,&(append->LastName));
//	findName_3("Zea", &(append->LastName));
//	printf("%s\n", append->LastName);	
	return 0;
}
	








