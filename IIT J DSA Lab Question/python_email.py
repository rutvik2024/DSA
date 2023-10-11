# import smtplib

# gmail_user = 'm22cs011@iitj.ac.in'
# gmail_password = 'rutvik@24'

# sent_from = gmail_user
# to = ['m22cs011@iitj.ac.in', ]
# subject = 'OMG Super Important Message'
# body = 'Hey, what'

# email_text = """\
# From: %s
# To: %s
# Subject: %s

# %s
# """ % (sent_from, ", ".join(to), subject, body)

# try:
#     server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
#     server.ehlo()
#     server.login(gmail_user, gmail_password)
#     server.sendmail(sent_from, to, email_text)
#     server.close()

#     print('Email sent!')
# except:
#     print('Something went wrong...')



import csv
import smtplib

# Gmail credentials
username = "m22cs011@iitj.ac.in"
password = "rutvik@24"

# Read data from .csv file
with open('/home/rutvik/Downloads/csv1.csv', 'r') as file:
    reader = csv.reader(file)
    contacts = list(reader)

# Email information
from_address = username
subject = "Important Email"
message = "This is a test message sent from Python."

# Connect to Gmail
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(username, password)

# Send email to all contacts
for contact in contacts:
    to_address = contact[0]
    full_message = f"From: {from_address}\nSubject: {subject}\n\n{message}"
    server.sendmail(from_address, to_address, full_message)

# Close connection
server.quit()
