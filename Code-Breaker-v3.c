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

/* function to generate and return random code array */
int * codegerate(int codeDigitInt){

	int address = 0;
	static int codeList[10];

	for(int count = 0 ; count < codeDigitInt ; count ++){
		srand(time(NULL));
		address = rand()%lenList;
		codeList[count] = numList[address];
		printf("%d", codeList[count]);
		takeaway(address);
	}
	printf("\n[INFO] Code Generated\n");

	return codeList;
}

int main(void){

//START PHASE//
	printf("Codebreaker\nPress Enter to Start");
	//function to press enter;
	getchar();

//CHOOSE DIGIT//
	char codeDigit[2];
	int *codeList;
	int codeDigitInt;

	printf("\n%s", "Input Digits between 1 and 10 to Play: ");

	/*foolproof system:*/
	scanf("%s", codeDigit);
	codeDigitInt = atoi(codeDigit);
	while( codeDigitInt >10 || atoi(codeDigit) <1 ){
		printf("\n[WRONGING] Please Input Digits between 1 and 10.\n");
		scanf("%s", codeDigit);
		codeDigitInt = atoi(codeDigit);
	}
	// codegrate code
	codeList = codegerate(codeDigitInt);
	
//INPUT CODE//
	char result[codeDigitInt];
	int A = 0, B = 0;
	for(int i = 0; i < codeDigitInt; i++){
		result[i] = 'N';
	}
	char user[codeDigitInt];
	int userInt;
	int userNum[codeDigitInt];

	while(A != codeDigitInt){
		A = 0;
		B = 0;
		printf("Input %d-digit Number:",codeDigitInt);
		scanf("%s", user);

		unsigned int length = strlen(user);
		userInt = atoi(user);
		while( userInt < 1 || length != codeDigitInt ){
			printf("%s%d%s", "[WRONGING] Please Input a ", codeDigitInt, "-digit Number\n");
			printf("Input %d-digit Number: ",codeDigitInt);
			scanf("%s", user);
			length = strlen(user);
			userInt = atoi(user);
		}

		for(int i = 0; i < codeDigitInt; i++){
			char temp[] = {user[i]};
			userNum[i] = atoi(temp);
			printf("%d ",userNum[i]);
		}

		//CHECK CODE//
		for(int i = 0; i < codeDigitInt; i++){
			for(int n = 0; n < codeDigitInt; n++){
				if(codeList[i] == userNum[i]){
					result[i] = 'A';
					break;
				}
				else if(userNum[i] == codeList[n]){
					result[i] = 'B';
					break;
				}
				else{
					result[i] = 'N';
				}
			}//end n forloop
		}//end i forloop

		//COUNT A
		for(int a=0 ; a < codeDigitInt; a++){
			if(result[a]=='A'){
				A += 1;
			}
			else if(result[a]=='B'){
				B += 1;
			}
		}

		//SHOW ANSWER
		printf("--- %dA%dB ---\n",A,B);

	}//end A!=codeDigitInt  while

	//THE END
	printf("------- YOU WIN! -------\n");
	return 0;
}