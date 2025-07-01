#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char customerName[101];   // Receberá o nome do consumidor
    char entrada[100];        // Receberá o primeiro valor de consumo em forma de string
    char* endptr;             // Indicará onde parou a conversão de string para valor numerico (double)
    double eletricalConsume;  // Armazenará o consumo elétrico
    double appliedTax = 0;    // Informará a taxa a ser aplicada conforme a instalação e consumo
    double result = 0;        // Armazenará o valor final a ser pago
    int validador = 0;        // Especificará o tipo de instalação para calcular a taxa
                              // e também servirá para validar o nome
    int validadorConsumo = 0; // definirá quando o consumo informado for um numero valido ou não

    setlocale(LC_ALL, "Portuguese.UTF-8"); // TODO - Necessário para colocatar
                                           // textos com pontuações brasileiras
    while (validador != 1) {
        printf("%s", "Digite o seu nome (máx. 100 caracteres): ");
        int res = scanf("%100[^\n]", customerName);
        if (res != 1) {
            printf("\033[38;5;208m[AVISO] - É necessário informar um nome, tente novamente.\033[0m\n");
            validador = 0;
            while (getchar() != '\n');
        }
        else {
            validador = 1;
            while (getchar() != '\n');
            break;
        }
    }
    validador = 0; // Resetar o validador para ser utilizado novamente
    int quantia = 0;
    for (int numChar = 0; customerName[numChar] != '\0'; numChar++) {
        quantia++;
    }
    if (quantia >= 100) {
        printf("\033[38;5;208m[AVISO] - Seu nome ultrapassou o limite de 100 caracteres, será encurtado no final.\033[0m\n");
    }

    while (validadorConsumo == 0) {
        printf("Informe o consumo elétrico do período: ");
        if (!fgets(entrada, sizeof(entrada), stdin)) {
            // Entra caso dê erro na leitura
            continue;
        }

        // Remover o '\n' do final, se houver
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] == '\n') {
                entrada[i] = '\0';
                break;
            }
            i++;
        }

        eletricalConsume = strtod(entrada, &endptr);

        // Validações:
        // 1° - Nenhum número foi lido
        // 2° - Sobrou lixo (letras, símbolos, espaço)
        // 3° - Número não pode ser zero ou negativo
        if (endptr == entrada || *endptr != '\0' || eletricalConsume <= 0) {
            printf("\033[38;5;208m[AVISO] - Valor inválido (Apenas um número real positivo, sem letras ou espaços extras)\033[0m\n");
            continue;
        }

        validadorConsumo = 1;
    }

    printf("%.2lf\n", eletricalConsume);
    printf("%s", "Informe o tipo de instalação ao qual sua rede se encaixa: ");

    char instalationType[100], tipoRe[] = "Residencial", tipoIn[] = "Industrial", tipoCo[] = "Comercial",
         tipore[] = "residencial", tipoin[] = "industrial", tipoco[] = "comercial", tipoRE[] = "RESIDENCIAL",
         tipoIN[] = "INDUSTRIAL", tipoCO[] = "COMERCIAL";

    int valid = 0;
    int instalationTypesize = 0; // vai armazenar o tamanho da string

    while (valid == 0) { // Loop enquanto o tipo de instalação for inválido
        instalationTypesize = 0; // Zera para cada ciclo do loop
        // TODO - Precisa modernizar a forma de fazer isso.
        scanf("%99s", instalationType);
        for (int p = 0; instalationType[p] != '\0';
            p++) // Vai acrescentar no tamanho da string caractere por caractere
        {
            instalationTypesize++;
        }
        // printf("%d", instalationTypesize);
        if ((instalationType[0] == tipoRe[0]) || (instalationType[0] == tipore[0])) {
            // Vai checar com qual tipo de instalação a inicial bate
            if (instalationTypesize == 1) {
                valid = 1;
                validador = 1;
                break;
            }
            for (int q = 1; q < instalationTypesize;) { // A partir daqui  vai checar
                // o resto das letras
                if (instalationType[q] == tipoRe[q] ||
                    instalationType[q] == tipoRE[q]) {
                    q++; // TODO - Tem certeza que isso é necessário?
                    if (q == instalationTypesize - 1) { // quando o q chegar na ultima letra e  for igual
                        // ele vai validar e dar seguimento no codigo
                        valid = 1;
                        validador = 1; // Aqui vai indicar o tipo de instalação
                        instalationType[0] = tipoRe[0];
                    }
                } else {
                    printf("\nInválido, tente novamente.\n"); // Caso tenha digitado outra
                    // coisa vai pedir para
                    // tentar novamente
                    valid = 0;
                    break; // quebrar o loop de checagem
                }
            }
        } else if (instalationType[0] == tipoIn[0] || instalationType[0] == tipoin[0]) {
            if (instalationTypesize == 1) {
                valid = 1;
                validador = 2;
                break;
            }
            for (int w = 1; w < instalationTypesize;) {
                if (instalationType[w] == tipoIn[w] || instalationType[w] == tipoIN[w]) {
                    w++;
                    if (w == instalationTypesize - 1) {
                        printf("\nVálidado.\n");
                        valid = 1;
                        validador = 2;
                        instalationType[0] = tipoIn[0];
                    }
                } else {
                    printf("\nInválido, tente novamente.\n");
                    valid = 0;
                    break;
                }
            }
        } else if ((instalationType[0] == tipoCo[0]) ||
            (instalationType[0] == tipoco[0])) {
            if (instalationTypesize == 1) {
                valid = 1;
                validador = 3;
                break;
            }
            for (int e = 1; e < instalationTypesize;) {
                if (instalationType[e] == tipoCo[e] ||
                    instalationType[e] == tipoCO[e]) {
                    e++;
                    if (e == instalationTypesize - 1) {
                        printf("\nVálidado.\n");
                        valid = 1;
                        validador = 3;
                        instalationType[0] = tipoCo[0];
                    }
                }
                else {
                    printf("\nInválido, tente novamente.\n");
                    valid = 0;
                    break;
                }
            }
        }
        else { // Caso ele não bata com nenhuma instalação ele vai dar inválido
            valid = 0;
            printf("\nInválido, tente novamente.\n");
        }
    }
    // Conforme o valor do validador ele vai selecionar o tipo correto de
    // instalação para selecionar a taxa aplicada
    if (validador == 1) {
        printf("\n%s\n", "Residencial");
        if (eletricalConsume <= 500) {
            appliedTax = 0.40;
        }
        else {
            appliedTax = 0.65;
        }
    }
    if (validador == 3) {
        printf("\n%s\n", "Comercial");
        if (eletricalConsume <= 1000) {
            appliedTax = 0.55;
        }
        else {
            appliedTax = 0.60;
        }
    }
    if (validador == 2) {
        printf("\n%s\n", "Industrial");
        if (eletricalConsume <= 5000) {
            appliedTax = 0.55;
        }
        else {
            appliedTax = 0.60;
        }
    }
    // Calcular o consumo elétrico
    result = eletricalConsume * appliedTax;
    if (eletricalConsume < 100) {
        result = result - (result * 0.05);
    }
    //;Imprimir o resultado com todas as informações
    printf("%s\n", "\e[0;35m==================\e[0mRelatório\e[0;35m============="
        "=====\e[0m");
    printf("\033[34m| - Nome: %s\033[0m;\n", customerName);
    switch (validador) {
    case 1:
        printf("| - Tipo de instalação: \033[38;2;255;215;0;24m%s\033[0m;\n", "Residencial");
        break;
    case 2:
        printf("| - Tipo de instalação: \033[38;2;255;215;0;24m%s\033[0m;\n", "Industrial");
        break;
    case 3:
        printf("| - Tipo de instalação: \033[38;2;255;215;0;24m%s\033[0m;\n", "Comercial");
        break;
    }
    if (eletricalConsume > 3000) {
        printf("\033[31m| - Consumo informado: (Excessivo) %.2lf kWh\033[0m;\n", eletricalConsume);
    }
    else if (eletricalConsume < 100) {
        printf("\033[32m| - Consumo informado: %.2f kWh\033[0m;\n", eletricalConsume);
    }
    else {
        printf("\033[38;2;254;138;24m| - Consumo informado: %.2lf kWh\033[0m;\n", eletricalConsume);
    }
    printf("| - Tarifa aplicada(R$/kWh): %.2lf;\n", appliedTax);
    if (eletricalConsume < 100) {
        printf("| - Valor total a pagar: %.2lf R$ \033[32m(5%% de desconto aplicado)\033[0m;\n", result);
    }
    else {
        printf("| - Valor total a pagar: %.2lf R$.\n", result);
    }
    printf("%s\n", "\e[0;35m=============================================\e[0m");
    return 0;
}