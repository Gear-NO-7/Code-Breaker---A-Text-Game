import random
import sys

##Rules:
##This game would generate a 4-digit code
##The player would have to type a 4-digit number guess
##The computer then returns the result in terms of 'A' and 'B'
##An A would mean that the input has a right number in the right posistion
##A B would mean that the input contains a number, but at the wrong posistion
##The game ends when the player gets the right code, which would be '4A, 0B'

input('''Codebreaker 4-digit Edition
Press Enter to Start''' )

numlist = [0,1,2,3,4,5,6,7,8,9]    ##Generates Code for round of game
c1 = random.choice(numlist)
numlist.remove(c1)
c2 = random.choice(numlist)
numlist.remove(c2)
c3 = random.choice(numlist)
numlist.remove(c3)
c4 = random.choice(numlist)
print('Code Generated')

result = []                        ##Checks if user input is a 4-digit number
while result != ['A','A','A','A']:
    result = []
    userinput = []
    user = input('Please Enter Number:')
    while len(user) != 4 or not user.isdigit():
        print('Please Enter a 4-digit Number')
        user = input('Please Enter Number:')
    for u in user:
            s = int(u)
            userinput.append(s)
            
    if c1 == userinput[0]:         ##Checks if the input matches the code
        result.append('A')
    elif c1 in userinput:
        result.append('B')
    if c2 == userinput[1]:
        result.append('A')
    elif c2 in userinput:
        result.append('B')
    if c3 == userinput[2]:
        result.append('A')
    elif c3 in userinput:
        result.append('B')
    if c4 == userinput[3]:
        result.append('A')
    elif c4 in userinput:
        result.append('B')
    print(result.count('A'),'A',result.count('B'),'B')
    
print('You Break the Code!')
