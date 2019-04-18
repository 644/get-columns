#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	if(isatty(fileno(stdin))){
		return 1;
	}
	
	int i=0, space_count=0, skip_print=0, empty_cols=6;
	char pipe[65536];
	while((pipe[++i] = getchar()) != EOF);
	
	for(int j=0; j<i; ++j){
		if(pipe[j] == '\n'){
			while(empty_cols > 0){
				printf("\"\",");
				--empty_cols;
			}
			space_count=0;
			empty_cols=6;
			continue;
		}
		
		if(pipe[j] == ' '){
			++space_count;
			continue;
		}
		
		if(skip_print > 0){
			--skip_print;
			continue;
		}
		
		if(pipe[j] == 'O' && pipe[j+1] == 'i'){
			skip_print=2;
			continue;
		}
		
		if(pipe[j] == 'B' && pipe[j+1] == 'r'){
			skip_print=4;
			continue;
		}
		
		if(pipe[j] == 'O' && pipe[j+1] == 't'){
			skip_print=4;
			continue;
		}
		
		while(space_count > 18){
			printf("\"\",");
			space_count -= 18;
			--empty_cols;
		}
		
		space_count=0;
		
		if(pipe[j-1] == ' '){
			printf("\"");
		}
		
		if(isdigit(pipe[j]) || pipe[j] == '.'){
			putchar(pipe[j]);
			if(pipe[j+1] == ' ' || pipe[j+1] == '\n'){
				printf("\",");
				--empty_cols;
			}
		}
		else{
			if((pipe[j] == 'G' || pipe[j] == 'g') && pipe[j+1] == 'a' && pipe[j+2] == 'l'){
				printf("gallons\",");
				skip_print=6;
				--empty_cols;
			}
			else if((pipe[j] == 'B' || pipe[j] == 'b') && pipe[j+1] == 'a' && pipe[j+2] == 'r'){
				printf("barrels\",");
				skip_print=6;
				--empty_cols;
			}
		}
	}
	
	return 0;
}
