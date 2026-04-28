#################
# Author        : Grace Brown
# Created       : April 28 2026
# Last Edited   : April 28 2026
# Tutorial      : https://realpython.com/python-web-scraping-practical-introduction/
#################

from urllib.request import urlopen

#This is the website the tut created FOR this example! Legal. 
url = "http://olympus.realpython.org/profiles/aphrodite"

#to open the webpage, pass url to urlopen() function
page = urlopen(url) #this returns the HTTPResponse object

#to EXTRACT the HTML, use the object's .read() method
html_bytes = page.read()
html = html_bytes.decode("utf-8") #decode method turns bytes to strings using UTF-8

#Prints the websites HTML code!
print(html)