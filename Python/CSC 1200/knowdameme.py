#School assignment -- Practice loops, dictionaries, and string iteration
#GRACE BROWN
#Last Modified: 11 November 2025

import random, sys, time

def themeDecoration():                                                           #Intro and Banner decoration
    print("""                                                                                           
 ______   _______      __   __  _______  __   __      ___   _  __    _  _______      ______   _______      __   __  _______  __   __  _______    ______  
|      | |       |    |  | |  ||       ||  | |  |    |   | | ||  |  | ||       |    |      | |   _   |    |  |_|  ||       ||  |_|  ||       |  |      | 
|  _    ||   _   |    |  |_|  ||   _   ||  | |  |    |   |_| ||   |_| ||   _   |    |  _    ||  |_|  |    |       ||    ___||       ||    ___|  |___   | 
| | |   ||  | |  |    |       ||  | |  ||  |_|  |    |      _||       ||  | |  |    | | |   ||       |    |       ||   |___ |       ||   |___     __|  | 
| |_|   ||  |_|  |    |_     _||  |_|  ||       |    |     |_ |  _    ||  |_|  |    | |_|   ||       |    |       ||    ___||       ||    ___|   |_____| 
|       ||       |      |   |  |       ||       |    |    _  || | |   ||       |    |       ||   _   |    | ||_|| ||   |___ | ||_|| ||   |___      __    
|______| |_______|      |___|  |_______||_______|    |___| |_||_|  |__||_______|    |______| |__| |__|    |_|   |_||_______||_|   |_||_______|    |__|                                                                                            
           """)
    print(" .　 . • ☆ . ° .• °:. *₊ ° . ☆.　 . • ☆ . ° .• °:. *₊ ° . ☆.　 . • ☆ . ° .• °:. *₊ ° . ☆")
    print(" ")
    slow_print("Welcome to the Hit Game Show: 'Do You Kno Da Meme!'", delay=0.05)                                   
    slow_print("...")
    print(" ")
    slow_print("*Crowd is silent*", delay=0.1)
    print(" ")
    slow_print("...", delay=0.09)
    print(" ")
    slow_print("Right.", delay=0.09)
    slow_print("Ahem.", delay=0.09)
    print(" ")
    slow_print("Well then... Lets begin!")


def simpleMatch(secret, guess):                                                  #Returns the amount of CORRECT characters in proper position
    
    return sum(secret[i] == guess[i] for i in range(min(len(secret), len(guess))))


def substringMatch(text, pattern):                                               
    n, m = len(text), len(pattern)                                               #Loop checks every possible letter in text for a match
                                                                                    
    for i in range(n - m + 1):
        match = True
        for j in range(m):
            if text[i + j] != pattern[j]:
                match = False
                break
        
        if match:                                                               #if its a match return true
            return True
    
    return False                                                                #if its not a match return false


def begin(name):                                                                #Allows contestant to choose if they want to play
    result = True
    slow_print(f"Would you like to play, {name}?")
    while result == True:
        print("[YES] [NO]")
        choice = input("...")
        choice = choice.upper()
        
        if choice == "YES":                                                     # choosing YES begins the playthrough Cycle
            result = True
            break
        elif choice == "NO":                                                    # choosing NO ends the game cycle
            slow_print("Guards!! Boot this guy off my stage!", delay=0.08)
            result = False
            break
        else:                                                                   # other choice repeats the loop until proper choice is implemented
            print("Please Type a Valid Choice!")
    return result
    

def slow_print(text, delay=0.02):                                               # prints out each letter at a timed interval
    for c in text:
        sys.stdout.write(c)
        sys.stdout.flush()
        time.sleep(delay)
    print()


def hints(secret):                                                                # provides a random hint per secret under the [HINT] option in menu
    hint_dict = {
        "trollface" : ["This is the face you make when you EPICALLY grief someone's Minecraft server", "Rage Comics Mascot", "Trololololol"],
        "six seven" : ["Tuffest Number", "Middle Schooler's favorite number", "69 but worse"],
        "big chungus" : ["Bugs Bunny but AWESOME", "Looney Toons character", "'That'll hold em all right heheheh'"],
        "among us": ["Sus Game", "Imposter was ejected", "2020 peak game"],
        "doge" : ["Such funny. wow. much shiba", "Elon Musk got his grubby hands on this meme", "crypto currency"],
        "sigma" : ["A based blud that mews", "What Patrick Bateman is considered", "Looksmaxxers"],
        "ugandan knuckles" : ["On de wae to da queen", "2018 red guy", "The title of this game is inspired by this meme"],
        "knee surgery" : ["What the Blinch is excited for tomorrow!", "Finish the quote: 'That feeling when [GUESS] is tomorrow'", "Benedict Cumcmperpatch Grinch but Blue"]
    }
    hint = random.choice(hint_dict[secret])                                     #maps out a random item based on the secret key
    
    print("★・・・・・・★・・・・・・★・・・・・・★")
    print(" ")
    print(hint)                                                                 #prints the hint
    print(" ")
    print("★・・・・・・★・・・・・・★・・・・・・★")

def menu():                                                                     # determines player action
    slow_print("What would You Like To Do?")
    print(" ")
    print("[1. GUESS] [2. HINT] [3. GIVE UP]")                                  # Three choices... [GIVE UP] breaks gameplay loop
    choice = True                                                               
    while True:
        menu_choice = input("[Enter Answer]... ").upper()
        if menu_choice == "1" or menu_choice == "GUESS":                        #if GUESS is chosen, the value of choice will reflect that
            choice= "guess"
            break
        elif menu_choice == "2" or menu_choice == "HINT":                       # if HINT is chosen, the value of choice will reflect that
            choice= "hint"
            break
        elif menu_choice == "3" or menu_choice == "GIVE UP":                    # if GIVE UP is chosen, gameplay loop will end
            choice= "give up"
            break
        else:                                                                   # Loop will continue if invalid choice is selected
            print("Please Select a Valid Choice!")
    return choice


def gamePlay(name):                                                                 # Main Gameplay function -- holds special variables and lists
    ################# VARIABLES ###################
    secrets=["trollface", "six seven", "big chungus", "among us", "doge", "sigma", "ugandan knuckles", "knee surgery"]
    word = random.choice(secrets)

    ################# FUNCTIONS ###################
    print(" ")
    while True:                                                                 # uses the return value from menu() to loop 
        choice = menu()
        if choice == "guess":                                                   # if GUESS is chosen, contestant gets to Type a guess
            print(" ")
            slow_print("TYPE GUESS BELOW")                                      
            guess = input("...").lower()
            print(" ")

            if guess == word:                                                   #outcome function prints endgame screen
                outcome(name, guess, word)
                return guess, word
                break

            elif guess != word:                                                 #Implements the substring and simplematch functions
                slow_print("THAT IS NOT THE WORD...")
                slow_print("however...", delay =0.08)
                slow_print(f"There are {simpleMatch(word, guess)} shared characters (in correct position) in your guess!")
                print(" ")
                
                if substringMatch(word, guess) == True:
                    slow_print("You have part of the secret meme guessed!")     #tells user if their string is EXACTLY part of the main secret
                elif substringMatch(word, guess) == False:
                    print("Your guess is NOT a subpart of the guess")
                    
                print(" ")
                slow_print("Try again!")
            print(" ")
            print("★・・・・・・★・・・・・・★・・・・・・★")

        elif choice == "hint":                                                  # if HINT is chosen, a hint in realtion to the list item is displayed
            print(" ")
            hints(word)
            print(" ")
        

        elif choice == "give up":                                               # if GIVE UP is chosen, the gameplay loop is broken
            slow_print("Guards!! Boot this guy off my stage!", delay=0.08)
            outcome(name, "giveup", word)
            break

        print(" ")

def outcome(name, guess, word):                                                # FINISH
    if guess == word:                                                          # if guess == secret then SUCCESS runs
        print(" ")
        slow_print(f"CONGRATULATIONS {name}!!!")
        slow_print("YOU KNO DA MEME!")
        print(" ")
        slow_print("ඩා ඩා ඩා ඩා ඩා ඩා ඩා ඩා")

    elif guess != word:                                                        # if guess =/= secret, then FAILURE runs
        print(" ")
        slow_print(f"I'm so sorry, {name}.")
        slow_print("You do NOT kno da meme :(")
        print(" ")
        print(" ❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。")
        

def main():                                                                     # compiles all the main functions into a loop
    themeDecoration()

    print(" ")
    slow_print("Now, contestant, what is YOUR name?")
    name = input("[Enter Name]... ")
    name = name.upper()                                                         # stores entered name as an uppercase string
    print(" ")
    slow_print(f"{name}! Welcome to the show!", delay=0.08)
    print(" ")

    while begin(name)== True:                                                   # BEGINS the main gameplay loop until GIVE UP is chosen
        gamePlay(name)
        print(" ")
        slow_print("Would you like to play again?")
        print("[YES] [NO]")
        
        answer = input("...").upper()

        while True:                                                             #Inner loop allows the choice to play again
            if answer == "YES" or answer == "Y":
                print(" ")
                slow_print("Alright! Thats what I'm talking about!")
                print(" ")
                slow_print("❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。")
                print(" ")
                break                                                           # 'break' only stops the inner loop and continues the gameplay loop

            elif answer == "NO" or answer == "N":                               #Exit() leaves both loops so game stops completely
                print(" ")
                slow_print("Alright! Thank you for playing!", delay = 0.05)
                slow_print("...", delay=0.5)
                slow_print("Okay get off my stage now", delay = 0.09)
                print(" ")
                print("❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。❀。• *₊°。 ❀°。")
                exit()
            else:                                                               #repeats the inner loop until valid answer is selected
                print(" ")
                print("Please type a valid answer!")
                print(" ")

#################### INITIATES MAIN ######################

if __name__ == "__main__":
    main()
