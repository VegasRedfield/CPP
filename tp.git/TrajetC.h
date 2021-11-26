#if ! defined ( TrajetC_H )
#define TrajetC_H
#include "Trajet.h"
#include "TrajetS.h"
#include "Liste.h"
using namespace std; 

class TrajetC : public Trajet
{
public:

    TrajetC(const char * laVilleDep, const char * laVilleArr, Liste * laListeTrajet);

    
    void Afficher(); 

    virtual ~TrajetC ( );

protected:

    Liste * listeTrajetS;
};

#endif

