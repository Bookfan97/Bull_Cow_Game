// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);   
}

void UBullCowCartridge::OnInput(const FString& Input) 
{ 
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
    
    
    // If No Show GameOver and HiddenWord?
    // Prompt To Play Again, Press Enter To Play Again?
    // Check User Input
    // PlayAgain Or Quit
}

void UBullCowCartridge::SetupGame()
{
    // Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue...")); // Prompt Player For Guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }
    // if (!bIsIsogram)
    // {
    //     PrintLine(TEXT("Sorry no repeating letters, try guessing again!"));
    //     return;
    // }
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Sorry wrong number of characters, try guessing again!"));
        PrintLine(TEXT("The word is %i characters long"), HiddenWord.Len());
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        return;
    }
    PrintLine(TEXT("Lost a life!"));
    PrintLine(TEXT("%i"), --Lives);
    if (Lives <= 0)
    {
        PrintLine(TEXT("You dead son"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;   
    }
    PrintLine(TEXT("Trying guessing again, you have %i lives left"), Lives);
}