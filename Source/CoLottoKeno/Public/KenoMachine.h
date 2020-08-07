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

	UPROPERTY(BlueprintReadOnly, Category = "Count")
	int KenoCount;

	UFUNCTION()
	void OnPlayRound();

	UFUNCTION()
	void OnGameOver();

	UFUNCTION()
	void OnJackPot();

	//Library of sounds relating to the Keno Count. Index 0 is "ONE!!!", etc.
	UPROPERTY(EditAnywhere, Category = "Sounds")
    TArray<USoundBase*> AudioLibrary;

	//if player's keno count equals 20
	UPROPERTY(EditAnywhere, Category = "Sounds")
    USoundBase* JackpotSound;

	//If player loses money, call this audio 
	UPROPERTY(EditAnywhere, Category = "Sounds")
    USoundBase* GameOver;	

	UPROPERTY(EditAnywhere, Category = "Sounds")
    USoundBase* OnButtonClicked;

	UPROPERTY(EditAnywhere, Category = "Sounds")
    USoundBase* ThemeMusic;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* TooBad;
	
	UPROPERTY(EditAnywhere, Category = "Credits")
	bool CreditsOnScreen;

	UPROPERTY(BlueprintReadWrite, Category = "Keno Backend")
	TSet<int32>PlayersKenoCard;

	UPROPERTY(BlueprintReadWrite, Category = "Keno Backend")
    TSet<int32>CalledKenoCard;

	UFUNCTION()
    void DrawANewCard();

	int ButtonCount;

	UFUNCTION(BlueprintCallable, Category = "Buttons")
	void OnClickButton();

protected:

	//The total money for the player, turned into dollars with a float to avoid poor integer division
    UPROPERTY(BlueprintReadWrite, Category = "Money")
    int cents;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
