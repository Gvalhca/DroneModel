// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyBlueprintAsyncActionBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyBlueprintAsyncActionBaseOutputPin);

UCLASS()
class PHYSDRONE_API UMyBlueprintAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FMyBlueprintAsyncActionBaseOutputPin AfterOneFrame;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
		static UMyBlueprintAsyncActionBase* WaitForOneFrame(const UObject* WorldContextObject, const float SomeInputVariables);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	//~UBlueprintAsyncActionBase interface
private:
	UFUNCTION()
		void ExecuteAfterOneFrame();


private:
	const UObject* WorldContextObject;
	
};
