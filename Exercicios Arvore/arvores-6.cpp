 	#include <iomanip>
#include <iostream>
#include <list>
using namespace std;
struct treenode
	{
	int  infor;
	treenode *direita;
	
	treenode *esquerda;
	
	};	
typedef treenode *treenodeptr;
float pPositivos(treenodeptr arvore){
	int contpos=0;
	if(arvore != NULL){	
	pPositivos(arvore->esquerda);
	
	pPositivos(arvore->direita);
	contpos++;
	}	
	return contpos;
}
void tDestruir(treenodeptr &arvore)
{
	if(arvore!=NULL)
	{
			tDestruir(arvore->esquerda);
			tDestruir(arvore->direita);
			delete arvore;
	}
	arvore=NULL;
}		
	void tInsere(treenodeptr &p, int x)
	{	
if(x!=0){
	if (p == NULL)
	{
	p = new treenode;
	p->infor = x;
	p->esquerda = NULL;
	p->direita = NULL;
	}
	else if (x < p->infor) 
	tInsere(p->esquerda, x);
	else
	tInsere(p->direita, x);
	}}
	int main(){
		treenodeptr arvore=NULL;
		int n=0;
		int cont;
		float positivos=0;	
			do{	
		cin>>n;
        tInsere(arvore,n);
        cont++;
	}while(n!=0);
	positivos=pPositivos(arvore);
	cout<<fixed<<setprecision(2)<<(positivos/cont)*100 <<" %"<<" de elementos positivos" ;
	tDestruir(arvore); 
	return 0;
	}