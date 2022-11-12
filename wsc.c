#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include "wsc.h"

void update_actual(void* file){

	FILE* fp = fopen(file, "r");
	int countlines = 0;
	if(fp == NULL) {
		printf("file error in actual\n");
		exit(errno);
	}
	
	while(!feof(fp)){
		countlines++;
		// check that the file is 16 lines long, exit if not
		if(countlines > 16){
			printf("too many names");
			exit(-1);
		}
		
		fgets(actual[countlines -1], NAMELEN, fp);
	
	}
	
	if(countlines < 16){
		printf("not enough elements");
		exit(-1);
	}
	fclose(fp);
	
	// uncomment for testing
	
	for(int i = 0; i < 16; i++){
		printf("%s", actual[i]);
	}
	

}	

void update_predictions(void* file){

	FILE* fp = fopen(file, "r");
	int countlines = 0;
	if(fp == NULL) {
		printf("file error in actual\n");
		exit(errno);
	}
	
	while(!feof(fp)){
		countlines++;
		// check that the file is 16 lines long, exit if not
		if(countlines > 16){
			printf("too many names");
			exit(-1);
		}
		
		fgets(predictions[countlines -1], NAMELEN, fp);
	
	}
	
	if(countlines < 16){
		printf("not enough elements");
		exit(-1);
	}
	fclose(fp);
	
	// uncomment for testing
	 
	for(int i = 0; i < 16; i++){
		printf("%s", predictions[i]);
	}
	

}	

int calculate_p_gs(){
	//calculate normal points
	
	for(int i = 0; i < 16; i++){
		if(i%2 == 0){
			if((strcmp(predictions[i], actual[i]) == 0) || (strcmp(predictions[i], actual[i+1]) == 0)){
				points = points + P_GS;
			}	
		} else { // i is odd
			if((strcmp(predictions[i], actual[i]) == 0) || (strcmp(predictions[i], actual[i-1]) == 0)){
				points = points + P_GS;
			}
		}	
	}
	
	for(int i = 0; i < 16; i = i + 2){
		if((strcmp(predictions[i], actual[i]) == 0) && (strcmp(predictions[i], actual[i]) == 0)){
			points = points + P_BONUS;
		}
	}
	return points;
}

int main(int argc, char* argv[]){

	update_actual(argv[1]);
	printf("\n###############################\n");
	update_predictions(argv[2]);

	int total_p_gs = calculate_p_gs();
	printf("\ngroup stage score: %d/32\n", total_p_gs);

exit(1);
}
