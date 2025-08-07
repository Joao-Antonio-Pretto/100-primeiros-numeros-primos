#include <math.h>
#include <stdio.h>

int eh_primo(int numero) {
    if (numero <= 1) return 0; // não é primo
    if (numero == 2) return 1; // 2 é primo
    if (numero % 2 == 0) return 0; // Pares maiores que 2 não são primos

    // Testar divisores ímpares, começando do 3.
    // Ir até a raiz quadrada do número, já que se eçe não tiver um divisor que não seja ele mesmo abaixo de sua raiz quadrada, ele não tem nenhum divisor.
    for (int i = 3; i <= sqrt(numero); i += 2) { //Começando com o divisor de teste i valendo 3, e enquanto esse divisor de teste i for menor ou igual à 
                                                 //raiz quadrada do numero que estamos investigando, execute o código do loop e depois some 2 ao i para testar o 
                                                 //próximo divisor ímpar.
        if (numero % i == 0) {
            return 0; // não é primo
        }
    }
    return 1; // é primo
}

int main() {
    int primos_encontrados = 0;
    int numero_atual = 1;
    int ultimo_primo = 0;
    const int OBJETIVO = 100; // 100º primo

    printf("Procurando o %dº número primo...\n", OBJETIVO);

    // Continue procurando enquanto não encontrar 100 primos
    while (primos_encontrados < OBJETIVO) {
        //Chamada da Função eh_primo para testar o número atual
        if (eh_primo(numero_atual)) {
            primos_encontrados++; // Mais 1
            ultimo_primo = numero_atual; // Guarda ele
        }
        numero_atual++; // Passa para o próximo número para testar
    }

    printf("O %dº número primo é: %d\n", OBJETIVO, ultimo_primo);

    return 0;
}