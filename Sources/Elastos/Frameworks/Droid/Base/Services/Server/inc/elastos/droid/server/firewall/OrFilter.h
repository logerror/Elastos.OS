/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.server.firewall;

using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Content::IIntent;
using Org::Xmlpull::V1::IXmlPullParser;
using Org::Xmlpull::V1::IXmlPullParserException;

using Elastos::IO::IIOException;

class OrFilter extends FilterList {
    //@Override
    public Boolean Matches(IntentFirewall ifw, ComponentName resolvedComponent, Intent intent,
            Int32 callerUid, Int32 callerPid, String resolvedType, Int32 receivingUid) {
        for (Int32 i=0; i<children->Size(); i++) {
            if (children->Get(i).Matches(ifw, resolvedComponent, intent, callerUid, callerPid,
                    resolvedType, receivingUid)) {
                return TRUE;
            }
        }
        return FALSE;
    }

    public static const FilterFactory FACTORY = new FilterFactory("or") {
        //@Override
        public Filter NewFilter(XmlPullParser parser)
                throws IOException, XmlPullParserException {
            return new OrFilter()->ReadFromXml(parser);
        }
    };
}