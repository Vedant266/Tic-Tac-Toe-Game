#include <stdio.h>

void printBoard(char numbers[]);
int checkResponse(int response);
int isValid(int response, char numbers[]);
int checkWin(char numbers[], int status);
int checkDraw(char numbers[], int status);

int main(){

char numbers[10] = {'1','2','3','4','5','6','7','8','9'}; 
int status = -1;
int player;
int response;;

printf("\nTic Tac Toe Game\n\n");

printBoard(numbers);

for(int i = 1; status == -1; i++){
    if(i % 2 == 0){
        player = 1;
    }
    else{
        player = 2;
    }

    char mark = (player == 1) ? 'O' : 'X';

    printf("\nEnter Number You Want to Replace with %c : ", mark);
    scanf("%d", &response);
    printf("\n");

    if(response == 0){
        printf("Thanks For Playing");
        break;
    }

    if(response > 9 || response < 0){
        response = checkResponse(response);
    }
    else if (numbers[response - 1] == 'X' || numbers[response - 1] == 'O'){
        response = isValid(response, numbers);
    }
    
    numbers[response - 1] = mark;

    printBoard(numbers);
    status = checkWin(numbers, status);

}

if(status == 1){
    printf("\nPlayer 1 Won!\n\n");
}
if(status == 2){
    printf("\nPlayer 2 Won!\n\n");
}
if(status == -2){
    printf("\nGame Drawn!\n\n");
}

 return 0;
}

void printBoard(char numbers[]){
printf("     |     |        \n");
printf("  %c  |  %c  |  %c     \n",numbers[0],numbers[1],numbers[2]);
printf(" ____|_____|_____\n");
printf("     |     |        \n");
printf("  %c  |  %c  |  %c      \n",numbers[3],numbers[4],numbers[5]);
printf(" ____|_____|_____\n");
printf("     |     |        \n");
printf("  %c  |  %c  |  %c     \n",numbers[6],numbers[7],numbers[8]);
printf("     |     |     \n");
}

int checkResponse(int response){
    printf("Please Enter Valid Number : ");
    scanf("%d", &response);

    if(response > 9 || response < 1){
        checkResponse(response);
    }
    else{
        return response;
    }
}

int isValid(int response, char numbers[]){
    printf("Number Already Replaced Please Choose Other : ");
    scanf("%d", &response);

    if(numbers[response - 1] == 'X' || numbers[response - 1] == 'O'){
        isValid(response, numbers);
    }
    
    else{
        return response;
    }
}

int checkWin(char numbers[], int status){
    if(numbers[0] == 'X' && numbers[1] == 'X' && numbers[2] == 'X'){
        return status + 2;
    }
    else if(numbers[0] == 'O' && numbers[1] == 'O' && numbers[2] == 'O'){
        return status + 3;
    }
    else if(numbers[0] == 'X' && numbers[4] == 'X' && numbers[8] == 'X'){
        return status + 2;
    }
    else if(numbers[0] == 'O' && numbers[4] == 'O' && numbers[8] == 'O'){
        return status + 3;
    }
    else if(numbers[0] == 'X' && numbers[3] == 'X' && numbers[6] == 'X'){
        return status + 2;
    }
    else if(numbers[0] == 'O' && numbers[3] == 'O' && numbers[6] == 'O'){
        return status + 3;
    }
    else if(numbers[1] == 'X' && numbers[4] == 'X' && numbers[7] == 'X'){
        return status + 2;
    }
    else if(numbers[1] == 'O' && numbers[4] == 'O' && numbers[7] == 'O'){
        return status + 3;
    }
    else if(numbers[2] == 'X' && numbers[5] == 'X' && numbers[8] == 'X'){
        return status + 2;
    }
    else if(numbers[2] == 'O' && numbers[5] == 'O' && numbers[8] == 'O'){
        return status + 3;
    }
    else if(numbers[2] == 'X' && numbers[4] == 'X' && numbers[6] == 'X'){
        return status + 2;
    }
    else if(numbers[2] == 'O' && numbers[4] == 'O' && numbers[6] == 'O'){
        return status + 3;
    }
    else if(numbers[3] == 'X' && numbers[4] == 'X' && numbers[5] == 'X'){
        return status + 2;
    }
    else if(numbers[3] == 'O' && numbers[4] == 'O' && numbers[5] == 'O'){
        return status + 3;
    }
    else{
        status = checkDraw(numbers, status);
        return status;
    }
}

int checkDraw(char numbers[], int status){
    for(int i = 0; i < 9; i++){
        if(numbers[i] != 'X' && numbers[i] != 'O'){
            status = -1;
            break;
        }
        else{
            status = -2;
        }
        
    }   
    return status;
}