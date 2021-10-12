// ********************** INCLUDES AND FORWARD DECLARATIONS **********************
#include "ddo.h"
#include <string>
#include <vector>
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
class IntegratorFactory;


// Forward declarations: 
void printState(double t, double *x, int dimen); 

class Inputs{
    // CLASS HOLDS USER INPUTS FROM THE COMMAND LINE AND PROCESSES THEM 
    // IT ALSO HOLDS FUNCTIONS TO RETRIEVE THE INPUTS TO PASS TO OTHER FUNCTIONS

    public: 
        // DEFINE PUBLIC VARIABLES
        std::string model_str;      // 'model' type entered by user
        std::string integrator_str; // 'integrator' type entered by user 
        double *params;             // Params for model (dim = 4)
        double *ICs;                // Initial conditions for integration (dim = 3)
        double dt;                  // Integration timestep [s]
        int timesteps;              // Number of integration timesteps 

        Inputs();
        ~Inputs();

        int extractInputs(int argc_, char **argv_);
        double initICs(double *x, int dimen);

    private: 
        int checkArgs_(int num_args_);
        int processString_(double *out_array, std::string ipt_str, int dim);
};



// ********************** DRIVER CODE **********************
int main(int argc, char **argv){

    // Get cmd line parameters from the user and assign to members of user_i  
    Inputs user_i; 
    user_i.extractInputs(argc, argv); 

    // Generate model using factory 
    ModelFactory model_factory; 
    Model *model = model_factory.createModel(user_i.model_str, user_i.params); 

    // Generate integrator using factory  ********
    Euler integrator(user_i.dt, *model); 
    //IntegratorFactory int_factory; 
    //Integrator *integrator = int_factory.createIntegrator("euler", user_i.dt, model);

    // Initialise state variables and t 
    double x[model->dimen()];  
    double t = user_i.initICs(x, model->dimen()); // IC for x updated in this function also


    // Print initial state and then loop through timesteps 
    printState(t, x, model->dimen());

    for (int i=0; i<user_i.timesteps; ++i){
        integrator.Step(t, x);              // Integrate one timestep
        t += user_i.dt;                     // Update time
        printState(t, x, model->dimen());   // Print output
    }

    // Destruction of any classes - possibly a factory to do this but might not be necessary? 
    delete model;
    //delete integrator;

    return 0;
}




// ********************** OTHER FUNCTIONS/METHODS **********************

Inputs::Inputs(){
    // CONSTRUCTOR
    params = new double[4]; 
    ICs = new double[3];
};
        
Inputs::~Inputs(){
    // DESTRUCTOR
    delete [] params;
    delete [] ICs;
};


int Inputs::extractInputs(int argc_, char **argv_){
    // CONVERTS USER ARGV TO MULTIPLE VARIABLES USED BY PROGRAM 
    
    checkArgs_(argc_); // Check number of user input is acceptable

    // Assign various strings to members using conversion methods
    model_str = argv_[1];
    processString_(params, argv_[2], 4); // processes and assigns param string -> param array
    processString_(ICs, argv_[3], 3);    // processes and assigns IC string -> IC array
    integrator_str = argv_[4]; 
    dt = std::stod(argv_[5]);
    timesteps = std::stoi(argv_[6]);

    return 0;
}; 


double Inputs::initICs(double *x, int dimen){
    // SETS INITIAL CONDITIONS FOR X AND t
    double t = ICs[0]; 
    
    for (int i=0; i<dimen; i++){
        x[i] = ICs[i+1];
    }
    return t;
}

int Inputs::checkArgs_(int num_args_){
    // CHECK NUMBER OF ARGUMENTS FROM USER IS 7
    assert(num_args_==7); 
    return 0;
}


int Inputs::processString_(double *out_array, std::string ipt_str, int dim){
    // TAKES STRING (ipt_str) OF FLOATING POINTS AND ASSIGNS THEM TO AN ARRAY (out_array) OF LENGTH 'dim'
    
    int position; // char position in string 

    for (int k=0; k<dim; k++){
        position = ipt_str.find(" "); // get char position of space delimiter
        out_array[k] = std::stod(ipt_str.substr(0, position)); // take substring: convert to double
        ipt_str = ipt_str.substr(position+1); // Slice ipt_str for next loop 
    }
    return 0;
}


void printState(double t, double *x, int dimen){
    // Function prints out state variables to user in correct format for x of any dimension
    printf("%15.8f", t);
    
    for (int i=0; i<dimen; i++){
        printf(" %15.8f", x[i]);
    }
    printf("\n");
}
