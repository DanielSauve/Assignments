#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct vote {
	int voted;
	char name[100];
}votes[10];

int main(int argc, char* argv[]){
	FILE *file=fopen(argv[1],"r");
	FILE *output=fopen(argv[2], "w");
	char line[100]="";
	int garb;
	char c;
	int i=0;
	while (c!='\n')
	{
		fscanf(file,"%c", &c);
		line[i]=c;
		i++;
	}
	fprintf(output,"Result of Poll:%s\n",line);
	i=0;
	int j=0;
	int num=-1;
	c='\\';
	while (garb!=-1){
	fscanf(file, "%i", &garb);
		if (garb!=-1){
			while (c!='\n'){
				fscanf(file,"%c",&c);
				votes[i].name[j]=c;
				j++;
			}
			//fscanf(file,"%s", votes[i].name);
		}
		votes[i].name[j-1]='\0';
		i++;
		num++;
		c='\\';
		j=0;
	}
	i=0;
	while (i!=10){
		votes[i].voted=0;
		i++;
	}
	while(!feof(file)){
		fscanf(file,"%i",&i);
		if(!(i>num))
			votes[i-1].voted++;
		else
			continue;
	}
	i=0;
	while(i<num)
	{
		fprintf(output,"%s:\t%i\n",votes[i].name,votes[i].voted);
		i++;
	}
	return 0;
}
