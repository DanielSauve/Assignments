#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
	char word[]="paintings";
	char guessed[]="*************************";
	int guesses=10;
	char guess, garb;
	char word2[]="_________";
	bool game=true;
	int i=0,k=0;
	while (game){
		i=0;
		k=0;
		printf("Wrong guesses remaining: %i\n", guesses);
		printf("Word: %s\n",word2);
		printf("Please enter a letter you would like to guess: ");
		scanf("%c%c",&guess,&garb);
		while (guessed[i]!='*'){
			if (guess==guessed[i]){
				printf("You have already guessed %c\n",guess);
				break;
			}
			i++;
		}
		if (guess==guessed[i]) continue;
		guessed[i]=guess;
		i=0;
		while (word[i]!='\0'){
			if (guess==word[i]){
				word2[i]=guess;
				k++;
			}
			i++;
		}
		i=0;
		while (word2[i]!='\0'){;
			if (word2[i]=='_'){
				game=true;
				break;
			}
			else game=false;
			i++;
		}
		if (k==0) guesses--;
		if (guesses==0) break;
	}
	if (game==false) printf("Congratulations, you won, the word was %s\n", word);
	else printf("You ran out of guesses try again\n");
	return 0;
}
