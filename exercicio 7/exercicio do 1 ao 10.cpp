/*Gustavo Henrique Mendon�a
BCC3�*/

#include<stdio.h>
#include<stdlib.h>

// Estrutura de Dados Fila Din�mica
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoItem { 
	int numero;
	int prioridade;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula; 

typedef struct TipoFila {
	TipoApontador Frente, Tras;
}TipoFila;

// Fun��es de manipula��o da Fila Din�mica
void FFVazia(TipoFila *Fila ) { 
	Fila ->Frente = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Frente; 
	Fila ->Frente ->Prox = NULL; 
}

int Vazia(TipoFila Fila ) { 
	return ( Fila.Frente == Fila.Tras) ;
}

void Enfileira (TipoItem x, TipoFila *Fila ) { 
	Fila ->Tras ->Prox = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Tras ->Prox;
	Fila ->Tras ->Item = x; 
	Fila ->Tras ->Prox = NULL; 
}

void Desenfileira(TipoFila *Fila , TipoItem *Item) { 
	TipoApontador q; 
	if (Vazia( *Fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ; return;
	} 
	q = Fila ->Frente; 
	Fila ->Frente = Fila ->Frente ->Prox; 
	*Item = Fila ->Frente ->Item; 
	free(q); 
}

void exibe (TipoFila fila){
	TipoApontador aux=fila.Frente->Prox;
	printf("\nfila:\n");
	while(aux!=NULL){
		printf("\n%d", aux->Item.numero);
		aux=aux->Prox;
	}
	printf("\n");
}

TipoApontador busca(TipoFila fila,int num){
    TipoApontador aux=fila.Frente->Prox;
    while(aux!=NULL){
        if(aux->Item.numero == num){
            return aux;
        }
        aux=aux->Prox;
    }
    return NULL;
}

//Fun��es da Pilha Dinamica

typedef struct TipoCelula *TipoApontadorP; 
typedef struct { 
    int numero;
	int prioridade;
}TipoItemP; 

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


/* 1. Receba uma Fila de n�meros (n�o ordenada) e mova a c�lula que 
   cont�m o maior valor para a primeira posi��o (com informa��o v�lida) 
   da Fila.
*/
void moveMaior(TipoFila *fila){
	TipoApontador aux=fila->Frente, antesMaior=fila->Frente, p;
	int maior=fila->Frente->Prox->Item.numero;
	
	while(aux->Prox!=NULL){
		if(aux->Prox->Item.numero > maior){
			antesMaior=aux;
			maior=aux->Prox->Item.numero;
		}
		aux=aux->Prox;
	}
	p=antesMaior->Prox;
	antesMaior->Prox=p->Prox;
	p->Prox=fila->Frente->Prox;
	fila->Frente->Prox=p;
}

/*2.  Receba  um  TipoItem  e  uma  fila  e  uma  fila  e  retorne  1,  se  o  item  estiver  presente  na  fila,  ou  0,  caso 
contrário. */
int itemPresente(TipoFila fila, TipoItem item){
    TipoApontador aux=fila.Frente->Prox;
    while(aux!=NULL){
        if(aux->Item.numero == item.numero){
            return 1;
        }
        aux=aux->Prox;
    }
    return 0;
}

/*3.  Simule  a  função  FuraFila  (TipoFila  *fila,  TipoItem  x),  que  insere  um  item  na  primeira  posição  da  fila. 
Observe que, neste caso, estaremos desrespeitando o conceito de FILA: primeiro a entrar é o primeiro a 
sair. */
void FuraFilanaprimeira(TipoFila *fila, TipoItem item){

    TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));
    aux->Item=item;
    aux->Prox = fila->Frente->Prox;
    fila->Frente->Prox=aux;
 
}

/*4.  Simule a função FuraFila (TipoFila *fila, TipoApontador p, TipoItem x), que insere um item na fila após a 
posição apontada por p (sentido frente -> trás).*/
void FuraFila(TipoFila *fila, TipoItem item, TipoApontador p){
    if(fila->Tras == p){
        Enfileira(item,fila);
    }else{
        TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));
        aux->Item=item;
        aux->Prox = p->Prox;
        p->Prox=aux;
    }
 
}

/*5.Retorne 1 se os elementos de uma fila dinâmica estiverem em ordem crescente. Caso contrário a função deve retornar 0. A fila deverá ser passada para a função como passagem de parâmetros por valor.*/
int ordemcres(TipoFila fila){
	TipoApontador aux=fila.Frente->Prox;

	while(aux!=NULL){

		if(aux->Item.numero>aux->Prox->Item.numero){
			return 0;
		}

		aux=aux->Prox;
	}
	return 1;
}
/* 6.Receba uma Fila de caracteres (não ordenada) e mova a célula que contém o maior valor para a primeira posição (com informação válida) da Fila.*/
void moveMaior2(TipoFila *fila){
	TipoApontador aux=fila->Frente, antesMaior=fila->Frente, p;
	int maior=fila->Frente->Prox->Item.numero;
	
	while(aux->Prox!=NULL){
		if(aux->Prox->Item.numero > maior){
			antesMaior=aux;
			maior=aux->Prox->Item.numero;
		}
		aux=aux->Prox;
	}
	p=antesMaior->Prox;
	antesMaior->Prox=p->Prox;
	p->Prox=fila->Frente->Prox;
	fila->Frente->Prox=p;
}

/*7.  Receba  duas  Filas  dinâmicas  (A  e  B)  e  gere  uma  terceira  Fila  (passada  como  parâmetro)  que  seja  a 
diferença entre A e B, ou seja, os elementos que pertencem a A e não pertencem a B.*/
void criaterceira(TipoFila fila, TipoFila fila2, TipoFila *fila3){
	TipoApontador aux=fila.Frente->Prox;
	TipoApontador aux2=fila2.Frente->Prox;
	while(aux!=NULL){
		if(aux->Item.numero != aux2->Item.numero){
			Enfileira(aux->Item,fila3);
		}
		aux=aux->Prox;
		aux2=aux2->Prox;
	}
}

/*8.  Receba  duas  Filas  dinâmicas  (A  e  B)  e  gere  uma  terceira  Fila  (como  passagem  de  parâmetro  por  referência)  que  seja  a  interseção  entre  A  e  B,  ou  seja,  os  elementos  que  pertencem  a  A  e  também pertencem a B.*/

void criaterceira2(TipoFila fila, TipoFila fila2, TipoFila *fila3){
	TipoApontador aux=fila.Frente->Prox;

	while(aux!=NULL){
		Enfileira(aux->Item,fila3);
		aux=aux->Prox;
	}
	aux=fila2.Frente->Prox;
	while(aux!=NULL){
		Enfileira(aux->Item,fila3);
		aux=aux->Prox;
	}
}

/*9. Simule  uma  Fila  com  prioridade.  Adicione  o  campo  int  prioridade  no  TipoItem.  A  função  desenfileira 
deverá dar prioridade a itens com o campo prioridade == 1.*/

void Desenfileira2(TipoFila *fila , TipoItem *item) { 
	if (Vazia( *fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ;
	} 
	TipoApontador aux=fila->Frente->Prox;

	while(aux!=NULL){
		if(aux->Item.prioridade==1){
			Desenfileira(fila,item);
			break;
		}
		aux=aux->Prox;
	}
	
}

/*10.  Receba uma fila dinâmica e inverta a ordem da fila recebida utilizando uma pilha. O TipoItem será o mesmo para as duas estruturas. */
///Arquivo separada apenas com a fun��o
void Inverte(TipoFila *fila){
	TipoApontador aux= fila->Frente->Prox;
	TipoItem x;
	TipoPilha pilha; FPVazia(&pilha);
	
	while(aux!=NULL){
        Empilha(aux->Item, &pilha);
        aux=aux->Prox;
    }
	FFVazia(fila);
	while(!VaziaP(pilha)){
		Desempilha(&pilha, &x);
		Enfileira(x, fila);
	}
}


main(){
	TipoFila fila,fila2,fila3,fila4;
	FFVazia(&fila);
	FFVazia(&fila2);
	FFVazia(&fila3);
	FFVazia(&fila4);
	TipoItem item;
    int num=6;
    TipoApontador p;
    
	item.numero=6; item.prioridade=0; Enfileira(item, &fila);
	item.numero=7; item.prioridade=1; Enfileira(item, &fila);
	item.numero=3; item.prioridade=0;Enfileira(item, &fila);
	item.numero=1; item.prioridade=0;Enfileira(item, &fila);
    exibe(fila);
	
	item.numero=3;item.prioridade=0;
    printf("\n\n2)Item presente: %i\n", itemPresente(fila,item));

    printf("\n3) Colocar Item no primeiro:\n" );
	item.numero=85;item.prioridade=0;
	FuraFilanaprimeira(&fila,item);
	exibe(fila);

    item.numero = 1;item.prioridade=0;
    p = busca(fila,num);
    printf("\n\n4) FuraFila\n");   
    FuraFila(&fila,item,p);
    exibe(fila);

	printf("\n\n5)Presente: %i\n",ordemcres(fila));

	printf("\n\n6) move o item: \n");
	moveMaior2(&fila);

	FFVazia(&fila);
	item.numero=4; item.prioridade=0;Enfileira(item, &fila);
	item.numero=5; item.prioridade=0;Enfileira(item, &fila);
	item.numero=6; item.prioridade=1;Enfileira(item, &fila);
	item.numero=10; item.prioridade=0;Enfileira(item, &fila);

	item.numero=4; item.prioridade=0;Enfileira(item, &fila2);
	item.numero=5; item.prioridade=0;Enfileira(item, &fila2);
	item.numero=9; item.prioridade=0;Enfileira(item, &fila2);
	item.numero=11; item.prioridade=0; Enfileira(item, &fila2);

	printf("\n\n7)Diferenca entre a Fila A e B\n");

	criaterceira(fila,fila2,&fila3);
	exibe(fila3);

	printf("\n\n8)Intersecao da fila A e B\n");

	criaterceira2(fila,fila2,&fila4);
	exibe(fila4);

	printf("\n\n9) Prioridade dos itens\n");

	Desenfileira2(&fila,&item);
	exibe(fila);
	
	printf("\n\n10) Inverter usando Pilha\n");
	FFVazia(&fila);
	item.numero=4; item.prioridade=0;Enfileira(item, &fila);
	item.numero=5; item.prioridade=0;Enfileira(item, &fila);
	item.numero=6; item.prioridade=1;Enfileira(item, &fila);
	item.numero=10; item.prioridade=0;Enfileira(item, &fila);

	Inverte(&fila);
	exibe(fila);
}
