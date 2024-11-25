/*
 *
 *    Copyright (c) 2024 Project CHIP Authors
 *    Copyright 2024 NXP
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

#pragma once

#include "AppCLIBase.h"

namespace chip {
namespace NXP {
namespace App {

class AppCLIZephyr : public AppCLIBase
{
public:
    virtual ~AppCLIZephyr() = default;

    virtual CHIP_ERROR Init(void) override;

    virtual void ResetCmdHandle(void) override;

    static AppCLIZephyr & GetDefaultInstance();

private:
    bool isShellInitialized = false;
};
AppCLIBase & GetAppCLI();
} // namespace App
} // namespace NXP
} // namespace chip
