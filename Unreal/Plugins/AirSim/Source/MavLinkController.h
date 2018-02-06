// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MavLinkConnection.hpp"
#include "MavLinkMessages.hpp"
#include "MavLinkNode.hpp"


#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "MavLinkController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class AIRSIM_API AMavLinkController : public AController
{
    GENERATED_BODY()

public:
    AMavLinkController();
    
    virtual void Tick(float DeltaTime) override;
    virtual void BeginPlay() override;
    virtual void HandleMavLinkMessage(const mavlinkcom::MavLinkMessage& msg);
    
public:
    UPROPERTY(EditAnywhere)
	int sysid = 142;

    UPROPERTY(EditAnywhere)
	int compid = 42;
    
    UPROPERTY(EditAnywhere)
	int port = 14530;

    UPROPERTY(EditAnywhere)
	FString local_ip_address = "127.0.0.1";

private:
    std::shared_ptr<mavlinkcom::MavLinkNode> mavlink_node;
    std::shared_ptr<mavlinkcom::MavLinkConnection> mavlink_connection;
	
};
