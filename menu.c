#include<stdlib.h>
#include<graph.h>
#include<stdio.h>
#include"menu.h"
#define tx 1600
#define ty 800


int selection_lignes(){
	int a, i,y,x,c,lignes,choix_l = 0; 
	/*affiche le menu pour sélectionner le nombre de ligne du taquin*/
		CreerFenetre(50,100,tx,ty);
   	
		for(c=160; c<=510; c = c +70){
		
		DessinerRectangle(800,c,70,70);
		}
		EcrireTexte(500,100,"Choisissez le nombre de ligne de votre Taquin:",2);
		EcrireTexte(830,205,"3",2);
		EcrireTexte(830,275,"4",2);
		EcrireTexte(830,345,"5",2);
		EcrireTexte(830,415,"6",2);
		EcrireTexte(830,485,"7",2);
		EcrireTexte(830,555,"8",2);

		/*détecter sur quelle case l'utilisateur clique (choix du nbre de lignes)*/
		
    do {
		while(!SourisCliquee());
		{
			
	
		/*case 3 ?*/	
			if( _X > 800 && _X < 870 && _Y > 160 && _Y < 230){
		lignes= 3;
		choix_l++;
		 																									 }
		/*case 4 ?*/	
			 if( _X > 800 && _X < 870 && _Y > 230 && _Y < 300){
		lignes= 4;
		choix_l++;
		 				
																											 }
			
		/*case 5 ?*/	
			 if( _X > 800 && _X < 870 && _Y > 300 && _Y < 370){
		lignes= 5;
		choix_l++;
		 											 														 }
		 											 
		/*case 6 ?*/	
		  if( _X > 800 && _X < 870 && _Y > 370 && _Y < 440){
		lignes= 6;
		choix_l++;
		 											 													 }
																										 
		
		/*case 7 ?*/	
			if( _X > 800 && _X < 870 && _Y > 440 && _Y < 510){
		lignes= 7;
		choix_l++;
		 											 													 }
		
		
		/*case 8 ?*/	
			if( _X > 800 && _X < 870 && _Y > 510 && _Y < 580){
		lignes= 8;
		choix_l++;
		 											 													 }
		 											 													 }
		
		 }while(choix_l!=1);

return lignes;
		  											 													 }
	




int selection_colonnes(){
int l,choix_c,colonnes;
EcrireTexte(500,100,"Choisissez le nombre de colonne de votre Taquin:",2);
		for(l=610;l<=960;l = l+70){
		DessinerRectangle(l,200,70,70);
		  											 	}
															 
		EcrireTexte(640,245,"3",2);
		EcrireTexte(710,245,"4",2);
		EcrireTexte(780,245,"5",2);
		EcrireTexte(850,245,"6",2);
		EcrireTexte(920,245,"7",2);
		EcrireTexte(990,245,"8",2);


		/*détecter sur quelle case l'utilisateur clique (choix du nbre de colonne)*/
    do{
		while(!SourisCliquee());
		{
		/*case 3 ?*/	
			if( _X > 610 && _X < 680 && _Y > 200 && _Y < 270){
			colonnes = 3;
			EcrireTexte(780,400,"3",2);
			choix_c = 1;
																											 }


		/*case 4 ?*/	
			if( _X > 680 && _X < 750 && _Y > 200 && _Y < 270){
			colonnes = 4;
		EcrireTexte(780,400,"4",2);
			choix_c =1;
																											 }
		  					

		/*case 5 ?*/	
		 	if( _X > 750 && _X < 820 && _Y > 200 && _Y < 270){
			colonnes = 5;
		EcrireTexte(780,400,"5",2);
			choix_c = 1;
																											 }

		/*case 6 ?*/	
			if( _X > 820 && _X < 890 && _Y > 200 && _Y < 270){
			colonnes = 6;
		EcrireTexte(780,400,"6",2);
			choix_c = 1;
																											 }
		/*case 7 ?*/	
			if( _X > 890 && _X < 960 && _Y > 200 && _Y < 270){
			colonnes = 7;
		EcrireTexte(780,400,"7",2);
			choix_c = 1;
																											 }
			

		/*case 8 ?*/	
			if( _X > 960 && _X < 1030 && _Y > 200 && _Y < 270){
			colonnes = 8;
		EcrireTexte(780,400,"8",2);
			choix_c = 1;
																											 }
																											 }

			}while(choix_c!=1);
			return colonnes;

																											 }





int selection_image(){
int image,choix_img;
EcrireTexte(500,100,"Choisissez l'image avec laquelle vous voulez jouer :",2);

	
ChargerImage("aj1.png",200,300,0,0,300,169);	
ChargerImage("Kangoo.png",600,290,0,0,300,202);	
ChargerImage("Vegeta.png",1000,300,0,0,300,169);	
	
    do{
		while(!SourisCliquee());
		{

		 	if( _X > 200 && _X < 500 && _Y > 300 && _Y < 469){
			image = 1;
			choix_img =1;
EcrireTexte(800,600,"Air jordan1",2);
printf("1");
																											 }
							
		 	if( _X > 600 && _X < 900 && _Y > 290 && _Y < 492){
			image = 2;
			choix_img =1;
EcrireTexte(800,600,"Miguel",2);
printf("2");
																											 }

		 	if( _X >1000 && _X < 1300 && _Y > 300 && _Y < 469){
			image = 3;
			choix_img =1;
EcrireTexte(800,600,"Eternel 2nd",2);
printf("3");
																											 }



																											 }

		}while(choix_img!=1);
return image;


										}



