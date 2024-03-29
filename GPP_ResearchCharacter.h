// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FormationSlot.h"
#include "GPP_ResearchCharacter.generated.h"


UCLASS(Blueprintable)
class AGPP_ResearchCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGPP_ResearchCharacter();

	virtual void BeginPlay() override;
	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns SelectedDecal subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return SelectedDecal; }

	bool bIsSelected;

	UPROPERTY(BlueprintReadWrite)
	bool bIsMoving;

	UPROPERTY(BlueprintReadWrite)
	FVector Destination;

	class AAIController* AIController;

	class AFormationSlot* FollowSlot;

	bool bIsInFormation;

	void MoveToDestination();
	void MoveTo(const FVector& destination);

private:

	
	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* SelectedDecal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* TargetDecal;
};

