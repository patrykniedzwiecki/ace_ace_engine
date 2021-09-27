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

#ifndef FRAMEWORKS_BRIDGE_DECLARATIVE_FRONTEND_JS_VIEW_JS_MENU_H
#define FRAMEWORKS_BRIDGE_DECLARATIVE_FRONTEND_JS_VIEW_JS_MENU_H

#include "frameworks/bridge/declarative_frontend/view_stack_processor.h"
#include "frameworks/bridge/declarative_frontend/jsview/js_container_base.h"
#include "frameworks/core/components/menu/menu_component.h"

namespace OHOS::Ace::Framework {
class JSMenu : public JSContainerBase {
public:
    static void Create(const JSCallbackInfo& info);
    static void JSBind(BindingTarget globalObj);

    static void SetShow(const JSCallbackInfo& info);
    static void MenuShowPosition(const JSCallbackInfo& info);

    // Common text attribute
    static void SetFontColor(const JSCallbackInfo& info);
    static void SetFontSize(const JSCallbackInfo& info);
    static void SetFontWeight(std::string value);
    static void SetFontFamily(std::string value);
private:
    static RefPtr<MenuComponent> GetMenuComponent();
};
} // namespace OHOS::Ace::Framework
#endif // FRAMEWORKS_BRIDGE_DECLARATIVE_FRONTEND_JS_VIEW_JS_MENU_H