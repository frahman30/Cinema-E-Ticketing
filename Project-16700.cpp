#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void Menu(void);

int editBranchAdmin(int);

void branchSearchMovie22(int,int);

void branchSearchMovie28(int,int);

void userMenu(int,int);

int Seen=0;

int Seen1=0;

int Seen2=0;

int cu=0;

char stringArrayError(string,char,char,char);

char stringArrayError2(string,char,char,char,char,char);

char stringArrayError3(string,char,char,char,char,char,char);

void adminMenu(void);

void branchAdmin(int);

void branchSearchMovie(int);

void addMovie(int);

struct returnValueOfMovieSearch
{
	int BranchIndex;
	int MovieIndex;
};

returnValueOfMovieSearch searchMovie();

int payWithoutIncrement[5];

int payWithoutDecrement[5];

struct cityAdministrator
{
	string userName;
	string Password;
};

struct branchAdministrators
{
	string Name;
	string Pin;
	int Salary;
	int workingYears;
};

struct Users
{
	string Name;
	int Pin;
	string Genre;
	float Cart;
	string moviesInCart[25];
	int movieCounter;
};

struct Movies
{
	string Name;
	string Genre;
	string releaseDate;
	float Price;
	float Time;
	bool Status;
};

struct Branches
{
	double Earning;
	char branchCode;
	branchAdministrators Administrator;
	Users User[5];
	Movies Movie[5];
};

Branches Branch[5] = {
						{ 2645.0, 'E', {"Naaif Sharaf","100",12000,5}, { { "Qadeer",200,"Romance",2000.0,{"Roy"},1 }, { "Luqman",201,"Horror",1500.0,{"The Exorcist","Psycho"},2 }, { "Qasim",203,"Thriller",3000.0,{"The Godfather","Inception"},2 } }, { {"Roy","Romance","15/5/2014",500.0,18.00,0}, {"The Exorcist","Horror","25/10/1995",550.0,10.00,0}, {"Psycho","Horror","10/6/2013",525.0,9.00,0}, {"The Godfather","Thriller","30/5/1994",450.0,8.00,0}, {"Inception","Thriller","6/5/2012",620.0,7.00,0} } },

						{ 2640.0, 'F', {"Faraj Munir","101",12500,7}, { { "Hakeem",205,"Horror",1200.0,{"Rear Window"},1 }, { "Fahad",206,"Romance",4500.0,{"Rosemary's Baby","Rear Window"},2 }, { "Shahrukh",207,"Thriller",3900.0,{"Fight Club","Rosemary's Baby"},2 } }, { {"Rear Window","Romance","15/5/2014",350.0,17.00,0}, {"Fight Club","Thriller","25/10/1995",510.0,5.00,0}, {"Rosemary's Baby","Horror","10/6/2013",715.0,16.00,0} } },
				   	 	
						{ 2840.0, 'G', {"Muneef Javid","102",10500,3}, { { "Shehryar",210,"Thriller",3400.0,{"Vertigo"},1 }, { "Ameer",211,"Romance",3250.0,{"Forrest Gump"},1 }, { "Wasif",212,"Horror",1990.0,{"Forrest Gump","Vertigo"},2 } }, { {"Vertigo","Romance","15/5/2014",670.0,3.00,0}, {"Forrest Gump","Horror","25/10/1995",750.0,4.00,0} } },
				   	 	
						{ 3980.0, 'H', {"Ali Hakim","103",11600,2}, { { "Shahan",215,"Horror",2600.0,{"Goodfellas","The Omen"},2 }, { "Rayan",216,"Thriller",1800.0,{"Goodfellas","The Omen"},2 }, { "Bilal",217,"Romance",2780.0,{"The Omen"},1 } }, { {"The Omen","Romance","15/5/2014",715.0,11.00,0}, {"Goodfellas","Horror","25/10/1995",850.0,13.00,0} } },
				   	 
						{ 2025, 'I', {"Nizaar Akhter","104",14500,8}, { { "Zeerak",220,"Horror",2100.0,{"Dawn Dead"},1 }, { "Khabbab",221,"Romance",2350.0,{"Dawn Dead"},1 }, { "Haziq",222,"Thriller",3870.0,{"Dawn Dead"},1 } }, { {"Dawn Dead","Thriller","15/5/2014",675.0,8.00,0} } },				   	
					};
					
int userCounter[5]={3,3,3,3,3};

int movieCounter[5]={5,3,2,2,1};

void viewAllUsers(int);
	
void adminViewAll()
{
	string branchCodeByUser;
	cout << "\n\n\tBranch Code\t\t\tBranch Administrator";
	for(int i=0;i<5;i++)
	{
		cout << "\n\n\t" << Branch[i].branchCode << "\t\t\t\t" << Branch[i].Administrator.Name;
	}
	cout << "\n\n\t> Enter branch code to view full statistics: ";
	do
	{
		getline(cin,branchCodeByUser);
	}
	while ( stringArrayError2(branchCodeByUser,'E','F','G','H','I') == 'Z' );
	system ("cls");
	
	for (int u=0;u<5;u++)
	{
		if ( tolower(Branch[u].branchCode) == tolower(stringArrayError2(branchCodeByUser,'E','F','G','H','I')) )
		{
			cout << "\n\n Branch code\tBranch administrator\tTotal users\tMovies\tTotal income";
			cout << "\n\n     " << Branch[u].branchCode << "\t\t" << Branch[u].Administrator.Name << "\t\t  " << userCounter[u] << "\t\t  " << movieCounter[u] << "\t " << Branch[u].Earning << " Rs.";
			break;
		}
		else if(u==5)
		{
			cout << "\n\n\tNo match";
		}
	};
	
};

void adminViewAdmins()
{
	cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
	for (int i=0;i<5;i++)
	{
		cout << "\n\n\t" << Branch[i].Administrator.Name << "\t\t" <<  Branch[i].branchCode << "\t   " << Branch[i].Administrator.Salary << "\t  " << Branch[i].Administrator.workingYears << "\t     " << Branch[i].Administrator.Pin;
	}
}

int searchBranchAdmin();
				   	 	
cityAdministrator Admin = {"Rahman","16700"};

string Messages[5]={"N","N","N","N","N"};

string nameByAdmin[5]={"N","N","N","N","N"};

string genreByAdmin[5]={"N","N","N","N","N"};

float priceByAdmin[5]={0,0,0,0,0};

string branchMessages[5]={"N","N","N","N","N"};

float updateCartRequest[5][5] = { {0,0},{0,0},{0,0},{0,0},{0,0} };

returnValueOfMovieSearch returningValues;

void editMovie(int);

int main()
{
	Menu();
	
	getch();
	return 0;
}

void Menu(void)
{
	system("cls");
	cout << "\n\n\t\t\tWelcome to Jinnah Multiplex";
	cout << "\n\n\n\t\t1- Administrator";
	cout << "\n\n\n\t\t2- User";
	cout << "\n\n\n\t\t> Enter 1 for Administrator or 2 for User: ";
	int characterCounter=0;
	char Choice[50];
	do
	{
		cin.getline(Choice,50);
		int i=0;
		characterCounter=0;
		while (Choice[i]!='\0')
		{
			if (Choice[0]==' ')
			{
				characterCounter=0;
				break;
			}
			else
			{
				characterCounter++;
				i++;
				continue;
			}
		}
		if (characterCounter<1)
		{
				cout << "\n\n\t\tPlz enter atleast one character!";
				cout << "\n\n\t\tTry again ";
		}
		else if (characterCounter>1)
		{
			cout << "\n\n\t\tOnly one character is allowed!";
			cout << "\n\n\t\tTry again ";
		}
		else if (characterCounter==1)
		{
			switch(Choice[0])
			{	
				case '1':{
					system("cls");
					cout << "\n\n\t\t1- City Administrator";
					cout << "\n\n\t\t2- Branch Administrator ";			
					int characterCounter1=0;
					char Choice1[50];
					do
					{
						cin.getline(Choice1,50);
						int j=0;
						characterCounter1=0;
						while (Choice1[j]!='\0')
						{
							if (Choice1[0]==' ')
							{
								characterCounter1=0;
								break;
							}
							else
							{
								characterCounter1++;
								j++;
								continue;
							}
						}
						if (characterCounter1<1)
						{
							cout << "\n\n\t\tPlz enter atleast one character!";
							cout << "\n\n\t\tTry again ";
						}
						else if (characterCounter1>1)
						{
							cout << "\n\n\t\tOnly one character is allowed!";
							cout << "\n\n\t\tTry again ";
						}
						else if (characterCounter1==1)
						{
							switch(Choice1[0])
							{
								case '1':
								{
									system("cls");
									bool Status=0;
									int Count1=0;
									int Count2=0;
									string Entry1;
									string Entry2;
									do
									{
										Count1=0;
										Count2=0;
										bool Status=0;
										cout << "\n\n\t\tEnter Username:  ";
										getline (cin,Entry1);
										cout << "\n\n\t\tEnter Password:  ";
										getline (cin,Entry2);
										if ( Entry1.length()>Admin.userName.length() )
										{
											cout << "\n\n\t\tUsername should not exceed " << Admin.userName.length() << " character!";
											Status=0;
										}
										else if ( Entry1.length()<Admin.userName.length() )
										{
											cout << "\n\n\t\tUsername should be greater than " << Entry1.length() << " character!";
											Status=0;
										}
										else if ( Entry1.length()==Admin.userName.length() )
										{										
											for (int k=0;k<Entry1.length();k++)
											{
												if ( (tolower(Admin.userName[k]))==(tolower(Entry1[k])) )
												{
													Count1++;
													Status = 1;
												}
												else if ( (tolower(Admin.userName[k]))!=(tolower(Entry1[k])) )
												{
													cout << "\n\n\t\tInvalid username!";
													Status = 0;
													break;
												}				
											}
										}
										if ( Entry2.length()>Admin.Password.length() )
										{
											cout << "\n\n\t\tPassword should not exceed " << Admin.userName.length() << " character!";
											Status=0;
										}
										else if ( Entry2.length()<Admin.Password.length() )
										{
											cout << "\n\n\t\tPassword should be greater than " << Entry2.length() << " character!";
											Status=0;
										}
										else if ( Entry2.length()==Admin.Password.length() )
										{										
											for (int k=0;k<Entry2.length();k++)
											{
												if ( (tolower(Admin.Password[k]))==(tolower(Entry2[k])) )
												{
													Count2++;
													Status = 1;
												}
												else if ( (tolower(Admin.Password[k]))!=(tolower(Entry2[k])) )
												{
													cout << "\n\n\t\tInvalid password!";
													Status = 0;
													break;
												}				
											}
										}
									}
									while( Status==0 && ( Count1!=Admin.userName.length() || Count2!=Admin.Password.length() ) );
									adminMenu();
									break;
								}
								case '2':
								{
									system("cls");
									string branchUserName;
									string branchPin;
									bool Status=0;
									int branchAdminIndex=0;
									do
									{
										Status=0;
										cout << "\n\n\t\tEnter username: ";
										getline(cin,branchUserName);
										cout << "\n\n\t\tEnter Pin: ";
										getline(cin,branchPin);
										for(int i=0;i<5;i++)
										{
											if ( ( branchUserName.compare(Branch[i].Administrator.Name) ) == 0 )
											{
												if ( ( branchPin.compare(Branch[i].Administrator.Pin) ) == 0 )
												{
													cout << "\n\n\t\tUsername and password matched.";
													cout << "\n\n\t\tPress enter key: ";
													getch();
													branchAdminIndex=i;
													Status=1;
													break;
												}												
											}
											else if (i==4)
											{
												cout << "\n\n\t\tWrong username or password!";
											}
										}
										
									}
									while(Status==0);
									branchAdmin(branchAdminIndex);																
									break;
								}
								default:
									cout << "\n\n\t\tYou had entered wrong input!";
									cout << "\n\n\t\tEnter value between 1-2.";
									cout << "\n\n\t\tTry again ";
									characterCounter1=0;
							}
						}
					}
					while (characterCounter1==0 || characterCounter1>1);
				break;}
				case '2':
						{
							system("cls");
							char userChoice[50];
							int lengthChoice=0;
							cout << "\n\n\t\t1- Sign in";
							cout << "\n\n\t\t2- Sign up: ";
							do
							{
								lengthChoice=0;
								cin.getline(userChoice,50);
								int i=0;
								while (userChoice[i]!='\0')
								{
									lengthChoice++;
									i++;
								};
								if (lengthChoice==0)
								{
									cout << "\n\n\t\tEnter atleast one character: ";
									lengthChoice=0;
								}
								else if (lengthChoice>1)
								{
									cout << "\n\n\t\tOnly one character is allowed: ";
									lengthChoice=0;
								}
								else if (lengthChoice==1)
								{
									switch (userChoice[0])
									{
										case '1':
											{
												system("cls");
												string userEnteredName;
												int userEnteredPassword;
												int Stat = 0;
												cout << "\n\n\t\t> Enter username: ";
												getline(cin,userEnteredName);
												cout << "\n\n\t\t> Enter Pin: ";
												cin >> userEnteredPassword;
												cin.ignore(100,'\n');
												for (int p=0; p<5; p++)
												{
														for (int q=0;q<5;q++)
														{
															if ( (Branch[p].User[q].Name.compare(userEnteredName) ) == 0 )
															{
																if ( (Branch[p].User[q].Pin) == userEnteredPassword )
																{
																	cout << "\n\n\t\t> Username & password matched.";
																	userMenu(p,q);
																	Stat = 1;
																	break;
																}
															}
														}
												}
												if (Stat==0)
												{
													cout << "\n\n\t\t> No user account found.";
													cout << "\n\n\n\t\t> Press enter to return to menu: ";
													cin.ignore(100,'\n');
													Menu();
												}
												break;
											}
										case '2':
											{
												system("cls");
												char b_zone;
												cout << "\n\n\t\tEnter your branch zone: ";
												cin >> b_zone;
												switch (b_zone)
												{
													case 'E':
														{
															if (userCounter[0]<5)
															{
																cout << "\n\n\t\tEnter your user name: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[0].User[userCounter[0]].Name);
																cout << "\n\n\t\tEnter your pin: ";
																cin >> Branch[0].User[userCounter[0]].Pin;
																cout << "\n\n\t\tEnter your genre: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[0].User[userCounter[0]].Genre);
																cout << "\n\n\t\tNew account created successfully.";
																userCounter[0]++;
																cout << "\n\n\t\tPress enter to login: ";
																getch();
																Menu();
															}
															else
															{
																cout << "\n\n\t\tNo more users can be added.";
															}
															break;
														}
													case 'F':
														{
															if (userCounter[1]<5)
															{
																cout << "\n\n\t\tEnter your user name: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[1].User[userCounter[1]].Name);
																cout << "\n\n\t\tEnter your pin: ";
																cin >> Branch[1].User[userCounter[1]].Pin;
																cout << "\n\n\t\tEnter your genre: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[1].User[userCounter[1]].Genre);
																cout << "\n\n\t\tNew account created successfully.";
																userCounter[1]++;
																cout << "\n\n\t\tPress enter to login: ";
																getch();
																Menu();
															}
															else
															{
																cout << "\n\n\t\tNo more users can be added.";
															}
															break;
														}
													case 'G':
														{
															if (userCounter[2]<5)
															{
																cout << "\n\n\t\tEnter your user name: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[2].User[userCounter[2]].Name);
																cout << "\n\n\t\tEnter your pin: ";
																cin >> Branch[2].User[userCounter[2]].Pin;
																cout << "\n\n\t\tEnter your genre: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[2].User[userCounter[2]].Genre);
																cout << "\n\n\t\tNew account created successfully.";
																userCounter[2]++;
																cout << "\n\n\t\tPress enter to login: ";
																getch();
																Menu();
															}
															else
															{
																cout << "\n\n\t\tNo more users can be added.";
															}
															break;
														}
													case 'H':
														{
															if (userCounter[3]<5)
															{
																cout << "\n\n\t\tEnter your user name: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[3].User[userCounter[3]].Name);
																cout << "\n\n\t\tEnter your pin: ";
																cin >> Branch[3].User[userCounter[3]].Pin;
																cout << "\n\n\t\tEnter your genre: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[3].User[userCounter[3]].Genre);
																cout << "\n\n\t\tNew account created successfully.";
																userCounter[3]++;
																cout << "\n\n\t\tPress enter to login: ";
																getch();
																Menu();
															}
															else
															{
																cout << "\n\n\t\tNo more users can be added.";
															}
															break;
														}
													case 'I':
														{
															if (userCounter[4]<5)
															{
																cout << "\n\n\t\tEnter your user name: ";
																cin.ignore(100,'\n');
																getline(cin,Branch[4].User[userCounter[4]].Name);
																cout << "\n\n\t\tEnter your pin: ";
																cin >> Branch[4].User[userCounter[4]].Pin;
																cout << "\n\n\t\tEnter your genre: ";
																cin.ignore(10,'\n');
																getline(cin,Branch[4].User[userCounter[4]].Genre);
																cout << "\n\n\t\tNew account created successfully.";
																userCounter[4]++;
																cout << "\n\n\t\tPress enter to login: ";
																getch();
																Menu();
															}
															else
															{
																cout << "\n\n\t\tNo more users can be added.";
															}
															break;
														}
													default:
														{
															cout << "\n\n\t\tWrong branch code.";
															break;
														}
												}
												break;
											}
										default:
											{
												cout << "\n\n\t\tWrong input: ";
												lengthChoice=0;
												break;
											}
									}
								}
							}
							while (lengthChoice==0);						
							break;
						}
				default:
					cout << "\n\n\t\tYou had entered wrong input!";
					cout << "\n\n\t\tEnter value between 1-2.";
					cout << "\n\n\t\tTry again ";
					characterCounter=0;
			}
		}
	}
	while (characterCounter==0 || characterCounter>1);
};

int searchBranchAdmin()
{
	system("cls");
	bool Status=0;
	cout << "\n\n\t\tEnter E-number of employee to search: ";
	char pin[50];
	int Length=0;
	do
	{
		char userSelection[50];
		Status=0;
		Length=0;
		cin.getline(pin,50);
		int i=0;
		while (pin[i]!='\0')
		{
			if (pin[i]==' ')
			{
				Length=0;
				break;
			}
			else
			{		
				Length++;
				i++;
			}
		};
		if (Length==0)
		{
			cout << "\n\t\tE-Number should have minimum 3 characters!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;
		}
		else if (Length>3)
		{
			cout << "\n\t\tE-Number cannot be greater than 3 characters!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;
		}
		else if (Length==3)
		{
			for (int n=0;n<5;n++)
			{
				for (int q=0;q<=Length;q++)
				{
					if (pin[q]==Branch[n].Administrator.Pin[q])
					{
						if (q+1==Length)
						{		
							Status=1;
							return n;
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
			if (Status!=1)
			{
				cout << "\n\t\tWrong E-Number entered!";
				cout << "\n\n\t\tEnter again: ";
				Status=0;
			}
		}	
	}
	while(Status==0);
};

void adminMenu(void)
{
	system("cls");
	if (Seen==0)
	{
		for (int z=0;z<5;z++)
		{
			if (branchMessages[z]=="N")
			{
				continue;
			}
			else if (branchMessages[z]!="N")
			{
				cout << "\n\n\t\t* Received new message from " << Branch[z].Administrator.Name << " *";
				Seen=10;
			}									
		};
	};
	cout << "\n\n\n\t\t1- View all branches";
	cout << "\n\n\t\t2- View all administrators";
	cout << "\n\n\t\t3- Edit branch administrator";
	cout << "\n\n\t\t4- Search movie";
	cout << "\n\n\t\t5- Sign out";
	cout << "\n\n\t\t6- View message: ";
	char adminChoice[50];
	int adminCharacterCounter=0;
	do
	{
		cin.getline(adminChoice,50);
		int i=0;
		adminCharacterCounter=0;
		while (adminChoice[i]!='\0')
		{
			if (adminChoice[0]==' ')
			{
				adminCharacterCounter=0;
				break;
			}
			else
			{
				adminCharacterCounter++;
				i++;
				continue;
			}
		}
		if (adminCharacterCounter<1)
		{
			cout << "\n\n\t\tPlz enter atleast one character!";
			cout << "\n\n\t\tTry again ";
		}
		else if (adminCharacterCounter>1)
		{
			cout << "\n\n\t\tOnly one character is allowed!";
			cout << "\n\n\t\tTry again ";
		}
		else if (adminCharacterCounter==1)
		{
			switch (adminChoice[0])
			{
				case '1':
				{
					system("cls");
					adminViewAll();
					cout << "\n\n\n\n\n\t\t > Press any key to go back to main menu ";
					getch();					
					adminMenu();
					break;
				}
				case '2':
				{
					system("cls");
					adminViewAdmins();
					cout << "\n\n\t\t> Press any key to go back to main menu ";
					getch();					
					adminMenu();
					break;
				}
				case '3':
				{
					int Yo=0;
					string Choice88;
					int x = 0;
					system("cls");
					x = searchBranchAdmin();
					system("cls");
					cout << "\n\n\t\t> Details for E-Number you entered are given below\n";													
					cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
					cout << "\n\n\t" << Branch[x].Administrator.Name << "\t\t" <<  Branch[x].branchCode << "\t   " << Branch[x].Administrator.Salary << "\t  " << Branch[x].Administrator.workingYears << "\t     " << Branch[x].Administrator.Pin;
					cout << "\n\n\n\tAre you sure to edit this user.";
					cout << "\n\n\tE -> Search Again";
					cout << "\n\n\tY -> Yes";
					cout << "\n\n\tN -> Menu ";
					do
					{
						getline (cin,Choice88);
						
						while ( tolower(Choice88[0]) == 'e' )
						{
							int x = searchBranchAdmin();
							system("cls");
							cout << "\n\n\t\t> Details for E-Number you entered are given below\n";													
							cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
							cout << "\n\n\t" << Branch[x].Administrator.Name << "\t\t" <<  Branch[x].branchCode << "\t   " << Branch[x].Administrator.Salary << "\t  " << Branch[x].Administrator.workingYears << "\t     " << Branch[x].Administrator.Pin;
							cout << "\n\n\n\tAre you sure to edit this user.";
							cout << "\n\n\tE -> Search Again";
							cout << "\n\n\tY -> Yes";
							cout << "\n\n\tN -> Menu ";
							getline (cin,Choice88);
						};					
						switch (tolower(Choice88[0]))
						{
							case 'y':
								editBranchAdmin(x);
								break;
							case 'n':
								adminMenu();
								break;
						}
					}
					while ( (stringArrayError(Choice88,'Y','N','E')) == 'Z' );
					break;
				}
				case '4':
					{
						searchMovie();
						break;
					}
				case '5':
					{
						Menu();
						break;
					}
				case '6':
					{
						system("cls");
						for (int f=0;f<5;f++)
						{
							if (branchMessages[f]!="N")
							{
								cout << "\n\n    (" << branchMessages[f] << ")";
								cout << "\n\n    * Sent by " << Branch[f].Administrator.Name << " *";
								break;
							}
							else if (branchMessages[f]=="N")
							{
								if (f==4)
								{
									cout << "\n\n\t\t\tNo new messages.";
								}
								else
								{
									continue;
								}					
							}							
						};
						cout << "\n\n\n\t\t> Press enter to return to menu: ";
						getch();
						adminMenu();						
						break;
					}
				default:
				{													
					cout << "\n\n\t\tYou had entered wrong input!";
					cout << "\n\n\t\tEnter value between 1-5.";
					cout << "\n\n\t\tTry again ";
					adminCharacterCounter=0;
				}
			}
		}
	}while (adminCharacterCounter==0 || adminCharacterCounter>1);
};

char stringArrayError(string a,char b,char c,char d)
{
	int characterCounter=0;
	int i=0;
	characterCounter=0;
	while (a[i]!='\0')
	{
		if (a[0]==' ')
		{
			characterCounter=0;
			break;
		}
		else
		{
			characterCounter++;
			i++;
		}
	}
	if (characterCounter==0)
	{
		cout << "\n\n\tPlz enter atleast one character!";
		cout << "\n\n\tTry again ";
		return 'Z';
	}
	else if (characterCounter>1)
	{
		cout << "\n\n\tOnly one character is allowed!";
		cout << "\n\n\tTry again ";
		return 'Z';
	}
	else if (characterCounter==1)
	{
		if (tolower(a[0])==tolower(b))
		{
			return b;
		}
		else if (tolower(a[0])==tolower(c))
		{
			return c;
		}
		else if (tolower(a[0])==tolower(d))
		{
			return d;
		}
		else
		{
			cout << "\n\n\tWrong value entered!";
			cout << "\n\n\tTry again ";
			return 'Z';
		}
	}
};

int editBranchAdmin(int w)
{
	string Choice91;
	system("cls");
	cout << "\n\n\t\t1 -> Edit pay";
	cout << "\n\n\t\t2 -> Edit all ";
	cout << "\n\n\t\t0 -> Menu ";
	do
	{
		getline (cin,Choice91);
	}
	while ( (stringArrayError(Choice91,'1','2','0')) == 'Z' );
	switch (Choice91[0])
	{
		case '1':
		{
			string Choice57;
			system ("cls");
			cout << "\n\n\t\t 1 -> Add Increment";
			cout << "\n\n\t\t 2 -> Add Decrement";
			cout << "\n\n\t\t 0 -> Main menu ";
			do
			{
				getline (cin,Choice57);
			}
			while ( (stringArrayError(Choice57,'1','2','0')) == 'Z' );
			switch (Choice57[0])
			{
				case '1':
				{
					payWithoutIncrement[w]=Branch[w].Administrator.Salary;
					int incrementAmount=0;
					system("cls");							
					cout << "\n\n\t\t> Current stats of the employee are stated below\n";											
					cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
					cout << "\n\n\t" << Branch[w].Administrator.Name << "\t\t" <<  Branch[w].branchCode << "\t   " << Branch[w].Administrator.Salary << "\t  " << Branch[w].Administrator.workingYears << "\t     " << Branch[w].Administrator.Pin;
					cout << "\n\n\n\tPlease enter increment amount: ";
					cin >> incrementAmount;
					Branch[w].Administrator.Salary += incrementAmount;
					cout << "\n\n\t\t > Current stats updated, View below";											
					cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
					cout << "\n\n\t" << Branch[w].Administrator.Name << "\t\t" <<  Branch[w].branchCode << "\t   " << Branch[w].Administrator.Salary << "\t  " << Branch[w].Administrator.workingYears << "\t     " << Branch[w].Administrator.Pin;							
					cout << "\n\n\t\t> Press any key to return to main menu: ";
					cin.ignore(100,'\n');
					getch();
					adminMenu();
					break;
				}
				case '2':
				{
					payWithoutDecrement[w]=Branch[w].Administrator.Salary;
					int decrementAmount=0;
					system("cls");							
					cout << "\n\n\t\t> Current stats of the employee are stated below\n";											
					cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
					cout << "\n\n\t" << Branch[w].Administrator.Name << "\t\t" <<  Branch[w].branchCode << "\t   " << Branch[w].Administrator.Salary << "\t  " << Branch[w].Administrator.workingYears << "\t     " << Branch[w].Administrator.Pin;
					cout << "\n\n\n\tPlease enter decrement amount: ";
					cin >> decrementAmount;
					Branch[w].Administrator.Salary -= decrementAmount;
					cout << "\n\n\t\t > Current stats updated, View below";											
					cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
					cout << "\n\n\t" << Branch[w].Administrator.Name << "\t\t" <<  Branch[w].branchCode << "\t   " << Branch[w].Administrator.Salary << "\t  " << Branch[w].Administrator.workingYears << "\t     " << Branch[w].Administrator.Pin;
					cout << "\n\n\t\t> Press any key to return to main menu: ";
					cin.ignore(100,'\n');
					getch();
					adminMenu();
					break;
				}
				case '0':
					adminMenu();
				break;
			}
			break;
		}
		case '2':
			{
				system("cls");
				cout << "\n\n\t\tEnter administrator name: ";
				getline(cin,Branch[w].Administrator.Name);
				cout << "\n\n\t\tEnter branch code: ";
				cin >> Branch[w].branchCode;
				cout << "\n\n\t\tEnter salary amount: ";
				cin >> Branch[w].Administrator.Salary;
				cout << "\n\n\t\tEnter working years of employee: ";
				cin >> Branch[w].Administrator.workingYears;
				cout << "\n\n\t\tEnter administrator Pin: ";
				cin >> Branch[w].Administrator.Pin;
				system("cls");
				cout << "\n\n\t\t > Current stats updated, View below";								
				cout << "\n\n\tAdministrator Name | Branch Code | Salary | Working years | E-No.";
				cout << "\n\n\t" << Branch[w].Administrator.Name << "\t\t" <<  Branch[w].branchCode << "\t   " << Branch[w].Administrator.Salary << "\t  " << Branch[w].Administrator.workingYears << "\t     " << Branch[w].Administrator.Pin;
				cout << "\n\n\t\t> Press any key to return to main menu: ";
				cin.ignore(100,'\n');
				getch();
				adminMenu();
				break;
			}
		case '0':
			adminMenu();
			break;
	}
};

char stringArrayError2(string a,char b,char c,char d,char e,char f)
{
	int characterCounter=0;
	int i=0;
	characterCounter=0;
	while (a[i]!='\0')
	{
		if (a[0]==' ')
		{
			characterCounter=0;
			break;
		}
		else
		{
			characterCounter++;
			i++;
		}
	}
	if (characterCounter==0)
	{
		cout << "\n\n\tPlz enter atleast one character!";
		cout << "\n\n\tTry again ";
		return 'Z';
	}
	else if (characterCounter>1)
	{
		cout << "\n\n\tOnly one character is allowed!";
		cout << "\n\n\tTry again ";
		return 'Z';
	}
	else if (characterCounter==1)
	{
		if (tolower(a[0])==tolower(b))
		{
			return b;
		}
		else if (tolower(a[0])==tolower(c))
		{
			return c;
		}
		else if (tolower(a[0])==tolower(d))
		{
			return d;
		}
		else if (tolower(a[0])==tolower(e))
		{
			return e;
		}
		else if (tolower(a[0])==tolower(f))
		{
			return f;
		}
		else
		{
			cout << "\n\n\tWrong value entered!";
			cout << "\n\n\tTry again ";
			return 'Z';
		}
	}
};

returnValueOfMovieSearch searchMovie()
{	
	//returnValueOfMovieSearch returningValues;
	bool Status=0;
	int Length=0;
	system("cls");
	string movieEntered;
	cout << "\n\n\t\tEnter name of movie to search: ";
	do
	{
		getline (cin,movieEntered);
		Status=0;
		Length=0;
		if (movieEntered[0]==' ')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;	
		}
		else if (movieEntered[0]=='\0')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;
		}
		else
		{
			for (int k=0;k<100;k++)
			{
				if ( isdigit(movieEntered[k]) )
				{
					cout << "\n\n\t\tDigits are not allowed!";
					cout << "\n\n\t\tEnter again: ";
					Status=0;
					break;
				}
				else if (movieEntered[k]=='\0')
				{
					Status=1;
					break;
				}
				Length++;
			}
		}
	}
	while (Status==0);
	
	int branchIndex=0;
	int movieIndex=0;
	bool Status1=0;
		
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			for (int p=0;p<100;p++)
			{
				if( ( tolower(Branch[i].Movie[j].Name[p]) ) == ( tolower(movieEntered[p]) ) )
				{
					if (p==Length)
					{
						branchIndex=i;
						movieIndex=j;
						Status1=1;
					}
				}
				else
				{
					break;
				}			
			}
		}
	}
	if (Status1==1)
	{
		system("cls");
		cout << "\n\n\t\t\t  >> Movie found <<";
		cout << "\n\n\n\t\t> Details of movie are in following order.\n\n";
		cout << "     Movie Name , Branch Code , Price , Release Date , Genre, Time, Status\n\n";
		cout << "\t      | " << Branch[branchIndex].Movie[movieIndex].Name << ", " << Branch[branchIndex].branchCode << ", " << Branch[branchIndex].Movie[movieIndex].Price << "/-Rs, " << Branch[branchIndex].Movie[movieIndex].releaseDate << ", " << Branch[branchIndex].Movie[movieIndex].Genre << "  |  " << Branch[branchIndex].Movie[movieIndex].Time << ", " << Branch[branchIndex].Movie[movieIndex].Status << " |";
		returningValues.BranchIndex=branchIndex;
		returningValues.MovieIndex=movieIndex;
		char Choice18[50];
		int Length18=0;
		cout << "\n\n\n\n\t 1- Ask branch administrator to update this movie";
		cout << "\n\n\t 2- Press two to return back to your main menu: ";
		do
		{
			cin.getline(Choice18,50);
			for (int y=0;y<50;y++)
			{
				if(Choice18[y]=='\0')
				{
					break;
				}
				else
				{
					Length18++;
					continue;
				}
			}
			if (Choice18[0] == ' ')
			{
				cout << "\n\n\tEnter atleast one characeter";
				cout << "\n\n\tEnter again: ";
				Length18=0;
			}
			else if (Choice18[0] == '\0')
			{
				cout << "\n\n\tEnter atleast one characeter";
				cout << "\n\n\tEnter again: ";
				Length18=0;
			}
			else if (Length18>1)
			{
				cout << "\n\n\tOnly one character is allowed";
				cout << "\n\n\tEnter again: ";
				Length18=0;
			}
			else if (Length18==1)
			{
				switch(Choice18[0])
				{
					case '1':
						{
							system("cls");
							cout << "\n\n\t\t1- Name";
							cout << "\n\n\t\t2- Genre";
							cout << "\n\n\t\t3- Price: ";
							char Choice66[50];
							int Length66=0;
							do
							{
								Length66=0;
								cin.getline(Choice66,50);
								for (int y=0;y<50;y++)
								{
									if(Choice66[y]=='\0')
									{
										break;
									}
									else
									{
										Length66++;
										continue;
									}
								}
								if (Choice66[0] == ' ')
								{
									cout << "\n\n\t\tEnter atleast one characeter";
									cout << "\n\n\t\tEnter again: ";
									Length66=0;
								}
								else if (Choice66[0] == '\0')
								{
									cout << "\n\n\t\tEnter atleast one characeter";
									cout << "\n\n\t\tEnter again: ";
									Length66=0;
								}
								else if (Length66>1)
								{
									cout << "\n\n\t\tOnly one character is allowed";
									cout << "\n\n\t\tEnter again: ";
									Length66=0;
								}
								else if (Length66==1)
								{
									switch (Choice66[0])
									{
										case '1':
											{
												system("cls");
												cout << "\n\n > Enter name that you want the branch administrator to update: ";
												getline(cin,nameByAdmin[branchIndex]);
												cout << "\n\n > Type your message explaining reason and other information:\n\n   ";
												getline(cin,Messages[branchIndex]);
												cout << "\n\n\t> Your message has been sent to branch administrator.";
												cout << "\n\n\t> Press any key to return to main menu: ";
												getch();
												adminMenu();
												break;
											}
										case '2':
											{
												system("cls");
												cout << "\n\n > Enter genre that you want the branch administrator to update: ";
												getline(cin,genreByAdmin[branchIndex]);
												cout << "\n\n > Type your message explaining reason and other information:\n\n   ";
												getline(cin,Messages[branchIndex]);
												cout << "\n\n\t> Your message has been sent to branch administrator.";
												cout << "\n\n\t> Press any key to return to main menu: ";
												getch();
												adminMenu();
												break;
											}
										case '3':
											{
												system("cls");
												cout << "\n\n > Enter price that you want the branch administrator to update: ";
												cin >> priceByAdmin[branchIndex];
												cout << "\n\n > Type your message explaining reason and other information:\n\n   ";
												cin.ignore(100,'\n');
												getline(cin,Messages[branchIndex]);
												cout << "\n\n\t> Your message has been sent to branch administrator.";
												cout << "\n\n\t> Press any key to return to main menu: ";
												getch();
												adminMenu();
												break;
											}
										default:
											{
												cout << "\n\n\t\tWrong input!";
												cout << "\n\n\t\tEnter again: ";
												Length66=0;
												break;
											}
									}
								}
							}
							while(Length66==0);
							Length18=1;
							break;
						}
					case '2':
						{
							Length18=1;
							adminMenu();
							break;
						}
					default:
						{
							cout << "\n\n\tWrong input!";
							cout << "\n\n\tTry again: ";
							Length18=0;
							break;
						}						
				}
			}
		}
		while(Length18==0);		
		return returningValues;
	}
	else
	{
		cout << "\n\n\t\tNo match found.";
		cout << "\n\n\t\tPress any key to go back to main menu: ";
		getch();
		adminMenu();
	}
};

void branchAdmin(int h)
{
	system("cls");
	cout << "\n   Welcome!\t\t\t\t\t\t-" << Branch[h].Administrator.Name;
	cout << "\n\t\t\t\t\t\t\t-Earning: " << Branch[h].Earning << " Rs.";
	if (Messages[h]=="N")
	{
		cout << "\n\t\t\t\t\t\t\t-No new message";
	}
	else
	{
		if (Seen1==0)
		{
			cout << "\n\t\t\t\t\t\t\t+New message received";
			Seen1=10;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t-No new message";			
		}
	}
	if (nameByAdmin[h]=="N" && genreByAdmin[h]=="N" && priceByAdmin[h]==0)
	{
		cout << "\n\t\t\t\t\t\t\t-No update request";	
	}
	else
	{
		if (Seen2==0)
		{
			cout << "\n\t\t\t\t\t\t\t+New update request";
			Seen2=10;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t-No update request";	
		}
	}
	char Choice11[50];
	int Length11=0;
	cout << "\n\n\t\t1- View all users";
	cout << "\n\n\t\t2- View all movies";
	cout << "\n\n\t\t3- Add movie";
	cout << "\n\n\t\t4- Search movie";
	cout << "\n\n\t\t5- Edit movie";
	cout << "\n\n\t\t6- View administrator messages";
	cout << "\n\n\t\t7- View administrator updates";															
	cout << "\n\n\t\t8- View cart updates";
	cout << "\n\n\t\t9- Sign out: ";
	do
	{
		Length11=0;
		cin.getline(Choice11,50);
		int l=0;
		while (Choice11[l]!='\0')
		{
			if (Choice11[0]==' ')
			{
				Length11=0;
				break;
			}
			else
			{
				Length11++;
				l++;
			}	
		}
		if (Length11==0)
		{
			cout << "\n\n\t\tEnter atleast one character: ";
			Length11=0;
		}
		else if (Length11>1)
		{
			cout << "\n\n\t\tOnly one character is allowed: ";
			Length11=0;
		}
		else if (Length11==1)
		{
			switch (Choice11[0])
			{
				case '1':
					{
						system("cls");
						viewAllUsers(h);
						cout << "\n\n\n\n\t\t  > Press any key to return to menu: ";
						getch();
						branchAdmin(h);
											
						break;
					}
				case '2':
					{
						system("cls");
						cout << "\n\n\t\t> Details are in the following order.";
						cout << "\n\n\t> Movie name, Genre, Release date, Price, Time, Status <\n\n";
						for (int i=0;i<movieCounter[h];i++)
						{
							cout << "\n\n\t" << i+1 << " - " << Branch[h].Movie[i].Name << " - " << Branch[h].Movie[i].Genre << " - " << Branch[h].Movie[i].releaseDate << " - " << Branch[h].Movie[i].Price << "/-Rs." << " - " << Branch[h].Movie[i].Time << " - " << Branch[h].Movie[i].Status;
						}
						cout << "\n\n\n\n\t\t> Press any key to return to menu: ";
						getch();
						branchAdmin(h);			
						break;
					}
				case '3':
					{
						system("cls");
						addMovie(h);
						cout << "\n\n\n\n\t\t> Press any key to return to menu: ";
						getch();
						branchAdmin(h);
						break;
					}
				case '4':
					{
						system("cls");
						branchSearchMovie(h);
						cout << "\n\n\n\n\t\t> Press any key to return to menu: ";
						getch();
						branchAdmin(h);
						break;
					}
				case '5':
					{
						system("cls");
						editMovie(h);
						cout << "\n\n\n\n\t\t> Press any key to return to menu: ";
						getch();
						branchAdmin(h);
						break;
					}
				case '6':
					{
						system("cls");
						if (Messages[h]!="N")
						{
							cout << "\n\n\t\t> New message received from " << Admin.userName << ".";
							cout << "\n\n\t\t> Press enter to view message: ";
							getch();
							system("cls");
							cout << "\n\n  (" << Messages[h] << ")  ";
							cout << "\n\n  1- Respond to message";
							cout << "\n\n  2- Ignore message: ";
							char Choice44[50];
							int Length44=0;
							do
							{
								Length44=0;
								cin.getline(Choice44,50);
								int i=0;
								while (Choice44[i] != '\0')
								{
									Length44++;
									i++;									
								};
								if (Length44==0)
								{
									cout << "\n\n    Enter atleast one character: ";
								}
								else if (Length44>1)
								{
									cout << "\n\n    Only one character is allowed: ";
									Length44=0;
								}
								else if (Length44==1)
								{
									switch(Choice44[0])
									{
										case '1':
											{
												cout << "\n\n  > Enter your message below: \n\n    ";
												getline(cin,branchMessages[h]);
												cout << "\n\n  > Your message has been sent.";
												break;
											}
										case '2':
											{
												cout << "\n\n  Message from administrator igored by you!";
												break;
											}
										default:
											{
												cout << "\n\n    Wrong input: ";
												Length44=0;
												break;
											}
									}
								}
							}
							while(Length44==0);
							cout << "\n\n\n  > Press any key to return to menu: ";
							getch();
							branchAdmin(h);
						}
						else
						{
							cout << "\n\n\t\t> You had no new message.";
							cout << "\n\n\t\t> Press any key to return to menu: ";
							getch();
							branchAdmin(h);
						}						
						break;
					}
				case '7':
					{
						system("cls");
						if (nameByAdmin[h]=="N" && genreByAdmin[h]=="N" && priceByAdmin[h]==0)
						{
							cout << "\n\n\t\t> You had no new update requests.";
							cout << "\n\n\t\t> Press any key to return to menu: ";
							getch();
							branchAdmin(h);		
						}
						else
						{
							cout << "\n\n\t\t> New update request received from " << Admin.userName << ".";
							cout << "\n\n\t\t> Press enter to view request: ";
							getch();
							system("cls");
							if (nameByAdmin[h]!="N")
							{
								cout << "\n\n\t\tUpdate name of movie no " << returningValues.MovieIndex+1 << "  from " << Branch[h].Movie[returningValues.MovieIndex].Name << " to " << nameByAdmin[h];
							}
							else if (genreByAdmin[h]!="N")
							{
								cout << "\n\n\t\tUpdate genre of movie no " << returningValues.MovieIndex+1 << "  from " << Branch[h].Movie[returningValues.MovieIndex].Genre << " to " << genreByAdmin[h];
							}
							else if (priceByAdmin[h]!=0)
							{
								cout << "\n\n\t\tUpdate price of movie no " << returningValues.MovieIndex+1 << "  from " << Branch[h].Movie[returningValues.MovieIndex].Price << " to " << priceByAdmin[h];
							}
							cout << "\n\n\t\t1- Respond to update";
							cout << "\n\n\t\t2- Ignore update: ";
							char Choice45[50];
							int Length45=0;
							do
							{
								Length45=0;
								cin.getline(Choice45,50);
								int i=0;
								while (Choice45[i] != '\0')
								{
									Length45++;
									i++;									
								};
								if (Length45==0)
								{
									cout << "\n\n\t\tEnter atleast one character: ";
								}
								else if (Length45>1)
								{
									cout << "\n\n\t\tOnly one character is allowed: ";
									Length45=0;
								}
								else if (Length45==1)
								{
									switch(Choice45[0])
									{
										case '1':
											{
												cout << "\n\n\t\tAuto responding to update..";
												if (nameByAdmin[h]!="N")
												{
													Branch[h].Movie[returningValues.MovieIndex].Name = nameByAdmin[h];
												}
												else if (genreByAdmin[h]!="N")
												{
													Branch[h].Movie[returningValues.MovieIndex].Genre = genreByAdmin[h];
												}
												else if (priceByAdmin[h]!=0)
												{
													Branch[h].Movie[returningValues.MovieIndex].Price = priceByAdmin[h];
												}
												cout << "\n\n\t\tPress enter key: ";
												getch();
												cout << "\n\n\t\tAuto responce to update request done successfully.";												
												break;
											}
										case '2':
											{
												cout << "\n\n\t\tUpdate from administrator igored by you!";
												break;
											}
										default:
											{
												cout << "\n\n\t\tWrong input: ";
												Length45=0;
												break;
											}
									}
								}
							}
							while(Length45==0);
							cout << "\n\n\t\t> Press any key to return to menu: ";
							getch();
							branchAdmin(h);
						}
						break;
					}
				case '8':
					{
						system("cls");
						for (int a=0;a<5;a++)
						{
							if (updateCartRequest[h][a] != 0)
							{
								system("cls");
								int KK=0;
								cout << "\n\n\t\t> Cart update request received from " << Branch[h].User[a].Name;
								cout << "\n\n\t\t> " << Branch[h].User[a].Name << " wants a recharge of " << updateCartRequest[h][a] << " Rs.";
								cout << "\n\n\n\n\t\t\t1- Auto update";
								cout << "\n\n\t\t\t2- Ignore request: ";
								cin >> KK;
								switch (KK)
								{
									case 1:
									{
										Branch[h].User[a].Cart += updateCartRequest[h][a];
										cout << "\n\n\t\tAuto updating..";
										cout << "\n\n\t\tPress enter: ";
										getch();
										cout << "\n\n\t\tSuccessfully updated.";
										cu=1;
										break;
									}
									case 2:
									{
										cout << "\n\n\t\tRequest from user is ignored.";
										cu=10;
										break;
									}
								}
							}
								else if (a==4)
								{
									cout << "\n\n\t\t> No new cart updates.";
								}
						}
						cin.ignore(100,'\n');
						cout << "\n\n\n\n\t\tPress enter to return to menu: ";
						getch();
						branchAdmin(h);
						break;
					}
				case '9':
					{
						Menu();
						break;
					}
				default:
					{
						Length11=0;
						cout << "\n\n\t\tWrong Input!";
						cout << "\n\n\t\tTry again: ";
						break;
					}
			}
		}
	}
	while (Length11==0);
};

void viewAllUsers(int g)
{
	cout << "\n\n\t\t> Details are in the following order.";
	cout << "\n\n\t> User name, Pin, Genre, Amount in Cart, Movies in Cart <\n\n";
	for (int i=0;i<userCounter[g];i++)
	{
		cout << "\n\n" << " " << i+1 << " -  " << Branch[g].User[i].Name << ", " << Branch[g].User[i].Pin << ", " << Branch[g].User[i].Genre << ", " << Branch[g].User[i].Cart << "/-Rs, ";
		for (int j=0;j<movieCounter[i];j++)
		{
			cout <<" " << Branch[g].User[i].moviesInCart[j];
		}
	}
};

void addMovie(int x)
{
	if (movieCounter[x]<5)
	{
		cout << "\n\n\t\tEnter name of movie: ";
		getline(cin,Branch[x].Movie[movieCounter[x]].Name);
		cout << "\n\n\t\tEnter release date: ";
		getline(cin,Branch[x].Movie[movieCounter[x]].releaseDate);
		cout << "\n\n\t\tEnter genre of movie: ";
		getline(cin,Branch[x].Movie[movieCounter[x]].Genre);
		cout << "\n\n\t\tEnter price of movie: ";
		cin >> Branch[x].Movie[movieCounter[x]].Price;
		cout << "\n\n\t\tEnter time of movie: ";
		cin >> Branch[x].Movie[movieCounter[x]].Time;		
		cin.ignore(100,'\n');
		movieCounter[x]++;
	}
	else
	{
		cout << "\n\n\t\tMaximum five movies can be added!";
		cout << "\n\n\t\tWe can't process your request now.";
	}
};

void branchSearchMovie(int t)
{
	bool Status=0;
	int Length=0;
	string movieEntered;
	cout << "\n\n\t\tEnter name of movie to search: ";
	do
	{
		getline (cin,movieEntered);
		Status=0;
		Length=0;
		if (movieEntered[0]==' ')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;	
		}
		else if (movieEntered[0]=='\0')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;		
		}
		else
		{
			for (int k=0;k<100;k++)
			{
				if ( isdigit(movieEntered[k]) )
				{
					cout << "\n\n\t\tDigits are not allowed!";
					cout << "\n\n\t\tEnter again: ";
					Status=0;
					break;
				}
				else if (movieEntered[k]=='\0')
				{
					Status=1;
					break;
				}
				Length++;
			}
		}
	}
	while (Status==0);
	
	int movieIndex=0;
	bool Status1=0;
	for (int j=0;j<5;j++)
	{
		for (int p=0;p<100;p++)
		{
			if( ( tolower(Branch[t].Movie[j].Name[p]) ) == ( tolower(movieEntered[p]) ) )
			{
				if (p==Length)
				{
					movieIndex=j;
					Status1=1;
				}
			}
			else
			{
				break;
			}			
		}
	}
	if (Status1==1)
	{
		system("cls");
		cout << "\n\n\t\t\t>> Movie found <<";
		cout << "\n\n\n\t\t > Details of movie are in following order <\n\n";
		cout << "    Movie Name , Branch Code , Price , Release Date , Genre, Time, Status\n\n\n";
		cout << "\t      | " << Branch[t].Movie[movieIndex].Name << ", " << Branch[t].branchCode << ", " << Branch[t].Movie[movieIndex].Price << "/-Rs, " << Branch[t].Movie[movieIndex].releaseDate << ", " << Branch[t].Movie[movieIndex].Genre << ", " << Branch[t].Movie[movieIndex].Time << ", " << Branch[t].Movie[movieIndex].Status << " |";	
	}
	else
	{
		cout << "\n\n\t\t> No match found for movie you entered.";
	}
};

void editMovie(int g)
{
	bool Status=0;
	int Length=0;
	string movieEntered;
	cout << "\n\n\t\tEnter name of movie to search: ";
	do
	{
		getline (cin,movieEntered);
		Status=0;
		Length=0;
		if (movieEntered[0]==' ')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;	
		}
		else if (movieEntered[0]=='\0')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;		
		}
		else
		{
			for (int k=0;k<100;k++)
			{
				if ( isdigit(movieEntered[k]) )
				{
					cout << "\n\n\t\tDigits are not allowed!";
					cout << "\n\n\t\tEnter again: ";
					Status=0;
					break;
				}
				else if (movieEntered[k]=='\0')
				{
					Status=1;
					break;
				}
				Length++;
			}
		}
	}
	while (Status==0);		
	int movieIndex=0;
	bool Status1=0;
	for (int j=0;j<5;j++)
	{
		for (int p=0;p<100;p++)
		{
			if( ( tolower(Branch[g].Movie[j].Name[p]) ) == ( tolower(movieEntered[p]) ) )
			{
				if (p==Length)
				{
					movieIndex=j;
					Status1=1;
				}
			}
			else
			{
				break;
			}			
		}
	}
	if (Status1==1)
	{
		system("cls");
		cout << "\n\n\t\t\t>> Movie found <<";
		cout << "\n\n\n\t\t > Details of movie are in following order.\n\n";
		cout << "    Movie Name , Branch Code , Price , Release Date , Genre, Time, Status\n\n\n";
		cout << "\t      | " << Branch[g].Movie[movieIndex].Name << ", " << Branch[g].branchCode << ", " << Branch[g].Movie[movieIndex].Price << "/-Rs, " << Branch[g].Movie[movieIndex].releaseDate << ", " << Branch[g].Movie[movieIndex].Genre << ", " << Branch[g].Movie[movieIndex].Time << ", " << Branch[g].Movie[movieIndex].Status << " |";	
		cout << "\n\n\n\t\t> Press enter to edit this movie: ";
		getch();
		system("cls");
		string Choice90;
		cout << "\n\n\t\t1- Name";
		cout << "\n\n\t\t2- Genre";
		cout << "\n\n\t\t3- Release date";
		cout << "\n\n\t\t4- Price";
		cout << "\n\n\t\t5- Time";
		cout << "\n\n\t\t6- Status: ";
		do
		{
			getline(cin,Choice90);
		}
		while ( stringArrayError3(Choice90,'1','2','3','4','5','6') == 'Z' );
		system("cls");
		switch (Choice90[0])
		{
			case '1':
				{
					cout << "\n\n\t\tEnter name to update movie name: ";
					getline (cin,Branch[g].Movie[movieIndex].Name);
					cout << "\n\n\t\tMovie name updated successfully.";
					break;
				}
			case '2':
				{
					cout << "\n\n\t\tEnter genre to update movie genre: ";
					getline (cin,Branch[g].Movie[movieIndex].Genre);
					cout << "\n\n\t\tMovie genre updated successfully.";
					break;
				}
			case '3':
				{
					cout << "\n\n\t\tEnter release date to update movie release date: ";
					getline (cin,Branch[g].Movie[movieIndex].releaseDate);
					cout << "\n\n\t\tMovie release updated successfully.";
					break;
				}
			case '4':
				{
					cout << "\n\n\t\tEnter price to update movie price: ";
					cin >> Branch[g].Movie[movieIndex].Price;
					cout << "\n\n\t\tMovie price updated successfully.";
					break;
				}
			case '5':
				{
					cout << "\n\n\t\tEnter time to update movie time: ";
					cin >> Branch[g].Movie[movieIndex].Time;
					cout << "\n\n\t\tMovie time updated successfully.";
					break;
				}
			case '6':
				{
					cout << "\n\n\t\tEnter status to update movie status.";
					cout << "\n\n\t\tEnter 1 or 0 for true or false: ";
					cin >> Branch[g].Movie[movieIndex].Status;
					cout << "\n\n\t\tMovie status updated successfully.";
					if ( Branch[g].Movie[movieIndex].Status == 1 )
					{
						movieCounter[g]--;
						for (int i=movieIndex;i<movieCounter[g];i++)
						{
							Branch[g].Movie[i].Name = Branch[g].Movie[i+1].Name;
							Branch[g].Movie[i].Genre = Branch[g].Movie[i+1].Genre;
							Branch[g].Movie[i].releaseDate = Branch[g].Movie[i+1].releaseDate;
							Branch[g].Movie[i].Price = Branch[g].Movie[i+1].Price;
							Branch[g].Movie[i].Time = Branch[g].Movie[i+1].Time;
							Branch[g].Movie[i].Status = Branch[g].Movie[i+1].Status;
						}
					}
					break;
				}				
		}
		cin.ignore(100,'\n');
	}
	else
	{
		cout << "\n\n\t\t> No match found for movie you entered.";
	}
};

char stringArrayError3(string a,char b,char c,char d,char e,char f,char g)
{
	int characterCounter=0;
	int i=0;
	characterCounter=0;
	while (a[i]!='\0')
	{
		if (a[0]==' ')
		{
			characterCounter=0;
			break;
		}
		else
		{
			characterCounter++;
			i++;
		}
	}
	if (characterCounter==0)
	{
		cout << "\n\n\t\tPlz enter atleast one character!";
		cout << "\n\n\t\tTry again ";
		return 'Z';
	}
	else if (characterCounter>1)
	{
		cout << "\n\n\t\tOnly one character is allowed!";
		cout << "\n\n\t\tTry again ";
		return 'Z';
	}
	else if (characterCounter==1)
	{
		if (a[0]==b)
		{
			return b;
		}
		else if (a[0]==c)
		{
			return c;
		}
		else if (a[0]==d)
		{
			return d;
		}
		else if (a[0]==e)
		{
			return e;
		}
		else if (a[0]==f)
		{
			return f;
		}
		else if (a[0]==g)
		{
			return g;
		}
		else
		{
			cout << "\n\n\t\tWrong value entered!";
			cout << "\n\n\t\tTry again ";
			return 'Z';
		}
	}
};

void userMenu(int Brancho,int Usero)
{
	char Choice61[50];
	int Length61 = 0;
	system("cls");
	cout << "\n   Welcome!\t\t\t\t\t\t    " << Branch[Brancho].User[Usero].Name;
	cout << "\n\n\t\t\t\t\t\t   Jinnah Multiplex Branch " << Branch[Brancho].branchCode;
	if (cu==1)
	{
		cout << "\n\n\t\t> Your cart update request has been accepted by administrator.";
	}
	else if (cu==10)
	{
		cout << "\n\n\t\t> Your cart update request has been ignored by administrator.";
	}
	cout << "\n\n\n\n\n\t\t1- View amount cart";
	cout << "\n\n\t\t2- View movies cart";
	cout << "\n\n\t\t3- Add new movie";
	cout << "\n\n\t\t4- Movies on the go";
	cout << "\n\n\t\t5- Edit request";
	cout << "\n\n\t\t6- Sign out: ";
	do
	{
		Length61=0;
		cin.getline(Choice61,50);
		int u=0;
		while (Choice61[u]!='\0')
		{
			Length61++;
			u++;
		}
		if (Length61==0)
		{
			cout << "\n\n\t\tEnter atleast one character: ";
			Length61=0;
		}
		else if (Length61>1)
		{
			cout << "\n\n\t\tOnly one character is allowed: ";
			Length61=0;
		}
		else if (Length61==1)
		{
			switch(Choice61[0])
			{
				case '1':
					{
						system("cls");
						cout << "\n\n\n\t\t> You had " << Branch[Brancho].User[Usero].Cart << "/- Rs in your cart.";
						if ( (Branch[Brancho].User[Usero].Cart) < 500 )
						{
							cout << "\n\n\n\t\tYour cart needs to be recharged!";		
						}
						cout << "\n\n\t\t> Press enter to return to menu: ";
						getch();
						userMenu(Brancho,Usero);
						break;
					}
				case '2':
					{
						system("cls");
						cout << "\n\n\n\t\t> You had " << Branch[Brancho].User[Usero].movieCounter << " movies in your cart <\n";
						for (int y=0;y<(Branch[Brancho].User[Usero].movieCounter);y++)
						{
							if ( (Branch[Brancho].Movie[y].Status) == 0 )
							{
								cout << "\n\n\t  " << y+1 << "- " << Branch[Brancho].User[Usero].moviesInCart[y];
							}
						}
						cout << "\n\n\n\n\t\t> Press enter to return to menu: ";
						getch();
						userMenu(Brancho,Usero);
						break;
					}
				case '3':
					{
						system("cls");
						branchSearchMovie22(Brancho,Usero);
						cin.ignore(100,'\n');
						cout << "\n\n\n\t> Press enter to return to menu: ";
						getch();
						userMenu(Brancho,Usero);
						break;
					}
				case '4':
					{
						system("cls");
						cout << "\n\n\n\t\t> Movies are in the following order <";
						cout << "\n\n\t    Movie name, Genre, Price, Time, Release Date.\n";
						for(int l=0;l<movieCounter[Brancho];l++)
						{
							if ( (Branch[Brancho].Movie[l].Status) == 0 )
							{
								cout << "\n\n\t" << l+1 << "- " << Branch[Brancho].Movie[l].Name << ", " << Branch[Brancho].Movie[l].Genre << ", " << Branch[Brancho].Movie[l].Price << "/-Rs, " << Branch[Brancho].Movie[l].Time << ", " << Branch[Brancho].Movie[l].releaseDate << ".";
							}
						}
						cout << "\n\n\n\t\t> Press enter to return to menu: ";
						getch();
						userMenu(Brancho,Usero);
						break;
					}
				case '5':
					{
						system("cls");
						int Choice19=0;
						cout << "\n\n\n\t\t1- Update cart";
						cout << "\n\n\n\t\t2- Remove movie: ";
						cin >> Choice19;
						switch (Choice19)
						{
							case 1:
								{
									system("cls");
									cout << "\n\n\t\t> How much amount you want to be recharged: ";
									cin >> updateCartRequest[Brancho][Usero];
									cout << "\n\n\t\t> Cart update request submitted successfully.";
									cout << "\n\n\n\t\t\tPress enter to return to menu: ";
									cin.ignore(100,'\n');
									getch();
									userMenu(Brancho,Usero);							
									break;
								}
							case 2:
								{
									cin.ignore(100,'\n');
									branchSearchMovie28(Brancho,Usero);
									cin.ignore(100,'\n');
									cout << "\n\n\n\t\tPress enter to return to menu: ";
									getch();
									userMenu(Brancho,Usero);
									break;
								}
						}
						break;
					}
				case '6':
					{
						cout << "\n\t\t Signing out..";
						cout << "\n\t\t Press enter: ";
						getch();
						Menu();
						break;
					}
				default:
					{
						cout << "\n\n\t\tWrong input: ";
						Length61=0;
						break;
					}
			}
		}
	}
	while (Length61==0);
};

void branchSearchMovie22(int t,int q)
{
	bool Status=0;
	int Length=0;
	string movieEntered;
	cout << "\n\n\t\tEnter name of movie to search: ";
	do
	{
		getline (cin,movieEntered);
		Status=0;
		Length=0;
		if (movieEntered[0]==' ')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;	
		}
		else if (movieEntered[0]=='\0')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;		
		}
		else
		{
			for (int k=0;k<100;k++)
			{
				if ( isdigit(movieEntered[k]) )
				{
					cout << "\n\n\t\tDigits are not allowed!";
					cout << "\n\n\t\tEnter again: ";
					Status=0;
					break;
				}
				else if (movieEntered[k]=='\0')
				{
					Status=1;
					break;
				}
				Length++;
			}
		}
	}
	while (Status==0);
	
	int movieIndex=0;
	bool Status1=0;
	for (int j=0;j<5;j++)
	{
		for (int p=0;p<100;p++)
		{
			if( ( tolower(Branch[t].Movie[j].Name[p]) ) == ( tolower(movieEntered[p]) ) )
			{
				if (p==Length)
				{
					movieIndex=j;
					Status1=1;
				}
			}
			else
			{
				break;
			}			
		}
	}
	if (Status1==1)
	{
		system("cls");
		int Cwy;
		cout << "\n\n\t\t\t>> Movie found <<";
		cout << "\n\n\t\t> Movie is in the following order <\n\n";
		cout << "\n\n\t  - Movie name, Genre, Price, Time, Release Date.";
		cout << "\n\n\t  - " << Branch[t].Movie[movieIndex].Name << ", " << Branch[t].Movie[movieIndex].Genre << ", " << Branch[t].Movie[movieIndex].Price << "/-Rs, " << Branch[t].Movie[movieIndex].Time << ", " << Branch[t].Movie[movieIndex].releaseDate << ".";
		cout << "\n\n\n\n\t\t     > Press enter key..";
		getch();
		system("cls");
		cout << "\n\n\n\t\t1- Add to cart";
		cout << "\n\n\t\t2- Return to menu: ";
		cin >> Cwy;
		switch (Cwy)
		{
			case 1:
				{
					if ( Branch[t].User[q].movieCounter < 25 )
					{
						Branch[t].User[q].moviesInCart[Branch[t].User[q].movieCounter] = Branch[t].Movie[movieIndex].Name;
						Branch[t].User[q].movieCounter++;
						Branch[t].User[q].Cart -= Branch[t].Movie[movieIndex].Price;
						Branch[t].Earning += Branch[t].Movie[movieIndex].Price;
						cout << "\n\n\t> Movie " << Branch[t].Movie[movieIndex].Name << " added to your cart.";
					}
					else
					{
						cout << "\n\n\t> Your movie cart is full.";
					}
					break;
				}
			case 2:
				{		
					cin.ignore(100,'\n');
					userMenu(t,q);
					break;
				}
			default:
				{
					cout << "\n\n\t\tWrong input.";
					break;
				}
		}
	}
	else
	{
		cout << "\n\n\t\t> No match found for movie you entered.";
	}
};

void branchSearchMovie28(int t,int q)
{
	bool Status=0;
	int Length=0;
	string movieEntered;
	cout << "\n\n\t\tEnter name of movie to search: ";
	do
	{
		getline (cin,movieEntered);
		Status=0;
		Length=0;
		if (movieEntered[0]==' ')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;	
		}
		else if (movieEntered[0]=='\0')
		{
			cout << "\n\n\t\tInput atleast one character!";
			cout << "\n\n\t\tEnter again: ";
			Status=0;		
		}
		else
		{
			for (int k=0;k<100;k++)
			{
				if ( isdigit(movieEntered[k]) )
				{
					cout << "\n\n\t\tDigits are not allowed!";
					cout << "\n\n\t\tEnter again: ";
					Status=0;
					break;
				}
				else if (movieEntered[k]=='\0')
				{
					Status=1;
					break;
				}
				Length++;
			}
		}
	}
	while (Status==0);
	
	int movieIndex=0;
	bool Status1=0;
	for (int j=0;j<5;j++)
	{
		for (int p=0;p<100;p++)
		{
			if( ( tolower(Branch[t].Movie[j].Name[p]) ) == ( tolower(movieEntered[p]) ) )
			{
				if (p==Length)
				{
					movieIndex=j;
					Status1=1;
				}
			}
			else
			{
				break;
			}			
		}
	}
	if (Status1==1)
	{
		system("cls");
		int Cwy;
		cout << "\n\n\t\t\t>> Movie found <<";
		cout << "\n\n\t\t> Movie is in the following order <\n\n";
		cout << "\n\n\t  - Movie name, Genre, Price, Time, Release Date.";
		cout << "\n\n\t  - " << Branch[t].Movie[movieIndex].Name << ", " << Branch[t].Movie[movieIndex].Genre << ", " << Branch[t].Movie[movieIndex].Price << "/-Rs, " << Branch[t].Movie[movieIndex].Time << ", " << Branch[t].Movie[movieIndex].releaseDate << ".";
		cout << "\n\n\n\n\t\t     > Press enter key..";
		getch();
		system("cls");
		cout << "\n\n\n\t\t1- Remove from cart";
		cout << "\n\n\t\t2- Return to menu: ";
		cin >> Cwy;
		switch (Cwy)
		{
			case 1:
				{
					int Fou=0;
					if ( Branch[t].User[q].movieCounter > 0 )
					{
						for (int f=0;f<(Branch[t].User[q].movieCounter);f++)
						{
							if ( Branch[t].User[q].moviesInCart[f].compare(Branch[t].Movie[movieIndex].Name) == 0 )
							{
								Branch[t].User[q].movieCounter--;
								Branch[t].User[q].Cart += Branch[t].Movie[movieIndex].Price;
								Branch[t].Earning -= Branch[t].Movie[movieIndex].Price;
								cout << "\n\n\t> Movie " << Branch[t].Movie[movieIndex].Name << " removed from your cart.";
								Fou = f;
								break;
							}
						}
						for (int b=Fou;b<5;b++)
						{
							Branch[t].User[q].moviesInCart[b] = Branch[t].User[q].moviesInCart[b+1];
						}
					}
					else
					{
						cout << "\n\n\t> Your movie cart is empty.";
					}
					break;
				}
			case 2:
				{		
					cin.ignore(100,'\n');
					userMenu(t,q);
					break;
				}
			default:
				{
					cout << "\n\n\t\tWrong input.";
					break;
				}
		}
	}
	else
	{
		cout << "\n\n\t\t> No match found for movie you entered.";
	}
};
