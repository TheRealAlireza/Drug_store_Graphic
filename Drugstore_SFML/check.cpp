#include <chrono>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "prescription.cpp"
using namespace std::chrono;
using namespace std;

class check
{
    friend class prescription;

private:
    string name;
    float time;
    string correctShelf;             // shomare ghafase
    string correctCount;             // tedade daroo
    float score = 0;                 // score
    unsigned int correctChoice = 0;  // tedade ghafase dorost
    unsigned int correctChoice1 = 0; // tedade daroo dorost
    string level;                      // daraje sakhti bazi
    int stage;                       // stae bar asase level
    string read;                     // khandan az file
public:
    void Name()
    {
        cout << "Enter your Name : ";
        cin >> name;
        cout << endl;
    }

    void Level()
    {
        cout << "Set the difficulty level of the game : (Eazy , Normal , Hard ,impossible)\n";
        cin >> level;

        if (level == "eazy" || level == "Eazy")
        {
            stage = 6;
        }

        if (level == "normal" || level == "Normal")
        {
            stage = 10;
        }
        if (level == "hard" || level == "Hard")
        {
            stage = 15;
        }
        if (level == "Impossible" || level == "impossible")
        {
            stage = 15;
        }
    }

    void scrutiny(prescription &noskhe)
    {
        if (level == "Impossible" || level == "impossible")
        {
            cout << "wow You chose the impossible level !!!!\nyou have only 25 Seconds to save everything in your mind\n";
            sleep(25);
            system("clear");
        }

        auto start = high_resolution_clock::now();
        for (size_t i = 0; i < stage; i++)
        {
            cout << noskhe.drugNeeded[i][0] << " : ";
            cin >> correctShelf >> correctCount;
            if (noskhe.drugNeeded[i][2] == correctShelf)
            {
                score += 5;
                correctChoice++;
            }
            if (noskhe.drugNeeded[i][1] == correctCount)
            {
                score += 2.5;
                correctChoice1++;
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<microseconds>(stop - start)) / 1000000;

        if (level == "Impossible" || level == "impossible")
        {
            if (duration.count() < 30)
            {
                score += 40;
            }
            else if (duration.count() < 50)
            {
                score += 20;
            }
        }

        if (level == "eazy" || level == "Eazy")
        {
            if (duration.count() < 15)
            {
                score += 20;
            }
            else if (duration.count() < 20)
            {
                score += 5;
            }
        }
        if (level == "hard" || level == "Hard")
        {
            if (duration.count() < 20)
            {
                score += 20;
            }
            else if (duration.count() < 25)
            {
                score += 5;
            }
        }
        if (level == "hard" || level == "Hard")
        {
            if (duration.count() < 30)
            {
                score += 25;
            }
            else if (duration.count() < 50)
            {
                score += 15;
            }
        }
        ofstream matchHistory("Information.txt");
        matchHistory << "Name : " << name << endl
                     << "level : " << level << endl
                     << "time : " << duration.count() << endl
                     << "Score : " << score << endl
                     << "-----------------------------------------------------------------------" << endl;
        matchHistory.close();
        cout << "time " << duration.count() << endl;
        cout << "count of correct shelf's number : " << correctChoice << endl
             << "count of correct drugs : " << correctChoice1 << endl;
        cout << "your point is : " << score << endl;
    }

    void history()
    {

        ifstream Read_matchHistory("Information.txt");

        while (getline(Read_matchHistory, read))
        {
            cout << read << endl;
        }
    }
};
