#include <iostream>
#include <string>
#include "integrator-factory.h"
#include "model.h"
#include "euler.h"

// Let the compiler know these classes will exist somewhere
class Integrator; 
class Model; 


// Empty constructor and destructor 
IntegratorFactory::IntegratorFactory() {}
IntegratorFactory::~IntegratorFactory() {}


Integrator* createIntegrator(std::string type, double dt, const Model &model){
    // FUNCTION RETURNS A PTR TO AN INTEGRATOR OBJECT OF THE DESIRED TYPE

    if (type=="euler"){
        // Create a model of type euler 
        return new Euler(dt, model);
    }

    else if(type=="rk4"){
        // Create a model of type RK4 
        std::cout << "ERROR: RK4 under construction" << "\n";
        return NULL;
    }

    else if(type=="ab2"){
        // Create a model of type AB2 
        std::cout << "ERROR: AB2 under construction" << "\n";
        return NULL; 
    }
    
    else{
        std::cout << "ERROR: no valid integrator method called" << "\n";
        std::cout << "*** need to make this a proper error message ***" << "\n";
        return NULL;
    }

}