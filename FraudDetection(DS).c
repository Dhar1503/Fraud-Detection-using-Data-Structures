#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char word[100];
	struct Node *next;
};

//function to check if a word is spam
int isSpam(struct Node * head, char* word)
{
	struct Node* current=head;
	while(current!=NULL)
	{
		if(strcmp(current->word, word)==0){
			return 1;
		}
		current = current->next;
	}
	return 0;
}

//function to add a word to the linked list
void addWord(struct Node **head, char *word)
{
	struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->word, word);
	newNode->next=*head;
	*head=newNode;
}

int main()
{
	struct Node* spamWords=NULL;
	int count=0;

	//example usage: adding spam words to the linked list
	addWord(&spamWords,"spam");
	addWord(&spamWords,"fraud");
	addWord(&spamWords,"offer");
	addWord(&spamWords,"free");
	addWord(&spamWords,"discount");
	addWord(&spamWords,"win");
	addWord(&spamWords,"money");
	addWord(&spamWords,"click");
	addWord(&spamWords,"buy");
	addWord(&spamWords,"Buy");
	addWord(&spamWords,"Click");
	addWord(&spamWords,"Get");
	addWord(&spamWords,"Win");


	char message[100];
	printf(">FRAUD DETECTION\n");
	printf(">Detect spam in any messaging app!\n");
	printf(">Enter a message: ");
	fgets(message, sizeof(message),stdin);
	message[strcspn(message,"\n")]='\0';

	char * token= strtok(message, " ");
	while(token!=NULL){
		if(isSpam(spamWords, token)){
			printf(">Spam detected: %s\n",token);
			count++;
		}
		token=strtok(NULL," ");
	}
	if(count==0){
		printf(">No spam :)");
	}

	//free the linked list memory
	struct Node *current=spamWords;
	while(current!=NULL){
		struct Node* temp=current;
		current=current->next;
		free(temp);
	}