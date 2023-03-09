/*Pilha Dinamica Exercicio do 1 ao 11
Gustavo Henrique Mendonça
BCC3°*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTAM 5
// Estrutura Pilha estática
typedef struct { 
    char chave; 
}TipoItem; 

typedef struct TipoCelula *TipoApontador; 

typedef struct TipoCelula { 
	TipoItem Item; 
	TipoApontador Prox; 
} TipoCelula; 

typedef struct { 
	TipoApontador  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;


// Funções de manipulação da pilha dinâmica

void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem x, TipoPilha *Pilha) { 
	TipoApontador Aux; 
	Aux = (TipoApontador) malloc(sizeof(TipoCelula)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++;
}

void Desempilha(TipoPilha *Pilha , TipoItem *Item) {
	TipoApontador q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

int Tamanho(TipoPilha Pilha) { 
	return ( Pilha .Tamanho) ; 
}

void exibePilha(TipoPilha pilha){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		printf("\n%c", aux->Item.chave);
		aux=aux->Prox;
	}
}

TipoApontador busca(TipoPilha pilha, TipoItem item){
	TipoApontador aux=pilha.Topo->Prox;
	while(aux!=NULL){
		if(aux->Item.chave==item.chave);
			return aux;
		aux=aux->Prox;		
	}
	return NULL;
}
void PreenchePilha(TipoPilha *pilha, char string[]){
	TipoItem item;
	FPVazia(pilha);
	int i=0;
	while(i<strlen(string)){
		item.chave=string[i]; Empilha(item, pilha);
		i++;
	}
			
	
}
int forma(TipoPilha *pilha){//////Questao 1
	TipoItem x;
	TipoApontador p= pilha->Topo->Prox;
	
	while(1){
		if(p->Item.chave == p->Prox->Prox->Item.chave){
			return 1;
		}
		if(Vazia(*pilha)){
			break;
		}
		Desempilha(pilha, &x);
	}	
	return 0;
}

int comparar(TipoPilha *pilha1, TipoPilha *pilha2){///////Questão 2
	char p,q;
	TipoItem x;	

	while(pilha1->Tamanho>0 || pilha2->Tamanho>0 ){
		p=pilha1->Topo->Prox->Item.chave;
		q=pilha2->Topo->Prox->Item.chave;
		if(p==q){
			Desempilha(pilha1, &x);
			Desempilha(pilha2, &x);
		}else{
			return 0;
		}
	}

	return 1;
}

int polindromo(TipoPilha *pilha, char string[]){////////Questão 3 
	char p;
	TipoItem item;
	FPVazia(pilha);
	int i=0;
	while(i<strlen(string)){
		item.chave=string[i]; Empilha(item, pilha);
		i++;
	}
	i=0;
	while(pilha->Tamanho>0){
		p=pilha->Topo->Prox->Item.chave;
		if(p!=string[i]){
			return 0;
		}
		i++;
		Desempilha(pilha, &item);
	}
	return 1;
}

TipoApontador posicao(TipoPilha pilha, TipoItem x){
	TipoApontador p=pilha.Topo->Prox;	
	while(p!=NULL){
		if(p->Item.chave==x.chave){
			return p;
		}
		p=p->Prox;
	}
	return NULL;
}

int crescente(TipoPilha *pilha){
	TipoItem x;
	char p,q;
	while(pilha->Tamanho > 1){
		p=pilha->Topo->Prox->Item.chave;
		q=pilha->Topo->Prox->Prox->Item.chave;
		if(p<q){
			return 0;
		}
		Desempilha(pilha, &x);	
	}
	return 1;
}

int presente (TipoPilha pilha1, TipoPilha pilha2, TipoItem x){//// Questao 7
	TipoItem y; int cont=0;
	while(!Vazia(pilha1)){
		Desempilha(&pilha1, &y);
		if(y.chave==x.chave){
			cont++;
			break;
		}
	}
	while(!Vazia(pilha2)){
		Desempilha(&pilha2, &y);
		if(y.chave==x.chave){
			cont++;
			break;
		}
	}
	if(cont==2){
		return 1;
	}
	return 0;
}

void vogal(TipoPilha *pilha){
	TipoItem x;
	TipoPilha aux;
	FPVazia(&aux);
	int i;
	while(!Vazia(*pilha)){
		Desempilha(pilha, &x);
		if(x.chave!='a' && x.chave!='e' && x.chave!='i' && x.chave!='o' && x.chave!='u'){
			Empilha(x, &aux);
		}
	}
	while(!Vazia(aux)){
		Desempilha(&aux, &x);
		Empilha(x, pilha);
	}
}

void FuraPilha(TipoPilha *pilha, TipoApontador p, TipoItem x){
	TipoItem auxItem;
	TipoPilha aux;
	FPVazia(&aux);
	while(!Vazia(*pilha)){
		Desempilha(pilha, &auxItem);
		Empilha(auxItem, &aux);
		if(pilha->Topo->Prox == p){
			Empilha(x, &aux);
		}
	}
	while(!Vazia(aux)){
		Desempilha(&aux, &auxItem);
		Empilha(auxItem, pilha);
	}	
}

void inverte(TipoPilha *pilha, char string[]){ 
	TipoItem x;
	FPVazia(pilha);
	char aux[50];
	
	int i;
	for(i=0;i<strlen(string);i++){
		x.chave=string[i]; Empilha(x, pilha);
	}
	i=0;
	while(!Vazia(*pilha)){
		Desempilha(pilha, &x);
	 	aux[i]=x.chave;
		i++;
	}
	aux[i]='\0';
	printf("%s", aux);
}

void RetiraC(TipoPilha pilha){
	TipoItem x;
	TipoPilha aux; FPVazia(&aux);
	while(!Vazia(pilha)){
		Desempilha(&pilha, &x);
		if(x.chave!='c'){
			Empilha(x, &aux);
		}
	}
	while(!Vazia(aux)){
		Desempilha(&aux, &x);
		Empilha(x, &pilha);
	}
	exibePilha(pilha);
	printf("\n\n");
}
	


main(){
	TipoItem item;
	TipoPilha pilha;
	TipoPilha pilha2;
	
	PreenchePilha(&pilha, (char*)"ababab");			
	printf("\nQuestao 1: %i", forma(&pilha));
	
	PreenchePilha(&pilha, (char*)"ababab");
	PreenchePilha(&pilha2, (char*)"ababay");
	printf("\n\nQuestao 2: %i", comparar(&pilha, &pilha2));
	printf("\n\nQuestao 3: %i", polindromo(&pilha, (char*)"subinoonibus"));
	exibePilha(pilha);
	
	PreenchePilha(&pilha, (char*)"abcdefghi");
	item.chave='a';
	printf("\n\nQuestao 5: %p", posicao(pilha, item));
	
	printf("\n\nQuestao 6: %i", crescente(&pilha));
	
	PreenchePilha(&pilha, (char*)"abcde");
	PreenchePilha(&pilha2, (char*)"abcde");
	item.chave='c';
	printf("\n\nQuestão 7: %i", presente(pilha, pilha2, item));
	
	PreenchePilha(&pilha, (char*)"abcdefg");
	vogal(&pilha);
	printf("\n\nQuestão 8:\n\n");
	exibePilha(pilha);
	
	printf("\n\nQuestão 9:\n");
	PreenchePilha(&pilha, (char*)"abcdefg");
	item.chave='c';
	TipoApontador p=posicao(pilha, item);
	item.chave='w';
	FuraPilha(&pilha, p, item);
	exibePilha(pilha);
	
	printf("\n\nQuestão 10:\n");
	inverte(&pilha, (char*)"bolo de chocolate");
	
	printf("\n\nQuestão 11:\n");
	PreenchePilha(&pilha, (char*)"chocolate de cacau");
	RetiraC(pilha);
	
	system("pause");
	return 0;
}
