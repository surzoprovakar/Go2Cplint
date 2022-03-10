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

char* call(const char *probQ) {
    int len = strlen(probQ);
    for (int i = 0; i < len; i++) {
        query[i] = probQ[i];
    }
    return "";
}

void checkHeadProb() {
    init();
    term_t ansHeads, ansTails, probHeads, probTails;
    functor_t pheads, ptails;
    pheads = PL_new_functor(PL_new_atom(query), 1);
    ptails = PL_new_functor(PL_new_atom("ptails"), 1);
    ansHeads = PL_new_term_ref();
    ansTails = PL_new_term_ref();
    probHeads = PL_new_term_ref();
    probTails = PL_new_term_ref();

    module_t coin_pl = PL_new_module(PL_new_atom("coin.pl"));

    PL_cons_functor(ansHeads, pheads, probHeads);
    double probVal;
    if (PL_call(ansHeads, coin_pl)) {
        PL_get_float(probHeads, &probVal);
        cout<<"The probability of heads is "<<probVal<<endl; 
    }

    // PL_cons_functor(ansTails, ptails, probTails);
    // if (PL_call(ansTails, coin_pl)) {
    //     PL_get_float(probTails, &probVal);
    //     cout<<"The probability of tails is "<<probVal<<endl; 
    // }
}

int main(int argc, char ** argv) {
    // if (argc != 2) {
    //     cout<<"Usage Caller file.csv"<<endl;
    //     exit(1);
    // }
    checkHeadProb();
    cout<<endl;
}

