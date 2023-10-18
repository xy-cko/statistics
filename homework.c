#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//decleration of linked list which is used for store words to database
typedef struct listword{
	char word[100];
	struct listword *next;
}listword;

//function to add a word to the database from the front
listword * push_front(listword * head, char word[]){
	listword * p = (listword *)malloc(sizeof(listword));
	strcpy(p->word, word);
	p->next = head;
	head = p;
	return head;
}

//function to add a word to the database from the back
listword * push_back(listword * head, char word[]){
	listword * p;
	if(head == NULL){
		return push_front(head, word);
	}
	for(p = head; p->next != NULL; p = p->next);
	p->next = (listword *)malloc(sizeof(listword));
	strcpy(p->next->word, word);
	p->next->next = NULL;
	return head;
}

//menu printing function
void print_menu(listword * head){
	printf("1. text input from file\n");
	printf("2. text input from keyboard.\n");
	printf("0. exit.\n");
	printf("8. history\n");
	if(head != NULL){
		printf("3. the longest word.\n");
		printf("4. the shortest word.\n");
		printf("5. occurrence.\n");
		printf("6. most occured.\n");
		printf("7. least occured.\n");
		
	}
}

//function to take an input from keyboard and store it to the database
listword * keyboard_input_to_database(listword * head){
	listword * p;
	p = head;
	char c;
	int i=0;
	int space_counter = 0;
	//allocating memory for *temp_word
	char * temp_word = (char *)malloc(20*sizeof(char));
	while(scanf("%c",&c) == 1 && c != '\n'){
		//if the program find nonspace character, the character will be copied to a string called temp_word
		if(c != ' '){
			space_counter = 0;
			temp_word[i] = c;
			temp_word[i+1] = '\0';
			i++;
			//if the program find a space character, the string will be added to the database
		} else {
			//space_counter is used to avoid the program adding the same string to the database multiple times when there are more than 1 spaces.
			space_counter++;
			if (space_counter <= 1) {
				p = push_back(p, temp_word);
				i = 0;
			}
		}
	}
	p = push_back(p, temp_word);
	return p;
}

//function to take an input from a file and store it to the database
listword * file_input_to_database(listword * head, char *file_name){
	listword * p;
	p = head;
	char c;
	int i = 0;
	int space_counter = 0;
	FILE * file = fopen(file_name, "r");
	//allocating memory for *temp_word
	char * temp_word = (char *)malloc(20*sizeof(char));
	while(fscanf(file, "%c", &c) == 1){
		if(c != ' '){
			space_counter = 0;
			temp_word[i] = c;
			temp_word[i+1] = '\0';
			i++;
		} else {
			space_counter++;
			if(space_counter <= 1){
				p = push_back(p, temp_word);
			    i = 0;
			}
		}
	}
	p = push_back(p, temp_word);
	return p;
}

//function to find the longest word in the database
char* longest_word(listword * head){
	char* return_string;
	listword * p;
	p = head;
	int max=0, lenght;
	while(p != NULL){
		lenght = strlen(p->word);
		if(lenght>max){
			max = lenght;
			//allocating memory for *return_string
			return_string = (char*)malloc(max*sizeof(char));
			int i;
			for (i = 0; i < max; i++) {
				return_string[i] = p->word[i];
			}
			return_string[i] = '\0';
		}
		p = p->next;
	}
	return return_string;
	
}

//function to find the shortest word in the database
char * shortest_word(listword * head){
	char * shortest;
	listword * p;
	p = head;
	int min, lenght;
	min=20;
	while(p != NULL){
		lenght = strlen(p->word);
		if(lenght<min){
			min = lenght;
			//allocating memory for *shortest
			shortest = (char*)malloc(min*sizeof(char));
			int i;
			for(i = 0; i < min; i++){
				shortest[i] = p->word[i];
			}
			shortest[i] = '\0';
		}
		p = p->next;
	}
	return shortest;
}

//function to count an occurance of the word
//pointer called 'word' as a parameter of the function is a desired word whose occurrence is to be counted
int occurrence(listword * head, char * word){ 
	int n=0, j;
	listword * p;
	p = head;
	while(p != NULL){
		j = strcmp(p->word, word);
		if(j == 0){
			n++;
		}
		p = p->next;
	}
	return n;
}

//function to find the most occured word
char * most_occured(listword * head){	
    int k, i, len;
    int max = 0;
    char * tmp;
	listword * p;
	p = head;
	while(p != NULL){
		k = occurrence(head, p->word);
		if(k > max){
			max = k;
			len = strlen(p->word);
			//allocating memory for *tmp
			tmp = (char*)malloc(len*sizeof(char));
			for(i = 0; i < len; i++){
				tmp[i] = p->word[i];
			}
			tmp[i] = '\0';
		}
		p = p->next;
	}
	return tmp;
}

//function to find the least occured word
char * fewest_occured(listword* head){
	int i, k, len;
	int min = 0;
	char * tmp;
	listword * p;
	//to find proper value to assign to the variable min(the maximum number of times a word can occur)
	for(p = head; p != NULL; p = p->next){
		min++;
	}
	for(p = head; p != NULL; p = p->next){
		k = occurrence(head, p->word);
		if(k < min){
			min = k;
			len = strlen(p->word);
			//allocating memory for *tmp
			tmp = (char*)malloc(len*sizeof(char));
			for(i = 0; i <len; i++){
				tmp[i] = p->word[i];
			}
			tmp[i] = '\0';
		}
	}
	return tmp;
}

//function to write a text from database to file
void write_sth_to_file(listword * head, FILE * file){
	listword * p;
	p = head;
	while(p != NULL){
		fprintf(file, p->word);
		fprintf(file, " ");
		p = p->next;
	}
}

//function to print text which is in the database
void print_database(listword * head){
	listword * p;
	p = head;
	printf("   ");
	while(p != NULL){
		printf("%s ", p->word);
		p = p->next;
	}
	printf("\n");
}
//function to destroy a linked list which contains only one element
listword * destroy_first(listword * head){
	free(head);
	head = NULL;
	return head;
}
//function to destroy the last element of a linked list
listword * destroy_back(listword * head){
	listword * p;
	if(head == NULL){
		return head;
	}
	if(head->next==NULL){
		return destroy_first(head);
	}
	for(p = head; p->next->next != NULL; p = p->next);
	free(p->next);
	p->next = NULL;
	return head;
}

//function to destroy a linked list
listword * destroy(listword * head){
	while (head!=NULL) {
		head = destroy_back(head);
	}
}

//main function
int main(){
	int m;
	int n = 10;
	char looking[100];
	char *longest_one;
	char *shortest_one;
	char file_name[100];
	char *most_occured_word;
	char *least_occured_word;
	//the outputs of the program will be written into that file
	FILE *history;
	listword * head = NULL;
    history = fopen("history.txt", "a");
    if (history == NULL) {
    	printf("The file wasn't found\n");
	}
	
	while(n != 0){
		print_menu(head);
		printf("   enter your choice:");
		scanf("%d",&n);
		getchar();
		switch (n){
			case 1:
				printf("   Enter file path:\n");
				scanf("%s", file_name);
				head = file_input_to_database(head, file_name);
				print_database(head);
				
				break;
			case 2:
				printf("   type a text:\n");
				head = keyboard_input_to_database(head);
				printf("   your input:\n");
				print_database(head);
				break;
			case 3:
				longest_one = longest_word(head);
				printf("  the longest word is:");
				printf("%s\n", longest_one);
				fprintf(history, "the longest word is: %s;  ", longest_one);
				break;
			case 4:
				shortest_one = shortest_word(head);
				printf("   the shortest word is: %s\n",shortest_one);
				fprintf(history,"the shortest word is: %s;  ", shortest_one);
		        break;
		    case 5:
		    	printf("   enter a word to becounted its occurrence: ");
		    	gets(looking);
		    	m = occurrence(head, looking);
		    	printf("   the word '%s' is occured %d times.\n",looking, m);
		    	fprintf(history, "the word '%s' is occured %d times.;  ", looking, m);
		    	break;
		    case 6:
		    	most_occured_word = most_occured(head);
		    	printf("   the most occured word is: %s\n",most_occured_word);
		    	fprintf(history, "the most occured word is: %s;  ", most_occured_word);
		    	break;
		    case 7:
		    	least_occured_word = fewest_occured(head);
		    	printf("   the least occured word is: %s\n" ,least_occured_word);
		    	fprintf(history,"the least occured word is: %s;  ", least_occured_word);
		    	break;
		    case 8:
		    	{
		    		fclose(history);
		    		history = fopen("history.txt", "r");
		    		char c;
		    		c = fgetc(history);
    				while (c != EOF)
    					{
        					printf ("%c", c);
        					c = fgetc(history);
    					}
					fclose(history);
					history = fopen("history.txt", "a");	
				}
		    	
		    	break;
		} 
	}
	//to find the date and time
	time_t current_time = time(NULL);
	char* current_time_str = ctime(&current_time);
	current_time_str[strlen(current_time_str)-1] = '\0';
	
	
	fprintf(history, "\nDatabase:");
	write_sth_to_file(head, history);
    fprintf(history, "\nTime : %s\n\n\n", current_time_str);
	fclose(history);
	head = destroy(head);
	return 0;
}
	
