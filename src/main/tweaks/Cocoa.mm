
#import <Cocoa/Cocoa.h>

extern "C" void tweak(void* window){
#ifdef MAC_OS_X_VERSION_10_10

    auto* win = (NSWindow*) window;

#if USE_HEADERBAR
    win.titleVisibility = NSWindowTitleHidden;

    win.titlebarAppearsTransparent = true;
#endif

    NSToolbar* toolbar = win.toolbar;
    if(toolbar != nullptr){
        toolbar.showsBaselineSeparator = false;
    }
#endif
}