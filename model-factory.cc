
#include "ddo.h"
#include "lv.h"
#include <string>
#include <iostream>


class DDOscillator;
class Model;

#include "model-factory.h"

ModelFactory::ModelFactory(){};
ModelFactory::~ModelFactory(){};



Model *ModelFactory::createModel(std::string type_str, double *params){

    
    if (type_str=="ddo"){
        return new DDOscillator(params); 
    } 

    else if (type_str=="lv"){
        return new Lv(params);
    }

    else{
        // Generate error message: 
        std::cout << "ERROR: invalid Model called..." << "\n";
        std::cout << "*** need to make this a proper error message ***" << "\n";
        return NULL;

    }
};

