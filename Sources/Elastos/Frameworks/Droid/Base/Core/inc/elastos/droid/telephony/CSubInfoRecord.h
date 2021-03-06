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

#ifndef __ELASTOS_DROID_TELEPHONY_CSUBINFORECORD_H__
#define __ELASTOS_DROID_TELEPHONY_CSUBINFORECORD_H__

#include "_Elastos_Droid_Telephony_CSubInfoRecord.h"
#include "elastos/droid/ext/frameworkdef.h"
#include <elastos/core/Object.h>

namespace Elastos {
namespace Droid {
namespace Telephony {

CarClass(CSubInfoRecord)
    , public Object
    , public ISubInfoRecord
    , public IParcelable
{
public:
    CSubInfoRecord();

    virtual ~CSubInfoRecord();

    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ Int64 subId,
        /* [in] */ const String& iccId,
        /* [in] */ Int32 slotId,
        /* [in] */ const String& displayName,
        /* [in] */ Int32 nameSource,
        /* [in] */ Int32 color,
        /* [in] */ const String& number,
        /* [in] */ Int32 displayFormat,
        /* [in] */ Int32 roaming,
        /* [in] */ ArrayOf<Int32>* iconRes,
        /* [in] */ Int32 mcc,
        /* [in] */ Int32 mnc,
        /* [in] */ Int32 status,
        /* [in] */ Int32 nwMode);

    CARAPI ReadFromParcel(
        /* [in] */ IParcel* source);

    CARAPI WriteToParcel(
        /* [in] */ IParcel* dest);

    CARAPI ToString(
        /* [out] */ String* str);

    CARAPI SetSubId(
        /* [in] */ Int64 subId);

    CARAPI GetSubId(
        /* [out] */ Int64* subId);

    CARAPI SetIccId(
        /* [in] */ const String& iccId);

    CARAPI GetIccId(
        /* [out] */ String* iccId);

    CARAPI SetSlotId(
        /* [in] */ Int32 slotId);

    CARAPI GetSlotId(
        /* [out] */ Int32* slotId);

    CARAPI SetDisplayName(
        /* [in] */ const String& displayName);

    CARAPI GetDisplayName(
        /* [out] */ String* displayName);

    CARAPI SetNameSource(
        /* [in] */ Int32 nameSource);

    CARAPI GetNameSource(
        /* [out] */ Int32* nameSource);

    CARAPI SetColor(
        /* [in] */ Int32 color);

    CARAPI GetColor(
        /* [out] */ Int32* color);

    CARAPI SetNumber(
        /* [in] */ const String& number);

    CARAPI GetNumber(
        /* [out] */ String* number);

    CARAPI SetDisplayNumberFormat(
        /* [in] */ Int32 displayNumberFormat);

    CARAPI GetDisplayNumberFormat(
        /* [out] */ Int32* displayNumberFormat);

    CARAPI SetDataRoaming(
        /* [in] */ Int32 dataRoaming);

    CARAPI GetDataRoaming(
        /* [out] */ Int32* dataRoaming);

    CARAPI SetSimIconRes(
        /* [in] */ ArrayOf<Int32>* res);

    CARAPI GetSimIconRes(
        /* [out, callee] */ ArrayOf<Int32>** res);

    CARAPI SetMcc(
        /* [in] */ Int32 mcc);

    CARAPI GetMcc(
        /* [out] */ Int32* mcc);

    CARAPI SetMnc(
        /* [in] */ Int32 mnc);

    CARAPI GetMnc(
        /* [out] */ Int32* mnc);

    CARAPI SetStatus(
        /* [in] */ Int32 status);

    CARAPI GetStatus(
        /* [out] */ Int32* status);

    CARAPI SetNwMode(
        /* [in] */ Int32 nwMode);

    CARAPI GetNwMode(
        /* [out] */ Int32* nwMode);

public:
    /**
     * Subscription Identifier, this is a device unique number
     * and not an index into an array
     */
    Int64 mSubId;
    /** The GID for a SIM that maybe associated with this subscription, empty if unknown */
    String mIccId;
    /**
     * The slot identifier for that currently contains the subscription
     * and not necessarily unique and maybe INVALID_SLOT_ID if unknown
     */
    Int32 mSlotId;
    /**
     * The string displayed to the user that identifies this subscription
     */
    String mDisplayName;
    /**
     * The source of the name, NAME_SOURCE_UNDEFINED, NAME_SOURCE_DEFAULT_SOURCE,
     * NAME_SOURCE_SIM_SOURCE or NAME_SOURCE_USER_INPUT.
     */
    Int32 mNameSource;
    /**
     * The color to be used for when displaying to the user
     */
    Int32 mColor;
    /**
     * A number presented to the user identify this subscription
     */
    String mNumber;
    /**
     * How to display the phone number, DISPLAY_NUMBER_NONE, DISPLAY_NUMBER_FIRST,
     * DISPLAY_NUMBER_LAST
     */
    Int32 mDisplayNumberFormat;
    /**
     * Data roaming state, DATA_RAOMING_ENABLE, DATA_RAOMING_DISABLE
     */
    Int32 mDataRoaming;
    /**
     * SIM Icon resource identifiers. FIXME: Check with MTK what it really is
     */
    AutoPtr<ArrayOf<Int32> > mSimIconRes;
    /**
     * Mobile Country Code
     */
    Int32 mMcc;
    /**
     * Mobile Network Code
     */
    Int32 mMnc;

    Int32 mStatus;

    Int32 mNwMode;
};

} // namespace Telephony
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TELEPHONY_CSUBINFORECORD_H__
