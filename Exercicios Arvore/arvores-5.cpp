#include <iostream>
#include <list>

using namespace std;
struct treenode
{
    int infor;
    treenode *direita;
    treenode *esquerda;
    
};
typedef treenode *treenodeptr;

void tDestruir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esquerda);
        tDestruir(arvore->direita);
        delete arvore;
    }
    arvore = NULL;
}

void multiplosde3(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        multiplosde3(arvore->esquerda);
        
        if (arvore->infor % 3 == 0)
        	
            cout << arvore->infor << " ";
        
        multiplosde3(arvore->direita);
    }
}
void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) 
    {
        p = new treenode;
         p->infor = x;
          p->direita = NULL;
           p->esquerda = NULL;
    }
    else if (x < p->infor) 
    	
        tInsere(p->esquerda, x);
    
    else 
    	
        tInsere(p->direita, x);
}

int main()
{
    int n = 0;
    treenodeptr arvore = NULL;
    do
    {
        cin >> n;
        tInsere(arvore, n);
    } while (n != -1);

    multiplosde3(arvore);
    cout << endl;
    tDestruir(arvore);
    return 0;
}