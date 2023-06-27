#! /bin/bash

#loadlcg
source /cvmfs/sft.cern.ch/lcg/contrib/gcc/10/x86_64-centos7-gcc10-opt/setup.sh
source /cvmfs/geant4.cern.ch/geant4/11.0.p02/x86_64-centos7-gcc10-optdeb-MT/CMake-setup.sh
source /cvmfs/sft.cern.ch/lcg/releases/LCG_100/CMake/3.20.0/x86_64-centos7-gcc10-opt/CMake-env.sh
source /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh

export PATH="$PATH:/lustre/collider/wonggm/musrSim_Twiss/build"
echo "musrSim path: " $(which musrSim)

musrSim 100masterWithAPC.mac
