#include "hide_pswd.h"

int getch()  //不使用
{  
	int c=0;  
	struct termios org_opts, new_opts;  
	int res=0;  

	res=tcgetattr(STDIN_FILENO, &org_opts);  
	assert(res==0);  
	memcpy(&new_opts, &org_opts, sizeof(new_opts));  
	new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK \
		| ECHONL | ECHOPRT | ECHOKE | ICRNL);  
	tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);  
	c=getchar();  
	res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);  
	assert(res==0);  
	return c;  
}  

char* get_pswd(char *pcPWD)
{
	int ch=0,i=0;
	for(i=0;i<20;){
		ch=getch();
		if(ch==-1){
			continue;
		}
		
		if((ch == 127 || ch == 8) && i>0){
			putchar('\b');	
			putchar(' ');	
			putchar('\b');	
			i--;			
		}
		else if(ch=='\n'){
			pcPWD[i]='\0';
			putchar('\n');
			return pcPWD;
		}
		else if(i==0 &&(ch==127 ||ch == 8)){
			printf("\a");
		}
		else if(i<19){
			pcPWD[i]=(char)ch;
			putchar('*');
			i++;
		}
		else{
			printf("\a");
		}
	}
	return pcPWD;
}
