#!/bin/bash

#make app

#mkdir -p macbuild

#cd macbuild

mkdir -p MDEditor.app/Contents/Frameworks
#mkdir -p MDEditor.app/Contents/MacOS

#cp ../MDEditor MDEditor.app/Contents/MacOS
#cp ../libscidown.dylib MDEditor.app/Contents/Frameworks
#install_name_tool -change libscidown.dylib @executable_path/../Frameworks/libscidown.dylib MDEditor.app/Contents/MacOS/MDEditor

cp lib/scidown/libscidown.dylib MDEditor.app/Contents/Frameworks
cp ../res/MDEditor.icns MDEditor.app/Contents/Resources/
install_name_tool -change @rpath/libscidown.dylib @executable_path/../Frameworks/libscidown.dylib MDEditor.app/Contents/MacOS/MDEditor
