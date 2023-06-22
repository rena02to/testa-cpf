#include <stdio.h>
#include <string.h>

int testa_dig2(char cpf[12])
{
    int x = 0, y = 11, result_two = 0, compara_two = 0;

    for(x = 0; x <= 9; x++)
    {
        result_two = result_two + (cpf[x] - '0') * y;
        y--;
    }

    result_two = result_two % 11;
    result_two = 11 - result_two;
    if(result_two >= 10){
        result_two = 0;
    }


    compara_two = cpf[10] - '0';
    if(result_two == compara_two){
        return 1;
    }else{
        return 0;
    }
}

int testa_dig1(char cpf[12])
{
    int i = 0, j = 10, result = 0, compara = 0;

    for(i = 0; i <= 8; i++)
    {
        result = result + (cpf[i] - '0') * j;
        j--;
    }

    result = result % 11;
    result = 11 - result;
    if(result >= 10){
        result = 0;
    }


    compara = cpf[9] - '0';
    if(result == compara){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    char cpf[13];
    int tamanho = 0, cont = 0, a = 0;

    printf("Digite o CPF sem pontos e hífens:\n");
    scanf("%s", cpf);

    tamanho = strlen(cpf);

    for(a = 0; a <= 10; a++)
    {
        if(cpf[a] == cpf[a + 1])
        {
            cont++;
        }
    }
    

    if(tamanho != 11 || cont == 10){
        printf("CPF INVÁLIDO\n");
    }else{
        if(testa_dig1(cpf) == 1 && testa_dig2(cpf) == 1){
            printf("CPF VÁLIDO!\n");
        }else{
            printf("CPF INVÁLIDO!\n");
        }
    }

    return 0;
}