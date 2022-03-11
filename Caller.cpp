#include "SWI-Prolog.h"
#include "SWI-Stream.h"
#include "SWI-cpp.h"
#include "Caller.h"
#include <vector>
#include <string>
#include<iterator>
#include<iostream>
#include<ostream>
#include<algorithm>
#include<fstream>
#include<numeric>

using namespace std;

bool initialized = false;
char* query;

void init() {
    if(!initialized) {
        const char* av[2];
        av[0] = "Caller";
        av[1] = "-q";

        const char * dir = "SWI_HOME_DIR=/usr/bin/swipl";
        putenv((char*)dir);

        PL_initialise(2, (char**)av);
        PlCall("consult('coin.pl')");
        initialized = true;
    }
}

const char* callGregory(const char* predName) {
    init();
    term_t anspred, probpred;
    functor_t ppred;
    ppred = PL_new_functor(PL_new_atom(predName), 1);
    anspred = PL_new_term_ref();
    probpred = PL_new_term_ref();

    module_t coin_pl = PL_new_module(PL_new_atom("coin.pl"));

    PL_cons_functor(anspred, ppred, probpred);
    double probVal;
    if (PL_call(anspred, coin_pl)) {
        PL_get_float(probpred, &probVal);
        cout <<"The probability of " << predName << " is " << probVal << endl;
	return std::to_string(probVal).c_str();	 
    }
   return "";

}

int main(int argc, char ** argv) {
    // if (argc != 2) {
    //     cout<<"Usage Caller file.csv"<<endl;
    //     exit(1);
    // }
    callGregory("pheads"); 
    callGregory("ptails"); 
    cout<<endl;
}

