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

Token analex(FILE *fp){
    Token token;                       // Recebe o token do analisador lexico
    int estado = 0;                    // Controla o estado no automato
    int p = 0;                             // Controla a posição tanto da vetor para literal quanto do vetor para o numero
    int c;                             // Recebe o caracter do arquivo
    char literal[TamLexema];           // Vetor temporario que guarda o literal
    char numero[TamNum];                  // Vetor temporario que guarda o numero



    while(1){

        switch (estado){

            case 0:
                c = fgetc(fp);
                if(c == " " || c == '\t'){  // Filtra espacos e tabs
                    estado = 0;
                }
                else if(c == isalpha(c)){   // Trata ID's e pal. reservadas
                    estado = 1;
                }
                else if(c == isdigit(c)){   // Trata constantes inteiras e constantes reais
                    estado = 3;
                }
                else if(c == '\''){         // Trata as constantes caracter, constante '\n' e constante '\0'
                    estado = 8;
                }
                else if(c == '\"'){         // Trata as constantes cadeia de caracteres
                    estado = 16;
                }
                else if(c == ';'){          // Trata o Ponto e Virgula
                    estado = 18;
                }
                else if(c == '('){          // Trata o abri parentese
                    estado = 19;
                }
                else if(c == ')'){          // Trata o fecha parentese
                    estado = 20;
                }
                else if(c == '-'){          // Trata o menos
                    estado = 21;
                }
                else if(c == '+'){          // Trata o mais
                    estado = 22;
                }
                else if(c == '*'){          // Trata o vezes
                    estado = 23;
                }
                else if(c == ','){          // Trata a virgula
                    estado = 24;
                }
                else if(c == '&'){          // Trata o AND
                    estado = 25;
                }
                else if(c == '|'){          // Trata o OR
                    estado = 27;
                }
                else if(c == '<'){          // Trata o menor ou menor igual
                    estado = 29;
                }
                else if(c == '>'){          // Trata o maior ou maior igual
                    estado = 32;
                }
                else if(c == '='){          // Trata a atribuicao ou a comparacao
                    estado = 35;
                }
                else if(c == '!'){          // Trata a negacao ou o diferente
                    estado = 38;
                }
                else if(c == '/'){          // Trata o comentario ou divisao
                    estado = 41;
                }
                else if(c == '{'){          // Trata o abri chave
                    estado = 46;
                }
                else if(c == '}'){          // Trata o fecha chave
                    estado = 47;
                }
                break;
            case 1:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(isalnum(c) || c == '_'){
                    estado = 1;
                }else{
                    estado = 2;
                }
                break;
            case 2:
                literal[p] = EOS;
                ungetc(c, fp);
                token.tipo = ID;
                strcpy(literal, token.lexema);
                // Checar se ID já existe, se não add id a tabela com ids
                return token;
                break;
            case 3:
                numero[p] = c;
                p++;
                c = fgetc(fp);
                if(isdigit(c)){
                    estado = 3;
                }else if(c == '.'){
                    estado = 5;
                }else{
                    estado = 4;
                }
                break;
            case 4:
                ungetc(c, fp);
                numero[p] = EOS;
                token.tipo = CT_I;
                token.valor.valorInt = atoi(numero);    // converter string para inteiro
                return token;
                break;
            case 5:
                numero[p] = c;
                p++;
                c = fgetc(fp);
                if(isdigit(c)){
                    estado = 6;
                }else{
                    //ErroToken;      // Criar a função erro token invalido
                }
                break;
            case 6:
                numero[p] = c;
                p++;
                c = fgetc(fp);
                if(isdigit(c)){
                    estado = 6;
                }else{
                    estado = 7;
                }
                break;
            case 7:
                ungetc(c, fp);
                numero[p] = EOS;
                token.tipo = CT_R;
                token.valor.valorReal = atol(numero);   // Converter string para num real
                return token;
                break;
            case 8:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(c == '\\'){
                    estado = 11;
                }else if(isprint(c)){
                    estado = 9;
                }
                break;
            case 9:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(c == '\''){
                    estado = 10;
                }else{
                    //ErroToken;
                }
                break;
            case 10:
                literal[p] = c;
                p++;
                literal[p] = EOS;
                token.tipo = CT_C;
                strcpy(literal, token.lexema);
                return token;
                break;
            case 11:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(c == '0'){
                    estado = 12;
                }else if(c == 'n'){
                    estado = 14;
                }else {
                    //ErroToken;
                }                          
                break;
            case 12:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(c == '\''){
                    estado = 13;
                }else{
                    //ErroToken;
                }
                break;
            case 13:
                literal[p] = c;
                p++;
                literal[p] = EOS;
                token.tipo = CT_C;
                strcpy(literal, token.lexema);
                return token;                
                break;
            case 14:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(c == '\''){
                    estado = 15;
                }else{
                    //ErroToken;
                }
                break;
            case 15:
                literal[p] = c;
                p++;
                literal[p] = EOS;
                token.tipo = CT_C;
                strcpy(literal, token.lexema);
                return token;
                break;
            case 16:
                literal[p] = c;
                p++;
                c = fgetc(fp);
                if(isprint(c)){
                    estado = 16;
                }else if(c == '\''){
                    estado = 17
                }else{
                    //ErroToken;
                }          
                break;
            case 17:
                literal[p] = c;
                p++;
                literal[p] = EOS;
                token.tipo = CT_L;
                strcpy(literal, token.lexema);
                return token;              
                break;
            case 18:
                token.tipo = SN;
                token.codSN = SN_PTO_VIRGULA;
                strcpy(';', token.lexema);
                return token;
                break;
            case 19:
                token.tipo = SN;
                token.codSN = SN_ABRI_PARENTESE;
                strcpy('(', token.lexema);
                return token;
                break;
            case 20:
                token.tipo = SN;
                token.codSN = SN_FECHA_PARENTESE;
                strcpy(')', token.lexema);
                return token;
                break;
            case 21:
                token.tipo = SN;
                token.codSN = SN_SUBTRACAO;
                strcpy('-', token.lexema);
                return token;
                break;
            case 22:
                token.tipo = SN;
                token.codSN = SN_SOMA;
                strcpy('+', token.lexema);
                return token;
                break;
            case 23:
                token.tipo = SN;
                token.codSN = SN_MULTIPLICACAO;
                strcpy('*', token.lexema);
                return token;
                break;
            case 24:
                token.tipo = SN;
                token.codSN = SN_VIRGULA;
                strcpy(',', token.lexema);
                return token;
                break;
            case 25:
                c = fgetc(fp);
                if(c == '&'){
                    estado = 26;
                }else{
                    //ErroToken;
                }
                break;
            case 26:
                token.tipo = SN;
                token.codSN = SN_AND;
                strcpy('&&', token.lexema);
                return token;
                break;
            case 27:
                c = fgetc(fp);
                if(c == '|'){
                    estado = 28;
                }else{
                    //ErroToken;
                }
                break;
            case 28:
                token.tipo = SN;
                token.codSN = SN_OR;
                strcpy('||', token.lexema);
                return token;
                break;
            case 29:
                c = fgetc(fp);
                if(c == '='){
                    estado = 31;
                }else{
                    estado = 30;
                }
                break;
            case 46:
                token.tipo = SN;
                token.codSN = SN_ABRI_CHAVE;
                strcpy('{', token.lexema);
                break;
            case 47:
                token.tipo = SN;
                token.codSN = SN_FECHA_CHAVE;
                strcpy('}', token.lexema);
                break;
            default:
            break;
        }

    }

}
