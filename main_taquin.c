#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include"menu.h"
#define tx 1600
#define ty 800


	
int main(void)  {
		
InitialiserGraphique();
selection_lignes();
EffacerEcran(CouleurParNom("white"));
selection_colonnes();
EffacerEcran(CouleurParNom("white"));
selection_image();						
Touche();		
		
FermerGraphique();		
		 }
			
