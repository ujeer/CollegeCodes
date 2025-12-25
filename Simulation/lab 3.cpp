#include <stdio.h>

int main() {
    printf("\n By Reeju Pandit\n");

 
    float arrival_rate = 1.0;       // ? = 1 customer per minute
    float service_time = 20.0 / 60; // 20 seconds = 0.333 minutes
    float service_rate = 1.0 / service_time; // µ = 3 per minute
    float walking_time = 1.5;       // time to seat after ticket
    float arrival_before_game = 2.0; // fan arrives 2 minutes early

    
    float rho = arrival_rate / service_rate;

    // Waiting time in queue using M/M/1 formula: Wq = ? / (µ - ?)
    float waiting_time = rho / (service_rate - arrival_rate);

    // Total time = waiting + service + walking
    float total_time = waiting_time + service_time + walking_time;

    // Output
    printf("\n--- Football Stadium Ticket Queue ---\n");
    printf("Waiting time in queue     : %.2f minutes\n", waiting_time);
    printf("Ticket purchase time      : %.2f minutes\n", service_time);
    printf("Time to reach seat        : %.2f minutes\n", walking_time);
    printf("Total time before seated  : %.2f minutes\n", total_time);

    // Will the fan make it before kickoff?
    if (total_time <= arrival_before_game) {
        printf("\n? Yes, the fan can be seated before kick-off!\n");
    } else {
        printf("\n? No, the fan will miss the kick-off.\n");
    }

    return 0;
}

