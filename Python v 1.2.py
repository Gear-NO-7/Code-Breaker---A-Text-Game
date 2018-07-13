import random
import sys

##Rules:
##This game would generate a multi-digit Code between 1 and 10 base on the user input
##The player would have to type a multi-digit number guess
##The computer then returns the result in terms of 'A' and 'B'
##An A would mean that the input has a right number in the right posistion
##A B would mean that the input contains a number, but at the wrong posistion
##The game ends when the player gets the right Code, which would be ''N' A, 0 B'

##Something that would come in handy later:
def NoRepeat(User):
    if len(User) != CodeDigit or not User.isdigit():
        return False
    else:
        for u in User:
            if User.count(u) > 1:
                return False
    return True

input('''Codebreaker
Press Enter to Start''' )

##Ask For Digits of the Code
CodeDigit = input('Enter Digits of the Code (1-10):')
while not CodeDigit.isdigit() or 1 > int(CodeDigit) or 10 < int(CodeDigit):
    print('Please Enter a Number Between 1 and 10')
    CodeDigit = input('Please Enter Number:')
CodeDigit = int(CodeDigit)
    
##Generates Code for round of game
NumList = [0,1,2,3,4,5,6,7,8,9]
Code = []
Count = 0
while Count < CodeDigit:
    CodeNum = random.choice(NumList)
    Code.append(CodeNum)
    NumList.remove(CodeNum)
    Count = Count + 1
##print(Code)
print('Code Generated')

##Checks if user input matches the digits of the code
Result = []
TryCount = 0
while Result.count('A') != CodeDigit:
    Result = []
    UserInput = []
    User = input('Please Enter Number, No Digits Are Allowed To Be The Same:')
    while not NoRepeat(User):
        print('Please Enter a ' + str(CodeDigit) + '-Digit Number, No Digits Are Allowed To Be The Same')
        User = input('Please Enter Number:')
    for u in User:
            c = int(u)
            UserInput.append(c)
    
##Checks Code And Prints Result
    Count = 0
    while Count < CodeDigit:
        if UserInput[Count] == Code[Count]:
            Result.append('A')
        elif UserInput[Count] in Code:
            Result.append('B')
        Count = Count + 1
    ##print(Result)
    print(Result.count('A'),'A',Result.count('B'),'B')
    TryCount = TryCount + 1
    
print('You Break the Code!')
if TryCount == 1:
    print('Lucky You! One Shot!')
else:
    print('You Took ' + str(TryCount) + ' Tries')
