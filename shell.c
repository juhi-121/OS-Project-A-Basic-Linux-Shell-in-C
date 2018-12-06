#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<string.h>
#include<signal.h>
#define max 100
int main(int argc,char *argv[])
{
	char *x,pwd[100],*st;
	system("say welcome muggle");
	system("xcowsay WELCOME!!!");
// 	getcwd(pwd,sizeof(pwd));

	while(1)
	{
		int status,i,c;
//		printf("%s",pwd);
		system("pwd");
		x=readline("$ ");
		if(strlen(x)>0)  //HISTORY
		add_history(x);
		
	/*	if(!strcmp(x,"clls"))
		system("clear");*/
		argv[0]=strtok(x," ");//PARSING
//		printf("%s",argv[0]);
		for(i=1;i<max;i++)
		{
			argv[i]=strtok(NULL," ");
		}
//	printf("In %s\n", argv[0]);
		if(!strcmp(argv[0],"exit"))
		break;
		if(!strcmp(argv[0],"goto"))
		{
	//	printf("hey");
			if(chdir(argv[1]) == 0) 
			{
			    getcwd(pwd, sizeof(pwd));
			//    printf("In %s\n", pwd);
			}
			else
				printf("Directory not found\n");
		}
		else
		{
//		printf("%s",argv[1]);
			pid_t pid,wpid;
			pid=fork();
			if(pid<0)
			{
				perror("forking error");
				exit(1);
			}
			if(pid==0)		//CHILD PROCESS
//		char *args[]={x,NULL};
		    {
	//		if(strcmp(argv[0],"exit"))
				if(!strcmp(x,"cls"))
				system("clear");

				else if(execvp(*argv,argv)==-1)
				perror("nope.");
				exit(1);
			
			}
			else				//PARENT PROCESS
			{
				
				wpid=waitpid	(pid,&status,WUNTRACED);

			}
		}
	}
}




