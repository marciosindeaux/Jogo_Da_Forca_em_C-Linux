#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>


#define quantidadeMaxima 26
char chutes[quantidadeMaxima];
int qtdErros;
char palavra[100];


void cabecalhoPrincipal();
void menu();
void escolhePalavra();
void adicionaPalavra();
void criaArquivo();
void preencheArquivo(char palavraNova[]);
void limpaChutes();
void iniciaJogo();
bool verificaRepeticaoDePalpite(char chute);
bool verificaLetra(char chute);
void verificarChute(char chute);
void venceu();
void perdeu();
void voltarMenu();
void dadosDoJogo();
void dadosDoAutor();
void sair();



