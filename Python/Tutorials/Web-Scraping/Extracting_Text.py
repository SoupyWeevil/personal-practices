#################
# Author        : Grace Brown
# Created       : April 28 2026
# Last Edited   : April 28 2026
# Tutorial      : https://realpython.com/python-web-scraping-practical-introduction/
#################

from urllib.request import urlopen
import re   #For second part of tut!

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

#############################################################

#Although that method is fun, there will be an issue if the syntax
#is slightly off, such as <title > thing <  / title>
#These differences will cause a shift in index, rendering the method useless

#Regualr Expressions (Regexes) are PATTERNS that you can use to search for text within a string
#Use python's re module!
#Regexes use metacharacters to denote different patterns...

#Use .findall() method to find AnY text within a string that matches a given regex
#first argument: Regex that you WANT to match
#Second argument: the string to TEST
example = re.findall("ab*c", "ac")
print(example)
# ^ Prints ['ac']

#The regex matches ANY part of the string that BEGINS with A and ENDS with C
#AND has 0 or more instances of B inbetween
#.findall() returns a LIST of all the matches...
#more examples!

example = re.findall("ab*c", "abcd") #['abc']
print(example)
example = re.findall("ab*c", "acbac")   #['ac', 'ac']
print(example)
example = re.findall("ab*c", "bchajkc") #[]
print(example)

#NOTE: Pattern matching is CASE SENSITIVE
#If you want to match regardless of case, pass a THIRD argument -> re.IGNORECASE

#you can use a . to stand for any SINGLE character in a regex
#You could find all the strings that contain "a" and "c" seperated by a SINGLE character
example = re.findall("a.c", "abc")  #['abc']
print(example)
example = re.findall("a.b", "AnB", re.IGNORECASE)   #['AnB']
print(example)

#The pattern .* inside a regex stands for ANY character repeated a number of times
#You can use "a.*c" to find EVERY substring that starts with "a" and ends with "c" 
#REGARDLESS of what is inbetween!!!
example = re.findall("a.*c", "abbbbbc") #['abbbbc']
print(example)

#re.search() seaches for a pattern INSIDE a string. Its more complicated than
#re.findall() since it returns an object that stores DIFFERENT groups of data
#BUT for now, just know if we call .group() on the return, it will return the
#FIRST and MOST INCLUVSIVE result 
match_results = re.search("ab*c", "ABC", re.IGNORECASE)
print(match_results.group())    #ABC

#One more function for parsing text: re.sub()
#Allows you to REPLACE the text in a string that matches the regex
#Behaves similar to .replace() stirng method

#Arguments: Regex, replacement, OG string
string = "Everything is <replaced> if it's in <tags>."
string = re.sub("<.*>", "ELEPHANTS", string)
print(string)   #Everything is ELEPHANTS

#Why did it cut apart the rest of the string??
#re.sub() uses the regex <.*> to find and replace EVERYTHING between the 
#FIRST AND LAST < >... see the pattern? 
#<Replaced..... Tags> first and last...

#Alternatively you can use .*? which is the same as .* but matches the SHORTEST string
string = "Everything is <replaced> if it's in <tags>."
string = string = re.sub("<.*?>", "ELEPHANTS", string)
print(string)   #Everyting is ELEPHANTS if it's in ELEPHANTS.

#############################################################

#using this knowledge, I will ATTEMPT to scrape another given page
url = "http://olympus.realpython.org/profiles/dionysus"

page = urlopen(url)

html_bytes = page.read()
html = html_bytes.decode('utf-8')

pattern = "<title.*?>.*?</title.*?>"
foundTitle = re.search(pattern, html, re.IGNORECASE)
title = foundTitle.group()
title = re.sub("<.*?>", "", title)
print(title)

#OKay i wont lie i cheated a bit and looked at the solution BUT i understand how they did it
#############################################################

