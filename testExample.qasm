// test circuit on 4 qubits

OPENQASM 2.0;
include "qelib1.inc";

// Register declarations
qreg q[5];
creg c[4];

// Choose starting state
// ** Put your code here **

h q[0];
cx q[1],q[0];
cx q[0],q[2];
cx q[0],q[3];
cx q[1],q[2];
cx q[1],q[3];
cx q[1],q[2];
cx q[2],q[3];
cx q[0],q[1];
cx q[2],q[0];
