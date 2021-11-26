#include <iostream>
#include<cstring>

#include "TrajetC.h"


TrajetC::TrajetC(const char * laVilleDep, const char * laVilleArr, Liste * laListeTrajet):Trajet(laVilleDep, laVilleArr),listeTrajetS(laListeTrajet)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetC>" << endl;
#endif
}


TrajetC::~TrajetC ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetC>" << endl;
#endif
}


void TrajetC::Afficher()
{

	cout << "trajet composé entre " << villeDep << " et "<< villeArr << " composé d'un ";
	listeTrajetS->afficheComp();
}