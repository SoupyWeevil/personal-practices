###############
# Creator    : Grace Brown
# Created    : April 28 2026
# Last Edited: April 28 2026
# Tutorial   : https://realpython.com/python-web-scraping-practical-introduction/
###############

from bs4 import BeautifulSoup
from urllib.request import urlopen

url = "http://olympus.realpython.org/profiles/dionysus"
page = urlopen(url)
html = page.read().decode("utf-8")

#heres the NEW ONE!
#Arguments: HTMl to be parsed, specific parser that tells object WHICH parser to use
soup = BeautifulSoup(html, "html.parser") #Creates a beautiful soup object

#NOTE: SAVE AND RUN THE PROGRAM NOW TO USE THE VARIABLE IN INTERACTIVE WINDOW!
#To enter interactive mode: copy this to run in proper path
#python -i BeautifulSoup_Parsing.py

#in the interactive window, type: print(soup.get_text())
#This extracts all the TEXT from the document and removes HTML tags

#To access all the links in a page:
soup.find_all("img") 
#Returns ALL the links under the img tag as a Tag object

#Unpacking each tag object, you can use the .name property to return the tag TYPE
img1, img2 = soup.find_all("img")

print(img1.name)    #Both print out "img" as this type of tag is an img link tag
print(img2.name)

#You can ACCESS the HTML attributes of the object by putting their "names" between brackets
#EX: <img src="/some/random/link.jpg"/> 
# This tag has a single attribute (src) with a value "/some/random/link.jpg"

#To get the SOURCE of the images, you ACCESS the src attribute using the dictionary notation
print(img1["src"])
print(img2["src"])

#Certain tags can be accessed by PROPERTIES of the tag object
#Ex: Title uses .title property
title = soup.title
print(title) #Will print with the HTML tags!

#NOTE: BeautifulSoup AUTOMATICALLY cleans all the tags for you! 
# No more <TITLE> <  /title  /> BS!!!

#To retrieve the string in the middle of the tags, use the string object!
title = soup.title.string
print(title) #No more tags!

#BeautifulSoup AlSO has the ability to seach for specific kinds of tags with specific Attributes
soup.find_all("img", src="/static/dionysus.jpg") #Returns all the instances with this exact tag and attribute value pair!

#NOTE: Beautiful Soup is great for scraping HTML, but does NOT
#provide any way to work with HTML forms. May use another library for that!