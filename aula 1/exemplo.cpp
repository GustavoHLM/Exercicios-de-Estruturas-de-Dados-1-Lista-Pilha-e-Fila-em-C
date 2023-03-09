#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Pessoa{
	char nome[100];
	char telefone[20];
};

struct Agenda{
	Pessoa contatos[50];
	int tamanho;
};

void fazListaFazia(Agenda *agenda){
	agenda->tamanho=0;
};

void insere(Agenda *agenda, Pessoa p){
	agenda->contatos[agenda->tamanho]=p;
	agenda->tamanho++;
};

void exibe(Agenda agenda){
	int i;
	for(i=0;i<agenda.tamanho;i++){
		printf("%s\n", agenda.contatos[i].nome);
		printf("%s\n", agenda.contatos[i].telefone);
	}
}

void retira(Agenda *agenda, int posicao){
	int i;
	for(i=posicao; i<agenda->tamanho; i++){
		agenda->contatos[i]= agenda->contatos[i+1];
	}
	agenda->tamanho--;
}

int analisa(Agenda agenda, Pessoa pessoa, char comparar[]){
	int i; char comp[50];
	for(i=0; i<agenda.tamanho; i++){
		strcpy(comp, agenda.contatos[i].nome);
		if(strcmp(comp, comparar)==0){
			return 1;
		}
	}
	return 0;
}

int main(){
	Agenda ag1; Pessoa p; char comparar[50];
	fazListaFazia(&ag1);
	strcpy(p.nome, "joao"); strcpy(p.telefone, "7070");
	insere(&ag1, p);
	strcpy(p.nome, "dudu"); strcpy(p.telefone, "1010");
	insere(&ag1, p);
	strcpy(p.nome, "gugu"); strcpy(p.telefone, "1010");
	insere(&ag1, p);
	exibe(ag1);
	retira(&ag1, 0);
	printf("------Removido-----\n");
	exibe(ag1);
	
	printf("Add o nome: ");
	scanf("%s", &comparar);
	if(analisa(ag1,p,comparar)==1){
		printf("\nExiste o nome");
	}
	
	
}
