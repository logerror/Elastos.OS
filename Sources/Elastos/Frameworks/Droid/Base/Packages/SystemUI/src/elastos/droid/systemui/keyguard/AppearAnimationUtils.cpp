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

#include "elastos/droid/systemui/keyguard/AppearAnimationUtils.h"
#include "Elastos.Droid.Animation.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.View.h"
#include "elastos/droid/R.h"
#include <elastos/core/Math.h>
#include "R.h"

using Elastos::Droid::Animation::ITimeInterpolator;
using Elastos::Droid::Content::Res::IResources;
using Elastos::Droid::View::Animation::IAnimationUtils;
using Elastos::Droid::View::Animation::CAnimationUtils;
using Elastos::Droid::View::IViewPropertyAnimator;
using Elastos::Core::Math;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Keyguard {

AppearAnimationUtils::AppearAnimationProperties::AppearAnimationProperties()
    : mMaxDelayRowIndex(0)
    , mMaxDelayColIndex(0)
{}

const Int64 AppearAnimationUtils::DEFAULT_APPEAR_DURATION = 220;

CAR_INTERFACE_IMPL(AppearAnimationUtils, Object, IAppearAnimationCreator)

AppearAnimationUtils::AppearAnimationUtils()
    : mStartTranslation(0.0)
    , mDelayScale(0.0)
    , mDuration(0)
{
    mProperties = new AppearAnimationUtils::AppearAnimationProperties();
}

ECode AppearAnimationUtils::constructor(
    /* [in] */ IContext* ctx)
{
    AutoPtr<IAnimationUtils> helper;
    CAnimationUtils::AcquireSingleton((IAnimationUtils**)&helper);
    AutoPtr<IInterpolator> interpolator;
    helper->LoadInterpolator(ctx, Elastos::Droid::R::interpolator::linear_out_slow_in, (IInterpolator**)&interpolator);
    return constructor(ctx, DEFAULT_APPEAR_DURATION, 1.0f, 1.0f, interpolator);
}

ECode AppearAnimationUtils::constructor(
    /* [in] */ IContext* ctx,
    /* [in] */ Int64 duration,
    /* [in] */ Float translationScaleFactor,
    /* [in] */ Float delayScaleFactor,
    /* [in] */ IInterpolator* interpolator)
{
    mInterpolator = interpolator;

    AutoPtr<IResources> resources;
    ctx->GetResources((IResources**)&resources);
    Int32 offset;
    resources->GetDimensionPixelOffset(R::dimen::appear_y_translation_start, &offset);
    mStartTranslation = offset * translationScaleFactor;
    mDelayScale = delayScaleFactor;
    mDuration = duration;
    return NOERROR;
}

ECode AppearAnimationUtils::StartAppearAnimation(
    /* [in] */ ArrayOf<ArrayOf<IInterface*>* >* objects,
    /* [in] */ IRunnable* finishListener)
{
    return StartAppearAnimation(objects, finishListener, (IAppearAnimationCreator*)this);
}

ECode AppearAnimationUtils::StartAppearAnimation(
    /* [in] */ ArrayOf<IInterface*>* objects,
    /* [in] */ IRunnable* finishListener)
{
    return StartAppearAnimation(objects, finishListener, (IAppearAnimationCreator*)this);
}

ECode AppearAnimationUtils::StartAppearAnimation(
    /* [in] */ ArrayOf<ArrayOf<IInterface*>* >* objects,
    /* [in] */ IRunnable* finishListener,
    /* [in] */ IAppearAnimationCreator* creator)
{
    AutoPtr<AppearAnimationProperties> properties = GetDelays(objects);
    StartAnimations(properties, objects, finishListener, creator);
    return NOERROR;
}

ECode AppearAnimationUtils::StartAppearAnimation(
    /* [in] */ ArrayOf<IInterface*>* objects,
    /* [in] */ IRunnable* finishListener,
    /* [in] */ IAppearAnimationCreator* creator)
{
    AutoPtr<AppearAnimationProperties> properties = GetDelays(objects);
    StartAnimations(properties, objects, finishListener, creator);
    return NOERROR;
}

void AppearAnimationUtils::StartAnimations(
    /* [in] */ AppearAnimationProperties* properties,
    /* [in] */ ArrayOf<IInterface*>* objects,
    /* [in] */ IRunnable* finishListener,
    /* [in] */ IAppearAnimationCreator* creator)
{
    if (properties->mMaxDelayRowIndex == -1 || properties->mMaxDelayColIndex == -1) {
        finishListener->Run();
        return;
    }
    for (Int32 row = 0; row < properties->mDelays->GetLength(); row++) {
        AutoPtr<ArrayOf<Int64> > columns = (*(properties->mDelays))[row];
        Int32 delay = (*columns)[0];
        AutoPtr<IRunnable> endRunnable;
        if (properties->mMaxDelayRowIndex == row && properties->mMaxDelayColIndex == 0) {
            endRunnable = finishListener;
        }
        creator->CreateAnimation((*objects)[row], delay, mDuration,
                mStartTranslation, mInterpolator, endRunnable);
    }
}

void AppearAnimationUtils::StartAnimations(
    /* [in] */ AppearAnimationProperties* properties,
    /* [in] */ ArrayOf<ArrayOf<IInterface*>* >* objects,
    /* [in] */ IRunnable* finishListener,
    /* [in] */ IAppearAnimationCreator* creator)
{
    if (properties->mMaxDelayRowIndex == -1 || properties->mMaxDelayColIndex == -1) {
        finishListener->Run();
        return;
    }
    for (Int32 row = 0; row < properties->mDelays->GetLength(); row++) {
        AutoPtr<ArrayOf<Int64> > columns = (*(properties->mDelays))[row];
        for (Int32 col = 0; col < columns->GetLength(); col++) {
            Int64 delay = (*columns)[col];
            AutoPtr<IRunnable> endRunnable;
            if (properties->mMaxDelayRowIndex == row && properties->mMaxDelayColIndex == col) {
                endRunnable = finishListener;
            }
            AutoPtr<ArrayOf<IInterface*> > _object = (*objects)[row];
            creator->CreateAnimation((*_object)[col], delay, mDuration,
                    mStartTranslation, mInterpolator, endRunnable);
        }
    }
}

AutoPtr<AppearAnimationUtils::AppearAnimationProperties> AppearAnimationUtils::GetDelays(
    /* [in] */ ArrayOf<IInterface*>* items)
{
    Int64 maxDelay = -1;
    mProperties->mMaxDelayColIndex = -1;
    mProperties->mMaxDelayRowIndex = -1;
    mProperties->mDelays = ArrayOf<ArrayOf<Int64>* >::Alloc(items->GetLength());
    for (Int32 row = 0; row < items->GetLength(); row++) {
        AutoPtr<ArrayOf<Int64> > array = ArrayOf<Int64>::Alloc(1);
        Int64 delay = CalculateDelay(row, 0);
        (*array)[0] = delay;
        mProperties->mDelays->Set(row, array);
        if ((*items)[row] != NULL && delay > maxDelay) {
            maxDelay = delay;
            mProperties->mMaxDelayColIndex = 0;
            mProperties->mMaxDelayRowIndex = row;
        }
    }
    return mProperties;
}

AutoPtr<AppearAnimationUtils::AppearAnimationProperties> AppearAnimationUtils::GetDelays(
    /* [in] */ ArrayOf<ArrayOf<IInterface*>* >* items)
{
    Int64 maxDelay = -1;
    mProperties->mMaxDelayColIndex = -1;
    mProperties->mMaxDelayRowIndex = -1;
    mProperties->mDelays = ArrayOf<ArrayOf<Int64>* >::Alloc(items->GetLength());
    for (Int32 row = 0; row < items->GetLength(); row++) {
        AutoPtr<ArrayOf<IInterface*> > columns = (*items)[row];
        AutoPtr<ArrayOf<Int64> > array = ArrayOf<Int64>::Alloc(columns->GetLength());
        mProperties->mDelays->Set(row, array);

        for (Int32 col = 0; col < columns->GetLength(); col++) {
            Int64 delay = CalculateDelay(row, col);
            AutoPtr<ArrayOf<IInterface*> > tmp = (*items)[row];
            array->Set(col, delay);
            if ((*tmp)[col] != NULL && delay > maxDelay) {
                maxDelay = delay;
                mProperties->mMaxDelayColIndex = col;
                mProperties->mMaxDelayRowIndex = row;
            }
        }
    }
    return mProperties;
}

Int64 AppearAnimationUtils::CalculateDelay(
    /* [in] */ Int32 row,
    /* [in] */ Int32 col)
{
    return (Int64) ((row * 40 + col * (Elastos::Core::Math::Pow(row, 0.4) + 0.4) * 20) * mDelayScale);
}

ECode AppearAnimationUtils::GetInterpolator(
    /* [out] */ IInterpolator** interpolator)
{
    VALIDATE_NOT_NULL(interpolator);

    *interpolator = mInterpolator;
    REFCOUNT_ADD(*interpolator);
    return NOERROR;
}

ECode AppearAnimationUtils::GetStartTranslation(
    /* [out] */ Float* translation)
{
    VALIDATE_NOT_NULL(translation);

    *translation = mStartTranslation;
    return NOERROR;
}

ECode AppearAnimationUtils::CreateAnimation(
    /* [in] */ IInterface* obj,
    /* [in] */ Int64 delay,
    /* [in] */ Int64 duration,
    /* [in] */ Float startTranslationY,
    /* [in] */ IInterpolator* interpolator,
    /* [in] */ IRunnable* endRunnable)
{
    IView* view = IView::Probe(obj);
    if (view != NULL) {
        view->SetAlpha(0.0f);
        view->SetTranslationY(startTranslationY);

        AutoPtr<IViewPropertyAnimator> animator;
        view->Animate((IViewPropertyAnimator**)&animator);
        animator->Alpha(1.0f);
        animator->TranslationY(0);
        animator->SetInterpolator(ITimeInterpolator::Probe(interpolator));
        animator->SetDuration(duration);
        animator->SetStartDelay(delay);

        Boolean res;
        if (view->HasOverlappingRendering(&res), res) {
            AutoPtr<IViewPropertyAnimator> _animator;
            view->Animate((IViewPropertyAnimator**)&_animator);
            _animator->WithLayer();
        }
        if (endRunnable != NULL) {
            AutoPtr<IViewPropertyAnimator> _animator;
            view->Animate((IViewPropertyAnimator**)&_animator);
            _animator->WithEndAction(endRunnable);
        }
    }
    return NOERROR;
}

} // namespace Keyguard
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
