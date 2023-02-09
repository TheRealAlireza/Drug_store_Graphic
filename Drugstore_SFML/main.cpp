#include "menu.cpp"
#include "headers/engine.h"

#include <iostream>
//#include <SFML/Graphics.hpp>




using namespace std;
using namespace sf;



int main()
{

Engine engine;
shuffled drugs;
prescription pers;

drugs.randomSet();
pers.fillPrescription();
pers.randomFill(drugs);
engine.get_drugs(drugs.randomDrugs,pers.drugNeeded);


engine.run();




//
//    menu program;
//    program.show();





    return 0;
}
