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

int main(int argc, char const *argv[])
{
    Token tkn;
    FILE *fp;

    fp = fopen("cod.txt", "r+");

    if(fp==NULL){
        printf("\n\tERRO AO ABRIR ARQUIVO");
        printf("\n\tPressione <ENTER> para finalizar...\n\t");
        exit(1);
    }else{

    printf("PASSOU!");}
    while(!feof (fp)){
        tkn = analex(fp);
    }

    printf ("\n\n\tAnalise lexica executada com sucesso.\n");
    fclose(fp);



    return 0;
}
