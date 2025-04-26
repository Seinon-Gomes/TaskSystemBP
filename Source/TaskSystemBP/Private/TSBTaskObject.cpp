#include "TSBTaskObject.h"

void UTSBTaskObject::SetTaskResult(const FTSBTaskResult& InTaskResult)
{
	TaskResult = InTaskResult;
}

void UTSBTaskObject::ExecuteTask()
{
	K2_ExecuteTask();
}

FTSBTaskResult UTSBTaskObject::GetTaskResult()
{
	return TaskResult;
}

void UTSBTaskObject::SetTaskArguments(const FInstancedStruct& InTaskArguments)
{
	TaskArguments = InTaskArguments;
}

#if WITH_EDITOR
bool UTSBTaskObject::ImplementsGetWorld() const
{
	return true;
}
#endif

FInstancedStruct UTSBTaskObject::GetTaskArguments() const
{
	return TaskArguments;
}
