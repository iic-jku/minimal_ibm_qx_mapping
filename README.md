## A tool to map quantum circuits to the IBM QX architecture using the minimal number of SWAP and H operations (developed in C++)
Copyright (c) 2019
by Robert Wille (robert.wille@jku.at), Lukas Burgholzer (lukas.burgholzer@jku.at) and Alwin Zulehner (alwin.zulehner@jku.at)
Johannes Kepler University Linz, Austria
http://iic.jku.at/eda/research/ibm_qx_mapping/

The software is intellectual property of the above mentioned authors. You 
can freely redistribute this software for non-commercial purposes as long as 
it includes a reference to its origin.

Use at your own risk!
In no event shall the authors be liable for any 
damages whatsoever (including without limitation damages for loss of business 
profits, business interruption, loss of business information, or any other 
pecuniary loss) arising from the use of or inability to use the software, even 
if the authors have been advised of the possibility of such 
damages.

If you have any questions feel free to contact us using
robert.wille@jku.at, lukas.burgholzer@jku.at, alwin.zulehner@jku.at

## Overview

The recent progress in the physical realization of quantum computers (the first publicly available ones—IBM’s QX architectures—have been launched in 2017) has motivated research on automatic methods that aid users in running quantum circuits on them. Here, certain physical constraints given by the architectures which restrict the allowed interactions of the involved qubits have to be satisfied.
 
Thus far, this has been addressed by inserting SWAP and H operations. However, it remains unknown whether existing methods add a minimum number of SWAP and H operations or, if not, how far they are away from that minimum—an NP-complete problem. 
 
This tool addresses this by formulating the mapping task as a symbolic optimization problem that is solved using the Z3 theorem solver. While only applicable for circuits with a small number of qubits, experimental evaluations show that the number of operations added by IBM’s heuristic solution exceeds the lower bound obtained with the proposed approach by more than 100% on average.

## Usage

### System Requirements 

The package has been tested under Linux (Ubuntu 18.10, 64-bit) and should be compatible with any current version of g++/cmake.
Additionally the following packages are required:
* The Z3 Theorem Solver: https://github.com/Z3Prover/z3
* MPFR: https://www.mpfr.org
* MPFRC++ Header: included with this package
* qelib.inc Gate Library: included with this package
  
### Build and Run 

To build the mapping tool type

    mkdir build
    cd build 
    cmake ..
    make
    cd ..
    
It is important to include the `qelib1.inc` file in the build directory in order to allow the parser to find the gate declarations.

Executing ``./build/minimal_ibm_qx_mapping`` runs the mapping task for the provided test circuit
mapped to IBM's QX4; showing the results for all available strategies. 

To run your own computations for mapping to IBM's QX4, either execute ``/build/minimal_ibm_qx_mapping <input file>`` or specify the filename in ``main.cpp``.

The strategy to use can be configured in ``main.cpp``

To run the mapping task for a different architecture, specify the architectures' coupling map, as well as the correspondingly required number of SWAP gates for each permutation in ``main.cpp``.

## Reference

If you use our mapping algorithm for your research, we would be thankful if you referred to it
by citing the following publication: 
````
@inproceedings{wille2019mapping,
    title={Mapping Quantum Circuits to {IBM QX} Architectures Using the Minimal Number of {SWAP} and {H} Operations},
    author={Wille, Robert and Burgholzer, Lukas and Zulehner, Alwin},
    booktitle={Design Automation Conference},
    year={2019}
}
````
