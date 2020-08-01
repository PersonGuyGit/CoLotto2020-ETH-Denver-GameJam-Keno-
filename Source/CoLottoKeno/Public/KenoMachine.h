// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Actor.h"
#include "KenoMachine.generated.h"

UCLASS()
class COLOTTOKENO_API AKenoMachine : public AActor
{
	GENERATED_BODY()


	
	
public:	
	// Sets default values for this actor's properties
	AKenoMachine();

	//IF any item(s) from BackendBingoCard[] match the contents of PlayersBingoCard[], allow the player to mark them
	UFUNCTION(BlueprintImplementableEvent, Category = "UX")
    void MarkADot();
	
	UPROPERTY(BlueprintReadOnly, Category = "Count")
	int KenoCount;
	
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    TArray<UAudioComponent*> AudioLibrary;

	//if player's keno count equals 20
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* Jackpot;

	//If player loses money, call this audio 
	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* GameOver;	

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* OnButtonClicked;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* ThemeMusic;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* MatchFailed;

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
    UAudioComponent* MatchSuccess;

	UPROPERTY(EditAnywhere, Category = "Credits")
	bool CreditsOnScreen;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Marked as EDO for purposes of Debugging
	//This int is randomized each time a new number is called by the gamemaster.
	UPROPERTY(EditDefaultsOnly, Category = "Bingo Backend")
    int NumberCalled;

	UPROPERTY(EditDefaultsOnly, Category = "Keno Backend")
	TArray<int>PlayersKenoCard;

	UPROPERTY(EditDefaultsOnly, Category = "Keno Backend")
    TArray<int>CalledKenoCard;
	
	UFUNCTION()
    void DrawANewCard();

	//The total money for the player, turned into dollars with a float to avoid poor integer division
	UPROPERTY(EditDefaultsOnly, Category = "Keno Backend")
    int64 Cents;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
