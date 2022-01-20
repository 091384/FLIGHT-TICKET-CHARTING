#include <stdio.h>
#include <string.h>

enum AIRPORTS {DXB=1, NYC, MAA, DEL};
enum GENDER {MALE=1, FEMALE};
char AirportList[] = "\t\t1.Dubai\n\t\t2.New York City\n\t\t3.Madras\n\t\t4.Delhi\n";
const int AirportTravelCost[4] = {100, 2000 , 3000, 400};

int inputInteger(const char prompt[], int start, int end) {
    int input;
    while (1){
        printf("%s",prompt);
        printf("\tEnter integer (%d - %d) : ", start, end);
        scanf("%d", &input);
        if (input >= start && input <= end){
            break;
        }else{
            printf("Sorry invalid input please enter a input between %d -> %d \n", start, end);
        }
    }
    return input;
}

const char* getAirport (enum AIRPORTS airportCode) {
    switch (airportCode)
    {
    case DXB :
        return "Dubai"; 
        break;
    case NYC :
        return "New York City";
        break;
    case  MAA : 
        return "Madras, India";
        break;
    case DEL : 
        return "Delhi, India";
        break;    
    default:
        return "ERROR !";
        break;
    }

}

const char* getTitle (enum GENDER gender) {
    switch (gender)
    {
    case MALE :
        return "Mr.";
    case FEMALE : 
        return "Mrs.";
    default:
        return "Error";
    }
}

int calculateTravelCost (enum AIRPORTS arrival, enum AIRPORTS destination){
    return AirportTravelCost[arrival-1] + AirportTravelCost[destination-1];
}

int main() {
    int counter;
    int passengers =0;
    char name[30];
    int age;
    
    enum GENDER pGender; 

    enum AIRPORTS arrival;
    enum AIRPORTS departure;
    printf("Flight Management System  \n Enter the number of passengers to Handle : ");
    scanf("%d", &passengers);
    for (int counter=0; counter<passengers; counter++){
        printf("\n\nEnter details for Passenger : %d \n", counter+1);
        
        printf("\t1. Passenger name : ");
        scanf("%s", name);

        // char prompt[] = "\t Passenger Gender : \n\t\t1.Male\n\t\t2.Female";
        pGender = (enum GENDER) inputInteger("\t2. Passenger Gender : \n\t\t1.Male\n\t\t2.Female\n", 1, 2);

        // char prompt[] = "\tPassenger age : ";
        age = inputInteger("\t3. Passenger age", 1, 100);
        
        char promptDeparture[100] = "\t4. Choose departure airport \n";
        departure = (enum AIRPORTS) inputInteger( strcat(promptDeparture, AirportList), 1, 4);
        
        char promptArrival[100] = "\t5. Choose destination airport \n";
        arrival = (enum AIRPORTS) inputInteger( strcat(promptArrival, AirportList), 1, 4);
        
        printf("Flight Booked, Travel Summary :\n");
        printf("1. Flight booked for %s%s\n", getTitle(pGender), name);
        printf("2. Passenger age is : %d\n", age);
        printf("3. Departure Airport : %s\n", getAirport(departure));
        printf("4. Arrival Airport : %s\n", getAirport(arrival));
        printf("5. Total Travel Cost : %d\n", calculateTravelCost(arrival, departure));
    }
    
    return 0;
}




