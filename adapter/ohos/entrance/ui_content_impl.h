/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FOUNDATION_ACE_ADAPTER_OHOS_ENTRANCE_ACE_UI_CONTENT_IMPL_H
#define FOUNDATION_ACE_ADAPTER_OHOS_ENTRANCE_ACE_UI_CONTENT_IMPL_H

#include "interfaces/innerkits/ace/ui_content.h"
#include "interfaces/innerkits/ace/viewport_config.h"
#include "key_event.h"
#include "native_engine/native_value.h"
#include "touch_event.h"

#include "base/utils/macros.h"

namespace OHOS {

class Window;

} // namespace OHOS

namespace OHOS::Ace {

class ACE_FORCE_EXPORT UIContentImpl : public UIContent {
public:
    UIContentImpl(OHOS::AbilityRuntime::Context* context, void* runtime);
    ~UIContentImpl() = default;

    // UI content lifecycles
    void Initialize(OHOS::Rosen::Window* window, const std::string& url, NativeValue* storage) override;
    void Foreground() override;
    void Background() override;
    void Focus() override;
    void UnFocus() override;
    void Destroy() override;

    // UI content event process
    bool ProcessBackPressed() override;
    bool ProcessPointerEvent(const std::shared_ptr<OHOS::MMI::PointerEvent>& pointerEvent) override;
    bool ProcessKeyEvent(const std::shared_ptr<OHOS::MMI::KeyEvent>& keyEvent) override;
    bool ProcessAxisEvent(const std::shared_ptr<OHOS::MMI::AxisEvent>& axisEvent) override;
    bool ProcessVsyncEvent(uint64_t timeStampNanos) override;
    void UpdateViewportConfig(const ViewportConfig& config) override;

    // interface for test
    bool ProcessTouchEvent(const OHOS::TouchEvent& touchEvent);
    void Initialize(OHOS::Window* window, const std::string& url, NativeValue* storage);

private:
    OHOS::AbilityRuntime::Context* context_ = nullptr;
    void* runtime_ = nullptr;
    OHOS::Window* window_ = nullptr;
    ViewportConfig config_;
    std::string startUrl_;
    int32_t instanceId_ = -1;
};

} // namespace OHOS::Ace

#endif // FOUNDATION_ACE_ADAPTER_OHOS_ENTRANCE_ACE_UI_CONTENT_IMPL_H