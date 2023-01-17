#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct trips{
    int id, data_c, data_p, carga, id_barco, id_porto_o, id_porto_d;
    float pagamento;
}TRIP;

typedef struct ports{
    int id;
    char nome[MAX], pais[MAX];
    float custo_dock;
}PORT;

typedef struct ships{
    int id, cap, ano;
    char nome[MAX], tipo[MAX], pais[MAX];
    float consumo_comb, custo_p;
}NAV;

void ler_viagens(TRIP trips[], int *maxt){
    FILE * viagens;
    int i=0;

    if((viagens=fopen("trips.txt","r"))== NULL){
        printf("\nImpossível abrir o arquivo\n\n");
    exit(1);
    }

    while (fscanf(viagens,"%d;%d;%d;%d;%d;%d;%d;%f;", &trips[i].id, &trips[i].id_barco, &trips[i].id_porto_o, &trips[i].id_porto_d, &trips[i].data_p, &trips[i].data_c, &trips[i].carga, &trips[i].pagamento)!=EOF){
        i++;//copia cada linha do programa para a string 
        (*maxt)++;//conta o numero de linhas que a string tem
    }
    
}

int ler_navios(NAV ships[]){
    FILE * navios;
    int i=0, p=0;

    if((navios=fopen("ships.txt","r"))== NULL){
        printf("\nImpossível abrir o arquivo\n\n");
    exit(1);
    }

    while (fscanf(navios,"%d;%[^;];%[^;];%d;%d;%[^;];%f;%f;", &ships[i].id, ships[i].nome, ships[i].tipo, &ships[i].cap, &ships[i].ano, ships[i].pais, &ships[i].consumo_comb, &ships[i].custo_p) !=EOF ){
        i++;//copia cada linha do programa para a string 
        p++;//conta o numero de linhas que a string tem
    }
    return p;
}

int ler_portos(PORT ports[]){
    FILE * portos;
    int i=0,p=0;

    if((portos=fopen("ports.txt","r"))== NULL){
        printf("\nImpossível abrir o arquivo\n\n");
    exit(1);
    }

    while (fscanf(portos,"%d;%[^;];%[^;];%f;", &ports[i].id, ports[i].nome, ports[i].pais, &ports[i].custo_dock) !=EOF){
        i++;//copia cada linha do programa para a string 
        p++;//conta o numero de linhas que a string tem
    }
    return p;
}

void listar_navios(NAV ships[], int maxs){
    int i;

    for(i=0;i<maxs;i++){
        printf("\nid:%d Nome:%s Capacidade:%d Ano:%d País:%s Consumo:%f Custo Tripulação:%f\n", ships[i].id, ships[i].nome, ships[i].cap, ships[i].ano, ships[i].pais, ships[i].consumo_comb, ships[i].custo_p);
    }   //Completa a frase com as informações de cada linha da string
}

PORT listar_portos(PORT ports[], int maxp){
    int i=0;

    for(i=0;i<maxp;i++){
        printf("\nid:%d Nome:%s País:%s Custo:%2f\n", ports[i].id, ports[i].nome, ports[i].pais, ports[i].custo_dock);
    }   //Completa a frase com as informações de cada linha da string
}

void nome_barco(NAV ships[], int D, char *nome, int maxs){
    int x ;

    for(x=0;x<=maxs;x++){
        if (D==ships[x].id){
            strcpy(nome,ships[x].nome);
        }   //encontra o nome do barco com o id e devolve à função
    }
}

void nome_porto(PORT ports[], int D, char *nome, int maxp){
    int i ;

    for(i=0;i<=maxp;i++){
        if (D==ports[i].id){
            strcpy(nome,ports[i].nome);
        }   //encontra o nome do porto com o id e devolve à função
    }
}

TRIP listar_viagens(TRIP trips[], PORT ports[], NAV ships[], int maxs, int maxp, int *maxt){
    int i;
    char nomeb[MAX], nomepo[MAX], nomepd[MAX];
    if (*maxt==27){
        for(i=0;i<*maxt;i++){ //para a primeira vez antes de adicionar alguma viagem
            nome_barco(ships, trips[i].id_barco, nomeb, maxs);
            nome_porto(ports, trips[i].id_porto_d, nomepd, maxp);
            nome_porto(ports, trips[i].id_porto_o, nomepo, maxp);
            printf("\nid: %d Nome: %s  Porto Partida: %s  Chegada: %s  Dia Inicio: %d Dia Final: %d Lotacao: %d \n", trips[i].id, nomeb, nomepo, nomepd, trips[i].data_p, trips[i].data_c, trips[i].carga);
        }
    }else{
        for(i=0;i<=trips[*maxt].id;i++){ //para contar até à última linha adicionada
            if (trips[i].id==0){//mete um 0 sempre a seguir ao 27, fazemos isto para não aparecer na listagem
            }else{
            nome_barco(ships, trips[i].id_barco, nomeb, maxs);
            nome_porto(ports, trips[i].id_porto_d, nomepd, maxp);
            nome_porto(ports, trips[i].id_porto_o, nomepo, maxp);
            printf("\nid: %d Nome: %s  Porto Partida: %s  Chegada: %s  Dia Inicio: %d Dia Final: %d Lotacao: %d \n", trips[i].id, nomeb, nomepo, nomepd, trips[i].data_p, trips[i].data_c, trips[i].carga);
            }        
        }//Completa a frase com as informações de cada linha da string
    }   
}

int info_barco(NAV ships[], int D, char *nome, int maxs){
    int i ;

    for(i=0;i<=maxs;i++){
        if (D==ships[i].id){
            strcpy(nome,ships[i].nome);
        }   //encontra o nome do barco com o id e escreve na string com o pointer
    }
    return i;
}

char info_portos(PORT ports[], int D, int K, char *nomeO, char *nomeD, int maxp){
    int i;

    for(i=0;i<=maxp;i++){
        if(D==ports[i].id){
            strcpy(nomeO,ports[i].nome);
        }//encontra o nome do porto com o id e escreve na string com o pointer
    }
    for(i=0;i<maxp;i++){
        if(K==ports[i].id){
            strcpy(nomeD,ports[i].nome);
        }//encontra o nome do porto com o id e escreve na string com o pointer
    }
}

void imprimir(TRIP trips[], int *F, int max){
    int i=0, min=1;

    while (i<=0){ //enquanto o utilizador meter números inválidos
        scanf("%d", F);
        if (*F>max || *F<min){
            printf("Número excede os limites.\n");
        }else{
            i++;
        }
    }
}

void listar_cargas(TRIP trips[], NAV ships[], PORT ports[], int maxs, int maxp, int *maxt){
    int idnavio, datai, dataf, i, captotal=0, x, verificador1=0, verificador2=0, resposta;
    float prct;
    char nomebarco[MAX], nomeportoO[MAX], nomeportoD[MAX];

        printf("\nComplete as seguintes informações:\n\n");
        printf("ID do navio (1-100): ");
        imprimir(trips, &idnavio, 100);
        printf("Data de início (1-31): ");
        imprimir(trips, &datai, 31);
        printf("Data final (1-31): ");
        imprimir(trips, &dataf, 31);
       
        for(i=0;i<=*maxt;i++){
            if (idnavio==trips[i].id_barco){
                verificador1=1; // verifica se existe alguma viagem com este barco
                if (datai<=trips[i].data_p){
                    if (dataf>=trips[i].data_c){ //se estiverem contidas entre as datas introduzidas
                        verificador2=1; // verifica se existem viagens do barco selecionado no periodo escolhido
                    
                        x=info_barco(ships, trips[i].id_barco, nomebarco, maxs);
                        prct=trips[i].carga*ships[x].cap/100;//calcula o peso da carga
                    
                        info_portos(ports, trips[i].id_porto_o, trips[i].id_porto_d, nomeportoO, nomeportoD, maxp);
                   
                        printf("%s viagem de %s para %s entre os dias %d e %d: %d%% --> %f kg\n", nomebarco, nomeportoO, nomeportoD, trips[i].data_p, trips[i].data_c, trips[i].carga, prct);
                        captotal= captotal + prct;
                    }
                }
            }
        }if (verificador1==1 && verificador2==1){
            printf("\n%s com carga total de %d kg em viagens entre os dias %d e %d\n\n", nomebarco, captotal, datai, dataf);
        }

        if(verificador1==0){
            printf("\nO navio introduzido não percorreu nenhuma viagem.\nDeseja escolher outro navio (1) ou sair (0)?\n\n");
            scanf("%d", &resposta);
            if (resposta==0){
                printf("Decidiu sair.\n");
                verificador2=1; //para nao aparecer o próximo if

            }else if(resposta==1){
                listar_cargas(trips, ships, ports, maxs, maxp, maxt);
            }else{
                printf("Isso não é uma opção!!\nMenu:");
            }
        }
        if (verificador2==0){
            printf("O navio selecionado não viajou durante o periodo escolhido.\nDeseja escolher outro periodo (1) ou sair (0)?\n\n");
            scanf("%d", &resposta);
            if (resposta==0){
                printf("Decidiu sair.\n");

            }else if(resposta==1){
                listar_cargas(trips, ships, ports, maxs, maxp, maxt);
            }else{
                printf("Isso não é uma opção!!\nMenu:");
            }
        }
        
}



int guardar_viagens(TRIP trips[], int *maxt){
    FILE * viagens;
    int i;

    if((viagens=fopen("trips.txt","a+"))== NULL){// abre o ficheiro para acrescentar a partir do fim
        printf("\nImpossível abrir o arquivo\n\n");
    exit(1);
    }
    
    fprintf(viagens,"%d;%d;%d;%d;%d;%d;%d;%f;\n", trips[*maxt].id, trips[*maxt].id_barco, trips[*maxt].id_porto_o, trips[*maxt].id_porto_d, trips[*maxt].data_c, trips[*maxt].data_p, trips[*maxt].carga, trips[*maxt].pagamento);
    fclose(viagens);
}

int idporto(PORT ports[], char *D, int maxp){
    int i, idp;

    for(i=0;i<maxp;i++){
        if (strcmp(D,ports[i].nome)==0){
            idp=ports[i].id;
        }   //encontra o nome do porto com o id e devolve à função
        
    }
    return idp;
}

int cap_barco(NAV ships[], int idnav, int maxs){
    int capb, i;

    for(i=0;i<maxs;i++){
        if (idnav==ships[i].id){
            capb=ships[i].cap;
        }//encontra o barco e devolve a sua capacidade a função
    }
    return capb;    
}

int percent_carga(TRIP trips[],NAV ships[], int id1, int id2, int maxs, int *maxt){
    int i, pcv, capb, ct=0;

    for(i=0;i<*maxt;i++){
        if (id1==trips[i].id_porto_o || id1==trips[i].id_porto_d){
            if (id2==trips[i].id_porto_o || id2==trips[i].id_porto_d){
                //para nos encontrarmos em cada linha com uma viagem entre os dois portos escolhidos
                capb=cap_barco(ships, trips[i].id_barco, maxs);
                pcv=trips[i].carga*capb/100;//calcula a carga que o navio transporta
                ct=ct+pcv;
            }
        }
    }
    return ct;
}


int num_viagens(TRIP trips[], int id1, int id2, int *maxt){
    int i, nviagens;

    for(i=0;i<*maxt;i++){
        if (id1==trips[i].id_porto_o || id1==trips[i].id_porto_d){
            if (id2==trips[i].id_porto_o || id2==trips[i].id_porto_d){// para nos encontrarmos em cada linha com uma viagem entre os dois portos escolhidos
                nviagens++;
            }
        }
    }
    return nviagens;
}

int carga_portos(PORT ports[], TRIP trips[], NAV ships[], int maxs, int maxp, int *maxt){
    int i, idporto1, idporto2, ct, nviagens;
    char porto1[MAX],porto2[MAX];

    printf("\n\nDeseja calcular a carga entre quais portos?\n");
    printf("Primeiro porto: ");
    scanf(" %[^\n]", porto1); 
    printf("Segundo porto: ");
    scanf(" %[^\n]", porto2);

    idporto1=idporto(ports, porto1, maxp);
    idporto2=idporto(ports, porto2, maxp);
    nviagens=num_viagens(trips, idporto1, idporto2, maxt);
    ct=percent_carga(trips, ships, idporto1, idporto2, maxs, maxt);
    printf("\n\nA carga total de %d kg transportada entre %s e %s em %d viagens\n", ct, porto1, porto2, nviagens);
}

float combustivel(NAV ships[], int D, int maxs){
    int i;
    float K;

    for(i=0;i<maxs;i++){
        if(D==ships[i].id){
            K=ships[i].consumo_comb; // vai buscar a struct dos ships o valor do consumo de combusivel
        }
    }
    return K;
}

float custopessoal(NAV ships[], int D, int maxs){
    int i;
    float K;

    for(i=0;i<maxs;i++){
        if(D==ships[i].id){
            K=ships[i].custo_p; // vai buscar a struct dos ships o valor do custo do pessoal
        }
    }
    return K;
}
int custoporto(PORT ports[], int D, int maxp){
    int i, dock;

    for(i=0;i<maxp;i++){
        if(D==ports[i].id){
            dock=ports[i].custo_dock; // vai buscar a struct dos ports o valor do custo do docking
        }
    }
    return dock;
}

void rendimento(TRIP trips[], PORT ports[], NAV ships[], int maxs, int maxp, int *maxt){
    int i, idv, duracao, dockd, docko, lucro;
    float cpessoal, conscomb, pagamento;

    printf("\nDiga o id da viagem que deseja calcular o rendimento\n");
    scanf("%d", &idv);
    
    for(i=0;i<*maxt;i++){
        if(idv==trips[i].id){
            pagamento=trips[i].pagamento;
            duracao=trips[i].data_c-trips[i].data_p;
            conscomb=combustivel(ships, trips[i].id_barco, maxs);
            cpessoal=custopessoal(ships, trips[i].id_barco, maxs);
            dockd=custoporto(ports, trips[i].id_porto_d, maxp);
            docko=custoporto(ports, trips[i].id_porto_o, maxp);
        }
    }
    lucro=pagamento-(dockd+docko)+(conscomb+cpessoal)*duracao;
    printf("\nUm lucro de %d será feito com esta viagem.\n", lucro);
}

int imprimircarga(TRIP trips[], int f){
    int i=0, min=1;

    while (i<=0){ //enquanto o utilizador meter números inválidos
        scanf("%d", &trips[f].carga);
        if (trips[f].carga<min){
            printf("Número inválido");
        }else{
            i++;
        }
    }
}

int imprimirpagamento(TRIP trips[], int f){
    int i=0, min=1;

    while (i<=0){ //enquanto o utilizador meter números inválidos
        scanf("%f", &trips[f].pagamento);
        if (trips[f].pagamento<min){
            printf("Número inválido");
        }else{
            i++;
        }
    }
}

int add_viagem(TRIP trips[], int *maxt){
    FILE * viagens;
    int i=*maxt+1, j=0;
    *maxt=i;

    if((viagens=fopen("trips.txt","a"))== NULL){
        printf("\nImpossível abrir o arquivo\n\n");
    exit(1);
    }

    printf ("\nEscreva os detalhes da viagem que quer adicionar:\n");
    while (j<=0){
        printf("id viagem (Já existem %d viagens):", *maxt-1);
        scanf("%d", &trips[*maxt].id);
        if (trips[*maxt].id<*maxt || trips[*maxt].id<j){
            printf("A viagem já existe.\n");
        }else{
            j++;
        printf ("id barco (1-100):");
        imprimir (trips, &trips[*maxt].id_barco, 100);
        printf ("id porto origem (1-54):");
        imprimir (trips, &trips[*maxt].id_porto_o, 54);
        printf ("id porto destino (1-54):");
        imprimir (trips, &trips[*maxt].id_porto_d, 54);
        printf ("data partida (1-31):");
        imprimir (trips, &trips[*maxt].data_p, 31);
        printf ("data chegada (1-31):");
        imprimir (trips, &trips[*maxt].data_c, 31);
        printf ("carga:");
        imprimircarga (trips, *maxt);
        printf ("pagamento:");
        imprimirpagamento (trips, *maxt);
        }
    }
}
int main(){

    FILE * navios, * portos, * viagens;
    NAV ships[MAX];
    PORT ports[MAX];
    TRIP trips[MAX];
    int n, i=0, maxs, maxp, v; 
    int *maxt=NULL;
    maxt=&v;

    maxs=ler_navios(ships);
    maxp=ler_portos(ports);
    ler_viagens(trips, maxt);

    do{
        printf("\n\nO que deseja fazer?\n(1) Listar Frota\n(2) Listar Portos\n(3) Listar Viagens\n(4) Listar toda a carga de um navio num determinado periodo de dias\n(5) Guardar Viagens no ficheiro de Texto\n(6) Carga transportada entre dois portos\n(7) Analisar o rendimento economico de uma determinada viagem\n(8) Adicionar uma viagem\n(9) Adicionar uma viagem (auto)\n(0) Sair do programa)\n\n");
        scanf("%d", &n);
        switch (n){
            case 1:listar_navios(ships, maxs); break;
            case 2:listar_portos(ports, maxp); break;
            case 3:listar_viagens(trips, ports, ships, maxs, maxp, maxt); break;
            case 4:listar_cargas(trips, ships, ports, maxs, maxp, maxt); break;
            case 5:guardar_viagens(trips, maxt); break;
            case 6:carga_portos(ports, trips, ships, maxs, maxp, maxt); break;
            case 7:rendimento(trips, ports, ships, maxs, maxp, maxt); break;
            case 8:add_viagem(trips, maxt);break;
            case 9:break; //não fiz :)
            case 0:printf("Adeus!!\n\n");
            exit(1);break;
            default:printf("\nIsso não é uma opção!\n");break;
        }
    }while(i<1);
}