#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*Stage 1:
  Start Title !
  Digit Input !
  Generate Code !
  Check Code !
  Print Result !*/
/*Stage 2:
  Extend amount of digit to all avaliable*/

//functions://
int numList[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int lenList = 10;
void takeaway(int temp){
	lenList--;
	for(int i = temp; i <= lenList; i++){
		numList[i] = numList[(i+1)];
	}
}

int main(void){

//START PHASE//
	printf("Codebreaker\nPress Enter to Start");
	//need function to press enter;

//CHOOSE DIGIT//
	char codeDigit[2];
	printf("\n%s", "Input Digits to Play between 1 and 10:");
	scanf("%s", codeDigit);
	printf("codeDigit: %s\n atoi(): %d\n",codeDigit, atoi(codeDigit) );
	while(1 > atoi(codeDigit) || 10 < atoi(codeDigit)){
		printf("\nPlease Enter a Number between 1 and 10\nInput Digit:");
		codeDigit[0] = 0;
		codeDigit[1] = 0;
		scanf("%s", codeDigit);
	}
	int codeDigitInt = atoi(codeDigit);
	printf("%d\n", codeDigitInt);
	/*foolproof system:*/

//GENERATE CODE//
	int count = 0;
	int temp = 0;
	int codeList[codeDigitInt];
	while(count < codeDigitInt){
		srand(time(NULL));
		temp = rand()%lenList;
		codeList[count] = numList[temp];
		printf("%d", codeList[count]);
		takeaway(temp);
		count++;
	}
	printf("%s", "Code Generated");
	/*for(int i = 0; i < codeDigitInt; i++){
		printf("%d", codeList[i]);
	}*/

//INPUT CODE//
	char result[codeDigitInt];
	int A = 0, B = 0;
	for(int i = 0; i < codeDigitInt; i++){
		result[i] = 'N';
	}
	char user[codeDigitInt];
	int userNum[codeDigitInt];
	while(A != codeDigitInt){
		printf("\n%s%d%s", "Input ", codeDigitInt, "-digit Number:");
		scanf("%s", user);

		unsigned int length = strlen(user);
		while(length != 4 || !atoi(user)){
			printf("%s%d%s", "Please Input a ", codeDigitInt, "-digit Number");
			printf("\n%s", "Input Number:");
			scanf("%s", user);
			length = strlen(user);
		}
		for(int i = 0; i < codeDigitInt; i++){
			userNum[i] = atoi(user[i]);
		}
//CHECK CODE//
		for(int i = 0; i < codeDigitInt; i++){
			for(int n = 0; n < codeDigitInt; n++){
				if(codeList[i] == userNum[i]){
					result[i] = 'A';
				}
				else if(userNum[i] == codeList[n]){
					result[i] = 'B';
				}
				else{
					result[i] = 'N';
				}
			}
			
		}
		/*if(codeList[0] == userNum / 1000){
			result[0] = 'A';
		}
		else if(userNum / 1000 == codeList[1] || userNum / 1000 == codeList[2] || userNum / 1000 == codeList[3]){
			result[0] = 'B';
		}
		else{
			result[0] = 'N';
		}
		if(codeList[1] == userNum / 100 % 10){
			result[1] = 'A';
		}
		else if(userNum / 100 % 10 == codeList[0] || userNum / 100 % 10 == codeList[2] || userNum / 100 % 10 == codeList[3]){
			result[1] = 'B';
		}
		else{
			result[1] = 'N';
		}
		if(codeList[2] == userNum / 10 % 10){
			result[2] = 'A';
		}
		else if(userNum / 10 % 10 == codeList[0] || userNum / 10 % 10 == codeList[1] || userNum / 10 % 10 == codeList[3]){
			result[2] = 'B';
		}
		else{
			result[2] = 'N';
		}
		if(codeList[3] == userNum % 10){
			result[3] = 'A';
		}
		else if(userNum % 10 == codeList[0] || userNum % 10 == codeList[1] || userNum % 10 == codeList[2]){
			result[3] = 'B';
		}
		else{
			result[3] = 'N';
		}*/
		//universalize, functionalize
		printf("%s", result);
		
		for(int i = 0; i < codeDigitInt; i++){
			if(result[i] == 'A'){
				A++;
			}
			else if(result[i] == 'B'){
				B++;
			}
		}
		printf("%dA %dB", A, B);
	}//end of main while
	return 0;
}
