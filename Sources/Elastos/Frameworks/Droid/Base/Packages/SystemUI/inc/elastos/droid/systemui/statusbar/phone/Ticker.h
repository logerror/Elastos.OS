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

#ifndef __ELASTOS_DROID_SYSTEMUI_STATUSBAR_PHONE_PHONE_TICKER_H__
#define __ELASTOS_DROID_SYSTEMUI_STATUSBAR_PHONE_PHONE_TICKER_H__

#include "_Elastos.Droid.SystemUI.h"
#include <elastos/core/Runnable.h>
#include <elastos/core/Object.h>
#include <elastos/utility/etl/List.h>

using Elastos::Droid::Content::IContext;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Os::IHandler;
using Elastos::Core::Runnable;
using Elastos::Droid::Service::Notification::IStatusBarNotification;
using Elastos::Droid::Text::IStaticLayout;
using Elastos::Droid::Text::ITextPaint;
using Elastos::Droid::View::IView;
using Elastos::Droid::Widget::ITextSwitcher;
using Elastos::Droid::Widget::IImageSwitcher;
using Elastos::Core::ICharSequence;
using Elastos::Core::IRunnable;
using Elastos::Core::Object;
using Elastos::Utility::Etl::List;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {
namespace Phone {

class Ticker: public Object
{
private:
    class Segment : public Object
    {
    public:
        Segment(
            /* [in] */ IStatusBarNotification* n,
            /* [in] */ IDrawable* icon,
            /* [in] */ ICharSequence* text,
            /* [in] */ Ticker* host);

        AutoPtr<IStaticLayout> GetLayout(
            /* [in] */ ICharSequence* substr);

        AutoPtr<ICharSequence> Rtrim(
            /* [in] */ ICharSequence* substr,
            /* [in] */ Int32 start,
            /* [in] */ Int32 end);

        /** returns null if there is no more text */
        AutoPtr<ICharSequence> GetText();

        /** returns null if there is no more text */
        AutoPtr<ICharSequence> Advance();

    public:
        AutoPtr<IStatusBarNotification> mNotification;
        AutoPtr<IDrawable> mIcon;
        AutoPtr<ICharSequence> mText;
        Int32 mCurrent;
        Int32 mNext;
        Boolean mFirst;
        Ticker* mHost;
    };

    class  AdvanceTickerRunnable : public Runnable
    {
    public:
        AdvanceTickerRunnable(
            /* [in] */ Ticker* ticker);

        CARAPI Run();

    private:
        Ticker* mHost;
    };

public:
    static Boolean IsGraphicOrEmoji(
        /* [in] */ Char32 c);

    Ticker();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IView* sb);

    CARAPI AddEntry(
        /* [in] */ IStatusBarNotification* n);

    CARAPI RemoveEntry(
        /* [in] */ IStatusBarNotification* n);

    CARAPI Halt();

    CARAPI ReflowText();

    virtual CARAPI TickerStarting() = 0;

    virtual CARAPI TickerDone() = 0;

    virtual CARAPI TickerHalting() = 0;

private:
    CARAPI_(void) ScheduleAdvance();

    static CARAPI_(Boolean) CharSequencesEqual(
        /* [in] */ ICharSequence* a,
        /* [in] */ ICharSequence* b);

private:
    static const Int32 TICKER_SEGMENT_DELAY;

    AutoPtr<IContext> mContext;
    AutoPtr<IHandler> mHandler;// = new Handler();
    AutoPtr<IRunnable> mAdvanceTicker;
    List<AutoPtr<Segment> > mSegments;// = new ArrayList();
    AutoPtr<ITextPaint> mPaint;
    AutoPtr<IView> mTickerView;
    AutoPtr<IImageSwitcher> mIconSwitcher;
    AutoPtr<ITextSwitcher> mTextSwitcher;
    Float mIconScale;
};

}// namespace Phone
}// namespace StatusBar
}// namespace SystemUI
}// namespace Droid
}// namespace Elastos

#endif //__ELASTOS_DROID_SYSTEMUI_STATUSBAR_PHONE_PHONE_TICKER_H__
