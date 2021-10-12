#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include "ddo.h"
#include <string>
#include <iostream>

class DDOscillator;
class Euler; 
class Model;
class Integrator;


class ModelFactory{
    public: 
        ModelFactory();  // constructor
        ~ModelFactory(); // destructor

        // Function to generate model and pass to user
        Model *createModel(std::string type_str, double *params);
};


#endif // MODEL_FACTORY_H
