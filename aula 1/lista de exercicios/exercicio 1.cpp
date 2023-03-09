#include<stdio.h>
#include<string.h>

// Estrutura de Dados - Lista Simples
struct Pessoa{ //Item que será manipulado
	char nome[100];
	char telefone[20];
	int idade;
};
struct Agenda{ //Lista
	Pessoa contatos[50];
	int tamanho;
};

// **** Operações ****

// Inicializa as variáveis de controle da estrutura
// No caso, a variável tamanho
void fazListaVazia(Agenda *agenda){
	agenda->tamanho=0;
}

void insere(Pessoa p, Agenda *agenda){
	if(agenda->tamanho>=50){
		printf("\n Agenda cheia!");
		return;
	}
	agenda->contatos[agenda->tamanho]=p;
	agenda->tamanho++;
}

void imprime(Agenda agenda){
	int i;
	for(i=0;i<agenda.tamanho;i++){
		printf("\n\nNome: %s", agenda.contatos[i].nome);
		printf("\nTelefone: %s", agenda.contatos[i].telefone);
		printf("\nIdade: %i", agenda.contatos[i].idade);
	}
}

void retira(int posicao, Agenda *agenda){
	int i;
	if(posicao >= agenda->tamanho){ 
		printf("Erro : Posicao nao existe \n") ;
		return ;
	}
	
	agenda->tamanho--;
	for(i=posicao; i < agenda->tamanho; i++){
		agenda->contatos[i] = agenda->contatos[i+1];
	}
}

main(){
	Pessoa pessoa;
	Agenda agenda;
	fazListaVazia(&agenda); // Inicializa as variáveis de controle da estrutura
	strcpy(pessoa.nome, "Joao"); strcpy(pessoa.telefone, "35 99997070");pessoa.idade=20;
	insere(pessoa, &agenda);
	strcpy(pessoa.nome, "Maria"); strcpy(pessoa.telefone, "35 88886060");pessoa.idade=15;
	insere(pessoa, &agenda);
	strcpy(pessoa.nome, "Ze"); strcpy(pessoa.telefone, "35 77775050");pessoa.idade=30;
	insere(pessoa, &agenda);

	imprime(agenda);
	
	retira(0, &agenda);
	
	printf("\n\n\n Exibindo apos a funcao retira \n");
	imprime(agenda);
}

