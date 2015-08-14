#include <stdio.h>
#include <string.h>
#define MAX_LAST_NAME_SIZE 16
#define BOOK_SIZE 512

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
int findName_2(char Last[], char **book) {
	int i ;
	for(i = 0; i<BOOK_SIZE; i++){
//		printf("cmp:%s\n", book[i]);
		if(strcasecmp(Last, book[i]) ==0){
			printf("findit:%s", book[i]);
			return 1;
		}
	}

	return 0;
}

PhoneBook *addName( char *lastname, PhoneBook *append){
	PhoneBook *newuser;
	newuser = (PhoneBook *) malloc(sizeof(PhoneBook));
	append -> pNext = newuser;
	strcpy( newuser -> LastName, lastname);
	newuser -> pNext = NULL;
	return newuser;
}
char **  create(  int m , int n ){
	char* values = calloc(m*n, sizeof(char));
	char** rows = malloc(n*sizeof(char*));
	int i;
	for (i=0; i<n; ++i){
        	rows[i] = values + i*m;
    	}
    	return rows;
}
	
/*void printBook(PhoneBook *head){
	while(head != NULL){
		printf("%s\n", head -> LastName);
		head = head ->pNext;
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

	while(fscanf(fp, "%s", name) != EOF){
		//printf("%s", name);
		append = addName(name, append);
	}

	char** book = create(BOOK_SIZE,16);	
//	book[0] = "sssss";
//	printf("%s", book[0]);
	int i ;
	append = head;
	for(i = 0;i<BOOK_SIZE; i++){
		if(append -> LastName != NULL)
		{
			book[i] = append->LastName;
//			printf("savebook: %s, %d\n", book[i],i);
			
			append = append -> pNext;
		}
	}
	while( !findName_2("Zea", book) ){
		for(i = 0;i<BOOK_SIZE; i++){
			if(append -> LastName != NULL)
			{
				book[i] = append->LastName;
	//			printf("savebook: %s\n", book[i]);
				append = append -> pNext;
			}
			else break;
		}
	}

//	append = findName("Zea", head);
//	printf("%s\n", append->LastName);	
	return 0;
}
	








