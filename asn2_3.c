/*Authors : Mahesh.N.Kumar and Akarsh

*Functions and Parameters: void Log(char *,char *,char *);
						   int FileProcess(char *,char*,char *,char *);
                           int Access(char *);
                           void Logo(char *);
                           void LogFun(char *l);

*Description: Log functions logs the activities of the program to a Log file.
              File Process will process the file for validation of username and Password.
              Access function checks whether the file exists or not
			 
*Returns: FileProcess will return 1 after successful operations else returns 0
          Access returns 1 if file exists, 0 otherwise.
          
*/

#include<stdio.h>
#include<time.h>
#include<unistd.h>

void Log(char *,char *,char *);
int FileProcess(char *,char*,char *,char *);
int Access(char *);
void Logo(char *);
void LogFun(char *l);

int main(int argc, char **argv)
{
	char name[20],pass[10];
	int i=0;
  	char *fname,*lname;
  	int c;

	while((c=getopt(argc,argv,"f:l:"))!=-1)
	{
  	  	switch(c)
  	  	{
  			case 'f': fname=optarg;
				  break;

			case 'l': lname=optarg;
				  break;

			default : printf("Invalid Arguments");
				  printf("\n\n\n-----------------------------------------------------\n\n\n");
			          return 1;
	   	}

	 }
	
	
	
	if(argc>=3)
	{
        	if(Access(fname)==1)
       		{
	
       
      			printf("\n\n\n----------------------WELCOME-----------------------\n\n\n");

			while(i==0)
		   	{   

 
  			 	printf("Enter User Name\n");
  			 	scanf("%s",name);
  
 			 	printf("\nEnter Password\n");
 			 	scanf("%s",pass);
	
		        	Log(name,pass,lname);
    				i=FileProcess(name,pass,fname,lname);
      			}
       
       		}
       		else
       		{
     			printf("\n\nFile Named %s Doesn't Exist\n\n",fname);
			printf("\n\n\n-----------------------------------------------------\n\n\n");
		     	return 1;
	        }
      
       
   	}
   
	else
	{
	  	printf("\nInvalid Arguments..!!!\n\nInput Format: ./a.out -f <filename> -l <logfile>\n");
		printf("\n\n\n-----------------------------------------------------\n\n\n");
	} 
	return 0;
}

int FileProcess(char *name,char *pass,char *fname,char *lname)
{
	LogFun(lname);
	FILE *fp;
	int i=0;
	int j,k;
	static count=0;
	char line[40],username[20],password[10];


	
	fp=fopen(fname,"r");
  
	do
  	{
	  	j=0;
		k=0;
		fscanf(fp,"%s",line);
     	
     		while(line[j]!=',')
		{
			username[j]=line[j];
			j++;
		}	
     		username[j]='\0';
     	
		j++;
    		
		while(line[j]!='\0')
		{
			password[k]=line[j];
			j++;
			k++;
		}
		
		password[k]='\0';
			
	    
      		if((strcmp(name,username)==0)&&(strcmp(pass,password)==0))
	  	{
        	        printf("\nWelcome %s \n\n",username);	
			printf("-------------------Have A Nice Day------------------\n\n\n");
		  	Logo(lname);
			i=1;
		  	break; 
		  
		}
		
	  	
	  
	}while(getc(fp)!=EOF);
  
	if(getc(fp)==EOF)
  	{
    		printf("\nYou have entered an Invalid Username/Password\n\n");
    		count++;
    		rewind(fp);
  	

  		if(count>=3)
  		{
			printf("----------------------------------------------------\n");    			
			printf("\nSorry Maximum Trials Exceeded..!!!\n\n");
			Logo(lname);
     			i=1;
  		}
  		else
  		{
			printf("------------------PLEASE TRY AGAIN------------------\n\n\n");
	  	}
	}
  	fclose(fp);
  	return i;
  	
  
  
}

void Log(char *n,char *p,char *l)
{
	FILE *fp;
 	
 	time_t rawtime;
  	struct tm * timeinfo;
  
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
	 
	fp=fopen(l,"a");
	 
	fprintf(fp, "\nInput Taken: %s  %s  %s",n,p,asctime (timeinfo) );
	 
	fclose(fp);
	 
}  

void Logo(char *l)
{
	FILE *fp;
 	
 	time_t rawtime;
  	struct tm * timeinfo;
  
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
	 
	fp=fopen(l,"a");
	 
	fprintf(fp,"\nOutput Displayed: %s",asctime (timeinfo) );
	 
	fclose(fp);
	 
} 

void LogFun(char *l)
{
	FILE *fp;
 	
 	time_t rawtime;
  	struct tm * timeinfo;
  
  	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
	 
	fp=fopen(l,"a");
	 
	fprintf(fp,"\nFile Processing: %s",asctime (timeinfo) );
	 
	fclose(fp);
	 
}   


int Access(char *fname)
{
	if(access(fname,F_OK)!=-1)
	{
		return 1;
	}
	else
	{
		
		return 0;
	}
}


