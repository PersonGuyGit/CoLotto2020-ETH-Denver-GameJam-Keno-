// Fill out your copyright notice in the Description page of Project Settings.


#include "KenoMachine.h"

// Sets default values
AKenoMachine::AKenoMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AKenoMachine::DrawANewCard()
{
	
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

