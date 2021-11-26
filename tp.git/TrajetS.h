#if ! defined ( TrajetS_H )
#define TrajetS_H
#include "Trajet.h"

class TrajetS : public Trajet
{

public:

	void Afficher(); 

	TrajetS (const char * laVilleDep, const char * laVilleArr, const char * leTransport);

	virtual ~TrajetS ( );

protected:

    const char * moyTrans; 

};

#endif

