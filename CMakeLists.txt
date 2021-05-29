#
# Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
# Copyright (C) 2021+ WarheadCore <https://github.com/WarheadCore>
#

# Add source files
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/LowLevelArena_SC.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/LowLevelArena.cpp")
AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/LowLevelArena.h")

# Add scripts to script loader
AC_ADD_SCRIPT_LOADER("LowLevelArena" "${CMAKE_CURRENT_LIST_DIR}/src/low_level_arena_loader.h")

# Add config file
AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/LowLevelArena.conf.dist")
