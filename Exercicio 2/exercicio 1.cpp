///Gustavo Henrique Mendon�a
///BCC 3�- Lista Estatica 1 exercicio


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Estrutura Lista Est?tica
#define INICIOARRANJO 1
#define MAXTAM 10

typedef int TipoApontador;
typedef int TipoChave;
struct  TipoItem {
	TipoChave isbn;
	char titulo[50];
	char autor[50];
};

struct  TipoLista {
	TipoItem item [MAXTAM];
	TipoApontador primeiro , ultimo ;
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

void retira (TipoApontador p , TipoLista *lista , TipoItem *item) { 
	int aux;
	if(vazia(*lista ) || p >= lista->ultimo ){ 
		printf("Erro : Posicao nao existe \n") ;
		return ;
	}
	*item = lista -> item [p - 1];
	lista -> ultimo--;
	for (aux = p;aux<lista->ultimo; aux++)
		lista->item[aux-1]=lista->item[aux];
}

void imprime( TipoLista lista ) { 
	int aux;
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
		printf("\n%d\t",lista.item[aux].isbn);
		printf("%s\t",lista.item[aux].titulo);
		printf("%s\t",lista.item[aux].autor);
	}
} 

// Retorna a quantidade de livros que o autor possui na lista
int buscaPorAutor(TipoLista lista, char autor[50]){
	int aux, cont=0;
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
		if(strcmp(lista.item[aux].autor, autor)==0)
			cont++;
	}
	return cont;
}

int Impar(TipoLista lista){
    int i, cont=0;
    for(i=lista.primeiro-1; i <=(lista.ultimo - 2); i++){
        if(lista.item[i].isbn%2!=0){
            cont++;
        }
    }
    return cont;
}

int Maior(TipoLista lista){
    int i, maior=0;

    for(i=lista.primeiro-1; i<=(lista.ultimo-2);i++){
        if(lista.item[i].isbn>maior){
            maior=lista.item[i].isbn;
        }
    }
    return maior;
}

int ProcuraAutor(TipoLista lista, char autor[]){
    int i;
    for(i=lista.primeiro-1; i<=(lista.ultimo-2); i++){
        if(strcmp(autor, lista.item[i].autor)==0){
            return i;
        }
    }

    return -1;
}

int ProcuraTitulo(TipoLista lista, char titulo[]){
    int i;
    for(i=lista.primeiro-1; i<=(lista.ultimo-2); i++){
        if(strcmp(titulo, lista.item[i].titulo)==0){
            return i;
        }
    }

    return -1;
}

int ComparaLista(TipoLista lista, TipoLista compara){
        if(lista.item==compara.item){
            return 1;
        }
    return 0;
}

int ContarItens(int lista1, int lista2){

    if(lista1>lista2){
        return 1;
    }
    if(lista1<lista2){
        return 2;
    }if(lista1==lista2){
        return 0;
    }
}

int ContarItensPares(TipoLista lista, TipoLista F){
    int i, count1=0, count2=0;
    for(i=lista.primeiro-1; i<=(lista.ultimo-2); i++){
        if(lista.item[i].isbn%2==0){
            count1++;
        }
    }
    for(i=F.primeiro-1; i<=(F.ultimo-2); i++){
        if(F.item[i].isbn%2==0){
            count2++;
        }
    }

    if(count1>count2){
        return 1;
    }
    else if(count1<count2){
        return 2;
    }else{
        return 0;
    }
}

void imprimeAutorIqual( TipoLista lista, TipoLista F ) { 
	int aux, j;
    printf("\n\n****Autores da lista 1 e lista 2 que sao iquais, Abaixo****");
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
        for(j= aux; j <= (F.ultimo - 2); j++){
            if(strcmp(lista.item[aux].autor, F.item[aux].autor)==0){
                printf("\n%s",lista.item[aux].autor);
            }
        }
	}
} 

void imprimeAutorDiferente( TipoLista lista, TipoLista F ) { 
	int aux, j;
    printf("\n\n****Autores da lista 1 e lista 2 que sao Diferentes, Abaixo****");
	for (aux = lista.primeiro - 1; aux <= (lista.ultimo - 2); aux++){
        for(j= aux; j <= (F.ultimo - 2); j++){
            if(strcmp(lista.item[aux].autor, F.item[aux].autor)!=0){
                printf("\n%s",lista.item[aux].autor);
            }
        }
	}
} 

void contatenar(TipoLista lista, TipoLista F, TipoLista *contatenada){
    int i;
    TipoItem item;
    fLVazia(&*contatenada);

    for(i=lista.primeiro-1; i<=lista.ultimo-2; i++){
        item.isbn=lista.item[i].isbn; strcpy(item.titulo, lista.item[i].titulo); strcpy(item.autor, lista.item[i].autor);
        insere(item, &*contatenada);
    }
    for(i=F.primeiro-1; i<=F.ultimo-2; i++){
        item.isbn=F.item[i].isbn; strcpy(item.titulo, F.item[i].titulo); strcpy(item.autor, F.item[i].autor);
        insere(item, *&contatenada);
    }
}


void Intercalar(TipoLista lista, TipoLista F, TipoLista *intercalada){
    int i, j;
    TipoItem item;
    fLVazia(&*intercalada);

    for(i=lista.primeiro-1; i<=lista.ultimo-2; i++){
        item.isbn=lista.item[i].isbn; strcpy(item.titulo, lista.item[i].titulo); strcpy(item.autor, lista.item[i].autor);
        insere(item, &*intercalada);

        for(j=i; j<=F.ultimo-2; j++){
            item.isbn=F.item[j].isbn; strcpy(item.titulo, F.item[j].titulo); strcpy(item.autor, F.item[j].autor);
            insere(item, *&intercalada);
        }
    }
}

void retiraPar(TipoLista *lista, TipoItem *item){
    if(lista->item[1].isbn%2==0){
        retira(1, &lista, &item);
    }
}

main(){
	TipoLista lista;
	TipoItem item;
	fLVazia(&lista); //Inicia os campos primeiro e ultimo da lista
	item.isbn=1; strcpy(item.titulo, "Algoritmos"); strcpy(item.autor, "Ziviani");
	insere(item, &lista); // Insere o item na lista
	item.isbn=2; strcpy(item.titulo, "Engenharia de Software"); strcpy(item.autor, "Pressman");
	insere(item, &lista); // Insere o item na lista
    item.isbn=3; strcpy(item.titulo, "Harry Potter"); strcpy(item.autor, "J.K.Rowling");
	insere(item, &lista); // Insere o item na lista
	imprime(lista); // Exibe os livros da lista
	
	retira(1,&lista, &item); // Retira o primeiro livro da lista
	printf("\n\nLivro retirado %s", item.titulo);
	
	printf("\n\n\n");
	imprime(lista);
	// Exibe a quantidade de livros do autor passado como par?metros
	printf("\n\n Quantidade de livros %d", buscaPorAutor(lista, "Pressman"));

    //A-Exibe numeros Impares
    printf("\n\nA-)Existe %d numeros impares...", Impar(lista));

    //B-Exibe o maior
    printf("\nB-)O maior isbn eh %d", Maior(lista));

    //C-Exibe se existe o autor na lista
    int posicao=ProcuraAutor(lista, "J.K.Rowling");
    if(posicao!=-1){
        printf("\nC-)A posicao do autor esta em %d", posicao);
    }else{
        printf("\nC-)Nao existe este autor na lista");
    }

    //D-Exibe se existe o titulo na lista
    posicao= ProcuraTitulo(lista, "Engenharia de Software");
    if(posicao!=-1){
        printf("\nD-)A posicao do titulo esta em %d", posicao);
    }else{
        printf("\nD-)Nao existe este titulo na lista");
    }

    //E-Comparar 2 listas
    TipoLista comparaL;
    fLVazia(&comparaL);
	item.isbn=2; strcpy(item.titulo, "Engenharia de Software"); strcpy(item.autor, "Pressman");
	insere(item, &comparaL); // Insere o item na lista
    
    int ComparaListamain= ComparaLista(lista, comparaL);
    if(ComparaListamain==1){
        printf("\nE-)As listas sao iquais");
    }else{
        printf("\nE-)As listas sao diferentes");
    }

    //F- Contar itens
    TipoLista F;
    fLVazia(&F);
    item.isbn=6;strcpy(item.titulo,"pudin");strcpy(item.autor, "Chico");
    insere(item, &F);
   
    printf("\nF-)lista com mais itens(0=numero de itens iquais)= %d", ContarItens(lista.ultimo-1, F.ultimo-1));
    

    //G- Retornar maior lista com isbns pares
    fLVazia(&F);
    item.isbn=1;strcpy(item.titulo,"pudin");strcpy(item.autor, "Pressman");
    insere(item, &F);
    printf("\nG-)lista com mais itens isbns pares(0=numero de itens iquais)= %d", ContarItensPares(lista, F));

    //H-)receba duas listas e exiba os autores que estão na lista 1 e também estão na lista 2;
    printf("\n\nH-)");
    imprimeAutorIqual(lista, F);

    //I-)receba duas listas e exiba os autores que estão na lista 1 e não estão na lista 2;
    fLVazia(&F);
    item.isbn=1;strcpy(item.titulo,"pudin");strcpy(item.autor, "Rodolfo");
    insere(item, &F);
    printf("\n\nI-)");
    imprimeAutorDiferente(lista, F);

    //J-) Contatenar 3 listas em 1
    printf("\n\nJ-)Contatenar\n");

    TipoLista contatena;
    fLVazia(&contatena);
    contatenar(lista, F, &contatena);
    imprime(contatena);

    //K-) Intercala 3 listas em 1
    printf("\n\nK-)Intercalar\n");

    TipoLista intercala;
    fLVazia(&intercala);
    Intercalar(lista, F, &intercala);
    imprime(intercala);

	system("pause");
    return 0;
}
