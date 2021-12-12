#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include"menu.h"
#include"partie.h"
#define Taille_EcranX 1600
#define Taille_EcranY 800

/*
int selection_controle(void){


EcrireTexte(500,100,"Choisissez la manière dont vous souhaitez jouer:",2); 
DessinerRectangle(800,200,150,150);
DessinerRectangle(1000,200,150,150);



 EffacerEcran(CouleurParNom("white"));


}*/
int main(void)  {
		
InitialiserGraphique();
CreerFenetre(100,100,Taille_EcranX,Taille_EcranY);
int a, b , c,d, e ;

b = selection_image();
c = selection_lignes();
d = selection_colonnes();						
e = selection_mode();
decoupage_image(b ,c , d , e);


Touche();		
		
FermerGraphique();		
		 }
			
