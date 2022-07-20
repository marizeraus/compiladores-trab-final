def convertToken(token, tokenVal):
    if(token == "INT"):
        return 1
    if(token == "VOID"):
        return 2
    if(token == "IF"):
        return 3
    if(token == "RETURN"):
        return 4
    if(token == "WHILE"):
        return 5
    if(token == "IDENTIFICADOR"):
        return 6
    if(token == "ELSE"):
        return 7
    if(token == "OPENPAREN"):
        return 8
    if(token == "CLOSEPAREN"):
        return 9
    if(token == "OPENCHAVES"):
        return 11
    if(token == "CLOSECHAVES"):
        return 13
    if(token == "OPENCOLCHETE"):
        return 10
    if(token == "CLOSECOLCHETE"):
        return 11
    if(token == "VIRGULA"):
        return 14
    if(token == "PONTOVIRGULA"):
        return 15
    if(token == "CONSTANTE"):
        return 16
    if(token == "OPERADOR"):
        if(tokenVal == "="):
            return 17
        if(tokenVal == "=="):
            return 22

    if(token == "MENORIGUAL"):
        return 18
    if(token == "MAIORIGUAL"):
        return 19
    if(token == "MAIOR"):
        return 20
    if(token == "MENOR"):
        return 21
    if(token == "IGUALIGUAL"):
        return 22
    if(token == "DIFERENTE"):
        return 23
    if(token == "MAIS"):
        return 24
    if(token == "MENOS"):
        return 25
    if(token == "MULT"):
        return 26
    if(token == "DIV"):
        return 27
    if(token == "EMPTY"):
        return 28


f = open("temp1.txt", "r")
f2 = open("temp2.txt", "w")

for x in f:
    tokens = x.split(" ")
    tokens[1] = tokens[1][:-1]
    tokens[0] = convertToken(tokens[0], tokens[1])
    f2.write(str(tokens[0]) + " " + str(tokens[1]) + '\n')
f.close()
f2.close()
