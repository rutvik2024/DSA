from email.message import EmailMessage
import ssl
import smtplib

# Gmail credentials
username = "m22cs011@iitj.ac.in"
password = "rutvik@24"

email_rec = username

subject = "Email"
body = "Rutvik "


em = EmailMessage()

em['from'] = username
em['to'] = email_rec
em['subject'] = subject
em.set_content(body)

context = ssl.create_default_context()
with smtplib.SMTP_SSL('smtp.gmail.com', 465, context=context) as smtp :
    smtp.login(username, password)
    smtp.sendmail(username, email_rec, em.as_string())
