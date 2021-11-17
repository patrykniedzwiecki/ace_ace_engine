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

#include "core/components/root/rosen_render_root.h"

#include "include/core/SkColor.h"
#include "render_service_client/core/ui/rs_node.h"
#include "render_service_client/core/ui/rs_ui_director.h"

#include "core/pipeline/base/rosen_render_context.h"

namespace OHOS::Ace {

void RosenRenderRoot::Paint(RenderContext& context, const Offset& offset)
{
    LOGD("RootNode Paint");
    auto rsNode = static_cast<RosenRenderContext*>(&context)->GetRSNode();
    if (!rsNode) {
        LOGE("Paint canvas is null");
        return;
    }
    rsNode->SetBackgroundColor(bgColor_.GetValue());
    rsNode->SetPivot(0.0f, 0.0f);
    rsNode->SetScale(scale_);
    auto pipelineContext = GetContext().Upgrade();
    if (pipelineContext) {
        pipelineContext->SetRootBgColor(bgColor_);
    }
    RenderNode::Paint(context, offset);
}

} // namespace OHOS::Ace
