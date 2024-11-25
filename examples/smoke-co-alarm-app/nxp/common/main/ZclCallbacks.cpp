/*
 *
 *    Copyright (c) 2021-2023 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <lib/support/logging/CHIPLogging.h>

#include "AppTask.h"
#include "CHIPDeviceManager.h"

#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/ConcreteAttributePath.h>
#include <app/util/af-types.h>
#include <app/util/af.h>

#include "SmokeCoAlarmManager.h"

using namespace ::chip;
using namespace ::chip::app::Clusters;

void MatterPostAttributeChangeCallback(const chip::app::ConcreteAttributePath & path, uint8_t type, uint16_t size, uint8_t * value)
{
	
	ClusterId clusterId     = path.mClusterId;
    AttributeId attributeId = path.mAttributeId;
    ChipLogProgress(Zcl, "Cluster callback: " ChipLogFormatMEI, ChipLogValueMEI(clusterId));

    if (clusterId == SmokeCoAlarm::Id && attributeId == SmokeCoAlarm::Attributes::ExpressedState::Id)
    {
        static_assert(sizeof(SmokeCoAlarm::ExpressedStateEnum) == 1, "Wrong size");
        SmokeCoAlarm::ExpressedStateEnum expressedState = *(reinterpret_cast<SmokeCoAlarm::ExpressedStateEnum *>(value));
        ChipLogProgress(Zcl, "Smoke CO Alarm cluster: " ChipLogFormatMEI " state %d", ChipLogValueMEI(clusterId),
                        to_underlying(expressedState));
    }
	
}

void emberAfSmokeCoAlarmClusterInitCallback(EndpointId endpoint)
{
    // TODO: implement any additional Cluster Server init actions
}

void emberAfPluginSmokeCoAlarmSelfTestRequestCommand(EndpointId endpointId)
{
    AlarmMgr().SelfTestingEventHandler();
}