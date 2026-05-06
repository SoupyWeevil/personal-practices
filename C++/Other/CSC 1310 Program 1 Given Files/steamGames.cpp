/*
	comment block should be here
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include "Game.h"
#include "Genre.h"
#include "Steam.h"

using namespace std;

// Function prototypes
void readGamesFromFile(vector<Game>& games);
Genre findGenreInFile(string genreName);
void printGenre(const vector<Game>& games);
void addGame(vector<Game>& games);
void deleteGame(vector<Game>& games);
void saveGamesToFile(const std::vector<Game>& games);

int main() 
{
	//variable definitions
    vector<Game> games;
	int choice;
	char response;
	int count;//used to help in printing out the games to the screen
	
	cout << setprecision(2) << fixed << showpoint;

	cout << "\n\n**********STEAM GAME DATABASE **********";
	
	//Read all the games from games-list.txt
	readGamesFromFile(games);	
	
	//**********************************START MAIN GAME***************************
    do 
    {
		cout << "\n\nSELECT FROM THE FOLLOWING CHOICES:\n";
        cout << "1. Print all games\n";
        cout << "2. Print games in a particular genre\n";
        cout << "3. Add a new game\n";
        cout << "4. Delete a game\n";
        cout << "5. Exit\n";
        cout << "CHOOSE 1-5: ";
        cin >> choice;

		//validate user input
		while(choice < 1 || choice >5)
		{
			cout << "CHOOSE 1-5: ";
			cin >> choice;
		}
		
        switch (choice) 
        {
            case 1: //print all games
				cout << endl;
				count = 1;
                for (const auto& game : games) {
                    cout << "********************  GAME " << count;
					cout << "  ********************\n";
					cout << game;
					cout << endl << endl;
					count++;
                }
                break;

            case 2: //print games in a specific genre
                printGenre(games);
                break;

            case 3: //add a game
                addGame(games);
                break;

            case 4: //delete a game
                deleteGame(games);
                break;

            case 5:
				cout << "\nDo you want to save the updated list of games to games-list.txt? (y/n) ";
				cin >> response;
				//HOW SHOULD response BE VALIDATED to ensure user entered y or n?
				
				if(tolower(response) == 'y')
					saveGamesToFile(games);
                cout << "Exiting program." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

/*******************************************************************************
	FUNCTION: readGamesFromFile()
	PURPOSE: to read in all the game data from games-list.txt and create the
	Game objects in the vector that was sent to this function
********************************************************************************/
void readGamesFromFile(vector<Game>& games)
{
	ifstream inputFile("games-list.txt");
	Genre tempGenre;
    string line;
    
	int pos = 0;
	int count = 1;
	
	//temporary variables to help read in data from the file
	string token;
	string name, publisherClass, publishers, developers, genreName, genreDescription, steamURL, reviewScore;
	double steamPrice, avgPlaytime;
	bool earlyAccess;
    
	
	cout << "\n\nFirst, adding all the games from games-list.txt.\n\n";
	if (!inputFile.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    while (getline(inputFile, line)) {
		//create temporary Game object
		Game tempGame;
		
		//cout << "GAME " << count << endl;
        // Manually parse the line separated by commas and set Game attributes
        
        // Extract name & set name attribute
        pos = line.find(',');
        tempGame.setName(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract copiesSold & set attribute
        pos = line.find(',');
        tempGame.setCopiesSold(stoll(line.substr(0, pos)));
        line.erase(0, pos + 1);

        // Extract revenue
        pos = line.find(',');
        tempGame.setRevenue(stod(line.substr(0, pos)));
        line.erase(0, pos + 1);

        // Extract publisherClass
        pos = line.find(',');
        tempGame.setPublisherClass(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract publishers
        pos = line.find(',');
        tempGame.setPublishers(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract developers
        pos = line.find(',');
        tempGame.setDevelopers(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract genres
		line.erase(0,1); //get rid of beginning {
		int pos2 = line.find('}');
		pos = line.find(',');
		while(pos <= pos2 || pos == pos2+1)
		{
			if(pos != pos2+1)
				genreName=line.substr(0,pos);
			else
				genreName=line.substr(0,pos2);

			//find Genre in game_genres.txt file & create Genre object
			tempGenre = findGenreInFile(genreName);

			//now add the Genre to the Game
			tempGame.setGenreElement(tempGenre);

			line.erase(0, pos + 1);
			pos = line.find(',');
			pos2 = line.find('}');
		}

        // Extract earlyAccess
        pos = line.find(',');
        earlyAccess = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract steamPrice
        pos = line.find(',');
        steamPrice = stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Extract steamURL
        pos = line.find(',');
        steamURL = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Extract avgPlaytime
		pos = line.find(',');
		avgPlaytime = stod(line.substr(0,pos));
		line.erase(0, pos + 1);
		
		// Extract review score
		reviewScore = line;

        // Create Genre and Steam objects
        //Genre genre(genreName, genreDescription);
        Steam tmpSteam(earlyAccess, steamPrice, steamURL, avgPlaytime,reviewScore);

        // Add steam object to the game object
		tempGame.setSteam(tmpSteam);
		
		//Add this Game object to the vector
        games.push_back(tempGame);
		count++;
    }
	cout << count-1 << " games were added from games-list.txt.\n";
    inputFile.close();
}

/*******************************************************************************
	FUNCTION: findGenreInFile()
	PURPOSE: to see if the genre sent to this function can be found
	in the text file game-genres.txt. If so, pull the description from
	the text file and then create a Genre object with the name and description.
	If the genre can't be found in the file, then add the genre to the file
	and get the description from the user.
********************************************************************************/
Genre findGenreInFile(string genreName)
{
	string strGenre, strDesc;
	bool foundGenre = false;
	ifstream inputFile("game-genres.txt");
	Genre tempGenre;
	
	if(genreName.back() == '}')
		genreName.pop_back();
	
	if(!inputFile.is_open())
	{
		cout << "Unable to open game genres file.\n\n";
	}
	else {
	
		while(getline(inputFile,strGenre,'*')){
			if(genreName == strGenre) {
				getline(inputFile,strDesc);
				tempGenre.setName(strGenre);
				tempGenre.setDescription(strDesc);
				foundGenre = true;
				break;
			}
			else
				getline(inputFile,strDesc); //to throw it out
		}
		inputFile.close();
	}
	if(!foundGenre) //either file existed and could't find or file didnt exist.
	{
		ofstream outFile("game-genres.txt", ios::app);
		outFile << endl << genreName << "*";
		cout << "Give me a description of the genre " << genreName << ", please.\nDESCRIPTION: ";
		getline(cin,strDesc);
		outFile << strDesc;
		tempGenre.setName(genreName);
		tempGenre.setDescription(strDesc);
		outFile.close();
	}
	return tempGenre;
}

/*******************************************************************************
	FUNCTION: 	printGenre()
	PURPOSE:	Allow the user to view the genres and then select 
				the genre for which they want to view the games
				Once they select the genre, print the games in that
				genre.
				
********************************************************************************/
void printGenre(const vector<Game>& games) {
	vector<Genre> genreVector;
	string genreName, selectedGenre;
	unsigned int choice;
	bool found;
	
    if (games.empty()) {
        cout << "No games available." << endl;
        return;
    }

    // Extract unique genres
    vector<string> uniqueGenres;
    for (const auto& game : games) {
        genreVector = game.getGenres();
		for(const auto& genre : genreVector) {
			genreName = genre.getName();
			if (find(uniqueGenres.begin(), uniqueGenres.end(), genreName) == uniqueGenres.end()) {
				uniqueGenres.push_back(genreName);
			}
		}
    }

    // Print genres
    cout << "\n\nAvailable genres:\n";
	unsigned int i;
    for (i = 0; i < uniqueGenres.size(); ++i) {
        cout << i + 1 << ". " << uniqueGenres[i] << endl;
    }

    // Get user's choice
    cout << "Select a genre by number: ";
    cin >> choice;

    while(choice < 1 || choice > i) {
		cout << "That isn't a valid choice. Choose 1 through " << i << ": ";
		cin >> choice;
	}

    selectedGenre = uniqueGenres[choice - 1];

    // Print games in the selected genre
    found = false;
    cout << "\nGames in genre \"" << selectedGenre << "\":\n";
	int count = 1;
    for (const auto& game : games) {
		genreVector = game.getGenres();
		for(const auto& genre : genreVector) {
			genreName = genre.getName();
			if (genreName == selectedGenre) {
				cout << "********************  GAME " << count;
				cout << "  ********************\n";
				cout << game << endl;
				cout << endl << endl;
				count++;
				found = true;
			}
		}
    }

    if (!found) {
        cout << "No games found in this genre." << endl;
    }
}

/***************************************************************************
	FUNCTION: 	addGame()
	PURPOSE:	Allow the user to add a new game, which will
				add a new game object to the vector
				
****************************************************************************/
void addGame(vector<Game>& games) {
    string name, publisherClass, publishers, developers, steamURL, reviewScore;
	string genreName, currentGenre;
    long long copiesSold;
    double revenue, steamPrice, avgPlaytime;
    bool earlyAccess;
	Game tempGame;
	Genre tempGenre;

    cout << "\n\nEnter game details of the game you wish to add.\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
	tempGame.setName(name);
	
    cout << "Copies Sold: ";
    cin >> copiesSold;
	tempGame.setCopiesSold(copiesSold);
	
    cout << "Revenue: ";
    cin >> revenue;
	tempGame.setRevenue(revenue);
	
    cout << "Publisher Class: ";
    cin.ignore();
    getline(cin, publisherClass);
	tempGame.setPublisherClass(publisherClass);
	
    cout << "Publishers: ";
    getline(cin, publishers);
	tempGame.setPublishers(publishers);
	
    cout << "Developers: ";
    getline(cin, developers);
	tempGame.setDevelopers(developers);
	
    cout << "Genres (List all separated by a comma. Ex:Adventure, Action, Simulation): ";
    getline(cin, genreName);
	
	//find Genre in game-genres.txt file & create Genre object
	//this loop works for the list of genres up until the last one
	int pos;
	while(genreName.find(',') != string::npos)
	{
		pos = genreName.find(',');
		currentGenre = genreName.substr(0,pos);
		
		// Trim leading/trailing spaces and ensure it's not empty
		currentGenre.erase(0, currentGenre.find_first_not_of(' '));
		currentGenre.erase(currentGenre.find_last_not_of(' ') + 1);
		
		if(!currentGenre.empty())
		{
			//find Genre in game-genres.txt file & create Genre object
			tempGenre = findGenreInFile(currentGenre);
			//cout << "Created " << tempGenre.getName() << "!\n";
			//now add the Genre to the Game
			tempGame.setGenreElement(tempGenre);
		}
		genreName.erase(0, pos + 1);
	}


	//first, trim leading/trailing spaces and ensure it's not empty
	genreName.erase(0, genreName.find_first_not_of(' '));
	genreName.erase(genreName.find_last_not_of(' ') + 1);
	//process the last genre (or the only one if no commas exist)
	if (!genreName.empty())
	{
		tempGenre = findGenreInFile(genreName);
		//cout << "Created " << tempGenre.getName() << "!\n";
		tempGame.setGenreElement(tempGenre);
	}
	
    cout << "Early Access (1 for Yes, 0 for No): ";
    cin >> earlyAccess;
	
    cout << "Steam Price: ";
    cin >> steamPrice;
    cout << "Steam URL: ";
    cin.ignore();
    getline(cin, steamURL);
    cout << "Average Playtime (hours): ";
    cin >> avgPlaytime;
	cin.ignore();
	cout << "Steam Review Score (65%): ";
	getline(cin,reviewScore);

	//create the Steam object
    Steam steam(earlyAccess, steamPrice, steamURL, avgPlaytime, reviewScore);
    
	//add the Steam object to the Game object
	tempGame.setSteam(steam);
	
	//add the Game object to the game vector
	games.push_back(tempGame);

    cout << "\n\nGame added successfully!" << endl;
}

/**********************************************************************
	FUNCTION: 	deleteGame()
	Purpose:	Allow the user to view the names of all the games,
				and then select the number of the game that they
				want to delete, which is then removed from the vector.
				The number of elements in the vector should be reduced.
				
***********************************************************************/
void deleteGame(vector<Game>& games) {
    unsigned int choice;
	
    if (games.empty()) {
        cout << "No games to delete." << endl;
        return;
    }

    cout << "\nSelect a game to delete:\n";
	unsigned int i;
    for (i = 0; i < games.size(); ++i) {
        cout << i + 1 << ". " << games[i].getName() << endl;
    }

    cout << "Enter the number of the game to delete: ";
    cin >> choice;

    while(choice < 1 || choice > i)
	{
		cout << "That isn't a valid choice. Choose 1 through " << i << ": ";
		cin >> choice;
	}

    games.erase(games.begin() + (choice - 1));
    cout << "\n\nGame deleted successfully!" << endl;
}


/*******************************************************************************
	FUNCTION: 	saveGamesToFile()
	PURPOSE: 	to save all the games from the Game vector to the games-list.txt
				text file
********************************************************************************/
void saveGamesToFile(const std::vector<Game>& games) {
    ofstream outputFile("games-list.txt");
	Steam tempSteam;
	vector<Genre> tempGenres;

    if (!outputFile.is_open()) {
        cout << "Error: Could not open file for writing." << endl;
        return;
    }

    for (const auto& game : games) {
        // Write game details in the specified format
        outputFile << game.getName() << ",";
        outputFile << game.getCopiesSold() << ",";
        outputFile << game.getRevenue() << ",";
        outputFile << game.getPublisherClass() << ",";
        outputFile << game.getPublishers() << ",";
        outputFile << game.getDevelopers() << ",{";

        // Write all genres in the game
        tempGenres = game.getGenres();
        for (unsigned int i = 0; i < tempGenres.size(); ++i) {
            outputFile << tempGenres[i].getName();
            if (i != tempGenres.size() - 1) { // Add comma except after the last genre
                outputFile << ",";
            }
        }

        outputFile << "},";

        // Write Steam details
        tempSteam = game.getSteam();
        outputFile << tempSteam.getEarlyAccess() << ",";
        outputFile << tempSteam.getPrice() << ",";
        outputFile << tempSteam.getSteamURL() << ",";
        outputFile << tempSteam.getAvgPlaytime() << ",";
        outputFile << tempSteam.getReviewScore();

        // End the current line
        outputFile << endl;
    }

    outputFile.close();
    cout << "Games successfully saved to games-list.txt." << endl;
}







