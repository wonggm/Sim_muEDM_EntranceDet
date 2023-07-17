# Sim_muEDM_EntranceDet
Entrance detector simulation for muEDM with Geant4-based musrSim.\
These simulations study the entrance detector performance and evaluates beam test measurement results.
- **`100masterWithAPD.mac`**: macro file containing instrument setup information
- `visVRML.mac`: macro file outputting `.wrl` for event display
- `*.stl`: AUTOCAD files for rack and holder geometries
### Running on INPAC-cluster
For simulations with high statistics, job submission can be done using Condor,
```
condor_submit 0condor
```
`0condor` submits job that executes `0run.sh`.\
\
In **`0run.sh`**, the path of musrSim build should be specified in **`line 9`**,
```
export PATH="$PATH:/lustre/collider/wonggm/musrSim_Twiss/build"
```

# Spring 2023
### Simulation of prototype telescope (veto) detector 
To reproduce detector measruements from PSI Beam Test 2022.
- Detector geometry based on beam test
- Optical photons collected with four sensitive device volumes attached to the rear end of the scintillator blocks
- Optical boundary processes are being defined between each surfaces

# Location of simulation ROOT output (INPAC path)
### For photon number distribution in SiPM (Spring 2023)
`ana_NPhotDist.C`\
/lustre/collider/wonggm/work/simODet/data/noTwiss_Galactic_100k.root
### For photon number distribution in scintillator channels (17072023)
`save_Dist.C`\
/lustre/collider/wonggm/work/simODet/data/musr_600.root
