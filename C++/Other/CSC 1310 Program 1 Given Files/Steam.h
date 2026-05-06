#ifndef STEAM_H
#define STEAM_H

#include <string>
#include <ostream>
using namespace std;

class Steam 
{
	private:
		bool earlyAccess;
		double price;
		string steamURL;
		double avgPlaytime;
		string reviewScore;

	public:
		Steam(){}
	
		//Constructor
		Steam(bool earlyAccess, double price, string steamURL, double avgPlaytime, string reviewScore) {
			this->earlyAccess = earlyAccess;
			this->price = price;
			this->steamURL = steamURL;
			this->avgPlaytime = avgPlaytime;
			this->reviewScore = reviewScore;
		}			

		// Mutators
		//ARE THERE ANY MUTATORS MISSING?
		
		void setEarlyAccess(bool earlyAccess) { 
			this->earlyAccess = earlyAccess; 
		}
		void setPrice(double price) { 
			this->price = price; 
		}
		void setSteamURL(string steamURL) { 
			this->steamURL = steamURL; 
		}
		void setAvgPlaytime(double avgPlaytime) { 
			this->avgPlaytime = avgPlaytime; 
		}

		// Accessors
		//ARE THERE ANY ACCESSORS MISSING?
		
		bool getEarlyAccess() const { 
			return earlyAccess; 
		}
		double getPrice() const { 
			return price; 
		}
		string getSteamURL() const { 
			return steamURL; 
		}
		double getAvgPlaytime() const { 
			return avgPlaytime; 
		}


		// Overloaded operator<<
		//YOU WILL NEED TO WRITE THIS FUNCTION FOR THE PROGRAM TO WORK!!
		
		//overloaded assignment operator
		Steam& operator=(const Steam& other) {
			if (this == &other) {
				// Check for self-assignment
				return *this;
			}

			// Copy data members from the source object
			earlyAccess = other.earlyAccess;
			price = other.price;
			steamURL = other.steamURL;
			avgPlaytime = other.avgPlaytime;
			reviewScore = other.reviewScore;

			return *this;
		}
};

#endif
