#include <iostream>
#include "queueing_ll.h"

int main(){
    Printer officePrinter;

    //Adding jobs 
    officePrinter.addjob(101, "Alice", 15);
    officePrinter.addjob(102, "Bob", 3);
    officePrinter.addjob(103, "Charlie", 22);

    //Display queue
    officePrinter.displayQueue();

    //Processing job
    std::cout << "\nProcessing current job...\n";
    officePrinter.processNextJob();

    //Display queue after job
    officePrinter.displayQueue();

    //Process remaining jobs
    officePrinter.processAllJobs();

    return 0;
} 