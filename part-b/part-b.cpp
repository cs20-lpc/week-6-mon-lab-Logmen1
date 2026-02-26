#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int numDisks, string source, string buffer, string target, int& numMoves){
    // Base case
    if (numDisks == 1)
    {
        cout << "Moving disc 1 from rod #"
            << source << " to rod #"
            << target << endl;

        numMoves++;
        return;
    }

    // Step 1: Move n-1 disks from source to buffer
    towerHanoi(numDisks - 1, source, target, buffer, numMoves);

    // Step 2: Move largest disk to target
    cout << "Moving disc " << numDisks
        << " from rod #" << source
        << " to rod #" << target << endl;

    numMoves++;

    // Step 3: Move n-1 disks from buffer to target
    towerHanoi(numDisks - 1, buffer, source, target, numMoves);
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}
