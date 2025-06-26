#include <stdio.h>
#include <locale.h>

int main() {
    char customerName[100];
    float eletricalConsume = 0;
    float appliedTax = 0;
    float result = 0;
    int validador = 0;

    setlocale(LC_ALL, "Portuguese.UTF-8"); //TODO - Necessário para colocatar textos com pontuações brasileiras
    printf("%s", "Digite o seu nome: ");
    scanf("%99[^\n]", customerName);
    printf("%s\n", customerName);
    while (getchar() != '\n'); 
    printf("%s", "Informe o consumo elétrco do periodo: ");
    scanf("%f", &eletricalConsume);
    printf("%.2f\n", eletricalConsume);
    while (getchar() != '\n'); // TODO - Isso aqui é devido o \n ficar no buffer
    printf("%s", "Informe o tipo de instalação ao qual sua rede se encaixa: " );

        char tipo1[] = "Residencial", tipo2[] = "Industrial", tipo3[] = "Comercial", instalationType[100];
        int valid = 0;
        int instalationTypesize = 0;    //vai armazenar o tamanho da string
  
        
        while (valid == 0) {    //Loop enquanto o tipo de instalação for inválido
        instalationTypesize = 0;    //Zera para cada ciclo do loop
        scanf("%99s", instalationType);

            for (int p = 0; instalationType[p]  != '\0'; p++)   //Vai acrescentar no tamanho da string caractere por caractere
            {
                instalationTypesize++;      
            }
            
            //printf("%d", instalationTypesize);

            if (instalationType[0] == tipo1[0]) {   //Vai checar com qual tipo de instalação a inicial bate
                for (int q = 0; q < instalationTypesize; ) {    //A partir daqui  vai checar o resto das letras
                    if (instalationType[q] == tipo1[q]) {
                        q++;
                        if (q == instalationTypesize - 1) { //quando o q chegar na ultima letra e for igual ele vai validar
                            printf("\nVálidado");           //e dar seguimento no codigo
                            valid = 1;
                            validador = 1;                  //Aqui vai indicar o tipo de instalação
                        }
                    } else {
                            printf("Inválido, tente novamente.");   //Caso tenha digitado outra coisa vai pedir para tentar novamente
                            valid = 0;
                            break;  //quebrar o loop de checagem
                    }
                } 
            } else if (instalationType[0] == tipo2[0]){     
                for (int w = 0; w < instalationTypesize; ) {
                    if (instalationType[w] == tipo2[w]) {
                        w++;
                        if (w == instalationTypesize - 1) {
                            printf("\nVálidado");
                            valid = 1;
                            validador = 2;
                        }
                    } else {
                        printf("Inválido, tente novamente.");
                        valid = 0;
                        break;
                    }
                }   
            } else if (instalationType[0] == tipo3[0]) {
                for (int e = 0; e < instalationTypesize; ) {
                    if (instalationType[e] == tipo3[e]) {
                        e++;
                        if (e == instalationTypesize - 1) {
                            printf("\nVálidado");
                            valid = 1;
                            validador = 3;
                        }
                    } else {
                        printf("Inválido, tente novamente.");
                        valid = 0;
                        break;
                    }
                }
            } else {    //Caso ele não bata com nenhuma instalação ele vai dar inválido
                valid = 0;
                printf("Inválido, tente novamente");
            }

        }

    //Conforme o valor do validador ele vai selecionar o tipo correto de instalação para selecionar a taxa aplicada
    if (validador == 1) {
        printf("%s\n", "Residencial");
        if (eletricalConsume <= 500) {
            appliedTax = 0.40;
        } else {
            appliedTax = 0.65;
        }
    }
    if (validador == 3) {
        printf("%s", "Comercial");
        if(eletricalConsume <= 1000) {
            appliedTax = 0.55;
        } else {
            appliedTax = 0.60;
        }
    }
    if (validador == 2) {
        printf("%s", "Industrial");
        if(eletricalConsume <= 5000){
            appliedTax = 0.55;
        } else {
            appliedTax = 0.60;
        }
    }
    //Calcular o consumo elétrico
    result = eletricalConsume * appliedTax;
    if (eletricalConsume < 100) {
        eletricalConsume = eletricalConsume - (eletricalConsume * 0.05);
    }

    //Imprimir o resultado com todas as informações
    printf("%.2f\n", appliedTax);
    printf("%s\n", "=================Relatório===================");
    printf("| - Nome: \033[34m%s\033[0m\n", customerName);
    printf("| - Tipo de instalação: %s\n", instalationType);
    if(eletricalConsume > 3000) {
        printf("| - Consumo informado: \033[31m(Excessivo)\033[0m %.2f kWh\n", eletricalConsume);
    } else {
        printf("| - Consumo informado: %.2f kWh\n", eletricalConsume);
    }
    printf("| - Tarfa aplicada(R$/kWh): %.2f\n", appliedTax);
    printf("| - Valor total a pagar: %.2f R$\n", result);
    printf("%s\n", "=============================================");
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