#Sieve Of Eratosthenes prime number finder - Python Conversion October 2018
#by Shane
#
#Converted from original C++ March 2017 version by Shane
#
#The code requires user input of an integer less than the arrSize variable
#and will then return all primes less than that input using the Sieve of Eratosthenes technique
#
#Feel free to look at this code and learn but please don't reuse it without my permission
#
#This code was written and tested using Visual Studio 2017 but should work on any Python interpreter
#including the SoloLearn testing environment
#  ******* how does solo learn do input now?
#
#
#original code: 9th October 2018
#update: no updates yet

#import necessary code
import time

#declare the variables
arrSize = 1500001   #this is included as a variable so that the upper bound can be changed easily
maxValue = 0
inputStr = ""
testArray = []
loopContinue = True
startTime = 0
currentTime = 0
elapsedSeconds = 0.0


print("The Sieve of Eratosthenes")

#play the game
while loopContinue:
    #get valid input from the user
    validInput = False
    while not validInput:
        inputStr = input("Please enter a number from 2 to " + str(arrSize - 1) + " : ")
        if inputStr.isnumeric():
            if int(inputStr) > 1 and int(inputStr) < arrSize:
                validInput = True
                maxValue = int(inputStr)
                pass
            else:
                print("That value isn't valid, please try again")
                pass
        else:
            print("That value isn't valid, please try again")
            pass

    # initialise the array
    del testArray
    testArray = []
    for i in range(0, maxValue):
        testArray.append(True)
        pass

    # start the clock
    startTime = time.time()      

    # use the sieve of Eratosthenes to remove all non-primes
    for i in range(2, int(maxValue**(1/2.0))+1):
        if testArray[i]:
            for j in range(2, int(maxValue / i)):
                testArray[i * j] = False
                pass
        pass

    # output all primes as well as a total and a count
    print("The primes less than " + str(maxValue) + " are: ")
    primeCount = 0
    primeTotal = 0
    for i in range(2, maxValue):
        if testArray[i]:
            print(str(i) + " ", end="")
            primeCount += 1
            primeTotal += i
        pass
    pass
    print()
    print("The number of primes is: " + str(primeCount) + " and the sum is: " + str(primeTotal))


    # stop the clock
    currentTime = time.time()
    elapsedSeconds = (currentTime -  startTime)
    print("This took: " + str(elapsedSeconds) + " seconds to run")

    loopAnswer = input("Do you want another go (Y/N)? ")
    if (loopAnswer == "y" or loopAnswer == "Y"):
        loopContinue = True
        pass
    else:
        loopContinue = False
        pass

