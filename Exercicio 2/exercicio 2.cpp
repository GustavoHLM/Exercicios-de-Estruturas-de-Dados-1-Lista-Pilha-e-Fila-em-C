///Gustavo Henrique Mendonça
///BCC 3°- Lista Estatica 2 exercicio

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Estrutura Lista Est?tica
#define INICIOARRANJO 1
#define MAXTAM 10

struct  TipoItem {
	int cod;
    char nome[50];
};

struct  TipoLista {
	TipoItem item [MAXTAM];
    int primeiro , ultimo ;
};

// Fun??es para manipula??o da Lista Est?tica
void fLVazia(TipoLista *lista){
	lista->primeiro = INICIOARRANJO ; lista->ultimo = lista->primeiro; 
}

int vazia(TipoLista lista){
	return (lista.primeiro == lista.ultimo); 
}

void insere (TipoItem x , TipoLista *lista){ 
    if(lista->ultimo > MAXTAM)
	printf ( " Lista esta cheia \n" ) ;
     else{
		lista-> item [lista->ultimo-1] = x ;
		lista->ultimo++;
      }
}

void imprime( TipoLista lista ) { 
	int aux;
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
		printf("\n%s\t",lista.item[aux].nome);
		printf("%i\t",lista.item[aux].cod);
	}
} 

void ImparePar(TipoLista *lista){
    int i;
    for(i=lista->primeiro-1; i<=(lista->ultimo-2);i++){
        if(i%2==0){
			strcpy(lista->item[i].nome, "Par");        
		}else{
            strcpy(lista->item[i].nome, "Impar");
        }
    }
}


int main(){
    int i;

    TipoLista lista;
	TipoItem item;
	fLVazia(&lista);

    for(i=0;i<10;i++){
        item.cod=i;
        insere(item, &lista);
    }
    ImparePar(&lista);
    imprime(lista);

	system("pause");
    return 0;
}
