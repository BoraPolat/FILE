#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 1000
//*******************************************
struct item{                //Definition of item data type
	char word[30];
	char mean[30];
};
//*******************************************
int search(char w[])
{
	FILE *p;                  // p is a pointer to file
	p=fopen("E:\\dictionary.txt","r");
      //fopen opens dictionary.txt file located on drive E for reading. The
        address of beginning of file is assigned to p
	struct item x;
	while(fscanf(p,"%s%s",x.word,x.mean)!=EOF)
      //fscanf reads data from the file pointed by p until we reach to the
        end of file (EOF)
		if(strcmp(w,x.word)==0)
		{
			printf("\nFound! The meaning is: %s",x.mean);
			fclose(p);
			return 1;
		}
	fclose(p);
	return 0;
}
//*******************************************
void insert()
{
	struct item x;
	printf("\nEnter the new word and meaning:");
	scanf("%s%s",x.word,x.mean);
	if(search(x.word)==0)
	{
		FILE *p;
		p=fopen("E:\\dictionary.txt","a");
            // the file is opened for writing to the end (append)
		fprintf(p,"\n%s      %s",x.word,x.mean);
		fclose(p);
	}
}
//*******************************************
void display()
{
	FILE *p;
	p=fopen("E:\\Dictionary.txt","r");
	struct item x;
	while(fscanf(p,"%s %s",x.word,x.mean)!=EOF)
		printf("\n%s    %s",x.word,x.mean);
}
//*******************************************
void remove()
{
	char w[30];
	printf("\n What are you going to remove?");
	scanf("%s",w);
	int i=0;
	if(search(w)==1)
	{
		struct item temp[100];
		FILE *p;
		p=fopen("E:\\Dictionary.txt","r");
		while(fscanf(p,"%s %s",temp[i].word,temp[i].mean)!=EOF)  i++;
		fclose(p);
		p=fopen("E:\\Dictionary.txt","w");
		for(int j=0;j<i;j++)
			if(strcmp(w,temp[j].word)!=0)
				fprintf(p,"\n%s   %s",temp[j].word,temp[j].mean);
		fclose(p);
	}
}
//*******************************
void edit()
{
	struct item x;
	printf("\n What are you going to edit?");
	scanf("%s",x.word);
	int i=0;
	if(search(x.word)==1)
	{
		printf("\nWhat is the new meaning?");
		scanf("%s",x.mean);
		struct item temp[100];
		FILE *p;
		p=fopen("E:\\Dictionary.txt","r");
		while(fscanf(p,"%s %s",temp[i].word,temp[i].mean)!=EOF)
			i++;
		fclose(p);
		p=fopen("E:\\Dictionary.txt","w");
		for(int j=0;j<i;j++)
			if(strcmp(x.word,temp[j].word)==0)
				fprintf(p,"\n%s   %s",temp[j].word,x.mean);
			else
				fprintf(p,"\n%s   %s",temp[j].word,temp[j].mean);
		fclose(p);
	}
}
//*******************************************
int main()
{
	int choice;
	do
	{
	        printf("\n1) Search\n2) Insert\n3) Remove\n4) Edit\n5) Display\n6) Exit\nChoose(1-6):");
	        scanf("%d",&choice);
	        switch(choice){
		          case(1):char w[30];
			    printf("\nWhat do you wanna search?");
			    scanf("%s",w);search(w);break;
     	                        case(2):insert();break;
 	                        case(3):remove();break;
          	                        case(4):edit();break;
	                        case(5):display();break;
	                        case(6):break;
	                        default:printf("\nWrong Choice! Try Again...");
		        }
	}while(choice!=6);
}
