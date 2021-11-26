#include <iostream>
#include<cstring>

#include "Trajet.h"

using namespace std;

const char* Trajet::getVd(void){return villeDep;}

const char* Trajet::getVa(void){return villeArr;}

Trajet::Trajet (const char * laVilledep,const char * laVilleArr)
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
villeDep = laVilledep; 
villeArr = laVilleArr; 
}


Trajet::~Trajet ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}

