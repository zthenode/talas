########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: starad.pri
#
# Author: $author$
#   Date: 11/7/2021
#
# QtCreator .pri file for talas executable starad
########################################################################

########################################################################
# starad

# starad TARGET
#
starad_TARGET = starad

# starad INCLUDEPATH
#
starad_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# starad DEFINES
#
starad_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# starad OBJECTIVE_HEADERS
#
#starad_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/network/sockets/base/main.hh \

# starad OBJECTIVE_SOURCES
#
#starad_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/network/sockets/base/main.mm \

########################################################################
# starad HEADERS
#
starad_HEADERS += \
$${TALAS_SRC}/xos/app/console/network/sockets/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/base/main.hpp \
\
$${TALAS_SRC}/xos/app/console/network/sockets/client/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/client/main.hpp \
\
$${TALAS_SRC}/xos/app/console/network/sockets/server/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/network/sockets/server/main.hpp \

# starad SOURCES
#
starad_SOURCES += \
$${TALAS_SRC}/xos/app/console/network/sockets/server/main_opt.cpp \
$${TALAS_SRC}/xos/app/console/network/sockets/server/main.cpp \

########################################################################
# starad FRAMEWORKS
#
starad_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# starad LIBS
#
starad_LIBS += \
$${talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core
