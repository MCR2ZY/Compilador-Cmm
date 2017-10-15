/**
******************************************************************************
* @file	analex.h
* @author Maurício Menezes
* @version  x.x
* @date 10.10.17
* @brief
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <analex.c>

int main(int argc, char const *argv[])
{
    Token token;
    FILE *fp;

    if((fp = fopen (cod.txt, rt)) == NULL){
        printf("ERRO AO ABRIR ARQUIVO");
        printf("\n\tPressione <ENTER> para finalizar...\n\t");
        getchar();
        fflush(stdin);
        exit(1);
    }

    while(!feof (fp)){
        token = analex(fp);
    }

    printf ("\n\n\tAnalise lexica executada com sucesso.\n");
	
	printf("\n\tPressione <ENTER> para continuar...\n\t");
	getchar();
	fflush(stdin);
    
    if (fclose(fp)) {
		printf ("\n\tErro fatal no fechamento de arquivo. O programa sera encerrado.\n");
		printf("\n\tPressione <ENTER> para continuar...\n\t");
		getchar();
		fflush(stdin);
		exit (1);
	}

    return 0;
}
