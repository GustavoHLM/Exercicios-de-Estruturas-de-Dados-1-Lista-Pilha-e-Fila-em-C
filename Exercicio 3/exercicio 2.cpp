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

TipoApontador buscaCod(TipoLista lista, int cod){////////Letra A
    TipoApontador aux;
    aux=lista.Primeiro->Prox;
    while (aux!=NULL){
        if(cod==aux->Item.codigo){
            return aux;
        }
        aux=aux->Prox;
    }
    return 0;
}

TipoApontador buscaDes(TipoLista lista, char des[100]){////////Letra B
    TipoApontador aux, p=NULL;
    aux=lista.Primeiro->Prox;
    while (aux!=NULL){
        if(strcmp(des, aux->Item.descricao)==0){
            return aux;
        }
        aux=aux->Prox;
    }
    strcpy(des, "vermelho");
    return p;
}

int maiorPar(TipoLista lista, TipoLista c){////////Letra C
    int count1=0, count2=0;
    TipoApontador aux1, aux2;
    aux1=lista.Primeiro->Prox;
    aux2=lista.Primeiro->Prox;

    while(aux1!=NULL){
        if(aux1->Item.codigo%2==0){
            count1++;
        }

        aux1=aux1->Prox;
    }

    while(aux2!=NULL){
        if(aux2->Item.codigo%2==0){
            count2++;
        }
        aux2=aux2->Prox;
    }

    if(count1>count2){
        return 1;
    }else if(count2>count1){
        return 2;
    }else{
        return 0;
    }
}

void InsereP(TipoLista *lista, TipoApontador p, TipoItem x){////////Letra D
    TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));
    aux->Prox=p->Prox;
    p->Prox=aux;
    aux->Item=x;
}

void troca(TipoApontador p, TipoApontador q){////////Letra E
    TipoItem aux;
    aux=p->Item;
    p->Item=q->Item;
    q->Item=aux;
}

void InserirCab(TipoLista *lista, TipoItem x){////////Letra F
    TipoApontador q = lista->Primeiro;
    TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));
    lista->Primeiro->Item = x;
    aux->Prox= q;
    lista->Primeiro = aux;
}

int Vazia(TipoLista Lista){
	return(Lista.Primeiro == Lista.Ultimo);
}

void RetiraP(TipoApontador p, TipoLista *lista, TipoItem *item) {////////Letra G
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

void RetirarPar(TipoLista *lista){////////Letra H
    TipoApontador Aux=lista->Primeiro->Prox,p,q;
	
    while (Aux != NULL){
		if(Aux->Item.codigo%2==0){
            printf("\no item --%s-- eh par e foi retirado\n",Aux->Item.descricao);
			RetiraP(Aux, lista,&Aux->Item);
        }
		Aux = Aux->Prox ;
	}
}

int comparaListas(TipoLista lista, TipoLista lista2){////////Letra I
    TipoApontador p=lista.Primeiro->Prox;
    int count1=0,count2=0;

    while(p!=NULL){
        count1++;
        p=p->Prox;
    }
    p=lista2.Primeiro->Prox;
    while(p!=NULL){
        count2++;
        p=p->Prox;
    }
    if(count1>count2){
        return 1;
    }else if(count2>count1){
        return 2;
    }else{
        return 0;
    }
}

int ordenado(TipoLista lista){////////Letra J
    TipoApontador p=lista.Primeiro->Prox;/////q=p->Prox irá comparar o proximo valor, caso seja maior que o anterior, significa que a ordem não é crescente
    int maior=lista.Primeiro->Prox->Item.codigo;
    
    while(p->Prox!=NULL){
        if((p->Item.codigo) > (p->Prox->Item.codigo)){/////Irá comparar se p>q caso seja, não é crescente
            return 0;
        }
        p=p->Prox;
    }
    return 1;
}

void ContatenarLista(TipoLista lista,TipoLista lista2, TipoLista *lista3){////////Letra K
	TipoItem item;
	TipoApontador Aux=lista.Primeiro->Prox;

    while (Aux != NULL){
		item=Aux->Item;
		Insere(item, lista3);
		Aux = Aux->Prox ;		
	}
	
	Aux=lista2.Primeiro->Prox;
	 while (Aux != NULL){
		item=Aux->Item;
		Insere(item, lista3);
		Aux = Aux->Prox ;		
	}
}

void antesP(TipoLista *lista, TipoApontador p,TipoItem x){
    TipoApontador aux=(TipoApontador)malloc(sizeof(TipoCelula));

    aux->Prox=p->Prox;
    p->Prox=aux;
    aux->Item=x;

    
}

main(){
	TipoLista lista;FLVazia(&lista);
    TipoLista lista2;FLVazia(&lista2);
    TipoLista lista3;FLVazia(&lista3);
	TipoApontador p,q;
    TipoItem item;

	item.codigo=123;strcpy(item.descricao, "vermelho"); item.valor=50000;
	Insere(item, &lista);
    item.codigo=4321;strcpy(item.descricao, "carro azul"); item.valor=40000;
	Insere(item, &lista);
    item.codigo=435346563;strcpy(item.descricao, "carro rosa"); item.valor=80000;
	Insere(item, &lista);
	
	printf("\n\nExibindo a Lista\n");
	Imprime(lista);		

    //********A***********
    int codBusca=123;
    printf("\n\nA-) O codigo para busca: %i\n", codBusca);
    p=buscaCod(lista, codBusca);
    if(p!=0){
        printf("O endereco eh %p, com a segunite descricao '%s'", p, p->Item.descricao);
    }else{
        printf("Nao existe");
    }
    	

    //********B*************
    char desBusca[100];
    strcpy(desBusca, "carro rosa");
    printf("\n\nB-) Descricao para busca: %s\n", desBusca);
    fflush(stdin);
    p=buscaDes(lista, desBusca);
    if(p!=NULL){
        printf("O endereco eh %p, com o segunite codigo '%i'", p, p->Item.codigo);
    }else{
        printf("Nao existe");
    }
    p=NULL;/////Corrigir bug caso não exista

    //********C**************
    item.codigo=35; strcpy(item.descricao, "carro preto"); item.valor=60000;
    Insere(item, &lista2);
    item.codigo=66; strcpy(item.descricao, "carro marrom"); item.valor=40000;
    Insere(item, &lista2);
    item.codigo=87; strcpy(item.descricao, "carro roxo"); item.valor=30000;
    Insere(item, &lista2);
    printf("\n\nC-) 1 primeira lista tem mais pares, 2 segunda lista tem mais pares, 0 tem o mesmo numero de pares: %i", maiorPar(lista, lista2));

    //*********D**************
    item.codigo=50000; strcpy(item.descricao, "carro rosa-choque"); item.valor=60000;
    p=buscaCod(lista, 123);
    InsereP(&lista, p, item);
    printf("\n\nD-)Imprimindo lista com item apos o endereco p\n\n*********D***********\n\n");
    Imprime(lista);

    //*********E**************
    p=buscaCod(lista, 123);
    q=buscaCod(lista, 4321);
    troca(p, q);
    printf("\n\nE-)printando lista com P e Q trocados********************\n\n");
    Imprime(lista);

    //**********F*************
    printf("F-) Troca de celula cabeca\n\n***********E**********\n\n");
    item.codigo=44; strcpy(item.descricao, "carro marrom"); item.valor=60000;
    InserirCab(&lista, item);
    Imprime(lista);

    //************g***********
    p=buscaCod(lista, 123);
    RetiraP(p, &lista, &item);
    printf("\n\nG-) Retira o elemento P\n\n***********F**********\n\n");
    Imprime(lista);

    //************H************
    RetirarPar(&lista);
    printf("\n\nH-)Removendo Pares da lista\n\n************H*********\n\n");
    Imprime(lista);

    //************I***************
    printf("\nI-)Comparar listas com mais itens entre a 1 e 2, 0 eh iqual: %i", comparaListas(lista, lista2));

    //************J***************
    printf("\n\nJ-)Sobre a lista; Crescente=1, Caso contario=0 : '%i'.......", ordenado(lista));

    //************K***************
    printf("\n\nK-) Cantatenando listas 1 e 2 para 3..........\n\n");
    ContatenarLista(lista, lista2, &lista3);
    Imprime(lista3);

    p=buscaCod(lista, 4321);
    item.codigo=43543545654665; item.valor=3243245345245;
    printf("\n\n\nAntes P\n\n\n");
    antesP(&lista, p, item);
    Imprime(lista);

    system("pause");
    return 0;
    
}
