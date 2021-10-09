
#include "ddo.h"
#include <string>
#include <iostream>
#include "model-factory.h"
#include "integrator-factory.h"
#include <assert.h>  
#include "rk4.h"
#include "ab2.h"

class DDOscillator;
class Euler; 
class Model;
class Rk4; 
class Ab2; 
class Integrator;
class ModelFactory; 


// Class needs modifying to be flexible to the n of x - some iterative print/string appending 
void printState(double t, double *x){
    printf("%15.8f %15.8f %15.8f\n", t, x[0], x[1]);
}


// Class not currently functional 
class InputAnalyser{
    // Example input: ./ode_solve ddo "2.0 1.5 0.25 1.0" "3.0 1.5 0.0" euler 0.1 40
    // Should therefore be argc = 7

    public: 
        InputAnalyser(int argc, char **argv): argc_(argc), argv_(argv){};
        ~InputAnalyser(){};

    std::string input_strs[6]; // Array holding seperate strings 
    
    private: 
    int argc_; 
    char **argv_; 

    int checkArgs_(){
        // Check number of args is 7 
        assert(argc_==7); 
        return 0;
    }
};





int main(int argc, char **argv){

    // Get parameters from the user and sort 
    int N = 10;
    double dt = 3.14159265359*6/N;
    double params[4] = {0.5, 1.0, 0.25, 1.0}; //omega, F, beta, omega_0 
    std::string model_inpt_string = "ddo";
    std::string integrator_inpt_string = "euler";


    // Generate model using factory 
    ModelFactory model_factory; 
    Model *model = model_factory.createModel(model_inpt_string, params); 

    // Generate integrator using factory 
     //IntegratorFactory *factory_1 = new IntegratorFactory();
    //IntegratorFactory int_factory; 
    //Integrator *integrator = factory_1->createIntegrator(integrator_inpt_string, dt, model);
    Ab2 integrator(dt, *model); 

    // Need some function setInitConditions()
    // Generate x_array: 
    int n = model->dimen();
    double t = 0;
    double x[n]; // Needs to be set to the initial conditions 
    for(int j=0; j<n;++j){x[j]=0;}  // Set initial conditions that are a temporary trial 


    printState(t, x);

    // Loop: run step function of the model - need to print at each timestep --> function within integrator or seperate class? 
    for (int i=0; i<N; ++i){
        integrator.Step(t, x);
        t += dt;
        printState(t, x);
    }


    // Destruction of any classes - possibly a factory to do this but might not be necessary? 


    return 0;
}


