#include <iostream>
#include<cstring>
using namespace std;

#include "TrajetS.h"


TrajetS::TrajetS (const char * laVilleDep, const char * laVilleArr, const char * leTransport):Trajet(laVilleDep, laVilleArr),moyTrans(leTransport){
 }

TrajetS::~TrajetS ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetS>" << endl;
#endif
}
void TrajetS::Afficher()
{
cout << "trajet simple entre " << villeDep << " et "<< villeArr << " qui s'effectue en " << moyTrans; 
}
