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

#If you know the index of the first character of the title, you can use string slice to extract title
#use the .find() method to RETURN THE INDEX of the first occurence of the substring
title_index = html.find("<title>")

#You ONLY want the index of the TITLE, not the title TAG...
#Add the length of the string "<title>" to title_index
start_index = title_index + len("<title>")

#Now get the index of the closing tag
end_index = html.find("</title")

#Then SLICE the string!!!
title = html[start_index:end_index]

print(title)