#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <iomanip>
#include <unistd.h>

using namespace std;

enum drugCode
{
    Atorvastatin,
    Levothyroxine,
    Metformin,
    Lisinopril,
    Amlodipine,
    Metoprolol,
    Albuterol,
    Omeprazole,
    Losartan,
    Gabapenti,
    Hydrochlore,
    Sertraline,
    Simvastatin,
    Montelukast,
    Escitalopram,
    Acetaminophen,
    Hydrocodone,
    Rosuvastatin,
    Bupropion,
    Furosemide,
    Pantoprazol,
    Trazodone,
    Dextro,
    Amphetamine,
    Aspartate,
    Fluticasone,
    Tamsulosin,
    Fluoxetine,
    Carvedilol
};

class shuffled
{
    friend class prescription;

private:
    string drugs[30] =
            {
                    "Atorvastatin", "Levothyrox", "Metformin", "Lisinopril", "Amlodipine", "Metoprolol", "Albuterol", "Omeprazole", "Losartan", "Gabapenti", "Hydrochloro", "Sertraline", "Simvastatin", "Montelukast", "Escitalopram", "Acetaminophen", "Hydrocodone",
                                                                                                                                                                                                                                                                    "Rosuvastatin",
                    "Bupropion", "Furosemide", "Pantoprazol", "Trazodone", "Dextro", "Dextroamphe", "Amphetamine", "Aspartate", "Fluticasone", "Tamsulosin", "Fluoxetine", "Carvedilol"};


public:
    string randomDrugs[30][3]; // dar [i][0] name daroo , adr [i][1] teade daroo , dar [i] [2] shomare ghafase
    void randomSet()
    {
        srand(time(0));
        random_shuffle(&drugs[0], &drugs[29]), rand();

        for (size_t i = 0; i < 30; i++)
        {
            randomDrugs[i][0] = drugs[i];
            randomDrugs[i][2] = to_string(i + 1);
        }

        for (size_t i = 0; i < 30; i++)
        {
            randomDrugs[i][1] = to_string(rand() % 5);
        }

        unsigned int j = 1;

        sleep(2); // delay

        cout << "*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*" << endl;

        for (size_t i = 0, k = 1; i < 30; i++, j++, k++)
        {

            cout << left << setw(35) << string("|" + to_string(j) + "." + randomDrugs[i][0] + " " + randomDrugs[i][1] + "X" + "|");

            if ((k % 5 == 0))
            {
                cout << endl;
                cout << endl;
            }
        }
        cout << "*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*";
        cout << endl;
        cout << endl;
    }
};
