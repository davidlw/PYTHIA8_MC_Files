1. Download and Install 
- ROOT: https://root.cern/install/
- Fastjet 3: https://fastjet.fr/
- PYTHIA 8: https://pythia.org/

2. Go to PYTHIA 8 directory and compile:
- ./configure --with-root --with-fastjet3
- make

3. Generate events with PYTHIA 8 and save trees:
- Copy all files in this repository into the examples
- cd examples
- make EEinJet
- ./EICinJet > output

4. Analyze generated trees using code in Macros directory
