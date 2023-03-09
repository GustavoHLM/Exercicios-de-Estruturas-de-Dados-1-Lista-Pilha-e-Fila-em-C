//Nome: Gustavo Henrique Mendonça
//BCC 3°       Lista Dinamica- Duplamente encadeada

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Estrutura de Dados Lista Din�mica*/
struct TipoItem{
	int isbn;
	char titulo[100];
};

typedef struct TipoCelula *TipoApontador;

struct TipoCelula {
	TipoItem Item ;
	TipoApontador Prox;
    TipoApontador Ant;
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
	Lista->Ultimo->Prox->Ant=Lista->Ultimo;
    Lista->Ultimo=Lista->Ultimo->Prox;
    Lista->Ultimo->Item=x;
    Lista->Ultimo->Prox=NULL;
}

void Imprime(TipoLista Lista){
	TipoApontador Aux;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		printf("%d\t" , Aux->Item.isbn);
		printf("%s\n" , Aux->Item.titulo);
		Aux = Aux->Prox ;
	}
}

/* Retorna o endere�o de mem�ria de uma c�lula que possui 
   um item com o isbn passado como par�metro*/
TipoApontador Busca(int isbn, TipoLista Lista){
	TipoApontador Aux, p=NULL;
	Aux = Lista.Primeiro->Prox;
	while (Aux != NULL){
		if(Aux->Item.isbn==isbn)
			p=Aux;
		Aux = Aux->Prox ;
	}
	return p;
}

void AlteraP(TipoLista *lista, TipoApontador p, TipoItem x){////////exercicio 3
    lista->Primeiro->Prox->Item=x;
}

void RetiraP(TipoApontador p, TipoLista *lista, TipoItem *item) {////////exercicio 4
    TipoApontador Aux=lista->Primeiro;
	TipoApontador k;
    TipoApontador q;
    while (Aux != NULL){
		if(Aux->Prox==p){
			k=Aux;
			break;
		}
		Aux = Aux->Prox ;
	}
    
	
	if(Vazia(*lista) || k==NULL || k->Prox == NULL){ 
		printf("Erro : Lista vazia ou posicao nao existe \n"); return ;
	}
	q = k->Prox; *item = q->Item; k->Prox = q->Prox;
      
	if (k->Prox == NULL) 
		lista->Ultimo = k;
	free (q) ;
}

void ImprimeContrario(TipoLista Lista){////////exercicio 5
	TipoApontador Aux;
	Aux = Lista.Ultimo;
	while (Aux->Ant->Ant != NULL){
		printf("%d\t" , Aux->Item.isbn);
		printf("%s\n" , Aux->Item.titulo);
		Aux = Aux->Ant ;
	}
}


void InsereP(TipoLista *lista, TipoApontador p, TipoItem x){////////exercicio 6
    TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));
    aux->Prox=p->Prox;
    p->Prox=aux;
    aux->Item=x;
}

main(){
	TipoLista lista;
	TipoApontador p;
	FLVazia(&lista);
	printf("\nLista Vazia %d", Vazia(lista));
	TipoItem item;

    ////////2/////////
	item.isbn=1;strcpy(item.titulo, "Estrutura de Dados");
	Insere(item, &lista);
	item.isbn=2;strcpy(item.titulo, "Inteligencia Artificial");
	Insere(item, &lista);
	item.isbn=3;strcpy(item.titulo, "batata");
	Insere(item, &lista);
    item.isbn=4;strcpy(item.titulo, "cebola");
	Insere(item, &lista);
    item.isbn=5;strcpy(item.titulo, "beterraba");
	Insere(item, &lista);
    item.isbn=6;strcpy(item.titulo, "chiclete");
	Insere(item, &lista);
	
	printf("\n\nExibindo a Lista\n");
	Imprime(lista);			
	
    
	p=Busca(1, lista);
    //////////3/////////////
    printf("\n\n3-)Exibindo a Lista Apos a funcao AlteraP\n");
    item.isbn=1;strcpy(item.titulo, "Senhor dos aneis");
	AlteraP(&lista, p, item);
    Imprime(lista);

    ///////////4//////////
	RetiraP(p, &lista, &item);
	printf("\nItem retirado %s", item.titulo);
	
	printf("\n\n4-)Exibindo a Lista Apos a funcao Retira\n");
	Imprime(lista);	

    ///////////5///////////
    printf("\n\n5-)Exibindo a Lista Apos a funcao ImprimeContrario\n");
	ImprimeContrario(lista);

    /////////6////////////
    item.isbn=1;strcpy(item.titulo, "Alice no pais das maravilhas");
	InsereP(&lista,p, item);
    printf("\n\n6-)Exibindo a Lista Apos a funcao InsereP\n");
	Imprime(lista);

    system("pause");
    return 0;
}
