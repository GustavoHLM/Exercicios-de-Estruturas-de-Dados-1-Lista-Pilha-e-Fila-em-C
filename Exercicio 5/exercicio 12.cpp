/* Quest�o 12: Irei apenas escrever a fun��o pois o codigo dos 
2 tipos de Estruturas s�o extensos. Obrigado

Gustavo Henrique Mendon�a*/

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
