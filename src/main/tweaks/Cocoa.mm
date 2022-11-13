
#import <Cocoa/Cocoa.h>

extern "C" void tweak(void* window){
#ifdef MAC_OS_X_VERSION_10_10

    NSWindow* win = (NSWindow*) window;

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

extern "C" const char* getResourcePath(const char* file){
    NSBundle* bundle = [NSBundle mainBundle];

    NSString* nsFile = [NSString stringWithUTF8String:(file)];

    NSString* fileName = [[nsFile lastPathComponent] stringByDeletingPathExtension];
    NSString* extension = [nsFile pathExtension];

    NSString* path = [bundle pathForResource:fileName ofType:extension];

    //NSLog(@"Path for %@: %@\n", nsFile, path);

    return [path UTF8String];
}