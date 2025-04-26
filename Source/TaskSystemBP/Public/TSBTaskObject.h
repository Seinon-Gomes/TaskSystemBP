﻿#pragma once

#include "CoreMinimal.h"
#include "TSBDataTypes.h"
#include "TSBTaskResult.h"
#include "UObject/Object.h"
#include "TSBTaskObject.generated.h"

UCLASS(Abstract, Blueprintable)
class TASKSYSTEMBP_API UTSBTaskObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Task System", DisplayName = "Execute Task")
	void K2_ExecuteTask();

	UFUNCTION(BlueprintCallable, Category = "Task System")
	void SetTaskResult(const FTSBTaskResult& InTaskResult);

	virtual void ExecuteTask();
	
	FTSBTaskResult GetTaskResult();

	UPROPERTY(EditAnywhere, Category = "Task System")
	ETSBInstancingPolicy InstancingPolicy;

	void SetTaskArguments(const FInstancedStruct& InTaskArguments);

#if WITH_EDITOR
	virtual bool ImplementsGetWorld() const override;
#endif

protected:
	UFUNCTION(BlueprintPure, Category = "Task System")
	FInstancedStruct GetTaskArguments() const;
	
private:
	UPROPERTY()
	FTSBTaskResult TaskResult;
	
	FInstancedStruct TaskArguments;
};
