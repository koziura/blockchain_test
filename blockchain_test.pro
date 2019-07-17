TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt qml qml_debug
CONFIG += precompile_header

APP_NAME = blockchain_test

# Debug configuration
CONFIG(debug, debug|release) {
	OUTPUT_DIR = debug
	TARGET_POSTFIX = _d
	CONFIG += debug declarative_debug
}else{
	# Configuration name
	OUTPUT_DIR = release
	CONFIG += warn_off
}

TARGET = $$APP_NAME$$TARGET_POSTFIX

DESTDIR = ./bin
Release:DLLDESTDIR += ./bin

# Moc output directory
MOC_DIR = tmp/$$OUTPUT_DIR

# Resource compiler directory
RCC_DIR = tmp

# Temp objects output directory
OBJECTS_DIR = obj/$$OUTPUT_DIR

UI_DIR = tmp/ui

# Use Precompiled headers (PCH)
PRECOMPILED_HEADER += include/baserefs.h

precompile_header:!isEmpty(PRECOMPILED_HEADER) {
DEFINES += USING_PCH
}

macx {
OPENSSL_PATH = /usr/local/opt/openssl
INCLUDEPATH += \
	$$OPENSSL_PATH/include/
LIBS += \
	-L$$OPENSSL_PATH/lib/
}

INCLUDEPATH += \
	include/	\
	ver/

SOURCES += \
	src/main.cpp \
	src/transaction.cpp \
	src/block.cpp \
	src/blockchain.cpp

HEADERS += \
	include/transaction.h \
	include/block.h \
	include/blockchain.h \
	include/baserefs.h

unix: {
LIBS += \
#	-lssl \
#	-lcrypto
}
