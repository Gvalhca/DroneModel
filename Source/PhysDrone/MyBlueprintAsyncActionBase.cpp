// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintAsyncActionBase.h"

UMyBlueprintAsyncActionBase::UMyBlueprintAsyncActionBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr)
{
}

UMyBlueprintAsyncActionBase* UMyBlueprintAsyncActionBase::WaitForOneFrame(const UObject* WorldContextObject, const float SomeInputVariables)
{
	UMyBlueprintAsyncActionBase* BlueprintNode = NewObject<UMyBlueprintAsyncActionBase>();
	BlueprintNode->WorldContextObject = WorldContextObject;
	//BlueprintNode->MyFloatInput = SomeInputVariables;
	return BlueprintNode;
}

void UMyBlueprintAsyncActionBase::Activate()
{
	// Any safety checks should be performed here. Check here validity of all your pointers etc.
	// You can log any errors using FFrame::KismetExecutionMessage, like that:
	// FFrame::KismetExecutionMessage(TEXT("Valid Player Controller reference is needed for ... to start!"), ELogVerbosity::Error);
	// return;

	WorldContextObject->GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UMyBlueprintAsyncActionBase::ExecuteAfterOneFrame);
}

void UMyBlueprintAsyncActionBase::ExecuteAfterOneFrame()
{
	AfterOneFrame.Broadcast();
}