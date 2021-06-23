// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class QUICKRUN2_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
protected:

public:
	AMyHUD();
	UFUNCTION(BlueprintCallable)
		void ShowScore();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MOO)
		UFont* Font;

private:
	virtual void DrawHUD() override;

	float uiScale_;

};
