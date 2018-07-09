# Code-Breaker---A-Text-Game
## Currently Avaliable Editions: Python
### Code for python:
```
import random
import sys


input('''Codebreaker 4-digit Edition
Press Enter to Start''' )

numlist = [0,1,2,3,4,5,6,7,8,9]
c1 = random.choice(numlist)
numlist.remove(c1)
c2 = random.choice(numlist)
numlist.remove(c2)
c3 = random.choice(numlist)
numlist.remove(c3)
c4 = random.choice(numlist)
print('Code Generated')


while numlist[0] == 0:
    userinput = []
    user = input('Please Enter Number:')
    while len(user) != 4 or not user.isdigit():
        print('Please Enter a 4-digit Number')
        user = input('Please Enter Number:')
        if len(user) == 4 and user.isdigit():
            break
    for u in user:
            s = int(u)
            userinput.append(s)
            
    result = []
    while result != ['A','A','A','A']:
        if c1 == userinput[0]:
            result.append('A')
        elif c1 == userinput[1] or c1 == userinput[2] or c1 == userinput[3]:
            result.append('B')
        else:
            result.append(0)
        if c2 == userinput[1]:
            result.append('A')
        elif c2 == userinput[0] or c2 == userinput[2] or c2 == userinput[3]:
            result.append('B')
        else:
            result.append(0)
        if c3 == userinput[2]:
            result.append('A')
        elif c3 == userinput[0] or c3 == userinput[1] or c3 == userinput[3]:
            result.append('B')
        else:
            result.append(0)
        if c4 == userinput[3]:
            result.append('A')
        elif c4 == userinput[0] or c4 == userinput[1] or c4 == userinput[2]:
            result.append('B')
        else:
            result.append(0)
        print(result.count('A'),'A',result.count('B'),'B')
        if result == ['A','A','A','A']:
            print('You Break the Code!')
            sys.exit()
        else:
            result = []
            break

```
