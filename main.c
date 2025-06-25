#include <stdio.h>
#include <locale.h>

int main() {
    char customerName[100];
    float eletricalConsume = 0;
    char instalationType;
    float appliedTax = 0;
    float result = 0;

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
    scanf("%c", &instalationType); // TODO - Colocar como um char longo
    printf("%c\n", instalationType);
    if (instalationType == 'R') {
        printf("%s\n", "Residencial");
        if (eletricalConsume <= 500) {
            appliedTax = 0.40;
        } else {
            appliedTax = 0.65;
        }
    }
    if (instalationType == 'C') {
        printf("%s", "Comercial");
        if(eletricalConsume <= 1000) {
            appliedTax = 0.55;
        } else {
            appliedTax = 0.60;
        }
    }
    if (instalationType == 'I') {
        printf("%s", "Industrial");
        if(eletricalConsume <= 5000){
            appliedTax = 0.55;
        } else {
            appliedTax = 0.60;
        }
    }
    result = eletricalConsume * appliedTax;
    if (eletricalConsume < 100) {
        eletricalConsume = eletricalConsume - (eletricalConsume * 0.05);
    }

    printf("%.2f\n", appliedTax);
    printf("%s\n", "=================Relatório===================");
    printf("| - Nome: %s\n", customerName);
    printf("| - Tipo de instalação: %c\n", instalationType);
    if(eletricalConsume > 3000) {
        printf("| - Consumo informado: (Excessivo)%.2f kWh\n", eletricalConsume);
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