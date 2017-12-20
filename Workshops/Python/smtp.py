import smtplib
content = "test mail"
mail = smtplib.SMTP("smtp.gmail.com",587)
mail.ehlo
mail.starttls()
mail.login("chinmay.chandak16@siesgst.ac.in","pass")
mail.sendmail("chinmay.chandak16@siesgst.ac.in","abc@gmail.com",content)
#mail.sendmail("sender","reciver","content")
mail.close()
