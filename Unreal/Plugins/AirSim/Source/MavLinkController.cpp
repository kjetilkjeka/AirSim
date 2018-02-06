// Fill out your copyright notice in the Description page of Project Settings.


#include "MavLinkController.h"


AMavLinkController::AMavLinkController(){
    PrimaryActorTick.bCanEverTick = true;    
}

void AMavLinkController::BeginPlay()
{
    Super::BeginPlay();

    std::string laddr = std::string(TCHAR_TO_UTF8(*local_ip_address));
    
    mavlink_node = std::make_shared<mavlinkcom::MavLinkNode>(sysid, compid);
    mavlink_connection = mavlinkcom::MavLinkConnection::connectLocalUdp("", laddr, port);

    if (mavlink_connection == NULL) {
	UE_LOG(LogTemp, Warning, TEXT("Could not connect to MavLink"));
    }
    
    mavlink_node->connect(mavlink_connection);
    mavlink_node->startHeartbeat();
    mavlink_connection->subscribe([=](std::shared_ptr<mavlinkcom::MavLinkConnection> mavlink_connection, const mavlinkcom::MavLinkMessage& msg) {
	    unused(mavlink_connection);
	    HandleMavLinkMessage(msg);
	});

}

void AMavLinkController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMavLinkController::HandleMavLinkMessage(const mavlinkcom::MavLinkMessage& msg)
{
}
