/************************************************
* Name:			Grace Brown						*
* FileName:		Lab4.cpp	             		*
* Last Edited:	19 Feb 2026						*
* Purpose:		Engage in a riveting 			*
*				adventure at Devin's Dentistry	*
*************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>    //Using for toUpper function to make logic and relational comparisons easier (https://docs.vultr.com/cpp/standard-library/cctype/toupper)
using namespace std;

int main(){
	
	string border(50, '-'); // Creates a long border to divide sections				
	char newPatient, insurance, nameVal, finalVal, repeat; // all of these are for Y/N Validation
	string fName, lName, fullName; //holds patient name
	int roomNumber, age, incompetency, choice, damage; //holds values that affect health and dialogue
	bool life; // Determines dialogue for end of game trivia -- true = Alive ... false  = Dead
	
	srand(time(0));								//Generates random seed for random int
	roomNumber = rand() % 21 + 100; 			// Generates a random room number from 100-120
	incompetency = rand() % 11 + 0;				// Generates a random number determining how stupid Devin will be (Higher chance for tooth pulling)
	
	cout << border << endl;
	// !!!!! WHERE I LEARNED THE RAW STRING LITERAL [https://stackoverflow.com/questions/37765925/ascii-art-in-c] !!!!!!!!!!!
	// This is the Title of the game
	cout << R"(
▗▄▄▄ ▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖    ▗▄▄▄ ▗▄▄▄▖▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▄▖  
▐▌  █▐▌   ▐▛▚▖▐▌  █    █  ▐▌     █      ▐▌  █▐▌   ▐▌  ▐▌  █  ▐▛▚▖▐▌▐▌     				
▐▌  █▐▛▀▀▘▐▌ ▝▜▌  █    █   ▝▀▚▖  █      ▐▌  █▐▛▀▀▘▐▌  ▐▌  █  ▐▌ ▝▜▌ ▝▀▚▖  
▐▙▄▄▀▐▙▄▄▖▐▌  ▐▌  █  ▗▄█▄▖▗▄▄▞▘  █      ▐▙▄▄▀▐▙▄▄▖ ▝▚▞▘ ▗▄█▄▖▐▌  ▐▌▗▄▄▞▘  
                                                                                                                                                                                                                             
 ▗▄▖ ▗▄▄▖  ▗▄▄▖▗▖ ▗▖▗▄▄▖ ▗▄▄▄     ▗▄▄▖ ▗▄▄▖  ▗▄▖  ▗▄▄▖▗▄▄▄▖▗▄▄▄▖ ▗▄▄▖▗▄▄▄▖
▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌▐▌ ▐▌▐▌  █    ▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌▐▌     █    █  ▐▌   ▐▌   
▐▛▀▜▌▐▛▀▚▖ ▝▀▚▖▐▌ ▐▌▐▛▀▚▖▐▌  █    ▐▛▀▘ ▐▛▀▚▖▐▛▀▜▌▐▌     █    █  ▐▌   ▐▛▀▀▘
▐▌ ▐▌▐▙▄▞▘▗▄▄▞▘▝▚▄▞▘▐▌ ▐▌▐▙▄▄▀    ▐▌   ▐▌ ▐▌▐▌ ▐▌▝▚▄▄▖  █  ▗▄█▄▖▝▚▄▄▖▐▙▄▄▖

)";
	cout << border << endl;
	
	cout << "\nNurse: Welcome to Dentist Devin's!"
		 << "\nNurse: I hope you have your insurance ready and a living will!"
		 << "\n ..."
		 << "\nNurse: Living will? I'm just kidding! Haha! \n"
		 << "\n[PRESS ENTER TO CONTINUE]";
	cin.ignore(100, '\n');								/* Allows user to press enter to continue program 
													(https://stackoverflow.com/questions/903221/press-enter-to-continue)*/ // VERY IMPORTANT WILL BE USING A LOT
	cout << "\nNurse: First off, are you a new patient? \n"
		 << "[Y/N] --> ";
	cin >> newPatient;
	cin.ignore();
	newPatient = toupper(newPatient);				// uses <cctype> library to standardize capitalization ##### LEARNED FROM https://cplusplus.com/reference/cctype/
	
	while(newPatient != 'Y' && newPatient != 'N'){	// VALIDATION LOOP -- if the user doesnt choose y or n it repeats 
			cout << "\nNurse: Hey. DO YOU SPEAK ENGLISH?"
				 << "\nNurse: I asked ARE YOU A NEW PATIENT?"	
				 << "\nNurse: It's a yes or no question"
				 << "\nNurse: Lets try this again... ahem... Are you a new patient? \n"
				 << "[Y/N] --> ";
			cin >> newPatient;
			cin.ignore(); //Cleans cin buffer
			newPatient = toupper(newPatient);
		}
		
	if(newPatient == 'Y'){							// After validation loop one of these two choices play
		cout << "\nNurse: Oh perfect! Devin is going to LOVE you!\n"
			 << "Nurse: I'm going to have you fill out some new patient forms...\n";
	}else if(newPatient == 'N'){
		cout << "\nNurse: What? ReallY? I dont see returning patients here often.\n"
			 << "Nurse: oh... hmm... well...\n"
			 << "Nurse: Ok! Well here's the iPad, you know the drill.\n";
	}
	
	cout << "\n[You Take The Ipad]\n"
		 << "\n[PRESS ENTER TO CONTINUE]";
	cin.ignore(100, '\n'); //Allows for terminating line input without clogging buffer
	
	cout << "\n" << border << endl;					// Plays a special border based on if patient is new or returning
	cout << setw(10) << " " << "╒═════════════════════════╕\n";
	if(newPatient == 'Y')
		cout << setw(10) << " " << "|     NEW PATIENT FORM    |\n";
	else if(newPatient == 'N')
		cout << setw(10) << " " << "| RETURNING PATIENT FORM  |\n";
	cout << setw(10) << " " << "╘═════════════════════════╛\n";
	
	
	//The new patient and returning patient questions are EXACTLY THE SAME because im lazy
	// BEGINS MASSIVE DO-WHILE LOOP -- Allows user to REENTER ALL INFO if something is wrong
	do{	
		cout << "\n●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●\n";
		cout << "\n" << setw(13) << " " << "••●•• PART ONE ••●••\n"
			 << "\n1.) Enter Patient's First Name --> ";
		getline(cin, fName);
		cout << "\n2.) Enter Patient's Last Name --> ";
		getline(cin, lName);
	
		fullName = fName + " " + lName;					//Updates the fullName variable 
	
		do{
			cout << "\nYour current name is set as " << fullName << ".\n"
				 << "Is this correct?\n"
				 << "[Y/N] --> ";
			cin >> nameVal;									// Name validation character variable -- holds a Y or N for validation
			nameVal = toupper(nameVal);						// Converts character to Uppercase
			cin.ignore();
		
			while(nameVal != 'Y' && nameVal != 'N'){		//	First level validation for y/n user input 
				cout << "Please enter a 'Y' or 'N'!\n"
					 << "[Y/N] --> ";
				cin >> nameVal;
				nameVal = toupper(nameVal);
				cin.ignore();
			}
		
			if(nameVal == 'Y'){								// Displays fullname as entered
				cout << "\nYour name is " << fullName << ".\n";
			}else if(nameVal == 'N'){						// Allows user to reenter and update name variables
				cout << "\nPlease Re-enter your name."
					 << "\n1.) Enter Patient's First Name --> ";
				getline(cin, fName);
				cout << "\n2.) Enter Patients Last Name --> ";
				getline(cin, lName);
				fullName = fName + " " + lName;
			}
		}while(nameVal == 'N');								// REPEATS the while loop if 'N' is selected for multiple chances to tweak name
		
		cout << border << endl;
		cout << "\n" << setw(13) << " " << "••●•• PART TWO ••●••\n"
			 << "\n1.) Enter Patient's Age --> ";
		cin >> age;
		cin.ignore();
		
		/* https://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c
		USED FOR cin.fail() IDEA !!!!!!!!!!! 												*/ 
		while(cin.fail() || age < 0){			//input validation for integer input  -- SEE COMMENT ABOVE!!!!!!!!!!
			cin.clear();							// Erases the input 
			cin.ignore(50, '\n');					// Erases up to 50 characters until a newline 
			cout << "\nPlease enter a valid age!\n"	
				 << "Enter Patient's Age --> ";
			cin >> age;
			cin.ignore();
		}
		
		if(age >= 18){							// User input for insurance -- determines if Devin will be incompetent
			cout << "\nDoes the patient have insurance?\n"
				 << "[Y/N] --> ";
			cin >> insurance;
			cin.ignore();
		}else if(age >= 0 && age < 18){			// Changes the cout. No new features here
			cout << "\nDoes the patient's Guardian have insurance?\n"
				 << "[Y/N] --> ";
			cin >> insurance;
			cin.ignore();
		}
		insurance = toupper(insurance); 	// UNIFORMS CAPITILIZATION -- optimal for relational conditions
		
		while(insurance != 'Y' && insurance != 'N'){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nPlease enter a valid option!\n"
				 << "[Y/N] --> ";
			cin >> insurance;
			insurance = toupper(insurance);
		}
		
		if(insurance == 'Y'){				// LOWERS Devin's incompetency -- makes him LESS LIKELY to commit malpractice
			incompetency -= 2;
			
			if(incompetency < 0){			//failsafe for if his incompetency reaches a negative number
				incompetency = 0;
			}
		}else{
			incompetency += 4;				/* RAISES his incompetency. 
											He CHOOSES this on purpose because if the patient cant afford insurance, they cant afford to sue */
		}
		
		cout << "\n" << border << endl;		// DISPLAYS final user choices ... 
		cout << setw(10) << " " << "╒═════════════════════════╕\n"
			 << setw(10) << " " << "|      FINAL ANSWERS      |\n"
			 << setw(10) << " " << "╘═════════════════════════╛\n"
			 << "\n" << setw(13) << " " << "••●•• PART ONE ••●••\n"
			 << "Patient Name: " << fullName << endl;
		cout << "Patient Age : " << age << endl;
		cout << "Insurance   : " << insurance << endl;
			
		cout << "\nIs The Information Above CORRECT?\n"  //ALLOWS user to change info if N is chosen
			 << "[Y/N] --> ";
		cin >> finalVal;
		cin.ignore();
		finalVal = toupper(finalVal);
		
		while(finalVal != 'Y' && finalVal != 'N'){	// Validates user input again
			cout << "\nPlease select a valid option!\n"
			 	 << "[Y/N] --> ";
			 cin >> finalVal;
			 cin.ignore();
			 finalVal = toupper(finalVal);			// Standardizes capitalization 
		}
	}while(finalVal == 'N');						// THE WHILE CONDITION FOR THE MASSIVE DO-WHILE... allows user to reenter choices
	
	// MENU IS OVER!!!!!!
	cout << border << endl;
	cout << "\n[You Return The Ipad]\n"
		 << "\n[PRESS ENTER TO CONTINUE]";
	cin.ignore(100, '\n');
	
	cout << "\nNurse: Your room number is " << roomNumber << ". Follow me.\n";
	
	for(int i = 0 ; i < 3 ; i++){					// Just prints out 3 dots in a row. Breaks up text
		cout << ".\n";
	 }
	 
	cout << "[You walk into room " << roomNumber << "]\n"
	 	 << "\nNurse: Dentist Devin will be with you \n"
	 	 << "\n[Nurse Leaves]\n"
	 	 << "\n[PRESS ENTER TO CONTINUE]";
	 cin.ignore(100, '\n');
	
	do{												// BEGINS STAGE ONE OF THE GAME
		cout << "\n" << border << endl;
		cout << "\n[Dentist Devin walks into the room]\n"
			 << "\nDevin: Hello uhh.... " << fName << "? Or was it Carl... I dont know!"
			 << "\nDevin: Anyway! What brings you in today, Carl?\n"
			 << "\n╒════════════════════════════════╕"
			 << "\n|          CHOOSE ONE            |"
			 << "\n|--------------------------------|"
			 << "\n|[1] Toothache                   |"
			 << "\n|[2] Jaw Dislocation             |"
			 << "\n|[3] Tongue fell out             |"
			 << "\n╘════════════════════════════════╛\n"
			 <<"\n CHOICE --> ";
		cin >> choice;
		
		while(cin.fail() || !(choice >=1 && choice <= 3)){  // Validates user choice.. using cin.fail again to ensure int type
			cin.clear();
			cin.ignore(20, '\n');
			cout << "\nPlease select a valid choice!\n"
				 << "CHOICE --> ";
			cin >> choice;
		}
		cin.ignore(100, '\n'); 
		
		switch(choice){		// SWITCHES that have their own if-branches to create new gameplay scenarios
			case 1: // TOOTHACHE
				cout << "\nDevin: A toothache? Well thats stupid. Let me look.\n"
					 << "\n[Devin pries open your mouth]\n"
					 << "\nDevin: Hmm...\n";
					 
				cout << "\n[PRESS ENTER TO CONTINUE]\n";		
				cin.ignore(100, '\n');		// ALLOWS ENTER TO CONTINUE
				
				if(incompetency == 0){		// The competent dialogue 
					cout << "\nDevin: Oh! I see now... you have a cavity haha."
						 << "\nDevin: Looks pretty rough. Yeesh."
						 << "\n...\n"
						 << "\nDevin: I can fill it now if you'd like!\n";
				}else if(incompetency > 0 && incompetency <= 4){		// Slightly concerning dialogue if incompetency on the low end
					cout << "\nDevin: Okay so yeah I see theres like a smelly hole in your tooth."
						 << "\nDevin: I'm pretty sure its a cavity but let me go check..."
						 << "\n...\n"
						 << "\n[Devin leaves and returns with a medical textbook]\n"
						 << "\nDevin: Yeah ok so if you look at this page it says you have a cavity."
						 << "\nDevin: Do you want me to fix it or...\n";
				}else if (incompetency > 4 && incompetency < 10){		//Hippa violation if incompetency is between 5 and 9
					cout << "\nDevin: Um..."
						 << "\nDevin: Yeah I lowkey lost my appetite looking at this..."
						 << "\nDevin: Ugh... I'll be right back...\n"
						 << "\n...\n"
						 << "\n[Devin comes back 5 minutes later, wiping puke from his lips]"
						 << "\nDevin: Yeah so I told my mom about us and she said you probs have a cavity"
						 << "\nDevin: Do you want me to fix your cavity?\n";
				}else{													// Straight malpractice and murder if incompetency is 10+
					cout << "\nDevin: oh my god its cancer. We have to Kill You\n"
						 << "Devin: Should I go ahead and kill you or...";
				}
				
				
				cout << "\n╒════════════════════════════════╕"
					 << "\n|          CHOOSE ONE            |"
			 		 << "\n|--------------------------------|"
		       		 << "\n|[1] Yes                         |"
		 			 << "\n|[2] No, just leave it           |"            
			 		 << "\n╘════════════════════════════════╛\n"
			 		 <<"\n CHOICE --> ";
			 	cin >> choice;   										// Will decide dialogue options -- doesn't impact gameplay really
			 	
			 	while(cin.fail() || (choice < 1 || choice >2)){			//ANOTHER user validation with cin.fail()
			 		cin.clear();
			 		cin.ignore(20, '\n');
			 		cout << "\nPlease select a valid choice! --> ";
			 		cin >> choice;
			 	}
			 	cin.ignore(100, '\n');
			 	
			 	switch(choice){			// More branches of dialogue based on randomly generated incompetency FOR TOOTHACHE
			 		case 1:
			 			if(incompetency == 0){
							cout << "\nDevin: Okay\n";
							
						}else if(incompetency > 0 && incompetency <= 4){
							cout << "\nDevin: Sh-t... I was hoping you wouldn't say that..."
							 	 << "\nDevin: UGHHH okay okay...\n"
							 	 << "\n[Devin begins hyping himself up]\n"
							 	 << "\nDevin: Okay lets do this!!!";
							 	 
						}else if (incompetency > 4 && incompetency < 10){	//More hippa violations
							cout << "\nDevin: Let me call my mom real quick...\n"
								 << "\n[Devin calls his mom]\n";
							for(int i = 0 ; i < 3 ; i++){					// Just prints 3 dots 
								cout << ".\n";
							}
							cout << "\nDevin: Okay bye, I love you. mwah.\n"
								 << "\n[Devin hangs up]\n"
								 << "Devin: She said she believes in me so lets do it.";
						}else{
							cout << "\nDevin: Okay.\n";
						}
						
						cout << "\n[Devin begins the operation]\n";
			 			break;
			 			
			 		case 2: 												//Alternative dialogue -- leads to triva anyway
			 			cout << "\nDevin: Leave it? Oh.. well I dont care!"
			 				 << "\nDevin: I'll fix it anyway for you haha\n";
			 			break;
			 	}
			 	break;
			 	
			case 2: 														// JAW DISLOCATION DIALOGUES 
				cout << "\nDevin: Dislocated? Like on purpose? Haha just kidding"
					 << "\nDevin: ok lemme see for real. Ill see how bad it is...\n"
					 << "\n[Press Enter to Continue]";
				cin.ignore(100, '\n');
				
				if(incompetency == 0){
					cout << "\nDevin: Ohhh yep yeah thats dislocated alright"
						 << "\nDevin: I can pop that sucker back in if you'd like...\n";
						 
				}else if(incompetency > 0 && incompetency <= 4){
					cout << "\nDevin: yeeeouucchhhh I would NOT want to be you right now"
						 << "\nDevin: Haha that looks awful."
						 << "\nDevin: You look SO STUPID right now\n"
						 << "\n[Devin takes a picture and posts you on Reddit]\n"
						 << "\nDevin: Haha oh my god. Okay do you want me to fix it now?\n";
				
				}else if(incompetency > 4 && incompetency < 10){
					cout << "\n[Devin begins touching the top of your head]\n"
						 << "\nDevin: ... Huh? oh you said JAW? as in your chin place?"
						 << "\nDevin: haha what?? How did you dislocated THAT?\n"
						 << "\n ... \n" 
						 << "\nDevin: Don't answer that."
						 << "\nDevin: ... Anyway I can TRY to put it back if you want.\n";
					
				}else{
					cout << "\nDevin: Okay so this is unfixable and we have to kill you."
						 << "\nDevin: Do you want me to go ahead and get the morphine?\n";
				}
				
				cout << "\n╒════════════════════════════════╕"
					 << "\n|          CHOOSE ONE            |"
			 		 << "\n|--------------------------------|"
		       		 << "\n|[1] Yes                         |"
		 			 << "\n|[2] No, just leave it           |"            
			 		 << "\n╘════════════════════════════════╛\n"
			 		 <<"\n CHOICE --> ";
			 	cin >> choice;   // Will decide dialogue options -- doesn't impact gameplay really
			 	
			 	while(cin.fail() || (choice < 1 || choice >2)){			//ANOTHER user validation with cin.fail()
			 		cin.clear();
			 		cin.ignore(20, '\n');
			 		cout << "\nPlease select a valid choice! --> ";
			 		cin >> choice;
			 	}
			 	cin.ignore(100, '\n');
			 	
			 	switch(choice){
			 		case 1:
			 			if(incompetency == 0){ // IF BRANCHES ARE BASED ON RANDOM INCOMPETENCY LEVEL
							cout << "\nDevin: Alright! Sounds good... hope this goes well...\n";
						 
						}else if(incompetency > 0 && incompetency <= 4){
							cout << "\nDevin: oh thank GOD"
								 << "\nDevin: I was worried you WANTED to look like an idiot haha"
								 << "\nDevin: Okay lets start!!\n";
						 
						}else if(incompetency > 4 && incompetency < 10){
							cout << "\nDevin: uhmmm... uh... Maybe if i just...\n"
								 << "\n[Devin grabs your jaw and jerks it to the side]\n"
								 << "\n[You feel a horrible painful crack]"
								 << "\nDevin: Oh well thats a good start... lets keep going until youre not ugly!\n";
				
						}else{
							cout << "\nDevin: aw man. You were so chill though..."
								 << "\nDevin: Third patient this week I've had to put out of their misery...\n";
						}
			 			break;
			 			
			 		case 2:
			 			cout << "\nDevin: Huh? Leave it? With you looking like Habsburg royalty?"
			 			 	 << "\nDevin: Yeah thats not gonna happen. LETS BEGIN!!!\n";
			 			break;
			 	}
				
				break;
			
			case 3: // TONGUE FALLING OUT DIALOGUES 
				cout << "\nDevin: huh? Your tongue did what?"
					 << "\nDevin: Well let me have a looksie...\n"
					 << "\n[Press Enter to Continue]\n";
				cin.ignore(100, '\n');
				
				if(incompetency == 0){ // IF BRANCHES ARE BASED ON RANDOM INCOMPETENCY LEVEL
					cout << "\nDevin: oh! Yeah you right."
						 << "\nDevin: I can try to fix it if you want...\n";
						 
				}else if(incompetency > 0 && incompetency <= 4){
					cout << "\nDevin: Oh my god you weren't lying haha"
						 << "\nDevin: Uhmm haha oh this is so gross ewww"
						 << "\nDevin: Yeah imma show this to my friend oh my god\n"
						 << "\n[Devin snaps a picture and starts texting to his group chat]\n" //HIPPA violation
						 << "\nDevin: haha okay yeah do you want me to sew it back on now?\n";
						 
				}else if(incompetency > 4 && incompetency < 10){
					cout << "\n[Devin Screams]\n"
						 << "\nDevin: OH MY GOD WHAT?? HOW...\n"
						 << "\n[Devin starts to shake and gag]\n"
						 << "\nDevin: EW EW EW EW EW"
						 << "\nDevin: Oh my god should I glue it on???\n";
				
				}else{
					cout << "\nDevin: Oh.\n"
						 << "\nDevin: Yeah thats weird."
						 << "\nDevin: BUT I have this fake tongue from Spencers I can staple on."
						 << "\nDevin: How does that sound?";
				}
				
				cout << "\n╒════════════════════════════════╕"
					 << "\n|          CHOOSE ONE            |"
			 		 << "\n|--------------------------------|"
		       		 << "\n|[1] Yes                         |"
		 			 << "\n|[2] No, just leave it           |"            
			 		 << "\n╘════════════════════════════════╛\n"
			 		 <<"\n CHOICE --> ";
			 	cin >> choice;   // Will decide dialogue options -- doesnt impact gameplay really
			 	
			 	while(cin.fail() || (choice < 1 || choice >2)){			//ANOTHER user validation with cin.fail()
			 		cin.clear();
			 		cin.ignore(20, '\n');
			 		cout << "\nPlease select a valid choice! --> ";
			 		cin >> choice;
			 	}
			 	cin.ignore(100, '\n');
			 	
			 	switch(choice){ // Selects DIALOGUE OPTIONS based on above dialogue... does not affect trivia gameplay
			 		case 1:
			 			if(incompetency == 0){
							cout << "\nDevin: Ok.\n";
							
						}else if(incompetency > 0 && incompetency <= 4){
							cout << "\nDevin: uhhh ok haha"
								 << "\nDevin: havent done this before so sorry if its ugly\n";
								 
						}else if(incompetency > 4 && incompetency < 10){
							cout << "\nDevin: Ughhhhh FINE"
								 << "\nDevin: ughhh....\n"
								 << "\n[Devin puts on used gloves]\n"
								 << "\nDevin: Okay lets start...\n";
								 
						}else{
							cout << "\nDevin: Aw man I kinda liked this tongue though..."
								 << "\nDevin: Whatever... patient is always right I GUESS...\n"
								 << "\n[Devin grabs the dirty fake tongue from the supplies cabinet]\n"
								 << "\nDevin: Mwah. Goodbye Tongue.\n";
						}
			 			break;
			 		case 2:
			 			cout << "\nDevin: What?? You just want me to leave it??"
			 				 << "\nDevin: Yeah thats not happening. Lets get this operation STARTED\n";
			 			break;
			 	}
			 	
				break;
		}
		
		cout << "\n" << border << endl
			 << "\n[PRESS ENTER TO CONTINUE]";     //Works now -- had to include cin.ignore after the previous cin (buffer wasnt cleared)
					 
		cin.ignore(1000, '\n');
				
		cout << "\n┌─────────── ∘°❉°∘ ───────────┐" //Trivia begins
			 << "\n|       SURVIVAL TRIVIA       |" // The questions are the same no matter what case you chose
			 << "\n|-----------------------------|" 
			 << "\n| •°.RULES --                 |" 
	         << "\n|1.) You begin with 10 HEALTH |"
			 << "\n|  -15 health WITH insurance- |"
			 << "\n|                             |"
			 << "\n|2.) Every wrong question     |"
			 << "\n|    LOSES health             |"
			 << "\n|                             |"
			 << "\n|3.) If you reach 0 health--  |"
			 << "\n|    YOU DIE                  |"
		     << "\n|-----------------------------|"
			 << "\n|          GOOD LUCK          |"
			 << "\n└─────────── °∘❉∘° ───────────┘\n"
			 << "\n[PRESS ENTER TO BEGIN GAME]";
	   cin.ignore(100, '\n');
						
	   do{  // Begins the trivia loop -- plays again if the REPEAT char is selected as 'Y' at the end
	   		int health = 10; //beginning player health -- will be updated as each question is answered incorrectly
	   		damage = (incompetency / 2) + (health / 3);
	   		
	   		if(insurance == 'Y'){   //Raises health stats to make surviving more likely if you miss a question
	   			health += 5;
	   		}
	   		
	   		////////////// QUESTION ONE/////////////////////////
			cout << "\n----✧*̥˚ QUESTION ONE *̥˚✧----"		
				 << "\nWhich of these foods is the HIGHEST CHOKING RISK in children?\n"
				 << "\n\t1.) Hotdogs"
				 << "\n\t2.) Chicken Nuggets"
				 << "\n\t3.) Doritos\n"
				 << "\nTYPE YOUR ANSWER HERE --> ";
			cin	>> choice;
			
			while(cin.fail() || choice > 3 || choice < 1 ){ //Validation loop
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease choose a valid answer! --> ";
				cin >> choice;
			}
			cin.ignore(); 
			
			switch(choice){ // Determines if choice is CORRECT -- deletes health if not
				case 1:
					cout << "\nCORRECT! You should chop up any hotdog that a child may eat\n";
					break;
				case 2:
					cout << "\nINCORRECT! These are NOT the most commonly choked on food!\n"
						 << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
				case 3:
					cout << "\nINCORRECT! Although sharp, these are NOT the most commonly choked on food!\n"
						 << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
			}
			cout << "\nYou now have " << health << " Health!\n"
			 	 << "Try not to miss the other two questions!\n"
			 	 << "\n[PRESS ENTER TO CONTINUE]\n";
			cin.ignore(100, '\n');
			
			////////////////////QUESTION TWO /////////////////////////
			cout << "\n----✧*̥˚ QUESTION TWO *̥˚✧----"		
				 << "\nWhat is the fear of Dentists called?\n"
				 << "\n\t1.) thallasophobia"
				 << "\n\t2.) odontophobia"
				 << "\n\t3.) iatrophobia\n"
				 << "\nTYPE YOUR ANSWER HERE --> ";
			cin	>> choice;
			
			while(cin.fail() || choice > 3 || choice < 1 ){ //Validation loop
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease choose a valid answer! --> ";
				cin >> choice;
			}
			cin.ignore(); 
			
			switch(choice){ //determines if answer is correct -- deleted health if not
				case 1:
					cout << "\nINCORRECT! This is the fear of the ocean!\n"
						 << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
				case 2:
					cout << "\nCORRECT! This is a very common fear of dentists, dental procedures, and teeth!\n";
					break;
				case 3:
					cout << "\nINCORRECT! This is a fear of doctors!\n"
						 << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
			}
			
			if(health <= 0){ //restates health as 0 in case it goes to negatives
				health = 0;			
			}
			
			cout << "\nYou now have " << health << " Health!\n"
			 	 << "Try not to miss the last question!\n"
			 	 << "\n[PRESS ENTER TO CONTINUE]\n";
			cin.ignore(100, '\n');
			
			
			
			///////////QUESTION THREE//////////////////////////////
			cout << "\n----✧*̥˚ QUESTION THREE *̥˚✧----"		
				 << "\nWhich of these is NOT an alternative name for 'cotton candy?'\n"
				 << "\n\t1.) Spindly Sugar"
				 << "\n\t2.) Daddy's Beard"
				 << "\n\t3.) Sugar Spider"
				 << "\nTYPE YOUR ANSWER HERE --> ";
			cin	>> choice;
			
			while(cin.fail() || choice > 3 || choice < 1 ){ //Validation loop
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease choose a valid answer! --> ";
				cin >> choice;
			}
			cin.ignore(); 
			
			switch(choice){ //determines if answer is CORRECT -- deletes health if not
				case 1:
					cout << "\nCORRECT! I made this up.\n";
					break;
				case 2:
					cout << "\nINCORRECT! This is the name used France!\n"
					     << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
				case 3:
					cout << "\nINCORRECT! This is the common name used in the Netherlands!\n"
						 << "YOU LOST " << incompetency << " HEALTH!\n";
					health -= damage;
					break;
			}
			
			if(health <= 0){ //restates health as 0 in case it goes to negatives
				health = 0;			
			}
			
			cout << "\n┌───────── ⋆⋅☆⋅⋆ ─────────┐";
			   
			if(health <= 0){ //Text blocks that appear based on life count
				life = false;
				cout << "\n|       YOU DIED!!!       |"
					 << "\n|    The operation was    |"
				 	 << "\n|     NOT successful!     |"
				 	 << "\n|-------------------------|"
				 	 << "\n|     Try quiz again?     |"
				 	 << "\n|         [Y/N]           |"
				 	 << "\n└──────── ⋆⋅☆⋅⋆ ──────────┘\n";
				cin >> repeat;
				repeat = toupper(repeat);
			
				while(cin.fail() || (repeat != 'Y' && repeat !='N')){ //Validation loop for user choice
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\nPlease enter a valid choice! --> ";
					cin >> repeat;
					repeat = toupper(repeat); // Standardizes user input
				}
				cin.ignore();
				
			}else{ //living text block does NOT offer option to replay
				life = true;
				cout << "\n|      YOU SURVIVED       |"
					 << "\n|    The operation WAS    |"
				 	 << "\n|       successful!       |"
				 	 << "\n└──────── ⋆⋅☆⋅⋆ ──────────┘\n";
				repeat = 'N';
			}
			
		}while(repeat == 'Y'); // Allows trivia game to repeat if user wants to NOT die
		
		cout << "\n[Press Enter To Continue]\n";
		cin.ignore(100, '\n');
		
		cout << "\n" << border << endl;
		
		if(life == true){ //If user survived this text block appears to end the game
			cout << "\n┏━━━━━━━━━━━━•❃°•°❀°•°❃•━━━━━━━━━━━━━┓"
				 << "\n|          CONGRATULATIONS!          |"
				 << "\n|------------------------------------|"
				 << "\n|     You survived the operation!    |"
				 << "\n|                                    |"
				 << "\n|    Dentist Devin has charged your  |"
				 << "\n|               account              |"
				 << "\n|------------------------------------|"
				 << "\n|    Be sure to leave a good review  |"
				 << "\n|              on Google             |"
				 << "\n┗━━━━━━━━━━━━•❃°•°❀°•°❃•━━━━━━━━━━━━━┛";
			
		}else if(life == false){ //If user died and chose not to replay, this text block appears
			cout << "\n┏━━━━━━━━━━━━•❃°•°❀°•°❃•━━━━━━━━━━━━━┓"
				 << "\n|              So Sorry              |"
				 << "\n|------------------------------------|"
				 << "\n|       You died on the table        |"
				 << "\n|                                    |"
				 << "\n|    Dentist Devin has charged your  |"
				 << "\n|               account              |"
				 << "\n|------------------------------------|"
				 << "\n|    Be sure to leave a good review  |"
				 << "\n|              on Google             |"
				 << "\n┗━━━━━━━━━━━━•❃°•°❀°•°❃•━━━━━━━━━━━━━┛";
		}
		
		cout << "\nPlay again?\n" // allows user to choose to play again 
			 << "[Y/N] --> ";
		cin >> repeat;
		repeat = toupper(repeat);
		
		while(cin.fail() || (repeat != 'Y' && repeat != 'N')){ //validation loop for user input
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nPlease enter a valid choice! --> ";
			cin >> repeat;
			repeat = toupper(repeat);
		}
		 
	}while(repeat == 'Y'); //Repeats WHOLE GAME if selected to repeat
	
	if(life == true){
		cout << "\n" << border << endl
			 << "\n [You walk out of the dentistry]\n";
	}else if(life == false){
		cout << "\n" << border << endl
			 << "\n[You wake up in hell]\n"
			 << "\n[This is infinitely better than Devin's]\n";
	}
	 	 
	return 0;
}