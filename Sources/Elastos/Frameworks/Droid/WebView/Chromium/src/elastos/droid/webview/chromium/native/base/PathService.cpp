//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "elastos/droid/webkit/webview/chromium/native/base/PathService.h"
#include "elastos/droid/webkit/webview/chromium/native/base/api/PathService_dec.h"

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Base {

const Int32 PathService::DIR_MODULE;

// Prevent instantiation.
PathService::PathService()
{
}

void PathService::Override(
    /* [in] */ Int32 what,
    /* [in] */ const String& path)
{
    NativeOverride(what, path);
}

void PathService::NativeOverride(
    /* [in] */ Int32 what,
    /* [in] */ const String& path)
{
    Elastos_PathService_nativeOverride(what, path);
}

} // namespace Base
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos
