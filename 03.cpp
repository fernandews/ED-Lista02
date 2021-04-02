#include <iostream>

using namespace std;

class No {
    public:
        int valor;
        No* esq;
        No* dir;

        No(int Valor) {
            this->valor = Valor;
            this->esq = nullptr;
            this->dir = nullptr;}

        int retornaAltura() {
            int altura_esquerda = 0;
            int altura_direita = 0;
            if (this->esq != nullptr) {
                altura_esquerda = this->esq->retornaAltura();
            }
            if (this->dir != nullptr) {
                altura_direita = this->dir->retornaAltura();
            }


            if (altura_esquerda > altura_direita) {
                return(altura_esquerda + 1);
            }
            else {
                return(altura_direita + 1);
            }
        }
        
        int retornaBalanceamento() {
            return (this->esq->retornaAltura() - this->dir->retornaAltura());}
};

class Arvore {
    public:
        No* raiz;

        Arvore(No* Raiz) {
            raiz = Raiz;
        }

        void somaFolhas(No *raiz, int &soma) {
            if(!raiz) {
                return;
            }

            if (!raiz->esq && !raiz->dir) {
                soma += raiz->valor;
            }

            somaFolhas(raiz->esq, soma);
            somaFolhas(raiz->dir, soma);
        }

        void posOrdem(No* raiz) {
            if (raiz == NULL) {
                return;
            }

            this->posOrdem(raiz->esq);
            this->posOrdem(raiz->dir);

            cout << raiz->valor << " ";
        }

        void emOrdem(No* raiz) {
            if (raiz == nullptr) {
                return;
            }

            this->emOrdem(raiz->esq);

            cout << raiz->valor << " ";

            this->emOrdem(raiz->dir);
        }

        void preOrdem(No* raiz) {
            if (raiz == nullptr) {
                return;
            }

            cout << raiz->valor << " ";

            this->preOrdem(raiz->esq);
            this->preOrdem(raiz->dir);
        }

        void percorreNivel(No* raiz, int nivel) {
            if (raiz == nullptr) {
                return;
            }

            if (nivel == 1) {
                cout << raiz->valor << " ";
            }
            else if (nivel > 1) {
                percorreNivel(raiz->esq, nivel - 1);
                percorreNivel(raiz->dir, nivel - 1);
            }
        }

        void percorreNiveis(No* raiz) {
            int altura = raiz->retornaAltura() + 1;
            int i;

            for (i = 0; i < altura; i++) {
                percorreNivel(raiz, i);
            }
        }

        int produtoNos(No* raiz) {
            if (raiz == nullptr) {
                return 1;
            }

            int produto = raiz->valor * this->produtoNos(raiz->esq) * this->produtoNos(raiz->dir);

            return produto;
        }
};


int main() {
    No *raiz = new No(1);
    Arvore *arvore = new Arvore(raiz);

    No subesq = No(1);
    No subsubesqesq = No(2);
    No subsubesqdir = No(3);
    subesq.esq = &subsubesqesq;
    subesq.dir = &subsubesqdir;

    No subdir = No(1);
    No subsubdiresq = No(2);
    No subsubdirdir = No(3);
    subdir.esq = &subsubdiresq;
    subdir.dir = &subsubdirdir;

    raiz->esq = &subesq;
    raiz->dir = &subdir;

    int somaFolhas = 0;
    arvore->somaFolhas(raiz, somaFolhas);

    int produtoNos = arvore->produtoNos(raiz);


    cout << "A altura da raiz e " << raiz->retornaAltura() << endl;
    cout << "O balanceamento da raiz e " << raiz->retornaBalanceamento() << endl;
    cout << "A soma das folhas e " << somaFolhas << endl;
    cout << "O produto dos nos da arvore e " << produtoNos << endl;
    cout << "========PERCURSO PREORDEM===========" << endl;
    arvore->preOrdem(raiz);
    cout << endl;
    cout << "========PERCURSO EM ORDEM===========" << endl;
    arvore->emOrdem(raiz);
    cout << endl;
    cout << "========PERCURSO POSORDEM===========" << endl;
    arvore->posOrdem(raiz);
    cout << endl;
    cout << "========PERCURSO EM NIVEIS==========" << endl;
    arvore->percorreNiveis(raiz);
    cout << endl;

    return 0;
}