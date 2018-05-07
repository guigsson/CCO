QT -= gui

CONFIG += qt c++11
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += src/

SOURCES += \
    src/main.cpp \
    src/model/checkin.cpp \
    src/model/neighborhood.cpp \
    src/model/pointofinterest.cpp \
    src/model/trajectory.cpp \
    src/model/user.cpp \
    src/utility/csvloader.cpp \
    src/utility/ellipsisproximityalgorithm.cpp \

HEADERS += \
    src/model/checkin.h \
    src/model/neighborhood.h \
    src/model/pointofinterest.h \
    src/model/trajectory.h \
    src/model/user.h \
    src/utility/csvloader.h \
    src/utility/ellipsisproximityalgorithm.h \
    src/utility/graph.h \
    src/utility/proximityalgorithm.h \

DISTFILES += \
    resources/tuesday.csv \
    resources/testloader.csv \
    resources/checkins_foursquare_50.csv


#test {
#QT += testlib

## SOURCES -= main.cpp
#SOURCES += \
#    test/testcsvloader.cpp \
#    test/testellipsisproximityalgorithm.cpp \
#    test/testgraph.cpp \
#    test/testneighborhood.cpp \
#    test/testpointofinterest.cpp \
#    test/testuser.cpp \
#    test/main.cpp

#HEADERS += \
#    test/testcsvloader.h \
#    test/testellipsisproximityalgorithm.h \
#    test/testgraph.h \
#    test/testneighborhood.h \
#    test/testpointofinterest.h \
#    test/testuser.h \
#}
