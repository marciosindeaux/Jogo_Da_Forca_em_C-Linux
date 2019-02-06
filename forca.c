#include "head.h"

int main(){
    qtdErros = 0;
    int opc = -1;
    while(opc != 0){
        system("clear");
        cabecalhoPrincipal();
        menu();
        scanf("%d",&opc);
        switch(opc){
            case 0:
                sair();
                opc = -1;
            break;
            case 1:
                iniciaJogo();
            break;
            case 2:
                dadosDoJogo();
                opc = -1;
            break;
            case 3:
                dadosDoAutor();
                opc = -1;
            break;
            case 4:
                adicionaPalavra();
                opc = -1;
            break;
        }
    }
    return(0);
}

void criaArquivo(){
    int quantidade = 0;
    FILE * f;
    printf("\n\nO arquivo não existia no seu diretório\nEstamos criando um novo banco de dados\n");
    system("touch palavras.txt");    
    system("sleep 4");
    f = fopen("palavras.txt","r+");
    fseek(f,0,SEEK_SET);
    fprintf(f,"%d",quantidade);
    fclose(f);
}

void preencheArquivo(char palavraNova[]){
    FILE * f;
    int quantidade;
    f = fopen("palavras.txt","r+");
    fscanf(f,"%d",&quantidade);
    quantidade++;
    fseek(f,0,SEEK_SET);
    fprintf(f,"%d",quantidade);
    fseek(f,0,SEEK_END);
    fprintf(f,"\n%s",palavraNova);
    fclose(f);
    
}

void adicionaPalavra(){
    char palavraNova[100];
    FILE * f;
    int quantidade;
    system("clear");
    printf("\nDigite a nova palavra com todas as letras em maiusculo\t : ");
    scanf("%s",&palavraNova);
    
    f = fopen("palavras.txt","r+");
    
    if(f == NULL){
        criaArquivo();
        preencheArquivo(palavraNova);
    }else{
        preencheArquivo(palavraNova);
        
    }
    free(f);
}

void escolhePalavra(){
    FILE * f;
    f = fopen("palavras.txt","r");

    if(f == NULL){
        printf("\n\nDesculpe, Bnco de dados não disponivel\nNão existe palavras no banco\n");
        printf("Deseja Criar um novo banco (y/n) ?\t");
        char escolha;
        scanf(" %c",&escolha);
        //
        if((escolha == 'y')||(escolha == 'Y')){
            criaArquivo();
            adicionaPalavra();
            main();
        }else{
            exit(1);
        }
    }else{
        srand(time(NULL));
        int quantidadePalavras;
        fscanf(f,"%d",&quantidadePalavras);
        int numeroRandomico = rand()%quantidadePalavras;
        for(int i = 0; i <=numeroRandomico; i++){
            fscanf(f,"%s",&palavra);
        }
    }
    free(f);
}

void limpaChutes(){
    for(int i = 0; i < quantidadeMaxima;i++){
        chutes[i] = '\0';
    }
}

void iniciaJogo(){
    limpaChutes();
    system("clear");
    bool acertou = false;
    int tentativas = 0;
    escolhePalavra(palavra);    
    do{
        char chute;
        printf("\nDigite uma letra em maiusculo : \t");
        scanf(" %c",&chute);

        bool palpite_repetido = verificaRepeticaoDePalpite(chute);
        if(!palpite_repetido){
            chutes[tentativas] = chute;
            tentativas++;
            printf("Tentativa %d , Letra : %c\n",tentativas,chute);
            printf("\n");
            verificarChute(chute);
        }else{
            printf("\nLetra ja foi chutada\n");
        }
        
        printf("\n");   
    }while((qtdErros < 6));
    perdeu();
}

bool verificaRepeticaoDePalpite(char chute){
    bool verificaRepeticao = false;
    for(int aux = 0 ; aux < strlen(chutes); aux++){
        if(chute == chutes[aux]){
            verificaRepeticao = true;
            return true;
        }
    }
    return false;
}

bool verificaLetra( char chute){
    for(int i = 0; i < strlen(palavra); i++){
        if(chute == palavra[i]){
            return true;
        }
    }
    qtdErros++;
    return false;
}

void verificarChute(char chute){
    
    bool letraExiste = verificaLetra(chute);   
    if(!letraExiste){
        printf(" Letra Não existe na palavra chave\n");
    }
    
    bool controle = false;
    int letras_aparecendo = 0;
    for(int i = 0; i < strlen(palavra);i++){
        for(int j = 0; j < strlen(chutes);j++){
            if(chutes[j] == palavra[i]){
                controle = true;
            }
        }
        if(controle == true){
            printf("%c ",palavra[i]);
            letras_aparecendo++;
        }else{
            printf("_ ");
        }
        controle = false;           
    }
    if(letras_aparecendo == strlen(palavra)){
        venceu();
    }else{

    }
}

void perdeu(){
    printf("\n\n");                                                
    printf("88\n");                                         
    printf("88\n");                                              
    printf("88\n");                                              
    printf("88  ,adPPYba,  ,adPPYba,  ,adPPYba, 8b,dPPYba,\n");  
    printf("88 a8'     '8a I8[    '' a8P_____88 88P'   'Y8\n");  
    printf("88 8b       d8  `'Y8ba,  8PP''''''' 88\n");          
    printf("88 '8a,   ,a8' aa    ]8I '8b,   ,aa 88\n");          
    printf("88  `'YbbdP''  `'YbbdP'  `'Ybbd8''' 88\n");
    printf("\n\nVoce perdeu o jogo\n\n");
    printf(" A palavra secreta era %s",palavra);
    voltarMenu();          

}

void venceu(){
    printf("                      ___________     \n");
    printf("                             .---'::'        `---.\n");
    printf("                            (::::::'              )\n");
    printf("                            |`-----._______.-----'|\n");
    printf("                            |              :::::::|\n");
    printf("                           .|               ::::::!-.\n");
    printf("                            |               :::::/|/\n");
    printf("                            |               ::::::|\n");
    printf("                            |    Meus Parabens::::|\n");
    printf("                            |    Voce Ganhou::::::|\n");
    printf("                            |      o Jogo   ::::::|\n");
    printf("                            |              .::::::|\n");
    printf("                            J              :::::::F\n");
    printf("                             \\            ::::::::/\n");
    printf("                              `.        .:::::::'\n");
    printf("                                `-._  .::::::-'\n");
    printf("____________________________________|  '''|'_________________________________________\n");
    printf("                                    |  :::|\n");
    printf("                                    F   ::J\n");
    printf("                                   /     ::\\ \n");                                       
    printf("                              __.-''      :::`-.__\n");
    printf("                             (_           ::::::_)\n");
    printf("                               `'''---------''''\n");
    voltarMenu();
}

void voltarMenu(){
    char escolha;
    printf("\n\nDeseja Sair do Jogo(y/n) ? ");
    scanf(" %c",&escolha);
    if((escolha == 'y') || (escolha == 'Y')){
        sair();
    }else{
        system("clear");
        main();
    }
}
void menu(){
    printf("\t[1] - Jogar o Jogo\n");
    printf("\t[2] - Dados do jogo\n");
    printf("\t[3] - Sobre o autor\n");
    printf("\t[4] - Adicionar palavras no Banco de dados\n");
    printf("\t[0] - Sair\n");
    printf("Opcao : ");
}

void cabecalhoPrincipal(){
    printf("\t*****************************************\n");
    printf("\t*                                       *\n");
    printf("\t*  BEM VINDO(A) AO JOGO DE FORCA \\O/    *\n");
    printf("\t*        Do Alura Cursos Online         *\n");
    printf("\t*                                       *\n");
    printf("\t*****************************************\n");
}

void dadosDoJogo(){
    
    system("clear");
    printf("\tDADOS DO JOGO :\n");
    printf("\tJogo proposto pelo professor Maurício Aniche, para o curso \n");
    printf("\tC II: Avavnçando na linguagem, O Jogo foi desenvolvido para \n");
    printf("\tsistemas operacionais linux. \n\n");
    printf("\tConfira as regras do jogo...\n\n\n");
    voltarMenu();
}

void dadosDoAutor(){
    char control;
    system("clear");
    printf("\tDADOS DO Autor :\n");
    printf("\tNome : Márcio Alexandre Freire Sindeaux\n");
    printf("\tGitHub : marciosindeaux\n");
    printf("\tEmail : sindeaux1999@hotmail.com\n\n\n");
    voltarMenu();
}

void sair(){
    char escolha;
    printf("\n\n\tTem Certeza que deseja Sair(y/n) ?");
    scanf(" %c",&escolha);
    if((escolha == 'y') || (escolha == 'Y')){
        system("clear");
        exit(1);
    }else{
        system("clear");
        main();
    }
}