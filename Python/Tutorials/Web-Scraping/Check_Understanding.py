#https://realpython.com/python-web-scraping-practical-introduction/
#Tutorials and practices
#Practiced: April 28 2026

import re
from urllib.request import urlopen
from bs4 import BeautifulSoup
import mechanicalsoup

def dionysusPractice():
    url = "http://olympus.realpython.org/profiles/dionysus"

    page = urlopen(url)

    html = page.read().decode('utf-8')

    for string in ["Name: ", "Favorite Color:"]:    #Iterates through HTML... starts at "Name: " and ends at "Favorite Color:"
        startIndex = html.find(string)  #Stores all the data in the range
        textIndex = startIndex + len(string)    #Grabs the full index of the data

        nextTag = html[textIndex:].find("<")    #In the grabbed info, iterate until the first <
        endIndex = textIndex + nextTag  #Create the last index using the segmented data

        rawtext = html[textIndex : endIndex]    #Read the info from the data range
        clean = rawtext.strip(" \r\n\t")    #Eliminate leading spaces and stuff
        print(clean)


def beautifulSoupPractice():
    base_url = "http://olympus.realpython.org" #base url... you can create  RELATIVE URL by concatenating!
    page = urlopen(base_url + "/profiles") #Concatenated!
    html = page.read().decode("utf-8")
    soup = BeautifulSoup(html, "html.parser")

    for i in soup.find_all("a"): #Begins loop... searches for all data within all objects with A tag
        links = base_url + i["href"] #looks for everything with the base URL and the href attribute
        print(links)

def mechanicalSoupPractice():
    browser = mechanicalsoup.Browser()
    url = "http://olympus.realpython.org/login"
    page = browser.get(url)
    login = page.soup

    form = login.select("form")[0]
    form.select("input")[0]["value"] = "zeus"
    form.select("input")[1]["value"] = "ThunderDude"

    profiles = browser.submit(form, page.url)

    print(profiles.soup.title)

def main():
    #dionysusPractice()
    #beautifulSoupPractice()
    mechanicalSoupPractice()
    
######################### Initiates main
main()
