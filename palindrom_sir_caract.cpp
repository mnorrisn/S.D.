#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    bool palindrom = true;
    char ciar[101];
    
    cin.getline(ciar, 101);
    int i, j = strlen(ciar)-1;
    
    for (i = 0; i <= j; i++)
    {
        if(ciar[i]==' ') i++;
        if(ciar[j]==' ') j--;
        if (ciar[i] != ciar[j])
        {
            palindrom = false;
            break;
        }
        j--;
    }

    if (palindrom)
        cout << "Char-ul \"" << ciar << "\" este palindrom!";
    else
        cout << "Char-ul \"" << ciar << "\" nu este palindrom!";

    return 0;
}
