//Nome: Gustavo Henrique Mendonça
//BCC 3°       Lista Dinamica

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Estrutura de Dados Lista Din�mica*/
struct TipoItem{
	int codigo;
	char descricao[100];
    float valor;
};

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
	TipoItem Item ;
	TipoApontador Prox;
};

struct TipoLista{
	TipoApontador Primeiro , 		
		Ultimo ;
};


/* Fun��es de manipula��o da Lista Din�mica*/
void FLVazia(TipoLista *Lista){
	Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula)) ;
	Lista->Ultimo = Lista->Primeiro ; 
	Lista->Primeiro->Prox = NULL ;
}

int Vazia(TipoLista Lista){
		return(Lista.Primeiro == Lista.Ultimo);
}

void Insere (TipoItem x , TipoLista * Lista ){
	Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
	Lista->Ultimo = Lista->Ultimo->Prox;
	Lista->Ultimo->Item = x ;
	Lista->Ultimo->Prox = NULL ;
}

void Imprime(TipoLista Lista){
	TipoApontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		printf("codigo: %d\n" , Aux->Item.codigo);
		printf("descricao: %s\n" , Aux->Item.descricao);
        printf("valor: %.2f\n\n\n" , Aux->Item.valor);
		Aux = Aux->Prox ;
	}
}

main(){
	TipoLista lista;
	TipoApontador p;
	FLVazia(&lista);
	printf("\nLista Vazia %d", Vazia(lista));
	TipoItem item;
	item.codigo=568464654;strcpy(item.descricao, "carro vermelho"); item.valor=50000;
	Insere(item, &lista);
    item.codigo=534543535;strcpy(item.descricao, "carro azul"); item.valor=40000;
	Insere(item, &lista);
    item.codigo=435346564;strcpy(item.descricao, "carro rosa"); item.valor=80000;
	Insere(item, &lista);
	
	
	printf("\n\nExibindo a Lista\n");
	Imprime(lista);			

    system("pause");
    return 0;
}
