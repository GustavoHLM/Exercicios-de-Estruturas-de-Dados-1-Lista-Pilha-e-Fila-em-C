#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 10

typedef int TipoApontador;
typedef struct {
	int cod;
	float valor;
	char operacao[20];
} TipoItem ;

typedef struct {
	TipoItem item [ MAXTAM ] ;
	TipoApontador frente, tras ;
} TipoFila;


//Funções da Pilha Dinamica

typedef struct TipoCelula *TipoApontadorP; 
typedef struct { 
    char chave; 
}TipoItemP; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontadorP Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontadorP  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;

void FPVazia(TipoPilha *Pilha) { 
	Pilha->Topo=(TipoApontadorP) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int VaziaP(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontadorP Aux; 
	Aux = (TipoApontadorP) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++;
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontadorP q; 
	if (VaziaP( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

//


void FFVazia( TipoFila *fila ){
	fila->frente = 1;
	fila->tras = fila->frente ;
}

int Vazia(TipoFila fila){
	return (fila.frente == fila.tras);
}

void Enfileira (TipoItem x, TipoFila * fila){
	if(fila->tras % MAXTAM + 1 == fila->frente)
			printf("Erro fila esta cheia \n" ) ;
	else {
             fila->item[fila->tras-1]=x;
             fila->tras=fila->tras%MAXTAM+1;
     }
}

void Desenfileira ( TipoFila * fila , TipoItem * item){
	if(Vazia(*fila))
		    printf("Erro fila esta vazia \n" ) ;
	else {
			 *item=fila->item [fila->frente - 1];
			 fila->frente = fila->frente % MAXTAM+1;
	}
}

void exibe (TipoFila fila){
	int i;	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		printf("\n\nItem==%i\t", fila.item[i-1].cod);
		printf("Item==%s\t", fila.item[i-1].operacao);
		printf("Item==%f", fila.item[i-1].valor);
	}
}


/*1. Receba um TipoItem e uma fila e retorne 1 se o item estiver presente na fila, ou 0, caso contrário.*/

int presente (TipoFila fila, TipoItem x){
	int i;	
	for(i=fila.frente;i != fila.tras; i=i% MAXTAM+1){
		if(fila.item[i-1].cod==x.cod){/// Analisarei apenas o codigo
			return 1;
		}
	}
	return 0;
}

/*2. Receba uma fila, um item e retorne a posição do vetor que o item se encontra na fila. Caso o item não
esteja presente na fila, a função deve retornar um valor negativo.*/


TipoApontador busca (TipoFila fila, TipoItem x){
	TipoItem y;
	TipoApontador p;
	int i;	
	while(!Vazia(fila)){
		Desenfileira(&fila, &y);
		if(y.cod==x.cod){
			p=fila.frente;
		}
	}
	return p;
}


/*3. Receba uma fila estática e retorne o código do item com maior valor de saque.*/

int maior (TipoFila fila){
	TipoItem y;
	float maior=fila.item[1].valor;
	int cod;

	int i;	
	while(!Vazia(fila)){
		Desenfileira(&fila, &y);
		if(maior<y.valor){
			maior=y.valor;
			cod=y.cod;
			
		}
	}
	return cod;
}

/*4. Receba uma fila estática e retorne o valor do maior depósito realizado.*/

float maiorDeposito (TipoFila fila){
	TipoItem y;
	float maior=fila.item[1].valor;

	int i;	
	while(!Vazia(fila)){
		Desenfileira(&fila, &y);
		if(maior<y.valor && strcmp(y.operacao,"deposito")==0){
			maior=y.valor;
		}
	}
	return maior;
}

/*5. Receba uma fila estática e retorne quantas operações de pagamento foram feitas.*/

int pagamento (TipoFila fila){
	TipoItem y;
	int cont=0, i;
	while(!Vazia(fila)){
		Desenfileira(&fila, &y);
		if(strcmp(y.operacao,"pagamento")==0){
			cont++;
		}
	}
	return cont;
}

/*6. Receba uma fila estática e uma operação (char op[20]). Retorne o valor total dos itens para a operação
passada como parâmetro.*/

float SomaOperacao (TipoFila fila, char op[]){
	TipoItem y;
	float soma=0;

	int i;	
	while(!Vazia(fila)){
		Desenfileira(&fila, &y);
		if(strcmp(y.operacao, op)==0){
			soma+=y.valor;
		}
	}
	return soma;
}

/*7. Receba uma fila estática e inverta a ordem da fila recebida utilizando uma pilha dinâmica. O TipoItem
será o mesmo para as duas estruturas.*/

void Inverte(TipoFila *fila){
	int i;
	TipoItem x;
	TipoItemP y;
	TipoPilha pilha; FPVazia(&pilha);
	
	for(i=fila->frente;i != fila->tras; i=i% MAXTAM+1){
		Empilha(fila->item[i-1], &pilha);
	}
	FFVazia(fila);
	while(!VaziaP(pilha)){
		Desempilha(&pilha, &x);
		Enfileira(x, fila);
	}
}

main(){
	TipoFila fila;
	FFVazia(&fila);
	TipoItem item;
	item.cod=1;item.valor=1100; strcpy(item.operacao, "pagamento"); Enfileira(item, &fila);
	item.cod=2;item.valor=200; strcpy(item.operacao, "deposito"); Enfileira(item, &fila);
	item.cod=3;item.valor=400; strcpy(item.operacao, "deposito"); Enfileira(item, &fila);
	item.cod=4;item.valor=700; strcpy(item.operacao, "pagamento"); Enfileira(item, &fila);
	item.cod=5;item.valor=500; strcpy(item.operacao, "deposito"); Enfileira(item, &fila);
	printf("\nExibindo a fila\n");
	exibe(fila);
	
	item.cod=3;item.valor=100; strcpy(item.operacao, "saque");
	printf("\n\n1-)R:%i", presente(fila, item));
	
	item.cod=2;item.valor=100; strcpy(item.operacao, "saque"); 
	printf("\n\n2-)R:%i", busca(fila, item));
	
	printf("\n\n3-)R:%i", maior(fila));
	
	printf("\n\n4-)R:%f", maiorDeposito(fila));
	
	printf("\n\n5-)R:%i", pagamento(fila));
	
	printf("\n\n6-)R:%f", SomaOperacao(fila, (char*)"deposito"));
	
	
	printf("\n\n7-)R:");
	Inverte(&fila);
	exibe(fila);
	
	
	
}


