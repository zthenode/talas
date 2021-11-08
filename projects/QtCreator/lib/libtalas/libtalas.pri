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
#   File: libtalas.pri
#
# Author: $author$
#   Date: 11/6/2021
#
# QtCreator .pri file for talas library libtalas
########################################################################

########################################################################
# libtalas
XOS_LIB_TALAS_VERSION_BUILD_DATE = $$system(~/bin/utility/tdate)

# libtalas TARGET
#
libtalas_TARGET = talas
libtalas_TEMPLATE = lib
libtalas_CONFIG += staticlib

# libtalas INCLUDEPATH
#
libtalas_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# libtalas DEFINES
#
libtalas_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_TALAS_VERSION_BUILD_DATE=$${XOS_LIB_TALAS_VERSION_BUILD_DATE} \

########################################################################
# libtalas OBJECTIVE_HEADERS
#
#libtalas_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/talas/app/console/talas/main.hh \

# libtalas OBJECTIVE_SOURCES
#
#libtalas_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/talas/app/console/talas/main.mm \

########################################################################
# libtalas HEADERS
#
libtalas_HEADERS += \
$${TALAS_SRC}/xos/lib/talas/version.hpp \

# libtalas SOURCES
#
libtalas_SOURCES += \
$${TALAS_SRC}/xos/lib/talas/version.cpp \

########################################################################


