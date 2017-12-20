''' In this code, Hangman Game runs with no repetition of letters allowed'''
''' Additionally, there is a check whether the input is a letter or not'''
import random
#-------------------------------------------------------------------------
''' Function for getting Random Word from the list '''
def getWord(wordList):
    x = random.randint(0,len(wordList) - 1)
    randomWord = wordList[x]
    return randomWord
#-------------------------------------------------------------------------
''' Function for getting the guessed letter from the user '''
def getGuessedLetter(missedLetters,correctLetters):

    smallLetters = 'abcdefghijklmnopqrstuvwxyz'

    while 'True':
        guessedLetter = raw_input('Guess a letter: ')
        guessedLetter = guessedLetter.lower()
        if len(guessedLetter) > 1:
            print('Please enter single letter only !!! Try again')
        elif not(guessedLetter.isalnum()) or guessedLetter is '':
            print('Please enter a letter only !!! Try again')
        elif guessedLetter in missedLetters or guessedLetter in correctLetters:
            print('Already guessed this letter earlier !!! Try again')
        else:
            return guessedLetter
#-------------------------------------------------------------------------
''' Function for updating the blankWord in case correct letter guessed '''
def updateBlankWord(splitWord,guessedLetter,blankWord):
    for i in range(len(splitWord)):
        if splitWord[i] == guessedLetter:
            s = list(blankWord)
            s[i] = guessedLetter
            blankWord = ''.join(s)
    return blankWord
#-------------------------------------------------------------------------
''' Hangman Figures '''
hangManFigs = ['''

  +---+
  |   |
      |
      |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''

  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']
#-------------------------------------------------------------------------
''' MAIN Program starts here '''
wordList = 'algeria bulgaria canada denmark england finland greece hungary india'.split()
game = 'ON'
#-------------------------------------------------------------------------
''' Game Code starts here '''
print('~~~~~H A N G M A N  G A M E~~~~~')
print('~~WORDS ARE NAMES OF COUNTRIES~~')

while game == 'ON':
    count = 0
    print(hangManFigs[count])
    blankWord = ''
    numberGuess = 6
    word = getWord(wordList)
    splitWord = list(word)

    for x in range(len(word)):
        blankWord += '-'

    missedLetters = ' '
    correctLetters = ' '

    print('Missed Letters: '+ missedLetters)
    print(blankWord)

    while 'True':

        guessedLetter = getGuessedLetter(missedLetters,correctLetters)

        if guessedLetter in word:
            correctLetters += guessedLetter
            correctLetters += ' '
            blankWord = updateBlankWord(splitWord,guessedLetter,blankWord)
        else:
            numberGuess -= 1;
            missedLetters += guessedLetter
            missedLetters += ' '
            count += 1

        print(hangManFigs[count])
        print('Missed Letters: '+ missedLetters)
        print(blankWord)

        if numberGuess == 0:
            print('Sorry, you could not guess it correctly in 6 tries')
            print('The correct word is: '+ word)
            break

        if not('-' in blankWord):
            print('Congratulations, you have WON !!!')
            break

    print('Do you want to continue ? (y/n)')
    choice = raw_input()

    if choice == 'y':
        continue
    else:
        game = 'OFF'
