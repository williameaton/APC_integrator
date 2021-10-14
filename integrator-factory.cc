
#include <iostream>
#include <string>
#include "integrator-factory.h"
#include "model.h"
#include "euler.h"
#include "rk4.h"
#include "ab2.h"

// Let the compiler know these classes will exist somewhere
class Integrator; 
class Model; 


// Empty constructor and destructor 
IntegratorFactory::IntegratorFactory() {}
IntegratorFactory::~IntegratorFactory() {}


Integrator* IntegratorFactory::createIntegrator(std::string integrator_type, double dt, const Model *model){
    // FUNCTION RETURNS A PTR TO AN INTEGRATOR OBJECT OF THE DESIRED TYPE

    if (integrator_type=="euler"){
        return new Euler(dt, *model);
    }

    else if(integrator_type=="rk4"){
        // Create a model of type RK4 
        return new Rk4(dt, *model);

    }

    else if(integrator_type=="ab2"){
        // Create a model of type AB2 
        return new Ab2(dt, *model);

    }
    
    else{
        std::cout << "ERROR: no valid integrator method called" << "\n";
        std::cout << "*** need to make this a proper error message ***" << "\n";
        return NULL;
    }
}