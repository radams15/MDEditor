LIB_EXT=.so
EXE_EXT=
EXTRAS=

DATA_DIR=./data

FILES=src/main/main.cpp src/main/MainApp.cpp src/main/MainFrame.cpp src/main/MainFrameCust.cpp src/main/Converter.cpp src/main/Settings.cpp src/main/SettingsDlgCust.cpp ${EXTRAS}
SCIDOWN_INC=lib/scidown/src/

libscidown${LIB_EXT}:
		gcc -fPIC -shared -o libscidown${LIB_EXT} -I${SCIDOWN_INC} lib/scidown/src/charter/src/clist.c lib/scidown/src/charter/src/parser.c lib/scidown/src/charter/src/charter.c lib/scidown/src/charter/src/svg.c lib/scidown/src/charter/src/latex.c lib/scidown/src/charter/src/charter_string.c lib/scidown/src/charter/src/svg_utils.c lib/scidown/src/charter/src/tinyexpr/tinyexpr.c lib/scidown/src/charter/src/csv_parser/csvparser.c lib/scidown/src/utils.c lib/scidown/src/constants.c lib/scidown/src/autolink.c lib/scidown/src/buffer.c lib/scidown/src/document.c lib/scidown/src/escape.c lib/scidown/src/html_blocks.c lib/scidown/src/html.c lib/scidown/src/latex.c lib/scidown/src/html_smartypants.c lib/scidown/src/stack.c lib/scidown/src/version.c

app: libscidown${LIB_EXT}
	g++ -o MDEditor${EXE_EXT} -I${SCIDOWN_INC} ${FILES} `wx-config --libs --cflags` -L. -lscidown -DDATA_DIR="\"${DATA_DIR}\""