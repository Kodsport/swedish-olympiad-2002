#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution joshua.cpp

samplegroup
sample 1
sample 2

group group1 100
include_group sample
tc_manual markant1
tc_manual markant2
tc_manual markant3
