#include <stdio.h>
#include <stdlib.h>

void bienvenue(){       //Affichage du message de bienvenue
    printf("##################################\n#");
    printf("Bienvenue sur le jeu de l'awalé.");
    printf("#\n##################################\n\n");
}

void affiche_regle(){       //Affichage des règle du jeu
    printf("Les règles du jeu sont simple.\n\n");
    printf("Matériel :\n");
    printf("Le jeu se joue sur un plateau composé de deux rangées de six petits compartiments, appelés cases, pour un total de 12 cases.\n");
    printf("Chaque joueur contrôle la rangée de cases qui est devant lui.\n\n");
    printf("But du jeu :\n");
    printf("L'objectif principal est de capturer le plus grand nombre possible de graines de l'adversaire.\n\n");
    printf("Déroulement de la partie :\n");
    printf("Au début de la partie, quatre graines sont placées dans chaque case du plateau.\n");
    printf("Les joueurs jouent à tour de rôle.\n");
    printf("Pendant son tour, un joueur choisit l'une des cases de sa rangée et ramasse toutes les graines de cette case.\n");
    printf("Le joueur distribue ensuite les graines une par une dans les cases suivantes dans le sens antihoraire.\n");
    printf("Si le joueur atteint la case suivante de son adversaire et qu'il y a assez de graines pour continuer, il continue à semer les graines dans la rangée de l'adversaire.\n");
    printf("Si le dernier grain semé tombe dans une case occupée de l'adversaire et que cette case atteint une comporte 2 ou 3 graines après le dépôt, le joueur capture ces graines.\n");
    printf("Il les retire du plateau et les place dans son propre but (un espace à sa droite sur le plateau).\n\n");
    printf("Fin de la partie :\n");
    printf("La partie se termine lorsque l'un des joueurs ne peut pas jouer à son tour, car toutes les cases de sa rangée sont vides.\n");
    printf("Le joueur qui a capturé le plus grand nombre de graines est déclaré vainqueur.\n\n");
    printf("Le jeu s'affiche de cette manière, il faut donc choisir les case qui corresponde lors de votre tour\n");
    printf("┌----------------------------------------------------┐\n");
    printf("|--[N°1]----[N°2]----[N°3]----[N°4]---[N°5]---[N°6]--|    <== Joueur 1\n");
    printf("├----------------------------------------------------┤\n");
    printf("|--[N°12]---[N°11]---[N°10]---[N°9]---[N°8]---[N°7]--|    <== Joueur 2\n");
    printf("└----------------------------------------------------┘\n");
}

void affiche_plateau(int tab[]){
    printf("┌-------------------------------------┐\n");
    printf("|--[%i]---[%i]---[%i]---[%i]---[%i]---[%i]--|    <== Joueur 1\n",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5]);
    printf("├-------------------------------------┤\n");
    printf("|--[%i]---[%i]---[%i]---[%i]---[%i]---[%i]--|    <== Joueur 2\n",tab[11],tab[10],tab[9],tab[8],tab[7],tab[6]);
    printf("└-------------------------------------┘\n");
}

void victoire_points(int nb_pts[]){
    if(nb_pts[0]>nb_pts[1]){
        printf("Le joueur 1 remporte la partie avec un total de %i points contre %i points\n",nb_pts[0],nb_pts[1]);
    }
    if(nb_pts[1]>nb_pts[0]){
        printf("Le joueur 2 remporte la partie avec un total de %i points contre %i points\n",nb_pts[1],nb_pts[0]);
    }
    if(nb_pts[0]==nb_pts[1]){
        printf("Le nombre de points est égal, aucun joueur ne remporte la partie avec chacun %i points\n",nb_pts[0]);
    }
}

void remplissage_tab(int t[], int nb){
    int i;
    for(i=0; i<12; i++){
        t[i]=nb;
    }
}

void affichage(int t[], int nb_pts[]){
    printf("\nJOUEUR 1 PTS : %i / JOUEUR 2 PTS : %i\n", nb_pts[0], nb_pts[1]);
}

int boucle(int cas){      //ne pas utiliser dans le main
    if (cas==0){
        return 12;
    }
    else{
        return cas;
    }
}

int retirer_grn(int ind_base, int ind, int t[]){  //ne pas utiliser dans le main
    if(ind_base<6 && ind>=6){
        return 0;
    }else{
        if(ind_base>=6 && ind<6){
            return 0;
        }else{
            return t[ind]=t[ind]+1;
        }
    }
}

int ajt_pts(int nb){ //ne pas utiliser dans le main
    if(nb>0){
        return 0;
    }else{
        return 1;
    }
}

int sauv_(int nb, int sauv){
    if(nb>0){
        return 0;
    }
    else{
        return sauv;
    }
}

void jouer_(int t[], int case_, int nb_pts[]){
    int i, ind = case_ - 1, ind_base = ind;
    int nb = t[ind];
    int sauv;
    t[ind]=0;
    for(i=0; i<nb; i++){
        ind = boucle(ind) - 1;
        if(t[ind]==1){
            sauv = t[ind];
            t[ind]=retirer_grn(ind_base, ind, t);
            if(case_<7){
                nb_pts[0] = nb_pts[0] + ajt_pts(t[ind]) + sauv_(t[ind], sauv);
            }
            else{
                nb_pts[1] = nb_pts[1] + ajt_pts(t[ind]) + sauv_(t[ind], sauv);
            }
        }
        else{
            if(t[ind]==2){
                sauv = t[ind];
                t[ind]=retirer_grn(ind_base, ind, t);
                if(case_<7){
                    nb_pts[0] = nb_pts[0] + ajt_pts(t[ind]) + sauv_(t[ind], sauv);
                }
                else{
                    nb_pts[1] = nb_pts[1] + ajt_pts(t[ind]) + sauv_(t[ind], sauv);
                }
            }
            else{
                t[ind]=t[ind]+1;
            }
        }
    }
}

int verif_j1(int tab[], int case_j1){
    if(case_j1>0 && case_j1<=6 && tab[case_j1-1]!=0){
        return 1;
    }else{
        return 0;
    }
}

int verif_j2(int tab[], int case_j2){
    if(case_j2>6 && case_j2<=12 && tab[case_j2-1]!=0){
        return 1;
    }else{
        return 0;
    }
}

void nb_pts_total(int nb_pts[], int plateau[]){
    int i = 0;
    for(i=0; i<6; i++){
        nb_pts[0]=nb_pts[0]+plateau[i];
    }
    for(i=6; i<12; i++){
        nb_pts[1]=nb_pts[1]+plateau[i];
    }
}

void menu(){
    int taper,fin=0;
    bienvenue();
    int tab[12];
    while(fin==0){
        do{
            printf(" |Tapez 1|--> pour afficher les règles du jeu\n");
            printf(" |Tapez 2|--> pour commencer une partie\n");
            printf(" |Tapez 3|--> pour quitter le programme\n");
            scanf("%i",&taper);
        }while(taper<1 || taper>3);
        switch(taper){
            case 1 : affiche_regle();
                break;
            case 2 :
                remplissage_tab(tab,4);
                int nb_pts[2];
                nb_pts[0]=0;
                nb_pts[1]=0;
                printf("\n-----------|Le joueur 1 commence|-----------\n\n");
                affiche_plateau(tab);
                affichage(tab,nb_pts);
                int fin_j1 = 0, fin_j2 = 0;
                while(fin_j1 == 0 && fin_j2 == 0){
                    if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0 && tab[4]==0 && tab[5]==0){
                        fin_j1=1;
                    }
                    else{
                        int case_j1;
                        scanf("%i", &case_j1);
                        while(verif_j1(tab, case_j1)==0){
                            printf("La saisie n'est pas valide\n");
                            scanf("%i", &case_j1);
                        }
                        jouer_(tab,case_j1,nb_pts);
                        printf("--------------|Tour du joueur 2|--------------\n\n");
                        affiche_plateau(tab);
                        affichage(tab,nb_pts);
                    }
                    if(tab[6]==0 && tab[7]==0 && tab[8]==0 && tab[9]==0 && tab[10]==0 && tab[11]==0){
                        fin_j2=1;
                        break;
                    }
                    else{
                        int case_j2;
                        scanf("%i", &case_j2);
                        while(verif_j2(tab, case_j2)==0){
                            printf("La saisie n'est pas valide\n");
                            scanf("%i", &case_j2);
                        }
                        jouer_(tab,case_j2,nb_pts);
                        printf("--------------|Tour du joueur 1|--------------\n\n");
                        affiche_plateau(tab);
                        affichage(tab,nb_pts);
                    }
                    if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0 && tab[4]==0 && tab[5]==0){
                        fin_j1=1;
                    }
                }
                nb_pts_total(nb_pts,tab);
                victoire_points(nb_pts);
                break;
            case 3 : fin = 1;
                break;
        }
    }
}

int main(){
    menu();
}