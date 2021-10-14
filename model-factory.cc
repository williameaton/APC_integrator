#include <string>
#include <iostream>
#include "ddo.h"
#include "lv.h"
#include "model-factory.h"

class Model;

// Construct and return ptr to correct model based on type_str 
Model *ModelFactory::createModel(std::string type_str, double *params){
    if (type_str=="ddo"){
        return new DDOscillator(params); 
    } 

    else if (type_str=="lv"){
        return new Lv(params);
    }

    else{
        // Invalid input - generate error message: 
        std::cout << "ERROR: invalid Model called..." << "\n";
        std::cout << "*** need to make this a proper error message ***" << "\n";
        return NULL;
    }
}

