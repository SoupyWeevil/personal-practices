import smtplib

def prompt(prompt):
    return input(prompt).strip()

fromaddrs = prompt("From: ")
toaddrs = prompt("To: ")
print("Enter message, end with ^D (Unix) or ^Z (Windows): ")

msg = ("From: %s\r\nTo: %s\r\n\r\n" 
       % (fromaddrs, ", ".join(toaddrs)))

while True:
    try:
        line = input()
    except EOFError:
        break
    if not line:
        break
    msg = msg + line

print("Message length is", len(msg))

server = smtplib.SMTP('localhost', 1025)
server.set_debuglevel(1)
server.sendmail(fromaddrs, toaddrs, msg)
server.quit()