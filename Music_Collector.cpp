#include <iostream>
#include <string>
// #include <Windows.h>

using namespace std;

struct Album
{
    string albumName;
    string artistName;
    string genre;
    int releaseYear;
    int numberOfTracks;
    int personalRating;
    int albumIndex;
};
struct Album Albums[256]; // 0-254 album spots, Albums[255] to be used as an auxiliary for reordering library

bool showHelp = true, showLibrary = false, showAlbumDetails = false, modifyAnAlbum = false, deleteAnAlbum = false, queuedLibrarySort = false;
int numberOfAlbums = 6; // nu uita sa pui 0 la numberOfAlbums cand stergi albumele de debugging

void LibrarySummary();
void SortLibrary();
void AddAlbum();
void ModifyAlbum(int index);
void DeleteAlbum(int index);
void GetAlbumDetails(int index);

int main()
{
    Albums[0].albumName = "Starboy (Deluxe)";
    Albums[0].artistName = "The Weeknd";
    Albums[0].genre = "Soul, Funk, R&B";
    Albums[0].releaseYear = 2023;
    Albums[0].numberOfTracks = 21;
    Albums[0].personalRating = 7;
    Albums[0].albumIndex = 1;

    Albums[1].albumName = "Inapoi La Viata";
    Albums[1].artistName = "Oscar";
    Albums[1].genre = "Rap";
    Albums[1].releaseYear = 2022;
    Albums[1].numberOfTracks = 15;
    Albums[1].personalRating = 9;
    Albums[1].albumIndex = 2;

    Albums[2].albumName = "Intr-o buna zi o sa fim bine";
    Albums[2].artistName = "Calinacho";
    Albums[2].genre = "Rap";
    Albums[2].releaseYear = 2022;
    Albums[2].numberOfTracks = 11;
    Albums[2].personalRating = 10;
    Albums[2].albumIndex = 3;

    Albums[3].albumName = "Stefan III (Deluxe Edition)";
    Albums[3].artistName = "Oscar";
    Albums[3].genre = "Divers";
    Albums[3].releaseYear = 2023;
    Albums[3].numberOfTracks = 12;
    Albums[3].personalRating = 7;
    Albums[3].albumIndex = 4;

    Albums[4].albumName = "Femei Bautura Necaz";
    Albums[4].artistName = "Calinacho";
    Albums[4].genre = "Soul, Funk, R&B";
    Albums[4].releaseYear = 2021;
    Albums[4].numberOfTracks = 13;
    Albums[4].personalRating = 9;
    Albums[4].albumIndex = 5;

    Albums[5].albumName = "Dawn FM";
    Albums[5].artistName = "The Weeknd";
    Albums[5].genre = "Soul, Funk, R&B";
    Albums[5].releaseYear = 2022;
    Albums[5].numberOfTracks = 16;
    Albums[5].personalRating = 8;
    Albums[5].albumIndex = 6; // albume placeholder pentru debugging

    while (true)
    {
        char command;

        if (showHelp)
        {
            system("clear");
            cout << "Enter the highlighted character in the brackets from the following list to execute a command (case-sensitive):\n"
                 << endl
                 << "Show (L)ibrary" << endl
                 << "(A)dd an album" << endl
                 << "(M)odify an album" << endl
                 << "(D)elete an album" << endl
                 << "Show (a)lbum details" << endl
                 << "(Q)uit the program"
                 << endl
                 << endl;
            showHelp = false;
        }

        if (showLibrary)
        {
            LibrarySummary();
            showLibrary = false;
        }

        /*if (queuedLibrarySort)
        {
            system("clear");

            cout << "Choose how you want to sort the library: " << endl
                 << "1. Smart" << endl
                 << "2. By rating" << endl
                 << "Command: ";
            cin >> method;
            SortLibrary(method);
            queuedLibrarySort = false;
        }*/

        if (modifyAnAlbum)
        {
            system("clear");

            int index;
            cout << "Enter album number: ";
            cin >> index;
            if ((index - 1) < numberOfAlbums)
            {
                ModifyAlbum(index);
            }
            else
            {
                cout << "Album entry doesn't exist." << endl;
            }
            modifyAnAlbum = false;
        }

        if (deleteAnAlbum)
        {
            system("clear");

            int index;
            char confirmation;
            cout << "Enter album number: ";
            cin >> index;
            if ((index - 1) < numberOfAlbums)
            {
                cout << "Are you sure you want to delete \"" << Albums[index - 1].albumName << " - " << Albums[index - 1].artistName << "\" (Y/N): ";
                cin >> confirmation;
                int confirmationAscii = confirmation;
                if (confirmationAscii == 89)
                    DeleteAlbum(index);
                deleteAnAlbum = false;

                system("clear");
            }
            else
            {
                cout << "Album entry doesn't exist." << endl;
            }
        }

        if (showAlbumDetails)
        {
            system("clear");

            int index;
            cout << "Enter album number: ";
            cin >> index;
            GetAlbumDetails(index);
            showAlbumDetails = false;
        }

        cout << "Music Collector v0.9 - Enter command (enter \"h\" for help): ";
        cin >> command;
        int commandAscii = command;

        switch (commandAscii)
        {
        case 65: // A
            AddAlbum();
            break;
        case 83: // S
            SortLibrary();
            system("clear");
            break;
        case 77: // M
            modifyAnAlbum = true;
            break;
        case 68: // D
            deleteAnAlbum = true;
            break;
        case 76: // L
            showLibrary = true;
            break;
        case 97: // a
            showAlbumDetails = true;
            break;
        case 104: // h
            showHelp = true;
            break;
        case 81: // Q
            return 0;
        default:
            system("clear");
            cout << "Command not valid." << endl;
            break;
        }
    }
}

void LibrarySummary()
{
    system("clear");
    for (int i = 0; i < numberOfAlbums; i++)
    {
        cout << "#" << Albums[i].albumIndex << ": " << Albums[i].albumName << " - " << Albums[i].artistName << endl;
    }

    if (numberOfAlbums > 0)
    {
        cout << "------------------------------\nTotal number of albums: " << numberOfAlbums << endl
             << endl;
    }
    else
    {
        cout << "No albums in library\n"
             << endl;
    }
}

void SortLibrary()
{
    for (int i = 0; i < numberOfAlbums; i++)
    {
        for (int j = i + 1; j < numberOfAlbums; j++)
        {
            if (Albums[i].artistName[0] > Albums[j].artistName[0])
            {
                Albums[255].albumName = Albums[i].albumName;
                Albums[255].artistName = Albums[i].artistName;
                Albums[255].genre = Albums[i].genre;
                Albums[255].releaseYear = Albums[i].releaseYear;
                Albums[255].numberOfTracks = Albums[i].numberOfTracks;
                Albums[255].personalRating = Albums[i].personalRating;

                Albums[i].albumName = Albums[j].albumName;
                Albums[i].artistName = Albums[j].artistName;
                Albums[i].genre = Albums[j].genre;
                Albums[i].releaseYear = Albums[j].releaseYear;
                Albums[i].numberOfTracks = Albums[j].numberOfTracks;
                Albums[i].personalRating = Albums[j].personalRating;

                Albums[j].albumName = Albums[255].albumName;
                Albums[j].artistName = Albums[255].artistName;
                Albums[j].genre = Albums[255].genre;
                Albums[j].releaseYear = Albums[255].releaseYear;
                Albums[j].numberOfTracks = Albums[255].numberOfTracks;
                Albums[j].personalRating = Albums[255].personalRating;
            }
        }
    }

    for (int i = 0; i < numberOfAlbums; i++)
    {
        for (int j = i + 1; j < numberOfAlbums; j++)
        {
            if (Albums[i].releaseYear < Albums[j].releaseYear && Albums[i].artistName == Albums[j].artistName)
            {
                Albums[255].albumName = Albums[i].albumName;
                Albums[255].artistName = Albums[i].artistName;
                Albums[255].genre = Albums[i].genre;
                Albums[255].releaseYear = Albums[i].releaseYear;
                Albums[255].numberOfTracks = Albums[i].numberOfTracks;
                Albums[255].personalRating = Albums[i].personalRating;

                Albums[i].albumName = Albums[j].albumName;
                Albums[i].artistName = Albums[j].artistName;
                Albums[i].genre = Albums[j].genre;
                Albums[i].releaseYear = Albums[j].releaseYear;
                Albums[i].numberOfTracks = Albums[j].numberOfTracks;
                Albums[i].personalRating = Albums[j].personalRating;

                Albums[j].albumName = Albums[255].albumName;
                Albums[j].artistName = Albums[255].artistName;
                Albums[j].genre = Albums[255].genre;
                Albums[j].releaseYear = Albums[255].releaseYear;
                Albums[j].numberOfTracks = Albums[255].numberOfTracks;
                Albums[j].personalRating = Albums[255].personalRating;
            }
        }
    }
}

void AddAlbum()
{
    Albums[numberOfAlbums].albumIndex = numberOfAlbums + 1;
    system("clear");

    cout << "Enter album name: ";
    getline(cin, Albums[numberOfAlbums].albumName);
    getline(cin, Albums[numberOfAlbums].albumName);

    cout << "Enter artist name: ";
    getline(cin, Albums[numberOfAlbums].artistName);

    cout << "Enter album genre: ";
    getline(cin, Albums[numberOfAlbums].genre);

    cout << "Enter album release year: ";
    cin >> Albums[numberOfAlbums].releaseYear;

    cout << "Enter album number of tracks: ";
    cin >> Albums[numberOfAlbums].numberOfTracks;

    cout << "Enter album rating: ";
    cin >> Albums[numberOfAlbums].personalRating;

    numberOfAlbums++;

    SortLibrary();
    system("clear");
}

void ModifyAlbum(int index)
{
    index -= 1;

    system("clear");

    string sinput;
    int iinput;

    cout << "Current album name: " << Albums[index].albumName << endl;
    cout << "Enter album name (Leave blank to not modify): ";
    getline(cin, sinput);
    getline(cin, sinput);
    if (!sinput.empty())
        Albums[index].albumName = sinput;

    cout << "Current artist name: " << Albums[index].artistName << endl;
    cout << "Enter artist name (Leave blank to not modify): ";
    getline(cin, sinput);
    if (!sinput.empty())
        Albums[index].artistName = sinput;

    cout << "Current album genre: " << Albums[index].genre << endl;
    cout << "Enter album genre (Leave blank to not modify): ";
    getline(cin, sinput);
    if (!sinput.empty())
        Albums[index].genre = sinput;

    cout << "Current album release year: " << Albums[index].releaseYear << endl;
    cout << "Enter album release year (Enter 0 to not modify): ";
    cin >> iinput;
    if (iinput != 0)
        Albums[index].releaseYear = iinput;

    cout << "Current number of tracks: " << Albums[index].numberOfTracks << endl;
    cout << "Enter number of tracks (Enter 0 to not modify): ";
    cin >> iinput;
    if (iinput != 0)
        Albums[index].numberOfTracks = iinput;

    cout << "Current rating: " << Albums[index].personalRating << endl;
    cout << "Enter new rating (Enter 0 to not modify): ";
    cin >> iinput;
    if (iinput != 0)
        Albums[index].personalRating = iinput;

    SortLibrary();
    system("clear");
}

void DeleteAlbum(int index)
{
    index -= 1;

    for (int i = index; i < numberOfAlbums; i++)
    {
        Albums[i].albumName = Albums[i + 1].albumName;
        Albums[i].artistName = Albums[i + 1].artistName;
        Albums[i].genre = Albums[i + 1].genre;
        Albums[i].releaseYear = Albums[i + 1].releaseYear;
        Albums[i].numberOfTracks = Albums[i + 1].numberOfTracks;
        Albums[i].personalRating = Albums[i + 1].personalRating;
    }

    numberOfAlbums--;
}

void GetAlbumDetails(int index)
{
    if (index <= numberOfAlbums)
    {
        index -= 1;
        system("clear");

        cout << "Album #" << Albums[index].albumIndex << endl
             << "   Name: " << Albums[index].albumName << endl
             << "   Artist: " << Albums[index].artistName << endl
             << "   Genre: " << Albums[index].genre << endl
             << "   Release year: " << Albums[index].releaseYear << endl
             << "   Number of tracks: " << Albums[index].numberOfTracks << endl
             << "   Rating: " << Albums[index].personalRating << endl
             << endl;
    }
    else
    {
        cout << "Album entry doesn't exist." << endl;
    }
}