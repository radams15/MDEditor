LIB_EXT=.dylib
EXE_EXT=
EXTRAS=src/main/tweaks/Cocoa.mm
CFLAGS=-isysroot /Developer/SDKs/MacOSX10.4u.sdk -mmacosx-version-min=10.3
#CFLAGS=-isysroot /Developer/SDKs/MacOSX10.5.sdk -mmacosx-version-min=10.4
#CFLAGS=

WX_VERS=2.8

VERS=0.2.1
NAME=MDEditor

FILES=src/main/main.cpp src/main/MainApp.cpp src/main/MainFrame.cpp src/main/MainFrameCust.cpp src/main/Converter.cpp src/main/Settings.cpp src/main/SettingsDlgCust.cpp ${EXTRAS}
SCIDOWN_INC=lib/scidown/src/

libscidown:
	mkdir -p MDEditor.app/Contents/Frameworks
	gcc -fPIC -dynamiclib ${CFLAGS} -o MDEditor.app/Contents/Frameworks/libscidown.dylib -I${SCIDOWN_INC} lib/scidown/src/charter/src/clist.c lib/scidown/src/charter/src/parser.c lib/scidown/src/charter/src/charter.c lib/scidown/src/charter/src/svg.c lib/scidown/src/charter/src/latex.c lib/scidown/src/charter/src/charter_string.c lib/scidown/src/charter/src/svg_utils.c lib/scidown/src/charter/src/tinyexpr/tinyexpr.c lib/scidown/src/charter/src/csv_parser/csvparser.c lib/scidown/src/utils.c lib/scidown/src/constants.c lib/scidown/src/autolink.c lib/scidown/src/buffer.c lib/scidown/src/document.c lib/scidown/src/escape.c lib/scidown/src/html_blocks.c lib/scidown/src/html.c lib/scidown/src/latex.c lib/scidown/src/html_smartypants.c lib/scidown/src/stack.c lib/scidown/src/version.c

resources:
	mkdir -p MDEditor.app/Contents/Resources
	cp res/Info.plist MDEditor.app/Contents/
	cp -r data/* MDEditor.app/Contents/Resources/
	cp res/MDEditor.icns MDEditor.app/Contents/Resources/

app: libscidown
	mkdir -p MDEditor.app/Contents/MacOS
	g++ ${CFLAGS} -o MDEditor.app/Contents/MacOS/MDEditor -I${SCIDOWN_INC} ${FILES} `wx-config --libs --cflags --version=${WX_VERS}` -LMDEditor.app/Contents/Frameworks/ -lscidown

tweak: resources
	cat MDEditor.app/Contents/Info.plist | sed 's/$${MACOSX_BUNDLE_GUI_IDENTIFIER}/uk.co.therhys.${NAME}/g' > MDEditor.app/Contents/Info.plist
	cat MDEditor.app/Contents/Info.plist | sed 's/$${MACOSX_BUNDLE_BUNDLE_NAME}/${NAME}/g' > MDEditor.app/Contents/Info.plist
	cat MDEditor.app/Contents/Info.plist | sed 's/$${MACOSX_BUNDLE_SHORT_VERSION_STRING}/${VERS}/g' > MDEditor.app/Contents/Info.plist
	cat MDEditor.app/Contents/Info.plist | sed 's/$${MACOSX_BUNDLE_BUNDLE_VERSION}/${VERS}/g' > MDEditor.app/Contents/Info.plist

MDEditor.app: app tweak
	install_name_tool -change 'MDEditor.app/Contents/Frameworks/libscidown.dylib' '@executable_path/../Frameworks/libscidown.dylib' MDEditor.app/Contents/MacOS/MDEditor

