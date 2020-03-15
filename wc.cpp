#include <stdio.h>
#include <stdlib.h>

void CharCount(FILE *f1)  
{
    char ch;  
    int charCounts=0;
    while((ch=fgetc(f1))!=EOF)
    charCounts++;
    printf("CharCount is %d \n",charCounts);
    printf("press to continue\n");
    getchar();
    getchar();
} 

void LineCount(FILE *f2) 
{
    char ch;
    int lineCounts=1;    
    while((ch=fgetc(f2))!=EOF)
    {
        if(ch=='\n')  
        lineCounts++;   
    }
    printf("LineCount is %d \n",lineCounts);
    printf("press to continue\n");
    getchar();
    getchar();
}

void WordCount(FILE*f3)
{       
    char ch;
    int wordCounts=0; 
    while((ch=fgetc(f3))!=EOF) 
	{
        if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z' || ch >= '0'&&ch <= '9')
        {
            while (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z' || ch >= '0'&&ch <= '9' || ch == '_')
            {
                ch = fgetc(f3);
            }
            wordCounts++;
            ch = fgetc(f3);
        }
    }
    printf("WordCount is %d \n",wordCounts);
    printf("press to continue\n");
    getchar();
    getchar();
}

void Home()
{
    system("cls");
    printf("***********************************\n");
    printf("Welcome to use WC.ese\n");
    printf("Please choose what you want to achieve:\nc:CharCount\nl:LineCount\nw:WordCount\n");
    printf("enter q exit\n");
    printf("***********************************\n");
}

int main()
{
   FILE *file=NULL;
   char order=0;
   do
   {    
        if((file= fopen("1.txt","r"))==0)
    {
    	printf("can't find the file\n");
    	exit(0);
	}
        Home();
        scanf("%c",&order);
        switch(order-'a')
        {
        	case 2:
        	{
        	    CharCount(file);
				break;	
			}
			
			case 11:
			{
				LineCount(file);
				break;
			}
			
			case 22:
			{
				WordCount(file);
				break;
			}
			
			case 16:
			{
				printf("thinks to use!\n");
				printf("press to continue\n");
				getchar();
				getchar();
				break;
			}
			default:
			{
				printf("order error!");
				printf("press to continue\n");
				getchar();
				getchar();
				break;
			}
		} 
		fclose(file);
   }while(order!='q');
   return 0;
}
