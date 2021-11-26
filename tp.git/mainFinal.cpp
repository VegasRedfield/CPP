#include <iostream>
#include <cstring>

#include "Catalogue.h"
#include "TrajetS.h"
#include "TrajetC.h"

void add(Catalogue *c);
TrajetS* initTS();
TrajetC* initTC();
void search(Catalogue *cata);

int main(void)
{
	cout << "Bienvenue !" << endl << "Rappel : à tout moment, vous pouvez taper 'menu' pour revenir au menu principal et annuler l'action en cours" << endl << endl;

	char *lecture = new char[100]; 
	Catalogue *cata;

	cata = new Catalogue();

	while(strcmp(lecture,"exit") != 0)
  	{
  		cout << "Que voulez vous faire ?" << endl << "Pour ajouter un trajet, tapez 'add'" << endl << "Pour afficher le contenu du catalogue, tapez 'afficher'" << endl << "Pour effetuer une recherche, tapez 'search'" << endl << "Pour quitter l'application, tapez 'exit'" << endl << endl;

  		cin >> lecture;
		cout << endl;
		if (cin.fail())
		{
	     	cerr << "input error" << endl;
	     	exit(0);
		}
	    if (strcmp(lecture,"add")==0)
	     	add(cata);
	    else if (strcmp(lecture,"search")==0)
	     	search(cata);
	     else if (strcmp(lecture, "afficher")==0)
	     	cata->affiche();
	}



    return 0;
}

void add(Catalogue *c)
{
	char* l = new char[100];
	Trajet *T;
	cout << "Trajet simple ou composé ? (tapez S ou C)" << endl << endl;

	cin >> l;
	cout << endl;
	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}else if(strcmp(l,"menu")==0)
		return;
	if (strcmp(l,"S")==0)
	{
	    cout << "Vous avez choisi d'ajouter un trajet simple à votre catalogue." << endl;
	    T = initTS();
	    if(T==NULL)
	    	return;
	    c->Ajouter(T);
	}
	else if (strcmp(l,"C")==0)
	{
	    cout << "Vous avez choisi d'ajouter un trajet composé à votre catalogue." << endl;
	    T = initTC(); 
	    if(T==NULL)
	    	return;
	    c->Ajouter(T);  	
	}
	cout << "Trajet ajouté !" << endl << endl;
}

TrajetS* initTS()
{
	char* mt = new char[100];
	char* vd = new char[100];
	char* va = new char[100];

	cout << "Veuillez saisir la ville de départ de votre trajet :" << endl << endl;

	cin >> vd;
	cout << endl;

	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}else if(strcmp(vd,"menu")==0)
		return NULL;

	cout << "Veuillez saisir la ville d'arrivée de votre trajet :" << endl << endl;

	cin >> va;
	cout << endl;
	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}else if(strcmp(va,"menu")==0)
		return NULL;

	cout << "Veuillez saisir le moyen de transport utilisé pour effectuer votre trajet :" << endl << endl;

	cin >> mt;
	cout << endl;
	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}else if(strcmp(mt,"menu")==0)
		return NULL;

	return new TrajetS(vd,va,mt);
}

TrajetC* initTC()
{
	int nb = 0;
	char* vd = new char[100];
	char* va = new char[100];
	char* villeAv = new char[100];
	char* villeAp;
	char* mt = new char[100];

	cout << "Saisissez la ville de laquelle part votre trajet : " << endl << endl;

	cin >> vd;
	cout << endl;
	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}else if(strcmp(vd,"menu")==0)
		return NULL;
	villeAv = vd;
	Liste* LTS = new Liste();

	cout << "Maintenant, tapez à la suite des doublets villes/moyens de transports (appuyez sur entrée entre les deux)." << endl << "Quand vous avez terminé votre trajet, tapez 'fin'" << endl << endl;

	while(1)
  	{
  		villeAp = new char[100];
  		mt = new char[100];
  		cout << "Etape " << nb << endl;
  		cin >> villeAp;
  		if (cin.fail())
		{
	     	cerr << "input error" << endl;
	     	exit(0);
		}else if(strcmp(villeAp,"menu")==0)
		{
			cout << endl;
			return NULL;
		}
  		if(strcmp(villeAp,"fin")==0)
  		{
  			cout << endl;
  			break;
  		}
		cin >> mt;
		if (cin.fail())
		{
	     	cerr << "input error" << endl;
	     	exit(0);
		}else if(strcmp(villeAp,"menu")==0)
		{
			cout << endl;
			return NULL;
		}
		
		LTS -> ajouter_fin(new TrajetS(villeAv,villeAp,mt));

		villeAv = villeAp;

		va = villeAp;

		nb++;
	}

	return new TrajetC(vd,va,LTS);
}

void search(Catalogue *cata)
{
	char * villeDep = new char [100]; 
	char * villeArr = new char [100]; 
	   		
	cout << "Entrez votre ville de Départ  " << endl;
	
	cin >> villeDep;
	cout << endl;
	if (cin.fail())
	{
     	cerr << "input error" << endl;
     	exit(0);
	}
	
		   		
	cout << "Entrez votre ville d'Arrivée "<< endl << endl;
	
	cin >> villeArr;
	cout << endl;

	cata->search(villeDep,villeArr)->afficheCata();

	
	
}