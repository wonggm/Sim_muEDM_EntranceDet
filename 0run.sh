#! /bin/bash

#loadlcg
source /cvmfs/sft.cern.ch/lcg/views/LCG_97rc4python3/x86_64-centos7-gcc9-opt/setup.sh

# inputs
RunNum=${1}
ThicknessLabel=${2}
Thickness=${3}
BeamMomentum=${4}

# initialization
macFile=${RunNum}_${ThicknessLabel}mm_${BeamMomentum}MeV_1e4.mac
OutFile=data/musr_${RunNum}.root
OutFileRenamed=data/${RunNum}_${ThicknessLabel}mm_${BeamMomentum}MeV_1e4.root
mkdir -p data macs

# for debugging, run: ./0run.sh 101 0.1 0.05 28
echo "macfile: "${macFile}
#cat ${macFile} 
echo "output filename: "${OutFile} 
echo "output filename (renamed): "${OutFileRenamed} 
#touch ${OutFile} # test only


# print geant4 information
echo "note: this musrSim was run under lcg environment via cvmfs"
# configure and check geant4 https://www.youtube.com/watch?v=8bcQ-yQepUM
# printenv | grep G4
echo "geant4 version: " $(geant4-config --version)


# copy,edit and run macros
cp 100masterWithAPD.mac ${macFile}
sed -i "s/GateDetD  10 10 0/GateDetD  10 10 ${Thickness}/g" ${macFile}
sed -i "s/box APD1  10 0.5 0/box APD1  10 0.5 ${Thickness}/g" ${macFile}
sed -i "s/momentum 0 MeV/momentum ${BeamMomentum} MeV/g" ${macFile}
./../musrSim20210903_withBC400/build/musrSim ${macFile}


# finalizing. rename output root files
mv ${macFile} macs
mv ${OutFile} ${OutFileRenamed}