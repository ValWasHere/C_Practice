#include <stdio.h>
#include <ctype.h>

#define QUESTION_LEN 256
#define OPTION_LEN 256


int main(){
    int mode;

    printf("\n======================================================\n");
    printf("                C QUIZ BUILDER                        \n");
    printf("======================================================\n");
    printf("1. Create Quiz\n");
    printf("2. Take Quiz\n");
    printf("Choose 1 or 2: ");
    scanf("%d", &mode);

    switch(mode){
        case 1: 
        {
            int numQuestions;
            printf("\nHow many questions would you like to make? ");
            scanf("%d", &numQuestions);
            getchar();
            FILE *file = fopen("quiz.txt", "w");
            if(file == NULL){
                printf("Error opening file! Time to die.");
                return 1;
            }
            
            fprintf(file, "%d\n", numQuestions);

            char question[QUESTION_LEN];
            char optionA[OPTION_LEN], optionB[OPTION_LEN], optionC[OPTION_LEN], optionD[OPTION_LEN];
            char answer;//a, b, c, d

            for(int i = 0; i < numQuestions; i++){
                
                printf("\nQuestion %d\n", i + 1);

                printf("Enter Question: \n");
                scanf("%[^\n]", question);
                getchar();

                printf("Enter Option A: \n");
                scanf("%[^\n]", optionA);
                getchar();

                printf("Enter Option B: \n");
                scanf("%[^\n]", optionB);
                getchar();

                printf("Enter Option C: \n");
                scanf("%[^\n]", optionC);
                getchar();

                printf("Enter Option D: \n");
                scanf("%[^\n]", optionD);
                getchar();

                printf("Enter correct answer (A, B, C, D): \n");
                scanf("%c", &answer);
                getchar();

                fprintf(file, "%s\n", question);
                fprintf(file, "A. %s\n", optionA);
                fprintf(file, "B. %s\n", optionB);
                fprintf(file, "C. %s\n", optionC);
                fprintf(file, "D. %s\n", optionD);
                fprintf(file, "%c\n", toupper(answer));
            }
            fclose(file);
            printf("You're done\n");
            break;
        }
        
        case 2: {
            
            FILE* file = fopen("takeQuiz.txt", "r");
            if(file == NULL){
                printf("AH, SHIIIIII something bad happened dawg. SUM AIN'T OPEN CORRECTLY....\n");
                return 1;
            }

            
            break;
        }
        default:{
            
        }
    }




    return 0;
}
