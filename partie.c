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
 
}	



