#include <iostream>

using namespace std;

#include "Catalogue.h"


Catalogue::Catalogue ()
{
	l = new Liste();
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
}


Catalogue::~Catalogue ( )
{
	delete[] l;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
}

void Catalogue::Ajouter (Trajet *Traj) {l->ajouter_fin(Traj);}

void Catalogue::affiche() {cout << "Catalogue : " << endl ; l->afficheCata();}

Liste* Catalogue::search(const char* vD, const char* vA){return l->search(vD,vA);}

void Catalogue::recherche(const char *Vd, const char *Va){ cout << "Résultat de la recherche : " << endl; l->search(Vd,Va)->afficheCata();}

