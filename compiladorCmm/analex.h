#ifndef ANALEX_H_INCLUDED
#define ANALEX_H_INCLUDED

typedef enum palReservada{
    PR_BOOLEANO,        PR_CARACTER,        PR_ENQUANTO, 
    PR_INTEIRO,         PR_PARA,            PR_REAL, 
    PR_RETORNE,         PR_SE,              PR_SEMRETORNO
}PalReservada;

typedef enum sinal{
    SN_ABRI_CHAVE,          SN_ABRI_PARENTESE,       SN_AND,            SN_ATRIBUICAO,          SN_COMPARACAO,
    SN_DIFERENTE,           SN_DIVISAO,              SN_DIVISAO,        SN_FECHA_CHAVE,         SN_FECHA_PARENTESE,
    SN_MAIOR,               SN_MAIOR_IGUAL,          SN_MENOR,          SN_MENOR_IGUAL,         SN_MULTIPLICACAO,
    SN_NEGACAO,             SN_OR,                   SN_PTO_VIRGULA,    SN_SOMA,                SN_SUBTRACAO
}Sinal;

typedef enum categoria{
    CT_C, CT_I, CT_L, 
    CT_R, ID,   PR, 
    SINAL
} Categoria;

#endif // ANALEX_H_INCLUDED
