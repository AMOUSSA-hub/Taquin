#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<string.h>
#include<time.h>
void deplacement_clavier(int h,int l, int taille, int taille_lignes,int tab[][4],int* x,int* y,int posc,int posl,int matrice[][taille_lignes]){
	int case_blanche[2]={*x,*y};//Sauvegarder posx et posy de la case blanche
	unsigned int entree;//Savoir ce que l'utilisateur envoie comme touche pou pouvoir bouger les cases
	int a=0,d,test;
	int verification[taille][taille_lignes];
	int col,lign,ite=0;
	for (lign=0;lign<taille;lign++){
		for (col=0;col<taille_lignes;col++){
			ite++;
			verification[lign][col]=ite;
		}
	}
	//char compteur[100]="0";
	//Correspondance : up=0XFF52; down=0XFF54; right=0XFF53; left=0XFF51
	test = memcmp(verification,matrice,sizeof(verification));
	while(test!=0){
		entree = Touche();//Affectation de la touche à la variable entree
		test = memcmp(verification,matrice,sizeof(verification));
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
		}	
	}
}
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
		sleep(0,6);
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

int main(int argc, char * argv[]){
	int posx=150,posy=100,i,j=0;//Position initiales
	int l,h,choix;//Image
	int x,y;//Variable pour l'aléatoire
	int posc,posl;
	char *image_selectionnee[16]={("luffy_grand.png"),("Kangoo.jpg"),("Vegeta.jpg")};//Regroupement du chemin des images
	scanf("%d",&choix);
	if (choix == 1){
		l=650;
		h=366;//Luffy
	}else if(choix == 2){		//Adapatition des résolutions en fonction du choix de l'utilisateur
		l=570;
		h=384;//kangoo
	}else if(choix == 3){
		l=480;
		h=270;//Vegeta
	}
	int taille,taille_lignes,num_case=0;
	scanf("%d %d",&taille,&taille_lignes);
	int tab[taille*taille_lignes-1][4]; 
	int matrice[taille][taille_lignes];
	InitialiserGraphique();
	CreerFenetre(100,0,1100,900);
	for(i=0;(i+(h%taille))<h;i+=(h/taille)){//Boucle principale pour decouper l'image, boucle pour les lignes
    	for(j=0;(j+(l%taille_lignes))<l;j+=(l/taille_lignes)){//Boucle pour les colonnes
        	ChargerImage(image_selectionnee[choix-1],posx,posy,j,i,(l/taille_lignes),(h/taille));
			printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));//test à supprimer
			tab[num_case][0]=num_case;
			tab[num_case][1]=posx;
			tab[num_case][2]=posy;					// enregistrement des valeurs de chaques cases dans un tableau
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
	CopierZone(10,0,0,0,l/taille_lignes,h/taille,150,100); // Création de la case vide
	sleep(2);
	ChoisirEcran(0);
	melange_aleatoire(h,l,taille,taille_lignes,tab,&x,&y,posc,posl,matrice);//Appel de la fonction qui mélange les cases. Utilisation de pointeur pour gérer pluiseurs changement de valeurs
	deplacement_clavier(h,l,taille,taille_lignes,tab,&x,&y,posc,posl,matrice); // Appel de la fonction pour deplacer les cases. On reprend la position de la case blanche pour pouvoir la déplacer.
	Touche();
	FermerGraphique();
return EXIT_SUCCESS;
}