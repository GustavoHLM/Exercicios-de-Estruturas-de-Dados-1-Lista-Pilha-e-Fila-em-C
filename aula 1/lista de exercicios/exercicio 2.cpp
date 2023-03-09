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
		return;
	}
	
	agenda->tamanho--;
	for(i=posicao; i < agenda->tamanho; i++){
		agenda->contatos[i] = agenda->contatos[i+1];
	}
}

float soma(Agenda agenda){///Função para somar
	int i;float soma=0;
	for(i=0; i<agenda.tamanho;i++){
		soma+=agenda.contatos[i].idade;
	}
	return soma;
}

float media(Agenda agenda){///Função de media, que chama a soma para auxiliar
	int i;float media=0;
	media=soma(agenda);
	media=media/agenda.tamanho;
	return media;
}

float menor(Agenda agenda){////Função para menor
	int i;float menor=agenda.contatos[0].idade;
	for(i=0; i<agenda.tamanho;i++){
		if(agenda.contatos[i].idade<menor)
		menor=agenda.contatos[i].idade;
	}
	return menor;
}

float maior(Agenda agenda){/////Função para maior
	int i;float maior=0;
	for(i=0; i<agenda.tamanho;i++){
		if(agenda.contatos[i].idade>maior)
		maior=agenda.contatos[i].idade;
	}
	return maior;
}

int analisa(Agenda agenda, char comparar[]){////Função para achar nome e retornar posiçaõ
	int i; char comp[50];
	for(i=0; i<agenda.tamanho; i++){
		if(strcmp(agenda.contatos[i].nome, comparar)==0){
			return i;
		}
	}
	return -1;
}

int vogal(Agenda agenda){//////Função para achar vogal na ultima letra do nome recebido
	int i;
	char vogal[10];
	strcpy(vogal,"aeiouAEIOU");
	int k=strlen(agenda.contatos[agenda.tamanho-1].nome);
	for(i=0;i<10;i++){
		if(agenda.contatos[agenda.tamanho-1].nome[k-1]==vogal[i]){
			return 1;
		}
	}
	return 0;
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
	
	printf("\n\nSoma= %.2f", soma(agenda));/////Imprime as funções que retornar os valores
	printf("\nMedia= %.2f", media(agenda));
	printf("\nIdade Menor= %.2f", menor(agenda));
	printf("\nIdade Maior= %.2f", maior(agenda));
	
	char comparar[50];Pessoa p;///Analisa os Nomes
	printf("\n\nAdd o nome: ");
	scanf("%s", &comparar);
	if(analisa(agenda,comparar)!=-1){
		printf("\nExiste o nome, posicao do item %i", analisa(agenda, comparar));
	}else{
		printf("****Nao existe na lista****");
	}
	////////
	
	retira(0, &agenda);///Retira o primeiro
	printf("\n\nExibindo apos a funcao retira");
	imprime(agenda);
	
	/////////
	
	
	///Acha a vogal no ultimo na ultima letra
	strcpy(pessoa.nome, "Luiza"); strcpy(pessoa.telefone, "35 99994055");pessoa.idade=20;
	printf("\n\nExibindo adicionado para vogal\n");
	insere(pessoa, &agenda);
	imprime(agenda);
	if(vogal(agenda)==1){
		printf("\n\nExiste a vogal na ultima letra de %s\n", agenda.contatos[agenda.tamanho-1].nome);
	}else{
		printf("\nNao existe vogal na ultima letra de %s\n", agenda.contatos[agenda.tamanho-1].nome);
	}
	return 0;
}

