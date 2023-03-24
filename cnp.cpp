#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

chrono::system_clock::time_point now = chrono::system_clock::now();
time_t tt = chrono::system_clock::to_time_t(now);
tm local_tm = *localtime(&tt);
int an = local_tm.tm_year + 1900;
int luna = local_tm.tm_mon + 1;
int zi = local_tm.tm_mday;

int main()
{
    ifstream cnpf("date.in");
    ofstream out("date.out");
    char cnp[15]; // SAALLZZJJNNNC
    int nr = 1;
    while (cnpf >> cnp)
    {
        int S = (int)cnp[0] - 48;
        int AA = (((int)cnp[1] - 48) * 10) + (int)cnp[2] - 48;
        int varsta = 0;
        int LL = (((int)cnp[3] - 48) * 10) + (int)cnp[4] - 48;
        int ZZ = (((int)cnp[5] - 48) * 10) + (int)cnp[6] - 48;

        out << " -- Persoana #" << nr << " --" << endl;

        if (strlen(cnp) != 13)
        {
            out << "CNP Invalid";
            return 0;
        }

        out << "CNP: " << cnp << endl;
        switch (S)
        {
        case 5:
            out << "Sex: Masculin" << endl
                << "Data de nastere: 20";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (2000 + AA);
                }
                else
                {
                    varsta = (an - (2000 + AA)) - 1;
                }
            else
            {
                varsta = (an - (2000 + AA) - 1);
            }
            break;
        case 6:
            out << "Sex: Feminin" << endl
                << "Data de nastere: 20";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (2000 + AA);
                }
                else
                {
                    varsta = (an - (2000 + AA)) - 1;
                }
            else
            {
                varsta = (an - (2000 + AA) - 1);
            }
            break;
        case 1:
            out << "Sex: Masculin" << endl
                << "Data de nastere: 19";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (1900 + AA);
                }
                else
                {
                    varsta = (an - (1900 + AA)) - 1;
                }
            else
            {
                varsta = (an - (1900 + AA) - 1);
            }
            break;
        case 2:
            out << "Sex: Feminin" << endl
                << "Data de nastere: 19";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (1900 + AA);
                }
                else
                {
                    varsta = (an - (1900 + AA)) - 1;
                }
            else
            {
                varsta = (an - (1900 + AA) - 1);
            }
            break;
        case 3:
            out << "Sex: Masculin" << endl
                << "Data de nastere: 18";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (1800 + AA);
                }
                else
                {
                    varsta = (an - (1800 + AA)) - 1;
                }
            else
            {
                varsta = (an - (1800 + AA) - 1);
            }
            break;
        case 4:
            out << "Sex: Feminin" << endl
                << "Data de nastere: 18";
            if (LL >= luna)
                if (ZZ >= zi)
                {
                    varsta = an - (1800 + AA);
                }
                else
                {
                    varsta = (an - (1800 + AA)) - 1;
                }
            else
            {
                varsta = (an - (1800 + AA) - 1);
            }
            break;
        case 7:
            out << "Sex: Masculin"; // wip
            break;
        case 8:
            out << "Sex: Feminin"; // wip
            break;
        case 9:
            out << "Sex: N/A"; // wip
            break;
        }

        if (AA < 10)
            out << "0";
        out << AA << "/";

        if (LL < 10)
            out << "0";
        out << LL << "/";

        if (ZZ < 10)
            out << "0";
        out << ZZ << endl;

        out << "Varsta: " << varsta;

        out << endl
            << " -----------------"
            << endl;
        nr++;
    }
}