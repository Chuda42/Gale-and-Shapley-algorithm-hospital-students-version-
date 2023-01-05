# Gale-and-Shapley-algorithm-hospital-students-version-
Algorithm to resolve exercise 1.4  (Algorithm Design Jon Kleinberg, Eva Tardos)

## Solution description
The asignacion_residencias.cpp file describes the proposed solution, the others are implementation of the necessary structures provided by Fing, UdelaR

## How to start

Compile with:
```
make
```

And start the program with:
```
./principal
```

Commands:
```
leer_instancia:
  - Read from the entry the number of hospitals and the number of students.
  The values are stored in the variables "n" and "m" accordingly.
  Each student corresponds to an index between 0 and n-1.
  Each hospital corresponds to an index between 0 and m-1.
  - Read a list of slots offered by each hospital. The value at position i corresponds to
  the free spaces of hospital i and it is stored in C[i].
  - Read from the input m permutations of n students. The permutation i corresponds to the list
  of hospital preferences i. The list is stored in hPrefs[i].
  - Read from the input n permutations of m hospitals. The permutation j corresponds to the list
  of student preferences j. The list is stored in ePrefs[j].
imprimir_instancia
  Prints the data that defines the instance: "n", "m", "C", and the preference arrays
  hPrefs and ePrefs.
asignar_residencias
  It executes the function assignResidences and stores the list of result pairs in "a".
asignar_residencias_stress
  It executes the function assignStressResidences and stores the list of result pairs in "a".
  Prints the mapping stored in a.
imprimir_asignacion
  Prints the assignment stored in a, if the assignment is empty returns the message
  "La asignación es vacía." The pairs are printed in increasing order by index
  of student. If a student e_i was free, the pair (e_i, libre) is printed.
Fin
  Close the program.
```
Run some test:
```
make testing
```

