
#include "elastos/droid/dialer/dialpad/CUnicodeDialerKeyListenerHelper.h"
#include "elastos/droid/dialer/dialpad/UnicodeDialerKeyListener.h"

namespace Elastos {
namespace Droid {
namespace Dialer {
namespace Dialpad {

CAR_INTERFACE_IMPL(CUnicodeDialerKeyListenerHelper, Singleton, IUnicodeDialerKeyListenerHelper);

CAR_SINGLETON_IMPL(CUnicodeDialerKeyListenerHelper);

ECode CUnicodeDialerKeyListenerHelper::GetINSTANCE(
    /* [out] */ IUnicodeDialerKeyListener** instance)
{
    VALIDATE_NOT_NULL(instance);
    *instance = UnicodeDialerKeyListener::INSTANCE;
    REFCOUNT_ADD(*instance);
    return NOERROR;
}

} // Dialpad
} // Dialer
} // Droid
} // Elastos