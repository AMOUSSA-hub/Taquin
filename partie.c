#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include "partie.h"

void decoupage_image(int image,int lignes,int colonnes){ 
    
int posx=150,posy=100,i,j=0;
    int l,h,choix;
    char *image_selectionnee[16]={("luffy_grand.png"),("Kangoo.jpg"),("Vegeta.jpg")};
    choix = image;
    if (choix == 1){ 
    l=299;
    h=450;//Luffy
    }else if(choix == 2){
    l=570;
    h=384;//kangoo
    }else if(choix == 3){
      l=480;
      h=270;//Vegeta
    }
    
		
        	ChargerImage(image_selectionnee[choix-1],1000,100,0,0,l,h);
		
		int taille,taille_lignes,num_case=0;
    taille = lignes;
		taille_lignes = colonnes;
    int tab[taille*taille_lignes-1][4];
 	//	int pos_origine[taille*taille_lignes-1][2];
    for(i=0;(i+( h%taillve))<h;i+=(h/taille) ){
      for(j=0;(j+(l%taillve_lignes))<l;j+=(l/taille_lignes)){
        ChargerImage(image_selectionnee[choix-1],posx,posy,j,i,(l/taille_lignes),(h/taille));
        printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));
        tab[num_case][0]=num_case;
        tab[num_case][1]=posx;
        tab[num_case][2]=posy;
        tab[num_case][3]=l/taille_lignes;
        tab[num_case][4]=h/taille;
        
     pos_origine[num_case][0]=num_case;
        pos_origine[num_case][1]=posx;
        pos_origine[num_case][2]=posy;
        tab[num_case][3]=l/taille_lignes;
        tab[num_case][4]=h/taille;
    
    
        posx+=((l/taille_lignes)+5);
   num_case++;                
                                   
      }                            
      posy+=((h/taille)+5);        
      j=0;                         
      posx=150;                    
    }                              
                                   
    ChoisirEcran(10);              
    EffacerEcran(CouleurParNom("white"));
    CopierZone(10,0,0,0,l/taille_lignes,h/taille,150,100);
    ChoisirEcran(0);
int recherche,case_cliquee,case_cliquee_melange,keep_x,keep_y,bravo,direction,coup_melange=0;                                                                     
int recherche_melange,keep_x_melange,keep_y_melange;
int case_inconnu[1];
int case_melange[1];
srand(time(NULL));





 /*Fonction de mélange*/ 
 do{			
		/*	haut=0
			droite=1
			bas=2
			gauche=3*/	
	
			direction =rand()%(3-0+1)+0;



			if( direction == 0 && tab [0][2] != 100){
				
				printf(" detecté haut");
				
				case_melange[0]=tab[0][1];
				case_melange[1]=tab[0][2]-(h/taille)-5;
				
				for(recherche_melange=0;recherche_melange <= num_case;recherche_melange++){
							if(tab[recherche_melange][1] == case_melange[0] && tab[recherche_melange][2] == case_melange[1]){
									case_cliquee_melange = recherche_melange;
																																																						}
																						 																				}
			 
CopierZone(0,1,0,0,Taille_EcranX,Taille_EcranY,0,0);
CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2]);
CopierZone(1,0,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);

keep_x_melange= tab[0][1];
keep_y_melange= tab[0][2];
tab[0][1]=tab[case_cliquee_melange][1];
tab[0][2]=tab[case_cliquee_melange][2];
tab[case_cliquee_melange][1]=keep_x_melange;
tab[case_cliquee_melange][2]=keep_y_melange;
			
			
}  



			if( direction == 1 &&  tab[0][1] != l+150-(l/taille_lignes)){
				
				printf(" detecté droite");
				
				case_melange[0]=tab[0][1]+(l/taille_lignes)+5;
				case_melange[1]=tab[0][2];
				
				for(recherche_melange = 0;recherche_melange <= num_case;recherche_melange++){
							if(tab[recherche_melange][1] == case_melange[0] && tab[recherche_melange][2] == case_melange[1]){
									case_cliquee_melange = recherche_melange;
																																																						}
																																										}
			 
CopierZone(0,1,0,0,Taille_EcranX,Taille_EcranY,0,0);
CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2]);
CopierZone(1,0,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);

keep_x_melange= tab[0][1];
keep_y_melange= tab[0][2];
tab[0][1]=tab[case_cliquee_melange][1];
tab[0][2]=tab[case_cliquee_melange][2];
tab[case_cliquee_melange][1]=keep_x_melange;
tab[case_cliquee_melange][2]=keep_y_melange;
			
			
}



			if( direction == 2 && tab[0][2] != 5+100-(h/taille)){
				
				printf(" detecté bas");
				
				case_melange[0]=tab[0][1];
				case_melange[1]=tab[0][2]+(h/taille)+5;
				
				for(recherche_melange = 0;recherche_melange <= num_case;recherche_melange++){
							if(tab[recherche_melange][1] == case_melange[0] && tab[recherche_melange][2] == case_melange[1]){
									case_cliquee_melange = recherche_melange;
																																																						}
																																										}
			 
CopierZone(0,1,0,0,Taille_EcranX,Taille_EcranY,0,0);
CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2]);
CopierZone(1,0,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);

keep_x_melange= tab[0][1];
keep_y_melange= tab[0][2];
tab[0][1]=tab[case_cliquee_melange][1];
tab[0][2]=tab[case_cliquee_melange][2];
tab[case_cliquee_melange][1]=keep_x_melange;
tab[case_cliquee_melange][2]=keep_y_melange;
			
			
}



			if( direction == 3 && tab[0][1] != 150 ){
				
				printf(" gauche");
				
				case_melange[0]=tab[0][1]-(l/taille_lignes)-5;
				case_melange[1]=tab[0][2];
				
				for(recherche_melange = 0;recherche_melange <= num_case;recherche_melange++){
							if(tab[recherche_melange][1] == case_melange[0] && tab[recherche_melange][2] == case_melange[1]){
									case_cliquee_melange = recherche_melange;
																																																						}
																																										}
			 
CopierZone(0,1,0,0,Taille_EcranX,Taille_EcranY,0,0);
CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2]);
CopierZone(1,0,tab[case_cliquee_melange][1],tab[case_cliquee_melange][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);

keep_x_melange= tab[0][1];
keep_y_melange= tab[0][2];
tab[0][1]=tab[case_cliquee_melange][1];
tab[0][2]=tab[case_cliquee_melange][2];
tab[case_cliquee_melange][1]=keep_x_melange;
tab[case_cliquee_melange][2]=keep_y_melange;
			
			
}

coup_melange++;
			
			/*
			haut[0]=tab[0][1];
			haut[1]=tab[0][2]-(h/taille);
			bas[0]=tab[0][1];
			bas[1]=tab[0][2]+(h/taille);
			gauche[0]=tab[0][1]-(l/taille_lignes);
			gauche[1]=tab[0][2];
			droite[0]=tab[0][1]+(l/taille_lignes);
			droite[1]=tab[0][2];*/

}while(coup_melange!=500);
/*Fonction de déplacement à la souris*/
do{
while(!SourisCliquee());
	{
		if(_X>=150 && _X<= 150+l+(taille_lignes-1)*5 && _Y>= 100 && _Y <= 100+h+(taille-1)*5){
			
			/*case du haut*/
			if(_X>=tab[0][1] && _X<=tab[0][1]+(l/taille_lignes) && _Y>=tab[0][2]-(h/taille)-5 && _Y <=tab[0][2]-5){
					case_inconnu[0]=tab[0][1];
					case_inconnu[1]=tab[0][2]-(h/taille)-5;
				
					printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}



			/*case de droite*/
			if(_X>=tab[0][1]+(l/taille_lignes)+5 && _X<=tab[0][1]+(2*(l/taille_lignes))+5 && _Y>=tab[0][2] && _Y <=tab[0][2]+(h/taille)){
					case_inconnu[0]=tab[0][1]+(l/taille_lignes)+5;
					case_inconnu[1]=tab[0][2];

					printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}


			/*case du bas*/
			if(_X>=tab[0][1] && _X<=tab[0][1]+(l/taille_lignes) && _Y >=tab[0][2]+(h/taille)+5  && _Y<= tab[0][2]+(2*(h/taille))+5){
					case_inconnu[0]=tab[0][1];
					case_inconnu[1]=tab[0][2]+(h/taille)+5;

					printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}


/*case du gauche*/
			if(_X >=tab[0][1]-(l/taille_lignes)-5 && _X<=tab[0][1]-5 && _Y>=tab[0][2] && _Y <=tab[0][2]+(h/taille)){
					case_inconnu[0]=tab[0][1]-(l/taille_lignes)-5;
					case_inconnu[1]=tab[0][2];
					printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}
					/*Cherche sur quelle case en particulier on a cliquée (sa postion quand l'image est résolue)*/
					for(recherche=0;recherche <= num_case;recherche++){
						
						if(tab[recherche][1] == case_inconnu[0] && tab[recherche][2] == case_inconnu[1]){
							case_cliquee = recherche;
							printf("%d\n",tab[case_cliquee][0]);
}
																																		  
																																			}
printf("%d   %d\n",tab[0][1],tab[0][2]);

/*Déplacer la case blanche et la case cliquée*/
CopierZone(0,1,0,0,Taille_EcranX,Taille_EcranY,0,0);
CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee][1],tab[case_cliquee][2]);
CopierZone(1,0,tab[case_cliquee][1],tab[case_cliquee][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);
/*changer leur coordonnées dans le tableau*/
keep_x= tab[0][1];
keep_y= tab[0][2];
tab[0][1]=tab[case_cliquee][1];
tab[0][2]=tab[case_cliquee][2];
tab[case_cliquee][1]=keep_x;
tab[case_cliquee][2]=keep_y;


printf("%d   %d\n",tab[case_cliquee][1],tab[case_cliquee][2]);
printf("%d   %d\n\n",tab[0][1],tab[0][2]);

 			}
 }

int verif_victoire = 0,valide;

/*
do{
	if(tab[verif_victoire][1] == pos_origine[verif_victoire][1] && tab[verif_victoire][2] == pos_origine[verif_victoire][2]){
				verif_victoire++;
																																		}
	else{
		valide=0;
			}
	
	
												}while( valide =! 0 && verif_victoire != num_case);
printf("Ici");
if( verif_victoire == num_case){
	bravo =1;
																}
*/
}while(bravo!=1);

//EffacerEcran(CouleurParNom("white"));
//EcrireTexte(700,400,"Bravo vous avez réussi",2);
 
}	



