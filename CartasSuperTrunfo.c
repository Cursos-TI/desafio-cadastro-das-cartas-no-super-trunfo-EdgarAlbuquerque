#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 2

typedef struct {
    int codigo;
    char nome[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Calcula densidade, PIB per capita e Super Poder
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos +
                        carta->densidadePopulacional + carta->pibPerCapita;
}

// Retorna 1 se A for maior, 2 se B for maior, 0 se empatar
int compararMaior(float a, float b) {
    return a > b ? 1 : (a < b ? 2 : 0);
}

// Retorna 1 se A for menor, 2 se B for menor, 0 se empatar
int compararMenor(float a, float b) {
    return a < b ? 1 : (a > b ? 2 : 0);
}

// Faz a comparação de todos os atributos entre as duas cartas
void compararCartas(Carta c1, Carta c2) {
    printf("\n=== COMPARAÇÃO DAS CARTAS ===\n");

    printf("População: Carta %d vence (%d)\n", compararMaior(c1.populacao, c2.populacao), compararMaior(c1.populacao, c2.populacao) == 1);
    printf("Área: Carta %d vence (%d)\n", compararMaior(c1.area, c2.area), compararMaior(c1.area, c2.area) == 1);
    printf("PIB: Carta %d vence (%d)\n", compararMaior(c1.pib, c2.pib), compararMaior(c1.pib, c2.pib) == 1);
    printf("Pontos Turísticos: Carta %d vence (%d)\n", compararMaior(c1.pontosTuristicos, c2.pontosTuristicos), compararMaior(c1.pontosTuristicos, c2.pontosTuristicos) == 1);
    printf("Densidade Populacional (menor vence): Carta %d vence (%d)\n", compararMenor(c1.densidadePopulacional, c2.densidadePopulacional), compararMenor(c1.densidadePopulacional, c2.densidadePopulacional) == 1);
    printf("PIB per Capita (menor vence): Carta %d vence (%d)\n", compararMenor(c1.pibPerCapita, c2.pibPerCapita), compararMenor(c1.pibPerCapita, c2.pibPerCapita) == 1);
    printf("Super Poder: Carta %d vence (%d)\n", compararMaior(c1.superPoder, c2.superPoder), compararMaior(c1.superPoder, c2.superPoder) == 1);
}

int main() {
    Carta cartas[MAX_CARTAS];

    for (int i = 0; i < MAX_CARTAS; i++) {
        printf("=== Cadastro da Carta %d ===\n", i + 1);
        cartas[i].codigo = i + 1;

        printf("Nome: ");
        scanf(" %[^\n]", cartas[i].nome);

        printf("População: ");
        scanf("%lu", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        calcularIndicadores(&cartas[i]);
    }

    compararCartas(cartas[0], cartas[1]);

    return 0;
}