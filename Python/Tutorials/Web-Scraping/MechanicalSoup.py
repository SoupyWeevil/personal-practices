###############
# Creator    : Grace Brown
# Created    : April 28 2026
# Last Edited: April 28 2026
# Tutorial   : https://realpython.com/python-web-scraping-practical-introduction/
###############

import mechanicalsoup, time
# this library installs a HEADLESS BROWSER

browser = mechanicalsoup.Browser() #creates a browser object

url = "http://olympus.realpython.org/login"
page = browser.get(url) #requests a page 
#page is a RESPONSE object that stores the response 

print(page) #prints <Response [200]>

#The number 200 reps the STATUS CODE returend by the request
# 200 is GOOD! 
# 404 = no existing URL
# 500 = server error

#NOTE: MechanicalSoup USES BeautifulSoup to parse through the HTML

#You can VIEW the HTML with the .soup attribute
print(page.soup)

####################
#SUBMITTING A FORM WITH MECHANICAL SOUP!
#Everything inside the <form> tags is the login form
#Name attribute in the form is set to "login"
#Two input elements: user and pwd
#Another input for Submit button

#### GET PAGE DETAILS
browser = mechanicalsoup.Browser()
url = "http://olympus.realpython.org/login"
login_page = browser.get(url)
login_html = login_page.soup

#INPUT FORM INFO!
form = login_html.select("form")[0] #returns lsit of ALL <form> elements.. access the first one with index 0
form.select("input")[0]["value"] = "zeus" #selects username form (indexed 0) and inserts zeus
form.select("input")[1]["value"] = "ThunderDude" #selects password form (indexed 1) and insters ThunderDude

#Submit form!
profiles_page = browser.submit(form, login_page.url)

#NOTE: To confirm youve logged in, run interactive window
#and type profiles_page.url
#if you get 'http://olympus.realpython.org/profiles' you got in!

#NOTE: Hackers try to bypass logins using this method..
# most websites lock you out and report your IP if they see too many failed attempts
#Very illegal! Dont try this! 

#Now its time to obtain the URL for each link on the profiles page!
#use the .select() method again
links = profiles_page.soup.select("a") #looks for all the <a> anchors

#now we iterate 
for link in links:
    address = link["href"] #finds the values of the href attributes
    text = link.text    #uses BeautifulSoup's .text property (same as .get_text())
    print(f"{text}: {address}") 

#These URLS are relative, but if you know the FULL URL, you can concatenate them
base = "http://olympus.realpython.org"
for link in links:
    address = base + link["href"]
    text = link.text
    print(f"{text}: {address}") 

#############################################
#INTERACTING WITH WEBSITES REAL TIME
#This program will REPEATEDLY scrap the page for a new result
#First thing to do: determine which element changes
#using http://olympus.realpython.org/dice

#NOTE: for the example in the tut, you can check that there is ONLY
#ONE element with id="result"
#Although id is supposed to be unique, ALWAYS check the element is uniquely identified

#start by writing a program that opens the page, scrapes result, and prints to console
browser = mechanicalsoup.Browser()
page = browser.get("http://olympus.realpython.org/dice")
tag = page.soup.select("#result")[0] #The # is a CSS ID selector to indicate "result" is an id value
result = tag.text

print(f"The result of your dice roll is: {result}")

#to periodically get a new result, create a LOOP that LOADS the page each iteration!
#NOTE: for this tut, they want four rolls EVERY ten seconds. Import time module

for i in range(4):
    browser = mechanicalsoup.Browser()
    page = browser.get("http://olympus.realpython.org/dice")
    tag = page.soup.select("#result")[0] #The # is a CSS ID selector to indicate "result" is an id value
    result = tag.text
    print(f"The result of your dice roll is: {result}")

    if i < 3: #wait 10 seconds if this is NOT the last request
        time.sleep(10) #stops for the ten seconds!

#NOTE: Remember doing this to a website that does not allow scraping, you could get IP blocked lol

