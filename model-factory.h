#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include "ddo.h"
#include <string>
#include <iostream>


class Model;


class ModelFactory{
    public: 
        // Function to generate model and pass to user
       static Model *createModel(std::string type_str, double *params);
};


#endif // MODEL_FACTORY_H
