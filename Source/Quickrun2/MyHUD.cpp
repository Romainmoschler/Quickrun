// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Containers/UnrealString.h"
#include "Math/Color.h"
#include "Engine/Font.h"


AMyHUD::AMyHUD()
{
}

void AMyHUD::ShowScore()
{

	
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

		DrawText("0", FLinearColor(255, 0, 0, 0), 10.0F, 10.0f, Font, 1.0f, false);
}