#ifndef INTEGRATOR_FACTORY_H_
#define INTEGRATOR_FACTORY_H_

// Other relevant includes
#include <iostream>
#include <string>
#include "euler.h"


// Forward declarations 
class Integrator; 
class Model; 

// Class integratorFactory holding createIntegrator function 
class IntegratorFactory{
    
    public: 
        IntegratorFactory();             // Constructor
        ~IntegratorFactory();		     // Destructor
        
        Integrator* createIntegrator(std::string type, double dt, const Model *model);  // Factory function 
    };

#endif //INTEGRATOR_FACTORY_H_
