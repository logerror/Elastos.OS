
#ifndef __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDMULTIUSERSELECTORVIEW_H__
#define __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDMULTIUSERSELECTORVIEW_H__

#include "_Elastos_Droid_SystemUI_Keyguard_CKeyguardMultiUserSelectorView.h"
#include <elastos/droid/widget/FrameLayout.h>

using Elastos::Droid::Widget::FrameLayout;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Keyguard {

CarClass(CKeyguardMultiUserSelectorView)
    , public FrameLayout
    , public IViewOnClickListener
{
private:
    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("CKeyguardMultiUserSelectorView::MyRunnable")

        MyRunnable(
            /* [in] */ CKeyguardMultiUserSelectorView* host);
            : mHost(host)
        {}

        //@Override
        CARPAI Run();

    private:
        CKeyguardMultiUserSelectorView* mHost;
    };

    class MyRunnable2
        : public Runnable
    {
    public:
        TO_STRING_IMPL("CKeyguardMultiUserSelectorView::MyRunnable")

        MyRunnable2(
            /* [in] */ CKeyguardMultiUserSelectorView* host,
            /* [in] */ IKeyguardMultiUserAvatar* avatar)
            : mHost(host)
            , mAvatar(avatar)
        {}

        //@Override
        CARPAI Run();

    private:
        CKeyguardMultiUserSelectorView* mHost;
        AutoPtr<IKeyguardMultiUserAvatar> mAvatar;
    };

    class TaskComparator
        : public Object
        , public IComparator
    {
    public:
        TO_STRING_IMPL("CKeyguardMultiUserSelectorView::TaskComparator")

        CAR_INTERFACE_DECL()

        // @Override
        CARAPI Compare(
            /* [in] */ IInterface* _task,
            /* [in] */ IInterface* _task2,
            /* [out] */ Int32* result);
    };

public:
    CAR_OBJECT_DECL()

    CKeyguardMultiUserSelectorView();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyle);

    CARAPI SetCallback(
        /* [in] */ IKeyguardHostViewUserSwitcherCallback* callback);

    CARAPI AddUsers(
        /* [in] */ ICollection* userList);

    CARAPI FinalizeActiveUserView(
        /* [in] */ Boolean animate);

    CARAPI FinalizeActiveUserNow(
        /* [in] */ Boolean animate);

    //@Override
    CARAPI OnInterceptTouchEvent(
        /* [in] */ IMotionEvent* event,
        /* [out] */ Boolean* result);

    //@Override
    CARAPI OnClick(
        /* [in] */ IView* v);

protected:
    CARAPI OnFinishInflate();

private:
    CARAPI_(AutoPtr<IKeyguardMultiUserAvatar>) CreateAndAddUser(
        /* [in] */ IUserInfo* user);

    CARAPI_(void) SetAllClickable(
        /* [in] */ Boolean clickable);

private:
    static const String TAG;

    AutoPtr<IViewGroup> mUsersGrid;
    AutoPtr<IKeyguardMultiUserAvatar> mActiveUserAvatar;
    AutoPtr<IKeyguardHostViewUserSwitcherCallback> mCallback;
    static const Int32 FADE_OUT_ANIMATION_DURATION;

    AutoPtr<IComparator> mOrderAddedComparator;
};

} // namespace Keyguard
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDMULTIUSERSELECTORVIEW_H__