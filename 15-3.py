string = input()
temp = string
tags = (string.replace('<', ' ').replace('>', ' ')).split()
 
def checkTags(xml):
    stack = []
    open_right = None
    tags = (xml.replace('<', ' ').replace('>', ' ')).split()
    for i in tags:
        if i.isalpha():
            stack.append(i)
        elif i.startswith('/') and i[1:] in stack:
            stack.remove(i[1:])
        else:
             open_right = i
             return open_right
    if len(stack) == 0 and open_right == None:
        return 'closed'
    else:
        return stack
 
 
if checkTags(temp) != 'closed':
    exchange = [i for e in checkTags(temp) for i in e]
    exchange.extend(['<', '>', '/'])
    temp = list(string)
    answers = []
    for j in range(len(temp)):
        for i in '<>/qwertyuiopasdfghjklzxcvbnm':
            if temp[j] in set(exchange):
                temp[j] = i
                xml = ''.join(temp)
                if checkTags(xml) == 'closed':
                    tags = (xml.replace('<', ' ').replace('>', ' ')).split()
                    result = (''.join(["<" + i + ">" for i in tags]))
                    if len(result) == len(string):
                        answers.append(result)
                else:
                    temp = list(string)
 
    print(max(answers))      
else:
    print(''.join(["<" + i + ">" for i in tags]))
