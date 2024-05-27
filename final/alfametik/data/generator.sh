#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution alfametik_js.cc

samplegroup
sample 1

group group1 100
include_group sample
tc_manual alfametik1
tc_manual alfametik2
tc_manual alfametik3
