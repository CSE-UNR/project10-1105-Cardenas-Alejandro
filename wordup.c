//Author:Alejandro Cardenas
//Date: 5/03/2025
//Purpose: wordup


#include <stdio.h>
#define GUESSES 6
#define WORD_LEN 5
#define FILENAME "word.txt"

void file_intake(FILE* fptr, char word[]);
void scan_guess(char guess[]);
int valid_entry(char guess[]);
int word_len(char s[]);
int guess_word(char a[], char b[]);
void input_case(char s[]);


int main(){
//** handles the file
FILE* fptr;
fptr = fopen(FILENAME,"r");
	if(fptr == NULL){
		printf("Failed to find file!\n");
		return 0;
	} //read the file
char word[WORD_LEN+1];
file_intake(fptr,word); 
fclose(fptr);				
//** relies on the char[word]; array

char guesses[GUESSES][WORD_LEN+1];
char display[WORD_LEN+1];
int used_let[WORD_LEN] = {0};

	int attempt_count = 0, won =0;		//declaring variabes
	
while(attempt_count < GUESSES && !won) {		//game loop
		char guess[WORD_LEN+1];

		
	printf("Attempt #%d: ", attempt_count+1);		
	scan_guess(guess);	
	input_case(guess);
					//take guesses
		if(valid_entry(guess) == 0){
			printf("\nInvalid entry. "); 
		continue;
			}
		for (int i = 0; i <= WORD_LEN;i++){		//store guesses
			guesses[attempt_count][i] = guess[i];
			}
		for (int a =0; a < WORD_LEN; a++) {
				display[a] = ' ';
				}

							//game loop
	
	for (int element = 0; element < WORD_LEN; element++){	
				//check for letters in correct positon
			if(guess[element] == word[element]) {
			display[element] = guess[element] - 32; 
				used_let[element] = 1;
			} 
			
		}
		for(int count = 0; count < WORD_LEN; count++){
			if (guess[count] != word[count]) {
				for(int j =0; j < WORD_LEN; j++){
					if(!display[j] && guess[count] == word[j]) {
					used_let[count] = '^';

					break;
		    } used_let[count] = ' ';
		  }
		}
	      }	int correct_letters = 0;
	      	for(int c = 0; c < WORD_LEN; c++){
	      		if(guess[c] == word[c]) {

	      			correct_letters++;
	      			}
	      		}
	      	
	      		if(guess_word(guess, word)){
	won =1;}	


	printf("\nGuess %d: \n", attempt_count + 1);
		for (int i = 0; i < WORD_LEN; i++){
			printf("%c", display[i]);
			
		} 
			for(int i = 0; i < WORD_LEN; i++){
				printf("%c", used_let[i]);
				} 
			printf("\n");	      		
		attempt_count++;
} 
if (won) {
printf("\ngame over!");  
//end of while loop

}	    
		
  
		printf("\n");
  
	return 0;
}
void file_intake(FILE* fptr, char word[]){			//read the word into the word array
		fscanf(fptr, "%5s", word);
		word[WORD_LEN] = '\0';
}
void scan_guess(char guess[]){					//prompt user for guess
		scanf("%5s", guess);
		guess[WORD_LEN] = '\0';
}
	 
int word_len(char s[]){
	int size =0;
	while (s[size] != '\0'){
	size++;
	}
	return size;
}
int valid_entry(char guess[]){		//check if guess is 5 characters long and alphabetical char
	if (word_len(guess) != WORD_LEN){
		return 0;
		}
	for(int a = 0; a < WORD_LEN; a++){
		if(!((guess[a] >= 'a' && guess[a] <= 'z') || (guess[a] >= 'A' && guess[a] <= 'Z'))){
		return 0;
		}
	}
	return 1;
}
int guess_word(char a[], char b[]){
 for (int p = 0; p < WORD_LEN; p++){
 	if(a[p] != b[p]){ return 0;}
 }
 return 1;
}
void input_case(char s[]){
for (int i =0; s[i] != '\0'; i++){
	if (s[i] >= 'A' && s[i] <= 'Z') {
	s[i] += 32;
	}
}
}
