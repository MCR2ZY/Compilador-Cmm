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

void imprimeToken(Token ); //Função temporaria de teste para imprimir tokens
char TabPalReservadas[QntPalReservadas][TamPalReservadas] = {
        "booleano",        "caracter",        "enquanto",
        "inteiro",         "para",            "real",
        "retorne",         "se",              "semparam",
        "semretorno",     "senao"
    };

int main(int argc, char const *argv[])
{
    Token tkn;
    FILE *fp;

    fp = fopen("cod.txt", "r+");

    if(fp==NULL){
        printf("\n\tERRO AO ABRIR ARQUIVO");
        printf("\n\tPressione <ENTER> para finalizar...\n\t");
        exit(1);
    }

    while(!feof (fp)){
        tkn = analex(fp);
        imprimeToken(tkn);
    }

    printf ("\n\n\tAnalise lexica executada com sucesso.\n");
    fclose(fp);
    getchar();
    return 0;
}

void imprimeToken(Token tkn){

    switch (tkn.tipo){
        case CT_C:
            printf("\n\t< CT_C, \"%s\" >", tkn.lexema);;
            break;
        case CT_I:
            printf("\n\t< CT_I, \"%d\" >", tkn.valor.valorInt);
            break;
        case CT_L:
            printf("\n\t< CT_L, \"%s\" >", tkn.lexema);
            break;
        case CT_R:
            printf("\n\t< CT_R, \"%f\" >", tkn.valor.valorReal);
            break;
        case ID:
            printf("\n\t< ID, \"%s\" >", tkn.lexema);
            printf(" [Codigo literal: %d]", tkn.valor.posLiteral);
            break;
        case PR:
            printf("\n\t< PR, \"%s\" >", TabPalReservadas[tkn.valor.codPR]);
            break;
        case SN:
            printf("\n\t< SN, \"%s\" >", tkn.lexema);
            break;
        case END:
            printf("\n\n\tEncerando...\n");
            getchar();
            exit (1);
            break;
    }

    return;
}
