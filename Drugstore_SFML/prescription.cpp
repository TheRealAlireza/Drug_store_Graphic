#include <string>
#include <time.h>

#include "shuffle.cpp"
using namespace std;

class prescription
{
    friend class check;
private:


public:
    string drugNeeded[12][3]; // dar [i][0] name darrohaye noskhe , dar [i][1] tedade daroo , dar [i][2] shomare ghafase
    void fillPrescription() // por kardan index haye noskhe bekhatere moghayese index hash badan dar tabe randomFill
    {

        for (size_t i = 0; i < 12; i++)
        {
            drugNeeded[i][0] = to_string(i + 60);
        }

    }
    void randomFill(shuffled &drugs)
    {

        srand(time(0));
        for (size_t i = 0; i < 15; i++)
        {

            for (size_t j = 0; j < 15; j++)
            {
                int k = (rand() % 30);

                drugNeeded[i][0] = drugs.randomDrugs[k][0];         // name daroo
                drugNeeded[i][1] = drugs.randomDrugs[k][1];         // tedade daroo
                drugNeeded[i][2] = drugs.randomDrugs[k][2];         // shomare ghafase


                if (i == j)
                {

                    break;

                }
                if (drugNeeded[i][0] == drugNeeded[j][0])
                {
                    i--;
                    break;
                }

            }
        }


    }
};