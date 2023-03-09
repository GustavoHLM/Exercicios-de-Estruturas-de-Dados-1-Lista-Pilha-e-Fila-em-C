/* Questão 4: Irei apenas escrever a função pois o codigo dos 
2 tipos de Estruturas são extensos. Obrigado

Gustavo Henrique Mendonça*/

void Separar_imparEpar(TipoLista lista){
	TipoItem x;
	TipoApontador p=lista->Primeiro->Prox;
	TipoPilha par; FPVazia(&p1);
	TipoPIlha impar; FPVazia(&p2);
	
	while(p!=NULL){
		if(p->Item.inteiro%2==0){
			x.chave=p->Item.inteiro;
			Empilha(x, &par);
		}else{
			x.chave=p->Item.inteiro;
			Empilha(x, &impar);
		}
		p=p->Prox;
	}
}
