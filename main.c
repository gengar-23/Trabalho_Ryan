#include <stdio.h>
#include <locale.h>

int main() {
    char customerName[100];
    double eletricalConsume = 0;
    double appliedTax = 0;
    double result = 0;
    int validador = 0; //especificará o tipo de instalação para calcular a taxa
    int validadorconsumo = 0; //definirá quando o consumo informado for um numero valido ou não
    int validadorconsumo2;

    setlocale(LC_ALL, "Portuguese.UTF-8"); //TODO - Necessário para colocatar textos com pontuações brasileiras
    printf("%s", "Digite o seu nome: ");
    scanf("%99[^\n]", customerName);
    printf("%s\n", customerName);
    while (getchar() != '\n');
    printf("%s", "Informe o consumo elétrico do periodo: ");
    while (validadorconsumo == 0) {
        validadorconsumo2 = scanf("%lf", &eletricalConsume);
        if (eletricalConsume > 0 && validadorconsumo2 == 1) {
            validadorconsumo = 1;
        }
        else {
            while (getchar() != '\n');
            printf("Valor inválido, tente novamente com um valor acima de 0: \n");
        }
    }
    printf("%.2lf\n", eletricalConsume);
    while (getchar() != '\n'); // TODO - Isso aqui é devido o \n ficar no buffer
    printf("%s", "Informe o tipo de instalação ao qual sua rede se encaixa: ");

    char tipo1[] = "Residencial", tipo2[] = "Industrial", tipo3[] = "Comercial", tipo11[] = "residencial", tipo21[] = "industrial", tipo31[] = "comercial", instalationType[100];
    int valid = 0;
    int instalationTypesize = 0;    //vai armazenar o tamanho da string


    while (valid == 0) {    //Loop enquanto o tipo de instalação for inválido
        instalationTypesize = 0;    //Zera para cada ciclo do loop
        scanf("%99s", instalationType);

        for (int p = 0; instalationType[p] != '\0'; p++)   //Vai acrescentar no tamanho da string caractere por caractere
        {
            instalationTypesize++;
        }

        //printf("%d", instalationTypesize);

        if ((instalationType[0] == tipo1[0]) || (instalationType[0] == tipo11[0])) {   //Vai checar com qual tipo de instalação a inicial bate
            for (int q = 1; q < instalationTypesize; ) {    //A partir daqui  vai checar o resto das letras
                if (instalationType[q] == tipo1[q]) {
                    q++;
                    if (q == instalationTypesize - 1) { //quando o q chegar na ultima letra e for igual ele vai validar
                        printf("\nVálidado.\n");           //e dar seguimento no codigo
                        valid = 1;
                        validador = 1;                  //Aqui vai indicar o tipo de instalação
                        instalationType[0] = tipo1[0];
                    }
                }
                else {
                    printf("\nInválido, tente novamente.\n");   //Caso tenha digitado outra coisa vai pedir para tentar novamente
                    valid = 0;
                    break;  //quebrar o loop de checagem
                }
            }
        }
        else if ((instalationType[0] == tipo2[0]) || (instalationType[0] == tipo21[0])) {
            for (int w = 1; w < instalationTypesize; ) {
                if (instalationType[w] == tipo2[w]) {
                    w++;
                    if (w == instalationTypesize - 1) {
                        printf("\nVálidado.\n");
                        valid = 1;
                        validador = 2;
                        instalationType[0] = tipo2[0];
                    }
                }
                else {
                    printf("\nInválido, tente novamente.\n");
                    valid = 0;
                    break;
                }
            }
        }
        else if ((instalationType[0] == tipo3[0]) || (instalationType[0] == tipo31[0])) {
            for (int e = 1; e < instalationTypesize; ) {
                if (instalationType[e] == tipo3[e]) {
                    e++;
                    if (e == instalationTypesize - 1) {
                        printf("\nVálidado.\n");
                        valid = 1;
                        validador = 3;
                        instalationType[0] = tipo3[0];
                    }
                }
                else {
                    printf("\nInválido, tente novamente.\n");
                    valid = 0;
                    break;
                }
            }
        }
        else {    //Caso ele não bata com nenhuma instalação ele vai dar inválido
            valid = 0;
            printf("\nInválido, tente novamente.\n");
        }

    }

    //Conforme o valor do validador ele vai selecionar o tipo correto de instalação para selecionar a taxa aplicada
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
        printf("\n%s", "Comercial");
        if (eletricalConsume <= 1000) {
            appliedTax = 0.55;
        }
        else {
            appliedTax = 0.60;
        }
    }
    if (validador == 2) {
        printf("\n%s", "Industrial");
        if (eletricalConsume <= 5000) {
            appliedTax = 0.55;
        }
        else {
            appliedTax = 0.60;
        }
    }
    //Calcular o consumo elétrico
    result = eletricalConsume * appliedTax;
    if (eletricalConsume < 100) {
        result = result - (result * 0.05);
    }

    //;Imprimir o resultado com todas as informações
    printf("%s\n", "\e[0;35m==================\e[0mRelatório\e[0;35m==================\e[0m");
    printf("\033[34m| - Nome: %s\033[0m\n", customerName);
    printf("| - Tipo de instalação: \033[38;2;255;215;0;24m%s\033[0m\n", instalationType);
    if (eletricalConsume > 3000) {
        printf("\033[31m| - Consumo informado: (Excessivo) %.2lf kWh\033[0m\n", eletricalConsume);
    }
    else if (eletricalConsume < 100) {
        printf("\033[32m| - Consumo informado: %.2f kWh\033[0m\n", eletricalConsume);
    }
    else {
        printf("\033[38;2;254;138;24m| - Consumo informado: %.2lf kWh\033[0m\n", eletricalConsume);
    }
    printf("| - Tarifa aplicada(R$/kWh): %.2lf\n", appliedTax);
    if (eletricalConsume < 100)
        printf("| - Valor total a pagar: %.2lf R$ \033[32m(5%% de desconto aplicado)\033[0m\n", result);
    printf("%s\n", "\e[0;35m=============================================\e[0m");
    // Entradas
        //Solicitar o nome do cliente
        //Solicitar o consumo de energia elétrica em kWh
        //Solicitar o tipo de instalação[Residencial[R], Comercial[C], Industrial[I]]
    // Processamento
        //Calcular o valor da contade energia com base nas seguintes tarifas
        /*
            Tipo            Faixa de Consumo        Tarifa (R$/kWh) // TODO - (Problema é como calcular isso aqui, 0.40 é apenas a porcentagem?)
            Residencial     até 500 kWh             0.40
            Residencial     acima de 500 kWh        0.65
            Comercial       até 1000 kWh            0.55
            Comercial       acima de 1000 kWh       0.60
            Industrial      até 5000 kWh            0.55
            Industrial      acima de 5000 kWh       0.60
        */
        // Saída
            // Exibir um resumo da conta com: [nome do cliente, tipo de instalação, consumo informado, tarifa aplicada, valor total a pagar]

        // Plus
            // Aplicar um desconto de 5% caso o cliente consuma menos de 100 kWh.
            // Exibir um alerta se o consumo for considerado excessivo (por exemplo, > 3000kWh).
            // Usar char[ ] para armazenar o nome e o tipo por extenso (ex: “Residencial” ao invés de “R”).
                // - Problema disso aqui é validar as formas de resdencial
            // Utilizar cores no terminal usando printf com códigos ANSI (apenas para usuários avançados)

    return 0;
}