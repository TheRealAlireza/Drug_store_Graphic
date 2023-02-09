#include <iostream>
#include <stdlib.h>
#include "check.cpp"

using namespace std;

class menu
{
private:

    char choice;

public:
    void show()
    {
        cout << "\t\t\t\t\t\t\t\t\tDRUGSTORE\n";
        cout << "\t\t\t\t\t\t**********************************************************";
        cout << "\n\t\t\t\t\t\t*\t\t\t\t\t\t\t *\n\t\t\t\t\t\t*\t\t\t\t\t\t\t *";
        cout << "\n\t\t\t\t\t\t* Start\t\t\t\t\t\t\t *\n\t\t\t\t\t\t* Match Histories\t\t\t\t\t *\n\t\t\t\t\t\t* Exit\t\t\t\t\t\t\t *";
        cout << "\n\t\t\t\t\t\t*\t\t\t\t\t\t\t *\n\t\t\t\t\t\t*\t\t\t\t\t\t\t *";
        cout << "\n\t\t\t\t\t\t**********************************************************";
        cout << endl
             << "Enter : ";
        cin >> choice;
        switch (choice)
        {
            case 'S':
            case 's':
                start();
                break;
            case 'h':
            case 'H':
            case 'm':
            case 'M':
                history();
                break;
            case 'e':
            case 'E':
                exit(0);
        }
    }

    void start()
    {

        cout << "wellcome to buali drugstore \nyou should help drugstore keeper to check shelfs and count of drugs we need for drugstore ." << endl;

        shuffled drugs; // class object

        drugs.randomSet();

        prescription noskhe; // class object

        check correct; // class object

        noskhe.fillPrescription();

        noskhe.randomFill(drugs);

        // score point; // class object
        correct.Name();
        correct.Level();
        correct.scrutiny(noskhe);


    }
    void history()
    {

        check ha;
        ha.history();
    }
};
