// Fill out your copyright notice in the Description page of Project Settings.


#include "KenoMachine.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
AKenoMachine::AKenoMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cents = 2000;

	KenoCount = 0;

	

	if(PlayersKenoCard.Num() == 20)
	{
		OnPlayRound(); 
	}
	
}

void AKenoMachine::OnPlayRound()
{

	DrawANewCard();
	
	//if(KenoCountnullptr)
	//{
	//	return; 
	//}


	switch (KenoCount)
	{

	case 0:
		UGameplayStatics::PlaySound2D(this, TooBad,1.0 ,0.0, 0.0);
	break;
		
	case 1:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 2:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 3:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 4:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 5:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 6:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 7:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 8:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;
		
	case 9:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 10:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 11:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 12:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 13:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 14:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 15:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
    break;

	case 16:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 17:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 18:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 19:
		UGameplayStatics::PlaySound2D(this, AudioLibrary[KenoCount + 1] ,1.0, 0.0, 0.0);
	break;

	case 20:
		UGameplayStatics::PlaySound2D(this, JackpotSound ,1.0, 0.0, 0.0);
	break;
default:
	UGameplayStatics::PlaySound2D(this, TooBad, 1,1,0);
	}
}

void AKenoMachine::OnGameOver()
{
	UGameplayStatics::PlaySound2D(this, GameOver ,1.0, 0.0, 0.0);
}

void AKenoMachine::OnJackPot()
{
	UGameplayStatics::PlaySound2D(this, JackpotSound ,1.0 ,0.0, 0.0);
}

void AKenoMachine::DrawANewCard()
{

	CalledKenoCard.Empty();
	
	//Create a random array, for the card used by the CO Lottery's rules
	for (int i = 0; i < 19; ++i)
	{
		int32 RandValue = FMath::RandRange(1, 80);
		CalledKenoCard.Add(RandValue);
        
		if(PlayersKenoCard.Contains(RandValue))
		{
			KenoCount++;
		}
	}
	
	if(cents >= 100)
	{
		cents -= 100;
	}
	else if(cents < 100)
	{
		OnGameOver();
	}

	OnPlayRound();
	
}

void AKenoMachine::OnClickButton()
{
	PlayersKenoCard.Add(ButtonCount);
	
	ButtonCount++;

	if(ButtonCount == 20)
	{
		DrawANewCard();
	}
}

// Called when the game starts or when spawned
void AKenoMachine::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AKenoMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

