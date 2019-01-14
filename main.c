#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

typedef struct pos{ //creation d'un type contenant les coordonnées x et y
    int x;
    int y;
}pos, *pPos;

int testCase(int nTab [TAILLE][TAILLE], pPos jeton);
void correction(int nTab [TAILLE][TAILLE], pPos jeton);
void avancerDr(int nTab [TAILLE][TAILLE], pPos jeton);
void avancerGa(int nTab [TAILLE][TAILLE], pPos jeton);
void placement(int nTab [TAILLE][TAILLE], pPos jeton, int nCpt);
void affichage(int nTab [TAILLE][TAILLE]);

int main()
//BUT : faire un carré magique
//ENTREES :
//SORTIES : le carré magique
{
    int nTab [TAILLE][TAILLE] =  {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    pos position;
        position.x = 1;
        position.y = 2;

    pPos jeton = &position;
    int nCpt = 0;

    for(nCpt = 2; nCpt <= (TAILLE*TAILLE); nCpt++){ //deroulement de toutes les procedures et fonctions permettant de creer le carre magique
        avancerDr(nTab, jeton);
        correction(nTab, jeton);
        if(testCase(nTab, jeton) == 1){
            placement(nTab, jeton, nCpt);
        }
        else{
            correction(nTab, jeton);
            avancerGa(nTab, jeton);
            correction(nTab, jeton);
            placement(nTab, jeton, nCpt);
        }
    }
    affichage(nTab);

    return 0;
}

int testCase(int nTab [TAILLE][TAILLE], pPos jeton)
//BUT : verifier si la case est libre ou non
//ENTREES : le tableau d'entiers et le jeton
//SORTIES : le resultat de si la case est libre ou non
{
    if(nTab[(*jeton).x][(*jeton).y] == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void correction(int nTab [TAILLE][TAILLE], pPos jeton)
//BUT : corriger la position du jeton lorsqu'il sort du tableau
//ENTREES : le tableau d'entiers et le jeton
//SORTIES : le replacement du jeton
{
    if ((*jeton).x == 5){
        (*jeton).x = 0;
    }
    if ((*jeton).y == -1){
        (*jeton).y = 4;
    }
    if ((*jeton).x == -1){
        (*jeton).x = 4;
    }
    if ((*jeton).y == 5){
        (*jeton).y = 0;
    }
}

void avancerDr(int nTab [TAILLE][TAILLE], pPos jeton)
//BUT : déplacer le jeton normalement
//ENTREES : le tableau d'entiers et le jeton
//SORTIES : la nouvelle position du jeton
{
    (*jeton).x -= 1;
    (*jeton).y += 1;
}

void avancerGa(int nTab [TAILLE][TAILLE], pPos jeton)
//BUT : déplacer le jeton si la case est déjà occupée
//ENTREES : le tableau d'entiers et le jeton
//SORTIES : la nouvelle position du jeton
{
    (*jeton).x -= 1;
    (*jeton).y -= 1;
}

void placement(int nTab [TAILLE][TAILLE], pPos jeton, int nCpt)
//BUT : placer du nombre
//ENTREES : le tableau d'entiers, le jeton et un compteur
//SORTIES : le nombre placé
{
    nTab[(*jeton).x][(*jeton).y] = nCpt;
}

void affichage(int nTab [TAILLE][TAILLE])
//BUT : afficher le carré magique
//ENTREES : le tableau d'entiers
//SORTIES : l'affichage du carré magique
{
    int nCptA1, nCptA2 = 0;

    for(nCptA1 = 0; nCptA1 <= 4; nCptA1++){
        for(nCptA2 = 0; nCptA2 <= 4; nCptA2++){
            printf("%d |", nTab[nCptA1][nCptA2]);
        }
        printf("\n");
    }
}
