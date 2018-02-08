#include <iostream>
#include <string>

#define SHORT_BEEP '.'
#define LONG_BEEP '-'

using namespace std;

/* CLASS: Message
 * DESCRIPTION: Base class, stores message and functions.
*/
class Message {
	private:

	public:
		// Variables
		string raw;		// Hold the message, inputted by the user

		// Constructors
		Message();
		Message( string rawInput ) { raw = rawInput; }

		// Deconstructors
		~Message();

		// Methods
		void print() { cout << "\nMESSAGE: " << raw << endl; }
}; // END CLASS Message

/* CLASS: Message
 * METHOD: Constructor
 * DESCRIPTION: Default (empty) Constructor. Prompts and gets raw message from user.
*/
Message::Message() {
	cout << "MESSAGE: ";
	getline( cin, raw );
	raw.push_back( '\0' );
} // END CONSTRUCTOR Message( void )

/* CLASS: Message
 * METHOD: Deconstructor
 * DESCRIPTION:  Deconstructor - ran when an object is destroyed
*/
Message::~Message() {
	// TEST: Prints when a message object is destroyed
	// cout << "Object Destroyed" << endl;
} // END DECONSTRUCTOR ~Message

/* CLASS: MorseCodeMessage
 * PARENT: Message
 * DESCRIPTION: Derived class of message. Translates and prints message in morse code.
*/
class MorseCodeMessage : public Message {
	private:

	public:
		// Class Variables
		string morseCode;

		// Constructor
		MorseCodeMessage();

		// Destructor
		~MorseCodeMessage();

		// Methods
		void translate();
		void print();
};

/* CLASS: MorseCodeMessage
 * PARENT: Message
 * 
 */
MorseCodeMessage::MorseCodeMessage() {
	// TEST: Signals if MorseCodeMessage object is constructed.
	// cout << "MorseCodeMessage Object Created" << endl;

	this->translate();
} // END CONSTRUCTOR MorseCodeMessage

/* CLASS: MorseCodeMessage
 * PARENT: Message
 * METHOD: ~MorseCodeMethod
 * DESCRIPTION: Destructor
 */
MorseCodeMessage::~MorseCodeMessage() {
	// TEST: Signals if MorseCodeMessage object is destroyed.
	// cout << "MorseCodeMessage Object Destroyed" << endl;
} // END DECONSTRUCTOR ~MorseCodeMessage

/* CLASS: MorseCode Message
 * PARENT: Message
 * METHOD: translate
 * DESCRIPTION: Translates <raw> string from <Message> class, which holds the
 * 				originally inputted message from the user; and translates it
 *				into morse code, putting the final translation into string
 *				<morseCode>.
 */
void MorseCodeMessage::translate() {
 	// TEST: Sees if method is called
 	// cout << "\nTranslate Method Called" << endl;

 	// TEST: Test message inputted into <morseCode>
 	// morseCode = "test ---.-.-. morse code .-.-.---";

 	int i = 0;	// Counter

 	// Iterates through every character in the string <raw> until null character is reached
 	while( raw[i] != '\0' ) {
 		// Translates each character in string <raw> and appends the translation into <morseCode>
 		switch( toupper( raw[i] ) ) {
 			case 'A':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'B':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'C':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'D':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'E':
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'F':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'G':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'H':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'I':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'J':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'K':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'L':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'M':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'N':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'O':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
				break;
			case 'P':
				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'Q':
 				morseCode.push_back( LONG_BEEP );
				morseCode.push_back( LONG_BEEP );
				morseCode.push_back( SHORT_BEEP );
				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'R':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'S':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case 'T':
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'U':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'V':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'W':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'X':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'Y':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case 'Z':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case '0':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case '1':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case '2':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case '3':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case '4':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				break;
 			case '5':
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case '6':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case '7':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case '8':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case '9':
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( LONG_BEEP );
 				morseCode.push_back( SHORT_BEEP );
 				break;
 			case ' ':
 				morseCode.append( "   " );
 				break;	
 			default:
 				morseCode.push_back( 'x' );
 				break;
 		} // END switch : Translates each character in <raw> into morse code 
 		morseCode.push_back( ' ' );
 		i++;
 	} // END for : Iterates through each character in <raw> 
} // END METHOD translate

/* CLASS: MorseCodeMessage
 * PARENT: Message
 * METHOD: print
 * DESCRIPTION: Prints the message converted into morse code, and the original
 *				message from base class <Message>
 */
void MorseCodeMessage::print() {
	cout << "\nRaw Message:\t" << raw << endl;
	cout << "Morse Message:\t" << morseCode << endl;
} // END METHOD print

/* CLASS: MessageStack
 * DESCRIPTION: Stores an array of <Message> objects
 */
class MessageStack {
	// Structure: Used to organize and construct the nodes which will be
	// 			  used in the composition of the linked list.
	struct Node
	{
		Message *nodeData;
		Node *nextNode;
	}*head; // END STRUCT Node

	public:
		// Constructor
		MessageStack();

		// Destructor
		~MessageStack();

		// Methods
		void push( Message *obj );
		Message *pop();
		void printStack();
}; // END CLASS DECLARATION MesssageStack

/* CLASS: MessageStack
 * METHOD: MessageStack
 * DESCRIPTION: Default constructor
 */
MessageStack::MessageStack() {
	// TEST: Signal if MessageStack object is constructed
	// cout << "\nMessageStack object created" << endl;

	head = NULL;
} // END METHOD MessageStack

/* CLASS: MessageStack
 * METHOD: ~MessageStack
 * DESCRIPTION: Destructor
 */
MessageStack::~MessageStack() {
	// TEST: Signal if MessageStack object is destroyed
	// cout << "MessageStack object destroyed" << endl;
}

/* CLASS: MessageStack
 * METHOD: push
 * DESCRIPTION: Pushes message object onto <nodeData>
*/
void MessageStack::push( Message *obj ) {
 	// TEST: Signal if method has been called
 	// cout << "\npush function called" << endl;

 	Node *data = new Node();
 	data->nodeData = obj;
 	data->nextNode = head;

 	head = data;
} // END METHOD push

/* CLASS: MessageStack
 * METHOD: pop
 * DESCRIPTION: Return pointer to the <Message> object that was returned from the stack
 */
Message *MessageStack::pop() {
	Node *data = head;
	Message *poppedObject = data->nodeData;
	head = head->nextNode;
	delete data;
	return poppedObject;
} // END METHOD pop

/* CLASS: MessageStack
 * METHOD: printStack
 * DESCRIPTION: Prints data from each element in the stack
*/
void MessageStack::printStack() {
	Node *data = head;
	Message *msgObj;

	cout << "STACK: " << endl;
	
	while( data != NULL ) {
		msgObj = data->nodeData;
		msgObj->print();
		data = data->nextNode;
	}

	cout << "END STACK..." << endl;
}

/* FUNCTION: main
 * DESCRIPTION: Runs main loop in program
 */
int main( void ) {
	//Message m1;

	//Message *msgPtr = &m1;
	//msgPtr->print();

/*	MorseCodeMessage m2;

	Message *msgPtr = &m2;

	// msgPtr->print();
	m2.print();

	MessageStack m_stack;

	m_stack.push( msgPtr );

	MorseCodeMessage m3;

	Message *msgPtr3 = &m3;

	m_stack.push( msgPtr3 );

	m_stack.printStack();

	Message *msg1 = m_stack.pop();

	msg1->print();

	Message *msg2 = m_stack.pop();

	msg2->print();*/

	Message *msgPtr;

	bool on = true;
	int menuChoice = 0;
	string raw;

	while( on ) {

		// Main menu prompt
		cout << "\nMAIN MENU: " << endl;
		cout << "1. Create New Message" << endl;
		cout << "2. Translate" << endl;
		cout << "3. Push Object" << endl;
		cout << "4. Pop Object" << endl;
		cout << "5. Print Object" << endl;
		cout << "9. Exit\n--> ";

		getline( cin, raw );

		menuChoice = stoi( raw.c_str() );

		switch( menuChoice ) {
			case 1: // Create new message object and message
				msgPtr = new MorseCodeMessage();
				break;
			case 2:
				
				break;
			case 3:
				cout << "Push" << endl;
				break;
			case 4:
				cout << "Pop" << endl;
				break;
			case 5:	// Print Message
				msgPtr->print();
				break;
			case 9:
				on = false;
				break;
		} // END SWITCH : Main menu selection and action

	} // END WHILE : Main program loop
	return 0;
} // END FUNCTION main
