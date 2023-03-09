/* Questão 12: Irei apenas escrever a função pois o codigo dos 
2 tipos de Estruturas são extensos. Obrigado

Gustavo Henrique Mendonça*/

void InverterListaEstatica(TipoLista *lista){
	int i;
	TipoItem x;
	TipoPilha aux; FPVazia(&aux);
	
	for(i=lista->primeiro-1; i <=(lista->ultimo - 2); i++){
        Empilha(lista->item[i], &aux);
    }
    FLVazia(lista);
	
	while(!Vazia(aux)){
		Desempilha(&aux, &x);
		Insere(x, lista);
	}
}
