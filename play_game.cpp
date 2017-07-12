#include "header.h"  //included header file

void play_game :: welcomNote()	//welcome note, only to be shown once when game starts
{
	cout<<"         ~~~~~~~~~~~Welcome to the Guess King game~~~~~~~~~~~~\n"<<endl;
}


void play_game :: Instruction()  //Instructions to be shown
{
			cout<<"        ~~~~~~~~~~~~~~~~~~~~~~~Instructions~~~~~~~~~~~~~~~~~~~\n"<<endl;
			cout<<"\t1. computer will generate a random number, range depends on your level"<<endl;
			cout<<"\t2. you have to guess the right number"<<endl;
			cout<<"\t3. on stage one, the number will be within 0 to 10"<<endl;
			cout<<"\t4. on stage two, the number will be within 0 to 50"<<endl;
			cout<<"\t5. on stage three, the number will be within 0 to 100"<<endl;
			cout<<"\t6. on every stage you get 5 lives/cances to guess the right number"<<endl;
			cout<<"\t7. you'll be told if your number is smaller or larger"<<endl;
			cout<<"\t8. if you guess the right number you'll be awareded as Guess King"<<endl;
			cout<<""<<endl;
			cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
			menu_option();
}

//used pointer in this level
bool play_game :: level_easy()  //easy level, random number between 1 to 10
								//Made different functions for different level so that its easy in future to make any changes and easier to track code crashes.
{
				srand(time(NULL));  //Generating random numbers
				int guessed;
				int randomInt = rand() % 10 +1;	
				int *RandomPtr;

				RandomPtr = &randomInt;
				
				bool loop = true;  //if returned false it will end this function

				while(loop){   //made while loop to count chances left
					int count = 4;
					cout<<"Please enter your guess between 1 to 10, you have five lives: ";
					
					while(count >=0){

						cin>>guessed;
					
						if(guessed == *RandomPtr)
							{
								cout<<"You won the Guess King Title... Congratulation!!!\n"<<endl;
								return false;
							}
						else if (guessed < *RandomPtr)
							{
								cout<<"Your entered number is smaller, Try again "<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else if(guessed >*RandomPtr)
							{
								cout<<"Your entered number is larger, try again"<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else 
						cout<<" "<<endl;
						}
					cout<<"Sorry, you counldn't be the Guess king!"<<endl;
					cout<<"\nNumber was: "<<*RandomPtr<<endl;
					return false;
				}

}

//used dynamic memory in this level
bool play_game :: level_med()  //Medium level, random number between 1 to 50
{							   //Made different functions for different level so that its easy in future to make any changes and easier to track code crashes.
				srand(time(NULL)); //random number generator
				int guessed;

				int randomInt = rand() % 50 +1;	

				int *DynaRandom;
				DynaRandom = new int(randomInt);

				bool loop = true;

				while(loop){
					int count = 4;
					cout<<"Please enter your guess between 1 to 50, you have five lives: ";
					
					while(count >=0){

						cin>>guessed;
					
						if(guessed == *DynaRandom)
							{
								cout<<"You won the Guess King Title... Congratulation!!!\n"<<endl;
								return false;
							}
						else if (guessed < *DynaRandom)
							{
								cout<<"Your entered number is smaller, Try again "<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else if(guessed >*DynaRandom)
							{
								cout<<"Your entered number is larger, try again"<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else 
						cout<<" "<<endl;
						}
					cout<<"Sorry, you counldn't be the Guess king!"<<endl;					
					cout<<"\nNumber was: "<<*DynaRandom<<endl;

					delete DynaRandom;  //deleted DynaRandom from memory
					return false;  //return false and go back to the main function 
				}
}

//used dynamic memory in this level
bool play_game :: level_high()   //high level, random number between 1 to 100
{								 //Made different functions for different level so that its easy in future to make any changes and easier to track code crashes.
		srand(time(NULL));		//random number generator
				int guessed;
				int randomInt = rand() % 100 +1;					
				bool loop = true;

				int *randomHard;
				randomHard = new int(randomInt);
				

				while(loop){
					int count = 4;
					cout<<"Please enter your guess between 1 to 100, you have five lives: ";
					
					while(count>=0){

						cin>>guessed;
					
						if(guessed == *randomHard)
							{
								cout<<"You won the Guess King Title... Congratulation!!!"<<endl;
								return false;
							}
						else if (guessed < *randomHard)
							{
								cout<<"Your entered number is smaller, Try again "<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else if(guessed > *randomHard)
							{
								cout<<"Your entered number is larger, try again"<<endl;
								cout<<"you have "<<count<<" lives left"<<endl;
								count--;
								cout<<" "<<endl;
							}
						else 
						cout<<" "<<endl;
						}
					cout<<"Sorry, you counldn't be the Guess king!"<<endl;
					cout<<"\nNumber was: "<<*randomHard<<endl;

					delete randomHard;  //deleted randomHard from memory

					return false;   //return false and go back to the main function 

				}
}

void play_game :: menu_option()   //cout main options screen
{
		
	cout<<"\n\t Please select from the below menu: "<<endl;   
	cout<<"\t\t\tPress 1: Instructions\n\t\t\tPress 2: Select level"<<endl;
	cout<<"\t\t\tPress 3: Start game\n\t\t\tPress 4: Quit\n\t\t\t";
	cin>>menu_options;
	cout_options();
}

void play_game :: cout_options()  //main game screen here
{
	
	bool menuloop = true;						//loop for game option control
		while (menuloop){		
			cout<<""<<endl;
			if(menu_options ==1)				 //Instructions wanted
			{	
				Instruction();
				//menuloop = false;
			}
			else if(menu_options ==2)				//User wants to select level
			{
				
				cout<<"\n\t Press 1 for easy.\n\t Press 2 for medium and\n\t Press 3 for Hard."<<endl;
				cin>>level_selected;

				if(level_selected == 1)				//level 1, easy
				
						
						menuloop = level_easy();
				

				else if(level_selected ==2)			//level medium
				
						menuloop = level_med();
				
				else								 //high level is Default
				
						menuloop = level_high();
					
				
			}
			
			else if(menu_options ==3)				  //default level is high, start game
			{
				menuloop = level_high(); 
			}
			
			else if(menu_options ==4)				 //quit option
			{
				exit(1);  //Quit the programme right here and right now
			}
			
			else										//else show warning message
			{
				cout<<"Invalid option!\n\n";  
				menuloop = false;
			}
			
		}
		char q;
					cout<<"Would you like to play again! (y/n)? ";
					cin>>q;
						if(q == 'Y' || q == 'y')
						{
							menu_option();
						}
						else
							menuloop =false;
												
		
		
}