#include "stack.h"
#include "maze.h"
#include "string.h"
#include <stdio.h>
#include <limits.h>

bool isClosingBracket(char bracket);
bool isOpeningBracket(char bracket);
bool arePaired(char openingbracket, char closingbracket);
int char_print (FILE *fp, const void * elem);


bool balanced_expression(const char *expr, int *pos, bool verbose){

    Status flag=OK;
    Stack *stack=NULL;
    char bracket;
    int length;

    length=strlen(expr);

    if(!expr || !pos){
        return false;
    }

    fprintf(stdout, "Checking: %s\n", expr);

    if(!(stack=stack_new())){
        return ERROR;
    }

    for(*pos=0; *pos<length && flag==OK ;(*pos)++){

        if(isOpeningBracket(expr[*pos])==true && verbose==true){

            flag=stack_push(stack, (void *)&expr[*pos]);
            stack_print(stdout, stack, char_print);

        }
        else if(isOpeningBracket(expr[*pos])==true && verbose==false){   

            flag=stack_push(stack, (void *)&expr[*pos]);
            
        }
        else if((isClosingBracket(expr[*pos]))==true && verbose==true && !stack_isEmpty(stack)){
            bracket=*(char *)stack_pop(stack);
            if(arePaired(bracket, expr[*pos])==false){
                flag=ERROR;
                break;
            }
            stack_print(stdout, stack, char_print);

        }
        else if((isClosingBracket(expr[*pos]))==true && verbose==false && !stack_isEmpty(stack)){
            bracket=*(char *)stack_pop(stack);
            if(arePaired(bracket, expr[*pos])==false){
                flag=ERROR;
                break;
            }

        }
        else if(stack_isEmpty(stack) && (isClosingBracket(expr[*pos]))){
            flag=ERROR;
        }
    
    }

    if(stack_isEmpty(stack)==false){
        flag=ERROR;
    }

    stack_free(stack);

    if(flag==OK){
        return true;
    }
    else{
        return false;
    }
}



bool isClosingBracket(char bracket){


    if(!bracket){
        return ERROR;
    }

    if(bracket == ']' || bracket == '}' ||bracket == ')'){
        return true;
    }


    return false;


}




bool isOpeningBracket(char bracket){

    if(!bracket){
        return ERROR;
    }

    if(bracket == '[' || bracket == '{' ||bracket == '('){
        return true;
    }


    return false;

}


bool arePaired(char openingbracket, char closingbracket){

    if(!openingbracket || !closingbracket){
        return false;
    }

    if((openingbracket=='('&& closingbracket== ')') || (openingbracket=='['&& closingbracket== ']') || (openingbracket=='{'&& closingbracket== '}')){
        return true;
    }


    return false;
}

int char_print (FILE *fp, const void * elem) {

    char *charr=NULL;
    
    if (!fp || !elem) {
        return ERROR;
    }

    charr = (char*)elem;

    return fprintf (stdout, "%c ", *charr);

}


int main(int argc, char *argv[]){


    char *str;
    bool verbose=false;
    int pos=0, i;


    if(!argv[1]){
        return ERROR;
    }

    if(argv[2]){
        if(!strcasecmp("-v",argv[2])){
        verbose=true;
        }
    }

    str=argv[1];

    if(balanced_expression(argv[1], &pos ,verbose)){
        fprintf(stdout, "It is balanced");
    }
    else{
        fprintf(stdout, "%s is not balanced in %i position", argv[1], pos);

        for(i=0; i<pos; i++){

            fprintf(stdout, "%c", str[i]);

            if(i==pos){
                fprintf(stdout, "****");
            }

        }
    }

    return 0;

}