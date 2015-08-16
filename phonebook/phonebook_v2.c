#include <stdio.h>
#include <time.h>
#include <string.h>
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
/*void printstruct(PhoneBook * book){
	printf("L:%p\n",book->LastName);	
	printf("F:%p\n",book->FirstName);	
	printf("e:%p\n",book->email);	
	printf("p:%p\n",book->phone);	
	printf("c:%p\n",book->cell);	
	printf("a:%p\n",book->addr1);	
	printf("a:%p\n",book->addr2);	
	printf("c:%p\n",book->city);	
	printf("s:%p\n",book->state);	
	printf("z:%p\n",book->zip);	
	printf("_p:%p\n",book->pNext);	
}*/
PhoneBook *addName( char *lastname, PhoneBook *append){
	PhoneBook *newuser;
	newuser = (PhoneBook *) malloc(sizeof(PhoneBook));
	append -> pNext = newuser;
	strcpy( newuser -> LastName, lastname);
	newuser -> pNext = NULL;
	return newuser;
}
	
void printBook(PhoneBook *head){
	while(head != NULL){
		printf("%s\n", head -> LastName);
		head = head ->pNext;
	}
}
//struct __Phone_BOOK_ENTRY *
int findName_3(char Last[]/*, struct __PHONE_BOOK_ENTRY * pNext*/, char* lastname, int offset ) {

	while (1) {
		if (strcasecmp(Last, *&lastname ) == 0){
//			printf("findit:%s\n", *&lastname);
			return 1;
		}
		lastname = lastname+offset;
		
	}
//	printf("cant find\n");
	return 0;
}
int main(void){
	FILE *fp;
	
	char name[MAX_LAST_NAME_SIZE];
	fp = fopen("all-names.txt","r");
	PhoneBook *head, *append;
	head = (PhoneBook *) malloc(sizeof(PhoneBook));
	strcpy(head -> LastName, "ben");
	head -> pNext = NULL;
	append = head;

	while(fscanf(fp, "%s", name) != EOF){
		//printf("%s", name);
		append = addName(name, append);
	}
	append = addName("tzuen", append);
//	printBook(head);
//	printf("%p\n", head->pNext);
	
	append = head->pNext;
	int a = &head->LastName;
	int b = &append->LastName;
	int offset = b - a;
//	printf("offset:%d\n",b-a);
	append = head;
	float startTime = 0 , endTime = 0;
        startTime = (float)clock()/CLOCKS_PER_SEC;
        
	findName_3("tzuen", &(append->LastName), offset);
        
        endTime = (float)clock()/CLOCKS_PER_SEC;
        printf("time:%f\n", endTime-startTime);

//	printstruct(head);
	return 0;
}
	








