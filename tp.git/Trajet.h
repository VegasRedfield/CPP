#if ! defined ( Trajet_H )
#define Trajet_H 

class Trajet
{
public:

	virtual void Afficher() = 0; 
    Trajet (const char *vDep, const char *vArr);
 	virtual ~Trajet ();
    const char* getVd(void);
    const char* getVa(void);

protected:
	const char * villeDep; 
	const char * villeArr; 
	
};

#endif

