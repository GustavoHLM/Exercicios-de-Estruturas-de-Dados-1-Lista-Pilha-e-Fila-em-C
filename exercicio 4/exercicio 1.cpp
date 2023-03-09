/*GUSTAVO HENRIQUE MENDONÇA
BCC3° EXERCICIO PILHA ESTATICA*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAXTAM 99
// Estrutura Pilha estï¿½tica
typedef int TipoApontador; 
typedef struct { 
    char chave; 
}TipoItem; 

typedef struct { 
    TipoItem itens[MAXTAM] ; 
    TipoApontador topo; 
} TipoPilha;


// Funï¿½ï¿½es de manipulaï¿½ï¿½o da pilha
void FPVazia(TipoPilha *pilha) { 
	pilha ->topo = 0; 
} 

int Vazia(TipoPilha pilha) {
	 return (pilha.topo == 0); 
}

void Empilha(TipoItem x, TipoPilha *pilha) {
	if (pilha ->topo == MAXTAM) 
			printf ("Erro : pilha esta cheia\n");
	 else{
			pilha ->topo++; 
			pilha ->itens[pilha ->topo - 1] = x ;
		 }
}

void Desempilha(TipoPilha *pilha , TipoItem *Item) { 
		if (Vazia(*pilha)) 
				printf ( "Erro : pilha esta vazia\n" ); 
		else { 
				*Item = pilha ->itens[pilha->topo - 1]; 
				pilha ->topo--; 
		}
}

int Tamanho(TipoPilha pilha) {
	return (pilha.topo) ; 
}

void exibePilha(TipoPilha pilha){
	int i;
	for(i=pilha.topo-1;i>=0;i--){
		printf("\n%d - %c", i, pilha.itens[i].chave);
	}
}

void String(TipoPilha *pilha, char string[]){
	int i; TipoItem x;
	for(i=0;i<strlen(string); i++){
		x.chave=string[i];
		Empilha(x, pilha);
	}
}

int paridade(TipoPilha *pilha){
    int i, count=0;
    TipoItem x;
    for(i=pilha->topo-1; i>=0 ;i--){
        if(pilha->itens[i].chave=='('){
			count++;
		}
		if(pilha->itens[i].chave==')'){
			count--;		
		}
    }
    FPVazia(pilha);
	if(count==0){
		return 1;
	}
	return 0;
}

void EmpilhaVogal(TipoPilha *pilha, char palavra[]){
	int i, j;
	TipoItem x;
	char vogal[10];
	strcpy(vogal, "aeiouAEIOU");
	for(i=0;i<=sizeof(palavra); i++){
		for(j=0; j<10; j++){
			if(palavra[i]==vogal[j]){
				x.chave=palavra[i];
				Empilha(x, pilha);
			}
		}
	}
}

void PalavraInvert(TipoPilha *pilha, char palavra[]){
	int i, j;
	TipoItem x;
	j=0;
	for(i=pilha->topo;i>=0;i--){
		palavra[j]=pilha->itens[i-1].chave;
		j++;
	}
}

void ErguePilha(TipoPilha *pilha, TipoApontador p, TipoItem x){
	TipoItem auxItem;
	TipoPilha aux;
	FPVazia(&aux);

	int i;
	for(i=0;i<p;i++){
		auxItem.chave=pilha->itens[i].chave;////Adiciona os itens no aux até antes do P
		Empilha(auxItem, &aux);
	}
	
	auxItem.chave=x.chave;//////Coloca o aux antes do P
	Empilha(auxItem, &aux);
	
	for(i=p; i<(pilha->topo); i++){
		auxItem.chave=pilha->itens[i].chave;////Adiciona o resto dos itens no aux
		Empilha(auxItem, &aux);
	}
	FPVazia(pilha);
	for(i=0;i<(aux.topo); i++){
		auxItem.chave=aux.itens[i].chave;////Coloca a mudança do aux no pilha
		Empilha(auxItem, pilha);
	}
}

int Crescente(TipoPilha pilha){
	TipoItem x;
	while(1){
		if((pilha.topo) < (pilha.topo-1)){
			return 0;
		}	
		
		Desempilha(&pilha, &x);
		if(pilha.topo==0){
			break;
		}
	}
	return 1;
}

int BuscaItem(TipoPilha pilha, TipoPilha pilha2, TipoItem x){
	int i;TipoItem aux;
	while(1){
		i=pilha.topo;
		if(pilha.itens[i].chave == x.chave){
			break;	
		}	
		Desempilha(&pilha, &aux);
		if(pilha.topo==0){
			return 0;
		}
	}
	while(1){
		i=pilha2.topo;
		if(pilha2.itens[i].chave==x.chave){
			break;
		}	
		Desempilha(&pilha2, &aux);
		if(pilha2.topo==0){
			return 0;
		}
	}
	
	return 1;
}

int PilhasComparar(TipoPilha pilha1, TipoPilha pilha2){///////Esta pergunta da 4 ficou identica a da 8 irei considerar apenas esta
	
	int aux=0;
	TipoItem x1, x2;
	
	while(1){
		Desempilha(&pilha1, &x1);
		Desempilha(&pilha2, &x2);
		if(Vazia(pilha1)==1||Vazia(pilha2)==1){
			aux=1;
			break;
		}
		if(x1.chave!=x2.chave)break;
	}
	if(aux==1&&Vazia(pilha1)==1 && Vazia(pilha2)==1){
		return 1;
	}
	return 0;
}


main(){
    int i, perg;
	TipoItem item;
	TipoPilha pilha;
	FPVazia(&pilha);
	setlocale(LC_ALL, "Portuguese");
	char palavra[50];
	
	TipoPilha pilha2;
	FPVazia(&pilha2);
	
	do{
		system("cls");
		printf("\n\n1. Teste a paridade de parenteses em uma expressão aritmetica (String) utilizando uma pilha. Ex: ((X+Y)+Z)/28*/");
		printf("\n\n2. Receba uma string (char palavra[50]) e uma Pilha. A função deve empilhar as vogais presentes na string recebida.");
		printf("\n\n3. Receba uma string (char palavra[50]) e inverta a ordem da string recebida utilizando uma pilha.");
		printf("\n\n4. Retorne 1 se duas pilhas estaticas recebidas forem iguais, caso contrario retorne 0. Use a função desempilha.");
		printf("\n\n5. Implemente a função erguePilha (TipoPilha pilha, TipoApontador p, TipoItem item), que recebe uma posição da pilha p e insira o item recebido abaixo de p.");
		printf("\n\n6. Receba uma pilha e retorne 1 (um), caso a pilha esteja composta por todos os itens em ordem crescente, ou 0 (zero), caso contrÃ¡rio. Use apenas a função desempilha para acessar os itens da pilha.");
		printf("\n\n7. Receba duas pilhas (P1 e P2), um item (TipoItem item) e retorne 1 (um), caso o item esteja presente nas duas pilhas, ou 0 (zero), caso contrario. Use apenas a funÃ§Ã£o desempilha para acessar os itens da pilha.");
		printf("\n\n8. Iqual a 4 não fiz denovo");
		printf("\n\n9. Não Consegui");
		printf("\n\n10. Não Consegui");
		
		printf("\n\nCodigo:");
		scanf("%i", &perg);
		
		if(perg==6){/////Não consigo adicionar mais cases// Questão 6
			strcpy(palavra, "123456789 ");///O espaço na frente é para não bugar a função String por causa do /0
			String(&pilha, palavra);
			printf("\n\nR:(1 eh crescente, 0 não eh): %i\n\n", Crescente(pilha));
			FPVazia(&pilha);
			system("pause");	
		}
		if(perg==7){// Questão 7
			strcpy(palavra, "carvalho ");///O espaço na frente é para não bugar a função String por causa do /0
			String(&pilha, palavra);
			
			strcpy(palavra, "abobora ");///O espaço na frente é para não bugar a função String por causa do /0
			String(&pilha2, palavra);
			
			item.chave='a';//// Mude  para alterar a buscar
			
			printf("\n\nR:(1 existe, 0 não tem o item): %i\n\n", BuscaItem(pilha, pilha2, item));
			FPVazia(&pilha);
			system("pause");	
		}

		switch(perg){

			case 1:
				char algebra[20];
    			printf("\n\nExpressao: ");
    			fflush(stdin);
    			gets(algebra);
    			String(&pilha, algebra);
				printf("\n1 existe paridade, 0 nao existe: %i\n", paridade(&pilha));
				FPVazia(&pilha);
				system("pause");
			break;

			case 2:
				printf("\nDigite a palavra para empilhar: ");
				fflush(stdin);
				gets(palavra);
				EmpilhaVogal(&pilha, palavra);
				exibePilha(pilha);
				printf("\n\n");
				FPVazia(&pilha);
				system("pause");
			break;
			
			case 3:
				printf("\nDigite a palavra para empilhar invertido: ");
				fflush(stdin);
				gets(palavra);
				String(&pilha, palavra);
				PalavraInvert(&pilha, palavra);
				exibePilha(pilha);
				printf("\n\nR:%s\n", palavra);
				FPVazia(&pilha);
				system("pause");
				
			break;
			
			case 4:
				char pi1[50], pi2[50];
				strcpy(pi1, "gustavo");strcpy(pi2, "gustvo");
				String(&pilha, pi1); String(&pilha2, pi2);
				printf("\nR:(1 são iguais, 0 são diferentes): %i\n\n", PilhasComparar(pilha, pilha2));
				FPVazia(&pilha);
				system("pause");
				
			break;
			
			case 5:
				char insere[50];
				strcpy(insere,"gustavo");
				String(&pilha, insere);
				printf("\nA palavra usada será W: \n\n Pilha criada");
				TipoApontador p=6;////Mude o valor do ponteiro para altera a pilha
				item.chave='w';
				exibePilha(pilha);
				ErguePilha(&pilha, p, item);
				printf("\n\n Pilha Modificada");
				exibePilha(pilha);
				printf("\n\n");
				FPVazia(&pilha);
				system("pause");
			break;
		}	
	}while(perg!=0);

}

