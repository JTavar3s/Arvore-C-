#include <iostream>
#include <list>

using namespace std;
struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;

void tDestruir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

void multiplos3(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        multiplos3(arvore->esq);
        if (arvore->info % 3 == 0) 
			cout << arvore->info << " ";
        multiplos3(arvore->dir);
    }
}

void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
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
    
    multiplos3(arvore);
    tDestruir(arvore);
    return 0;
}