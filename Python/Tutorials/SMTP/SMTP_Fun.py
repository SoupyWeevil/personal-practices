###################################
# Created By    : Grace Brown     #
# Create Date   : April 27, 2026  #
# Last Edited   : April 27, 2026  #
# Tut           : https://www.tutorialspoint.com/python_network_programming/python_smtp.htm
###################################

import smtplib

#params: host IP, port that is listening, OWN machine (localHost, can leave as none)
#port 587  is the STANDARD modern mail submission port that uses the required encryption for modern servers
smtpObj = smtplib.SMTP("smtp.gmail.com", 587)

#identify yourself to ESMTP server
#EHLO is saying Extended Hello to the server to show differentiate between SMTP
smtpObj.ehlo()

#secure SMTP connection
#this is an ESMTP extenstion that ENCRYPTS the connection before sending credentials
smtpObj.starttls()

#######################
#Log in to account (using a dummy account)
smtpObj.login('spencerfuzzybottom@gmail.com', 'gsrl ohmp tnyx antb')

#send an email!
from_address = 'spencerfuzzybottom@gmail.com'
to_address = 'EnterFriendsEmailHere@dummy.com'

message = "This is a test email!!!"

smtpObj.sendmail(from_address, to_address, message)

#######################
#quit session
smtpObj.quit()