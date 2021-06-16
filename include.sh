#!/usr/bin/env bash

LLA_PATH_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $LLA_PATH_ROOT"/conf/conf.sh.dist"

if [ -f $LLA_PATH_ROOT"/conf/conf.sh" ]; then
    source $LLA_PATH_ROOT"/conf/conf.sh"
fi
