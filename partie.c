#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"partie.h"
#define Taille_EcranX 1600
#define Taille_EcranY 800
#include <time.h>

int melange_aleatoire(int h,int l, int taille, int taille_lignes,int tab[][4],int* x,int* y,int posc,int posl,int matrice[][taille_lignes]){
	int alea,b;//Gestion des variables pour l'aléatoire du mélange
	int case_blanche[2]={tab[0][1],tab[0][2]};//Sauvegarder posx et posy de la case blanche
	int col,lign,ite=0,d;
	for (lign=0;lign<taille;lign++){
		for (col=0;col<taille_lignes;col++){
			ite++;
			matrice[lign][col]=ite;
		}
	}
	srand (time(NULL));
	for (b=0;b <= 200;b++){
		alea =rand()%(5-1+1)+1;
		if (alea == 1 && (case_blanche[1]+((h/taille)+5))<=tab[taille*taille_lignes-1][2]){//condition pour deplacement et non depacement des limites HAUT
			CopierZone(0,1,0,0,1000,1000,0,0);                                                                                                                             
			CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]+((h/taille)+5));//Changement de case blanche avec la case voulue
			CopierZone(1,0,case_blanche[0],case_blanche[1]+((h/taille)+5),l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);//Changement de la case avec l'ancienne case blanche
			case_blanche[1]+=((h/taille)+5);//enregistrement de la nouvelle position de la case blanche
			d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc+1][posl]; // on deplace les valeurs de la matrice pour pouvoir verifier la position de chaque case et ainsi determiner la position gagnante
		  	matrice[posc+1][posl]=d;
		  	posc+=1;

		}else if (alea == 2 && (case_blanche[1]-((h/taille)+5))>=tab[0][2]){//BAS
			CopierZone(0,1,0,0,1000,1000,0,0);                                                                                                                                 
			CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]-((h/taille)+5));
			CopierZone(1,0,case_blanche[0],case_blanche[1]-((h/taille)+5),l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
			case_blanche[1]-=((h/taille)+5);
			d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc-1][posl];
		  	matrice[posc-1][posl]=d;
		  	posc-=1;
		}else if (alea == 3 && case_blanche[0]+((l/taille_lignes)+5) <= tab[taille*taille_lignes-1][1]){//GAUCHE
			CopierZone(0,1,0,0,1000,1000,0,0);
		  	CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0]+((l/taille_lignes)+5),case_blanche[1]);
		  	CopierZone(1,0,case_blanche[0]+((l/taille_lignes)+5),case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
		  	case_blanche[0]+=((l/taille_lignes)+5);
		  	d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc][posl+1];
		  	matrice[posc][posl+1]=d;
		  	posl+=1;
		}else if (alea == 4 && case_blanche[0]-((l/taille_lignes)+5) >= tab[0][1]){//DROITE
			CopierZone(0,1,0,0,1000,1000,0,0);
		  	CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0]-((l/taille_lignes)+5),case_blanche[1]);
		  	CopierZone(1,0,case_blanche[0]-((l/taille_lignes)+5),case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
		  	case_blanche[0]-=((l/taille_lignes)+5);
		  	d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc][posl-1];
		  	matrice[posc][posl-1]=d;
		  	posl-=1;
		}
	}
	*x=case_blanche[0];
	*y=case_blanche[1];
}



void deplacement_clavier(int h,int l, int taille, int taille_lignes,int tab[][4],int* x,int* y,int posc,int posl,int matrice[][taille_lignes]){
	int case_blanche[2]={*x,*y};//Sauvegarder posx et posy de la case blanche
	unsigned int entree;//Savoir ce que l'utilisateur envoie comme touche pou pouvoir bouger les cases
	int a=0,d,test;
	int verification[taille][taille_lignes];
	int col,lign,ite=0;
	/*for (lign=0;lign<taille;lign++){
		for (col=0;col<taille_lignes;col++){
			ite++;
			verification[lign][col]=ite;
		}
	}*/
	//char compteur[100]="0";
	//Correspondance : up=0XFF52; down=0XFF54; right=0XFF53; left=0XFF51
	//test = memcmp(matrice,verification,sizeof(&matrice));
	while(a==0){
		entree = Touche();//Affectation de la touche à la variable entree
		//test = memcmp(matrice,verification,sizeof(&matrice));
		if (entree == 0XFF52 && (case_blanche[1]+((h/taille)+5))<=tab[taille*taille_lignes-1][2]){//condition pour deplacement et non depacement des limites
			CopierZone(0,1,0,0,1000,1000,0,0);                                                                                                                               
			CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]+((h/taille)+5));//Changement de case blanche avec la case voulue
			CopierZone(1,0,case_blanche[0],case_blanche[1]+((h/taille)+5),l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);//Changement de la case avec l'ancienne case blanche
			case_blanche[1]+=((h/taille)+5);//enregistrement de la nouvelle position de la case blanche
			//Verification
			d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc+1][posl]; // on deplace les valeurs de la matrice pour pouvoir verifier la position de chaque case et ainsi determiner la position gagnante
		  	matrice[posc+1][posl]=d;
		  	posc+=1;
			//compteur++;
		}else if (entree == 0XFF54 && (case_blanche[1]-((h/taille)+5))>=tab[0][2]){
			CopierZone(0,1,0,0,1000,1000,0,0);                                                                                                                                 
			CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]-((h/taille)+5));
			CopierZone(1,0,case_blanche[0],case_blanche[1]-((h/taille)+5),l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
			case_blanche[1]-=((h/taille)+5);
			d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc-1][posl];
		  	matrice[posc-1][posl]=d;
		  	posc-=1;
			//compteur++;
		}else if (entree == 0XFF51 && case_blanche[0]+((l/taille_lignes)+5) <= tab[taille*taille_lignes-1][1]){
			CopierZone(0,1,0,0,1000,1000,0,0);
		  	CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0]+((l/taille_lignes)+5),case_blanche[1]);
		  	CopierZone(1,0,case_blanche[0]+((l/taille_lignes)+5),case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
		  	case_blanche[0]+=((l/taille_lignes)+5);
		  	d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc][posl+1];
		  	matrice[posc][posl+1]=d;
		  	posl+=1;
		  	//compteur++;
		}else if (entree == 0XFF53 && case_blanche[0]-((l/taille_lignes)+5) >= tab[0][1]){
			CopierZone(0,1,0,0,1000,1000,0,0);
		  	CopierZone(0,0,case_blanche[0],case_blanche[1],l/taille_lignes,h/taille,case_blanche[0]-((l/taille_lignes)+5),case_blanche[1]);
		  	CopierZone(1,0,case_blanche[0]-((l/taille_lignes)+5),case_blanche[1],l/taille_lignes,h/taille,case_blanche[0],case_blanche[1]);
		  	case_blanche[0]-=((l/taille_lignes)+5);
		  	d = matrice[posc][posl];
		  	matrice[posc][posl]=matrice[posc][posl-1];
		  	matrice[posc][posl-1]=d;
		  	posl-=1;
		  	//compteur++;
		}else if (entree == 0xff80){
			a = 1;
		}	
	}
}

void decoupage_image(int image,int ligne, int colonne,int controle ){
		int posx=150,posy=100,i,j=0;
		int l,h,choix;
		char *image_selectionnee[16]={("luffy_grand.png"),("Kangoo.jpg"),("Vegeta.jpg")};
		int x,y;//Variable pour l'aléatoire
		int posc,posl;
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
		int taille,taille_lignes, num_case=0;
		taille = ligne;
		taille_lignes = colonne;
		int tab[taille*taille_lignes-1][4]; 
		int matrice[taille][taille_lignes];
	  InitialiserGraphique();
		CreerFenetre(100,100,Taille_EcranX,Taille_EcranY);
		for(i=0;(i+( h%taille))<h;i+=(h/taille) ){
      for(j=0;(j+(l%taille_lignes))<l;j+=(l/taille_lignes)){
        ChargerImage(image_selectionnee[choix-1],posx,posy,j,i,(l/taille_lignes),(h/taille));
				printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));
				tab[num_case][0]=num_case;
				tab[num_case][1]=posx;
				tab[num_case][2]=posy;
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



if (controle==2){
int recherche,case_cliquee,case_cliquee_melange,keep_x,keep_y,bravo,direction,coup_melange=0;
int recherche_melange,keep_x_melange,keep_y_melange;
int case_inconnu[1];
int case_melange[1];
srand(time(NULL));
        ChargerImage(image_selectionnee[choix-1],800,100,0,0,l,h);
 
/*Fonction de mélange*/
do{			
		/*	haut=0
			droite=1
			bas=2
			gauche=3*/	
	
			direction =rand()%(3-0+1)+0;



			if( direction == 0 && tab [0][2] != 100){
				
				
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
}
					/*Cherche sur quelle case en particulier on a cliquée (sa postion quand l'image est résolue)*/
					for(recherche=0;recherche <= num_case;recherche++){
						
						if(tab[recherche][1] == case_inconnu[0] && tab[recherche][2] == case_inconnu[1]){
							case_cliquee = recherche;
}
																																		  
																																			}

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



 		 	}
 }  

//int verif_victoire = 0,valide;

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

} 
		
		

if (controle == 1){

melange_aleatoire(h,l,taille,taille_lignes,tab,*x,*y,posc,posl,matrice);//Appel de la fonction qui mélange les cases. Utilisation de pointeur pour gérer pluiseurs changement de valeurs
    deplacement_clavier(h,l,taille,taille_lignes,tab,&x,&y,posc,posl,matrice); // Appel de la fonction pour deplacer les cases. On reprend la position de la case blanche pour pouvoir la déplacer.	
}






}



