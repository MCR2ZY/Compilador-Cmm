/**
******************************************************************************
* @file	analex.h
* @author Maurício Menezes
* @version  x.x
* @date 10.10.17
* @brief
******************************************************************************
*/
#include "analex.h"

Token analex(FILE *fd){
    Token token;
    int estado = 0;
    int p;
    int c;
    char literal[TamLexema];
    char num[TamNum];



    while(true){
        
        switch (estado){
        
            case 0:
            c = fgetc(fp);    
            break;
        default:
            break;
        }

    }

}