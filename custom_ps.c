#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(void){
	struct dirent *de;
	DIR *dr=opendir("/proc");
	int flag=1;

	if(dr==NULL){
		printf("Could not open /proc directory");
		return 0;
	}

	while((de=readdir(dr))!=NULL){
		char* name=de->d_name;
		for(int i=0;i<(int) strlen(name); i++){
			if (name[i] < '0' || name[i] > '9'){
				flag=0;
				break;
			}
		}
		if(flag==1){
			printf("%s\n", name);
		}
		else{
			flag=1;
		}
	}

	closedir(dr);
	return 0;
}