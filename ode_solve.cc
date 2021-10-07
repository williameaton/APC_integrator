
#include "ddo.h"
#include <string>
#include <iostream>
#include "model-factory.h"
#include "integrator-factory.h"

class DDOscillator;
class Euler; 
class Model;
class Integrator;
class ModelFactory; 





int main(){

    // Get parameters from the user and sort 
    double dt = 0.5;
    double params[4] = {3.0, 5.0, 0.25, 1.0}; //omega, F, beta, omega_0 
    std::string model_inpt_string = "ddo";
    std::string integrator_inpt_string = "euler";


    // Generate model using factory 
    ModelFactory model_factory; 
    Model *model = model_factory.createModel(model_inpt_string, params); 


    // Generate integrator using factory 
    // IntegratorFactory factory_1 = new IntegratorFactory()
    //IntegratorFactory int_factory; 
    //Integrator *integrator = int_factory.createIntegrator(integrator_inpt_string, dt, model);


    // Loop: run step function of the model - need to print at each timestep --> function within integrator or seperate class? 
    





    // Destruction of any classes - possibly a factory to do this but might not be necessary? 


    return 0;
}

