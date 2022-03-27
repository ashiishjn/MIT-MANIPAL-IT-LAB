with open("names.txt", 'r') as names_file:
    with open("body.txt", 'r') as body_file:
        body = body_file.read()
        for name in names_file:
            mail = "Hello " + name.strip() + "\n" + body
            with open(name.strip()+".txt", 'w') as mail_file:
                mail_file.write(mail)