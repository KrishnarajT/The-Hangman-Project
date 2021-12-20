#include "include/Header.h"
//Declaring Structure for the player File
struct Player_Info
{
	string Player_Name;
	int Themes[5] = {1, 0, 0, 0, 0};
	int points = 1000;
} Player_Info_Obj, Cur_Player_Info_Obj; //2 objects, 1 for the current player and another for retrieving information from the text file.

//Declaring the shapes
sf::RectangleShape Apple_Shape(sf::Vector2f(30.0f, 30.0f));
sf::RectangleShape Up_Border(sf::Vector2f(1060.0f, 15.0f));
sf::RectangleShape Down_Border(sf::Vector2f(1075.0f, 15.0f));
sf::RectangleShape Left_Border(sf::Vector2f(15.0f, 720.0f));
sf::RectangleShape Right_Border(sf::Vector2f(15.0f, 720.0f));

//Declaring the Default theme in the game ( Non Purchased )
string topic = "People", theme = "People";

//val is hte counter for the frames in the video displaying, life is the number of lives with the player.
int val = 0, life = 3;
string Answer;
//Declaring a general Parent class from which all the other classes can inherit basic variables.
class General
{
public:
	sf::Sprite Mini_Border;
	sf::Texture Background_Texture, Video_Texture, People_Texture, Border_Texture, Mini_Border_Texture;
	;
	sf::Sprite Back_Image, Video_Image, People_Image, Border, Soul_Stone_Video_Image, Loki_Video_Image;
	sf::Text Game_Name, Score_Disp_Text, Answer_Text, Life_Text, Life_Text_Val, Play_Game, How_To, About, Records, Quit, Store, ch1, ch2, ch3, ch4, ch5, ch6, Back_To_Menu, Present_Word, Time_Passed, Time_Val, Enter_Player_Name, Player_Name, Underline, Dialog, Topic_Select_Text;
	sf::Font font, fonthead, fontheadgame;
	//Funtion to delay some time
	void Delay(int millisecond)
	{
		bool a = 0;
		sf::Clock clock;
		while (a == 0)
		{
			sf::Time T1, T2;
			sf::Time delay = sf::milliseconds(millisecond);
			T1 = clock.getElapsedTime();
			if (T1.asMilliseconds() < delay.asMilliseconds())
			{
				a = 0;
			}
			else
			{
				a = 1;
			}
		}
	}
} General_Obj;

// Class inherited from the general class to draw teh dialog box on the screen for necessary events in the game specific to each scenario.
class Dialog_Box : public General
{
public:
	const char *ch1_c, *ch2_c;						   //char pointers to be converted from strings.
	string one, two, Score_Disp_Str, Answer_Str, Func; //Strings for the words to display in the dialog later to be converted into their correspondin char pointers.

	//Copy Constructor to assignt the values of one two and to know the scenario in which the dialog box is used.
	Dialog_Box(string a, string b, string Function_Of_Dialog_Box)
	{
		one = a;
		two = b;
		Func = Function_Of_Dialog_Box;
	}

	//Function to assign the basic attributes to the images in the dialog box.
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/greenback.jpg");
		Border_Texture.loadFromFile("Resources/Borders/Border5.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
		//font.loadFromFile("Resources/Fonts/amarurgt.ttf");
	}

	//Function to check which key is pressed so it can return a number accordingly in the respective scenario.
	//returns 0 if nothing is pressed and then after the loop it checks again.
	//only useful after a key is pressed and the function returns other than 0.
	int KeyPressChecker()
	{
		if (Func == "Topic Selection")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return 1;
			}
			else
				return 0;
		}
		else if (Func == "Settings")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return 1;
			}
			else
				return 0;
		}
		else if (Func == "Settings Cant")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return 1;
			}
			else
				return 0;
		}
		else if (Func == "Store Cant Buy")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return 1;
			}
			else
				return 0;
		}
		else if (Func == "Store Buy")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return 1;
			}
			else
				return 0;
		}
		else if (Func == "Game Over")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				return 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			{
				return 2;
			}
			else
				return 0;
		}
		else
			return 3;
	}

	//Function to assign attributed to the text in the dialog box.
	void SetText()
	{
		int Font_Size = 100, FontHead_Size = 35;
		//asssign differet origins in deffernt scenarios due to different spaces occupied by longer sentences.
		ch1.setOrigin(-115, -150);
		if (Func == "Game Over")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
			Score_Disp_Text.setOrigin(-560, -150);
			Score_Disp_Str = to_string(Player_Info_Obj.points);
			Answer_Str = Answer;
			Answer_Text.setOrigin(-125, -250);
		}
		else if (Func == "Settings")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
		}
		else if (Func == "Settings Cant")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
		}
		else if (Func == "Store Buy")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
		}
		else if (Func == "Store Cant Buy")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
		}
		else if (Func == "Topic Selection")
		{
			ch1.setOrigin(-115, -150);
			ch2.setOrigin(-550, -350);
		}

		//assigning the values of one to their character pointers.
		ch1_c = one.c_str();
		ch2_c = two.c_str();

		//attributes for indivudual text variables.
		ch1.setFont(fonthead);
		ch1.setString(ch1_c);
		ch1.setCharacterSize(FontHead_Size);
		ch1.setFillColor(sf::Color::Red);
		ch1.setStyle(sf::Text::Style::Bold);
		Score_Disp_Text.setFont(fonthead);
		Score_Disp_Text.setString(Score_Disp_Str);
		Score_Disp_Text.setCharacterSize(FontHead_Size);
		Score_Disp_Text.setFillColor(sf::Color::Blue);
		Score_Disp_Text.setStyle(sf::Text::Style::Bold);
		Answer_Text.setFont(fonthead);
		Answer_Text.setString(Answer_Str);
		Answer_Text.setCharacterSize(FontHead_Size);
		Answer_Text.setFillColor(sf::Color::Blue);
		Answer_Text.setStyle(sf::Text::Style::Bold);
		ch2.setFont(fonthead);
		ch2.setString(ch2_c);
		ch2.setCharacterSize(FontHead_Size);
		ch2.setFillColor(sf::Color::Black);
		ch2.setStyle(sf::Text::Style::Bold);
		ch3.setFont(fonthead);
		ch3.setString("BACK TO MENU");
		ch3.setCharacterSize(FontHead_Size);
		ch3.setFillColor(sf::Color::Black);
		ch3.setStyle(sf::Text::Style::Bold);
		ch3.setOrigin(-100, -350);
	}
	int Main()
	{
		int Return_Val; //value of the key pressed.
		sf::RenderWindow window(sf::VideoMode(800, 500), "Look at me !!!!", sf::Style::Resize);
		SetText();
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			SetAttributes();
			Return_Val = KeyPressChecker();
			window.clear(sf::Color::White); //make the background white
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(ch1);
			window.draw(Score_Disp_Text);
			window.draw(Answer_Text);
			window.draw(ch2);
			window.draw(ch3);
			window.display();
			//we know that KeypressChecker() returns values from 0 to a positive number, if that number is 0, we just proceed to check again.
			if (Return_Val == 1 || Return_Val == 2)
				return Return_Val;
			else if (Return_Val == 3)
				return 3; //3 stands for incorrect value for the function of the Dialog Box
		}
	}
} Play_Over_Disp("YOUR TOTAL SCORE IS ", "REPEAT", "Game Over"),
	Settings_Disp("THEME CHANGED", "OK", "Settings"),
	Settings_Disp_Cant("ITEM NOT BOUGHT", "OK", "Settings Cant"),
	Store_Buy_Disp("THEME PURCHASED !", "OK", "Store Buy"),
	Store_Cantbuy_Disp("NOT ENOUGH POINTS TO PURCHASE", "OK", "Store Cant Buy");

//class to do the files for the player and to accept the name of the player.
class Player : public General
{
public:
	int sizeofobj = sizeof(Player_Info_Obj);
	string filename, Player_Name_Str = "";
	sf::Clock clock;
	sf::Time T1;

	//integers for each letter that the user can press.
	int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1, l = 1, n = 1, m = 1, o = 1, p = 1, q = 1, r = 1, s = 1, t = 1, u = 1, v = 1, w = 1, x = 1, y = 1, z = 1, space = 1;
	int I = 0, J = 0, Input_Done = 0, Text_Done = 0, ankey = 0, ramesh, found, checkres;
	char Player_Name_Char;
	string theme, Cur_Player_Name = "";
	const char *cstr1, *cstr2;

	//assign the attributes for each image in the player section.
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/background3.png");
		Border_Texture.loadFromFile("Resources/Borders/Border3.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		Mini_Border.setTexture(Mini_Border_Texture);
	}

	//set the attributes for each text in the player section.
	void SetText()
	{
		//if the input is done i.e the user has pressed enter for giving his name this var becomes 1 meaning the player is accepted.
		if (Input_Done == 1)
		{
			cstr1 = "PLAYER ACCEPTED";
		}
		else
		{
			cstr1 = ""; // do not display anythign on the screen.
		}
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
		Game_Name.setFont(font);
		Game_Name.setString("HANG MAN");
		Game_Name.setCharacterSize(100);
		Game_Name.setFillColor(sf::Color::Blue);
		Game_Name.setStyle(sf::Text::Style::Bold);
		Game_Name.setStyle(sf::Text::Style::Underlined);
		Game_Name.setOrigin(-650, -20);
		Enter_Player_Name.setFont(fonthead);
		Enter_Player_Name.setString("ENTER PLAYER NAME");
		Enter_Player_Name.setCharacterSize(50);
		Enter_Player_Name.setFillColor(sf::Color::Black);
		Enter_Player_Name.setOrigin(-650, -200);
		Dialog.setFont(fonthead);
		Dialog.setString(cstr1);
		Dialog.setCharacterSize(50);
		Dialog.setFillColor(sf::Color::Black);
		Dialog.setOrigin(-650, -500);
		//Enter_Player_Name.setStyle(sf::Text::Style::);
		//Enter_Player_Name.setStyle(sf::Text::Style::Underlined);
		Player_Name.setFont(fonthead);
		Player_Name.setString(Player_Name_Str);
		Player_Name.setCharacterSize(50);
		Player_Name.setFillColor(sf::Color::Red);
		Player_Name.setStyle(sf::Text::Style::Italic);
		Player_Name.setOrigin(-700, -325);
		Underline.setFont(fonthead);
		Underline.setString("________________________________________________");
		Underline.setCharacterSize(40);
		Underline.setFillColor(sf::Color::Blue);
		Underline.setStyle(sf::Text::Style::Bold);
		Underline.setOrigin(-300, -350);
	}

	//Function to simulate the keyboard and get the name of the player.

	// we want to simulate how an actual keyboard works when we type as this is almost that.
	/*
	when we generally press a key on the keyboard, we keep our finger on that key of the keyboard for some 20 milliseconds.
	a
	this program takes less than 1 millisecond to run again and so it check whether you have entered something more than 500 times a second
	so if we keep the finger on the keyboard for 20 milliseconds, it will print a 20 times on the screen, which is a problem as we only want 1 
	if we keep our finger on the keyboard (key pressed) , for about 1500 milliseconds, then the keyboard recognises that we want to repeat the 
	letter many times( like how we do in backspace )
	so it waits for us to press the key for about 100 milliseconds.
	after 1500 ms it displays a lot of the letter 
	eg aaaaaaaaaaaaaaaaaaaaaaaaa
	*more like*
	a (waits for 1500 ms) aaaaaaaaaaaaaaaaaaaa
	now in these 100 ms, we can press another character like b then it would have to wit for another 100 ms to show lots of bbbbb
	eg a (wait20 ms) b (wait 1500ms) bbbbbbbbbbbbbbbbb

	so we need to tell the computer to keep track of how many milliseconds has passed after we press the key a
	so after every 50 milliseconds, we increment an integer I whose value is initially equal to J
	so after I gets incremented 50 times, around 50 * 50 milliseconds have passed
	so we can release the buffer to print a many times.
	then we assign the value of I to J and then we can repeat the process again.
	a
	Now, when we press a key, and then we go to press another key, we press the other key without actually letting go of the previous key
	in other words, we press 2 keys at the same time which messes up the code logic as both go one after the other and at that time, we do not 
	check any condition so both go on pressing for ever very fast, for avoiding this, we introduce 'ankey' variable.
	ankey starts working when we press 2 keys at the same time, it has a default value of 0 as in everything is fine no keys are pressed twice
	
	the last key pressed by the user is not A and it has been pressed before 50 ms of pressing the last key which lets assume is B
	provided that ankey is either 0 or 1 (because this may happen repeatedly); the value of ankey is set to the value of the alphabet pressed
	in numerical order.
	a=1
	b=2
	and so on.
	so in this case ankey is 1. so when b is pressed at the same time, b wont be assigned to the player name because of an && statement 
	that requires ankey to be either 2 or 0.
	and one it has been 100 ms after pressing any key, ankey will set itself to 0 so other keys can be pressed.
	
	*/
	string Get_Player_Name()
	{
		//everytime this function starts, restart the clock
		T1 = clock.getElapsedTime();

		//ankey = whether the user has pressed another key
		//Player_Name_Char is the letter that hthe user presses.
		//T1 is the elapsed time.
		//I is always 0
		//J is the number of times
		//boolean a = 1 means A is free to be used in the next iteration, 0 means a was already used b4
		//if the user has not pressed a before this and since he pressed the last letter, the elapsed time is less than 50 milliseconds,
		//and he has pressed A now wth less than 50 milliseconds from the last time he pressed something, then Ankey is 1.
		//assume that A and B are pressed together
		if (Player_Name_Char != 'A' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ankey == 0)
		{
			ankey = 1;
		}

		//if the time passed since the last time the user pressed something is more than 100 milliseconds, ankey is 0, irrespective of the key pressed.
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}

		//if the last key pressed by the user was A
		if (Player_Name_Char == 'A')
		{
			//if the player has pressed the last key A and he has also pressed A now, and ankey is either 1 or 0
			//This section is to check whether or not to show repeated A because it is possible to reach here only if you have pressed a before
			//checks if A is pressed now and if it is not pressed with some other letter ( ankey is 1 or 0 ).
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (ankey == 1 || ankey == 0))
			{
				clock.restart(); //restart the clock because the user pressed a key for sure, only then this if loop is iterated

				//if the time passed after the user pressed A is Greater than 50 milliseconds, or if I-J is 50 or if boolean A is 0,
				if (T1.asMilliseconds() > 50 || I - J == 50 || a == 0)
				{
					Player_Name_Char = 'A';				 //set the character pressed to A
					Player_Name_Str += Player_Name_Char; //add the player character to the name of the player

					//the I-J is in the || condition so we have to check it again
					if (I - J == 50)
					{
						//a is generally not 0 but if it is 0 that means the user has pressed a for more then 2500 (50*50) milliseconds
						//so we will assign a to 0 so that in the if loop above, a is checked to be 0 and it will keep displaying 1 but
						//it wont show that until i increments 50 times so that the difference bw i and j is 50.
						a = 0;
					}

					//if this if loop runs then the user has pressed A before this and now also, so the vallues of I and J must be same
					//for the next checking
					//its kept after the if condition above or else that condition wont ever run.
					J = I;
					//The J = I condition is vital here,
					//when this loop runs, it will display a on the screen and then the I-j=50 part becomes useless and the t1>50 ms becomes imp
					//as if it takes more than 50 ms, then you have obviously lifted your finger so you are nor trying to do a lot of aaaa
					//so at that point this loop runs because of the if loop on top and then i=j. also the if loop on the bottom ensures that if you have
					//started pressing a lot of aaaa then obviously boolean a will be 0 coz of the if loop above and if you wait for mre than 50 ms, u dont want
					// to press a lot of aaaa so the if condition down will ensure that the boolean a is set back to 1
				}
				if (T1.asMilliseconds() > 50)
				{
					a = 1;
				}
				//if the time passed after the use pressed a the last time is less than 50 ms increment I
				else
				{
					I++;
				}
			}
		}

		//If the last  key pressed by the user was not A, and the user presses A
		//ankey is either 1 or 0 so no 2 letters are pressed together
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (ankey == 1 || ankey == 0))
		{
			I = J = 0;							 //the value of I and J is same is 0.
			Player_Name_Char = 'A';				 //the player presses a assign the playernamechar to A
			Player_Name_Str += Player_Name_Char; //add this character that the user just pressed to the name of the player
			a = 1;								 //boolean A = 1 that means
			clock.restart();
		}

		if (Player_Name_Char != 'B' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::B) && ankey == 0)
		{
			ankey = 2;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'B')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (ankey == 2 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || b == 0)
				{
					Player_Name_Char = 'B';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						b = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					b = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (ankey == 2 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'B';
			Player_Name_Str += Player_Name_Char;
			b = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'C' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::C) && ankey == 0)
		{
			ankey = 3;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'C')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (ankey == 3 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || c == 0)
				{
					Player_Name_Char = 'C';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						c = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					c = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (ankey == 3 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'C';
			Player_Name_Str += Player_Name_Char;
			c = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'D' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ankey == 0)
		{
			ankey = 4;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'D')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (ankey == 4 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || d == 0)
				{
					Player_Name_Char = 'D';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						d = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					d = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (ankey == 4 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'D';
			Player_Name_Str += Player_Name_Char;
			d = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'E' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::E) && ankey == 0)
		{
			ankey = 5;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'E')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (ankey == 5 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || e == 0)
				{
					Player_Name_Char = 'E';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						e = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					e = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (ankey == 5 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'E';
			Player_Name_Str += Player_Name_Char;
			e = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'F' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::F) && ankey == 0)
		{
			ankey = 6;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'F')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && (ankey == 6 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || f == 0)
				{
					Player_Name_Char = 'F';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						f = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					f = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && (ankey == 6 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'F';
			Player_Name_Str += Player_Name_Char;
			f = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'G' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::G) && ankey == 0)
		{
			ankey = 7;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'G')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && (ankey == 7 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || g == 0)
				{
					Player_Name_Char = 'G';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						g = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					g = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && (ankey == 7 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'G';
			Player_Name_Str += Player_Name_Char;
			g = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'H' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::H) && ankey == 0)
		{
			ankey = 8;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'H')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && (ankey == 8 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || h == 0)
				{
					Player_Name_Char = 'H';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						h = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					h = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && (ankey == 8 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'H';
			Player_Name_Str += Player_Name_Char;
			h = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'I' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::I) && ankey == 0)
		{
			ankey = 9;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'I')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && (ankey == 9 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || i == 0)
				{
					Player_Name_Char = 'I';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						i = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					i = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && (ankey == 9 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'I';
			Player_Name_Str += Player_Name_Char;
			i = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'J' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && ankey == 0)
		{
			ankey = 10;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'J')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && (ankey == 10 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || j == 0)
				{
					Player_Name_Char = 'J';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						j = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					j = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && (ankey == 10 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'J';
			Player_Name_Str += Player_Name_Char;
			j = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'K' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::K) && ankey == 0)
		{
			ankey = 11;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'K')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && (ankey == 11 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || k == 0)
				{
					Player_Name_Char = 'K';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						k = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					k = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && (ankey == 11 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'K';
			Player_Name_Str += Player_Name_Char;
			k = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'L' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::L) && ankey == 0)
		{
			ankey = 12;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'L')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (ankey == 12 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || l == 0)
				{
					Player_Name_Char = 'L';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						l = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					l = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (ankey == 12 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'L';
			Player_Name_Str += Player_Name_Char;
			l = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'M' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::M) && ankey == 0)
		{
			ankey = 13;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'M')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && (ankey == 13 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || m == 0)
				{
					Player_Name_Char = 'M';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						m = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					m = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && (ankey == 13 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'M';
			Player_Name_Str += Player_Name_Char;
			m = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'N' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::N) && ankey == 0)
		{
			ankey = 14;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'N')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && (ankey == 14 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || n == 0)
				{
					Player_Name_Char = 'N';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						n = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					n = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && (ankey == 14 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'N';
			Player_Name_Str += Player_Name_Char;
			n = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'O' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::O) && ankey == 0)
		{
			ankey = 15;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'O')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && (ankey == 15 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || o == 0)
				{
					Player_Name_Char = 'O';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						o = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					o = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && (ankey == 15 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'O';
			Player_Name_Str += Player_Name_Char;
			o = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'P' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::P) && ankey == 0)
		{
			ankey = 16;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'P')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (ankey == 16 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || p == 0)
				{
					Player_Name_Char = 'P';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						p = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					p = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (ankey == 16 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'P';
			Player_Name_Str += Player_Name_Char;
			p = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Q' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && ankey == 0)
		{
			ankey = 17;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Q')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (ankey == 17 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || q == 0)
				{
					Player_Name_Char = 'Q';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						q = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					q = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (ankey == 17 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Q';
			Player_Name_Str += Player_Name_Char;
			q = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'R' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::R) && ankey == 0)
		{
			ankey = 18;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'R')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (ankey == 18 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || r == 0)
				{
					Player_Name_Char = 'R';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						r = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					r = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (ankey == 18 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'R';
			Player_Name_Str += Player_Name_Char;
			r = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'S' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ankey == 0)
		{
			ankey = 19;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'S')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (ankey == 19 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || s == 0)
				{
					Player_Name_Char = 'S';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						s = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					s = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (ankey == 19 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'S';
			Player_Name_Str += Player_Name_Char;
			s = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'T' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::T) && ankey == 0)
		{
			ankey = 20;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'T')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && (ankey == 20 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || t == 0)
				{
					Player_Name_Char = 'T';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						t = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					t = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && (ankey == 20 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'T';
			Player_Name_Str += Player_Name_Char;
			t = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'U' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::U) && ankey == 0)
		{
			ankey = 21;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'U')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && (ankey == 21 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || u == 0)
				{
					Player_Name_Char = 'U';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						u = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					u = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && (ankey == 21 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'U';
			Player_Name_Str += Player_Name_Char;
			u = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'V' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::V) && ankey == 0)
		{
			ankey = 22;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'V')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && (ankey == 22 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || v == 0)
				{
					Player_Name_Char = 'V';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						v = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					v = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && (ankey == 22 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'V';
			Player_Name_Str += Player_Name_Char;
			v = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'W' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ankey == 0)
		{
			ankey = 23;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'W')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (ankey == 23 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || w == 0)
				{
					Player_Name_Char = 'W';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						w = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					w = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (ankey == 23 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'W';
			Player_Name_Str += Player_Name_Char;
			w = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'X' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::X) && ankey == 0)
		{
			ankey = 24;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'X')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (ankey == 24 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || x == 0)
				{
					Player_Name_Char = 'X';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						x = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					x = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (ankey == 24 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'X';
			Player_Name_Str += Player_Name_Char;
			x = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Y' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && ankey == 0)
		{
			ankey = 25;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Y')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && (ankey == 25 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || y == 0)
				{
					Player_Name_Char = 'Y';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						y = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					y = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && (ankey == 25 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Y';
			Player_Name_Str += Player_Name_Char;
			y = 1;
			clock.restart();
		}

		if (Player_Name_Char != 'Z' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && ankey == 0)
		{
			ankey = 26;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == 'Z')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (ankey == 26 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || z == 0)
				{
					Player_Name_Char = 'Z';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						z = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					z = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (ankey == 26 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = 'Z';
			Player_Name_Str += Player_Name_Char;
			z = 1;
			clock.restart();
		}

		if (Player_Name_Char != ' ' && T1.asMilliseconds() < 50 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && ankey == 0)
		{
			ankey = 27;
		}
		if (T1.asMilliseconds() > 100)
		{
			ankey = 0;
		}
		if (Player_Name_Char == ' ')
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (ankey == 27 || ankey == 0))
			{
				clock.restart();
				if (T1.asMilliseconds() > 50 || I - J == 50 || space == 0)
				{
					Player_Name_Char = ' ';
					Player_Name_Str += Player_Name_Char;
					if (I - J == 50)
					{
						space = 0;
					}
					J = I;
				}
				if (T1.asMilliseconds() > 50)
				{
					space = 1;
				}
				else
				{
					I++;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (ankey == 27 || ankey == 0))
		{
			I = J = 0;
			Player_Name_Char = ' ';
			Player_Name_Str += Player_Name_Char;
			space = 1;
			clock.restart();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			cout << "return pressed";
			Input_Done = 1;
			return Player_Name_Str;
		}
		else
			return "NOT ENTERED YET";
	}

	int Cur_Player_Loc = -1; //location of the player in the file

	//Update a player record in the file.
	void update()
	{
		fstream fcom;
		fcom.open("Player_Info.dat", ios::binary | ios::app);
		fcom.seekp((Cur_Player_Loc * sizeofobj), ios::beg); //change the position of the put pointer to 1 minus the current position.
		fcom.write((char *)&Player_Info_Obj, sizeofobj);	//write to that position
		fcom.close();
	}

	//Fumction to check whether the player's name is already in the file.
	int check()
	{
		ifstream fin;
		fin.open("Player_info.dat", ios::binary);

		while (!fin.eof())
		{
			fin.read((char *)&Cur_Player_Info_Obj, sizeofobj);		//write hte player name to Cur_Player_Info_Obj
			if (Cur_Player_Info_Obj.Player_Name == Cur_Player_Name) //If that name is the name that the player entered, found is 1 and function stops.
			{
				found = 1;
				break;
			}
			else
			{
				found = 0;
				Cur_Player_Loc++;
			}
		}
		fin.close();
		if (found == 1)
		{
			return 1;
		}
		else
			return 0;
	} //if found is 1 then we update else it's a new player and so we write a new record.

	int Main()
	{
		found = 0;
		SetAttributes();
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "										INPUT PLAYER NAME", sf::Style::Resize | sf::Style::Close);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			if (Input_Done == 0)
			{
				Cur_Player_Name = Get_Player_Name();
			}
			SetText();
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(Game_Name);
			window.draw(Enter_Player_Name);
			window.draw(Dialog);
			window.draw(Player_Name);
			window.draw(Underline);
			window.display();
			if (Input_Done == 1) //if the input is done then check the name after delaying for 2 seconds
			{
				Delay(1200);
				//check returns 1 if the name was found else 0.
				return check();
			}
		}
	}
} Player_Obj;

//Class to assign the path of the images to display to the respective textures for the respepctive themes for each life.
class Video_and_Image_Files : public General
{
public:
	string filename;
	int val = 1;
	//JOHN WICK
	//to display before the player makes any mistake
	void Play_Video_Theme_1_Scene_Null()
	{
		filename = "Themes/John Wick/Null.jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_1_Scene_1()
	{
		filename = "Themes/John Wick/Wife/Wife (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_1_Scene_2()
	{
		filename = "Themes/John Wick/Dog/Dog (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_1_Scene_3()
	{
		filename = "Themes/John Wick/Him/Him (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	//to display after the player wins the game
	void Play_Video_Theme_1_Scene_Win()
	{
		filename = "Themes/John Wick/Dog/Dog (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}

	//classic Hangman
	//life = 6;
	//to display before the player makes any mistake
	void Show_Image_Theme_2_Pic_Null()
	{
		filename = "Themes/Classic/Hangman-0.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_1()
	{
		filename = "Themes/Classic/Hangman-1.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_2()
	{
		filename = "Themes/Classic/Hangman-2.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_3()
	{
		filename = "Themes/Classic/Hangman-3.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_4()
	{
		filename = "Themes/Classic/Hangman-4.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_5()
	{
		filename = "Themes/Classic/Hangman-5.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_Image_Theme_2_Pic_6()
	{
		filename = "Themes/Classic/Hangman-6.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	//To display after the player wins the game
	void Show_Image_Theme_2_Pic_Win()
	{
		filename = "Themes/Classic/Hangman-Win.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}

	//Harry Potter
	//to display before the player makes any mistake
	void Show_Image_Theme_3_Pic_Null()
	{
		filename = "Themes/Harry Potter/Null.jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_1()
	{
		filename = "Themes/Harry Potter/Lily/Lily (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_2()
	{
		filename = "Themes/Harry Potter/Hedwig/Hedwig (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_4()
	{
		filename = "Themes/Harry Potter/Dumbledore/Dumbledore (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_5()
	{
		filename = "Themes/Harry Potter/Dobby/Dobby (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_6()
	{
		filename = "Themes/Harry Potter/Sirius/Sirius (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_7()
	{
		filename = "Themes/Harry Potter/Snape/Snape (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_3()
	{
		filename = "Themes/Harry Potter/Cedric/Cedric (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_3_Scene_Win()
	{
		filename = "Themes/Harry Potter/Voldemort/Voldemort (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}

	//Marvel
	//to display before the player makes any mistake
	void Show_Image_Theme_4_Pic_Null()
	{
		filename = "Themes/Marvel/Null.png";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_1()
	{
		filename = "Themes/Marvel/Space Stone/Space_Stone (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_2()
	{
		filename = "Themes/Marvel/Loki/Loki (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_3()
	{
		filename = "Themes/Marvel/Soul Stone/Soul_Stone (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_4()
	{
		filename = "Themes/Marvel/Reality Stone/Reality_Stone (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_5()
	{
		filename = "Themes/Marvel/Stabbing Tony/Stabbing_Tony (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_6()
	{
		filename = "Themes/Marvel/Time Stone/Time_Stone (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_7()
	{
		filename = "Themes/Marvel/Mind Stone/Mind_Stone (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_8()
	{
		filename = "Themes/Marvel/The Snap/The_Snap (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Play_Video_Theme_4_Scene_Win()
	{
		filename = "Themes/Marvel/Tony Snap/Tony_Snap (" + to_string(val);
		filename += ").jpg";
		const char *cstr = filename.c_str();
		Video_Texture.loadFromFile(cstr);
		Video_Image.setTexture(Video_Texture);
		val++;
	}
	void Show_People_Pic(string name)
	{
		filename = "Themes/People/" + name;
		filename += ".jpg";
		const char *cstr = filename.c_str();
		People_Texture.loadFromFile(cstr);
		People_Image.setTexture(People_Texture);
	}
};

//The Main Game Function.
class Play_Game : public Video_and_Image_Files
{
public:
	sf::Text A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
	bool a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1, l = 1, n = 1, m = 1, o = 1, p = 1, q = 1, r = 1, s = 1, t = 1, u = 1, v = 1, w = 1, xx = 1, y = 1, z = 1;
	int Dialog_Res, life = 3, res; //res is for the result of the main function and Dialog_Res is for the returned value of the dialog box.
	string filename;
	sf::Clock clock; //clock initiates upon declaration in the stack here.
	sf::Time Time_Passed_S;
	Play_Game() //assign the values of the variables.
	{
		a = 1;
		b = 1;
		c = 1;
		d = 1;
		e = 1;
		f = 1;
		g = 1;
		h = 1;
		i = 1;
		j = 1;
		k = 1;
		l = 1;
		n = 1;
		m = 1;
		o = 1;
		p = 1;
		q = 1;
		r = 1;
		s = 1;
		t = 1;
		u = 1;
		v = 1;
		w = 1;
		xx = 1;
		y = 1;
		z = 1;
		res = 0;
		val = 0;
	}

	//Function to assign the attributes to the images in the game
	void SetAttributes()
	{
		Video_Image.setOrigin(-160, -310);
		People_Image.setOrigin(-160, -310);
		Mini_Border.setOrigin(-15, -200);
		Background_Texture.loadFromFile("Resources/Backgrounds/background3.png");
		Mini_Border_Texture.loadFromFile("Resources/Borders/Mini_Border4.png");
		Border_Texture.loadFromFile("Resources/Borders/Border3.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		Mini_Border.setTexture(Mini_Border_Texture);
	}

	//Returns the letter that gets pressed and sets the boolean of hte vatiable to 0 that makes the color of the variable red on the screen.
	char KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && a == 1)
		{
			a = 0;
			return 'A';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && b == 1)
		{
			b = 0;
			return 'B';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && c == 1)
		{
			c = 0;
			return 'C';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && d == 1)
		{
			d = 0;
			return 'D';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && e == 1)
		{
			e = 0;
			return 'E';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && f == 1)
		{
			f = 0;
			return 'F';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && g == 1)
		{
			g = 0;
			return 'G';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && h == 1)
		{
			h = 0;
			return 'H';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && i == 1)
		{
			i = 0;
			return 'I';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && j == 1)
		{
			j = 0;
			return 'J';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && k == 1)
		{
			k = 0;
			return 'K';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && l == 1)
		{
			l = 0;
			return 'L';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && m == 1)
		{
			m = 0;
			return 'M';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && n == 1)
		{
			n = 0;
			return 'N';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && o == 1)
		{
			o = 0;
			return 'O';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && p == 1)
		{
			p = 0;
			return 'P';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && q == 1)
		{
			q = 0;
			return 'Q';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && r == 1)
		{
			r = 0;
			return 'R';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && s == 1)
		{
			s = 0;
			return 'S';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && t == 1)
		{
			t = 0;
			return 'T';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && u == 1)
		{
			u = 0;
			return 'U';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && v == 1)
		{
			v = 0;
			return 'V';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && w == 1)
		{
			w = 0;
			return 'W';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && xx == 1)
		{
			xx = 0;
			return 'X';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && y == 1)
		{
			y = 0;
			return 'Y';
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && z == 1)
		{
			z = 0;
			return 'Z';
		}
		else
			return '#';
	}
	void SetText(string Cur_Word, int Time_Passed_Int)
	{
		sf::Color color, Pressed_Color, Not_Pressed_Color;
		Not_Pressed_Color = sf::Color::Blue;
		Pressed_Color = sf::Color::Red;
		int x = -50; //x is the factor of multiplication in the separation of the digits.

		//Change the color of the letter upon the boolean changed in the previous function.
		if (a == 0)
			A.setFillColor(Pressed_Color);
		else
			A.setFillColor(Not_Pressed_Color);
		if (b == 0)
			B.setFillColor(Pressed_Color);
		else
			B.setFillColor(Not_Pressed_Color);
		if (c == 0)
			C.setFillColor(Pressed_Color);
		else
			C.setFillColor(Not_Pressed_Color);
		if (d == 0)
			D.setFillColor(Pressed_Color);
		else
			D.setFillColor(Not_Pressed_Color);
		if (e == 0)
			E.setFillColor(Pressed_Color);
		else
			E.setFillColor(Not_Pressed_Color);
		if (f == 0)
			F.setFillColor(Pressed_Color);
		else
			F.setFillColor(Not_Pressed_Color);
		if (g == 0)
			G.setFillColor(Pressed_Color);
		else
			G.setFillColor(Not_Pressed_Color);
		if (h == 0)
			H.setFillColor(Pressed_Color);
		else
			H.setFillColor(Not_Pressed_Color);
		if (i == 0)
			I.setFillColor(Pressed_Color);
		else
			I.setFillColor(Not_Pressed_Color);
		if (j == 0)
			J.setFillColor(Pressed_Color);
		else
			J.setFillColor(Not_Pressed_Color);
		if (k == 0)
			K.setFillColor(Pressed_Color);
		else
			K.setFillColor(Not_Pressed_Color);
		if (l == 0)
			L.setFillColor(Pressed_Color);
		else
			L.setFillColor(Not_Pressed_Color);
		if (m == 0)
			M.setFillColor(Pressed_Color);
		else
			M.setFillColor(Not_Pressed_Color);
		if (n == 0)
			N.setFillColor(Pressed_Color);
		else
			N.setFillColor(Not_Pressed_Color);
		if (o == 0)
			O.setFillColor(Pressed_Color);
		else
			O.setFillColor(Not_Pressed_Color);
		if (p == 0)
			P.setFillColor(Pressed_Color);
		else
			P.setFillColor(Not_Pressed_Color);
		if (q == 0)
			Q.setFillColor(Pressed_Color);
		else
			Q.setFillColor(Not_Pressed_Color);
		if (r == 0)
			R.setFillColor(Pressed_Color);
		else
			R.setFillColor(Not_Pressed_Color);
		if (s == 0)
			S.setFillColor(Pressed_Color);
		else
			S.setFillColor(Not_Pressed_Color);
		if (t == 0)
			T.setFillColor(Pressed_Color);
		else
			T.setFillColor(Not_Pressed_Color);
		if (u == 0)
			U.setFillColor(Pressed_Color);
		else
			U.setFillColor(Not_Pressed_Color);
		if (v == 0)
			V.setFillColor(Pressed_Color);
		else
			V.setFillColor(Not_Pressed_Color);
		if (w == 0)
			W.setFillColor(Pressed_Color);
		else
			W.setFillColor(Not_Pressed_Color);
		if (xx == 0)
			X.setFillColor(Pressed_Color);
		else
			X.setFillColor(Not_Pressed_Color);
		if (y == 0)
			Y.setFillColor(Pressed_Color);
		else
			Y.setFillColor(Not_Pressed_Color);
		if (z == 0)
			Z.setFillColor(Pressed_Color);
		else
			Z.setFillColor(Not_Pressed_Color);
		A.setFont(fonthead);
		A.setString("A");
		A.setCharacterSize(50);
		//A.setStyle(sf::Text::Style::Bold);
		Game_Name.setFont(fonthead);
		Game_Name.setString("HANG MAN");
		Game_Name.setCharacterSize(100);
		Game_Name.setFillColor(sf::Color::Black);
		Game_Name.setStyle(sf::Text::Style::Bold);
		Game_Name.setStyle(sf::Text::Style::Underlined);
		Game_Name.setOrigin(-650, -20);
		Time_Passed.setFont(fonthead);
		Time_Passed.setString("TIME LEFT :");
		Time_Passed.setCharacterSize(50);
		Time_Passed.setFillColor(sf::Color::Red);
		Time_Passed.setOrigin(-1500, -450);
		Life_Text.setFont(fonthead);
		Life_Text.setString("LIVES LEFT :");
		Life_Text.setCharacterSize(50);
		Life_Text.setFillColor(sf::Color::Red);
		Life_Text.setOrigin(-1500, -250);
		Life_Text_Val.setFont(fonthead);
		Life_Text_Val.setString(to_string(life));
		Life_Text_Val.setCharacterSize(70);
		Life_Text_Val.setFillColor(sf::Color::Blue);
		Life_Text_Val.setOrigin(-1500, -350);
		Time_Val.setFont(fonthead);
		Time_Val.setString(to_string(Time_Passed_Int));
		Time_Val.setCharacterSize(70);

		//Change the Color of the timer if the time is less than 10.
		if (Time_Passed_Int > 10)
			Time_Val.setFillColor(sf::Color::Green);
		else
			Time_Val.setFillColor(sf::Color::Red);

		Time_Val.setStyle(sf::Text::Style::Bold);
		Time_Val.setOrigin(-1500, -550);
		int X_Offset_For_Alphabets = 300, Y_Offset_For_Alphabets = 170;
		A.setOrigin(-X_Offset_For_Alphabets, -Y_Offset_For_Alphabets);
		B.setFont(fonthead);
		B.setString("B");
		B.setCharacterSize(50);
		//B.setStyle(sf::Text::Style::Bold);
		B.setOrigin(-X_Offset_For_Alphabets + x, -Y_Offset_For_Alphabets);
		C.setFont(fonthead);
		C.setString("C");
		C.setCharacterSize(50);
		//C.setStyle(sf::Text::Style::Bold);
		C.setOrigin(-X_Offset_For_Alphabets + 2 * x, -Y_Offset_For_Alphabets);
		D.setFont(fonthead);
		D.setString("D");
		D.setCharacterSize(50);
		//D.setStyle(sf::Text::Style::Bold);
		D.setOrigin(-X_Offset_For_Alphabets + 3 * x, -Y_Offset_For_Alphabets);
		E.setFont(fonthead);
		E.setString("E");
		E.setCharacterSize(50);
		//E.setStyle(sf::Text::Style::Bold);
		E.setOrigin(-X_Offset_For_Alphabets + 4 * x, -Y_Offset_For_Alphabets);
		F.setFont(fonthead);
		F.setString("F");
		F.setCharacterSize(50);
		//F.setStyle(sf::Text::Style::Bold);
		F.setOrigin(-X_Offset_For_Alphabets + 5 * x, -Y_Offset_For_Alphabets);
		G.setFont(fonthead);
		G.setString("G");
		G.setCharacterSize(50);
		//G.setStyle(sf::Text::Style::Bold);
		G.setOrigin(-X_Offset_For_Alphabets + 6 * x, -Y_Offset_For_Alphabets);
		H.setFont(fonthead);
		H.setString("H");
		H.setCharacterSize(50);
		//H.setStyle(sf::Text::Style::Bold);
		H.setOrigin(-X_Offset_For_Alphabets + 7 * x, -Y_Offset_For_Alphabets);
		I.setFont(fonthead);
		I.setString("I");
		I.setCharacterSize(50);
		//I.setStyle(sf::Text::Style::Bold);
		I.setOrigin(-X_Offset_For_Alphabets + 8 * x, -Y_Offset_For_Alphabets);
		J.setFont(fonthead);
		J.setString("J");
		J.setCharacterSize(50);
		//J.setStyle(sf::Text::Style::Bold);
		J.setOrigin(-X_Offset_For_Alphabets + 9 * x, -Y_Offset_For_Alphabets);
		K.setFont(fonthead);
		K.setString("K");
		K.setCharacterSize(50);
		//K.setStyle(sf::Text::Style::Bold);
		K.setOrigin(-X_Offset_For_Alphabets + 10 * x, -Y_Offset_For_Alphabets);
		L.setFont(fonthead);
		L.setString("L");
		L.setCharacterSize(50);
		//L.setStyle(sf::Text::Style::Bold);
		L.setOrigin(-X_Offset_For_Alphabets + 11 * x, -Y_Offset_For_Alphabets);
		M.setFont(fonthead);
		M.setString("M");
		M.setCharacterSize(50);
		//M.setStyle(sf::Text::Style::Bold);
		M.setOrigin(-X_Offset_For_Alphabets + 12 * x, -Y_Offset_For_Alphabets);
		N.setFont(fonthead);
		N.setString("N");
		N.setCharacterSize(50);
		//N.setStyle(sf::Text::Style::Bold);
		N.setOrigin(-X_Offset_For_Alphabets + 13 * x, -Y_Offset_For_Alphabets);
		O.setFont(fonthead);
		O.setString("O");
		O.setCharacterSize(50);
		//O.setStyle(sf::Text::Style::Bold);
		O.setOrigin(-X_Offset_For_Alphabets + 14 * x, -Y_Offset_For_Alphabets);
		P.setFont(fonthead);
		P.setString("P");
		P.setCharacterSize(50);
		P.setOrigin(-X_Offset_For_Alphabets + 15 * x, -Y_Offset_For_Alphabets);
		//P.setStyle(sf::Text::Style::Bold);
		Q.setFont(fonthead);
		Q.setString("Q");
		Q.setCharacterSize(50);
		//Q.setStyle(sf::Text::Style::Bold);
		Q.setOrigin(-X_Offset_For_Alphabets + 16 * x, -Y_Offset_For_Alphabets);
		R.setFont(fonthead);
		R.setString("R");
		R.setCharacterSize(50);
		//R.setStyle(sf::Text::Style::Bold);
		R.setOrigin(-X_Offset_For_Alphabets + 17 * x, -Y_Offset_For_Alphabets);
		S.setFont(fonthead);
		S.setString("S");
		S.setCharacterSize(50);
		//S.setStyle(sf::Text::Style::Bold);
		S.setOrigin(-X_Offset_For_Alphabets + 18 * x, -Y_Offset_For_Alphabets);
		T.setFont(fonthead);
		T.setString("T");
		T.setCharacterSize(50);
		//T.setStyle(sf::Text::Style::Bold);
		T.setOrigin(-X_Offset_For_Alphabets + 19 * x, -Y_Offset_For_Alphabets);
		U.setFont(fonthead);
		U.setString("U");
		U.setCharacterSize(50);
		//U.setStyle(sf::Text::Style::Bold);
		U.setOrigin(-X_Offset_For_Alphabets + 20 * x, -Y_Offset_For_Alphabets);
		V.setFont(fonthead);
		V.setString("V");
		V.setCharacterSize(50);
		//V.setStyle(sf::Text::Style::Bold);
		V.setOrigin(-X_Offset_For_Alphabets + 21 * x, -Y_Offset_For_Alphabets);
		W.setFont(fonthead);
		W.setString("W");
		W.setCharacterSize(50);
		//W.setStyle(sf::Text::Style::Bold);
		W.setOrigin(-X_Offset_For_Alphabets + 22 * x, -Y_Offset_For_Alphabets);
		X.setFont(fonthead);
		X.setString("X");
		X.setCharacterSize(50);
		//X.setStyle(sf::Text::Style::Bold);
		X.setOrigin(-X_Offset_For_Alphabets + 23 * x, -Y_Offset_For_Alphabets);
		Y.setFont(fonthead);
		Y.setString("Y");
		Y.setCharacterSize(50);
		//Y.setStyle(sf::Text::Style::Bold);
		Y.setOrigin(-X_Offset_For_Alphabets + 24 * x, -Y_Offset_For_Alphabets);
		Z.setFont(fonthead);
		Z.setString("Z");
		Z.setCharacterSize(50);
		//Z.setStyle(sf::Text::Style::Bold);
		Z.setOrigin(-X_Offset_For_Alphabets + 25 * x, -Y_Offset_For_Alphabets);
		Present_Word.setFont(fonthead);
		Present_Word.setString(Cur_Word);
		Present_Word.setCharacterSize(50);
		Present_Word.setFillColor(color);
		Present_Word.setStyle(sf::Text::Style::Bold);
		Present_Word.setOrigin(-740, -940);
		//Change the Starting points for Quotes as they are long
		if (topic == "Quotes")
		{
			Present_Word.setOrigin(-340, -940);
		}
	}

	//Function to randomly take a number and then look for the word in the file that many times.
	string randomiser()
	{
		int a;
		string str;
		ifstream fin;
		string filename_Text = "Text File Sources/";
		filename_Text += topic + ".txt";
		fin.open(filename_Text);
		srand((unsigned)(time(0)));
		a = (rand() % 20) + 1;
		for (int i = 0; i < a; i++)
		{
			fin >> str;
		}
		fin.close();
		int len = str.length();
		//since the ' >> ' operator cant take words after space and a return key, there is a hyphen for each space in the word or Quote
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '-') //converts hypen back to space
			{
				str[i] = ' ';
			}
		}
		Answer = str;
		return str;
	}

	//Function to check the user's inputted letter to check whether it matches the word in any place.
	//word is the Original Word without the underscores.
	//Cur_Word in the original Word with the Underscores
	//Userinp is any haracter entered by the user.
	int Check_User_inp(string Word, string &Cur_Word, int &life, char user_inp) //if the user does not enter anything it is set to '#' by default
	{
		bool correct = 0;
		int len = Word.length();
		for (int i = 0; i < len; i++)
		{
			if (Word[i] == user_inp) //if the userinp is a letter in the word,
			{
				Cur_Word[i] = Word[i]; //assign it to that position in the cur_word.
				correct = 1;
			}
		}
		if (correct == 0 && user_inp != '#') //if (user_inp == '#') then the user has'nt actually entered anything.
		{
			life--;
			val = 1; //life has reduced so a clip has to be played which means val is set to 0.
		}
		if (Cur_Word == Word) //if everyting matches
		{
			return 1;
		}
		else
			return 0;
	}
	//Function to make a string with underscores from the original word.
	//here word is the original word from the randomiser and Cur_Word is the word to be underscored.
	void Assign_Word(string &Cur_Word, string Word)
	{
		Cur_Word = Word;
		int len = Word.length();
		for (int i = 0; i < len; i++) //assign every char into underscore
		{
			Cur_Word[i] = '_';
		}
		for (int i = 0; i < len; i++) //assign all the spaces back to spaces
		{
			if (Word[i] == ' ')
			{
				Cur_Word[i] = ' ';
			}
		}
	}
	int Main()
	{
		a = 1;
		b = 1;
		c = 1;
		d = 1;
		e = 1;
		f = 1;
		g = 1;
		h = 1;
		i = 1;
		j = 1;
		k = 1;
		l = 1;
		n = 1;
		m = 1;
		o = 1;
		p = 1;
		q = 1;
		r = 1;
		s = 1;
		t = 1;
		u = 1;
		v = 1;
		w = 1;
		xx = 1;
		y = 1;
		z = 1;
		//Assign life to different themes.
		if (theme == "Marvel")
		{
			life = 8;
		}
		else if (theme == "John Wick")
		{
			life = 3;
		}
		else if (theme == "Classic")
		{
			life = 6;
		}
		else if (theme == "Harry Potter")
		{
			life = 7;
		}
		else if (theme == "People")
		{
			life = 10;
		}
		res = 0;
		val = 1;
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		string Word, Cur_Word, User_Word = "";
		Word = randomiser();
		int Time_Passed_Int;
		clock.restart();
		bool Time_Bool = 1;
		Assign_Word(Cur_Word, Word);
		char User_inp = '#'; //default
		SetAttributes();
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "HANG MAN", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			Time_Passed_S = clock.getElapsedTime();
			if (Time_Bool == 1) //timebool is zero if time is not less than 0
				Time_Passed_Int = 62 - Time_Passed_S.asSeconds();
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			//Check the user input only if the player has'nt won or he has'nt lost
			//if the player wins the life becomes 100. if he loses it becomes 0.
			if (life != 100 && life != 0)
				res = Check_User_inp(Word, Cur_Word, life, User_inp);

			//if the userinput is 1 then the user wins and timebool is 1 means the time is above 0
			if (res == 1 && Time_Bool == 1)
			{
				life = 100;
				Player_Info_Obj.points += Time_Passed_Int; //add up the points
				Time_Bool = 0;							   //stop counting the time
				val = 1;								   //set val to 1 and show hte winning clip
			}

			//if the player has'nt won and he has'nt los,t, oinly then recieve his input.
			if (life != 100 && life != 0)
				User_inp = KeyPressChecker();

			//if the user lost or won his input becomes the default.
			if (life == 100 || life == 0)
				User_inp = '#';

			//if the time runs out and is less than 0, then the player loses
			if (Time_Passed_Int == 0 && Time_Bool == 1)
			{
				life = 0;								   //player loses
				Player_Info_Obj.points += Time_Passed_Int; ////add the points
				val = 1;								   //play the losing clip
				Time_Bool = 0;							   //stop counting
			}

			//only set teh text and refresh it if the player hasnt lost
			if (life != 0)
			{
				SetText(Cur_Word, Time_Passed_Int);
			}
			if (theme == "Classic")
			{
				switch (life)
				{
				case 0:
					Show_Image_Theme_2_Pic_6();
					break;
				case 1:
					Show_Image_Theme_2_Pic_5();
					break;
				case 2:
					Show_Image_Theme_2_Pic_4();
					break;
				case 3:
					Show_Image_Theme_2_Pic_3();
					break;
				case 4:
					Show_Image_Theme_2_Pic_2();
					break;
				case 5:
					Show_Image_Theme_2_Pic_1();
					break;
				case 6:
					Show_Image_Theme_2_Pic_Null();
					break;
				case 100:
					Show_Image_Theme_2_Pic_Win();
					break;
				}
				//if life becomes 0 and value of val is the number of frames in the losing clip of the theme, only then execute lost commands.
				if (life == 0 && val == 500)
				{
					cout << "you lose";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main(); //show the dialog box that the player lost.
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
				//if life becomes 0 and value of val is the number of frames in the losing clip of the theme, only then execute lost commands.
				if (life == 100 && val == 500)
				{
					cout << "you win";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
			}
			else if (theme == "Marvel")
			{
				switch (life)
				{
				case 0:
					Play_Video_Theme_4_Scene_8();
					break;
				case 1:
					Play_Video_Theme_4_Scene_7();
					break;
				case 2:
					Play_Video_Theme_4_Scene_6();
					break;
				case 3:
					Play_Video_Theme_4_Scene_5();
					break;
				case 4:
					Play_Video_Theme_4_Scene_4();
					break;
				case 5:
					Play_Video_Theme_4_Scene_3();
					break;
				case 6:
					Play_Video_Theme_4_Scene_2();
					break;
				case 7:
					Play_Video_Theme_4_Scene_1();
					break;
				case 8:
					Show_Image_Theme_4_Pic_Null();
					break;
				case 100:
					Play_Video_Theme_4_Scene_Win();
					break;
				}
				if (life == 0 && val == 500)
				{
					cout << "you lose";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
				if (life == 100 && val == 500)
				{
					cout << "you win";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
			}
			else if (theme == "Harry Potter")
			{
				switch (life)
				{
				case 0:
					Play_Video_Theme_3_Scene_7();
					break;
				case 1:
					Play_Video_Theme_3_Scene_6();
					break;
				case 2:
					Play_Video_Theme_3_Scene_5();
					break;
				case 3:
					Play_Video_Theme_3_Scene_4();
					break;
				case 4:
					Play_Video_Theme_3_Scene_3();
					break;
				case 5:
					Play_Video_Theme_3_Scene_2();
					break;
				case 6:
					Play_Video_Theme_3_Scene_1();
					break;
				case 7:
					Show_Image_Theme_3_Pic_Null();
					break;
				case 100:
					Play_Video_Theme_3_Scene_Win();
					break;
				}
				if (life == 0 && val == 500)
				{
					cout << "you lose";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
				if (life == 100 && val == 500)
				{
					cout << "you win";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
			}
			else if (theme == "John Wick")
			{
				switch (life)
				{
				case 0:
					Play_Video_Theme_1_Scene_3();
					break;
				case 1:
					Play_Video_Theme_1_Scene_2();
					break;
				case 2:
					Play_Video_Theme_1_Scene_1();
					break;
				case 3:
					Play_Video_Theme_1_Scene_Null();
					break;
				case 100:
					Play_Video_Theme_1_Scene_Win();
					break;
				}
				if (life == 0 && val == 500)
				{
					cout << "you lose";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
				if (life == 100 && val == 500)
				{
					cout << "you win";
					Delay(2000);
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
			}
			else if (theme == "People")
			{
				Show_People_Pic(Word);
				if (life == 0)
				{
					cout << "you lose";
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
				if (life == 100)
				{
					cout << "you win";
					Dialog_Res = Play_Over_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2; //back to menu
					}
					else if (Dialog_Res == 1)
					{
						window.close();
						return 1; //1 means play again
					}
				}
			}
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(Present_Word);
			window.draw(A);
			window.draw(B);
			window.draw(C);
			window.draw(D);
			window.draw(E);
			window.draw(F);
			window.draw(G);
			window.draw(H);
			window.draw(I);
			window.draw(J);
			window.draw(K);
			window.draw(L);
			window.draw(M);
			window.draw(N);
			window.draw(O);
			window.draw(P);
			window.draw(Q);
			window.draw(R);
			window.draw(S);
			window.draw(T);
			window.draw(U);
			window.draw(V);
			window.draw(W);
			window.draw(X);
			window.draw(Y);
			window.draw(Z);
			window.draw(Life_Text);
			window.draw(Life_Text_Val);
			window.draw(Game_Name);
			if (theme != "People")
				window.draw(Video_Image);
			else
				window.draw(People_Image);
			window.draw(Mini_Border);
			window.draw(Time_Passed);
			window.draw(Time_Val);
			window.display();
		}
	}
} Play_Obj;

//Class for selecting the topic for the words in the game.
class Sub_Types : public General
{
public:
	sf::Text Fruits_Text, Colors_Text, Countries_Text, Quotes_Text, Marvel_Text, People_Text, Sel_Topic, Back_To_Menu;
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/background3.png");
		Border_Texture.loadFromFile("Resources/Borders/Border3.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
		//font.loadFromFile("Resources/Fonts/amarurgt.ttf");
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			topic = "Quotes";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			topic = "Fruits";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			topic = "Colors";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			topic = "Countries";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			topic = "People";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			topic = "Marvel";
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			return 2;
		}
		else
			return 0;
	}
	void SetText()
	{
		int Font_Size = 100, FontHead_Size = 80;
		Game_Name.setFont(font);
		Game_Name.setString("HANG MAN");
		Game_Name.setCharacterSize(Font_Size);
		Game_Name.setFillColor(sf::Color::Blue);
		Game_Name.setStyle(sf::Text::Style::Bold);
		Game_Name.setStyle(sf::Text::Style::Underlined);
		Game_Name.setOrigin(-650, -20);
		Back_To_Menu.setFont(fonthead);
		Back_To_Menu.setString("BACK TO MENU (B)");
		Back_To_Menu.setCharacterSize(30);
		Back_To_Menu.setFillColor(sf::Color::Black);
		Back_To_Menu.setStyle(sf::Text::Style::Bold);
		Back_To_Menu.setOrigin(-1400, -950);
		Sel_Topic.setFont(fonthead);
		Sel_Topic.setString("SELECT THE TOPIC");
		Sel_Topic.setCharacterSize(FontHead_Size);
		Sel_Topic.setFillColor(sf::Color::Red);
		Sel_Topic.setStyle(sf::Text::Style::Bold);
		Sel_Topic.setStyle(sf::Text::Style::Underlined);
		Sel_Topic.setOrigin(-500, -150);
		Quotes_Text.setFont(fonthead);
		Quotes_Text.setString("QUOTES (Q)");
		Quotes_Text.setCharacterSize(FontHead_Size);
		Quotes_Text.setFillColor(sf::Color::Black);
		Quotes_Text.setStyle(sf::Text::Style::Bold);
		Quotes_Text.setOrigin(-250, -300);
		Fruits_Text.setFont(fonthead);
		Fruits_Text.setString("FRUITS AND VEGETABLES (F)");
		Fruits_Text.setCharacterSize(FontHead_Size);
		Fruits_Text.setFillColor(sf::Color::Black);
		Fruits_Text.setStyle(sf::Text::Style::Bold);
		Fruits_Text.setOrigin(-250, -400);
		Colors_Text.setFont(fonthead);
		Colors_Text.setString("COLORS (C)");
		Colors_Text.setCharacterSize(FontHead_Size);
		Colors_Text.setFillColor(sf::Color::Black);
		Colors_Text.setStyle(sf::Text::Style::Bold);
		Colors_Text.setOrigin(-250, -500);
		Countries_Text.setFont(fonthead);
		Countries_Text.setString("COUNTRIES (N)");
		Countries_Text.setCharacterSize(FontHead_Size);
		Countries_Text.setFillColor(sf::Color::Black);
		Countries_Text.setStyle(sf::Text::Style::Bold);
		Countries_Text.setOrigin(-250, -600);
		People_Text.setFont(fonthead);
		People_Text.setString("CELEBRITIES (P)");
		People_Text.setCharacterSize(FontHead_Size);
		People_Text.setFillColor(sf::Color::Black);
		People_Text.setStyle(sf::Text::Style::Bold);
		People_Text.setOrigin(-250, -700);
		Marvel_Text.setFont(fonthead);
		Marvel_Text.setString("MARVEL (M)");
		Marvel_Text.setCharacterSize(FontHead_Size);
		Marvel_Text.setFillColor(sf::Color::Black);
		Marvel_Text.setStyle(sf::Text::Style::Bold);
		Marvel_Text.setOrigin(-250, -800);
	}
	int Main()
	{
		int Return_Val;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "SNAKE XENZIA", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			SetAttributes();
			SetText();
			Return_Val = KeyPressChecker();
			if (Return_Val != 0)
			{
				window.close();
				return Return_Val;
			}
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(Game_Name);
			window.draw(Quotes_Text);
			window.draw(Countries_Text);
			window.draw(Marvel_Text);
			window.draw(Sel_Topic);
			window.draw(People_Text);
			window.draw(Fruits_Text);
			window.draw(Colors_Text);
			window.draw(Back_To_Menu);
			window.display();
		}
	}
} Sub_Type_Obj;

//Class for the Min Menu and Selecting all the other screen and sections.
class Menu : public General
{
public:
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/img.png");
		Back_Image.setTexture(Background_Texture);
		fonthead.loadFromFile("Resources/Fonts/CloisterBlack.ttf");
		font.loadFromFile("Resources/Fonts/Roboto-thin.ttf");
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			return 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			return 4;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			return 5;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			return 6;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			return 7;
		}
		else
			return 0;
	}
	int Main()
	{
		int Return_Val;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "SNAKE XENZIA", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			SetAttributes();
			Return_Val = KeyPressChecker();
			if (Return_Val != 0)
			{
				return Return_Val;
			}
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Game_Name);
			window.draw(Play_Game);
			window.draw(Store);
			window.draw(Records);
			window.draw(How_To);
			window.draw(About);
			window.draw(Quit);
			window.display();
		}
	}
} Menu_Obj;

//Class for displaying the Help and Credits Page.
class Help_and_About : public General
{
public:
	sf::Text Back_To_Menu;
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/Help_and_About.jpg");
		Back_Image.setTexture(Background_Texture);
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
	}
	int Key_Press_Ckecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			return 2;
		}
		else
			return 0;
	}
	void Set_Text()
	{
		Back_To_Menu.setFont(fonthead);
		Back_To_Menu.setString("BACK TO MENU (B)");
		Back_To_Menu.setCharacterSize(30);
		Back_To_Menu.setFillColor(sf::Color::Black);
		Back_To_Menu.setStyle(sf::Text::Style::Bold);
		Back_To_Menu.setOrigin(-1400, -950);
	}
	//text for help and about;
	/*
	how to play HangMan // heading
	HnagMan is a classic game that we have been playing since centuries. it is a word Guessing Game that requires the basic knowledge of
	words of the specified genre. This version of the game consists of several subtopics like movies, celebreties, colors, countries etc
	Play Classic
	upon selecting play classic, you will be presented with a hang mam and the alphabets just above the word that you are required to guess
	to guess a letter, press that letter on the keyboard and it will turn red signifying that it has been used up and all the occurances of
	the letter will be displayed on the screen filling up the word in the right places allowing you to press another letter in order to
	complete the word.
	you will be given a time limit and how fast you guess the word will determine your points.
	you will have 1 hints that you can use to help you guess the word which will reduce you points
	you have a limited amount of lives(5).every time you misguess a letter, a body part of the hangman appears on the screes
	and hence you goal is to correctly guess the word before the body of the hangman appears on the screen.

	Play Theme
	Upon selecting your theme in the store, the option of that skin will be available in the settings.
	the ruled of this mode of the game will be alike the classin mode, with the only exception that upon every misguess of a letter,
	you will be shown a scene of the genre( or movie or theme or villain ) that you have purchased from the store.
	you objective is therefore to prevent a negative ending to the theme( depending on the respective ciscumstances ).


	About
	Programmed by : Krishnaraj PT
	Class 12 A

	As a part of the CBSE Project to be submitted to Mini Mam.
	Programming language : C++

	Sincere thanks to :
	Parents and Teachers,
	Master Joshua Nishant, For helping with the creative aspects of the Game
	Stack OverFlow.com
	Google
	LearnC++.com
	Notepad++
	Paint.net Picsart

	*/
	int Main()
	{
		int Return_Val;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "HANG MAN", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			Return_Val = Key_Press_Ckecker();
			if (Return_Val != 0)
				return Return_Val;
			Set_Text();
			SetAttributes();
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Back_To_Menu);
			window.draw(Quit);
			window.display();
		}
	}

} Help_About_Obj;

//Class for the Store tp buy the differnt themes.
class Store : public General
{
public:
	sf::Text ch1, ch2, ch3, ch4, ch5, ch6, Back_To_Menu, Total_Coins;
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/background3.png");
		Border_Texture.loadFromFile("Resources/Borders/Border3.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
		//font.loadFromFile("Resources/Fonts/amarurgt.ttf");
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			return 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			return 4;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			return 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			return 1;
		}
		else
			return -1;
	}
	void SetText()
	{
		string scorestr;
		const char *score;
		scorestr = "THE TOTAL SCORE IS " + to_string(Player_Info_Obj.points);
		score = scorestr.c_str();
		int Font_Size = 100, FontHead_Size = 80;
		Game_Name.setFont(font);
		Game_Name.setString("HANG MAN");
		Game_Name.setCharacterSize(Font_Size);
		Game_Name.setFillColor(sf::Color::Blue);
		Game_Name.setStyle(sf::Text::Style::Bold);
		Game_Name.setStyle(sf::Text::Style::Underlined);
		Game_Name.setOrigin(-650, -20);
		Back_To_Menu.setFont(fonthead);
		Back_To_Menu.setString("BACK TO MENU (B)");
		Back_To_Menu.setCharacterSize(30);
		Back_To_Menu.setFillColor(sf::Color::Black);
		Back_To_Menu.setStyle(sf::Text::Style::Bold);
		Back_To_Menu.setOrigin(-1400, -950);
		Total_Coins.setFont(fonthead);
		Total_Coins.setString(score);
		Total_Coins.setCharacterSize(30);
		Total_Coins.setFillColor(sf::Color::Black);
		Total_Coins.setStyle(sf::Text::Style::Bold);
		Total_Coins.setOrigin(-1400, -150);
		ch1.setFont(fonthead);
		ch1.setString("STORE");
		ch1.setCharacterSize(FontHead_Size);
		ch1.setFillColor(sf::Color::Red);
		ch1.setStyle(sf::Text::Style::Bold);
		ch1.setStyle(sf::Text::Style::Underlined);
		ch1.setOrigin(-500, -150);
		ch2.setFont(fonthead);
		ch2.setString("MARVEL (M) - 600");
		ch2.setCharacterSize(FontHead_Size);
		ch2.setFillColor(sf::Color::Black);
		ch2.setStyle(sf::Text::Style::Bold);
		ch2.setOrigin(-250, -300);
		ch3.setFont(fonthead);
		ch3.setString("HARRY POTTER (H) - 400");
		ch3.setCharacterSize(FontHead_Size);
		ch3.setFillColor(sf::Color::Black);
		ch3.setStyle(sf::Text::Style::Bold);
		ch3.setOrigin(-250, -400);
		ch4.setFont(fonthead);
		ch4.setString("CLASSIC (C) - 200");
		ch4.setCharacterSize(FontHead_Size);
		ch4.setFillColor(sf::Color::Black);
		ch4.setStyle(sf::Text::Style::Bold);
		ch4.setOrigin(-250, -500);
		ch5.setFont(fonthead);
		ch5.setString("JOHN WICK (J) - 200");
		ch5.setCharacterSize(FontHead_Size);
		ch5.setFillColor(sf::Color::Black);
		ch5.setStyle(sf::Text::Style::Bold);
		ch5.setOrigin(-250, -600);
	}
	int Main()
	{
		int Return_Val, Dialog_Res;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "HANG MAN", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			SetAttributes();
			SetText();
			Return_Val = KeyPressChecker();
			switch (Return_Val)
			{
			case 1:
				if (Player_Info_Obj.points >= 200) //check if the guy has bucks
				{
					Player_Info_Obj.Themes[1] = 1; //giv him the thing
					Player_Info_Obj.points -= 200; //take his bucks
					Dialog_Res = Store_Buy_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Store_Cantbuy_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				break;
			case 2:
				if (Player_Info_Obj.points >= 400)
				{
					Player_Info_Obj.Themes[2] = 1;
					Player_Info_Obj.points -= 400;
					Dialog_Res = Store_Buy_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Store_Cantbuy_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				break;
			case 3:
				if (Player_Info_Obj.points >= 600)
				{
					Player_Info_Obj.Themes[3] = 1;
					Player_Info_Obj.points -= 600;
					Dialog_Res = Store_Buy_Disp.Main();
					if (Dialog_Res == 2)
					{
						Delay(2000);
						return 2;
					}
				}
				else
				{
					Dialog_Res = Store_Cantbuy_Disp.Main();
					if (Dialog_Res == 2)
					{
						Delay(2000);
						return 2;
					}
				}
				break;
			case 4:
				if (Player_Info_Obj.points >= 200)
				{
					Player_Info_Obj.Themes[4] = 1;
					Player_Info_Obj.points -= 200;
					Dialog_Res = Store_Buy_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Store_Cantbuy_Disp.Main();
					if (Dialog_Res == 2)
					{
						Delay(2000);
						return 2;
					}
				}
				break;
			case 0:
				window.close();
				return 2;
			}
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(Game_Name);
			window.draw(Total_Coins);
			window.draw(ch1);
			window.draw(ch2);
			window.draw(ch3);
			window.draw(ch4);
			window.draw(ch5);
			window.draw(ch6);
			window.draw(Back_To_Menu);
			window.display();
		}
	}
} Store_Obj;

//Class for the different changing the themes of the game.
class Settings : public General
{
public:
	sf::Text ch1, ch2, ch3, ch4, ch5, ch6, Back_To_Menu, Total_Coins;
	void SetAttributes()
	{
		Background_Texture.loadFromFile("Resources/Backgrounds/background3.png");
		Border_Texture.loadFromFile("Resources/Borders/Border3.png");
		Back_Image.setTexture(Background_Texture);
		Border.setTexture(Border_Texture);
		fonthead.loadFromFile("Resources/Fonts/DeliusUnicase.ttf");
		font.loadFromFile("Resources/Fonts/Merienda-Regular.ttf");
		//font.loadFromFile("Resources/Fonts/amarurgt.ttf");
	}
	int KeyPressChecker()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			return 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
		{
			return 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
		{
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			return 5;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		{
			return 4;
		}
		else
			return -1;
	}
	void SetText()
	{
		int Font_Size = 100, FontHead_Size = 80;
		Game_Name.setFont(font);
		Game_Name.setString("HANG MAN");
		Game_Name.setCharacterSize(Font_Size);
		Game_Name.setFillColor(sf::Color::Blue);
		Game_Name.setStyle(sf::Text::Style::Bold);
		Game_Name.setStyle(sf::Text::Style::Underlined);
		Game_Name.setOrigin(-650, -20);
		Back_To_Menu.setFont(fonthead);
		Back_To_Menu.setString("BACK TO MENU (B)");
		Back_To_Menu.setCharacterSize(30);
		Back_To_Menu.setFillColor(sf::Color::Black);
		Back_To_Menu.setStyle(sf::Text::Style::Bold);
		Back_To_Menu.setOrigin(-1400, -950);
		ch1.setFont(fonthead);
		ch1.setString("SETTINGS");
		ch1.setCharacterSize(FontHead_Size);
		ch1.setFillColor(sf::Color::Red);
		ch1.setStyle(sf::Text::Style::Bold);
		ch1.setStyle(sf::Text::Style::Underlined);
		ch1.setOrigin(-500, -150);
		ch2.setFont(fonthead);
		ch2.setString("MARVEL (M)");
		ch2.setCharacterSize(FontHead_Size);
		ch2.setFillColor(sf::Color::Black);
		ch2.setStyle(sf::Text::Style::Bold);
		ch2.setOrigin(-250, -300);
		ch3.setFont(fonthead);
		ch3.setString("HARRY POTTER (H)");
		ch3.setCharacterSize(FontHead_Size);
		ch3.setFillColor(sf::Color::Black);
		ch3.setStyle(sf::Text::Style::Bold);
		ch3.setOrigin(-250, -400);
		ch4.setFont(fonthead);
		ch4.setString("JOHN WICK (J)");
		ch4.setCharacterSize(FontHead_Size);
		ch4.setFillColor(sf::Color::Black);
		ch4.setStyle(sf::Text::Style::Bold);
		ch4.setOrigin(-250, -500);
		ch5.setFont(fonthead);
		ch5.setString("CLASSIC (C)");
		ch5.setCharacterSize(FontHead_Size);
		ch5.setFillColor(sf::Color::Black);
		ch5.setStyle(sf::Text::Style::Bold);
		ch5.setOrigin(-250, -600);
		ch6.setFont(fonthead);
		ch6.setString("CELEBRITIES (P)");
		ch6.setCharacterSize(FontHead_Size);
		ch6.setFillColor(sf::Color::Black);
		ch6.setStyle(sf::Text::Style::Bold);
		ch6.setOrigin(-250, -700);
	}
	int Main()
	{
		int Return_Val, Dialog_Res, Return_Val_Frm_Func = 0;
		sf::RenderWindow window(sf::VideoMode(1920, 1080), "HANG MAN", sf::Style::Close | sf::Style::Resize);
		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			SetAttributes();
			SetText();
			Return_Val = KeyPressChecker();
			switch (Return_Val)
			{
			case 1:

				if (Player_Info_Obj.Themes[1] == 1) //chech if the theme is bought
				{
					theme = "Classic"; //set the theme
					life = 6;
					Dialog_Res = Settings_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Settings_Disp_Cant.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				break;
			case 2:

				if (Player_Info_Obj.Themes[2] == 1)
				{
					theme = "Harry Potter";
					life = 7;
					Dialog_Res = Settings_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Settings_Disp_Cant.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				break;
			case 3:
				if (Player_Info_Obj.Themes[3] == 1)
				{
					theme = "Marvel";
					life = 8;
					Dialog_Res = Settings_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Settings_Disp_Cant.Main();
					if (Dialog_Res == 2)
					{

						return 2;
					}
				}
				break;
			case 5:
				if (Player_Info_Obj.Themes[4] == 1)
				{
					theme = "John Wick";
					life = 8;
					Dialog_Res = Settings_Disp.Main();
					if (Dialog_Res == 2)
					{
						return 2;
					}
				}
				else
				{
					Dialog_Res = Settings_Disp_Cant.Main();
					if (Dialog_Res == 2)
					{

						return 2;
					}
				}
				break;
			case 0:
				theme = "People";
				life = 10;
				Dialog_Res = Settings_Disp.Main();
				if (Dialog_Res == 2)
				{
					return 2;
				}
				break;
			case 4:
				return 2;
			}
			window.clear(sf::Color::White);
			window.draw(Back_Image);
			window.draw(Border);
			window.draw(Game_Name);
			;
			window.draw(ch1);
			window.draw(ch2);
			window.draw(ch3);
			window.draw(ch4);
			window.draw(ch5);
			window.draw(Back_To_Menu);
			window.display();
		}
	}
} Settings_Obj;

int main()
{
	int Quit = 0;
	int a, b, c, d, e, f, g, h, Skip_Menu = 0;

	//Run the main function for getting the name of the player
	//a is th evalue of the check function and whether hte function reuturned true or false determines whether to write or to update.
	a = Player_Obj.Main();
	//if a is 0 then the player is new and we need to write the record of the player in the file.
	if (a == 0)
	{
		Player_Info_Obj.Player_Name = Player_Obj.Cur_Player_Name; //Updtate function works by using the Playe_Info_Obj
		Player_Obj.update();
	}
	else
	{
		Player_Info_Obj = Cur_Player_Info_Obj;
	}
	while (Quit == 0)
	{
		if (theme == "People")
		{
			topic = "People";
		}
		if (Skip_Menu == 0)
		{
			b = Menu_Obj.Main();
		}
		// b is the section of the menu that the player wants to go to.
		switch (b)
		{
		case 1:					 //PLAY GAME
			c = Play_Obj.Main(); //returns 1 for back to menu else returns 0.
			if (c == 1)
				Skip_Menu = 1;
			else
				Skip_Menu = 0;
			continue; //we do not use break because break goes to the next statement after the while loop but we want o rerun the while loop.
		case 2:		  //STORE
			Store_Obj.Main();
			continue;
		case 4:
			Help_About_Obj.Main();
			continue;
		case 5:
			Settings_Obj.Main();
			continue;
		case 6:
			Player_Info_Obj.Player_Name = Player_Obj.Cur_Player_Name;
			Player_Obj.update(); //update whatever we did to the object and then quit is 1 to end the loop.
			Quit = 1;
			continue;
		case 7:
			Sub_Type_Obj.Main();
			continue;
		}
	}
	system("cls");
	cout << "Thanks for Playing HangMan";
	General_Obj.Delay(100000000);
	return 0;
}
//
//int main()
//{
//	cout<<Play_Over_Disp.Main();
//	return 0;
//}